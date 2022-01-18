package fr.nathan.mim.render.shape;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.awt.*;

@ToString
public class Meta {

    @Getter @Setter
    private Color color;
    @Getter @Setter
    private Color borderColor;
    @Getter @Setter
    private int id;
}
