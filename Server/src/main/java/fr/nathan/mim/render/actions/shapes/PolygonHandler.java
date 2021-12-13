package fr.nathan.mim.render.actions.shapes;

import fr.nathan.mim.api.data.ADataArray;
import fr.nathan.mim.api.data.ADataElement;
import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shapes.AShape;
import fr.nathan.mim.render.shapes.Circle;
import fr.nathan.mim.render.shapes.Polygon;

public class PolygonHandler extends ACORHandler<ADataObject, AShape> {

    public PolygonHandler(Handler<ADataObject, AShape> shapeHandler) {        super(shapeHandler);    }

    @Override
    protected AShape parse(ADataObject input) {
        if (!input.has("POLYGON")) return null;

        ADataObject object = input.get("POLYGON").getAsObject();

        Polygon polygon = new Polygon();

        ADataArray points = object.get("points").getAsArray();

        for (ADataElement element : points.getElements()) {
            double x = element.getAsObject().get("x").getAsPrimitive().getAsDouble();
            double y = element.getAsObject().get("y").getAsPrimitive().getAsDouble();
            polygon.addPoint(new Point2D(x, y));
        }

        return polygon;
    }
}
