//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_NAMEHANDLER_H
#define CLIENT_NAMEHANDLER_H

#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class NameHandler : public ACORHandler<pair<ADataObject *, Shape *>, Shape *>{

protected:

    Shape * parse(const pair<ADataObject*, Shape *> &source) const override {
        string name = source.first->get("name")->getAsPrimitive()->getAsString();
        source.second->setName(name);
        return nullptr;
    }


public:
    explicit NameHandler(Handler<pair<ADataObject *, Shape *>, Shape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_NAMEHANDLER_H
