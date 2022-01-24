//
// Created by Nathan David on 19/01/2022.
//

#pragma once

#include "data/DataElement.h"
#include <iostream>

class Serializable {


public:

    /**
     * Transforme la classe actuelle en DataElement
     * @return L'objet actuel sous forme DataElement
     */
    virtual DataElement *serialize0(bool ignoreGroup) const = 0;

    /**
     * Appelle la méthode serialize0 et ajoute ou non les propriétés du groupe.
     * On peut vouloir ignorer le groupe dans le cas de la sauvegarde pour garder les propriétés de base.
     * @param ignoreGroup false pour que les propriétés du groupe écrasent les propriétés de l'objet
     */
    virtual DataElement *serialize(bool ignoreGroup) const {
        DataElement *element = serialize0(ignoreGroup);
        return element;
    };
};