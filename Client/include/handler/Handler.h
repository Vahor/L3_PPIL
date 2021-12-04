//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H


template<class In, class Out>
class Handler {

protected:
    /**
     *
     * @param line
     *  Source des informations à extraire
     * @return
     *  nullptr si cette classe ne sait pas gérer l'information
     *  ou un pointeur sur <In>
     */
    virtual Out parse(const In &line) const = 0;

public:

    /**
     *
     * @param line  Source des informations à extraire
     * @return nullptr si aucun expert ne sait gérer l'information
     *  ou un pointeur sur <In>
     */
    virtual Out solve(const In &line) const = 0;

};


#endif //CLIENT_HANDLER_H
