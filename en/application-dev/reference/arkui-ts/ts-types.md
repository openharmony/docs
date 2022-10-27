# Types

## Resource

The **Resource** type is used to reference resources for setting component attribute values.

If a **Resource** object is created using `$r` or `$rawfile`, modifying attribute values of the object is prohibited.

- `$r('belonging.type.name')`

  **belonging**: system or application resource. The value can be **'sys'** or **'app'**.

  **type**: resource type, which can be **'color'**, **'float'**, **'string'**, or **'media'**.

  **name**: resource name, which is determined during resource definition.

- `$rawfile('filename')`

  **filename**: name of the file in **resources/rawfile** of the project.

## Length

The **Length** type is used to represent a size unit.

| Type      | Description                                    |
| -------- | -------------------------------------- |
| string   | String type. Explicitly specify the length unit, for example, **'10px'**, or the length in percentage, for example, **'100%'**.|
| number   | Number type. The default unit is vp.                               |
| [Resource](#resource) | Size referenced from system or application resources.           |

## ResourceStr<sup>8+</sup>

The **ResourceStr** type is used to represent the types that can be used by input parameters of the string type.

| Type      | Description                          |
| -------- | ---------------------------- |
| string   | String type.                      |
| [Resource](#resource) | String referenced from system or application resources.|

## Padding

The **Padding** type is used to describe the padding areas in different directions of a component.

| Name    | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| top    | [Length](#length) | No   | Height of the padding area on the top of the component. |
| right  | [Length](#length) | No   | Width of the padding area on the right of the component.|
| bottom | [Length](#length) | No   | Height of the padding area at the bottom of the component. |
| left   | [Length](#length) | No   | Width of the padding area on the left of the component.|

## Margin

The **Margin** type is used to describe the margin areas in different directions of a component.

| Name    | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| top    | [Length](#length) | No   | Height of the margin area above the component. |
| right  | [Length](#length) | No   | Width of the margin area on the right of the component.|
| bottom | [Length](#length) | No   | Height of the margin area below the component. |
| left   | [Length](#length) | No   | Width of the margin area on the left of the component.|

## Offset

The **Offset** type is used to describe the offset coordinates of a component in the layout.

| Name  | Type    | Mandatory  | Description      |
| ---- | ------ | ---- | -------- |
| dx   | [Length](#length) | Yes   | Horizontal offset.|
| dy   | [Length](#length) | Yes   | Vertical offset.|

## ResourceColor<sup>8+</sup>

The **ResourceColor** type is used to describe the color types of resources.

| Type                                     | Description                                            |
| ---------------------------------------- | ------------------------------------------------- |
| [Color](ts-appendix-enums.md#color)      | Color enum.                                      |
| number                                   | Color in the hexadecimal notation.                                     |
| string                                   | Color in the RGB or RGBA notion.                             |
| [Resource](#resource)                    | Color referenced from system or application resources.|


## Font

The **Font** type is used to set the text style.

| Name    | Type                                      | Mandatory  | Description                                      |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Length](#length)                        | No   | Font size. If the value is of the number type, the unit fp is used.         |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | No   | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight.|
| family | string \| [Resource](#resource)          | No   | Font family of the text. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is **'Arial, sans-serif'**.|
| style  | [FontStyle](ts-appendix-enums.md#fontstyle) | No   | Font style.                              |

## Area<sup>8+</sup>

The **Area** type is used to describe the area information of the target element.

| Name            | Type                    | Mandatory                   | Description                            |
| -------------- | ---------------------- | ------------------------------ | ------------------------------ |
| width          | [Length](#length)      | Yes | Width of the target element. The value is of the number type when being used as the return value and the unit is vp.|
| height         | [Length](#length)      | Yes | Height of the target element. The value is of the number type when being used as the return value and the unit is vp.|
| position       | [Position](#position8) | Yes        | Position of the upper left corner of the target element relative to that of the parent element.           |
| globalPosition | [Position](#position8) | Yes         | Position of the upper left corner of the target element relative to that of the page.            |


## Position<sup>8+</sup>

The **Position** type is used to represent coordinates of a point.

| Name  | Type    | Mandatory  | Description                         |
| ---- | ------ | ---- | --------------------------- |
| x    | [Length](#length) | No   | X coordinate. The value is of the number type when being used as the return value and the unit is vp.|
| y    | [Length](#length) | No   | Y coordinate. The value is of the number type when being used as the return value and the unit is vp.|

## ConstraintSizeOptions

The **ConstraintSizeOptions** type is used to set the constraint size of a component, thereby limiting the size range during component layout.

| Name       | Type    | Mandatory  | Description     |
| --------- | ------ | ---- | ------- |
| minWidth  | [Length](#length) | No   | Minimum width of the element.|
| maxWidth  | [Length](#length) | No   | Maximum width of the element.|
| minHeight | [Length](#length) | No   | Minimum height of the element.|
| maxHeight | [Length](#length) | No   | Maximum height of the element.|

## SizeOptions

The **SizeOptions** type is used to set the width and height.

| Name    | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| width  | [Length](#length) | No   | Width of the element.|
| height | [Length](#length) | No   | Height of the element.|


## BorderOptions

The **BorderOptions** type is used to provide border information.

| Name    | Type                                      | Mandatory  | Description     |
| ------ | ---------------------------------------- | ---- | ------- |
| width  | [Length](#length)       | No   | Border width.  |
| color  | [ResourceColor](#resourcecolor8) | No   | Border color.  |
| radius | [Length](#length)    | No   | Radius of the rounded corner border.|
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Border style.  |

## CustomBuilder<sup>8+</sup>

The **CustomBuilder** type is used to define custom UI descriptions in component attribute methods.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | Must be decorated by **@Builder**. For details, see [@Builder](../../ui/ts-component-based-builder.md).|
