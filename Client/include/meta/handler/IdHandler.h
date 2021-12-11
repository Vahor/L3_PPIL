//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_IDHANDLER_H
#define CLIENT_IDHANDLER_H


#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class IdHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("id")) {
            source.second->setId(source.first->get("id")->getAsPrimitive()->getAsInt());
        }
        return nullptr;
    }


public:
    explicit IdHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}

};


#endif //CLIENT_IDHANDLER_H
