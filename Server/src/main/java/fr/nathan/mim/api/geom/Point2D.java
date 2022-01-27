package fr.nathan.mim.api.geom;

import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.ToString;

@ToString(of = {"x", "y"})
@EqualsAndHashCode
@Getter
public class Point2D {

    private double x;
    private double y;

    public Point2D() {
        x = 0;
        y = 0;
    }

    public Point2D(double x, double y) {
        this.x = x;
        this.y = -y; // -y
    }

    public void translate(double x, double y) {
        this.x += x;
        this.y += y;
    }
}
