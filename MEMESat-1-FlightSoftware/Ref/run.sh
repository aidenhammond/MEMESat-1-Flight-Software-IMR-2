#!/bin/bash
trap 'echo "\n\nError Occured" >&2; exit 1' ERR

njobs=10

# If build exists, prompt a purge
if [ -d "build-fprime-automatic-native" ] 
then
    fprime-util purge
fi

# Make all libcron files
if [ cd libcron ]
then
    rm CMakeCache.txt
    cmake .
    make
    mv *.a libs
    cd ..
fi

###################################
# Don't build unless error occurs.#2&>1 | grep "FileRecycelreComponentAi.xml" ?
###################################

# Defining log file for this because not everything gets printed
log="run_log.log"
echo "" > $log

# Fix the fprime double double quote issue by replacing all double double quotes with a single double quote
# in the FileRecycler component xml
fix_fr() {
    if cat $1 | grep -q "FileRecyclerComponentAi.xml"; then
        file_recycler_build_file_rel_path='build-fprime-automatic-native/Ref/FileRecycler/FileRecyclerComponentAi.xml'
        sed -i '' -e 's/""/"/g' "$file_recycler_build_file_rel_path" 
        fprime-util build --jobs $njobs | tee $1
    fi
}

# Fix the fprime double double quote issue by replacing all double double quotes with a single double quote
# in the tlmchanwrapper component xml
fix_tlm() {
    if cat $1 | grep -q "TlmChanWrapperComponentAi.xml"; then
        tlm_chan_build_file_rel_path='build-fprime-automatic-native/Ref/TlmChanWrapper/TlmChanWrapperComponentAi.xml'
        sed -i '' -e 's/""/"/g' "$tlm_chan_build_file_rel_path"
    fi
}

# generate
fprime-util generate 2>/tmp/a || true

# Not tested
# Issue occurs when build cache gets messed up like if you stop a generate mid generate I believe
err=$(cat /tmp/a)
if [ "$err" = "[WARNING] Build cache '/Users/aiden/MEMESat-1-FlightSoftware/Ref/build-fprime-automatic-native' invalid or not found. Skipping." ]; then
    read -p "$err Do you want rm -rf build-fprime-automatic-native? " can_remove_build
    if [ "$can_remove_build" = "yes" ] || [ "$can_remove_build" = "y" ]; then
        rm -rf build-fprime-automatic-native
    fi
fi

# build, send to both std out and a file (| tee /tmb/b)
if ! fprime-util build --jobs $njobs | tee /tmp/b; then 

    echo "\nRunning fprime-util build"
    # this should be fixed lol, definetely a way to combine them
    # or make it generally better
    fix_fr /tmp/b
    fix_tlm /tmp/b
    fprime-util build --jobs $njobs 
fi
#read -p "Build ground station? (Ensure that all GDS tabs are closed) : " gs
echo $2
if [ "$3" = "gs" ]; then
    # commands to run if the user entered "yes" or "y"
    socat -d -d pty,raw,echo=0,ispeed=15200,ospeed=15200 pty,raw,echo=0,ispeed=15200,ospeed=15200 2>/tmp/c &
    sleep 1
    socat_output=$(cat /tmp/c)
    # getting the ttys locations from socat
    tty1=$(echo "$socat_output" | awk '/\/dev\/ttys/{print $0; exit}' | awk '{print $NF}')
    tty2=$(echo "$socat_output" | awk '/\/dev\/ttys/{if (!found) {found=1; next}; print $0; exit}' | awk '{print $NF}')
    echo $tty1
    echo $tty2
    # replacing the old ttys in instances.fpp and eps_spoof.py
    find Top/instances.fpp -exec sed -i '' -e "s@\(/dev/ttys[^\"]*\)@$tty1@g" {} \;
    find eps-spoof-memesat/eps_spoof.py -exec sed -i '' -e "s|\(/dev/ttys[^\"]*\)|$tty2|g" {} \;
    fprime-util build --jobs $njobs
    python eps-spoof-memesat/eps_spoof.py &
    sudo ./build-fprime-automatic-native/bin/Darwin/Ref -a 127.0.0.1 -p 50000 >> out.txt\n


fi

cat /tmp/a >> $log
cat /tmp/b >> $log
cat /tmp/c >> $log

