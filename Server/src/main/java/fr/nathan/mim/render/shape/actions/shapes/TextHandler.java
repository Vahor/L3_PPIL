package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.Shape;
import fr.nathan.mim.render.shape.shapes.Text;

public class TextHandler extends ShapeHandler {

    public TextHandler(Handler<ShapeHandler.Parameters, Shape> shapeHandler) {super(shapeHandler);}

    @Override
    protected Shape parse(ShapeHandler.Parameters input) {
        if (!input.getObject().has("TEXT")) return null;

        DataObject object = input.getObject().get("TEXT").getAsObject();

        String value = object.get("value").getAsPrimitive().getAsString();
        int size = object.get("size").getAsPrimitive().getAsInt();

        DataObject position = object.get("position").getAsObject();

        double x = position.get("x").getAsPrimitive().getAsDouble();
        double y = position.get("y").getAsPrimitive().getAsDouble();


        double radians = object.get("radians").getAsPrimitive().getAsDouble();

        return new Text(new Point2D(x, y), value, size, radians, input.getMeta());
    }
}
