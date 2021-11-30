package render;

import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

/**
 * Chaque instance de Renderer correspondra à un dessin entier
 */
public class Renderer extends Frame implements WindowListener {

    public Renderer(){
        super();

        // On ajoute une taille et position par défaut
        setSize(500, 250);
        setLocation(100,100);

        addWindowListener(this);

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
