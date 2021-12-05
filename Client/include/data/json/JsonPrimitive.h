//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONPRIMITIVE_H
#define CLIENT_JSONPRIMITIVE_H


#include "api/data/ADataPrimitive.h"

using namespace std;


class JsonPrimitive : public ADataPrimitive {


public:
    JsonPrimitive(const string &value) : ADataPrimitive(value) {}
    JsonPrimitive(int value) : ADataPrimitive(value) {}
    JsonPrimitive(bool value) : ADataPrimitive(value) {}
    JsonPrimitive(double value) : ADataPrimitive(value) {}

    virtual JsonPrimitive *clone() const {
        return new JsonPrimitive(*this);
    }

    virtual string toString() const {
        return '"' + value + '"';
    }

};


#endif //CLIENT_JSONPRIMITIVE_H
