cmake_minimum_required(VERSION 3.20)
project(Client)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Client
        src/main.cpp
        src/client/TCPClient.cpp
        src/Color.cpp
        src/api/shape/AShape.cpp)


set(SOURCE_FILES_TEST
        test/test.cpp
        test/lib/SimpleTest.cpp test/lib/SimpleTest.h
        test/tests/LOAD_SCENE.h
        src/Color.cpp
        src/api/shape/AShape.cpp
        include/api/dao/Dao.h)


add_executable(run-test ${SOURCE_FILES_TEST})