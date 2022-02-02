//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/json/JsonParser.h"
#include "scene/Scene.h"
#include <string>
#include <algorithm>

using namespace std;

class TEXT {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("TEXT");

        // Test constructor
        try {
            Text c({0, 0}, -10, "", 0);
            test.assertTrue(false, "Invalid size should throw an exception");
        } catch (const std::exception &e) {
            test.assertTrue(true, e.what());
        }
    }
};

