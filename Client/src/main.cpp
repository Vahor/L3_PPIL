#include "client/TCPClient.h"
#include "cli/Cli.h"

#include "shapes/Circle.h"
#include "shapes/Text.h"
#include "shapes/Line.h"

#include "scene/SceneDao.h"
#include "scene/Scene.h"

//#include "cli/commands/ExitCommand.h"
//#include "cli/commands/HelpCommand.h"
//#include "cli/commands/LoadCommand.h"
//#include "cli/commands/SaveCommand.h"
//#include "cli/commands/ListCommand.h"
//#include "cli/commands/ReconnectCommand.h"
#include "cli/commands/DrawCommand.h"
//#include "cli/commands/ShapeCommand.h"

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

    Line line({60, 50}, {100, 100});
    line.setColor(Color::BLACK);

    ShapeGroup earthGroup;
    earthGroup.addShape(&earth);
    earthGroup.addShape(&moon);
    earthGroup.addShape(&earthText);

    ShapeGroup everything;
    everything.addShape(&earthGroup);
    everything.addShape(&sunGroup);
    everything.addShape(&line);

    scene.add(&everything);

    SceneDao::getInstance()->save("solarSystem.json", &scene);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing", false);
    bool scale = true;
    Point2D center(500, 0);
    while (true) {
        scene.draw(visitor);
        double rad = 10 * M_PI / 180;
//        everything.zoom(center, scale ? 2 : 1);
//        everything.rotate({0, 0}, rad);

        visitor.setReuseSameWindow(true);
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

        visitor.setReuseSameWindow(true);
        usleep(2000 * 1000);
    }
    //SceneDao::getInstance()->save("textTest.json", &scene);
}

void dvdTest() {

    Scene scene;
    int width = 500;
    int width_2 = width / 2;
    int height = 250;
    int height_2 = height / 2;

    scene.setWidth(width);
    scene.setHeight(height);
    scene.setName("DVD Animation Test");

    ShapeGroup DVD;

    double rectangleHeight = 20;
    double rectangleWidth = 40;
    double fontSize = 20;

    Text text({(-fontSize / 2), (-fontSize / 2)}, (int) fontSize, "DVD");
    text.setColor(Color::WHITE);

    Polygon rectangle;

    rectangle.addPoint({-rectangleWidth, -rectangleHeight});
    rectangle.addPoint({-rectangleWidth, rectangleHeight});
    rectangle.addPoint({rectangleWidth, rectangleHeight});
    rectangle.addPoint({rectangleWidth, -rectangleHeight});
    rectangle.setColor(Color::BLACK);

    DVD.addShape(&rectangle);
    //DVD.addShape(&text);

    scene.add(&DVD);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing", false);

    double speed = 5;
    double motX = 1;
    double motY = 1;

    while (true) {
        scene.draw(visitor);

        Point2D *currentPosition = DVD.getCenter();
        int currentX = currentPosition->getX();
        int currentY = currentPosition->getY();

        bool changeColor = false;

        if ((currentX - rectangleWidth) <= -width_2 || (currentX + rectangleWidth) >= width_2) {
            motX = -motX;
            changeColor = true;
        }

        if ((currentY - rectangleHeight) <= -height_2 || (currentY + rectangleHeight) >= height_2) {
            motY = -motY;
            changeColor = true;
        }

        if (changeColor) {
            double r = rand() % 255;
            double g = rand() % 255;
            double b = rand() % 255;
            DVD.setColor(new Color(r, g, b, 255));
        }

        DVD.translate(motX * speed, motY * speed);

        visitor.setReuseSameWindow(true);
        usleep(100 * 1000);
    }


}

void alexTest() {
    Scene scene;
    scene.setWidth(400);
    scene.setHeight(400);
    scene.setBackgroundColor(Color::BLACK);


    Circle center({0, 0}, 5);
    center.setColor(Color::GREEN);

    Circle circle1({-150, 60}, 5);

    Polygon square;
    square.addPoint({-120, 100});
    square.addPoint({-150, 100});
    square.addPoint({-150, 130});
    square.addPoint({-120, 130});


    Polygon triangle;
    triangle.addPoint({-20, 60});
    triangle.addPoint({0, 90});
    triangle.addPoint({20, 60});


    Line line({-150, 60}, {0, 95});

    Text text({30, 30}, 10, "Yey salut");

    Circle circleText({30, 30}, 5);

    Polygon textBox;
    textBox.setBorderColor(Color::RED);
    textBox.addPoint({25, 25});
    textBox.addPoint({25, 40});
    textBox.addPoint({90, 40});
    textBox.addPoint({90, 25});

    ShapeGroup inner;

    inner.addShape(&circle1);
    inner.addShape(&square);
    inner.addShape(&triangle);
    inner.addShape(&line);

    inner.addShape(&text);
    inner.addShape(&circleText);
    inner.setColor(Color::CYAN);

    ShapeGroup group;
    group.addShape(&inner);
    group.addShape(&textBox);

    DrawOverJavaTcp visitor = DrawOverJavaTcp("swing");

    ShapeGroup clone = *group.clone();

    clone.rotate({0, 0}, degToRad(-25));
    clone.zoom(*center.getCenter(), .5);

    clone.regenerateId();
    clone.regenerateChildrenIds();
    clone.getChildrenById(12)->setColor(Color::YELLOW);

    scene.add(&group);
    scene.add(&clone);
    scene.add(&center);

    scene.setName("Test de scene");

    scene.draw(visitor);
}

int main() {

    Client *client = TCPClient::getInstance();
    client->connect("127.0.0.1", 10000);
    dvdTest();
    getchar();

//        Cli *cli = Cli::getInstance();
//        cli->setPrefix("\033[32mcli > \033[37m");
//
//        cli->addCommand("exit", new ExitCommand());
//        cli->addCommand("help", new HelpCommand());
//        cli->addCommand("load", new LoadCommand());
//        cli->addCommand("save", new SaveCommand());
//        cli->addCommand("list", new ListCommand());
//        cli->addCommand("draw", new DrawCommand());
//        cli->addCommand("reconnect", new ReconnectCommand());
//        cli->addCommand("shape", new ShapeCommand());
//
//        cli->init();


    return 0;
}

