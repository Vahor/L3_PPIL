package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.Circle;
import fr.nathan.mim.render.shape.shapes.Shape;

public class CircleHandler extends ShapeHandler {

    public CircleHandler(Handler<Parameters, Shape> shapeHandler) {super(shapeHandler);}

    /**
     * @param input
     *  Source des informations à extraire
     * @return
     *  nullptr si cette classe ne sait pas gérer l'information
     *  ou un pointeur sur <In>
     */
    @Override
    protected Shape parse(Parameters input) {
        if (!input.getObject().has("CIRCLE")) return null;

        DataObject object = input.getObject().get("CIRCLE").getAsObject();

        double diameter = object.get("diameter").getAsPrimitive().getAsDouble();

        DataObject position = object.get("position").getAsObject();

        double x = position.get("x").getAsPrimitive().getAsDouble();
        double y = position.get("y").getAsPrimitive().getAsDouble();

        return new Circle(new Point2D(x, y), diameter);
    }
}
