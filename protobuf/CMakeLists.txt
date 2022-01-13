cmake_minimum_required(VERSION 3.15)
project(protobuf)

message("CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

add_executable(protobuf main.cpp)

find_package(Protobuf REQUIRED)
message("Protobuf_INCLUDE_DIRS: ${Protobuf_INCLUDE_DIRS}")
message("Protobuf_LIBRARIES: ${Protobuf_LIBRARIES}")
include_directories(${Protobuf_INCLUDE_DIRS})
target_link_libraries(tryBoost ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})