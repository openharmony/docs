# Layout Description


The baseline width for page design is 720 logical pixels. The display width of a page element depends on the ratio of the screen width to the baseline width.


For example, when the width of a component is 100 px, its display width is converted as follows:


On a screen with the width of 720 physical pixels, the display width is 100 physical pixels. On a screen with the width of 1440 physical pixels, the display width is 200 physical pixels.

Basic page elements include title, text, and image areas. Each basic element may contain multiple sub-elements. You can add components, such as buttons, switches, and progress bars, to these elements and sub-elements as required. When setting the layout, you need to consider the following for each basic element:


- Size and arrangement

- Overlapping with other elements

- Alignment, padding, and margin

- Sub-elements and their positions

- Container components and their types

  You can disassemble elements on the page first and then implement them in sequence. This reduces visual confusion and logical conflicts caused by element nesting and improves code readability for easier modification. For example, as shown below, you disassemble the page elements and elements in the comment area.

**Figure 1** Page layout

![en-us_image_0000001070558189](figures/en-us_image_0000001070558189.png)

**Figure 2** Layout of the comment area

![en-us_image_0000001063442797](figures/en-us_image_0000001063442797.png)
