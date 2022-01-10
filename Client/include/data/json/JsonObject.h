//
// Created by Nathan David on 01/12/2021.
//
#pragma once


#include <iostream>
#include <map>
#include <string>

using namespace std;

#include "data/DataObject.h"

/**
 * Création de Json simples pour l'envoie de packets
 * @link{JsonObject.cpp} @link(JsonPrimitive.cpp}
 * Format possible de Json
 *
 * {
 *  'key': 'value',
 *  'key2': {
 *
 *  }
 */
class JsonObject : public DataObject {


public:

    JsonObject *clone() const override {
        return new JsonObject(*this);
    }

    string toString() const override {
        string res = "{";

        for (auto it = children.begin(); it != children.end(); ++it) {
            DataElement *element = it->second;
            res += '"' + it->first + "\":";
            res += element->toString();

            if (std::next(it) != children.end()) {
                res += ",";
            }
        }

        res += "}";
        return res;
    }

};



