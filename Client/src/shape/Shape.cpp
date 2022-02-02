//
// Created by Nathan David on 11/12/2021.
//

#include "shapes/Shape.h"
#include "shapes/ShapeGroup.h"

int Shape::previousId = 1;

Shape::Shape(const Shape &copy) {
    this->color = copy.color;
    this->borderColor = copy.borderColor;
    this->id = copy.id;
    // Lorsqu'on clone un element, on ne clone pas le groupe !
}

Shape::~Shape() {
    if (group != nullptr)
        group->removeShape(this);
}


Color *getShapeColor(const Shape *shape, bool useGroup) {
    if (shape == nullptr) { return nullptr; }

    if (useGroup) {
        Color *parentColor = getShapeColor(shape->getGroup(), true);
        if (parentColor != nullptr) return parentColor;
    }
    return shape->getColor();
}

Color *getShapeBorderColor(const Shape *shape, bool useGroup) {
    if (shape == nullptr) { return nullptr; }

    if (useGroup) {
        Color *parentColor = getShapeBorderColor(shape->getGroup(), true);
        if (parentColor != nullptr) return parentColor;
    }

    return shape->getBorderColor();
}

DataObject *Shape::addMetaData(DataObject *object, bool ignoreGroup) const {
    DataObject *metaObject;

    if (object->has("meta"))
        metaObject = object->get("meta")->getAsObject();
    else
        metaObject = new DataObject();

    metaObject->put("id", DataPrimitive(id));

    // Si la valeur est égale à la valeur par défaut, on ne fait rien
    // pour ne pas stocker des gros fichier pour rien

    bool useGroup = !ignoreGroup;
    Color *shapeOrParentColor = getShapeColor(this, useGroup);
    Color *shapeOrParentBorderColor = getShapeBorderColor(this, useGroup);

    // Color
    metaObject->put("color", shapeOrParentColor);

    // BorderColor
    metaObject->put("borderColor", shapeOrParentBorderColor);

    object->put("meta", metaObject);

    return metaObject;
}


string Shape::getMetaString() const {
    string res = "Meta[";
    res += "id=" + to_string(id) + ",";
    if (color)
        res += "color=" + color->toString() + ",";
    if (borderColor)
        res += "borderColor=" + borderColor->toString() + ",";
    if (group)
        res += "group=" + to_string(group->getId()) + ",";

    res.pop_back(); // On retire la dernière virgule

    res += "]";

    return res;
}
DataElement *Shape::serialize(bool ignoreGroup) const {
    DataElement *element = serialize0(ignoreGroup);

    addMetaData(element->getAsObject(), ignoreGroup);
    return element;
}
void Shape::draw(const DrawVisitor &visitor) const {
    visitor.drawShape(this);
}
ostream &operator<<(ostream &os, const Shape &shape) {
    os << shape.toString();
    return os;
}
void Shape::setGroup(ShapeGroup *v) {
    if (group != nullptr)
        group->removeShape(this);
    this->group = v;
}
bool Shape::operator==(const Shape &rhs) const {
    return id == rhs.id;
}
bool Shape::operator!=(const Shape &rhs) const {
    return !(rhs == *this);
}
Shape *Shape::parse(const DataObject &object, const Handler<DataObject, Shape *> *shapeHandler,
                    const Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler) {
    Shape *shape = shapeHandler->solve(*object.getAsObject());
    if (shape != nullptr) {
        if (object.has("meta")) {
            DataObject *elementMeta = object.get("meta")->getAsObject();
            metaHandler->solve({elementMeta, shape});
        }
    }
    return shape;
}
