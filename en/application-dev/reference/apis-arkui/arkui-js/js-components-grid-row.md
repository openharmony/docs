# grid-row

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<grid-row>** component is a container used as a child component of **\<grid-container>**. Each **\<grid-col>** component is arranged horizontally with **flex**-related styles. By default, items in the **\<grid-row>** component are packed towards the start row and aligned to the start of the cross axis. You can set the items to be displayed in multiple axes.

## Required Permissions

None


## Child Components

Only the **\<grid-col>** component is supported.


## Attributes

The [universal attributes](js-components-common-attributes.md) are supported.


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| flex-wrap | string | nowrap | No| Whether items in the flex container are displayed in a single line or multiple lines. The value cannot be dynamically updated. Available values are as follows:<br>- **nowrap**: Items are displayed on a single axis.<br>- **wrap**: Items are displayed on multiple axes.|
| justify-content | string | flex-start | No| How items are aligned along the main axis of the flex container. Available values are as follows:<br>- **flex-start**: Items are packed towards the start row.<br>- **flex-end**: Items are packed towards the end row.<br>- **center**: Items are centered along the row.<br>- **space-between**: Items are positioned with space between the rows.<br>- **space-around**: Items are positioned with space before, between, and after the rows.|
| align-items | string | flex-start | No| How items are aligned along the cross axis in a flex container. Available values are as follows:<br>- **stretch**: Items are stretched to the same height or width as the container in the cross axis direction.<br>- **flex-start**: Items are aligned to the start of the cross axis.<br>- **flex-end**: Items are aligned to the end of the cross axis.<br>- **center**: Items are aligned in the center of the cross axis.|
| align-content | string | flex-start | No| Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:<br>- **flex-start**: All rows are packed towards the start of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **flex-end**: All rows are packed towards the end of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **center**: All rows are packed towards the center of the container. Rows are close to each other and aligned with the center of the container. The spacing between the start edge of the container's cross axis and the first row is equal to the spacing between the end edge of the container's cross axis and the last row.<br>- **space-between**: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.<br>- **space-around**: All rows are evenly distributed in the container, and the spacing between two adjacent lines is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.|

>  **NOTE**
>
>  Width-related styles are not supported.


## Events

The [universal events](js-components-common-events.md) are supported.


## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

For details, see [Example in grid-col](js-components-grid-col.md#example).
