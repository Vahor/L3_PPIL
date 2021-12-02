#include <string>
#include <iostream>

using namespace std;

#include "client/TCPClient.h"
#include "shapes/Circle.h"

#include "json/JsonParser.h"


int main() {

    JsonParser::parse(R"({
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
		"title": "Truc",
		"width": "1000"
	}
})");
    return 0;

    TCPClient client("127.0.0.1", 10000);


    Circle sun(0, 0, 150);
    sun.setColor(Color::ORANGE);

    Circle earth(150, 0, 40);
    earth.setColor(Color::CYAN);

    Circle earthPath(0, 0, 310);

    client.send(sun.toString());
    client.send(earth.toString());
    client.send(earthPath.toString());

    return 0;
}


