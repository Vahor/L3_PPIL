//
// Created by Nathan David on 11/12/2021.
//

#include "api/shape/AShape.h"

int AShape::previousId = 1;
ADataObject *AShape::addMetaData(ADataObject *object) const {
    ADataObject *metaObject;

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
    if (!name.empty())
        metaObject->put("name", new DataPrimitiveImpl(name));
    if (showName)
        metaObject->put("showName", new DataPrimitiveImpl(showName));

    if (!visible)
        metaObject->put("visible", new DataPrimitiveImpl(visible));

    if (group != nullptr)
        metaObject->put("group", new DataPrimitiveImpl(group->getId()));

    object->put("meta", metaObject);
    return metaObject;
}

AShape::~AShape() {
    cout << "Delete AShape" << endl;
    if (group != nullptr)
        group->removeShape(this);
}
