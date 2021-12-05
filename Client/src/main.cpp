#include "client/TCPClient.h"
#include "shapes/Circle.h"

#include "scene/JsonScene.h"
#include "scene/SceneDao.h"

int main() {

    //TCPClient client("127.0.0.1", 10000);

    SceneDao sceneDao;
    JsonScene *scene = sceneDao.get("/Users/nathan/Desktop/UFR/PPIL/Projet/Client/data/scene1.json");
    cout << scene->getName() << endl;
    cout << scene->serialize()->toString() << endl;

    sceneDao.save("/Users/nathan/Desktop/UFR/PPIL/Projet/Client/data/scene2.json", scene);

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


