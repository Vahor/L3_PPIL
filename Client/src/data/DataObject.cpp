//
// Created by Nathan David on 02/02/2022.
//

#include "data/DataObject.h"
#include "data/Parser.h"

string DataObject::serialize(const Parser &parser) const {
    return parser.serialize(this);
}

string DataObject::toString() const {
    string res = "{";

    for (const auto &it: children) {
        DataElement *element = it.second;
        res += '"' + it.first + "\":";
        res += element->toString();

        res += ",";
    }

    if (res.length() > 1)
        res.pop_back();

    res += "}";
    return res;
}