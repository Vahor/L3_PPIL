package fr.nathan.mim.api.handler;

public abstract class Handler<In, Out> {

    /**
     * @param input
     *  Source des informations à extraire
     * @return
     *  nullptr si cette classe ne sait pas gérer l'information
     *  ou un pointeur sur In
     */
    protected abstract Out parse(In input);

    /**
     * @param input  Source des informations à extraire
     * @return nullptr si aucun expert ne sait gérer l'information
     *  ou un pointeur sur In
     */
    public abstract Out solve(In input);
}
