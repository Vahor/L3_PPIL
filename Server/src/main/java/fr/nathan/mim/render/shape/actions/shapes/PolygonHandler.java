package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataArray;
import fr.nathan.mim.api.data.DataElement;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;
import fr.nathan.mim.render.shape.shapes.Polygon;

public class PolygonHandler extends ACORHandler<DataObject, AShape> {

    public PolygonHandler(Handler<DataObject, AShape> shapeHandler) {        super(shapeHandler);    }

    @Override
    protected AShape parse(DataObject input) {
        if (!input.has("POLYGON")) return null;

        DataObject object = input.get("POLYGON").getAsObject();

        Polygon polygon = new Polygon();

        DataArray points = object.get("points").getAsArray();

        for (DataElement element : points.getElements()) {
            double x = element.getAsObject().get("x").getAsPrimitive().getAsDouble();
            double y = element.getAsObject().get("y").getAsPrimitive().getAsDouble();
            polygon.addPoint(new Point2D(x, y));
        }

        return polygon;
    }
}
