//
// Created by Nathan David on 26/01/2022.
//
#include "data/DataArray.h"
#include "data/DataObject.h"
#include "data/DataPrimitive.h"
#include "data/DataElement.h"
#include "scene/SceneDao.h"


string DataArray::toString() const {
    return SceneDao::getInstance()->getParser()->toString(this);
}

string DataObject::toString() const {
    return SceneDao::getInstance()->getParser()->toString(this);
}

string DataPrimitive::toString() const {
    return SceneDao::getInstance()->getParser()->toString(this);
}

DataObject *DataElement::getAsObject() const {
    return (DataObject *) this;
}
DataArray *DataElement::getAsArray() const {
    return (DataArray *) this;
}
DataPrimitive *DataElement::getAsPrimitive() const {
    return (DataPrimitive *) this;
}
