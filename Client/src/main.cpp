#include <string>
#include <iostream>

using namespace std;

#include "client/TCPClient.h"
#include "shapes/Circle.h"

#include "data/json/JsonParser.h"
#include "Scene.h"
#include "shapes/handler/ShapesCORLoader.h"


int main() {

    JsonParser parser;
    JsonObject *object = parser.parse(R"({
	"items": [{
		"CIRCLE": {
			"color": {
				"b": "0",
				"g": "0",
				"r": "255"
			},
			"diameter": "50",
			"x": "50",
			"y": "50"
		},
		"type": "CIRCLE"
	}, {
		"CIRCLE": {
			"color": {
				"b": "0",
				"g": "0",
				"r": "255"
			},
			"diameter": "50",
			"x": "200",
			"y": "200"
		},
		"type": "CIRCLE"
	}],
	"window": {
		"height": "500",
		"name": "Truc",
		"width": "1000"
	}
})");
    cout << object->toString() << endl;

    auto* handler = new ShapesCORLoader();
    Scene* scene = handler->parseScene(*object);

    Scene testScene("Truc");
    testScene.setHeight(500);
    testScene.setWidth(1000);
    testScene.add(new Circle(200,200,50));
    testScene.add(new Circle(50,50,50));


    cout << scene->serialize()->toString() << endl;
    cout << testScene.serialize()->toString() << endl;
    return 0;
//
//    TCPClient client("127.0.0.1", 10000);
//
//
//    Circle sun(0, 0, 150);
//    sun.setColor(Color::ORANGE);
//
//    Circle earth(150, 0, 40);
//    earth.setColor(Color::CYAN);
//
//    Circle earthPath(0, 0, 310);
//
//    client.send(sun.toString());
//    client.send(earth.toString());
//    client.send(earthPath.toString());

    return 0;
}


