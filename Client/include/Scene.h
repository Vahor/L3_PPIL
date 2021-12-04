//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_SCENE_H
#define CLIENT_SCENE_H

#include <string>
#include <vector>
#include "shapes/Shape.h"
#include "handler/Handler.h"

using namespace std;

class Scene {

    string name;
    int height;
    int width;
    vector<Shape *> shapes;

public:

    static Scene *parse(const JsonObject &object, const Handler<ADataObject, Shape* > *handler) {

        ADataObject *window = object.get("window")->getAsObject();
        auto *scene = new Scene(window->get("name")->getAsPrimitive()->getAsString());

        scene->setHeight(window->get("height")->getAsPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsPrimitive()->getAsInt());

        ADataArray *items = object.get("items")->getAsArray();
        for(ADataElement* element : *items){
            Shape* shape = handler->solve(*element->getAsObject());
            if(shape != nullptr)
                scene->shapes.push_back(shape);
        }

        return scene;
    }

    Scene(const string &name) : name(name) {

    }

    Scene(const Scene &copy) {
        //cout << "copy JsonArray" << endl;
        // todo
    }

    ~Scene() {
        //cout << "delete JsonObject" << endl;
        // todo
    }

    virtual Scene *clone() const {
        return new Scene(*this);
    }


    virtual ADataElement *serialize() const {
        auto *object = new JsonObject();
        auto *window = new JsonObject();
        auto *items = new JsonArray();

        window->put("name", new JsonPrimitive(name));
        window->put("height", new JsonPrimitive(to_string(height)));
        window->put("width", new JsonPrimitive(to_string(width)));

        for (auto &shape: shapes) {
            items->add(shape->serialize());
        }

        object->put("window", window);
        object->put("items", items);

        return object;
    }

    void add(Shape *shape) {
        shapes.push_back(shape->clone());
    }

    // Setters
    void setHeight(int _height) { this->height = _height; }

    void setWidth(int _width) { this->width = _width; }

    // Getters
    string getName() { return name; }

    int getHeight() { return height; }

    int getWidth() { return width; }

};


#endif //CLIENT_SCENE_H
