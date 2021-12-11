//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_ASHAPE_H
#define CLIENT_ASHAPE_H

#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"
#include "Color.h"
#include "data/DataImpl.h"

class AShape {

    // Meta
    Color color = Color::TRANSPARENT;
    Color borderColor = Color::TRANSPARENT;
    string name;
    int id;
    int zIndex = 0;
    bool showName = false;
    bool visible = true;

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
    virtual ADataObject *addMetaData(ADataObject *object) const {
        ADataObject *metaObject;

        if (object->has("meta"))
            metaObject = object->get("meta")->getAsObject();
        else
            metaObject = new DataObjectImpl();

        metaObject->put("id", new DataPrimitiveImpl(id));
        metaObject->put("color", &color);
        metaObject->put("borderColor", &borderColor);
        metaObject->put("zIndex", new DataPrimitiveImpl(zIndex));
        metaObject->put("name", new DataPrimitiveImpl(name));
        metaObject->put("showName", new DataPrimitiveImpl(showName));
        metaObject->put("visible", new DataPrimitiveImpl(visible));

        object->put("meta", metaObject);
        return metaObject;
    }

    virtual AShape *clone() const = 0;

    virtual ~AShape() {
        cerr << "delete shape" << endl;
    }

    // setters
    void setColor(const Color &v) { this->color = v; }
    void setBorderColor(const Color &v) { this->borderColor = v; }
    void setName(const string &v) { this->name = v; }
    void setId(const int v) {
        // Les nombres positifs seront ceux générés automatiquement. Pour ceux chargés depuis un fichier, on ne veut pas de superposition, pour éviter ça, on va utiliser les nombres négatifs
        if (v > 0) cerr << "Utilisation d'un id positif, l'id n'est pas garanti d'être unique";
        this->id = v;
    }
    void generateId() { this->id = previousId++; }
    void setVisible(bool b) { this->visible = b; }
    void setShowName(bool b) { this->showName = b; }
    void setZIndex(int v) { this->zIndex = v; }

    // getters
    Color getColor() const { return color; }
    string getName() const { return name; }
    int getId() const { return id; }
    bool getVisible() const { return visible; }
    bool getShowName() const { return showName; }


    virtual double getArea() const = 0;


};

int AShape::previousId = 1;


#endif //CLIENT_ASHAPE_H
