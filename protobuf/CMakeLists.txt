cmake_minimum_required(VERSION 3.15)
project(protobuf)

message("CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

include_directories(src/generated/cpp)

add_executable(protobuf main.cpp src/generated/cpp/SearchRequest.pb.cc src/generated/cpp/MyMessage.pb.cc)

find_package(Protobuf REQUIRED)
message("Protobuf_INCLUDE_DIRS: ${Protobuf_INCLUDE_DIRS}")
message("Protobuf_LIBRARIES: ${Protobuf_LIBRARIES}")
include_directories(${Protobuf_INCLUDE_DIRS})
target_link_libraries(protobuf ${Protobuf_LIBRARIES})


FILE(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/externals/protodef PROTOMODEL_PATH)
FILE(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/generated PROTOBINDING_PATH)
file(MAKE_DIRECTORY ${PROTOMODEL_PATH})

FILE(GLOB DATAMODEL_PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/src/externals/protodef/*.proto")

message("PROTOMODEL_PATH: ${PROTOMODEL_PATH}")
set(langs cpp java)
FOREACH (lang ${langs})
    FOREACH (proto ${DATAMODEL_PROTOS})
        FILE(TO_NATIVE_PATH ${proto} proto_native)
        file(MAKE_DIRECTORY ${PROTOBINDING_PATH}/${lang})
        EXECUTE_PROCESS(COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
                --proto_path=${PROTOMODEL_PATH} --${lang}_out=${PROTOBINDING_PATH}/${lang} ${proto_native}
                RESULT_VARIABLE rv)
        IF (${rv})
            MESSAGE("Generation of data model returned ${rv} for proto ${proto_native}")
        ENDIF ()
    ENDFOREACH (proto)
ENDFOREACH (lang)