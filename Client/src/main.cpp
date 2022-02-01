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
    sunPolygon.addPoint(new Point2D({100, 100}));
    sunPolygon.addPoint(new Point2D({100, 50}));
    sunPolygon.addPoint(new Point2D({50, 50}));
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

    Circle earthPath({0, 0}, 315);
    earthPath.setBorderColor(Color::WHITE);

    Text earthText({150, 0}, 20, "Terre");
    earthText.setColor(Color::BLACK);
    earthText.setAngleDeg(180);

    ShapeGroup earthGroup;
    earthGroup.addShape(&earthPath);
    earthGroup.addShape(&earth);
    earthGroup.addShape(&earthText);

    ShapeGroup everything;
    everything.addShape(&earthGroup);
    everything.addShape(&sunGroup);

    scene.add(&everything);

    SceneDao::getInstance()->save("solarSystem.json", &scene);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing", false);
    scene.draw(visitor);
}

void textTest() {
    Scene scene;
    scene.setName("textTest");
    scene.setHeight(500);
    scene.setWidth(1000);


    ShapeGroup everything;

    double y = 200;
    double x = -480;
    for (int i = 1; i < 3; i++) {
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
    // todo :
    //  La rotation de texte n'est toujours pas bonne, l'angle n'est pas bon
    //  Si on n'utilise que le radius ça fonctionne, mais si on décale le texte par la suite, ça ne marche plus
    while (true) {
        scene.draw(visitor);
        //everything.rotate({0, 0}, 1);
        double r = rand() % 255;
        double g = rand() % 255;
        double b = rand() % 255;
        everything.setColor(new Color(r, g, b, 255));

        visitor.setReset(true);
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

