package fr.nathan.mim.render.actions.shapes;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.geom.Point2D;
import fr.nathan.mim.render.shapes.AShape;
import fr.nathan.mim.render.shapes.Circle;

public class CircleHandler extends ACORHandler<ADataObject, AShape> {

    public CircleHandler(Handler<ADataObject, AShape> shapeHandler) {        super(shapeHandler);    }

    @Override
    protected AShape parse(ADataObject input) {
        if (!input.has("CIRCLE")) return null;

        ADataObject circle = input.get("CIRCLE").getAsObject();

        double diameter = circle.get("diameter").getAsPrimitive().getAsDouble();
        double x = circle.get("x").getAsPrimitive().getAsDouble();
        double y = circle.get("y").getAsPrimitive().getAsDouble();

        return new Circle(new Point2D(x, y), diameter);
    }
}
