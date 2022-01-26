//
// Created by Nathan David on 11/12/2021.
//

#include "shapes/Shape.h"

DataObject *Shape::addMetaData(DataObject *object, bool ignoreGroup) const {
    DataObject *metaObject;

    if (object->has("meta"))
        metaObject = object->get("meta")->getAsObject();
    else
        metaObject = new DataObjectImpl();

    // Si la valeur est égale à la valeur par défaut, on ne fait rien
    // pour ne pas stocker des gros fichier pour rien

    bool useGroup = group != nullptr && !ignoreGroup;

    // Color
    Color *metaColor = (useGroup && group->color != nullptr) ? group->color : color;
    if (metaColor != nullptr)
        metaObject->put("color", metaColor);

    // BorderColor
    Color *metaBorderColor = (useGroup && group->color != nullptr) ? group->borderColor : borderColor;
    if (metaBorderColor != nullptr)
        metaObject->put("borderColor", metaBorderColor);

    object->put("meta", metaObject);
    return metaObject;
}

Shape::~Shape() {
    cout << "Delete AShape" << endl;
    if (group != nullptr)
        group->removeShape(this);
}
string Shape::_toString() const {
    string res = "Meta[";
    if (color)
        res += "color=" + color->toString() + ",";
    if (borderColor)
        res += "borderColor=" + borderColor->toString() + ",";
    if (group)
        res += "group=true,"; // todo afficher un id ?

    if (res.length() > 5)
        res.pop_back(); // On retire la dernière virgule

    res += "]";

    return res;
}
