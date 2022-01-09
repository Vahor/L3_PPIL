package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;
import fr.nathan.mim.render.shape.shapes.Text;

public class TextHandler extends ACORHandler<DataObject, AShape> {

    public TextHandler(Handler<DataObject, AShape> shapeHandler) {super(shapeHandler);}

    @Override
    protected AShape parse(DataObject input) {
        if (!input.has("TEXT")) return null;

        DataObject object = input.get("TEXT").getAsObject();

        String value = object.get("value").getAsPrimitive().getAsString();
        int size = object.get("size").getAsPrimitive().getAsInt();

        DataObject position = object.get("position").getAsObject();

        double x = position.get("x").getAsPrimitive().getAsDouble();
        double y = position.get("y").getAsPrimitive().getAsDouble();


        double angle = object.get("angle").getAsPrimitive().getAsDouble();

        return new Text(new Point2D(x, y), value, size,angle);
    }
}
