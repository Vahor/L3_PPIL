//
// Created by Nathan David on 01/12/2021.
//
#pragma once


#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"
#include "data/DataImpl.h"
#include "handler/Handler.h"
#include "Point2D.h"

class ShapeGroup;

class Shape {

    // Meta
    Color color = Color::TRANSPARENT;
    Color borderColor = Color::TRANSPARENT;
    int id;
    int zIndex = 0;
    bool visible = true;
    ShapeGroup *group = nullptr;

public:

    static int previousId;

    Shape() : id(nextId()) {}

    /**
     * Méthode appelée lorsqu'on veut enregistrer une forme en un objet neutre.
     * @return L'objet actuel sous forme ADataElement
     */
    virtual DataElement *serialize() const = 0;

    virtual string toString() const = 0;

    /**
     * Ajoutes les variables metas communes à chaque formes
     * @param object Object dans lequel on va ajouter l'objet meta
     * @return Objet meta
     */
    virtual DataObject *addMetaData(DataObject *object) const;

    virtual Shape *clone() const = 0;

    virtual ~Shape();

    // setters
    void setColor(const Color &v) { this->color = v; }
    void setBorderColor(const Color &v) { this->borderColor = v; }
    void setId(const int v) {
        // Les nombres positifs seront ceux générés automatiquement.
        // Pour ceux chargés depuis un fichier, on ne veut pas de superposition,`
        //  pour éviter ça, on va utiliser les nombres négatifs
        if (v > 0) cerr << "Utilisation d'un id positif, l'id n'est pas garanti d'être unique" << endl;
        this->id = v;
    }
    static int nextId() { return previousId++; }
    void setVisible(bool b) { this->visible = b; }
    void setZIndex(int v) { this->zIndex = v; }
    void setGroup(ShapeGroup *v) { this->group = v; }

    // getters
    virtual Point2D *getCenter() const = 0;
    Color getColor() const { return color; }
    int getId() const { return id; }
    bool getVisible() const { return visible; }

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

// ShapeGroup

class ShapeGroup : public Shape {

    std::vector<Shape *> elements;

public:

    ShapeGroup() : Shape() {}
    ShapeGroup(const ShapeGroup &copy) : Shape(copy) {
        for (const auto &it: copy.elements) { addShape(it->clone()); }
    }

    void addShape(Shape *shape) {
        elements.push_back(shape);
        shape->setGroup(this);
    }

    void removeShape(Shape *shape) {
        elements.erase(std::find(elements.begin(), elements.end(), shape));
    }

    DataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        auto *items = new DataArrayImpl();

        for (Shape *shape: elements) {
            items->add(shape->serialize());
        }

        data->put("items", items);

        object->put("GROUP", data);

        Shape::addMetaData(object);

        return object;
    }

    string toString() const override {
        string res = "ShapeGroup[";
        for (auto *shape: elements) {
            res += shape->toString();
        }
        res += "]";
        return res;
    }

    Shape *clone() const override {
        return new ShapeGroup(*this);
    }

    Point2D *getCenter() const override {
        return new Point2D(0, 0); // todo
    }

    double getArea() const override {
        double res = 0;
        for (Shape *shape: elements) {
            res += shape->getArea();
        }
        return res;
    }

    void scale(int scale) override {
        for (Shape *shape: elements) {
            shape->scale(scale);
        }
    }

    void translate(double x, double y) override {
        for (Shape *shape: elements) {
            shape->translate(x, y);
        }
    }

    void rotate(const Point2D &center, double deg) override {
        for (Shape *shape: elements) {
            shape->rotate(center, deg);
        }
    }


    // Iterator

    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }

};



