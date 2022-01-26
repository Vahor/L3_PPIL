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
#include "actions/java/DrawOverJavaTcp.h"
#include "cli/commands/DrawCommand.h"

void solar(TCPClient &client) {

    Scene scene;
    scene.setName("SolarSystem");
    scene.setHeight(500);
    scene.setWidth(1000);


    Circle sun({0, 0}, 150);
    sun.setColor(Color::ORANGE);

    Text sunText({0, 0}, 50, "Soleil");
    sunText.setColor(Color::RED);
    sunText.rotateSelf(45);


    Polygon sunPolygon;
    sunPolygon.addPoint(new Point2D({100, 100}));
    sunPolygon.addPoint(new Point2D({100, 50}));
    sunPolygon.addPoint(new Point2D({50, 50}));
    sunPolygon.setColor(Color::RED);

    Text polygonText({100, 100}, 10, "polygonText");
    polygonText.setColor(Color::YELLOW);
    polygonText.rotateSelf(0);

    ShapeGroup sunGroup;
    sunGroup.addShape(&sun);
    sunGroup.addShape(&sunText);

    sunGroup.addShape(&sunPolygon);
    sunGroup.addShape(&polygonText);

    Circle earth({150, 0}, 40);
    earth.setColor(Color::CYAN);

    Circle earthPath({0, 0}, 315);
    earthPath.setBorderColor(Color::WHITE);

    Text earthText({150, 0}, 20, "Terre");
    earthText.setColor(Color::GREEN);
    earthText.rotateSelf(45);

    ShapeGroup earthGroup;
    earthGroup.addShape(&earthPath);
    earthGroup.addShape(&earth);
    earthGroup.addShape(&earthText);


    earthGroup.setColor(Color::RED);
    scene.add(&sunGroup);
    scene.add(&earthGroup);

    DrawOverJavaTcp visitor;
    scene.draw(visitor);

    SceneDao::getInstance()->save("solarSystem.json", &scene);
}

int main() {

    Client *client = TCPClient::getInstance();
    client->connect("127.0.0.1", 10000);

    Cli *cli = Cli::getInstance();
    cli->setPrefix("\033[32mtruc > \033[37m");

    cli->addCommand("exit", new ExitCommand());
    cli->addCommand("help", new HelpCommand());
    cli->addCommand("load", new LoadCommand());
    cli->addCommand("save", new SaveCommand());
    cli->addCommand("list", new ListCommand());
    cli->addCommand("draw", new DrawCommand());
    cli->addCommand("reconnect", new ReconnectCommand());

    // TODO : Ajouter une commande pour le calcul d'aire
    // TODO : Ajouter une commande pour initialiser le parser

    cli->init();


    return 0;
}

