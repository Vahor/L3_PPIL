package fr.nathan.mim.render.actions.shapes;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shapes.AShape;
import fr.nathan.mim.render.shapes.Text;

public class TextHandler extends ACORHandler<ADataObject, AShape> {

    public TextHandler(Handler<ADataObject, AShape> shapeHandler) {super(shapeHandler);}

    @Override
    protected AShape parse(ADataObject input) {
        if (!input.has("TEXT")) return null;

        ADataObject object = input.get("TEXT").getAsObject();

        String value = object.get("value").getAsPrimitive().getAsString();
        int size = object.get("size").getAsPrimitive().getAsInt();
        double x = object.get("x").getAsPrimitive().getAsDouble();
        double y = object.get("y").getAsPrimitive().getAsDouble();

        return new Text(new Point2D(x, y), value, size);
    }
}
