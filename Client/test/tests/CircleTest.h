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

class CircleTest {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("CIRCLE");

        // Test scale
        Circle circle(Point2D(0, 0), 20);

        double previousArea = circle.getArea();
        circle.scale(2);
        circle.scale(.5);

        test.assertTrue(previousArea == circle.getArea(), "Circle Scale 2 => .5 Keep area");

        // Test constructor
        try {
            Circle c({0, 0}, -10);
            test.assertTrue(false, "Invalid diameter should throw an exception");
        } catch (const std::exception &e) {
            test.assertTrue(true, e.what());
        }
    }
};

