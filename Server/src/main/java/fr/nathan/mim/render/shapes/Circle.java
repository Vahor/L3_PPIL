package fr.nathan.mim.render.shapes;

import fr.nathan.mim.render.geom.Point2D;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Circle extends AShape {

    private final double diameter;

    public Circle(Point2D point, double diameter) {
        addPoint(point);
        this.diameter = diameter;
    }


    @Override
    public void draw(Graphics g, double widthRatio, double heightRatio) {
        Graphics2D graphics2D = (Graphics2D) g;

        Point2D center = getPoints().get(0);
        double width = diameter * widthRatio;
        double height = diameter * heightRatio;
        Shape circle = new Ellipse2D.Double(
                center.getX() * widthRatio - width/2,
                center.getY() * heightRatio - height/2,
                width,
                height);

        if(getColor() != null) {
            graphics2D.setPaint(getColor());
            graphics2D.fill(circle);
        }
        graphics2D.draw(circle);
    }
}
