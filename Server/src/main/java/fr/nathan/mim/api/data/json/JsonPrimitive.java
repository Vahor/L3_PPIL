package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.DataElement;
import fr.nathan.mim.api.data.DataPrimitive;

public class JsonPrimitive extends DataPrimitive {

    public JsonPrimitive(JsonPrimitive jsonPrimitive) {super(jsonPrimitive);}
    public JsonPrimitive(String value)                {super(value);}

    @Override
    public DataElement clone() {
        return new JsonPrimitive(this);
    }
    @Override
    public String toString() {
        return '"' + value + '"';
    }
}
