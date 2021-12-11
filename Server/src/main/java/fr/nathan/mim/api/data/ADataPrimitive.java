package fr.nathan.mim.api.data;

public abstract class ADataPrimitive extends ADataElement {

    protected String value;

    public ADataPrimitive(ADataPrimitive aDataPrimitive) {this.value = aDataPrimitive.value;}
    public ADataPrimitive(String value)                  {this.value = value;}

    public boolean getAsBoolean()                        {return value.equalsIgnoreCase("true");}
    public int getAsInt()                                {return Integer.parseInt(value);}
    public double getAsDouble()                          {return Double.parseDouble(value);}
    public String getAsString()                          {return value;}
}
