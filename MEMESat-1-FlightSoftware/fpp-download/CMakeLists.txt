cmake_minimum_required(VERSION 2.8.12)

project(fpp-download NONE)

include(ExternalProject)
ExternalProject_Add(fpp-tools
  GIT_REPOSITORY    https://github.com/fprime-community/fpp
  GIT_TAG           ee355fc99eb8040157c62e69f58ac6a8435cd981
  SOURCE_DIR        "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src"
  BINARY_DIR        "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/bin"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools/src/compiler/install" "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools-install"
  TEST_COMMAND      ""
)
