//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_DAO_H
#define CLIENT_DAO_H

#include <vector>

/*
 * Classe template pour le DAO.
 */
template <class Data, class Identifier>
class Dao {

public:

    virtual Data* get(Identifier id) const = 0;
    virtual void save(Identifier id, Data* data) const = 0;



};


#endif //CLIENT_DAO_H
