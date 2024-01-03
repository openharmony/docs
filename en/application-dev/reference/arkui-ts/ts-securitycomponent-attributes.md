# Security Component Universal Attributes


Universal attributes of security components are basic attributes applicable to all security components.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| iconSize | [Dimension](ts-types.md#dimension10) | No| Icon size of the security component.<br>Default value: **16vp**|
| layoutDirection | [SecurityComponentLayoutDirection](#securitycomponentlayoutdirection) | No| Direction of the icon and text on the security component.<br>Default value: **SecurityComponentLayoutDirection.HORIZONTAL**|
| position | [Position](ts-types.md#position8) | No| Absolute position of the security component, that is, the offset of the component's upper left corner relative to its parent container's.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>} |
| markAnchor | [Position](ts-types.md#position8) | No| Anchor of the security component for moving the component with its upper left corner as the reference point. Generally, this attribute is used together with the **position** and **offset** attributes. When used alone, it produces an effect similar to that produced by **offset**.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>} |
| offset | [Position](ts-types.md#position8) | No| Relative position of the security component, that is, the offset of the component relative to itself.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>} |
| fontSize | [Dimension](ts-types.md#dimension10) | No| Font size of the text on the security component.<br>Default value: **16fp**|
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | No| Font style of the text on the security component.<br>Default value: **FontStyle.Normal**|
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | No| Font weight of the text on the security component.<br>Default value: **FontWeight.Medium**|
| fontFamily | string \| [Resource](ts-types.md#resource) | No| Font family of the text on the security component.<br>Default font: **'HarmonyOS Sans'**|
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | No| Font color of the text on the security component.<br>Default value: **'\#ffffffff'**|
| iconColor | [ResourceColor](ts-types.md#resourcecolor) | No| Color of the icon on the security component.<br>Default value: **'\#ffffffff'**|
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | No| Background color of the security component.<br>Default value: **\#007dff**|
| borderStyle | [BorderStyle](ts-appendix-enums.md#borderstyle) | No| Border style of the security component.<br>By default, the border style is not set.|
| borderWidth | [Dimension](ts-types.md#dimension10) | No| Border width of the security component.<br>By default, the border width is not set.|
| borderColor | [ResourceColor](ts-types.md#resourcecolor) | No| Border color of the security component.<br>By default, the border color is not set.|
| borderRadius | [Dimension](ts-types.md#dimension10) | No| Radius of the rounded border corners of the security component.|
| padding | [Padding](ts-types.md#padding) \| [Dimension](ts-types.md#dimension10) | No| Padding of the security component.<br>Default value: 12 vp for the top and bottom paddings and 24 vp for the left and right paddings|
| textIconSpace | [Dimension](ts-types.md#dimension10) | No| Space between the icon and text on the security component.<br>Default value: **4vp**|
| width<sup>11+</sup> | [Length](ts-types.md#length) | No| Width of the security component. By default, the security component automatically adapts its width to the content. If the value is less than the minimum width allowed by the current attribute combination, the actual width will be greater than the set value to ensure that content of the security component is fully displayed.|
| height<sup>11+</sup> | [Length](ts-types.md#length) | No| Height of the security component. By default, the security component automatically adapts its height to the content. If the value is less than the minimum height allowed by the current attribute combination, the actual height will be greater than the set value to ensure that content of the security component is fully displayed.|
| size<sup>11+</sup> | {<br>width?: [Length](ts-types.md#length),<br>height?: [Length](ts-types.md#length)<br>} | No| Size of the security component. By default, the security component automatically adapts its size to the content. If the value is less than the minimum size allowed by the current attribute combination, the actual size will be greater than the set value to ensure that content of the security component is fully displayed.|
| constraintSize<sup>11+</sup> | {<br>minWidth?: [Length](ts-types.md#length),<br>maxWidth?: [Length](ts-types.md#length),<br>minHeight?: [Length](ts-types.md#length),<br>maxHeight?: [Length](ts-types.md#length)<br>} | No| Size constraint of the security component. Its priority is higher than that of **Width** and **Height**. Learn [how the value of this attribute affects the width and height](ts-universal-attributes-size.md#impact-of-constraintsize-on-widthheight).<br> As with width and height, the actual size cannot be less than the minimum size allowed by the current attribute combination, so as to ensure that content of the security component is fully displayed.<br>Default value:<br>{<br>minWidth: 0,<br>maxWidth: Infinity,<br>minHeight: 0,<br>maxHeight: Infinity<br>} |


## SecurityComponentLayoutDirection

| Name| Description|
| -------- | -------- |
| HORIZONTAL | The icon and text on security component are horizontally arranged.|
| VERTICAL | The icon and text on security component are vertically arranged.|


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
