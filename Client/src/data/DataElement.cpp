//
// Created by Nathan David on 26/01/2022.
//
#include "data/DataArray.h"
#include "data/DataObject.h"
#include "data/DataPrimitive.h"
#include "data/DataElement.h"
#include "scene/SceneDao.h"


DataObject *DataElement::getAsObject() const {
    return (DataObject *) this;
}
DataArray *DataElement::getAsArray() const {
    return (DataArray *) this;
}
DataPrimitive *DataElement::getAsPrimitive() const {
    return (DataPrimitive *) this;
}
ostream &operator<<(ostream &os, const DataElement &element) {
    return os << element.toString();
}

string typeToString(Type type) {
    return enumStr[type];
}