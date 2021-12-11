package fr.nathan.mim.api.data;


public abstract class ADataElement implements Cloneable {

    public abstract ADataElement clone();

    public ADataObject getAsObject() {return (ADataObject) this;}
    public ADataArray getAsArray()         {return (ADataArray) this;}
    public ADataPrimitive getAsPrimitive() {return (ADataPrimitive) this;}

    public abstract String toString();

}
