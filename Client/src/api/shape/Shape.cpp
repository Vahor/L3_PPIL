//
// Created by Nathan David on 11/12/2021.
//

#include "shapes/Shape.h"

int Shape::previousId = 1;

DataObject *Shape::addMetaData(DataObject *object, bool ignoreGroup) const {
    DataObject *metaObject;

    if (object->has("meta"))
        metaObject = object->get("meta")->getAsObject();
    else
        metaObject = new DataObjectImpl();

    metaObject->put("id", new DataPrimitiveImpl(id));

    // Si la valeur est égale à la valeur par défaut, on ne fait rien
    // pour ne pas stocker des gros fichier pour rien

    bool useGroup = group != nullptr && !ignoreGroup;

    // Color
    Color metaColor = (useGroup && group->color != Color::TRANSPARENT) ? group->color : color;
    if (metaColor != Color::TRANSPARENT)
        metaObject->put("color", &metaColor);

    // BorderColor
    Color metaBorderColor = (useGroup && group->color != Color::TRANSPARENT) ? group->borderColor : borderColor;
    if (metaBorderColor != Color::TRANSPARENT)
        metaObject->put("borderColor", &metaBorderColor);

    // zIndex
    int metaZIndex = (useGroup) ? group->zIndex + zIndex : zIndex;
    if (metaZIndex != 0)
        metaObject->put("zIndex", new DataPrimitiveImpl(metaZIndex));

    // vsible
    bool metaVisible = (useGroup) ? group->visible : visible;
    if (!metaVisible)
        metaObject->put("visible", new DataPrimitiveImpl(metaVisible));

    // groupId
    if (useGroup)
        metaObject->put("group", new DataPrimitiveImpl(group->getId()));

    object->put("meta", metaObject);
    return metaObject;
}

Shape::~Shape() {
    cout << "Delete AShape" << endl;
    if (group != nullptr)
        group->removeShape(this);
}
