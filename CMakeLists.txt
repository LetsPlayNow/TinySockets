cmake_minimum_required(VERSION 3.5)
project(SocketLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Message.h
    SocketClient.cpp
    SocketClient.h
    SocketException.h
    SocketMessenger.cpp
    SocketMessenger.h
    SocketServer.cpp
    SocketServer.h
    StepInfoReply.h
    StepInfoRequest.h
    StepParameters.h
    Tests.h)

add_executable(SocketLib ${SOURCE_FILES})