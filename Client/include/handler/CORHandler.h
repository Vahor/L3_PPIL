//
// Created by Nathan David on 03/12/2021.
//
#pragma once


#include "Handler.h"

template<class In, class Out>
class CORHandler : public Handler<In, Out> {

protected:
    Handler<In, Out> *next;

public:
    explicit CORHandler(Handler<In, Out> *suivant) : next(suivant) {}
    CORHandler() : next(nullptr) {}

public:

    /**
     * Essaie d'analyser l'entrée à l'aide de Handler::parse() sur la classe actuelle
     * Si l'implementation retourne nullptr, on essaie le suivant.
     *
     * @param input  Source des informations à extraire
     * @return NULL si aucun expert ne sait gérer l'information
     *  ou un pointeur sur In
     */
    virtual Out solve(const In &input) const {
        Out value = this->parse(input);

        if (value != NULL)
            return value;

        if (this->next != nullptr) {
            return this->next->solve(input);
        } else {
            return NULL;
        }
    }

};



