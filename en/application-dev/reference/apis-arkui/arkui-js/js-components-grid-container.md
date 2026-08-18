# grid-container
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @lanshouren-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

>  **NOTE**
> This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<grid-container>** component is the root container of the grid layout. Within the root container, you can use **\<grid-row>** and **\<grid-col>** for the grid layout.

## Required Permissions

Unavailable

## Child Components

Only the **\<grid-row>** component is supported.

## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| columns | string&nbsp;\|&nbsp;number | auto | No| Total number of columns in the grid. If a value of the string type is set, it can only be **auto**. In this case, the total number of columns is determined based on the current **sizetype**, which can be one of the following values:<br>- **xs**: 2 columns<br>- **sm**: 4 columns<br>- **md**: 8 columns<br>- **lg**: 12 columns|
| sizetype | string | auto | No| Size-responsive type of the grid. Available values are **xs**, **sm**, **md**, and **lg**. If the default value **auto** is used, the framework automatically selects one of the four types based on the current container size.|
| gutter | &lt;length&gt; | 24px | No| Gutter width.|
| gridtemplate<sup>6+</sup> | string | default | No| Layout template of the grid, which defines the columns, gutters, and margins for different size-responsive types. This attribute is available when **columns** and **sizetype** are set to **auto**. For details about the values, see **gridtemplate**.|

**Table 1** gridtemplate<sup>6+</sup>

| Name | Template Value| Size-responsive Type| Columns | Margins(px) | Gutters(px) |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Default grid| default | xs | 2 | 12 | 12 |
| Default grid| default | sm                               | 4       | 24          | 24          |
| Default grid| default | md                               | 8       | 32          | 24          |
| Default grid| default | lg                               | 12      |48|24|
| Grid layout| grid | sm (0 < device horizontal resolution < 600px)| 4 | 24 | 12 |
| Grid layout| grid | md                               | 8       |32|12|
| Grid layout| grid | lg                               | 12      |48|12|

>  **NOTE**
>
> The px unit is applicable when **autoDesignWidth** is set to **true** in the "js" tag.<sup>6+</sup>

## Style

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported. 

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| justify-content | string | flex-start | No| How items are aligned along the main axis of the flex container. Available values are as follows:<br>- **flex-start**: Items are packed toward the start edge of the container along the main axis.<br>- **flex-end**: Items are packed toward the end edge of the container along the main axis.<br>- **center**: Items are packed toward the center of the container along the main axis.<br>- **space-between**: Items are positioned with space between the rows.<br>- **space-around**: Items are positioned with space before, between, and after the rows.|
| align-items | string | stretch | No| How items are aligned along the cross axis in a flex container. Available values are as follows:<br>- **stretch**: Items are stretched to the same height or width as the container in the cross axis direction.<br>- **flex-start**: Items are packed toward the start edge of the cross axis.<br>- **flex-end**: Items are packed toward the end edge of the cross axis.<br>- **center**: Items are packed toward the center of the cross axis.|
| align-content | string | flex-start | No| Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:<br>- **flex-start**: All rows are packed toward the start edge of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **flex-end**: All rows are packed toward the end edge of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.<br>- **center**: All rows are packed toward the center of the cross axis. Rows are close to each other and aligned with the center of the container. The spacing between the start edge of the container's cross axis and the first row is equal to the spacing between the end edge of the container's cross axis and the last row.<br>- **space-between**: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.<br>- **space-around**: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.|

## Events

The [universal events](js-components-common-events.md) are supported.

## Method

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.
| Name| Parameter| Description|
| -------- | -------- | -------- |
| getColumns | (result: number) => void | Obtains the number of columns in the grid. **result** indicates the number of columns in the grid.|
| getColumnWidth | (result: number) => void | Obtains the column width of the grid. **result** indicates the column width of the grid.|
| getGutterWidth | (result: number) => void | Obtains the gutter width of the grid. **result** indicates the obtained gutter width of the grid.|
| getSizeType | (result: number) => void | Obtains the size-responsive type of the grid (xs\|sm\|md\|lg). **result** indicates the size-responsive type of the grid.|

## Example

For details, see [Example in grid-col](js-components-grid-col.md#example).
