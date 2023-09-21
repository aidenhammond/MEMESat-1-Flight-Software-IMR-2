set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/FileRecycler.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/FileRecycler.fpp"
)
register_fprime_module()
set(UT_SOURCE_FILES
	"${CMAKE_CURRENT_LIST_DIR}/FileRecycler.fpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/main.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
	)
register_fprime_ut()
