package fr.nathan.mim.api.data;

public abstract class Parser {

    /**
     * Transforme une chaine de caracteres en un DataObject
     *
     * @param input L'information à transformer
     * @return Un DataObject correspondant à l'entrée
     */
    abstract public DataObject parse(String input);

    /**
     * Transforme un DataObject en une chaine de caractere.<br>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param object L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entré
     */
    abstract public String toString(DataObject object);

    /**
     * Transforme un DataArray en une chaine de caractere.<br>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param array L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entré
     */
    abstract public String toString(DataArray array);

    /**
     * Transforme un DataPrimitive en une chaine de caractere.<br>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param primitive L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entré
     */
    abstract public String toString(DataPrimitive primitive);
}
