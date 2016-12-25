cmake_minimum_required(VERSION 3.5)
project(SocketLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Messages/Message.h
        Messengers/SocketClient.cpp
        Messengers/SocketClient.h
        Other/SocketException.h
        Messengers/SocketMessenger.cpp
        Messengers/SocketMessenger.h
        Messengers/SocketServer.cpp
        Messengers/SocketServer.h
        Messages/StepInfoReply.h
        Messages/StepInfoRequest.h
        Messages/StepParameters.h
        Tests/Tests.h)

add_executable(MainTests Tests/Main.cpp ${SOURCE_FILES})

add_executable(Client Tests/Client.cpp ${SOURCE_FILES})

add_executable(Server Tests/Server.cpp ${SOURCE_FILES})