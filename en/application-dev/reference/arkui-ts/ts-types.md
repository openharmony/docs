# Types

## Resource

The **Resource** type is used to reference resources for setting component attributes.

You can use `$r` or `$rawfile` to create a **Resource** object, but its attribute values cannot be changed.

- `$r('belonging.type.name')`

  **belonging**: group to which the resource belongs, which can be **'sys'** or **'app'**.

  **type**: resource type, which can be **'color'**, **'float'**, **'string'**, or **'media'**.

  **name**: resource name, which is determined during resource definition.

- `$rawfile('filename')`

  **filename**: name of the file in the **resources/rawfile** directory of the project.

## Length

The **Length** type is used to represent a size unit.

| Type      | Description                                    |
| -------- | -------------------------------------- |
| string   | String type. Specify the length unit explicitly, for example, **'10px'**, or provide the length in percentage, for example, **'100%'**.|
| number   | Number type. The default unit is vp.                               |
| [Resource](#resource) | Size referenced from system or application resources.           |

## ResourceStr

The **ResourceStr** type is used to represent the types that can be used by input parameters of the string type.

| Type      | Description                          |
| -------- | ---------------------------- |
| string   | String type.                      |
| [Resource](#resource) | String referenced from system or application resources.|

## Padding

The **Padding** type is used to describe the paddings in different directions of a component.

| Name    | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| top    | [Length](#length)  | No   | Height of the padding on the top of the component. |
| right  | [Length](#length)  | No   | Width of the padding on the right of the component.|
| bottom | [Length](#length)  | No   | Height of the padding at the bottom of the component. |
| left   | [Length](#length)  | No   | Width of the padding on the left of the component.|

## Margin

The **Margin** type is used to describe the margins in different directions of a component.

| Name    | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| top    | [Length](#length)  | No   | Height of the margin above the component. |
| right  | [Length](#length)  | No   | Width of the margin on the right of the component.|
| bottom | [Length](#length)  | No   | Height of the margin below the component. |
| left   | [Length](#length)  | No   | Width of the margin on the left of the component.|

## EdgeWidths<sup>9+</sup>

The **EdgeWidths** type is used to describe the edge widths in different directions of a component.

| Name    | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | -------- |
| top    | [Length](#length) | No   | Width of the top edge of the component.|
| right  | [Length](#length) | No   | Width of the right edge of the component.|
| bottom | [Length](#length) | No   | Width of the bottom edge of the component.|
| left   | [Length](#length) | No   | Width of the left edge of the component.|

## BorderRadiuses<sup>9+</sup>

The **BorderRadiuses** type is used to describe the radius of the rounded corners of a component.

| Name         | Type    | Mandatory  | Description        |
| ----------- | ------ | ---- | ---------- |
| topLeft     | [Length](#length) | No   | Radius of the top left rounded corner of the component.|
| topRight    | [Length](#length) | No   | Radius of the top right rounded corner of the component.|
| bottomLeft  | [Length](#length) | No   | Radius of the bottom left rounded corner of the component.|
| bottomRight | [Length](#length) | No   | Radius of the bottom right rounded corner of the component.|

## EdgeColors<sup>9+</sup>

The **EdgeColors** type is used to describe the edge colors of a component.

| Name    | Type           | Mandatory  | Description      |
| ------ | ------------- | ---- | -------- |
| top    | [ResourceColor](#resourcecolor) | No   | Color of the top edge of the component.|
| right  | [ResourceColor](#resourcecolor) | No   | Color of the right edge of the component.|
| bottom | [ResourceColor](#resourcecolor) | No   | Color of the bottom edge of the component.|
| left   | [ResourceColor](#resourcecolor) | No   | Color of the left edge of the component.|

## EdgeStyles<sup>9+</sup>

The **EdgeStyles** type is used to describe the edge styles of a component.

| Name    | Type         | Mandatory  | Description      |
| ------ | ----------- | ---- | -------- |
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the top edge of the component.|
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the right edge of the component.|
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the bottom edge of the component.|
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the left edge of the component.|


## Offset

The **Offset** type is used to describe the offset coordinates of a component in the layout.

| Name  | Type    | Mandatory  | Description      |
| ---- | ------ | ---- | -------- |
| dx   | [Length](#length) | Yes   | X coordinate of the offset.|
| dy   | [Length](#length) | Yes   | Y coordinate of the offset.|

## ResourceColor

The **ResourceColor** type is used to describe the color types of resources.

| Type                                     | Description                                            |
| ---------------------------------------- | ------------------------------------------------- |
| [Color](ts-appendix-enums.md#color)      | Color enums.                                      |
| number                                   | Color in hexadecimal notation.                                     |
| string                                   | Color in RGB or RGBA notation.                             |
| [Resource](#resource)                    | Color referenced from system or application resources.|

## LengthConstrain

The **LengthConstrain** type is used to describe the maximum and minimum lengths of a component.

| Name       | Type    | Mandatory  | Description     |
| --------- | ------ | ---- | ------- |
| minLength | [Length](#length) | Yes   | Minimum length of the component.|
| maxLength | [Length](#length) | Yes   | Maximum length of the component.|


## Font

The **Font** type is used to set the text style.

| Name    | Type                                      | Mandatory  | Description                                      |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Length](#length)                        | No   | Font size. If the value is of the number type, the unit fp is used.         |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | No   | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight.|
| family | string \| [Resource](#resource)          | No   | Font family of the text. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is **'Arial, sans-serif'**.|
| style  | [FontStyle](ts-appendix-enums.md#fontstyle) | No   | Font style.                              |

## Area<sup>8+</sup>

The **Area** type is used to describe the area information of a component.

| Name            | Type                    | Description                            |
| -------------- | ---------------------- | ------------------------------ |
| width          | [Length](#length)      | Width of the component. The value is of the number type in vp when used as the return value.|
| height         | [Length](#length)      | Height of the component. The value is of the number type in vp when used as the return value.|
| position       | [Position](#position8) | Position of the upper left corner of the component relative to that of its parent container.           |
| globalPosition | [Position](#position8) | Position of the upper left corner of the component relative to that of the page where the component resides.            |

## Position<sup>8+</sup>

The **Position** type is used to represent coordinates of a point.

| Name  | Type    | Mandatory  | Description                         |
| ---- | ------ | ---- | --------------------------- |
| x    | [Length](#length) | No   | X coordinate. The value is of the number type in vp when used as the return value.|
| y    | [Length](#length) | No   | Y coordinate. The value is of the number type in vp when used as the return value.|

## ConstraintSizeOptions

The **ConstraintSizeOptions** type is used to set the size constraints of a component during component layout.

| Name       | Type    | Mandatory  | Description     |
| --------- | ------ | ---- | ------- |
| minWidth  | [Length](#length) | No   | Minimum width of the component.|
| maxWidth  | [Length](#length) | No   | Maximum width of the component.|
| minHeight | [Length](#length) | No   | Minimum height of the component.|
| maxHeight | [Length](#length) | No   | Maximum height of the component.|

## SizeOptions

The **SizeOptions** type is used to set the width and height.

| Name    | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| width  | [Length](#length) | No   | Width of the component.|
| height | [Length](#length) | No   | Height of the component.|


## BorderOptions

The **BorderOptions** type is used to provide border information.

| Name    | Type                                      | Mandatory  | Description     |
| ------ | ---------------------------------------- | ---- | ------- |
| width  | [Length](#length)  \| [EdgeWidths](#edgewidths9)<sup>9+</sup>       | No   | Border width.  |
| color  | [ResourceColor](#resourcecolor) \| [EdgeColors](#edgecolors9)<sup>9+</sup> | No   | Border color.  |
| radius | [Length](#length) \| [BorderRadiuses](#borderradiuses9)<sup>9+</sup>    | No   | Radius of the rounded corner border.|
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)  \| EdgeStyles<sup>9+</sup> | No   | Border style.  |

## ColorFilter<sup>9+</sup>

The **ColorFilter** type is used to create a color filter with a 4 x 5 matrix.

| Name         | Type      | Mandatory  | Description                                      |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | Yes   | Constructor for creating a color filter with a 4 x 5 matrix. The input parameter is [m*n], which is the matrix value in row m and column n. The matrix is row-first.|


## CustomBuilder<sup>8+</sup>

The **CustomBuilder** type is used to define custom UI descriptions in component attribute methods.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | Must be decorated by **@Builder**. For details, see [@Builder](../../quick-start/arkts-dynamic-ui-elememt-building.md#builder).|
