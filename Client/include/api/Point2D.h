//
// Created by Nathan David on 13/12/2021.
//

#ifndef CLIENT_POINT2D_H
#define CLIENT_POINT2D_H

class Point2D {

    double x;
    double y;

public:

    Point2D(double x, double y) : x(x), y(y) {}


    ADataElement *serialize() const {
        auto *object = new DataObjectImpl();
        object->put("x", new DataPrimitiveImpl(x));
        object->put("y", new DataPrimitiveImpl(y));
        return object;
    }

    Point2D *clone() const {
        return new Point2D(*this);
    }
};

#endif //CLIENT_POINT2D_H
