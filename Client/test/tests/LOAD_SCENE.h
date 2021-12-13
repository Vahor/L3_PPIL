//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/json/JsonParser.h"
#include "scene/AScene.h"
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

        AScene testScene;
        testScene.setName("Truc");
        testScene.setHeight(500);
        testScene.setWidth(1000);

        auto *circle1 = new Circle({200, 200}, 50);
        circle1->setColor(Color::RED);
        circle1->setVisible(false);
        testScene.add(circle1);


        auto *text = new Text({0, 0}, 50, "Soleil");
        text->setColor(Color::RED);
        text->setZIndex(1);
        testScene.add(text);

        auto *circle2 = new Circle({50, 50}, 50);
        circle2->setColor(Color::BLUE);
        testScene.add(circle2);


        auto *polygon = new Polygon();
        polygon->setColor(Color::RED);
        polygon->addPoint(new Point2D({100, 100}));
        polygon->addPoint(new Point2D({100, 50}));
        polygon->addPoint(new Point2D({50, 50}));
        testScene.add(polygon);

        SceneDao sceneDao;
        sceneDao.save("scene1.json", &testScene);
        AScene *scene = sceneDao.get("scene1.json");
        AScene *sceneClone = scene->clone();

        string fromCode = testScene.serialize()->toString();

        AScene testGroupScene;
        testGroupScene.setName("testGroup");
        testGroupScene.setHeight(500);
        testGroupScene.setWidth(1000);

        ShapeGroup group;
        group.addShape(circle1);
        group.addShape(circle2);
        testGroupScene.add(&group);

        sceneDao.save("scene2.json", &testGroupScene);
        AScene *groupLoad = sceneDao.get("scene2.json");


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

//        cout << testScene.serialize()->toString() << endl;
//        cout << scene->serialize()->toString() << endl;
//        cout << fromCode << endl;
        cout << testGroupScene.serialize()->toString() << endl;
        cout << groupLoad->serialize()->toString() << endl;

        test.assertTrue(scene->serialize()->toString().length() == fromCode.length(),
                        "Load");
        test.assertTrue(sceneClone->serialize()->toString().length() == scene->serialize()->toString().length(),
                        "Clone");
        test.assertTrue(groupLoad->serialize()->toString().length() == testGroupScene.serialize()->toString().length(),
                        "Group Load");
    }
};

