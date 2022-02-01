package fr.nathan.mim.api.data;

import fr.nathan.mim.Main;

public class DataPrimitive extends DataElement {

    protected String value;

    public DataPrimitive(DataPrimitive aDataPrimitive) {this.value = aDataPrimitive.value;}
    public DataPrimitive(String value)                 {this.value = value;}

    public boolean getAsBoolean()                      {return value.equalsIgnoreCase("true");}
    public int getAsInt()                              {return Integer.parseInt(value);}
    public double getAsDouble()                        {return Double.parseDouble(value);}
    public String getAsString()                        {return value;}

    @Override
    public DataElement clone() {
        return new DataPrimitive(value);
    }

    @Override
    public String toString() {
        return Main.currentParser.toString(this);
    }
}
