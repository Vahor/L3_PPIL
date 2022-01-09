//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include <vector>

/*
 * Classe modèle pour le DAO.
 */
template <class Data, class Identifier>
class Dao {

public:

    virtual Data* get(Identifier id) const = 0;
    virtual void save(Identifier id, Data* data) const = 0;



};

