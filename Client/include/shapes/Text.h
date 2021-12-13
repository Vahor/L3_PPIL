//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_TEXT_H
#define CLIENT_TEXT_H

#include <utility>

#include "api/shape/AShape.h"
#include "data/DataImpl.h"

class Text : public AShape {

private:

    Point2D position;
    int size;
    string value;

public:

    Text(Point2D position, int size, string value) :
            position(position),
            size(size),
            value(std::move(value)),
            AShape() {}

    ADataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        data->put("position", position.serialize());
        data->put("size", new DataPrimitiveImpl(size));
        data->put("value", new DataPrimitiveImpl(value));

        object->put("TEXT", data);

        AShape::addMetaData(object);

        return object;
    }

    Text *clone() const override {
        return new Text(*this);
    }

    double getArea() const override {
        return 0;
    }

};

#endif //CLIENT_TEXT_H
