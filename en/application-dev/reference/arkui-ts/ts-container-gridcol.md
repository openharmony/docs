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
| span   | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Number of occupied columns. If it is set to **0**, the element is not involved in layout calculation, that is, the element is not rendered.<br>Default value: **1**|
| offset | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Number of offset columns relative to the previous child component of the grid<br>Default value: **0**          |
| order  | number \| [GridColColumnOption](#gridcolcolumnoption) | No  | Sequence number of the element. Child components of the grid are sorted in ascending order based on their sequence numbers.<br>Default value: **0**|

## Attributes

| Name| Type                         | Mandatory| Description                                                        |
| ------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| span   | number \| GridColColumnOption | No  | Number of occupied columns. If it is set to **0**, the element is not involved in layout calculation, that is, the element is not rendered.<br>Default value: **1**<br>Since API version 9, this API is supported in ArkTS widgets.|
| gridColOffset | number \| GridColColumnOption | No  | Number of offset columns relative to the previous child component of the grid<br>Default value: **0**<br>Since API version 9, this API is supported in ArkTS widgets.|
| order  | number \| GridColColumnOption | No  | Sequence number of the element. Child components of the grid are sorted in ascending order based on their sequence numbers.<br>Default value: **0**<br>Since API version 9, this API is supported in ArkTS widgets.|

## GridColColumnOption

Since API version 9, this API is supported in ArkTS widgets.

| Name  | Type  | Mandatory  | Description                                    |
| ----- | ------ | ---- | ---------------------------------------- |
| xs  | number | No   | Device of the minimum size.   |
| sm  | number | No   | Small-sized device.     |
| md  | number | No   | Medium-sized device.   |
| lg  | number | No   | Large-sized device.     |
| xl  | number | No   | Extra-large-sized device.   |
| xxl | number | No   | Ultra-large-sized device.   |

The values of `span`, `offset`, and `order` attributes are inherited in the sequence of `xs`, `sm`, `md`, `lg`, `xl`, and `xxl`. If no value is set for a breakpoint, the value is obtained from the previous breakpoint.

|Parameter\Breakpoint|xs|sm|md|lg|xl|xxl|
|---|---|---|---|---|---|---|
|span   |2  |2  |3  |3  |4  |4  |
|offset |2  |2  |3  |5  |5  |5  |
|order  |20 |20 |20 |3  |3  |3  |

## Example
See [GridRow](ts-container-gridrow.md#example).
