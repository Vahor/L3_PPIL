#include <string>
#include <iostream>

using namespace std;

#include "client/TCPClient.h"
#include "shapes/Circle.h"



int main() {




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


