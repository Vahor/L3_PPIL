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

class TRIANGLE {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("TRIANGLE");

        // Test constructor
        try {
            Triangle t(new Point2D{0, 0}, nullptr, new Point2D{1, 1});
            test.assertTrue(false, "All points must be non-null.");
        } catch (const std::exception &e) {
            test.assertTrue(true, e.what());
        }
    }
};

