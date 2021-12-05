//
// Created by Nathan David on 04/12/2021.
//

#include "./lib/SimpleTest.h"
#include "./tests/LOAD_SCENE.h"

using namespace std;

SimpleTest test;
int main()
{
    LOAD_SCENE::runTest(test);

    test.stop();

    return 0;
}
