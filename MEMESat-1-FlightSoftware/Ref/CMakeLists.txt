####
# 'Ref' Deployment:
#
# This sets up the build for the 'Ref' Application, including the custom reference
# components. In addition, it imports FPrime.cmake, which includes the core F Prime
# components.
#
# This file has several sections.
#
# 1. Header Section: define basic properties of the build
# 2. F prime core: includes all F prime core components, and build-system properties
# 3. Local subdirectories: contains all deployment specific directory additions
####

##
# Section 1: Basic Project Setup
#
# This contains the basic project information. Specifically, a cmake version and
# project definition.
##
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0048 NEW)
project(Ref VERSION 1.0.0 LANGUAGES C CXX)

##
# Section 2: F prime Core
#
# This includes all of the F prime core components, and imports the make-system. F prime core
# components will be placed in the F-Prime binary subdirectory to keep them from
# colliding with deployment specific items.
##
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime-Code.cmake")
##
# Section 3: Components and Topology
#
# This section includes deployment specific directories. This allows use of non-
# core components in the topology, which is also added here.
##
# Add component subdirectories
#add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/libcron/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SensorTypes")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PingReceiver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/RecvBuffApp/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SendBuffApp/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SignalGen/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/StateMachineTypes/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileRecyclerTypes/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SchedulerPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Scheduler/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileRecycler/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileRecyclerPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/StateMachinePorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/StateMachine/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TlmChanWrapper/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/EPS_UART/")

# Add Topology subdirectory
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Top/")
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/Top/Main.cpp")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -g3")
set(MOD_DEPS ${PROJECT_NAME}/Top)

register_fprime_deployment()
