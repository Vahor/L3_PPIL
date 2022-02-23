package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.renderer.Renderable;
import lombok.Getter;
import lombok.ToString;

@Getter
@ToString(callSuper = true)
public class Circle extends Shape {

    private final double diameter;
    private final Point2D center;

    public Circle(Point2D center, double diameter) {
        this.center   = center;
        this.diameter = diameter;
    }

    @Override
    public void draw(Renderable renderable) {
        renderable.drawCircle(this);
    }
}
