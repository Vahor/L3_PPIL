package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.*;

public interface Renderable {

    void redraw();
    void resetGraphics();
    void resetScene();
    void disposeBuffer();
    void setTitle(String title);
    void setSize(int width, int height);
    void drawShape(Shape shape);

    void drawLine(Line line);
    void drawCircle(Circle circle);
    void drawPolygon(Polygon polygon);
    void drawText(Text text);

}
