package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.DataElement;
import fr.nathan.mim.api.data.DataObject;

import java.util.Map;

public class JsonObject extends DataObject {

    public JsonObject(JsonObject jsonObject) {super(jsonObject);}
    public JsonObject()                      {}

    @Override
    public DataElement clone() {return new JsonObject(this);}

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("{");

        int i = 0;
        for (Map.Entry<String, DataElement> entry : children.entrySet()) {

            res.append('"').append(entry.getKey()).append("\":");
            res.append(entry.getValue().toString());

            if ((i + 1) != children.size()) {
                res.append(",");
            }
            i++;
        }

        res.append("}");
        return res.toString();
    }
}
