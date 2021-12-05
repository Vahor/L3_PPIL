//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_SHAPE_H
#define CLIENT_SHAPE_H

#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"
#include "data/DataImpl.h"

class Shape {

    // Meta
    Color color;
    string name;
    bool showName = false;
    bool visible = true;


public:

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
    virtual ADataObject* addMetaData(ADataObject *object) const {
        ADataObject *metaObject;

        if (object->has("meta"))
            metaObject = object->get("meta")->getAsObject();
        else
            metaObject = new DataObjectImpl();

        metaObject->put("color", &color);
        metaObject->put("name", new DataElementImpl(name));
        metaObject->put("showName", new DataElementImpl(showName));
        metaObject->put("visible", new DataElementImpl(visible));

        object->put("meta", metaObject);
        return metaObject;
    }

    virtual Shape *clone() const = 0;

    virtual ~Shape() {
        cout << "delete shape" << endl;
    }

    // setters
    void setColor(const Color &color) {
        this->color = color;
    }
    void setName(const string &name) { this->name = name; }
    void setVisible(bool b) { this->visible = b; }
    void setShowName(bool b) { this->showName = b; }

    // getters
    Color getColor() const { return color; }
    string getName() const { return name; }
    bool getVisible() const { return visible; }
    bool getShowName() const { return showName; }


    virtual double getArea() const = 0;


};


#endif //CLIENT_SHAPE_H
