//
// Created by Nathan David on 01/12/2021.
//
#pragma once

#include <ostream>
#include "Serializable.h"
#include "Color.h"
#include "handler/Handler.h"
#include "Point2D.h"
#include "actions/DrawVisitor.h"

using namespace std;

class ShapeGroup;

class Shape : public Serializable {

    // Meta
    Color *color = nullptr;
    Color *borderColor = nullptr;
    ShapeGroup *group = nullptr;
    int id;

public:

    static int previousId;

    Shape() : id(nextId()) {}
    Shape(const Shape &copy);

    string getMetaString() const;
    /**
     * Transforme la forme en une chaine de caractere
     * compréhensible par un humain.
     *
     * @return Une chaine de caractere correspondant à la forme
     */
    virtual string toString() const = 0;
    explicit operator std::string() const { return toString(); }

    /**
     * Ajoutes les variables metas communes à chaque formes
     * @param object Object dans lequel on va ajouter l'objet meta
     * @return Objet meta
     */
    virtual DataObject *addMetaData(DataObject *object, bool ignoreGroup) const;

    /**
     * Clone l'élement actuel en gardant les propriétes de couleurs.<br />
     * Un nouvel identifiant est généré.
     * Le groupe n'est pas assigné lors du clonnage.
     *
     * @return Un clone de l'objet actuel, partageant des propriétes.
     */
    virtual Shape *clone() const = 0;

    virtual ~Shape();

    DataElement *toDataElement(bool ignoreGroup) const override;

    /**
     * Execute la méthode de dessin correspondante dans le visitor.
     * @param visitor Implémentation de dessin.
     */
    virtual void draw(const DrawVisitor &visitor) const;

    // setters
    void setColor(Color *v) { this->color = v; }
    void setBorderColor(Color *v) { this->borderColor = v; }
    void setGroup(ShapeGroup *v);
    void resetGroup() { this->group = nullptr; }
    void setId(const int v) { this->id = v; }
    static int nextId() { return previousId++; }

    // getters
    virtual Point2D *getCenter() const = 0;
    Color *getColor() const { return color; }
    Color *getBorderColor() const { return borderColor; }
    ShapeGroup *getGroup() const { return group; }
    bool isInGroup() const { return group != nullptr; }
    int getId() const { return id; }

    /**
     * Applique une transformation d'agrandissement sur la forme
     * Ne prend pas en compte les distances, seul les distances internes à la formes sont modifiées.
     *
     * @param scale Facteur d'agrandissement de la forme.
     */
    virtual void scale(double scale) = 0;

    /**
     * Appliqune une homothétie de la forme par rapport à un point.
     * Correspond à une translation suivie d'une agrandissement de la forme.
     *
     * @param center Point invariant de la transformation
     * @param scale Facteur d'agrandissement de la forme
     */
    virtual void zoom(const Point2D &center, double scale) = 0;

    /**
     * Décale la forme de {x} sur l'axe x et {y} sur l'axe y.
     *
     * @param x Offset for the x coordinate
     * @param y Offset for the y coordinate
     */
    virtual void translate(double x, double y) = 0;

    /**
     * Utiilise la méthode rotate avec le centre
     * de la forme comme point de rotation
     *
     * @see Shape::rotate
     * @param radians
     */
    void rotateSelf(double radians) { rotate(*getCenter(), radians); }

    /**
     * Applique une rotation de la forme d'un angle de {radians} radians.
     * Par rapport au point {center}
     *
     * @param center Point d'ancrage pour la rotation
     * @param radians Angle de rotation
     */
    virtual void rotate(const Point2D &center, double radians) = 0;


    /**
     * Retourne l'aire de la forme.
     * Ne prend pas en compte les superpositions de formes
     *
     * @return aire de la forme
     */
    virtual double getArea() const = 0;

    friend ostream &operator<<(ostream &os, const Shape &shape);
    bool operator==(const Shape &rhs) const;
    bool operator!=(const Shape &rhs) const;

    static Shape *parse(const DataObject &object,
                        const Handler<DataObject, Shape *> *shapeHandler,
                        const Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler
    );


};

