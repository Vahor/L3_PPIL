package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.Shape;
import lombok.Getter;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class RenderableImpl extends JFrame implements WindowListener, Renderable {

    private final ArrayList<Shape> shapes = new ArrayList<>();

    private double scaleBoost = 0;

    @Getter
    private double initialHeight;
    @Getter
    private double initialWidth;

    private boolean drawing;


    private BufferStrategy bufferStrategy;
    private Graphics2D graphics2D;

    public RenderableImpl(int initialWidth, int initialHeight) throws InterruptedException {
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
//
//        // Ajout du zoom lorsque l'utilisateur scroll
        addMouseWheelListener((e) -> {
//            int direction = e.getWheelRotation() > 0 ? 1 : -1;
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
            Graphics2D graphics2D = getGraphics2D();
            shapes.forEach(s -> s.draw(graphics2D));
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
        shape.draw(getGraphics2D());
        shapes.add(shape);
    }

    @Override
    public Graphics2D getGraphics2D() {
        return graphics2D;
    }

    @Override
    public void disposeBuffer() {
        graphics2D.dispose();
        bufferStrategy.show();
        Toolkit.getDefaultToolkit().sync();
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
