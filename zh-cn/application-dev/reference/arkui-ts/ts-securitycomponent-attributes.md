# 安全控件通用属性


安全控件的基础属性，用于设置安全控件通用的属性。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性

| 名称 | 参数类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| iconSize | [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件上图标的尺寸。<br/>默认值：16vp |
| layoutDirection | [SecurityComponentLayoutDirection](#securitycomponentlayoutdirection枚举说明) | 否 | 设置安全控件上图标和文字分布的方向。<br/>默认值：SecurityComponentLayoutDirection.HORIZONTAL |
| position | [Position](ts-types.md#position8) | 否 | 设置绝对定位，设置安全控件的左上角相对于父容器左上角的偏移位置。<br/>默认值：<br/>{<br/>x: 0,<br/>y: 0<br/>} |
| markAnchor | [Position](ts-types.md#position8) | 否 | 设置安全控件在位置定位时的锚点，以控件左上角作为基准点进行偏移。通常配合position和offset属性使用，单独使用时，效果类似offset<br/>默认值：<br/>{<br/>x: 0,<br/>y: 0<br/>} |
| offset | [Position](ts-types.md#position8) | 否 | 设置安全控件相对于自身布局位置的坐标偏移。设置此属性不会影响父容器的布局，仅在绘制过程中调整位置。<br/>默认值：<br/>{<br/>x: 0,<br/>y: 0<br/>} |
| fontSize | [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件上文字的尺寸。<br/>默认值：16fp |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 否 | 设置安全控件上文字的样式。<br/>默认值：FontStyle.Normal |
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | 否 | 设置安全控件上文字粗细。<br/>默认值：FontWeight.Medium |
| fontFamily | string \| [Resource](ts-types.md#resource) | 否 | 设置安全控件上文字的字体。<br/>默认字体：'HarmonyOS Sans' |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置安全控件上文字的颜色。<br/>默认值：\#ffffffff |
| iconColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置安全控件上图标的颜色。<br/>默认值：\#ffffffff |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置安全控件的背景颜色。<br/>默认值：\#007dff |
| borderStyle | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否 | 设置安全控件的边框的样式。<br/>默认不设置边框样式 |
| borderWidth | [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件的边框的宽度。<br/>默认不设置边框宽度 |
| borderColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置安全控件的边框的颜色。<br/>默认不设置边框颜色 |
| borderRadius | [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件的边框圆角半径。|
| padding | [Padding](ts-types.md#padding) \| [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件的内边距。<br/>默认值：上下12vp, 左右24vp |
| textIconSpace | [Dimension](ts-types.md#dimension10) | 否 | 设置安全控件中图标和文字的间距。<br/>默认值：4vp |


## SecurityComponentLayoutDirection枚举说明

| 名称 | 枚举值 | 描述 |
| -------- | -------- | -------- |
| HORIZONTAL | 0 | 安全控件上图标和文字分布的方向为水平排列。 |
| VERTICAL | 1 | 安全控件上图标和文字分布的方向为垂直排列。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        // 生成一个保存按钮，并设置它的SecurityComponent属性
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
      }.width('100%')
    }.height('100%')
  }
}
```

![zh-cn_image_0000001643038221](figures/zh-cn_image_0000001643038221.png)
