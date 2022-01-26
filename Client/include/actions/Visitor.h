//
// Created by Nathan David on 26/01/2022.
//

#pragma once

class Shape;

class Scene;

class Visitor {

public:

    virtual void drawShape(const Shape *shape) const = 0;
    virtual void drawScene(const Scene *scene) const = 0;

};