//
// Created by Nathan David on 02/02/2022.
//


#include "shapes/Line.h"

DataElement *Line::toDataElement0(bool ignoreGroup) const {
    auto *object = new DataObject();

    auto data = DataObject();

    data.put("from", from.toDataElement(ignoreGroup));
    data.put("to", to.toDataElement(ignoreGroup));

    object->put("LINE", data);

    return object;
}
