package fr.nathan.mim.api.data;

import fr.nathan.mim.Main;

import java.util.HashMap;

public class DataObject extends DataElement {

    protected HashMap<String, DataElement> children = new HashMap<>();

    public DataObject()                               {}
    public DataObject(DataObject copy)                {copy.children.forEach(this::put);}

    public boolean has(String key)                    {return children.containsKey(key);}
    public void put(String key, DataElement element)  {children.put(key, element.clone());}
    public DataElement get(String key)                {return children.get(key);}
    public HashMap<String, DataElement> getChildren() {return children;}

    @Override
    public DataElement clone() {return new DataObject(this);}

    @Override
    public String toString() {
        return Main.currentParser.toString(this);
    }

}
