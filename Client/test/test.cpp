//
// Created by Nathan David on 04/12/2021.
//

#include "./lib/SimpleTest.h"
#include "./tests/PARSER_SCENE.h"

using namespace std;

SimpleTest test;
int main()
{
    PARSER_SCENE::runTest(test);

    test.stop();

    return 0;
}
