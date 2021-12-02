//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_JSONARRAY_H
#define CLIENT_JSONARRAY_H

#include <iostream>
#include <string>

using namespace std;

#include "json/JsonElement.h"

class JsonArray : public JsonElement {

    vector<JsonElement*> children;

public:
    JsonArray(){}
    JsonArray(const JsonArray *copy) {
        cout << "copy" << endl;
    }
    ~JsonArray(){
        // todo
    }

    void addChildren(JsonElement *json) {
        children.push_back(json->clone());
    }

    virtual JsonArray *clone() const {
        return new JsonArray(*this);
    }

    virtual string toString() const {
        string res = "[";

        for (auto it = children.begin(); it != children.end(); ++it) {
            JsonElement* element = *it;
            res += element->toString();

            if(std::next(it) != children.end()) {
                res += ",";
            }
        }

        res += "]";
        return res;
    }

};


#endif //CLIENT_JSONARRAY_H
