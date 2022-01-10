//
// Created by Nathan David on 11/12/2021.
//

#include "shapes/Shape.h"

int Shape::previousId = 1;
DataObject *Shape::addMetaData(DataObject *object) const {
    DataObject *metaObject;

    if (object->has("meta"))
        metaObject = object->get("meta")->getAsObject();
    else
        metaObject = new DataObjectImpl();

    metaObject->put("id", new DataPrimitiveImpl(id));

    // Si la valeur est égale à la valeur par défaut, on ne fait rien
    // pour ne pas stocker des gros fichier pour rien

    if (color != Color::TRANSPARENT)
        metaObject->put("color", &color);

    if (borderColor != Color::TRANSPARENT)
        metaObject->put("borderColor", &borderColor);

    if (zIndex != 0)
        metaObject->put("zIndex", new DataPrimitiveImpl(zIndex));

    if (!visible)
        metaObject->put("visible", new DataPrimitiveImpl(visible));

    if (group != nullptr)
        metaObject->put("group", new DataPrimitiveImpl(group->getId()));

    object->put("meta", metaObject);
    return metaObject;
}

Shape::~Shape() {
    cout << "Delete AShape" << endl;
    if (group != nullptr)
        group->removeShape(this);
}
