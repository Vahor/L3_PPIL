package fr.nathan.mim.render.actions.shapes;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shapes.AShape;
import fr.nathan.mim.render.shapes.Circle;

public class CircleHandler extends ACORHandler<ADataObject, AShape> {

    public CircleHandler(Handler<ADataObject, AShape> shapeHandler) {        super(shapeHandler);    }

    @Override
    protected AShape parse(ADataObject input) {
        if (!input.has("CIRCLE")) return null;

        ADataObject object = input.get("CIRCLE").getAsObject();

        double diameter = object.get("diameter").getAsPrimitive().getAsDouble();

        ADataObject position = object.get("position").getAsObject();

        double x = position.get("x").getAsPrimitive().getAsDouble();
        double y = position.get("y").getAsPrimitive().getAsDouble();

        return new Circle(new Point2D(x, y), diameter);
    }
}
