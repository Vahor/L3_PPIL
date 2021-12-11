package fr.nathan.mim.render;

import fr.nathan.mim.render.shapes.AShape;
import lombok.Getter;
import lombok.Setter;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Chaque instance de Renderer correspondra à un dessin entier
 */
public class Renderer extends JFrame implements WindowListener {

    private final HashMap<Integer, AShape> shapes = new HashMap<>();

    private double scale = 1;
    private double widthRatio;
    private double heightRatio;

    @Getter
    @Setter
    private int initialHeight = 500;
    @Getter
    @Setter
    private int initialWidth = 900;

    public Renderer() {
        super();
        setBackground(Color.BLACK);

        // On ajoute une taille et position par défaut
        setSize(initialWidth, initialHeight);
        setLocationRelativeTo(null);

        setFocusable(true);
        requestFocusInWindow();

        addWindowListener(this);


        // Ajout du zoom lorsque l'utilisateur scroll
        addMouseWheelListener((e) -> {
            double steps = e.getWheelRotation() / 10.;
            scale = Math.max(.1, scale + steps);

            // À chaque zoom on retire les anciens elements
            invalidate();
            repaint();
        });
    }

    public AShape getById(int id) {
        return shapes.get(id);
    }

    public void addShape(AShape shape) {
        shapes.put(shape.getId(), shape);
        shape.setRendered(true);
    }

    @Override
    public void paint(Graphics g) {
        // clear
        getGraphics().clearRect(0, 0, getWidth(), getHeight());
        // 0,0 au centre de la feuille
        g.translate(getWidth() / 2, getHeight() / 2);

        List<AShape> _shapes = new ArrayList<>(shapes.values());
        _shapes.sort(AShape::compareTo);
        for (AShape shape : _shapes) {
            if(!shape.isVisible()) continue;
            shape.draw(g, widthRatio * scale, heightRatio * scale);
        }
    }

    @Override
    public void validate() {
        super.validate();
        widthRatio  = (double) getWidth() / initialWidth;
        heightRatio = (double) getHeight() / initialHeight;
    }

    @Override
    public void windowClosing(WindowEvent e) {
        dispose();
    }

    // Aucunes actions sur les autres évènements
    @Override
    public void windowOpened(WindowEvent e) {}
    @Override
    public void windowClosed(WindowEvent e) {}
    @Override
    public void windowIconified(WindowEvent e) {}
    @Override
    public void windowDeiconified(WindowEvent e) {}
    @Override
    public void windowActivated(WindowEvent e) {}
    @Override
    public void windowDeactivated(WindowEvent e) {}
}
