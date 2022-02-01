#include "client/TCPClient.h"
#include "cli/Cli.h"

#include "shapes/Circle.h"
#include "shapes/Text.h"

#include "scene/SceneDao.h"
#include "scene/Scene.h"

#include "cli/commands/ExitCommand.h"
#include "cli/commands/HelpCommand.h"
#include "cli/commands/LoadCommand.h"
#include "cli/commands/SaveCommand.h"
#include "cli/commands/ListCommand.h"
#include "cli/commands/ReconnectCommand.h"
#include "cli/commands/DrawCommand.h"
#include "cli/commands/ShapeCommand.h"

void solar() {

    Scene scene;
    scene.setName("SolarSystem");
    scene.setHeight(500);
    scene.setWidth(1000);


    Circle sun({0, 0}, 150);
    sun.setColor(Color::ORANGE);

    Text sunText({0, 0}, 50, "Soleil");
    sunText.setColor(Color::BLACK);
    sunText.setAngleDeg(135);


    Polygon sunPolygon;
    sunPolygon.addPoint(Point2D({100, 100}));
    sunPolygon.addPoint(Point2D({100, 50}));
    sunPolygon.addPoint(Point2D({50, 50}));
    sunPolygon.setColor(Color::RED);

    Text polygonText({100, 100}, 10, "polygonText");
    polygonText.setColor(Color::BLACK);
    polygonText.setAngleDeg(-135);

    ShapeGroup sunGroup;
    sunGroup.addShape(&sun);
    sunGroup.addShape(&sunText);

    sunGroup.addShape(&sunPolygon);
    sunGroup.addShape(&polygonText);

    Circle earth({150, 0}, 40);
    earth.setColor(Color::CYAN);

    Circle moon({180, 0}, 5);
    moon.setColor(Color::LIGHT_GRAY);

    Text earthText({150, 0}, 20, "Terre");
    earthText.setColor(Color::BLACK);
    earthText.setAngleDeg(180);

    ShapeGroup earthGroup;
    earthGroup.addShape(&earth);
    earthGroup.addShape(&moon);
    earthGroup.addShape(&earthText);

    ShapeGroup everything;
    everything.addShape(&earthGroup);
    everything.addShape(&sunGroup);

    scene.add(&everything);

    SceneDao::getInstance()->save("solarSystem.json", &scene);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing", false);
    bool scale = true;
    while (true) {
        scene.draw(visitor);
        double rad = 10 * M_PI / 180;
        everything.scale(scale ? 2 : .5);
        everything.rotate({0, 0}, rad);
        for (auto shape: earthGroup) {
            double r = rand() % 255;
            double g = rand() % 255;
            double b = rand() % 255;
            shape->setColor(new Color(r, g, b, 255));
        }

        visitor.setReset(true);
        usleep(500 * 1000);
        scale = !scale;
    }
}

void textTest() {
    Scene scene;
    scene.setName("textTest");
    scene.setHeight(500);
    scene.setWidth(1000);


    ShapeGroup everything;

    double y = 200;
    double x = -480;
    for (int i = 1; i < 360; i++) {
        Text *text = new Text({x, y}, 15, to_string(i));
        text->setColor(Color::BLACK);
        text->setAngleDeg(i);

        x += 50;

        if (i % 20 == 0) {
            y -= 50;
            x = -480;
        }


        everything.addShape(text);
    }

    scene.add(&everything);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing", false);
    srand(time(nullptr));
    while (true) {
        scene.draw(visitor);
        double rad = 90 * M_PI / 180;
        everything.rotate({0, 0}, rad);
        double r = rand() % 255;
        double g = rand() % 255;
        double b = rand() % 255;
        everything.setColor(new Color(r, g, b, 255));

        visitor.setReset(true);
        usleep(2000 * 1000);
    }
    //SceneDao::getInstance()->save("textTest.json", &scene);
}

int main() {

    Client *client = TCPClient::getInstance();
    client->connect("127.0.0.1", 10000);
    solar();

    Cli *cli = Cli::getInstance();
    cli->setPrefix("\033[32mtruc > \033[37m");

    cli->addCommand("exit", new ExitCommand());
    cli->addCommand("help", new HelpCommand());
    cli->addCommand("load", new LoadCommand());
    cli->addCommand("save", new SaveCommand());
    cli->addCommand("list", new ListCommand());
    cli->addCommand("draw", new DrawCommand());
    cli->addCommand("reconnect", new ReconnectCommand());
    cli->addCommand("shape", new ShapeCommand());

    // TODO : Ajouter une commande pour initialiser le parser

    cli->init();


    return 0;
}

