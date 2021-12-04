//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_JSONSCENE_H
#define CLIENT_JSONSCENE_H

#include "api/scene/AScene.h"
#include "data/json/JsonObject.h"
#include "data/json/JsonArray.h"
#include "data/json/JsonObject.h"

class JsonScene : public AScene {


public:


    static JsonScene *parse(const ADataObject &object, const Handler<ADataObject, Shape *> *handler) {

        ADataObject *window = object.get("window")->getAsObject();
        auto *scene = new JsonScene;

        scene->setName(window->get("name")->getAsPrimitive()->getAsString());
        scene->setHeight(window->get("height")->getAsPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsPrimitive()->getAsInt());

        ADataArray *items = object.get("items")->getAsArray();
        for (ADataElement *element: *items) {
            Shape *shape = handler->solve(*element->getAsObject());
            if (shape != nullptr)
                scene->shapes.push_back(shape);
        }

        return scene;
    }

    virtual JsonScene *clone() const {
        cout << "copy JsonScene" << endl;
        return new JsonScene(*this);
    }

    JsonObject *serialize() const {
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
};


#endif //CLIENT_JSONSCENE_H
