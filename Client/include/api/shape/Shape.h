//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_SHAPE_H
#define CLIENT_SHAPE_H

#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"

class Shape {

    // Meta
    Color color;
    string name;
    bool showName = false;
    bool visible = true;


public:

    virtual ADataElement *serialize() const = 0;

    virtual void addMetaData(ADataObject *object) const {
        ADataObject *metaObject;

        if (object->has("meta"))
            metaObject = object->get("meta")->getAsObject();
        else
            metaObject = new JsonObject();

        metaObject->put("color", &color);
        metaObject->put("name", new JsonPrimitive(name));
        metaObject->put("showName", new JsonPrimitive(showName));
        metaObject->put("visible", new JsonPrimitive(visible));

        object->put("meta", metaObject);
    }

    virtual Shape *clone() const = 0;

    virtual ~Shape() {
        cout << "delete shape" << endl;
    }

    // setters
    void setColor(const Color &color) {
        this->color = color;
    }
    void setName(const string &name) { this->name = name; }
    void setVisible(bool b) { this->visible = b; }
    void setShowName(bool b) { this->showName = b; }

    // getters
    Color getColor() const { return color; }
    string getName() const { return name; }
    bool getVisible() const { return visible; }
    bool getShowName() const { return showName; }


    virtual double getArea() const = 0;


};


#endif //CLIENT_SHAPE_H
