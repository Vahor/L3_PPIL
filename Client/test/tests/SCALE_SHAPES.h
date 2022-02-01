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

class SCALE_SHAPES {

public:


    static void runTest(SimpleTest &test) {
        SimpleTest::divider("SCALE_SHAPES");

        // Polygon
        {
            Polygon polygon;
            polygon.addPoint(Point2D(1, 4));
            polygon.addPoint(Point2D(2, 7));
            polygon.addPoint(Point2D(3, -3));
            polygon.addPoint(Point2D(-3, -2));
            polygon.addPoint(Point2D(8, -20));

            double previousArea = polygon.getArea();
            polygon.scale(2);
            polygon.scale(.5);

            test.assertTrue(previousArea == polygon.getArea(), "Polygon Scale 2 => .5 Keep area");
        }


        // Circle
        {
            Circle circle(Point2D(0, 0), 20);

            double previousArea = circle.getArea();
            circle.scale(2);
            circle.scale(.5);

            test.assertTrue(previousArea == circle.getArea(), "Circle Scale 2 => .5 Keep area");
        }
    }
};

