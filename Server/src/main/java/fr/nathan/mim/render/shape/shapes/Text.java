package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import lombok.Setter;
import lombok.ToString;

import java.awt.*;
import java.awt.geom.AffineTransform;

@ToString(callSuper = true)
public class Text extends AShape {

    @Setter
    private int size;
    @Setter
    private String value;
    @Setter
    double angle;

    public Text(Point2D point, String value, int size, double angle) {
        addPoint(point);
        this.value = value;
        this.size  = size;
        this.angle = angle;
    }

    @Override
    public void draw(Graphics g, double widthRatio, double heightRatio) {
        Point2D center = getPoints().get(0);

        Graphics2D graphics2D = (Graphics2D) g;
        AffineTransform affineTransform = new AffineTransform();
        // todo voir si on a besoin d'ajouter un point d'ancrage pour la rotation
        affineTransform.rotate(Math.toRadians(angle));

        Font font = new Font(Font.MONOSPACED, Font.PLAIN, (int) (size * heightRatio));
        font = font.deriveFont(affineTransform);
        graphics2D.setFont(font);

        int width = graphics2D.getFontMetrics().stringWidth(value);
        int height = graphics2D.getFontMetrics().getHeight();
        int x = (int) (center.getX() * widthRatio - width / 2);
        int y = (int) (center.getY() * heightRatio - height / 2);

        graphics2D.setColor(getColor());

        graphics2D.drawString(value, x, y);
    }
}
