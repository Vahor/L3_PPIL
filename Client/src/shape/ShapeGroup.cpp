//
// Created by Nathan David on 02/02/2022.
//

#include "shapes/ShapeGroup.h"

DataElement *ShapeGroup::toDataElement0(bool ignoreGroup) const {
    auto *object = new DataObject();

    auto data = DataObject();
    auto items = DataArray();

    for (Shape *shape: elements) {
        items.add(shape->toDataElement(ignoreGroup));
    }

    data.put("items", items);

    object->put("GROUP", data);

    return object;
}
Point2D *ShapeGroup::getCenter() const {
    auto count = (double) elements.size();
    double sumX = 0;
    double sumY = 0;
    for (Shape *shape: elements) {
        Point2D *center = shape->getCenter();
        sumX += center->getX();
        sumY += center->getY();
    }
    return new Point2D(sumX / count, sumY / count);
}
Shape *ShapeGroup::getChildrenById(int id) const {
    for (Shape *shape: elements) {
        if (auto *group = dynamic_cast<const ShapeGroup *>(shape)) {
            if (group->getId() == id) return shape;
            return group->getChildrenById(id);
        } else {
            if (shape->getId() == id) return shape;
        }
    }
    return nullptr;
}
