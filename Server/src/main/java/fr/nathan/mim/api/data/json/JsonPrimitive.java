package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.ADataElement;
import fr.nathan.mim.api.data.ADataPrimitive;

public class JsonPrimitive extends ADataPrimitive {

    public JsonPrimitive(JsonPrimitive jsonPrimitive) {super(jsonPrimitive);}
    public JsonPrimitive(String value)                {super(value);}

    @Override
    public ADataElement clone() {
        return new JsonPrimitive(this);
    }
    @Override
    public String toString() {
        return '"' + value + '"';
    }
}
