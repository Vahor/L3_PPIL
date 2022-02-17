package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;
import lombok.ToString;

@Getter
@ToString(callSuper = true)
public class Text extends Shape {

    private final int size;
    private final Point2D center;
    private final String value;
    private final double radians;

    public Text(Point2D center, String value, int size, double radians) {
        super();
        this.center   = center;
        this.value    = value;
        this.size     = size;
        this.radians = radians;
    }

    @Override
    public void draw(Renderable renderable) {
        renderable.drawText(this);
    }
}
