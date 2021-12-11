//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_GROUPHANDLER_H
#define CLIENT_GROUPHANDLER_H

#include "shapes/Circle.h"
#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class GroupHandler : public ACORHandler<ADataObject, AShape *> {


protected:

    Handler<pair<ADataObject *, AShape *>, AShape *> *metaHandler = nullptr;

    AShape *parse(const ADataObject &source) const override {
        if (!source.has("GROUP")) return nullptr;


        auto *group = new ShapeGroup;
        ADataArray *items = source.get("GROUP")->getAsObject()->get("items")->getAsArray();
        for (ADataElement *element: *items) {
            AShape *shape = AShape::parse(*element->getAsObject(), this, metaHandler);
            if (shape != nullptr) group->addShape(shape);
        }


        return group;
    }

public:
    explicit GroupHandler(Handler<ADataObject, AShape *> *suivant,
                          Handler<pair<ADataObject *, AShape *>, AShape *> *metaHandler
    ) : ACORHandler(suivant), metaHandler(metaHandler) {}
};

#endif //CLIENT_GROUPHANDLER_H
