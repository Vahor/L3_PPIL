cmake_minimum_required(VERSION 3.20)
project(Client)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Client
        src/main.cpp
        src/client/TCPClient.cpp
        src/Color.cpp include/Color.h
        include/json/JsonObject.h
        include/json/JsonElement.h
        include/json/JsonPrimitive.h
        include/shapes/Shape.h
        include/shapes/Circle.h
        )
