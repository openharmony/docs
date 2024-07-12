# Security Component Universal Attributes


Universal attributes of security components are basic attributes applicable to all security components.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## iconSize

iconSize(value: Dimension)

Sets the icon size of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) | No|Icon size of the security component.<br>Default value: **16vp**|

## layoutDirection

layoutDirection(value: SecurityComponentLayoutDirection)

Sets the direction of the icon and text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [SecurityComponentLayoutDirection](#securitycomponentlayoutdirection) |No| Direction of the icon and text on the security component.<br>Default value: **SecurityComponentLayoutDirection.HORIZONTAL**|

## position

position(value: Position)

Sets the absolute position of the security component, that is, the offset of the component's upper left corner relative to its parent container's.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) |No|Offset of the security component's upper left corner relative to its parent container's.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

## markAnchor

markAnchor(value: Position)

Sets the anchor of the security component for moving the component with its upper left corner as the reference point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) |No|Anchor of the security component for moving the component with its upper left corner as the reference point. Generally, this attribute is used together with the **position** and **offset** attributes. When used alone, it produces an effect similar to that produced by **offset**.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

## offset

offset(value: Position | Edges | LocalizedEdges)

Sets the coordinate offset of the security control relative to its own layout position.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) \| [Edges<sup>12+</sup>](ts-types.md#edges12) \| [LocalizedEdges<sup>12+</sup>](ts-types.md#localizededges12) |No|Coordinate offset of the security control relative to its own layout position. This attribute does not affect the layout in the parent container. The offset is used only during drawing.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

## fontSize

fontSize(value: Dimension)

Sets the font size of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |No|Font size of the text on the security component.<br>Default value: **16fp**|

## fontStyle

fontStyle(value: FontStyle)

Font style of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [FontStyle](ts-appendix-enums.md#fontstyle) |No|Font style of the text on the security component.<br>Default value: **FontStyle.Normal**|

## fontWeight

fontWeight(value: number | FontWeight | string)

Sets the font weight of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string |No|Font weight of the text on the security component.<br>Default value: **FontWeight.Medium**|

## fontFamily

fontFamily(value: string | Resource)

Sets the font family of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | string \| [Resource](ts-types.md#resource) |No|Font family of the text on the security component.<br>Default font: **'HarmonyOS Sans'**|

## fontColor

fontColor(value: ResourceColor)

Sets the font color of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |No|Font color of the text on the security component.<br>Default value: **'\#ffffffff'**|

## iconColor

iconColor(value: ResourceColor)

Sets the color of the icon on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |No|Color of the icon on the security component.<br>Default value: **'\#ffffffff'**|

## backgroundColor

backgroundColor(value: ResourceColor)

Sets the background color of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |No|Background color of the security component.<br>Default value: **\#007dff**|

## borderStyle

borderStyle(value: BorderStyle)

Sets the border style of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [BorderStyle](ts-appendix-enums.md#borderstyle) |No|Border style of the security component.<br>By default, the border style is not set.|

## borderWidth

borderWidth(value: Dimension)

Sets the border width of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |No|Border width of the security component.<br>By default, the border width is not set.|

## borderColor

borderColor(value: ResourceColor)

Sets the border color of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |No|Border color of the security component.<br>By default, the border color is not set.|

## borderRadius

borderRadius(value: Dimension)

Sets the radius of the rounded border corners of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value |  [Dimension](ts-types.md#dimension10) |No|Radius of the rounded border corners of the security component.|

## padding

padding(value: Padding | Dimension)

Sets the padding of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Padding](ts-types.md#padding) \| [Dimension](ts-types.md#dimension10) |No|Padding of the security component.<br>Default value: 12 vp for the top and bottom paddings and 24 vp for the left and right paddings|

## textIconSpace

textIconSpace(value: Dimension)

Sets the space between the icon and text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |No|Space between the icon and text on the security component.<br>Default value: **4vp**|

## width<sup>11+</sup>

width(value: Length)

Sets the width of the security component. By default, the security component automatically adapts its width to the content.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
|value | [Length](ts-types.md#length) |No|Width of the security component. By default, the security component automatically adapts its width to the content. If the value is less than the minimum width allowed by the current attribute combination, the actual width will be greater than the set value to ensure that content of the security component is fully displayed.|

## height<sup>11+</sup>

height(value: Length)

Sets the height of the security component. By default, the security component automatically adapts its height to the content.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Length](ts-types.md#length) |No|Height of the security component. By default, the security component automatically adapts its height to the content. If the value is less than the minimum height allowed by the current attribute combination, the actual height will be greater than the set value to ensure that content of the security component is fully displayed.|

## size<sup>11+</sup>

size(value: SizeOptions)

Sets the size of the security component. By default, the security component automatically adapts its size to the content.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [SizeOptions](ts-types.md#sizeoptions) |No|Size of the security component. By default, the security component automatically adapts its size to the content. If the value is less than the minimum size allowed by the current attribute combination, the actual size will be greater than the set value to ensure that content of the security component is fully displayed.|

## constraintSize<sup>11+</sup>

constraintSize(value: ConstraintSizeOptions)

Sets the size constraints of the component during component layout.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) |No|Size constraints of the component during component layout. **constraintSize** takes precedence over **width** and **height**. Learn [how the value of this attribute affects the width and height](ts-universal-attributes-size.md).<br> As with width and height, the actual size cannot be less than the minimum size allowed by the current attribute combination, so as to ensure that content of the security component is fully displayed.<br>Default value:<br>{<br>minWidth: 0,<br>maxWidth: Infinity,<br>minHeight: 0,<br>maxHeight: Infinity<br>}|


## SecurityComponentLayoutDirection

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| HORIZONTAL | 0 | The icon and text on security component are horizontally arranged.|
| VERTICAL | 1 | The icon and text on security component are vertically arranged.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column({space:5}) {
        // Generate a save button and set its security component attributes.
        SaveButton()
          .fontSize(35)
          .fontColor(Color.White)
          .iconSize(30)
          .layoutDirection(SecurityComponentLayoutDirection.HORIZONTAL)
          .borderWidth(1)
          .borderStyle(BorderStyle.Dashed)
          .borderColor(Color.Blue)
          .borderRadius(20)
          .fontWeight(100)
          .iconColor(Color.White)
          .padding({left:50, top:50, bottom:50, right:50})
          .textIconSpace(20)
          .backgroundColor(0x3282f6)
        SaveButton().size({width:200, height:100})
        SaveButton().constraintSize({maxWidth:60})
      }.width('100%')
    }.height('100%')
  }
}
```

![en-us_image_0000001643038221](figures/en-us_image_0000001643038221.png)
