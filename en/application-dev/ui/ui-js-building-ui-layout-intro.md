# Layout Description<a name="EN-US_TOPIC_0000001063230905"></a>

The basic element width on devices is 720 px \(logical pixels\). The actual display effect is scaled based on the ratio of the actual screen width to the basic width.

The conversion is as follows:

If you set the component width to 100 px, the display width of the component is 100 physical px on the screen with the width of 720 physical px. On a screen with a width of 1440 physical px, the display width of the component is 200 physical px.

Basic page elements include title, text, and image areas. Each basic element may contain multiple sub-elements. You can add components such as buttons, switches, and progress bars as required. When setting the layout, you need to consider the following for each basic element:

-   Size and arrangement
-   Overlapped with another element
-   Alignment, padding, and margin
-   Sub-elements and their positions
-   Container components and their types

You can disassemble elements on the page first and then implement them in sequence. This reduces visual confusion and logical conflicts caused by element nesting and improves code readability for easier modification. The following figure is used as an example.

**Figure  1**  Page layout<a name="fig11335192315417"></a>  
![](figures/page-layout.png "page-layout")

**Figure  2**  Layout of the comment area<a name="fig186911810182717"></a>  


![](figures/图片3.png)

