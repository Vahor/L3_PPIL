#include "client/TCPClient.h"
#include "shapes/Circle.h"

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

    Circle sun(0, 0, 150);
    sun.setColor(Color::ORANGE);
    sun.setName("sun");

    Circle earth(150, 0, 40);
    earth.setColor(Color::CYAN);

    Circle earthPath(0, 0, 310);
    earthPath.setBorderColor(Color::WHITE);
    earthPath.setZIndex(-1);

    client.send(InitRendererPacket());
    client.send(DrawShapePacket(sun));
    client.send(DrawShapePacket(earth));
    client.send(DrawShapePacket(earthPath));

    ShapeGroup earthGroup;
    earthGroup.addShape(&earth);
    earthGroup.addShape(&earthPath);

    scene.add(&sun);
    scene.add(&earthGroup);

    SceneDao sceneDao;
    sceneDao.save("solarSystem.json", &scene);

    return 0;
}


