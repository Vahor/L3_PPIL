package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.ADataElement;
import fr.nathan.mim.api.data.ADataObject;

import java.util.Map;

public class JsonObject extends ADataObject {

    public JsonObject(JsonObject jsonObject) {super(jsonObject);}
    public JsonObject()                      {}

    @Override
    public ADataElement clone() {return new JsonObject(this);}

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("{");

        int i = 0;
        for (Map.Entry<String, ADataElement> entry : children.entrySet()) {

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
