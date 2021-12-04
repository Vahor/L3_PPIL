//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/JsonScene.h"
#include "scene/JsonSceneDao.h"
#include "data/json/JsonParser.h"
#include "api/scene/AScene.h"
#include <string>
#include <algorithm>

using namespace std;

class PARSER_SCENE {

public:
    static void runTest(SimpleTest &test) {
        SimpleTest::divider("PARSER_SCENE");

        JsonSceneDao sceneDao;
        JsonScene *scene = sceneDao.get("/Users/nathan/Desktop/UFR/PPIL/Projet/Client/data/scene1.json");

        JsonScene testScene;
        testScene.setName("Truc");
        testScene.setHeight(500);
        testScene.setWidth(1000);

        auto *circle1 = new Circle(200, 200, 50);
        circle1->setColor(Color::RED);
        testScene.add(circle1);

        auto *circle2 = new Circle(50, 50, 50);
        circle2->setColor(Color::RED);
        testScene.add(circle2);

        string fromCode = testScene.serialize()->toString();

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

        test.assertTrue(scene->serialize()->toString().length() == fromCode.length(), "scene.length() != fromCode.length");
    }
};

