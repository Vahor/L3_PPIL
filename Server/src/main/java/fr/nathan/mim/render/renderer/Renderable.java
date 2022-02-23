package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.*;

public interface Renderable {

    void redraw();
    void resetGraphics();
    void resetScene();
    void disposeBuffer();
    void setTitle(String title);
    void setSize(int width, int height);

    /**
     * Dessine une forme sans connaitre son type.<br>
     * À l'aide d'un appel sur la forme.
     *
     * @see Shape#draw(Renderable)
     *
     * @param shape Forme à dessiner
     */
    void drawShape(Shape shape);

    /**
     * Dessine une ligne
     * @param line Instance d'une ligne
     */
    void drawLine(Line line);
    /**
     * Dessine un circle
     * @param circle Instance d'un circle
     */
    void drawCircle(Circle circle);
    /**
     * Dessine un polygon
     * @param polygon Instance d'un polygon
     */
    void drawPolygon(Polygon polygon);
    /**
     * Dessine un text
     * @param text Instance d'un text
     */
    void drawText(Text text);

}
