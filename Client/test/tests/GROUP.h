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

class GROUP {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("GROUP");

        // Test scale
        auto *circle = new Circle(Point2D(0, 0), 20);
        Circle circle2(Point2D(0, 0), 20);
        auto *circle3 = new Circle(Point2D(0, 0), 20);

        auto *group = new ShapeGroup;
        group->addShape(circle);
        group->addShape(&circle2);
        group->addShape(circle3);

        delete circle;

        test.assertTrue(group->size() == 2, "Delete element removes it from the group");

        circle2.setGroup(nullptr);

        test.assertTrue(group->size() == 1, "Shape.setGroup to nullptr removes it from the group");

        delete group;

        test.assertTrue(circle3->getGroup() == nullptr, "Shape.getGroup is null when group is deleted");


    }
};

