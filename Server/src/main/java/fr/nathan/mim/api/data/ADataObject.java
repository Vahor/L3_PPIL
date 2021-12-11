package fr.nathan.mim.api.data;

import java.util.HashMap;

public abstract class ADataObject extends ADataElement {

    protected HashMap<String, ADataElement> children = new HashMap<>();

    public ADataObject()                              {}
    public ADataObject(ADataObject copy)              {copy.children.forEach(this::put);}

    public boolean has(String key)                    {return children.containsKey(key);}
    public void put(String key, ADataElement element) {children.put(key, element.clone());}
    public ADataElement get(String key)               {return children.get(key);}
}
