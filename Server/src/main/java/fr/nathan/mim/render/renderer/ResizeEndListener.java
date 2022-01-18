package fr.nathan.mim.render.renderer;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public abstract class ResizeEndListener extends ComponentAdapter implements ActionListener {

    private final Timer timer;

    protected ResizeEndListener() {
        timer = new Timer(200, this);
        timer.setRepeats(false);
        timer.setCoalesce(false);
    }

    @Override
    public void componentResized(ComponentEvent e) {
        timer.restart();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        onResizeEnd();
    }

    public abstract void onResizeEnd();
}
