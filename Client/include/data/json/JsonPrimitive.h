//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONPRIMITIVE_H
#define CLIENT_JSONPRIMITIVE_H


#include "api/data/ADataPrimitive.h"

using namespace std;


class JsonPrimitive : public ADataPrimitive {


public:
    explicit JsonPrimitive(const string &value) : ADataPrimitive(value) {}
    explicit JsonPrimitive(int value) : ADataPrimitive(value) {}
    explicit JsonPrimitive(bool value) : ADataPrimitive(value) {}
    explicit JsonPrimitive(double value) : ADataPrimitive(value) {}

    JsonPrimitive *clone() const override {
        return new JsonPrimitive(*this);
    }

    string toString() const override {
        return '"' + value + '"';
    }

};


#endif //CLIENT_JSONPRIMITIVE_H
