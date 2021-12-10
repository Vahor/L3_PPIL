#include "client/TCPClient.h"
#include "shapes/Circle.h"

#include "scene/SceneDao.h"

int main() {

    TCPClient client("127.0.0.1", 10000);

//    Circle sun(0, 0, 150);
//    sun.setColor(Color::ORANGE);
//
//    Circle earth(150, 0, 40);
//    earth.setColor(Color::CYAN);
//
//    Circle earthPath(0, 0, 310);
//
//    client.send(sun.serialize()->toString());
//    client.send(earth.serialize()->toString());
//    client.send(earthPath.serialize()->toString());

    return 0;
}


