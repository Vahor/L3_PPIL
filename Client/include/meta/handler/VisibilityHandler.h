//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_VISIBILITYHANDLER_H
#define CLIENT_VISIBILITYHANDLER_H

#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class VisibilityHandler : public ACORHandler<pair<ADataObject *, Shape *>, Shape *>{

protected:

    Shape * parse(const pair<ADataObject*, Shape *> &source) const override {
        bool visible = source.first->get("visible")->getAsPrimitive()->getAsBool();
        source.second->setVisible(visible);
        return nullptr;
    }


public:
    explicit VisibilityHandler(Handler<pair<ADataObject *, Shape *>, Shape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_VISIBILITYHANDLER_H
