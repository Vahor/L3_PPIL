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

class GroupTest {

public:

    static void runTest(SimpleTest &test) {
        SimpleTest::divider("GROUP");

        Scene groupScene;
        // Test scale
        auto *circle = new Circle(Point2D(0, 0), 20);
        Circle circle2(Point2D(0, 0), 20);
        auto *circle3 = new Circle(Point2D(0, 0), 20);
        auto *circle4 = new Circle(Point2D(0, 0), 20);

        auto *group = new ShapeGroup;
        group->addShape(circle);
        group->addShape(&circle2);
        group->addShape(circle3);

        auto *innerGroup = new ShapeGroup();
        innerGroup->addShape(circle4);

        group->addShape(innerGroup);

        groupScene.add(group);

        SceneDao *sceneDao = SceneDao::getInstance();
        sceneDao->setParser("json");
        sceneDao->save("groupScene.json", &groupScene);
        Scene *scene = sceneDao->get("groupScene.json");

        test.assertTrue(groupScene.toString() == scene->toString(), "Loaded group equals group");

        delete circle;

        test.assertTrue(group->size() == 3, "Delete element removes it from the group");

        circle2.setGroup(nullptr);

        test.assertTrue(group->size() == 2, "Shape.setGroup to nullptr removes it from the group");

        delete group;

        test.assertTrue(circle3->getGroup() == nullptr, "Shape.getGroup is null when group is deleted");

    }
};

