//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_ASCENE_H
#define CLIENT_ASCENE_H

#include <string>
#include <vector>
#include "api/shape/Shape.h"
#include "api/handler/Handler.h"

using namespace std;

class AScene {

protected:
    string name;
    int height;
    int width;
    vector<Shape *> shapes;

public:

    AScene(const AScene &copy) {
        cout << "copy AScene" << endl;
        // todo
    }

    AScene() {}

    virtual ~AScene() {
        cout << "delete AScene" << endl;
        // todo
    }

    virtual AScene *clone() const = 0;

    virtual ADataElement *serialize() const = 0;

    void add(Shape *shape) {
        shapes.push_back(shape->clone());
    }

    // Setters
    void setHeight(int _height) { this->height = _height; }
    void setWidth(int _width) { this->width = _width; }
    void setName(const string& _name) { this->name = _name; }

    // Getters
    string getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }

};


#endif //CLIENT_ASCENE_H
