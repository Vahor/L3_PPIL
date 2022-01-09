package fr.nathan.mim.api.data;

import java.util.HashMap;

public abstract class DataObject extends DataElement {

    protected HashMap<String, DataElement> children = new HashMap<>();

    public DataObject()                              {}
    public DataObject(DataObject copy)               {copy.children.forEach(this::put);}

    public boolean has(String key)                   {return children.containsKey(key);}
    public void put(String key, DataElement element) {children.put(key, element.clone());}
    public DataElement get(String key)               {return children.get(key);}
}
