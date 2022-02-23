//
// Created by Nathan David on 02/02/2022.
//

#include "shapes/Circle.h"

DataElement *Circle::toDataElement0(bool ignoreGroup) const {
    auto *object = new DataObject();

    auto data = DataObject();
    data.put("position", position.toDataElement(ignoreGroup));
    data.put("diameter", DataPrimitive(diameter));

    object->put("CIRCLE", data);

    return object;
}
