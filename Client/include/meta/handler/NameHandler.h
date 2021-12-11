//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_NAMEHANDLER_H
#define CLIENT_NAMEHANDLER_H

#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class NameHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("name")) {
            string name = source.first->get("name")->getAsPrimitive()->getAsString();
            source.second->setName(name);
        }
        return nullptr;
    }


public:
    explicit NameHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_NAMEHANDLER_H
