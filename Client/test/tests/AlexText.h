//
// Created by Nathan David on 24/02/2022.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/json/JsonParser.h"
#include "scene/Scene.h"
#include <string>
#include <algorithm>

using namespace std;

class AlexText {

public:

    static void runTest(SimpleTest &test) {
        Scene scene;
        scene.setWidth(400);
        scene.setHeight(400);
        scene.setBackgroundColor(Color::BLACK);

        Circle circle1({-150, 60}, 50);

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
        Circle circleText({30, 30}, 20);

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

        ShapeGroup *clone = group.clone();

        cout << group << endl;

        test.assertTrue(group.toString() == clone->toString(), "Clone");

        clone->regenerateId();
        clone->regenerateChildrenIds();
        clone->getChildrenById(58)->setColor(Color::YELLOW);

        cout << *clone << endl;

        delete clone;
    }
};
