package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.*;
import fr.nathan.mim.render.shape.shapes.Polygon;
import fr.nathan.mim.render.shape.shapes.Shape;
import lombok.Getter;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RenderableImplSwing extends JFrame implements WindowListener, Renderable {

    private final List<Shape> shapes = Collections.synchronizedList(new ArrayList<>());

    private double scaleBoost = 0;
    private double offsetX = 0;
    private double offsetY = 0;

    @Getter
    private double initialHeight;
    @Getter
    private double initialWidth;

    private boolean drawing;

    private BufferStrategy bufferStrategy;
    private Graphics2D graphics2D;

    @SuppressWarnings("deprecation")
    public RenderableImplSwing(int initialWidth, int initialHeight) throws InterruptedException {
        super();

        setVisible(true);

        // Active rendering
        setIgnoreRepaint(true);
        createBufferStrategy(2);
        Thread.sleep(250);

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
            scaleBoost = Math.min(2, Math.max(-0.99, scaleBoost + steps));
            if (scaleBoost == prev) return;

            // Redraw
            redraw();
        });

        int defaultCursor = Cursor.HAND_CURSOR;
        setCursor(defaultCursor);
        addMouseListener(new MouseListener() {

            private Point initialClick;

            @Override
            public void mousePressed(MouseEvent e) {
                initialClick = e.getPoint();

                setCursor(Cursor.CROSSHAIR_CURSOR);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if (initialClick != null) {

                    // How much the mouse moved
                    int xMoved = e.getX() - initialClick.x;
                    int yMoved = e.getY() - initialClick.y;

                    offsetX += xMoved;
                    offsetY += yMoved;
                    setCursor(defaultCursor);

                    redraw();
                }
            }

            // Empty
            @Override
            public void mouseClicked(MouseEvent e) {}
            @Override
            public void mouseEntered(MouseEvent e) {}
            @Override
            public void mouseExited(MouseEvent e) {}
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
            shapes.forEach(s -> {
                try {
                    s.draw(this);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
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
        graphics2D.translate(getWidth() / 2. + offsetX, getHeight() / 2. + offsetY);

        // Adapt to screen size
        double currentFactor = Math.min((double) getHeight() / initialHeight, (double) getWidth() / initialWidth);
        currentFactor *= (1 + scaleBoost);
        graphics2D.scale(currentFactor, currentFactor);
    }

    @Override
    public void resetScene() {
        shapes.clear();
    }

    @Override
    public void setSize(int width, int height) {
        super.setSize(width, height);
        initialWidth  = width;
        initialHeight = height;
    }

    @Override
    public void drawShape(Shape shape) {
        try {
            shape.draw(this);
        } catch (ClassCastException e) {
            e.printStackTrace();
        }
        shapes.add(shape);
    }

    @Override
    public void disposeBuffer() {
        bufferStrategy.show();
        graphics2D.dispose();
        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void drawLine(Line line) {
        graphics2D.setColor(line.getMeta().getColor());

        graphics2D.drawLine(
                (int) line.getFrom().getX(), (int) line.getFrom().getY(),
                (int) line.getTo().getX(), (int) line.getTo().getY()
        );
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
        affineTransform.setToRotation(text.getRadians());

        Font font = new Font(Font.MONOSPACED, Font.PLAIN, text.getSize());
        font = font.deriveFont(affineTransform);
        graphics2D.setFont(font);

        graphics2D.setColor(text.getMeta().getColor());
        graphics2D.drawString(text.getValue(), (int) text.getCenter().getX(), (int) text.getCenter().getY());

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
