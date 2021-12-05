//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_COLORHANDLER_H
#define CLIENT_COLORHANDLER_H

#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class ColorHandler : public ACORHandler<pair<ADataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<ADataObject *, Shape *> &source) const override {
        if(source.first->has("color")) {
            ADataObject *color = source.first->get("color")->getAsObject();
            source.second->setColor(Color(
                    color->get("r")->getAsPrimitive()->getAsInt(),
                    color->get("g")->getAsPrimitive()->getAsInt(),
                    color->get("b")->getAsPrimitive()->getAsInt()
            ));
        }
        return nullptr;
    }


public:
    explicit ColorHandler(Handler<pair<ADataObject *, Shape *>, Shape *> *suivant) : ACORHandler(suivant) {}

};


#endif //CLIENT_COLORHANDLER_H
