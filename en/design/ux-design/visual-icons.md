# System Icons

Icons are one of the key visual elements for the operating system and UI. They must help users easily identify the key information and semantics they represent. To ensure consistent visual experience across devices, the icon elements should be consistent and match the background against different devices in various scenarios. In addition, the color rules of human factors must be followed to provide a comfortable reading experience and a harmonious UI display for users. The system's design rules also must be followed for area charts and line charts, which use the same graphic structure to reduce the reading difficulty.


![en-us_image_0000001517612980](figures/en-us_image_0000001517612980.jpg)


## Design Principles

OpenHarmony system icons pursue the design principles of exquisiteness, simplicity, and particularity. They mainly use geometry to shape graphics, simplify the structure of lines, and accurately grasp the proportion relationship. Up-to-date design languages are added to the style to make it look more fashionable. Sharp right angles are avoided to ensure that the style looks friendly and inviting.

| <div style="width:50%">Exquisiteness and simplicity</div>| <div style="width:50%">Particularity</div>|
|  --------  |  --------  |
| Born from geometric shapes, simple lines, and precise control of proportions and structural positions.| Opening details show the intercalation and folding relationships, and the negative space conveys the shadow and a sense of space.   |
| ![en-us_image_0000001559920864.png](figures/en-us_image_0000001559920864.png) |   ![en-us_image_0000001559601332.png](figures/en-us_image_0000001559601332.png)   |

## Icon Styles

The system icon has two styles: outlined icon and filled icon. The two styles use the same structure to ensure consistent visual experience. <br>Icons are classified into single-color icons and dual-color icons based on use scenarios. Single-color icons are used to assist in expressing basic functions on the UI.
| ![en-us_image_0000001610200817](figures/en-us_image_0000001610200817.png) | ![en-us_image_0000001559442068](figures/en-us_image_0000001559442068.png) |
| -------- | -------- |
| Outlined icons|Filled icons|

A dual-color icon expresses the colorful dual-color effect based on the filled style. This type of icon is mainly used in scenarios where functions need to be highlighted.
|  ![en-us_image_0000001610401157](figures/en-us_image_0000001610401157.png) |  ![en-us_image_0000001610280813](figures/en-us_image_0000001610280813.png)|
| -------- | -------- |
| Status icon - off| Status icon - on |
| ![en-us_image_0000001609961253](figures/en-us_image_0000001609961253.png) | ![en-us_image_0000001559760964](figures/en-us_image_0000001559760964.png) |
|Functional entry icons| Operational entry icons|


## Icon Size and Layout

The standard size of a system icon is 24 vp. The size of an icon in the main drawing area is 22 vp, with 1 vp of space reserved around the drawing area.

| ![en-us_image_0000001559920868](figures/en-us_image_0000001559920868.png) |![en-us_image_0000001559601336](figures/en-us_image_0000001559601336.png)|
| -------- | -------- |
|Drawing area|Space area|

**Key Shapes**

Key shapes are the foundation of the grid. Using these core shapes as a guide ensures a visually consistent scale and volume in the icons related to the product.

| ![en-us_image_0000001610200821](figures/en-us_image_0000001610200821.png) | ![en-us_image_0000001559442072](figures/en-us_image_0000001559442072.png)|
| -------- | -------- |
|Square<br>Width and height: 20 vp| Circle<br>Diameter: 22 vp|
| ![en-us_image_0000001610401161](figures/en-us_image_0000001610401161.png) | ![en-us_image_0000001610280817](figures/en-us_image_0000001610280817.png) |
|Horizontal rectangle<br>Width: 22 vp<br>Height: 18 vp|Vertical rectangle<br>Width: 18 vp<br>Height: 22 vp|

**Extra Visual Weight**

If the icon shape is special, extra visual weight needs to be added to balance the overall icon volume. The drawing area can be extended into the space area, but the overall icon size remains within 24 vp.

  |![en-us_image_0000001609961257](figures/en-us_image_0000001609961257.png) | ![en-us_image_0000001559760968.png](figures/en-us_image_0000001559760968.png) |
| -------- | -------- |

**Gravity Center of Icons**
Ensure that the gravity center of an icon is in the center of the icon area. Given that the gravity center of the icon is stable, the icon can extend beyond the drawing area to the space area.
| ![en-us_image_0000001559920872](figures/en-us_image_0000001559920872.png) |![en-us_image_0000001610200829](figures/en-us_image_0000001610200829.png) |
| -------- | -------- |
|![green](figures/green.png)<br>Recommended|![red](figures/red.png)<br>Not recommended|

## Shape Characteristics

1. Line thickness: 1.5 vp

2. End point style: round head

3. Outer rounded corner: 4 vp; inner rounded corner: 2.5 vp

4. Opening width: 1 vp

![canvas](figures/canvas.png)

| | |
| -------- | -------- |
| ![en-us_image_0000001610280821](figures/en-us_image_0000001610280821.png) | **Cut-off**<br>1. Leave a margin in the upper part for the cut-off line and retain the connection line in the lower part.<br>2. Opening width: 1 vp<br>3. The cutting surface should be flat and straight. <br>4. The oblique line is 45 degrees from the upper left corner to the lower right corner. |

**Graphics Overlay**

Two icons are used together to demonstrate the concepts of clusters, groups, and sets.
Leave a margin of 1 vp between shapes.
| ![en-us_image_0000001609961261](figures/en-us_image_0000001609961261.png) |  ![en-us_image_0000001559920876](figures/en-us_image_0000001559920876.png)|
| -------- | -------- |
| ![green](figures/green.png)<br>Recommended| ![red](figures/red.png)<br>Not recommended|

 Add the inner rounded corner of 3.5 vp to the corner of the icon gap.

| ![en-us_image_0000001610200833](figures/en-us_image_0000001610200833.png)  |  ![en-us_image_0000001610401169](figures/en-us_image_0000001610401169.png)  |
|  --------  |  --------  |
| ![green](figures/green.png)<br>Recommended  |![red](figures/red.png)<br>Not recommended  |


## Icon Resource Naming Rules

**Naming example: *ic_Module_Function_Location_Color_Status_Number***

*ic_Module_Function* is mandatory, and *Location_Color_Status_Number* is optional.

Note: All resource names must be in lowercase. Long fields can be abbreviated. The name cannot contain spaces. Different fields are separated by underscores (_).

![en-us_image_0000001609961265](figures/en-us_image_0000001609961265.png)


For details about the default icon library provided by OpenHarmony, see [Resources](design-resources.md).
