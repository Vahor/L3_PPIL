package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shape.shapes.AShape;
import fr.nathan.mim.render.shape.shapes.Circle;

public class CircleHandler extends ACORHandler<DataObject, AShape> {

    public CircleHandler(Handler<DataObject, AShape> shapeHandler) {        super(shapeHandler);    }

    @Override
    protected AShape parse(DataObject input) {
        if (!input.has("CIRCLE")) return null;

        DataObject object = input.get("CIRCLE").getAsObject();

        double diameter = object.get("diameter").getAsPrimitive().getAsDouble();

        DataObject position = object.get("position").getAsObject();

        double x = position.get("x").getAsPrimitive().getAsDouble();
        double y = position.get("y").getAsPrimitive().getAsDouble();

        return new Circle(new Point2D(x, y), diameter);
    }
}
