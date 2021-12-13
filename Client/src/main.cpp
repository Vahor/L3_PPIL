#include "client/TCPClient.h"
#include "shapes/Circle.h"
#include "shapes/Text.h"

#include "scene/SceneDao.h"
#include "scene/AScene.h"

#include "packet/DrawShapePacket.h"
#include "packet/InitRendererPacket.h"
#include "packet/RefreshRendererPacket.h"

int main() {

    TCPClient client("127.0.0.1", 10000);

    AScene scene;
    scene.setName("SolarSystem");
    scene.setHeight(500);
    scene.setWidth(1000);


    Circle sun({0, 0}, 150);
    sun.setColor(Color::ORANGE);

    Text sunText({0, 0}, 50, "Soleil");
    sunText.setColor(Color::RED);
    sunText.setZIndex(1);

    ShapeGroup sunGroup;
    sunGroup.addShape(&sun);
    sunGroup.addShape(&sunText);


    Circle earth({150, 0}, 40);
    earth.setColor(Color::CYAN);

    Circle earthPath({0, 0}, 315);
    earthPath.setBorderColor(Color::WHITE);
    earthPath.setZIndex(-1);

    Text earthText({150, 0}, 20, "Terre");
    earthText.setColor(Color::GREEN);
    earthText.setZIndex(1);

    client.send(InitRendererPacket());
    client.send(DrawShapePacket(sun));
    client.send(DrawShapePacket(sunText));
    client.send(DrawShapePacket(earth));
    client.send(DrawShapePacket(earthPath));
    client.send(DrawShapePacket(earthText));


    ShapeGroup earthGroup;
    earthGroup.addShape(&earth);
    earthGroup.addShape(&earthPath);

    scene.add(&sun);
    scene.add(&earthGroup);

    SceneDao sceneDao;
    sceneDao.save("solarSystem.json", &scene);

    return 0;
}


