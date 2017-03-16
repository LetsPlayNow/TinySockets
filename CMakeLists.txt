cmake_minimum_required(VERSION 3.5)
project(SocketLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Other/SocketException.h
        Other/Utils.h
        Tests/Tests.h
        Tests/Tests.cpp
        Connections/Connection.h
        Communicators/Client.h
        Communicators/Server.h
        Communicators/TCPClient.h
        Communicators/UDPClient.h
        Communicators/UDPServer.h
        Communicators/TCPServer.h
        Connections/Socket.h
        )

add_executable(MainTests Tests/Main.cpp ${SOURCE_FILES})