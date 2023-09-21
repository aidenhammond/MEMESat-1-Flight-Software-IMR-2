# Register the standard build
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/EPS_UART.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/EPS_UART.fpp"
)
register_fprime_module()

set(UT_SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/EPS_UART.fpp"
)

set(UT_AUTO_HELPERS ON)
register_fprime_ut()