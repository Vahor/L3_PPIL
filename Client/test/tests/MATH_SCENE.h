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

class MATH_SCENE {

public:


    static void runTest(SimpleTest &test) {
        SimpleTest::divider("MATH_SCENE");

        Polygon square;
        square.addPoint(new Point2D(0, 0));
        square.addPoint(new Point2D(0, 5));
        square.addPoint(new Point2D(5, 5));
        square.addPoint(new Point2D(5, 0));

        test.assertTrue(
                square.getArea() == 25,
                "square.getArea() == 25");

        Polygon weirdSquare;
        weirdSquare.addPoint(new Point2D(-4, 4));
        weirdSquare.addPoint(new Point2D(2, 7));
        weirdSquare.addPoint(new Point2D(3, -3));
        weirdSquare.addPoint(new Point2D(-3, -2));

        test.assertTrue(
                weirdSquare.getArea() == 49,
                "weirdSquare.getArea() == 49");

        Polygon convexe;
        convexe.addPoint(new Point2D(1, 4));
        convexe.addPoint(new Point2D(2, 7));
        convexe.addPoint(new Point2D(3, -3));
        convexe.addPoint(new Point2D(-3, -2));

        test.assertTrue(
                convexe.getArea() == 26.5,
                "convexe.getArea() == 26.5");

    }
};

