//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/json/JsonParser.h"
#include "scene/Scene.h"
#include "shapes/Line.h"
#include <string>
#include <algorithm>

using namespace std;

class LineTest {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("LINE");

        // Test scale
        Point2D from(0, 0);
        Point2D to(1, 1);
        Line line(from, to);

        Point2D *center = line.getCenter();
        line.scale(1);
        Point2D *centerAfterScale = line.getCenter();

        test.assertTrue(*center == *centerAfterScale, "Line scaling should not change the center");
    }
};

