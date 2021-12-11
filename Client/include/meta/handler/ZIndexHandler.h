//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_ZINDEXHANDLER_H
#define CLIENT_ZINDEXHANDLER_H


#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class ZIndexHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("zIndex")) {
            source.second->setZIndex(source.first->get("zIndex")->getAsPrimitive()->getAsInt());
        }
        return nullptr;
    }


public:
    explicit ZIndexHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}


};


#endif //CLIENT_ZINDEXHANDLER_H
