//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_ASHAPE_H
#define CLIENT_ASHAPE_H

#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"
#include "data/DataImpl.h"
#include "api/handler/Handler.h"

class ShapeGroup;

class AShape {

    // Meta
    Color color = Color::TRANSPARENT;
    Color borderColor = Color::TRANSPARENT;
    int id;
    int zIndex = 0;
    bool visible = true;
    ShapeGroup *group = nullptr;

public:

    static int previousId;

    AShape() { generateId(); }

    /**
     * Méthode appelée lorsqu'on veut enregistrer une forme en un objet neutre.
     * @return L'objet actuel sous forme ADataElement
     */
    virtual ADataElement *serialize() const = 0;

    /**
     * Ajoutes les variables metas communes à chaque formes
     * @param object Object dans lequel on va ajouter l'objet meta
     * @return Objet meta
     */
    virtual ADataObject *addMetaData(ADataObject *object) const;

    virtual AShape *clone() const = 0;

    virtual ~AShape();

    // setters
    void setColor(const Color &v) { this->color = v; }
    void setBorderColor(const Color &v) { this->borderColor = v; }
    void setId(const int v) {
        // Les nombres positifs seront ceux générés automatiquement. Pour ceux chargés depuis un fichier, on ne veut pas de superposition, pour éviter ça, on va utiliser les nombres négatifs
        if (v > 0) cerr << "Utilisation d'un id positif, l'id n'est pas garanti d'être unique" << endl;
        this->id = v;
    }
    void generateId() { this->id = previousId++; }
    void setVisible(bool b) { this->visible = b; }
    void setZIndex(int v) { this->zIndex = v; }
    void setGroup(ShapeGroup *v) { this->group = v; }

    // getters
    Color getColor() const { return color; }
    int getId() const { return id; }
    bool getVisible() const { return visible; }


    virtual double getArea() const = 0;

    static AShape *parse(const ADataObject &object,
                         const Handler<ADataObject, AShape *> *shapeHandler,
                         const Handler<pair<ADataObject *, AShape *>, AShape *> *metaHandler
    ) {
        AShape *shape = shapeHandler->solve(*object.getAsObject());
        if (shape != nullptr) {
            if (object.has("meta")) {
                ADataObject *elementMeta = object.get("meta")->getAsObject();
                metaHandler->solve({elementMeta, shape});
            }
        }
        return shape;
    }


};




// ShapeGroup

class ShapeGroup : public AShape {

    std::vector<AShape *> elements;

public:

    ShapeGroup() : AShape() {}
    ShapeGroup(const ShapeGroup &copy) : AShape(copy) {
        for (const auto &it: copy.elements) { addShape(it->clone()); }
    }

    void addShape(AShape *shape) {
        elements.push_back(shape);
        shape->setGroup(this);
    }

    void removeShape(AShape *shape) {
        elements.erase(std::find(elements.begin(), elements.end(), shape));
    }

    ADataElement *serialize() const {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        auto *items = new DataArrayImpl();

        for (AShape *shape: elements) {
            items->add(shape->serialize());
        }

        data->put("items", items);

        object->put("GROUP", data);

        AShape::addMetaData(object);

        return object;
    }

    AShape *clone() const {
        return new ShapeGroup(*this);
    }

    double getArea() const {
        double res = 0;
        for (AShape *shape: elements) {
            res += shape->getArea();
        }
        return res;
    }

};


#endif //CLIENT_ASHAPE_H
