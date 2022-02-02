//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/xml/XMLParser.h"
#include "scene/Scene.h"
#include <string>
#include <algorithm>

using namespace std;

class XML_PARSER {

public:


    static void runTest(SimpleTest &test) {
        testSave();
    }

    static void testSave() {
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

        SceneDao *sceneDao = SceneDao::getInstance();
        sceneDao->setParser("xml");
        sceneDao->save("scene1_xml.xml", &testScene);
    }
};

