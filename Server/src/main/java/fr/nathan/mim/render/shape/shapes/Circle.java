package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shape.Meta;
import lombok.ToString;

import java.awt.*;

@ToString(callSuper = true)
public class Circle extends Shape {

    private final double diameter;
    private final Point2D center;

    public Circle(Point2D center, double diameter, Meta meta) {
        super(meta);
        this.center   = center;
        this.diameter = diameter;
    }

    @Override
    public void draw(Graphics graphics) {

        // On retire la moitié du diamètre pour centrer le cercle sur sa position
        int xPosition = (int) (center.getX() - diameter / 2);
        int yPosition = (int) (center.getY() - diameter / 2);

        // fill
        graphics.setColor(meta.getColor());
        graphics.fillOval(xPosition, yPosition, (int) diameter, (int) diameter);

        // border
        graphics.setColor(meta.getBorderColor());
        graphics.drawOval(xPosition, yPosition, (int) diameter, (int) diameter);
    }
}
