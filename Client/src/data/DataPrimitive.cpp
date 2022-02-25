//
// Created by Nathan David on 02/02/2022.
//


#include "data/DataPrimitive.h"
#include "data/Parser.h"

string DataPrimitive::serialize(const Parser &parser) const {
    return parser.serialize(this);
}
string DataPrimitive::toString() const {
    return value;
}

