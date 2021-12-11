package fr.nathan.mim.render.shapes;

import fr.nathan.mim.render.geom.Point2D;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

@ToString(of={"id", "name", "color", "visible", "showName","borderColor" })
public abstract class AShape extends JPanel implements Comparable<AShape> {

    @Getter @Setter
    private Color color;
    @Getter @Setter
    private Color borderColor;
    @Getter @Setter
    private String name;
    @Getter @Setter
    private int id;
    @Getter @Setter
    private int zIndex;
    @Getter @Setter
    boolean visible = true;
    @Getter @Setter
    boolean showName = false;

    @Getter @Setter
    boolean rendered = false;
    @Getter
    private final List<Point2D> points = new ArrayList<>();


    protected void addPoint(Point2D point) {points.add(point);}
    public abstract void draw(Graphics g, double widthRatio, double heightRatio);

    @Override
    public int compareTo(AShape o) {
        return zIndex - o.zIndex;
    }
}
