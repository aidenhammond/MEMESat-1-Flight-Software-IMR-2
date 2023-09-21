cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
project(top)
add_subdirectory(libcron)
#add_subdirectory(test)
add_library(CronClock STATIC libs/CronClock.h libcron/src/CronClock.cpp)
add_library(CronData STATIC libs/CronData.h libcron/src/CronData.cpp)
add_library(CronRandomization STATIC libs/CronRandomization.h libcron/src/CronRandomization.cpp)
add_library(CronSchedule STATIC libs/CronSchedule.h libcron/src/CronSchedule.cpp)
add_library(Task STATIC libs/Task.h libcron/src/Task.cpp)


#add_dependencies(cron_test libcron)

install(TARGETS libcron DESTINATION lib)
install(DIRECTORY libcron/include/libcron DESTINATION include)
install(DIRECTORY libcron/externals/date/include/date DESTINATION include)

