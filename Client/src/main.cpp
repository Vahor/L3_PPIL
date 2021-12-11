#include "client/TCPClient.h"
#include "shapes/Circle.h"

#include "packet/DrawShapePacket.h"
#include "packet/InitRendererPacket.h"
#include "packet/RefreshRendererPacket.h"

int main() {

    TCPClient client("127.0.0.1", 10000);

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

    int i = 0;
    while (true) {
        Color color;
        color = i == 0 ? Color::ORANGE : Color::CYAN;
        sun.setColor(color);
        client.send(DrawShapePacket(sun));
        client.send(RefreshRendererPacket());
        sleep(1);
        i = 1 - i;
    }

    return 0;
}


