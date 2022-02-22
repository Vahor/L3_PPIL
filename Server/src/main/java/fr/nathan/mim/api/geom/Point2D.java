package fr.nathan.mim.api.geom;

import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.ToString;

@ToString(of = {"x", "y"})
@EqualsAndHashCode
@Getter
public class Point2D {

    private final double x;
    private final double y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = -y; // -y
    }
}
