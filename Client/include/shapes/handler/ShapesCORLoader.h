//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_SHAPESCORLOADER_H
#define CLIENT_SHAPESCORLOADER_H

#include <vector>

#include "shapes/Shape.h"
#include "handler/Handler.h"

#include "shapes/handler/ShapeHandler.h"

using namespace std;

class ShapesCORLoader {

    Handler<ADataObject, Shape*>* handler;

public:

    ShapesCORLoader() {
        handler = new ShapeHandler();
    }

    Scene* parseScene(const ADataObject &object) const {
        return Scene::parse(object, handler);
    }



};


#endif //CLIENT_SHAPESCORLOADER_H
