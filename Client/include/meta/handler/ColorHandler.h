//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_COLORHANDLER_H
#define CLIENT_COLORHANDLER_H

#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class ColorHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("color")) {
            ADataObject *color = source.first->get("color")->getAsObject();
            source.second->setColor(Color(
                    color->get("r")->getAsPrimitive()->getAsInt(),
                    color->get("g")->getAsPrimitive()->getAsInt(),
                    color->get("b")->getAsPrimitive()->getAsInt(),
                    color->get("a")->getAsPrimitive()->getAsInt()
            ));
        }
        return nullptr;
    }


public:
    explicit ColorHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}

};


#endif //CLIENT_COLORHANDLER_H
