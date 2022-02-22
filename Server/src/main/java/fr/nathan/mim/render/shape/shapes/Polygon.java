package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.renderer.Renderable;
import lombok.Getter;
import lombok.ToString;

import java.util.ArrayList;
import java.util.List;

@Getter
@ToString(callSuper = true)
public class Polygon extends Shape {

    @Getter
    private final List<Point2D> points = new ArrayList<>();

    public Polygon()                    {super();}

    public void addPoint(Point2D point) {points.add(point);}

    @Override
    public void draw(Renderable renderable) {
        renderable.drawPolygon(this);
    }
}
