package fr.nathan.mim.render.renderer;

import fr.nathan.mim.render.shape.shapes.Circle;
import fr.nathan.mim.render.shape.shapes.Shape;
import fr.nathan.mim.render.shape.shapes.Text;
import fr.nathan.mim.render.shape.shapes.Polygon;

public interface Renderable {

    void redraw();
    void resetGraphics();
    void resetScene();
    void disposeBuffer();
    void setTitle(String title);
    void setSize(int width, int height);
    void drawShape(Shape shape);

    void drawCircle(Circle circle);
    void drawPolygon(Polygon polygon);
    void drawText(Text text);

}
