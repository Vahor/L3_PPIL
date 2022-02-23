package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataArray;
import fr.nathan.mim.api.data.DataElement;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shape.shapes.Polygon;
import fr.nathan.mim.render.shape.shapes.Shape;

public class PolygonHandler extends ShapeHandler {

    public PolygonHandler(ShapeHandler shapeHandler) {super(shapeHandler);}

    @Override
    protected Shape parse(Parameters input) {
        if (!input.getObject().has("POLYGON")) return null;

        DataObject object = input.getObject().get("POLYGON").getAsObject();

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
