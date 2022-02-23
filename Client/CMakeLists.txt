cmake_minimum_required(VERSION 3.20)
project(Client)


set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Client
        src/main.cpp
        src/client/TCPClient.cpp
        src/Color.cpp
        src/data/json/JsonParser.cpp
        src/data/DataElement.cpp
        src/shape/Shape.cpp
        src/scene/SceneDao.cpp
        src/shape/TriangleTest.cpp src/shape/Polygon.cpp src/shape/LineTest.cpp src/shape/CircleTest.cpp src/shape/ShapeGroup.cpp src/data/DataArray.cpp src/data/DataObject.cpp src/data/DataPrimitive.cpp include/data/xml/XMLParser.cpp include/data/xml/XMLParser.h)


set(SOURCE_FILES_TEST
        test/test.cpp
        include/Serializable.h
        test/lib/SimpleTest.cpp test/lib/SimpleTest.h
        test/tests/LOAD_SCENE.h
        src/Color.cpp
        src/data/json/JsonParser.cpp
        src/data/DataElement.cpp
        src/shape/Shape.cpp
        src/scene/SceneDao.cpp
        src/shape/TriangleTest.cpp src/shape/Polygon.cpp src/shape/LineTest.cpp src/shape/CircleTest.cpp src/shape/ShapeGroup.cpp src/data/DataArray.cpp src/data/DataObject.cpp src/data/DataPrimitive.cpp include/data/xml/XMLParser.cpp include/data/xml/XMLParser.h include/data/xml/XMLToken.h)


target_link_libraries(Client readline)
add_executable(run-test ${SOURCE_FILES_TEST})