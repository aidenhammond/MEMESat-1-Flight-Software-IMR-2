####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding diles
# MOD_DEPS: (optional) module dependencies
####
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/instances.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/topology.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/RefTopologyDefs.cpp"
)
set(MOD_DEPS
  Fw/Logger
  Svc/LinuxTime
  # Communication Implementations
  Drv/Udp
  Drv/TcpClient
  Drv/LinuxSerialDriver
)

register_fprime_module()
