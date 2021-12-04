//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_ACORHANDLER_H
#define CLIENT_ACORHANDLER_H

#include "api/handler/Handler.h"

template<class In, class Out>
class ACORHandler : public Handler<In, Out> {

protected:
    ACORHandler<In, Out> *suivant;


public:
    explicit ACORHandler(ACORHandler<In, Out> *suivant) : suivant(suivant) {}
    explicit ACORHandler() : suivant(nullptr) {}

public:

    /**
     * Essaie d'analyser l'entrée à l'aide de Expert::parse() sur la classe actuelle
     * Si l'implementation retourne nullptr, on essaie le suivant.
     *
     * @param line  Source des informations à extraire
     * @return NULL si aucun expert ne sait gérer l'information
     *  ou un pointeur sur <In>
     */
    virtual Out solve(const In &line) const {
        Out value = this->parse(line);

        if (value != NULL)
            return value;


        if (this->suivant != nullptr) {
            return this->suivant->solve(line);
        } else {
            return NULL;
        }
    }

};


#endif //CLIENT_ACORHANDLER_H
