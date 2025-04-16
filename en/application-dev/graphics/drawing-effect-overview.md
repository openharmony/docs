# Overview of Drawing Effects


After a canvas is created, it has the default filling and stroke effects. You can directly draw diagram elements. However, in most cases, a default effect cannot meet a requirement. For example, a default color is black, only a black graph can be drawn, and there is no blur or gradient effect by default. If more drawing effects are required, for example, drawing a red image, adding a blur effect, or adding a gradient effect, you need to set a custom brush or pen for Canvas.


Brush is used to implement the filling effect, which is targeted at the internal area of a graph. The basic effects include the filling color and anti-aliasing.


The pen is used to implement the stroke effect, which is for the outline of a graph. The basic effect includes the stroke color, width, line connection mode, and line endpoint style.


In addition, brushes and pens can achieve more complex effects, such as:


- Blend mode

- Path effect (dotted line effect)

- Shader effect (linear gradient, radial gradient, and more)

- Filter effect (such as blurring effect)


You can select either the brush or the pen as required, or set both or neither of them. If you do not set either of them, the default black brush is used.
