Drv/LinuxSerialDriver/LinuxSerialDriverComponentImpl.cpp
    commented out 378 & 379:
        //static int totalSizeRead = 0;
        //totalSizeRead += sizeRead;
    were giving the issue:
    Drv/LinuxSerialDriver/LinuxSerialDriverComponentImpl.cpp:378:30: error: variable totalSizeRead set but not used [-Werror,-Wunused-but-set-variable] static int totalSizeRead = 0;


<h1>On error: </h1>
ImportError: dlopen(/Users/aiden/fprime-venv/lib/python3.10/site-packages/lxml/etree.cpython-310-darwin.so, 0x0002): tried: '/Users/aiden/fprime-venv/lib/python3.10/site-packages/lxml/etree.cpython-310-darwin.so' (mach-o file, but is an incompatible architecture (have 'x86_64', need 'arm64')), '/System/Volumes/Preboot/Cryptexes/OS/Users/aiden/fprime-venv/lib/python3.10/site-packages/lxml/etree.cpython-310-darwin.so' (no such file), '/Users/aiden/fprime-venv/lib/python3.10/site-packages/lxml/etree.cpython-310-darwin.so' (mach-o file, but is an incompatible architecture (have 'x86_64', need 'arm64')) 

<h1>run</h1>: 
pip uninstall lxml
ARCHFLAGS="-arch arm64" pip install lxml==4.9.0 --compile --no-cache-dir