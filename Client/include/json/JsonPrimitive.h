//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONPRIMITIVE_H
#define CLIENT_JSONPRIMITIVE_H


#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

#include "json/JsonElement.h"

class JsonPrimitive : public JsonElement {

    string value;

public:
    JsonPrimitive(string value) : value(std::move(value)) {}

    virtual JsonPrimitive *clone() const {
        return new JsonPrimitive(*this);
    }


    int getAsInt() const { return stoi(value); }
    string getAsString() const { return value; }

    virtual string toString() const {
        return '"' + value + '"';
    }

};


#endif //CLIENT_JSONPRIMITIVE_H
