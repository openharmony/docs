# Security Component Universal Attributes


Universal attributes of security components are basic attributes applicable to all security components.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## iconSize

iconSize(value: Dimension): T

Sets the icon size of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) | Yes|Icon size of the security component.<br>Default value: **16vp**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## layoutDirection

layoutDirection(value: SecurityComponentLayoutDirection): T

Sets the direction of the icon and text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description                  |
|------------|------|-------|---------|
| value | [SecurityComponentLayoutDirection](#securitycomponentlayoutdirection) |Yes| Direction of the icon and text on the security component.<br>Default value: **SecurityComponentLayoutDirection.HORIZONTAL**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## position

position(value: Position): T

Sets the absolute position of the security component, that is, the offset of the component's upper left corner relative to its parent container's.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) |Yes|Offset of the security component's upper left corner relative to its parent container's.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## markAnchor

markAnchor(value: Position): T

Sets the anchor of the security component for moving the component with its upper left corner as the reference point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) |Yes|Anchor of the security component for moving the component with its upper left corner as the reference point. Generally, this attribute is used together with the **position** and **offset** attributes. When used alone, it produces an effect similar to that produced by **offset**.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## offset

offset(value: Position | Edges | LocalizedEdges): T

Sets the coordinate offset of the security control relative to its own layout position.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Position](ts-types.md#position) \| [Edges<sup>12+</sup>](ts-types.md#edges12) \| [LocalizedEdges<sup>12+</sup>](ts-types.md#localizededges12) |Yes|Coordinate offset of the security control relative to its own layout position. This attribute does not affect the layout in the parent container. The offset is used only during drawing.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>}|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## fontSize

fontSize(value: Dimension): T

Sets the font size of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |Yes|Font size of the text on the security component.<br>Default value: **16fp**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## fontStyle

fontStyle(value: FontStyle): T

Font style of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [FontStyle](ts-appendix-enums.md#fontstyle) |Yes|Font style of the text on the security component.<br>Default value: **FontStyle.Normal**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## fontWeight

fontWeight(value: number | FontWeight | string): T

Sets the font weight of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string |Yes|Font weight of the text on the security component.<br>Default value: **FontWeight.Medium**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## fontFamily

fontFamily(value: string | Resource): T

Sets the font family of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | string \| [Resource](ts-types.md#resource) |Yes|Font family of the text on the security component.<br>Default font: **'HarmonyOS Sans'**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## fontColor

fontColor(value: ResourceColor): T

Sets the font color of the text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |Yes|Font color of the text on the security component.<br>Default value: **'\#ffffffff'**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## iconColor

iconColor(value: ResourceColor): T

Sets the color of the icon on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |Yes|Color of the icon on the security component.<br>Default value: **'\#ffffffff'**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## backgroundColor

backgroundColor(value: ResourceColor): T

Sets the background color of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |Yes|Background color of the security component.<br>Default value: **\#007dff**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## borderStyle

borderStyle(value: BorderStyle): T

Sets the border style of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [BorderStyle](ts-appendix-enums.md#borderstyle) |Yes|Border style of the security component.<br>By default, the border style is not set.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## borderWidth

borderWidth(value: Dimension): T

Sets the border width of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |Yes|Border width of the security component.<br>By default, the border width is not set.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## borderColor

borderColor(value: ResourceColor): T

Sets the border color of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ResourceColor](ts-types.md#resourcecolor) |Yes|Border color of the security component.<br>By default, the border color is not set.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## borderRadius

borderRadius(value: Dimension): T

Sets the radius of the rounded border corners of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value |  [Dimension](ts-types.md#dimension10) |Yes|Radius of the rounded border corners of the security component.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## padding

padding(value: Padding | Dimension): T

Sets the padding of the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Padding](ts-types.md#padding) \| [Dimension](ts-types.md#dimension10) |Yes|Padding of the security component.<br>Default value: 8 vp for the top and bottom paddings and 16 vp for the left and right paddings|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## textIconSpace

textIconSpace(value: Dimension): T

Sets the space between the icon and text on the security component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Dimension](ts-types.md#dimension10) |Yes|Space between the icon and text on the security component.<br>Default value: **4vp**|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## width<sup>11+</sup>

width(value: Length): T

Sets the width of the security component. By default, the security component automatically adapts its width to the content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
|value | [Length](ts-types.md#length) |Yes|Width of the security component. By default, the security component automatically adapts its width to the content. If the set width is less than the minimum width allowed by the current combination of attributes, the width will be adjusted to the set value, and the button text will automatically wrap to maintain the complete display of the security component.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## height<sup>11+</sup>

height(value: Length): T

Sets the height of the security component. By default, the security component automatically adapts its height to the content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [Length](ts-types.md#length) |Yes|Height of the security component. By default, the security component automatically adapts its height to the content. If the value is less than the minimum height allowed by the current attribute combination, the actual height will be greater than the set value to ensure that content of the security component is fully displayed.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## size<sup>11+</sup>

size(value: SizeOptions): T

Sets the size of the security component. By default, the security component automatically adapts its size to the content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [SizeOptions](ts-types.md#sizeoptions) |Yes|Size of the security component. By default, the security component automatically adapts its size to the content. If the set size is less than the minimum size allowed by the current combination of attributes, the width will be adjusted to the set value while the height will not, and the button text will automatically wrap to ensure the integrity of the display for the security control.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|

## constraintSize<sup>11+</sup>

constraintSize(value: ConstraintSizeOptions): T

Sets the size constraints of the component during component layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| value | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) |Yes|Size constraints of the component during component layout. **constraintSize** takes precedence over **width** and **height**. Learn [how the value of this attribute affects the width and height](ts-universal-attributes-size.md).<br>As with width and height, if the set size is less than the minimum size allowed by the current combination of attributes, the width will be adjusted to the set value while the height will not, and the button text will automatically wrap to ensure the integrity of the display for the security control.<br>Default value:<br>{<br>minWidth: 0,<br>maxWidth: Infinity,<br>minHeight: 0,<br>maxHeight: Infinity<br>}|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Attributes of the security component.|


## SecurityComponentLayoutDirection

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| HORIZONTAL | 0 | The icon and text on the security component are horizontally arranged.|
| VERTICAL | 1 | The icon and text on the security component are vertically arranged.|


## Example

> **NOTE**
> You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

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
