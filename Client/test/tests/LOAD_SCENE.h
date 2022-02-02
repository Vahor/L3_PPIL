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

class LOAD_SCENE {

public:
    /*
     * - Création de scene
     * - Sauvegarde scene
     * - Load scene
     * - Comparaison du load et clone
     */
    static void runTest(SimpleTest &test) {
        SimpleTest::divider("PARSER_SCENE");

        Scene testScene;
        testScene.setName("Truc");
        testScene.setHeight(500);
        testScene.setWidth(1000);

        auto *circle1 = new Circle({200, 200}, 50);
        circle1->setColor(Color::RED);
        circle1->setBorderColor(Color::YELLOW);
        testScene.add(circle1);


        auto *text = new Text({0, 0}, 50, "Soleil");
        text->setColor(Color::RED);
        testScene.add(text);

        auto *circle2 = new Circle({50, 50}, 50);
        circle2->setColor(Color::BLUE);
        testScene.add(circle2);

        auto *polygon = new Polygon();
        polygon->setColor(Color::RED);
        polygon->addPoint(Point2D({100, 100}));
        polygon->addPoint(Point2D({100, 50}));
        polygon->addPoint(Point2D({50, 50}));
        testScene.add(polygon);

        SceneDao *sceneDao = SceneDao::getInstance();
        sceneDao->setParser("json");
        sceneDao->save("scene1.json", &testScene);
        Scene *scene = sceneDao->get("scene1.json");
        Scene *sceneClone = scene->clone();

        string fromCode = testScene.serialize(false)->toString();

        Scene testGroupScene;
        testGroupScene.setName("testGroup");
        testGroupScene.setHeight(500);
        testGroupScene.setWidth(1000);

        ShapeGroup group;
        group.addShape(circle1);
        group.addShape(polygon);
        group.addShape(circle2);
        group.setColor(Color::BLUE);
        testGroupScene.add(&group);

        sceneDao->save("scene2.json", &testGroupScene);
        Scene *groupLoad = sceneDao->get("scene2.json");


//        cout << "fromCode.length() : " << fromCode.length() << endl;
//        cout << fromCode << endl;
//
//        cout << "fromParser2.length() : " << fromParser2.length() << endl;
//        cout << fromParser2 << endl;
//
//        cout << "fromParser.length() : " << fromParser.length() << endl;
//
//        cout << fromParser << endl;
//        cout << "text.length() : " << text.length() << endl;
//
//        cout << text << endl;

//        cout << testScene.serialize(false)->toString() << endl;
//        cout << scene->serialize(false)->toString() << endl;
//        cout << fromCode << endl;

        // cout << groupLoad->serialize(true)->toString() << endl;
        // cout << testGroupScene.serialize(false)->toString() << endl;
        // cout << groupLoad->serialize(false)->toString() << endl;

        test.assertTrue(scene->serialize(false)->toString().length() == fromCode.length(),
                        "Load");
        test.assertTrue(
                sceneClone->serialize(false)->toString().length() == scene->serialize(false)->toString().length(),
                "Clone");
        test.assertTrue(groupLoad->serialize(false)->toString().length() ==
                        testGroupScene.serialize(false)->toString().length(),
                        "Group Load");
        test.assertTrue(
                groupLoad->serialize(true)->toString().length() == testGroupScene.serialize(true)->toString().length(),
                "Group ignore Load");
    }
};

