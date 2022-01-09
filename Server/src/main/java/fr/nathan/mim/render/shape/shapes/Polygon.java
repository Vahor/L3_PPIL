package fr.nathan.mim.render.shape.shapes;

import lombok.ToString;

import java.awt.*;

@ToString(callSuper = true)
public class Polygon extends AShape {


    public Polygon() {}

    @Override
    public void draw(Graphics g, double widthRatio, double heightRatio) {
        Graphics2D graphics2D = (Graphics2D) g;

        int[] xPoints = getPoints().stream().mapToInt(p -> (int) (p.getX() * widthRatio)).toArray();
        int[] yPoints = getPoints().stream().mapToInt(p -> (int) (p.getY() * heightRatio)).toArray();

        // fill
        graphics2D.setColor(getColor());
        graphics2D.fillPolygon(xPoints, yPoints, getPoints().size());

        // border
        graphics2D.setColor(getBorderColor());
        graphics2D.drawPolygon(xPoints, yPoints, getPoints().size());

    }
}
