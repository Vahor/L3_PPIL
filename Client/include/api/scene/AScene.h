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

    string name;
    int height = 500;
    int width = 900;
    vector<Shape *> shapes;

protected:
    void add2(Shape *shape) {
        shapes.push_back(shape->clone());
    }

public:

    AScene(const AScene &copy) {
        for (auto &shape: copy.shapes) {
            add(shape);
        }
        this->name = copy.name;
        this->height = copy.height;
        this->width = copy.width;
    }

    AScene() = default;

    virtual ~AScene() {
        cerr << "delete AScene" << endl;
        // todo
    }

    virtual AScene *clone() const = 0;

    virtual ADataElement *serialize() const = 0;

    void add(Shape *shape) {
        add2(shape->clone());
    }

    // Setters
    void setHeight(int _height) { this->height = _height; }
    void setWidth(int _width) { this->width = _width; }
    void setName(const string& _name) { this->name = _name; }

    // Getters
    string getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }


    // Iterator

    auto begin() { return &shapes[0]; }
    auto end() { return &shapes[shapes.size()]; }
    auto begin() const { return &shapes[0]; }
    auto end() const { return &shapes[shapes.size()]; }

};


#endif //CLIENT_ASCENE_H
