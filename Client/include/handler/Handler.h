//
// Created by Nathan David on 04/12/2021.
//
#pragma once


template<class In, class Out>
class Handler {

protected:

    /**
     *
     * @param input
     *  Source des informations à extraire
     * @return
     *  nullptr si cette classe ne sait pas gérer l'information
     *  ou un pointeur sur In
     */
    virtual Out parse(const In &input) const = 0;

public:

    /**
     *
     * @param input  Source des informations à extraire
     * @return nullptr si aucun expert ne sait gérer l'information
     *  ou un pointeur sur In
     */
    virtual Out solve(const In &input) const = 0;

};
