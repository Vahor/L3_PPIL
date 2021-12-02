//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_SCENE_H
#define CLIENT_SCENE_H

#include <string>
#include <vector>
#include "json/JsonObject.h"
#include "shapes/Shape.h"

using namespace std;

class Scene {

    string name;
    int height;
    int width;
    vector<Shape *> shapes;

public:

    static Scene *parse(const JsonObject &object) {
        JsonObject *window = object.get("window")->getAsJsonObject();
        auto *scene = new Scene(window->get("name")->getAsJsonPrimitive()->getAsString());

        scene->setHeight(window->get("height")->getAsJsonPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsJsonPrimitive()->getAsInt());

        JsonArray *items = object.get("items")->getAsJsonArray();
        for (JsonElement *element: *items) {
            // todo
            cout << "Ajout de : " << element->getAsJsonObject()->get("type")->getAsJsonPrimitive()->getAsString()
                 << endl;
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


    virtual JsonElement *serialize() const {
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
