# GridCol

The **\<GridCol>** component must be used as a child component of the **[\<GridRow>](ts-container-gridrow.md)** container.

>  **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version. 

## Child Components

This component can contain only one child component.
## APIs

GridCol(option?:{span?: number | GridColColumnOption, offset?: number | GridColColumnOption, order?: number | GridColColumnOption})

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type                                                 | Mandatory| Description                                                        |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| span   | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Number of columns occupied by the component. If it is set to **0**, the component is not involved in layout calculation, that is, the component is not rendered.<br>Default value: **1**|
| offset | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Number of offset columns relative to the original position of the component.<br>Default value: **0**          |
| order  | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Sequence number of the element. Child components of the grid are sorted in ascending order based on their sequence numbers.<br>Default value: **0**<br>**NOTE**<br>If a child component shares an **order** value with another child component or does not have **order** set, it is displayed based on its code sequence number.<br>If **order** is not set for all child components, those that have **order** set are displayed after those that do not and are sorted in ascending order based on the value.|

>  **NOTE**
>
>  The values of `span`, `offset`, and `order` attributes are inherited in the sequence of **xs**, **sm**, **md**, **lg**, **xl**, and **xxl**. If no value is set for a breakpoint, the value is obtained from the previous breakpoint.
>
>  The default values vary by device width type.
>  |Parameter\Breakpoint|xs|sm|md|lg|xl|xxl|
>  |---|---|---|---|---|---|---|
>  |span   |2  |2  |3  |3  |4  |4  |
>  |offset |2  |2  |3  |5  |5  |5  |
>  |order  |20 |20 |20 |3  |3  |3  |

## Attributes

| Name| Type                         | Mandatory| Description                                                        |
| ------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| span   | number \| GridColColumnOption | No  | Number of occupied columns. If it is set to **0**, the element is not involved in layout calculation, that is, the element is not rendered.<br>Default value: **1**<br>Since API version 9, this API is supported in ArkTS widgets.|
| gridColOffset | number \| GridColColumnOption | No  | Number of offset columns relative to the previous child component of the grid<br>Default value: **0**<br>Since API version 9, this API is supported in ArkTS widgets.|
| order  | number \| GridColColumnOption | No  | Sequence number of the element. Child components of the grid are sorted in ascending order based on their sequence numbers.<br>Default value: **0**<br>Since API version 9, this API is supported in ArkTS widgets.|

## GridColColumnOption

Describes the numbers of grid columns occupied by the **\<GridCol>** component on devices with different width types.

Since API version 9, this API is supported in ArkTS widgets.

| Name  | Type  | Mandatory  | Description                                    |
| ----- | ------ | ---- | ---------------------------------------- |
| xs  | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the minimum-width device.   |
| sm  | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the small-width device.     |
| md  | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the medium-width device.   |
| lg  | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the large-width device.     |
| xl  | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the extra-large-width device.   |
| xxl | number | No   | Number of grid columns occupied by the **\<GridCol>** component on the extra-extra-large-width device.   |

## Example
See [GridRow](ts-container-gridrow.md#example).
