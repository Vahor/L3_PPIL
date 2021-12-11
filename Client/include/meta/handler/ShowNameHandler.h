//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_SHOWNAMEHANDLER_H
#define CLIENT_SHOWNAMEHANDLER_H

#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class ShowNameHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {

        if (source.first->has("showName")) {
            bool showName = source.first->get("showName")->getAsPrimitive()->getAsBoolean();
            source.second->setShowName(showName);
        }
        return nullptr;
    }


public:
    explicit ShowNameHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_SHOWNAMEHANDLER_H
