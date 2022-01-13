cmake_minimum_required(VERSION 3.15)
project(tryBoost)


set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(tryBoost main.cpp)

set(Boost_NO_BOOST_CMAKE FALSE CACHE BOOL "" FORCE)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system)

message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
target_include_directories(tryBoost PUBLIC ${Boost_INCLUDE_DIRS})

message("Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")