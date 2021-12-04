//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_SHAPE_H
#define CLIENT_SHAPE_H

#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"

class Shape {


public:

    Shape(const string& name)  {
    }


    virtual ADataElement* serialize() const = 0;

    virtual Shape* clone() const = 0;

    void setColor(const Color* color){
    }
};


#endif //CLIENT_SHAPE_H
