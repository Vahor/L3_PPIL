//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "data/json/JsonParser.h"
#include "Scene.h"
#include "shapes/handler/ShapesCORLoader.h"
#include <string>
#include <algorithm>

using namespace std;

class PARSER_SCENE {

public:
    static void runTest(SimpleTest &test) {
        SimpleTest::divider("PARSER_SCENE");

        string text = R"({
	"items": [{
		"CIRCLE": {
			"color": {
				"b": "0",
				"g": "0",
				"r": "255"
			},
			"diameter": "50.000000",
			"x": "50.000000",
			"y": "50.000000"
		},
		"type": "CIRCLE"
	}, {
		"CIRCLE": {
			"color": {
				"b": "0",
				"g": "0",
				"r": "255"
			},
			"diameter": "50.000000",
			"x": "200.000000",
			"y": "200.000000"
		},
		"type": "CIRCLE"
	}],
	"window": {
		"height": "500",
		"name": "Truc",
		"width": "1000"
	}
})";

        JsonParser parser;

        auto *handler = new ShapesCORLoader();

        Scene testScene("Truc");
        testScene.setHeight(500);
        testScene.setWidth(1000);

        auto *circle1 = new Circle(200, 200, 50);
        circle1->setColor(Color::RED);
        testScene.add(circle1);

        auto *circle2 = new Circle(50, 50, 50);
        circle2->setColor(Color::RED);
        testScene.add(circle2);

        JsonObject *object = parser.parse(text);
        Scene *scene = handler->parseScene(*object);
        string fromParser = object->toString();
        string fromParser2 = scene->serialize()->toString();

        string fromCode = testScene.serialize()->toString();

        text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

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

        test.assertTrue(text.length() == fromParser.length(), "text.length() != fromParser.length");
        test.assertTrue(text.length() == fromParser2.length(), "text.length() != fromParser2.length");
        test.assertTrue(text.length() == fromCode.length(), "text.length() != fromCode.length");
        test.assertTrue(fromParser2.length() == fromParser.length(), "fromParser2.length() != fromParser.length");
        test.assertTrue(fromCode.length() == fromParser.length(), "fromCode.length() != fromParser.length");
    }
};

