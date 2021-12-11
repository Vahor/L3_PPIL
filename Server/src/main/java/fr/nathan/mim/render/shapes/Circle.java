package fr.nathan.mim.render.shapes;

import fr.nathan.mim.render.geom.Point2D;
import lombok.ToString;

import java.awt.*;

@ToString(callSuper = true)
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
        int width = (int) (diameter * widthRatio);
        int height = (int) (diameter * heightRatio);
        int x = (int) (center.getX() * widthRatio - width / 2);
        int y = (int) (center.getY() * heightRatio - width / 2);

        graphics2D.setColor(new Color(0,0,0,0));
        if (getColor() != null) {
            // fill
            graphics2D.setColor(getColor());
        }
        graphics2D.fillOval(x, y, width, height);

        if(getBorderColor() != null) {
            // border
            graphics2D.setColor(getBorderColor());
            graphics2D.drawOval(x, y, width, height);
        }
    }
}
