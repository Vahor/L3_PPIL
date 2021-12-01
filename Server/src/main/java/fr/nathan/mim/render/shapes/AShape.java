package fr.nathan.mim.render.shapes;

import fr.nathan.mim.render.geom.Point2D;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

@ToString(of={"name", "color"})
public abstract class AShape extends JPanel {

    @Getter @Setter
    private Color color;
    @Getter @Setter
    private String name;
    @Getter
    private final List<Point2D> points = new ArrayList<>();


    protected void addPoint(Point2D point) {points.add(point);}
    public abstract void draw(Graphics g, double widthRatio, double heightRatio);
}
