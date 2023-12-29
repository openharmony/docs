# Types

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Resource

The **Resource** type is used to reference resources for setting component attributes.

You can use `$r` or `$rawfile` to create a **Resource** object, but its attribute values cannot be changed.

- `$r('belonging.type.name')`

  **belonging**: group to which the resource belongs, which can be **'sys'** or **'app'**.

  **type**: resource type, which can be '**boolean'**, **'color'**, **'float'**, **'intarray'**, **'integer'**, **'pattern'**, '**plural'**, **'strarray'**, **'string'**, or **'media'**.

  **name**: resource name, which is determined during resource definition.

- `$rawfile('filename')`

  **filename**: name of the file in the **resources/rawfile** directory of the project.

  > **NOTE**
  >
  > When referencing resources of the **Resource** type, make sure the data type is the same as that of the attribute method. For example, if an attribute method supports the **string | Resource** types, the data type of the **Resource** type must be string.

## Length

The **Length** type is used to represent a size unit.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| string                | String type. Specify the length unit explicitly, for example, **'10px'**, or provide the length in percentage, for example, **'100%'**.|
| number                | Number type. The default unit is vp.                               |
| [Resource](#resource) | Size referenced from system or application resources.              |

## ResourceStr

The **ResourceStr** type is used to represent the types that can be used by input parameters of the string type.

| Type                   | Description                       |
| --------------------- | ------------------------- |
| string                | String type.                   |
| [Resource](#resource) | String referenced from system or application resources.|

## Padding

The **Padding** type is used to describe the paddings in different directions of a component.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | No   | Height of the padding on the top of the component. |
| right  | [Length](#length) | No   | Width of the padding on the right of the component.|
| bottom | [Length](#length) | No   | Height of the padding at the bottom of the component. |
| left   | [Length](#length) | No   | Width of the padding on the left of the component.|

## Margin

The **Margin** type is used to describe the margins in different directions of a component.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | No   | Height of the margin above the component. |
| right  | [Length](#length) | No   | Width of the margin on the right of the component.|
| bottom | [Length](#length) | No   | Height of the margin below the component. |
| left   | [Length](#length) | No   | Width of the margin on the left of the component.|

## EdgeWidths<sup>9+</sup>

The **EdgeWidths** type is used to describe the edge widths in different directions of a component.

| Name    | Type               | Mandatory  | Description      |
| ------ | ----------------- | ---- | -------- |
| top    | [Length](#length) | No   | Width of the top edge of the component.|
| right  | [Length](#length) | No   | Width of the right edge of the component.|
| bottom | [Length](#length) | No   | Width of the bottom edge of the component.|
| left   | [Length](#length) | No   | Width of the left edge of the component.|

## BorderRadiuses<sup>9+</sup>

The **BorderRadiuses** type is used to describe the radius of the rounded corners of a component.

| Name         | Type               | Mandatory  | Description        |
| ----------- | ----------------- | ---- | ---------- |
| topLeft     | [Length](#length) | No   | Radius of the top left rounded corner of the component.|
| topRight    | [Length](#length) | No   | Radius of the top right rounded corner of the component.|
| bottomLeft  | [Length](#length) | No   | Radius of the bottom left rounded corner of the component.|
| bottomRight | [Length](#length) | No   | Radius of the bottom right rounded corner of the component.|

## EdgeColors<sup>9+</sup>

The **EdgeColors** type is used to describe the edge colors of a component.

| Name    | Type                             | Mandatory  | Description      |
| ------ | ------------------------------- | ---- | -------- |
| top    | [ResourceColor](#resourcecolor) | No   | Color of the top edge of the component.|
| right  | [ResourceColor](#resourcecolor) | No   | Color of the right edge of the component.|
| bottom | [ResourceColor](#resourcecolor) | No   | Color of the bottom edge of the component.|
| left   | [ResourceColor](#resourcecolor) | No   | Color of the left edge of the component.|

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

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| [Color](ts-appendix-enums.md#color) | Color enums.                                  |
| number                              | Color in hexadecimal notation. RGB is supported. Example: **0xffffff**              |
| string                              | Color in RGB or ARGB notation. Example: **'#ffffff', '#ff000000', 'rgb(255, 100, 255)', 'rgba(255, 100, 255, 0.5)'**|
| [Resource](#resource)               | Color referenced from system or application resources.             |

## ColoringStrategy<sup>10+</sup>

The **ColoringStrategy** type is used to describe the foreground and shadow colors.

| Name    | Description             |
| ------ | --------------- |
| INVERT | The foreground colors are the inverse of the component background colors.|
| AVERAGE| The shadow colors of the component are the average color obtained from the component background shadow area.|
| PRIMARY| The shadow colors of the component are the primary color obtained from the component background shadow area.|

## LengthConstrain

The **LengthConstrain** type is used to describe the maximum and minimum lengths of a component.

| Name       | Type               | Mandatory  | Description     |
| --------- | ----------------- | ---- | ------- |
| minLength | [Length](#length) | Yes   | Minimum length of the component.|
| maxLength | [Length](#length) | Yes   | Maximum length of the component.|


## Font

The **Font** type is used to set the text style.

| Name    | Type                                      | Mandatory  | Description                                      |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Length](#length)                        | No   | Font size. If the value is of the number type, the unit fp is used. The value cannot be a percentage.<br>Default value: **16.0** |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | No   | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a thicker font.<br>Default value: **400** \| **FontWeight.Normal** |
| family | string \| [Resource](#resource)          | No   | Font family of the text. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is **'Arial, HarmonyOS Sans'**. The HarmonyOS Sans font and [register custom fonts](../apis/js-apis-font.md) are supported.|
| style  | [FontStyle](ts-appendix-enums.md#fontstyle) | No   | Font style.<br>Default value: **FontStyle.Normal**                              |

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

| Name  | Type               | Mandatory  | Description                         |
| ---- | ----------------- | ---- | --------------------------- |
| x    | [Length](#length) | No   | X coordinate. The value is of the number type in vp when used as the return value.|
| y    | [Length](#length) | No   | Y coordinate. The value is of the number type in vp when used as the return value.|

## ConstraintSizeOptions

The **ConstraintSizeOptions** type is used to set the size constraints of a component during component layout.

| Name       | Type               | Mandatory  | Description     |
| --------- | ----------------- | ---- | ------- |
| minWidth  | [Length](#length) | No   | Minimum width of the component.|
| maxWidth  | [Length](#length) | No   | Maximum width of the component.|
| minHeight | [Length](#length) | No   | Minimum height of the component.|
| maxHeight | [Length](#length) | No   | Maximum height of the component.|

## SizeOptions

The **SizeOptions** type is used to set the width and height.

| Name    | Type               | Mandatory  | Description   |
| ------ | ----------------- | ---- | ----- |
| width  | [Length](#length) | No   | Width of the component.|
| height | [Length](#length) | No   | Height of the component.|


## BorderOptions

The **BorderOptions** type is used to provide border information.

| Name    | Type                                      | Mandatory  | Description     |
| ------ | ---------------------------------------- | ---- | ------- |
| width  | [Length](#length)  \| [EdgeWidths](#edgewidths9)<sup>9+</sup> | No   | Border width.  |
| color  | [ResourceColor](#resourcecolor) \| [EdgeColors](#edgecolors9)<sup>9+</sup> | No   | Border color.  |
| radius | [Length](#length) \| [BorderRadiuses](#borderradiuses9)<sup>9+</sup> | No   | Radius of the rounded corner border.|
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)  \| [EdgeStyles](#EdgeStyles9)<sup>9+</sup>| No   | Border style.  |

## ColorFilter<sup>9+</sup>

The **ColorFilter** type is used to create a color filter with a 4 x 5 matrix.

| Name         | Type      | Mandatory  | Description                                      |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | Yes   | Constructor for creating a color filter with a 4 x 5 matrix. The input parameter is [m*n], which is the matrix value in row m and column n. The matrix is row-first.|


## CustomBuilder<sup>8+</sup>

The **CustomBuilder** type is used to define custom UI descriptions in component attribute methods.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | () =&gt; any | Builder for creating a custom component; must be used with @Builder. For details, see [@Builder](../../quick-start/arkts-builder.md#builder).|

## PixelStretchEffectOptions<sup>10+</sup>

The **PixelStretchEffectOptions** type is used to describe the pixel stretch effect options.

| Name    | Type               | Mandatory  | Description            |
| ------ | ----------------- | ---- | -------------- |
| left   | [Length](#length) | No   | Length by which a pixel is stretched towards the left edge of the image.|
| right  | [Length](#length) | No   | Length by which a pixel is stretched towards the right edge of the image.|
| top    | [Length](#length) | No   | Length by which a pixel is stretched towards the top edge of the image.|
| bottom | [Length](#length) | No   | Length by which a pixel is stretched towards the bottom edge of the image.|

## ModalTransition<sup>10+</sup>

The **ModalTransition** type is used to set the transition type for a full-screen modal.

| Name     | Description          |
| ------- | ------------ |
| NONE    | No transition animation for the modal.  |
| DEFAULT | Slide-up and slide-down animation for the modal. |
| ALPHA   | Opacity gradient animation for the modal.|

## Dimension<sup>10+</sup>

The **Length** type is used to represent a size unit.

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

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}px               | Physical pixel unit type. The unit px must be included, for example, **'10px'**.|

## VP<sup>10+</sup>

The **VP** type is used to represent a length in vp.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}vp\|number | Pixel unit type specific to the screen density. The unit vp can be included or omitted, for example, **10** or **'10vp'**.|

## FP<sup>10+</sup>

The **FP** type is used to represent a length in fp.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}fp               | Font pixel unit type. The unit fp must be included, for example, **'10fp'**.|

## LPX<sup>10+</sup>

The **LPX** type is used to represent a length in lpx.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}lpx               | Logical pixel unit type. The unit lpx must be included, for example, **'10lpx'**.|

## Percentage<sup>10+</sup>

The **Percentage** type is used to represent a length in percentage.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}%               | Percentage type. The unit % must be included, for example, **'10%'**.|

## Degree<sup>10+</sup>

The **Degree** type is used to represent a length in deg.

| Type                   | Description                                    |
| --------------------- | -------------------------------------- |
| {number}deg               | Degree type. The unit deg must be included, for example, **'10deg'**.|

## SwiperAnimationEvent<sup>10+</sup>

Describes the animation information of the \<Swiper> component.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| currentOffset | number | Offset of the currently displayed element relative to the start position of the **\<Swiper>** along the main axis. Unit: vp<br>Default value: **0**|
| targetOffset | number | Offset of the target element relative to the start position of the **\<Swiper>** along the main axis. Unit: vp<br>Default value: **0**|
| velocity | number | Hands-off velocity at the beginning of the animation. Unit: VP/S<br>Default value: **0**|

## TabsAnimationEvent<sup>11+</sup>

The **TabsAnimationEvent** type is used to describe the animation information of the **\<Tabs>** component.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| currentOffset | number | Offset of the currently displayed element relative to the start position of the **\<Tabs>** along the main axis. Unit: vp<br>Default value: **0**|
| targetOffset | number | Offset of the target element relative to the start position of the **\<Tabs>** along the main axis. Unit: vp<br>Default value: **0**|
| velocity | number | Hands-off velocity at the beginning of the animation. Unit: vp/s<br>Default value: **0**|

## SafeAreaType<sup>10+</sup>

The **SafeAreaType** type is used to describe the types of expanded safe areas.

| Name    | Description                                      |
| -------- | ------------------------------------------ |
| SYSTEM   | Default non-safe area of the system, including the status bar and navigation bar.  |
| CUTOUT   | Non-safe area of the device, for example, the notch area.|
| KEYBOARD | Soft keyboard area.                              |

## SafeAreaEdge<sup>10+</sup>

The **SafeAreaEdge** type is used to define the edge for expanding the safe area.

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

| Name  | Description      |
| ------ | ---------- |
| X | X coordinate of the touch point.|
| Y | Y coordinate of the touch point.|

## TabContentAnimatedTransition<sup>11+</sup>

The **TabContentAnimatedTransition** type is used to define the custom tab switching animation.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| timeout | number | Timeout for the custom tab switching animation. If the set timeout period expires before the **finishTransition** API of [TabContentTransitionProxy](#tabcontenttransitionproxy11) is called, the **\<Tabs>** component considers that the custom animation has ended and performs subsequent operations. Unit:ms<br>Default value: **1000**|
| transition | (proxy: [TabContentTransitionProxy](#tabcontenttransitionproxy11)) => void | Content of the custom tab switching animation.|

## TabContentTransitionProxy<sup>11+</sup>

Proxy object returned during the execution of the custom tab switching animation. You can use this object to obtain the start and target pages for the custom tab switching animation. In addition, you can call the **finishTransition** API of this object to notify the **\<Tabs>**component of the ending of the custom animation.

| Name           | Type                  | Description                                      |
| ------------- | ---------------------- | ---------------------------------------- |
| from | number | Index of the currently displayed tab before the animation starts.|
| to | number | Index of the target tab to switch to.|
| finishTransition() | void | Called to notify the **\<Tabs>** component that the custom animation ends.|
