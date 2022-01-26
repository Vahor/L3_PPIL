//
// Created by Nathan David on 01/12/2021.
//
#pragma once

#include "Serializable.h"
#include "Color.h"
#include "handler/Handler.h"
#include "Point2D.h"
#include "actions/Visitor.h"

using namespace std;

class ShapeGroup;

class Shape : public Serializable {

    // Meta
    Color *color = nullptr;
    Color *borderColor = nullptr;
    ShapeGroup *group = nullptr;

public:

    Shape() = default;
    Shape(const Shape &copy);

    string _toString() const;
    virtual string toString() const = 0;
    explicit operator std::string() const { return toString(); }

    /**
     * Ajoutes les variables metas communes à chaque formes
     * @param object Object dans lequel on va ajouter l'objet meta
     * @return Objet meta
     */
    virtual DataObject *addMetaData(DataObject *object, bool ignoreGroup) const;

    virtual Shape *clone() const = 0;

    virtual ~Shape();

    DataElement *serialize(bool ignoreGroup) const override;

    virtual void draw(Visitor &visitor) const;

    // setters
    void setColor(Color *v) { this->color = v; }
    void setBorderColor(Color *v) { this->borderColor = v; }
    void setGroup(ShapeGroup *v) { this->group = v; }

    // getters
    virtual Point2D *getCenter() const = 0;
    Color *getColor() const { return color; }
    ShapeGroup *getGroup() const { return group; }
    bool isInGroup() const { return group != nullptr; }

    virtual void scale(int scale) = 0;
    virtual void translate(double x, double y) = 0;
    void rotateSelf(double deg) { rotate(*getCenter(), deg); }
    virtual void rotate(const Point2D &center, double deg) = 0;


    virtual double getArea() const = 0;

    static Shape *parse(const DataObject &object,
                        const Handler<DataObject, Shape *> *shapeHandler,
                        const Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler
    ) {
        Shape *shape = shapeHandler->solve(*object.getAsObject());
        if (shape != nullptr) {
            if (object.has("meta")) {
                DataObject *elementMeta = object.get("meta")->getAsObject();
                metaHandler->solve({elementMeta, shape});
            }
        }
        return shape;
    }


};

