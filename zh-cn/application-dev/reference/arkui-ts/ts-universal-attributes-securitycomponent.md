# 安全组件通用

安全组件的基础属性，用于设置安全组件通用的属性。

> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 属性

| 名称              | 参数类型                                     | 必填   | 描述                                       |
| --------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| iconSize        | [Length](ts-types.md#length)             | 否    | 设置安全组件上图标的尺寸。<br/> 默认值：16vp              |
| layoutDirection | [SecurityComponentLayoutDirection](#securitycomponentlayoutdirection枚举说明) | 否    | 设置安全组件上图标和文字分布的方向。 <br/> 默认值：SecurityComponentLayoutDirection.HORIZONTAL |
| layoutOrder     | [SecurityComponentLayoutOrder](#securitycomponentlayoutorder枚举说明) | 否    | 设置安全组件上图标和文字分布的顺序。 <br/> 默认值：SecurityComponentLayoutOrder.ICON_FIRST |
| position        | [Position](ts-types.md#position8)        | 否    | 设置绝对定位，设置安全组件的左上角相对于父容器左上角的偏移位置。<br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>} |
| markAnchor      | [Position](ts-types.md#position8)        | 否    | 设置绝对定位的锚点，以安全组件的左上角作为基准点进行偏移。<br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>} |
| offset          | [Position](ts-types.md#position8)        | 否    | 设置相对定位，安全组件相对于自身的偏移量。<br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>} |
| fontSize        | [Length](ts-types.md#length)             | 否    | 设置安全组件上文字的尺寸。<br/> 默认值：16fp              |
| fontStyle       | [FontStyle](ts-appendix-enums.md#fontstyle) | 否    | 设置安全组件上文字的样式。<br/> 默认值：FontStyle.Normal  |
| fontWeight      | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | 否    | 设置安全组件上文字粗细。 <br/> 默认值：FontWeight.Medium |
| fontFamily      | string \| [Resource](ts-types.md#resource类型) | 否    | 设置安全组件上文字的字体。 <br/>默认字体：'HarmonyOS Sans' |
| fontColor       | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置安全组件上文字的颜色。<br/> 默认值：#ffffffff         |
| iconColor       | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置安全组件上图标的颜色。<br/> 默认值：#ffffffff         |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置安全组件的背景颜色。 <br/> 默认值：#007dff           |
| borderStyle     | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 设置安全组件的边框的样式。  <br/> 默认不设置边框样式           |
| borderWidth     | [Length](ts-types.md#length)             | 否    | 设置安全组件的边框的宽度。 <br/> 默认不设置边框宽度            |
| borderColor     | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置安全组件的边框的颜色。 <br/> 默认不设置边框颜色            |
| borderRadius    | [Length](ts-types.md#length)             | 否    | 设置安全组件的边框圆角半径。<br/> 默认值：1/2 按钮整高         |
| padding         | [Padding](ts-types.md#padding) \| [Length](ts-types.md#length) | 否    | 设置安全组件的内边距。 <br/> 默认值：上下8vp, 左右24vp      |
| textIconSpace   | [Length](ts-types.md#length)             | 否    | 设置安全组件中图标和文字的间距。  <br/> 默认值：4vp          |

## SecurityComponentLayoutDirection枚举说明

| 名称         | 描述                    |
| ---------- | --------------------- |
| HORIZONTAL | 安全组件上图标和文字分布的方向为水平排列。 |
| VERTICAL   | 安全组件上图标和文字分布的方向为垂直排列。 |

## SecurityComponentLayoutOrder枚举说明

| 名称         | 描述           |
| ---------- | ------------ |
| ICON_FIRST | 图标的排列顺序先于文字。 |
| TEXT_FIRST | 文字的排列顺序先于图标。 |

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
        SecSaveButton()
          .fontSize(35)
          .fontColor(Color.White)
          .iconSize(30)
          .layoutDirection(SecurityComponentLayoutDirection.HORIZONTAL)
          .layoutOrder(SecurityComponentLayoutOrder.TEXT_FIRST)
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

![securitycomponent1](figures/securitycomponent1.png)
