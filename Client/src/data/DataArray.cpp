//
// Created by Nathan David on 02/02/2022.
//

#include "data/DataArray.h"
#include "data/Parser.h"

string DataArray::serialize(const Parser &parser) const {
    return parser.serialize(this);
}
string DataArray::toString() const {
    return std::string();
}

