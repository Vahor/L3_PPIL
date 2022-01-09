package fr.nathan.mim.api.data;


public abstract class DataElement implements Cloneable {

    public abstract DataElement clone();

    public DataObject getAsObject()       {return (DataObject) this;}
    public DataArray getAsArray()         {return (DataArray) this;}
    public DataPrimitive getAsPrimitive() {return (DataPrimitive) this;}

    public abstract String toString();

}
