//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_BORDERCOLORHANDLER_H
#define CLIENT_BORDERCOLORHANDLER_H

#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class BorderColorHandler : public ACORHandler<pair<ADataObject *, AShape *>, AShape *> {

protected:

    AShape *parse(const pair<ADataObject *, AShape *> &source) const override {
        if (source.first->has("borderColor")) {
            ADataObject *color = source.first->get("borderColor")->getAsObject();
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
    explicit BorderColorHandler(Handler<pair<ADataObject *, AShape *>, AShape *> *suivant) : ACORHandler(suivant) {}


};


#endif //CLIENT_BORDERCOLORHANDLER_H
