cmake_minimum_required(VERSION 3.15)
project(cppnotebook)

set(CMAKE_CXX_STANDARD 11)

option(tryboost "Enable building tryboost" ON)
option(protobuf "Enable building protobuf" ON)

if(tryboost)
    add_subdirectory(tryboost)
endif()
if(protobuf)
    add_subdirectory(protobuf)
endif()

add_executable(cppnotebook main.cpp)