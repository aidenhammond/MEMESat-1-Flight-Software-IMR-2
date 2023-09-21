
if(NOT "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitinfo.txt" IS_NEWER_THAN "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/fprime-community/fpp" "src"
    WORKING_DIRECTORY "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/fprime-community/fpp'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout ee355fc99eb8040157c62e69f58ac6a8435cd981 --
  WORKING_DIRECTORY "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'ee355fc99eb8040157c62e69f58ac6a8435cd981'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitinfo.txt"
    "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-download/fpp-tools-prefix/src/fpp-tools-stamp/fpp-tools-gitclone-lastrun.txt'")
endif()

