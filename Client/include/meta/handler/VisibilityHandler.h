//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_VISIBILITYHANDLER_H
#define CLIENT_VISIBILITYHANDLER_H

#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class VisibilityHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("visible")) {
            bool visible = source.first->get("visible")->getAsPrimitive()->getAsBoolean();
            source.second->setVisible(visible);
        }
        return nullptr;
    }


public:
    explicit VisibilityHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_VISIBILITYHANDLER_H
