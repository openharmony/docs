# Basic Types

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Resource

**Atomic service API**: This API can be used in atomic services since API version 11.

The **Resource** type is used to reference resources for setting component attributes.

You can use `$r` or `$rawfile` to create a **Resource** object, but its attribute values cannot be changed.

- `$r('belonging.type.name')`

  **belonging**: group to which the resource belongs, which can be **'sys'** or **'app'**.

  **type**: resource type, which can be '**boolean'**, **'color'**, **'float'**, **'intarray'**, **'integer'**, **'pattern'**, '**plural'**, **'strarray'**, **'string'**, or **'media'**.

  **name**: resource name, which is determined during resource definition.

- `$rawfile('filename')`

  **filename**: name of the file in the **resources/rawfile** directory of the project.

  **NOTE**<br>When referencing resources of the **Resource** type, make sure the data type is the same as that of the attribute method. For example, if an attribute method supports the **string | Resource** types, the data type of the **Resource** type must be string.

## Length

The **Length** type is used to represent a size unit.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| string                | String type. Specify the length unit explicitly, for example, **'10px'**, or provide the length in percentage, for example, **'100%'**.|
| number                | Number type. The default unit is vp.                               |
| [Resource](#resource) | Size referenced from system or application resources.              |

## ResourceStr

The **ResourceStr** type is used to represent the types that can be used by input parameters of the string type.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                       |
| --------------------- | ------------------------- |
| string                | String type.                   |
| [Resource](#resource) | String referenced from system or application resources.|

## ASTCResource<sup>12+</sup>

The **ASTCResource** type is used to describe texture stitching.

| Type                   | Description                       |
| --------------------- | ------------------------- |
| sources               | URI array, indicating the textures to be stitched.                   |
| column                | Column size, indicating the number of textures to be stitched in each row.|

## Padding

The **Padding** type is used to describe the paddings in different directions of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | No   | Height of the padding on the top of the component. |
| right  | [Length](#length) | No   | Width of the padding on the right of the component.|
| bottom | [Length](#length) | No   | Height of the padding at the bottom of the component. |
| left   | [Length](#length) | No   | Width of the padding on the left of the component.|

## LocalizedPadding<sup>12+</sup>

The **Padding** type is used to describe the paddings in different directions of a component.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Height of the padding on the top of the component. |
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the padding on the right of the component.<br>For right-to-left scripts:<br>Width of the padding on the left of the component.|
| bottom | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Height of the padding at the bottom of the component. |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the padding on the left of the component.<br>For right-to-left scripts:<br>Width of the padding on the right of the component.|

## Margin

The **Margin** type is used to describe the margins in different directions of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | No   | Height of the margin above the component. |
| right  | [Length](#length) | No   | Width of the margin on the right of the component.|
| bottom | [Length](#length) | No   | Height of the margin below the component. |
| left   | [Length](#length) | No   | Width of the margin on the left of the component.|

## LocalizedMargin<sup>12+</sup>

The **Margin** type is used to describe the margins in different directions of a component.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [LengthMetrics<](../js-apis-arkui-graphics.md#lengthmetrics12)sup>12+</sup> | No   | Height of the margin above the component. |
| end    | [LengthMetrics<](../js-apis-arkui-graphics.md#lengthmetrics12)sup>12+</sup> | No   | Width of the margin on the right of the component.<br>For right-to-left scripts:<br>Width of the margin on the left of the component.|
| bottom | [LengthMetrics<](../js-apis-arkui-graphics.md#lengthmetrics12)sup>12+</sup> | No   | Height of the margin below the component. |
| start  | [LengthMetrics<](../js-apis-arkui-graphics.md#lengthmetrics12)sup>12+</sup> | No   | Width of the margin on the left of the component.<br>For right-to-left scripts:<br>Width of the margin on the right of the component.|

## EdgeWidths<sup>9+</sup>

The **EdgeWidths** type is used to describe the edge widths in different directions of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type               | Mandatory  | Description      |
| ------ | ----------------- | ---- | -------- |
| top    | [Length](#length) | No   | Width of the top edge of the component.|
| right  | [Length](#length) | No   | Width of the right edge of the component.|
| bottom | [Length](#length) | No   | Width of the bottom edge of the component.|
| left   | [Length](#length) | No   | Width of the left edge of the component.|

## LocalizedEdgeWidths<sup>12+</sup>

The **EdgeWidths** type is used to describe the edge widths in different directions of a component.

| Name    | Type               | Mandatory  | Description      |
| ------ | ----------------- | ---- | -------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the top edge of the component.|
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the right edge of the component.<br>Width of the left edge of the component for right-to-left scripts.|
| bottom | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the bottom edge of the component.|
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Width of the left edge of the component.<br>Width of the right edge of the component for right-to-left scripts.|

## BorderRadiuses<sup>9+</sup>

The **BorderRadiuses** type is used to describe the radius of the rounded corners of a component.

| Name         | Type               | Mandatory  | Description        |
| ----------- | ----------------- | ---- | ---------- |
| topLeft     | [Length](#length) | No   | Radius of the top left rounded corner of the component.|
| topRight    | [Length](#length) | No   | Radius of the top right rounded corner of the component.|
| bottomLeft  | [Length](#length) | No   | Radius of the bottom left rounded corner of the component.|
| bottomRight | [Length](#length) | No   | Radius of the bottom right rounded corner of the component.|

## LocalizedBorderRadiuses<sup>12+</sup>

The **BorderRadiuses** type is used to describe the radius of the rounded corners of a component.

| Name         | Type               | Mandatory  | Description        |
| ----------- | ----------------- | ---- | ---------- |
| topStart    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Radius of the top left rounded corner of the component.<br>Radius of the top right rounded corner of the component for right-to-left scripts.|
| topEnd      | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Radius of the top right rounded corner of the component.<br>Radius of the top left rounded corner of the component for right-to-left scripts.|
| bottomStart | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Radius of the bottom left rounded corner of the component.<br>Radius of the bottom right rounded corner of the component for right-to-left scripts.|
| bottomEnd   | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | No   | Radius of the bottom right rounded corner of the component.<br>Radius of the bottom left rounded corner of the component for right-to-left scripts.|

## EdgeColors<sup>9+</sup>

The **EdgeColors** type is used to describe the edge colors of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type                             | Mandatory  | Description      |
| ------ | ------------------------------- | ---- | -------- |
| top    | [ResourceColor](#resourcecolor) | No   | Color of the top edge of the component.|
| right  | [ResourceColor](#resourcecolor) | No   | Color of the right edge of the component.|
| bottom | [ResourceColor](#resourcecolor) | No   | Color of the bottom edge of the component.|
| left   | [ResourceColor](#resourcecolor) | No   | Color of the left edge of the component.|

## LocalizedEdgeColors<sup>12+</sup>

The **EdgeColors** type is used to describe the edge colors of a component.

| Name    | Type                             | Mandatory  | Description      |
| ------ | ------------------------------- | ---- | -------- |
| top    | [ResourceColor](#resourcecolor) | No   | Color of the top edge of the component.|
| end    | [ResourceColor](#resourcecolor) | No   | Color of the right edge of the component.<br>Color of the left edge of the component for right-to-left scripts.|
| bottom | [ResourceColor](#resourcecolor) | No   | Color of the bottom edge of the component.|
| start  | [ResourceColor](#resourcecolor) | No   | Color of the left edge of the component.<br>Color of the right edge of the component for right-to-left scripts.|

## EdgeStyles<sup>9+</sup>

The **EdgeStyles** type is used to describe the edge styles of a component.

| Name    | Type                                      | Mandatory  | Description      |
| ------ | ---------------------------------------- | ---- | -------- |
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the top edge of the component.|
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the right edge of the component.|
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the bottom edge of the component.|
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | No   | Style of the left edge of the component.|


## Offset

The **Offset** type is used to describe the offset coordinates of a component in the layout.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type               | Mandatory  | Description      |
| ---- | ----------------- | ---- | -------- |
| dx   | [Length](#length) | Yes   | X coordinate of the offset.|
| dy   | [Length](#length) | Yes   | Y coordinate of the offset.|

## RectResult<sup>10+</sup>

The **RectResult** type is used to describe the position, width, and height of a component.

| Name     | Type    | Description|
| ------- | ------ | ----------------------- |
| x     | number | Horizontal coordinate.|
| y     | number | Vertical coordinate.|
| width | number | Content width.|
| height | number | Content height.|

## ResourceColor

The **ResourceColor** type is used to describe the color types of resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [Color](ts-appendix-enums.md#color) | Color enums.                                                |
| number                              | Color in hexadecimal notation. RGB and ARGB are supported. Examples: **0xffffff** and **0xffff0000**.  |
| string                              | Color in RGB or ARGB notation. Example: **'#ffffff', '#ff000000', 'rgb(255, 100, 255)', 'rgba(255, 100, 255, 0.5)'**|
| [Resource](#resource)               | Color referenced from system or application resources.      |

## ColoringStrategy<sup>10+</sup>

The **ColoringStrategy** type is used to describe the foreground and shadow colors.

| Name    | Description             |
| ------ | --------------- |
| INVERT | The foreground colors are the inverse of the component background colors.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AVERAGE<sup>11+</sup> | The shadow colors of the component are the average color obtained from the component background shadow area.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PRIMARY<sup>11+</sup> | The shadow colors of the component are the primary color obtained from the component background shadow area.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## LengthConstrain

The **LengthConstrain** type is used to describe the maximum and minimum lengths of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name       | Type               | Mandatory  | Description     |
| --------- | ----------------- | ---- | ------- |
| minLength | [Length](#length) | Yes   | Minimum length of the component.|
| maxLength | [Length](#length) | Yes   | Maximum length of the component.|


## Font

The **Font** type is used to set the text style.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Length](#length)                                            | No  | Font size. If the value is of the number type, the unit fp is used. The value cannot be a percentage.<br>Default value: **16.0**|
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | No  | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a thicker font.<br>Default value: **400** \| **FontWeight.Normal** |
| family | string \| [Resource](#resource)                              | No  | Font family of the text. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is **'Arial, HarmonyOS Sans'**. The 'HarmonyOS Sans' font and [registered custom fonts](../js-apis-font.md) are supported.|
| style  | [FontStyle](ts-appendix-enums.md#fontstyle)                  | No  | Font style.<br>Default value: **FontStyle.Normal**            |

## Area<sup>8+</sup>

The **Area** type is used to describe the area information of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name            | Type                    | Description                            |
| -------------- | ---------------------- | ------------------------------ |
| width          | [Length](#length)      | Width of the component. The value is of the number type in vp when used as the return value.|
| height         | [Length](#length)      | Height of the component. The value is of the number type in vp when used as the return value.|
| position       | [Position](#position) | Position of the upper left corner of the component relative to that of its parent container.           |
| globalPosition | [Position](#position) | Position of the upper left corner of the component relative to that of the page where the component resides.            |

## Position

The **Position** type is used to represent coordinates of a point.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type               | Mandatory  | Description                         |
| ---- | ----------------- | ---- | --------------------------- |
| x    | [Length](#length) | No   | X coordinate. The value is of the number type in vp when used as the return value.|
| y    | [Length](#length) | No   | Y coordinate. The value is of the number type in vp when used as the return value.|

## LocalizedPosition<sup>12+</sup>

The **LocalizedPosition** type is used to represent coordinates of a point.

| Name  | Type               | Mandatory  | Description                         |
| ---- | ----------------- | ---- | --------------------------- |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | X-coordinate relative to the left for left-to-right scripts; X-coordinate relative to the right for right-to-left scripts. |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Y-coordinate.|

## Edges<sup>12+</sup>

The **Edges** type is used to describe the offset relative to the four edges. If both **top** and **bottom** are set, only **top** takes effect. If both **left** and **right** are set, only **left** takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type    | Mandatory  | Description                         |
| ---- | ------ | ---- | --------------------------- |
| top    | [Dimension](#dimension10) | No   | Offset relative to the top edge.|
| bottom    | [Dimension](#dimension10) | No   | Offset relative to the bottom edge.|
| left    | [Dimension](#dimension10) | No   | Offset relative to the left edge.|
| right    | [Dimension](#dimension10) | No   | Offset relative to the right edge.|

## LocalizedEdges<sup>12+</sup>

The **LocalizedEdges** type is used to describe the offset relative to the four edges. If both **top** and** bottom **are set, only **top** takes effect. If both **start** and **end** are set, only **start** takes effect.

| Name  | Type    | Mandatory  | Description                         |
| ---- | ------ | ---- | --------------------------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Offset relative to the top edge.|
| bottom    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Offset relative to the bottom edge.|
| start    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Offset relative to the left for left-to-right scripts; offset relative to the right for right-to-left scripts.|
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No   | Offset relative to the right for left-to-right scripts; offset relative to the left for right-to-left scripts.|

## ConstraintSizeOptions

The **ConstraintSizeOptions** type is used to set the size constraints of a component during component layout.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name       | Type               | Mandatory  | Description     |
| --------- | ----------------- | ---- | ------- |
| minWidth  | [Length](#length) | No   | Minimum width of the component.|
| maxWidth  | [Length](#length) | No   | Maximum width of the component.|
| minHeight | [Length](#length) | No   | Minimum height of the component.|
| maxHeight | [Length](#length) | No   | Maximum height of the component.|

## SizeOptions

The **SizeOptions** type is used to set the width and height.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type               | Mandatory  | Description   |
| ------ | ----------------- | ---- | ----- |
| width  | [Length](#length) | No   | Width of the component.|
| height | [Length](#length) | No   | Height of the component.|


## BorderOptions

The **BorderOptions** type is used to provide border information.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type                                      | Mandatory  | Description     |
| ------ | ---------------------------------------- | ---- | ------- |
| width  | [Length](#length)  \| [EdgeWidths](#edgewidths9)<sup>9+</sup> | No   | Border width.  |
| color  | [ResourceColor](#resourcecolor) \| [EdgeColors](#edgecolors9)<sup>9+</sup> | No   | Border color.  |
| radius | [Length](#length) \| [BorderRadiuses](#borderradiuses9)<sup>9+</sup> | No   | Radius of the rounded corner border.|
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)  \| [EdgeStyles](#EdgeStyles9)<sup>9+</sup>| No   | Border style.  |

## ColorFilter<sup>9+</sup>

The **ColorFilter** type is used to create a color filter with a 4 x 5 matrix.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name         | Type      | Mandatory  | Description                                      |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | Yes   | Constructor for creating a color filter with a 4 x 5 matrix. The input parameter is [m*n], which is the matrix value in row m and column n. The matrix is row-first.|


## CustomBuilder<sup>8+</sup>

The **CustomBuilder** type is used to define custom UI descriptions in component attribute methods.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | () =&gt; any \| void | Builder for creating a custom component; must be used with @Builder. For details, see [@Builder](../../../quick-start/arkts-builder.md).|

## PixelStretchEffectOptions<sup>10+</sup>

The **PixelStretchEffectOptions** type is used to describe the pixel stretch effect options.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type               | Mandatory  | Description            |
| ------ | ----------------- | ---- | -------------- |
| left   | [Length](#length) | No   | Length by which a pixel is stretched towards the left edge of the image.|
| right  | [Length](#length) | No   | Length by which a pixel is stretched towards the right edge of the image.|
| top    | [Length](#length) | No   | Length by which a pixel is stretched towards the top edge of the image.|
| bottom | [Length](#length) | No   | Length by which a pixel is stretched towards the bottom edge of the image.|

## ModalTransition<sup>10+</sup>

The **ModalTransition** type is used to set the transition type for a full-screen modal.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name     | Description          |
| ------- | ------------ |
| NONE    | No transition animation for the modal.  |
| DEFAULT | Slide-up and slide-down animation for the modal. |
| ALPHA   | Opacity gradient animation for the modal.|

## Dimension<sup>10+</sup>

The **Length** type is used to represent a size unit.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| [PX](#px10)               | Physical pixel unit type. The unit px must be included, for example, **'10px'**.|
| [VP](#vp10)                | Pixel unit type specific to the screen density. The unit vp can be included or omitted, for example, **10** or **'10vp'**.|
| [FP](#fp10)                | Font pixel unit type. The unit fp must be included, for example, **'10fp'**.|
| [LPX](#lpx10)              | Logical pixel unit type. The unit lpx must be included, for example, **'10lpx'**.|
| [Percentage](#percentage10)        | Percentage type. The unit % must be included, for example, **'10%'**.|
| [Resource](#resource) | Size referenced from system or application resources.|

## PX<sup>10+</sup>

The **PX** type is used to represent a length in px.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}px               | Physical pixel unit type. The unit px must be included, for example, **'10px'**.|

## VP<sup>10+</sup>

The **VP** type is used to represent a length in vp.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}vp\|number | Pixel unit type specific to the screen density. The unit vp can be included or omitted, for example, **10** or **'10vp'**.|

## FP<sup>10+</sup>

The **FP** type is used to represent a length in fp.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}fp               | Font pixel unit type. The unit fp must be included, for example, **'10fp'**.|

## LPX<sup>10+</sup>

The **LPX** type is used to represent a length in lpx.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}lpx               | Logical pixel unit type. The unit lpx must be included, for example, **'10lpx'**.|

## Percentage<sup>10+</sup>

The **Percentage** type is used to represent a length in percentage.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}%               | Percentage type. The unit % must be included, for example, **'10%'**.|

## Degree<sup>10+</sup>

The **Degree** type is used to represent a length in deg.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}deg               | Degree type. The unit deg must be included, for example, **'10deg'**.|

## MultiShadowOptions<sup>10+</sup>

The **MultiShadowOptions** type is used to describe the shadow style.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name         | Type| Mandatory| Description|
| ------------- | ------- | ---- | -------- |
| radius | number \| [Resource](#resource) | No| Shadow blur radius.<br>The default value varies by API version.<br>API version 10 and earlier versions: **5**<br>Since API version 11: **20**<br>Unit: vp<br>**NOTE**<br>A value less than or equal to 0 is handled as the default value.|
| offsetX | number \| [Resource](#resource) | No| Offset on the x-axis.<br>Default value: **5**<br>Unit: vp|
| offsetY | number \| [Resource](#resource) | No| Offset on the y-axis.<br>Default value: **5**<br>Unit: vp|

## SwiperAnimationEvent<sup>10+</sup>

Describes the animation information of the \<Swiper> component.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name           | Type      | Mandatory           | Description                                      |
| ------------- | ---------------------- | ---------|------------------------------- |
| currentOffset | number | Yes| Offset of the currently displayed element relative to the start position of the **\<Swiper>** along the main axis. Unit: vp<br>Default value: **0**|
| targetOffset | number | Yes| Offset of the target element relative to the start position of the **\<Swiper>** along the main axis. Unit: vp<br>Default value: **0**|
| velocity | number | Yes| Hands-off velocity at the beginning of the animation. Unit: VP/S<br>Default value: **0**|

## TabsAnimationEvent<sup>11+</sup>

The **TabsAnimationEvent** type is used to describe the animation information of the **\<Tabs>** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name           | Type     |  Mandatory            | Description                                      |
| ------------- | ---------------------- | ----------------|------------------------ |
| currentOffset | number | Yes| Offset of the currently displayed element relative to the start position of the **\<Tabs>** along the main axis. Unit: vp<br>Default value: **0**|
| targetOffset | number | Yes| Offset of the target element relative to the start position of the **\<Tabs>** along the main axis. Unit: vp<br>Default value: **0**|
| velocity | number | Yes| Hands-off velocity at the beginning of the animation. Unit: VP/S<br>Default value: **0**|

## SafeAreaType<sup>10+</sup>

The **SafeAreaType** type is used to describe the types of expanded safe areas.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Description                                      |
| -------- | ------------------------------------------ |
| SYSTEM   | Default non-safe area of the system, including the status bar and navigation bar.  |
| CUTOUT   | Non-safe area of the device, for example, the notch area.|
| KEYBOARD | Soft keyboard area.                              |

## SafeAreaEdge<sup>10+</sup>

The **SafeAreaEdge** type is used to define the edge for expanding the safe area.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Description      |
| ------ | ---------- |
| TOP    | Top edge.|
| BOTTOM | Bottom edge.|
| START  | Start edge.|
| END    | End edge.|

## KeyboardAvoidMode<sup>11+</sup>

The **KeyboardAvoidMode** type is used to define the avoidance mode for the virtual keyboard.

| Name  | Description      |
| ------ | ---------- |
| OFFSET | Avoid the virtual keyboard through offset.|
| RESIZE | Avoid the virtual keyboard through resizing.|

## TouchPoint<sup>11+</sup>

The **TouchPoint** type is used to define the coordinates of the touch point.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Description      |
| ------ | ----------------------| ---------- |
| X | [Dimension](#dimension10) | X coordinate of the touch point.|
| Y | [Dimension](#dimension10) | Y coordinate of the touch point.|

## TabContentAnimatedTransition<sup>11+</sup>

The **TabContentAnimatedTransition** type is used to define the custom tab switching animation.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name           | Type        | Mandatory         | Description                                      |
| ------------- | ---------------------- | ------------------|---------------------- |
| timeout | number | No| Timeout for the custom tab switching animation. If the set timeout period expires before the **finishTransition** API of [TabContentTransitionProxy](#tabcontenttransitionproxy11) is called, the **\<Tabs>** component considers that the custom animation has ended and performs subsequent operations.<br> Unit: ms<br>Default value: **1000**|
| transition | (proxy: [TabContentTransitionProxy](#tabcontenttransitionproxy11)) => void | Yes| Content of the custom tab switching animation.|

## TabContentTransitionProxy<sup>11+</sup>

Proxy object returned during the execution of the custom tab switching animation. You can use this object to obtain the start and target pages for the custom tab switching animation. In addition, you can call the **finishTransition** API of this object to notify the **\<Tabs>** component of the ending of the custom animation.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name           | Type    |  Mandatory             | Description                                      |
| ------------- | ---------------------- | ----------------------|------------------ |
| from | number | Yes| Index of the currently displayed tab before the animation starts.|
| to | number | Yes| Index of the target tab to switch to.|
| finishTransition() | void | Yes| Called to notify the **\<Tabs>** component that the custom animation ends.|

## PixelRoundPolicy<sup>11+</sup>

The **PixelRoundPolicy** type is used to describe the rounding strategy for component pixel-level alignment.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| start | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) | No| Rounding for alignment with the start edge.|
| top | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) | No| Rounding for alignment with the top edge.|
| end | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) | No| Rounding for alignment with the end edge.|
| bottom | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) | No| Rounding for alignment with the bottom edge.|

## VoidCallback<sup>12+</sup>

The **VoidCallback** type is used to represent the callback: **() => void**.

## Callback<sup>12+</sup>

Callback<T,V = void> = (T) => V;

The **Callback** type is used to represent the callback with parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

## HoverCallback<sup>12+</sup>

The **HoverCallback** type is used to represent the callback for the hover event.

HoverCallback = (isHover: boolean, event: [HoverEvent](./ts-universal-mouse-key.md#hoverevent10)) => void

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| HoverCallback | (isHover: boolean, event: [HoverEvent](./ts-universal-mouse-key.md#hoverevent10)) => void | Callback for the hover event.|

## StyledStringValue<sup>12+</sup>

The **StyledStringValue** type is used to set the style for an attribute string.

| Name  | Description      |
| ------ | ---------- |
| TextStyle | Text style.|
| DecorationStyle | Text decorative line style.|
| BaselineOffsetStyle | Text baseline offset style.|
| LetterSpacingStyle | Text letter spacing style.|
| LineHeightStyle | Text line height style.|
| TextShadowStyle | Text shadow style.|
| GestureStyle | Gesture style.|
| ParagraphStyle | Text paragraph style.|
| ImageAttachment | Image style.|
| CustomSpan | Custom span style.|

## SubmitEvent<sup>11+</sup>

The **SubmitEvent** type is used to define the user submission event.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name             | Type      | Mandatory| Description                                              |
| ----------------- | ---------- | ---- | -------------------------------------------------- |
| keepEditableState | () => void | No  | Editing status of the text box.<br> When this API is called, the text box remains in editing state.|
| text              | string     | No  | Text in the text box.                                  |

## EnterKeyType

| Name                  | Description              |
| ---------------------- | ------------------ |
| Go                     | The Enter key is labeled "Go."<br>**Atomic service API**: This API can be used in atomic services since API version 11.  |
| Search                 | The Enter key is labeled "Search."<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| Send                   | The Enter key is labeled "Send."<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| Next                   | The Enter key is labeled "Next."<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Done                   | The Enter key is labeled "Done."<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| PREVIOUS<sup>11+</sup> | The Enter key is labeled "Previous."<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| NEW_LINE<sup>11+</sup> | The Enter key is labeled "Return."<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## LengthMetrics<sup>12+</sup>

The **LengthMetrics** type is used to describe the metrics of length.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Attributes**

| Name             | Type      | Mandatory| Description                         |
| ----------------- | ---------- | ---- | ----------------------------- |
| value       | number | Yes| Value of the length attribute.  |
| unit | [LengthUnit](#lengthunit12)     | Yes| Unit of the length attribute.|

## LengthUnit<sup>12+</sup>

Enumerates length units.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| [PX](#px10) | 0 | The **PX** type is used to represent a length in px.|
| [VP](#vp10) | 1 | The **VP** type is used to represent a length in vp.|
| [FP](#fp10) | 2 | The **FP** type is used to represent a length in fp.|
| [PERCENT](#percentage10) | 3 | The **Percentage** type is used to represent a length in percentage.|
| [LPX](#lpx10) | 4 | The **LPX** type is used to represent a length in lpx.|
