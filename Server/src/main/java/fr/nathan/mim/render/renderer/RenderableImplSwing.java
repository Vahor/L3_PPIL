package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.Circle;
import fr.nathan.mim.render.shape.shapes.Polygon;
import fr.nathan.mim.render.shape.shapes.Shape;
import fr.nathan.mim.render.shape.shapes.Text;
import lombok.Getter;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class RenderableImplSwing extends JFrame implements WindowListener, Renderable {

    private final ArrayList<Shape> shapes = new ArrayList<>();

    private double scaleBoost = 0;

    @Getter
    private double initialHeight;
    @Getter
    private double initialWidth;

    private boolean drawing;

    private BufferStrategy bufferStrategy;
    private Graphics2D graphics2D;

    public RenderableImplSwing(int initialWidth, int initialHeight) throws InterruptedException {
        super();

        setVisible(true);

        // Active rendering
        setIgnoreRepaint(true);
        createBufferStrategy(2);
        Thread.sleep(250);

        setBackground(Color.BLACK);

        // On ajoute une taille et position par défaut
        setSize(initialWidth, initialHeight);
        setLocationRelativeTo(null);
        resetGraphics();// init instead

        setFocusable(true);
        requestFocusInWindow();

        addWindowListener(this);

//        // Ajout du zoom lorsque l'utilisateur scroll
        addMouseWheelListener((e) -> {
            double steps = e.getWheelRotation() / 15.;
            double prev = scaleBoost;

            // [0,2]
            scaleBoost = Math.min(2, Math.max(0, scaleBoost + steps));
            if (scaleBoost == prev) return;

            System.out.println("scaleBoost = " + scaleBoost);

            // Redraw
            redraw();
        });

        addComponentListener(new ResizeEndListener() {
            @Override
            public void onResizeEnd() {
                redraw();
            }
        });

    }

    @Override
    public void redraw() {
        if (drawing || !isVisible()) return;
        try {
            drawing = true;
            resetGraphics();
            shapes.forEach(s -> s.draw(this));
            disposeBuffer();
            drawing = false;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void resetGraphics() {
        bufferStrategy = getBufferStrategy();
        // Graphics
        graphics2D = (Graphics2D) bufferStrategy.getDrawGraphics();

        // Clear
        graphics2D.clearRect(0, 0, getWidth(), getHeight());

        // Move origin to center
        graphics2D.translate(getWidth() / 2., getHeight() / 2.);

        // Adapt to screen size
        double currentFactor = Math.min((double) getHeight() / initialHeight, (double) getWidth() / initialWidth)
                + scaleBoost;
        graphics2D.scale(currentFactor, currentFactor);
    }

    @Override
    public void setSize(int width, int height) {
        super.setSize(width, height);
        initialWidth  = width;
        initialHeight = height;
    }

    @Override
    public void drawShape(Shape shape) {
        shape.draw(this);
        shapes.add(shape);
    }

    @Override
    public void disposeBuffer() {
        graphics2D.dispose();
        bufferStrategy.show();
        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void drawCircle(Circle circle) {

        // On retire la moitié du diamètre pour centrer le cercle sur sa position
        int xPosition = (int) (circle.getCenter().getX() - circle.getDiameter() / 2);
        int yPosition = (int) (circle.getCenter().getY() - circle.getDiameter() / 2);

        // fill
        graphics2D.setColor(circle.getMeta().getColor());
        graphics2D.fillOval(xPosition, yPosition, (int) circle.getDiameter(), (int) circle.getDiameter());

        // border
        graphics2D.setColor(circle.getMeta().getBorderColor());
        graphics2D.drawOval(xPosition, yPosition, (int) circle.getDiameter(), (int) circle.getDiameter());
    }

    @Override
    public void drawText(Text text) {

        AffineTransform affineTransform = new AffineTransform();
        affineTransform.rotate(Math.toRadians(text.getAngleDeg()));

        Font font = new Font(Font.MONOSPACED, Font.PLAIN, text.getSize());
        font = font.deriveFont(affineTransform);
        graphics2D.setFont(font);

        // On retire la moitié de la taille/largeur pour centrer le texte sur sa position
        int width = graphics2D.getFontMetrics().stringWidth(text.getValue());
        int height = graphics2D.getFontMetrics().getHeight();

        int xPosition = (int) (text.getCenter().getX() - width / 2);
        int yPosition = (int) (text.getCenter().getY() - height / 2);

        graphics2D.setColor(text.getMeta().getColor());
        graphics2D.drawString(text.getValue(), xPosition, yPosition);
    }

    @Override
    public void drawPolygon(Polygon polygon) {
        int[] xPoints = polygon.getPoints().stream().mapToInt(p -> (int) p.getX()).toArray();
        int[] yPoints = polygon.getPoints().stream().mapToInt(p -> (int) p.getY()).toArray();

        // fill
        graphics2D.setColor(polygon.getMeta().getColor());
        graphics2D.fillPolygon(xPoints, yPoints, polygon.getPoints().size());

        // border
        graphics2D.setColor(polygon.getMeta().getBorderColor());
        graphics2D.drawPolygon(xPoints, yPoints, polygon.getPoints().size());
    }

    @Override
    public void windowClosing(WindowEvent e) {
        dispose();
    }
    @Override
    public void windowOpened(WindowEvent e) {}
    @Override
    public void windowClosed(WindowEvent e) {}
    @Override
    public void windowIconified(WindowEvent e) {}
    @Override
    public void windowDeiconified(WindowEvent e) {
        setVisible(true);
    }
    @Override
    public void windowActivated(WindowEvent e) {
        setVisible(true);
    }
    @Override
    public void windowDeactivated(WindowEvent e) {}

}
