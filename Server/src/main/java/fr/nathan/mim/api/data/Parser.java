package fr.nathan.mim.api.data;

public abstract class Parser {

    abstract public DataObject parse(String input);

    abstract public String toString(DataObject object);
    abstract public String toString(DataArray array);
    abstract public String toString(DataPrimitive primitive);
}
