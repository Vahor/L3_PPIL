package fr.nathan.mim.render.shapes;

import fr.nathan.mim.api.geom.Point2D;
import lombok.Setter;
import lombok.ToString;

import java.awt.*;

@ToString(callSuper = true)
public class Text extends AShape {

    @Setter
    private int size;
    @Setter
    private String value;

    public Text(Point2D point, String value, int size) {
        addPoint(point);
        this.value = value;
        this.size  = size;
    }

    @Override
    public void draw(Graphics g, double widthRatio, double heightRatio) {
        Graphics2D graphics2D = (Graphics2D) g;
        graphics2D.setFont(new Font(Font.MONOSPACED, Font.PLAIN, (int) (size * heightRatio)));

        Point2D center = getPoints().get(0);
        int width = graphics2D.getFontMetrics().stringWidth(value);
        int height = graphics2D.getFontMetrics().getHeight();
        int x = (int) (center.getX() * widthRatio - width / 2);
        int y = (int) (center.getY() * heightRatio + height / 4);

        graphics2D.setColor(getColor());

        graphics2D.drawString(value, x, y);
    }
}
