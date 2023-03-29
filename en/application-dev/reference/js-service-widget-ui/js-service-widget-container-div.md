# div


The **\<div>** component is a basic container that is used as the root node of the page structure or is used to group the content.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Supported


## Attributes

The [universal attributes](js-service-widget-common-attributes.md) are supported.


## Styles

In addition to the [universal styles](js-service-widget-common-styles.md), the following styles are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| flex-direction | string | row | No| Main axis direction of the flex container, which defines how items are placed in the container. Available values are as follows:<br>- **column**: Items are placed vertically from top to bottom.<br>- **row**: Items are placed horizontally from left to right.|
| flex-wrap | string | nowrap | No| Whether items in the flex container are displayed in a single line or multiple lines. The value cannot be dynamically updated. Available values are as follows:<br>- **nowrap**: Flex items are displayed in a single line.<br>- **wrap**: Flex items are displayed in multiple lines.|
| justify-content | string | flex-start | No| How items are aligned along the main axis of the flex container. Available values are as follows:<br>- **flex-start**: Items are packed toward the start edge of the container along the main axis.<br>- **flex-end**: Items are packed toward the end edge of the container along the main axis.<br>- **center**: Items are packed toward the center of the container along the main axis.<br>- **space-between**: Items are positioned with space between the rows.<br>- **space-around**: Items are positioned with space before, between, and after the rows.<br>- **space-evenly**<sup>5+</sup>: Items are distributed within the container along the main axis, with even space between each two.|
| align-items | string | stretch | No| How items are aligned along the cross axis in a flex container. Available values are as follows:<br>- **stretch**: Items are stretched to the same height or width as the container along the cross axis.<br>- **flex-start**: Items are packed toward the start edge of the cross axis.<br>- **flex-end**: Items are packed toward the end edge of the cross axis.<br>- **center**: Items are packed toward the center of the cross axis.|
| align-content | string | flex-start | No| Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:<br>- **flex-start**: All rows are packed toward the start edge of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **flex-end**: All rows are packed toward the end edge of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **center**: All rows are packed toward the center of the cross axis. Rows are close to each other and aligned with the center of the container. The spacing between the start edge of the container's cross axis and the first row is equal to the spacing between the end edge of the container's cross axis and the last row.<br>- **space-between**: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.<br>- **space-around**: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.|
| display | string | flex | No| Type of the view box of the item. The value cannot be dynamically updated. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| grid-template-[columns\|rows] | string | 1 row, 1 column| No| Number of rows and columns in the current grid layout. If this attribute is not set, one row and one column are displayed by default. This attribute is valid only when **display** is set to **grid**.<br>Below are some example values of **grid-template-columns**:<br>- **50px 100px 60px**: There are three columns. The first column is 50 px, the second column is 100 px, and the third column is 60 px.<br>- **1fr 1fr 2fr**: There are three columns, and the width allowed by the parent component is divided into four equal shares. The first column occupies one share, the second column occupies one share, and the third column occupies two shares.<br>- **30% 20% 50%**: There are three columns. The first column occupies 30% of the total width allowed by the parent component, the second column occupies 20%, and the third column occupies 50%.<br>- **repeat (2,100px)**: There are two columns. The first column is 100 px, and the second column is 100 px.<br>- **repeat(auto-fill,100px)**<sup>5+</sup>: Each column is 100 px and repeats to fill the cross axis. The number of columns is calculated based on the column size and the cross axis size.<br>- **auto 1fr 1fr**: There are three columns. The first column is adaptive to the width required by its child components. The remaining space is divided into two equal shares, one share occupied by each of the rest two columns.|
| grid-[columns\|rows]-gap | &lt;length&gt; | 0 | No| Size of the gap between two consecutive rows or columns in a grid layout. You can also use **grid-gap** to set the same size of the gap between rows and columns. This attribute is valid only when **display** is set to **grid**.|
| grid-row-[start\|end] | number | - | No| Start and end row numbers of the current item in the grid layout. This attribute is valid only when the item's parent component is a **\<div>** container whose **display** style is set to **grid**.|
| grid-column-[start\|end] | number | - | No| Start and end column numbers of the current item in the grid layout. This attribute is valid only when the item's parent component is a **\<div>** container whose **display** style is set to **grid**.|
| grid-auto-flow | string | - | No| How grid items are laid out automatically. Available values are as follows:<br>- **row**: Elements are filled row by row. When there is no horizontal space in a row, a new row is added.<br>- **column**: Elements are filled column by column. When there is no vertical space in a column, a new column is added.|
| align-items | string | - | No| How items are aligned along the cross axis in a flex container. Available values are as follows:<br>- **stretch**: Items are stretched to the same height or width as the flex container along the cross axis.<br>- **flex-start**: Items are aligned to the start of the cross axis.<br>- **flex-end**: Items are aligned to the end of the cross axis.<br>- **center**: Items are aligned in the center of the cross axis.<br>- **baseline**: In a vertical layout, items are aligned to the start of the cross axis, which means that this value is equivalent of **flex-start**. In a horizontal layout, items are aligned with the text baseline if there is text involved, and aligned to the bottom otherwise.|


## Events

The [universal events](js-service-widget-common-events.md) are supported.


## Example

1. Flex style
  
   ```html
   <!-- xxx.hml -->
   <div class="container">
     <div class="flex-box">
       <div class="flex-item color-primary"></div>
       <div class="flex-item color-warning"></div>
       <div class="flex-item color-success"></div>
     </div>
   </div>
   ```

   
   ```css
   /* xxx.css */
   .container {
     flex-direction: column;
     justify-content: center;
     align-items: center;
     width: 454px;
     height: 454px;
   }
   .flex-box {
     justify-content: space-around;
     align-items: center;
     width: 400px;
     height: 140px;
     background-color: #ffffff;
   }
   .flex-item {
     width: 120px;
     height: 120px;
     border-radius: 16px;
   }
   .color-primary {
     background-color: #007dff;
   }
   .color-warning {
     background-color: #ff7500;
   }
   .color-success {
     background-color: #41ba41;
   }
   ```
    **2 x 4 widget**

    ![en-us_image_0000001231610863](figures/en-us_image_0000001231610863.png)

2. Flex wrap style
  
   ```html
   <!-- xxx.hml -->
   <div class="container">
     <div class="flex-box">
       <div class="flex-item color-primary"></div>
       <div class="flex-item color-warning"></div>
       <div class="flex-item color-success"></div>
     </div>
   </div>
   ```

   
   ```css
   /* xxx.css */
   .container {
     flex-direction: column;
     justify-content: center;
     align-items: center;
     width: 454px;
     height: 454px;
   }
   .flex-box {
     justify-content: space-around;
     align-items: center;
     flex-wrap: wrap;
     width: 300px;
     height: 250px;
     background-color: #ffffff;
   }
   .flex-item {
     width: 120px;
     height: 120px;
     border-radius: 16px;
   }
   .color-primary {
     background-color: #007dff;
   }
   .color-warning {
     background-color: #ff7500;
   }
   .color-success {
     background-color: #41ba41;
   }
   ```
   **4 x 4 widget**

   ![en-us_image_0000001186131150](figures/en-us_image_0000001186131150.png)
