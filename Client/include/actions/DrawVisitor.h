//
// Created by Nathan David on 26/01/2022.
//

#pragma once

class Shape;

class Scene;

class DrawVisitor {

public:

    /**
     * Dessine la forme
     * @param shape Scene a dessiner
     */
    virtual void drawShape(const Shape *shape) const = 0;

    /**
     * Dessine la scene.<br />
     * Initialise la scene puis dessines toutes les formes à l'aide de la méthode drawShape.
     *
     * @see DrawVisitor.drawShape
     * @param shape Scene a dessiner
     */
    virtual void drawScene(const Scene *scene) const = 0;

};