//
// Created by Nathan David on 02/12/2021.
//

#pragma once

#include <string>
#include <vector>
#include <ostream>
#include "actions/DrawVisitor.h"
#include "handler/Handler.h"
#include "client/Client.h"

#include "data/DataObject.h"
#include "data/DataArray.h"
#include "data/DataPrimitive.h"

#include "shapes/Shape.h"
#include "shapes/ShapeGroup.h"

using namespace std;

class Scene : public Serializable {

    string name;
    int height = 500;
    int width = 900;
    const Color *backgroundColor = Color::WHITE;
    vector<Shape *> shapes;

public:
    Scene() = default;

    Scene(const Scene &copy) {
        for (auto &shape: copy.shapes) {
            add(shape->clone());
        }
        this->name = copy.name;
        this->height = copy.height;
        this->width = copy.width;
    }

    static Scene *parse(const DataObject &object,
                        const Handler<DataObject, Shape *> *shapeHandler,
                        const Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler
    ) {

        DataObject *window = object.get("window")->getAsObject();
        auto *scene = new Scene();

        scene->setName(window->get("name")->getAsPrimitive()->getAsString());
        scene->setHeight(window->get("height")->getAsPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsPrimitive()->getAsInt());

        DataArray *items = object.get("items")->getAsArray();
        for (DataElement *element: *items) {
            DataObject *elementObject = element->getAsObject();
            Shape *shape = Shape::parse(*elementObject, shapeHandler, metaHandler);
            if (shape != nullptr) scene->add(shape);
        }

        return scene;
    }

    virtual ~Scene() {
        shapes.clear();
    }

    /**
     * Clone la scene en conservant ses propriétes <br/>
     * Toutes les formes sont aussi clonnées et ajoutées à la nouvelle scene.
     *
     * @return Un clone de l'objet actuel, partageant des propriétes.
     */
    virtual Scene *clone() const {
        return new Scene(*this);
    }

    DataElement *toDataElement0(bool ignoreGroup) const override {

        auto *object = new DataObject();

        auto window = DataObject();

        window.put("name", DataPrimitive(getName()));
        window.put("height", DataPrimitive(getHeight()));
        window.put("width", DataPrimitive(getWidth()));

        auto items = DataArray();
        for (auto &shape: shapes) {
            items.add(shape->toDataElement(ignoreGroup));
        }

        object->put("window", window);
        object->put("items", items);

        return object;
    };

    /**
     * Ajoutes une forme dans la scene.
     *
     * @param shape Forme à ajouter
     */
    void add(Shape *shape) {
        shapes.push_back(shape);
    }

    /**
     * Execute la méthode de dessin correspondante dans le visitor.
     * @param visitor Implémentation de dessin.
     */
    virtual void draw(const DrawVisitor &visitor) const {
        visitor.drawScene(this);
    }

    /**
     * Retourne la forme de la scene qui a comme identifiant `id`.
     * On cherche récursivement dans les groupes.
     *
     * @param id L'identifiant de la forme qu'on veut récupérer
     * @return La forme qui à l'identifiant recherché, ou nullptr si aucune forme ne correspond
     */
    Shape *getShapeById(int id) const {
        for (Shape *shape: shapes) {
            if (auto *group = dynamic_cast<const ShapeGroup *>(shape)) {
                if (group->getId() == id) return shape;
                return group->getChildrenById(id);
            } else {
                if (shape->getId() == id) return shape;
            }
        }
        return nullptr;
    }

    /**
     * Transforme la scene en une chaine de caractere
     * compréhensible par un humain.
     *
     * @return Une chaine de caractere correspondant à la forme
     */
    virtual string toString() const {
        string res = "Shape[name=" + name +
                     ",width=" + to_string(width) +
                     ",height=" + to_string(height)
                     + ",";

        for (auto *shape: shapes) {
            res += shape->toString();
            res += ",";
        }

        res.pop_back();
        res += "]";
        return res;
    }
    explicit operator std::string() const { return toString(); }

    // Setters
    void setHeight(int _height) { this->height = _height; }
    void setWidth(int _width) { this->width = _width; }
    void setName(const string &_name) { this->name = _name; }
    void setBackgroundColor(const Color *_color) { this->backgroundColor = _color; }

    // Getters
    const string &getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
    const Color *getBackgroundColor() const { return backgroundColor; }

    double getArea() const {
        double res = 0;
        for (auto shape: shapes) {
            res += shape->getArea();
        }
        return res;
    }



    // Iterator

    auto begin() { return &shapes[0]; }
    auto end() { return &shapes[shapes.size()]; }
    auto begin() const { return &shapes[0]; }
    auto end() const { return &shapes[shapes.size()]; }

    friend ostream &operator<<(ostream &os, const Scene &scene) {
        os << scene.toString();
        return os;
    }

};



