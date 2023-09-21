# Install script for directory: /home/aiden/SSRL/MEMESat-1-FlightSoftware/Drv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/aiden/SSRL/MEMESat-1-FlightSoftware/build-artifacts")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/DataTypes/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/GpioDriverPorts/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/SerialDriverPorts/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/SpiDriverPorts/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/I2cDriverPorts/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/BlockDriver/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/ByteStreamDriverModel/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/LinuxGpioDriver/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/LinuxSerialDriver/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/LinuxSpiDriver/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/LinuxI2cDriver/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/Ip/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/TcpClient/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/TcpServer/cmake_install.cmake")
  include("/home/aiden/SSRL/MEMESat-1-FlightSoftware/F-Prime/Drv/Udp/cmake_install.cmake")

endif()

