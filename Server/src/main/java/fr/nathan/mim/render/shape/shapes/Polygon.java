package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;
import lombok.ToString;

import java.awt.*;
import java.util.HashSet;
import java.util.Set;

@ToString(callSuper = true)
public class Polygon extends Shape {

    @Getter
    private final Set<Point2D> points = new HashSet<>();

    public Polygon(Meta meta)           {super(meta);}

    public void addPoint(Point2D point) {points.add(point);}

    @Override
    public void draw(Graphics graphics) {

        int[] xPoints = getPoints().stream().mapToInt(p -> (int) p.getX()).toArray();
        int[] yPoints = getPoints().stream().mapToInt(p -> (int) p.getY()).toArray();

        // fill
        graphics.setColor(meta.getColor());
        graphics.fillPolygon(xPoints, yPoints, getPoints().size());

        // border
        graphics.setColor(meta.getBorderColor());
        graphics.drawPolygon(xPoints, yPoints, getPoints().size());

    }
}
