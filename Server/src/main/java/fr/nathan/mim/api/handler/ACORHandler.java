package fr.nathan.mim.api.handler;

public abstract class ACORHandler<In, Out> extends Handler<In, Out> {

    protected Handler<In, Out> next;

    public ACORHandler(Handler<In, Out> next) {this.next = next;}

    /**
     * Essaie d'analyser l'entrée à l'aide de Expert::parse() sur la classe actuelle
     * Si l'implementation retourne nullptr, on essaie le suivant.
     *
     * @param line  Source des informations à extraire
     * @return NULL si aucun expert ne sait gérer l'information
     *  ou un pointeur sur <In>
     */
    public Out solve(In line) {
        Out value = this.parse(line);

        if (value != null)
            return value;

        if (this.next != null) {
            return this.next.solve(line);
        }
        else {
            return null;
        }
    }
}
