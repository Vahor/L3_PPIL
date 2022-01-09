package fr.nathan.mim.api.data;

public abstract class DataPrimitive extends DataElement {

    protected String value;

    public DataPrimitive(DataPrimitive aDataPrimitive) {this.value = aDataPrimitive.value;}
    public DataPrimitive(String value)                 {this.value = value;}

    public boolean getAsBoolean()                      {return value.equalsIgnoreCase("true");}
    public int getAsInt()                              {return Integer.parseInt(value);}
    public double getAsDouble()                        {return Double.parseDouble(value);}
    public String getAsString()                        {return value;}
}
