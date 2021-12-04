//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONOBJECT_H
#define CLIENT_JSONOBJECT_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

#include "api/data/ADataObject.h"

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
class JsonObject : public ADataObject {


public:

    virtual JsonObject *clone() const {
        return new JsonObject(*this);
    }

    virtual string toString() const {
        string res = "{";

        for (auto it = children.begin(); it != children.end(); ++it) {
            ADataElement *element = it->second;
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


#endif //CLIENT_JSONOBJECT_H
