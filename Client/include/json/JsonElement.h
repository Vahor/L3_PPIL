//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONELEMENT_H
#define CLIENT_JSONELEMENT_H

#include <string>
#include <utility>

class JsonObject;

class JsonArray;

class JsonPrimitive;

using namespace std;

class JsonElement {

public:

    virtual string toString() const = 0;

    virtual JsonElement *clone() const = 0;

    JsonObject *getAsJsonObject() const { return (JsonObject *) this; }

    JsonArray *getAsJsonArray() const { return (JsonArray *) this; }

    JsonPrimitive *getAsJsonPrimitive() const { return (JsonPrimitive *) this; }

    explicit operator string() const {
        return toString();
    }


};


#endif //CLIENT_JSONELEMENT_H
