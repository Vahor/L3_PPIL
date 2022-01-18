package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.api.geom.Point2D;
import fr.nathan.mim.render.shape.Meta;
import lombok.ToString;

import java.awt.*;
import java.awt.geom.AffineTransform;

@ToString(callSuper = true)
public class Text extends Shape {

    private final int size;
    private final Point2D center;
    private final String value;
    private final double angleDeg;

    public Text(Point2D center, String value, int size, double angleDeg, Meta meta) {
        super(meta);
        this.center   = center;
        this.value    = value;
        this.size     = size;
        this.angleDeg = angleDeg;
    }

    @Override
    public void draw(Graphics graphics) {

        AffineTransform affineTransform = new AffineTransform();
        affineTransform.rotate(Math.toRadians(angleDeg));

        Font font = new Font(Font.MONOSPACED, Font.PLAIN, size);
        font = font.deriveFont(affineTransform);
        graphics.setFont(font);

        // On retire la moitié de la taille/largeur pour centrer le texte sur sa position
        int width = graphics.getFontMetrics().stringWidth(value);
        int height = graphics.getFontMetrics().getHeight();

        int xPosition = (int) (center.getX() - width / 2);
        int yPosition = (int) (center.getY() - height / 2);

        graphics.setColor(meta.getColor());
        graphics.drawString(value, xPosition, yPosition);
    }
}
