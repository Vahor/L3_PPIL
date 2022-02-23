package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.Circle;
import fr.nathan.mim.render.shape.shapes.Line;
import fr.nathan.mim.render.shape.shapes.Shape;

public class LineHandler extends ShapeHandler {

    public LineHandler(Handler<Parameters, Shape> shapeHandler) {super(shapeHandler);}

    @Override
    protected Shape parse(Parameters input) {
        if (!input.getObject().has("LINE")) return null;

        DataObject object = input.getObject().get("LINE").getAsObject();

        DataObject from = object.get("from").getAsObject();

        Point2D fromPoint = new Point2D(
                from.get("x").getAsPrimitive().getAsDouble(),
                from.get("y").getAsPrimitive().getAsDouble()
        );


        DataObject to = object.get("to").getAsObject();
        Point2D toPoint = new Point2D(
                to.get("x").getAsPrimitive().getAsDouble(),
                to.get("y").getAsPrimitive().getAsDouble()
        );

        return new Line(fromPoint, toPoint);
    }
}
