package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;
import lombok.ToString;

@Getter
@ToString(callSuper = true)
public class Line extends Shape {

    private final Point2D from;
    private final Point2D to;

    public Line(Point2D from, Point2D to) {
        super();
        this.from   = from;
        this.to = to;
    }

    @Override
    public void draw(Renderable renderable) {
        renderable.drawLine(this);
    }
}
