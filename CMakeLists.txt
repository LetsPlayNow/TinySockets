cmake_minimum_required(VERSION 3.5)
project(SocketLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY, ${CMAKE_CURRENT_SOURCE_DIR}/Build)
set(LibrarySources MyException.h
        SocketClient.cpp
        SocketClient.h
        SocketServer.cpp
        SocketServer.h)
add_library (SocketLib ${LibrarySources})
target_include_directories (SocketLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(SocketLibTest main.cpp)
target_link_libraries(SocketLibTest SocketLib)