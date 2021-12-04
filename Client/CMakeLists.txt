cmake_minimum_required(VERSION 3.20)
project(Client)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Client
        src/main.cpp
        src/client/TCPClient.cpp
        src/Color.cpp test/lib/SimpleTest.cpp test/lib/SimpleTest.h)


set(SOURCE_FILES_TEST
        test/test.cpp
        test/lib/SimpleTest.cpp test/lib/SimpleTest.h
        test/tests/PARSER_SCENE.h
        src/Color.cpp
        )


add_executable(run-test ${SOURCE_FILES_TEST})