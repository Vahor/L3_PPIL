//
// Created by Nathan David on 04/12/2021.
//

#include "./lib/SimpleTest.h"
#include "./tests/LOAD_SCENE.h"
#include "./tests/MATH_SCENE.h"
#include "./tests/JSON_PARSER.h"
#include "./tests/SCALE_SHAPES.h"
#include "./tests/CIRCLE.h"
#include "./tests/TEXT.h"
#include "./tests/TRIANGLE.h"

using namespace std;

SimpleTest test;
int main() {
    LOAD_SCENE::runTest(test);
    JSON_PARSER::runTest(test);
    MATH_SCENE::runTest(test);
    SCALE_SHAPES::runTest(test);
    CIRCLE::runTest(test);
    TEXT::runTest(test);
    TRIANGLE::runTest(test);

    test.stop();

    return 0;
}
