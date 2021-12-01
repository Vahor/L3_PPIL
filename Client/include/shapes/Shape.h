//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_SHAPE_H
#define CLIENT_SHAPE_H

#include "json/JsonObject.h"
#include "json/JsonPrimitive.h"
#include "Color.h"

class Shape : public JsonObject {


public:

    Shape(const string& actionName) : JsonObject() {
        addChildren("_action", new JsonPrimitive(actionName));
    }

    void setColor(const Color* color){
        addChildren("color", (JsonObject *) color);
    }
};


#endif //CLIENT_SHAPE_H
