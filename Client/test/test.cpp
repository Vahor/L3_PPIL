//
// Created by Nathan David on 04/12/2021.
//

#include "./lib/SimpleTest.h"
#include "./tests/LOAD_SCENE.h"
#include "./tests/MATH_SCENE.h"
#include "./tests/JSON_PARSER.h"
#include "./tests/XML_PARSER.h"
#include "./tests/SCALE_SHAPES.h"
#include "./tests/CircleTest.h"
#include "./tests/TextTest.h"
#include "./tests/TriangleTest.h"
#include "./tests/GroupTest.h"
#include "./tests/LineTest.h"
#include "./tests/AlexText.h"

using namespace std;

SimpleTest test;
int main() {
    LOAD_SCENE::runTest(test);
    JSON_PARSER::runTest(test);
    MATH_SCENE::runTest(test);
    SCALE_SHAPES::runTest(test);
    CircleTest::runTest(test);
    TextTest::runTest(test);
    TriangleTest::runTest(test);
    GroupTest::runTest(test);
    XML_PARSER::runTest(test);
    LineTest::runTest(test);
    AlexText::runTest(test);

    test.stop();

    return 0;
}
