cmake_minimum_required(VERSION 2.8.12)

project(sbt-download NONE)

include(ExternalProject)
ExternalProject_Add(sbt
  URL https://github.com/sbt/sbt/releases/download/v1.5.5/sbt-1.5.5.zip
  DOWNLOAD_DIR      "/home/aiden/SSRL/MEMESat-1-FlightSoftware/sbt-download"
  SOURCE_DIR        "/home/aiden/SSRL/MEMESat-1-FlightSoftware/fpp-tools-install/sbt"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

