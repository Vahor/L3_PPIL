//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_SHOWNAMEHANDLER_H
#define CLIENT_SHOWNAMEHANDLER_H

#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class ShowNameHandler : public ACORHandler<pair<ADataObject *, Shape *>, Shape *>{

protected:

    Shape * parse(const pair<ADataObject*, Shape *> &source) const override {

        if(source.first->has("showName")) {
            bool showName = source.first->get("showName")->getAsPrimitive()->getAsBool();
            source.second->setShowName(showName);
        }
        return nullptr;
    }


public:
    explicit ShowNameHandler(Handler<pair<ADataObject *, Shape *>, Shape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_SHOWNAMEHANDLER_H
