# 外描边设置

设置组件外描边样式。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性

| 名称         | 参数类型                                                     | 描述                                                         |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| outline       | {<br/>width?:&nbsp;[Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[EdgeOutlineWidths](#edgeoutlinewidths对象说明),<br/>color?:&nbsp;[ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](#edgecolors对象说明),<br/>radius?:&nbsp;[Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[OutlineRadiuses](#outlineradiuses对象说明),<br/>style?:&nbsp;[OutlineStyle](ts-appendix-enums.md#outlinestyle11)&nbsp;\|&nbsp;[EdgeOutlineStyles](#edgeoutlinestyles对象说明)<br/>} | 统一外描边样式设置接口。<br/>-&nbsp;width：设置外描边宽度。<br/>默认值：0，外描边效果width为必设项，否则不显示外描边。<br/>-&nbsp;color：设置外描边颜色。<br/>默认值：Color.Black。<br/>-&nbsp;radius：设置外描边圆角半径。<br/>默认值：0。<br/>最大生效值：组件width/2 + outlineWidth或组件height/2 + outlineWidth。<br/>-&nbsp;style：设置外描边样式。<br/>默认值：OutlineStyle.SOLID。<br/>从API version 11开始，该接口支持在ArkTS卡片中使用。|
| outlineStyle  | [OutlineStyle](ts-appendix-enums.md#outlinestyle11) \| [EdgeOutlineStyles](#edgeoutlinestyles对象说明) | 设置元素的外描边样式。<br/>默认值：OutlineStyle.SOLID <br/>从API version 11开始，该接口支持在ArkTS卡片中使用。|
| outlineWidth  | [Dimension](ts-types.md#dimension10) \| [EdgeOutlineWidths](#edgeoutlinewidths对象说明) | 设置元素的外描边宽度，不支持百分比。 <br/>默认值：0，外描边效果width为必设项。<br/>从API version 11开始，该接口支持在ArkTS卡片中使用。|
| outlineColor  | [ResourceColor](ts-types.md#resourcecolor) \| [EdgeColors](#edgecolors对象说明) | 设置元素的外描边颜色。<br/>默认值：Color.Black。 <br/>从API version 11开始，该接口支持在ArkTS卡片中使用。|
| outlineRadius | [Dimension](ts-types.md#dimension10) \| [OutlineRadiuses](#outlineradiuses对象说明) | 设置元素的外描边圆角半径，不支持百分比。<br/>默认值：0。<br/>最大生效值：组件width/2 + outlineWidth或组件height/2 + outlineWidth。<br/>从API version 11开始，该接口支持在ArkTS卡片中使用。|

## EdgeOutlineWidths对象说明

引入该对象时，至少传入一个参数。

| 名称     | 参数类型                         | 必填   | 描述      |
| ------ | ---------------------------- | ---- | ------- |
| left   | [Dimension](ts-types.md#dimension10) | 否    | 左侧外描边宽度。 |
| right  | [Dimension](ts-types.md#dimension10) | 否    | 右侧外描边宽度。 |
| top    | [Dimension](ts-types.md#dimension10) | 否    | 上侧外描边宽度。 |
| bottom | [Dimension](ts-types.md#dimension10) | 否    | 下侧外描边宽度。 |

## EdgeColors对象说明

引入该对象时，至少传入一个参数。

| 名称     | 参数类型                                     | 必填   | 描述      |
| ------ | ---------------------------------------- | ---- | ------- |
| left   | [ResourceColor](ts-types.md#resourcecolor) | 否    | 左侧外描边颜色。 |
| right  | [ResourceColor](ts-types.md#resourcecolor) | 否    | 右侧外描边颜色。 |
| top    | [ResourceColor](ts-types.md#resourcecolor) | 否    | 上侧外描边颜色。 |
| bottom | [ResourceColor](ts-types.md#resourcecolor) | 否    | 下侧外描边颜色。 |

## OutlineRadiuses对象说明

引用该对象时，至少传入一个参数。

| 名称          | 参数类型                         | 必填   | 描述       |
| ----------- | ---------------------------- | ---- | -------- |
| topLeft     | [Dimension](ts-types.md#dimension10) | 否    | 左上角圆角半径。 |
| topRight    | [Dimension](ts-types.md#dimension10) | 否    | 右上角圆角半径。 |
| bottomLeft  | [Dimension](ts-types.md#dimension10) | 否    | 左下角圆角半径。 |
| bottomRight | [Dimension](ts-types.md#dimension10) | 否    | 右下角圆角半径。 |

## EdgeOutlineStyles对象说明

引入该对象时，至少传入一个参数。

| 名称     | 参数类型                                     | 必填   | 描述      |
| ------ | ---------------------------------------- | ---- | ------- |
| left   | [OutlineStyle](ts-appendix-enums.md#outlinestyle11) | 否    | 左侧外描边样式。 |
| right  | [OutlineStyle](ts-appendix-enums.md#outlinestyle11) | 否    | 右侧外描边样式。 |
| top    | [OutlineStyle](ts-appendix-enums.md#outlinestyle11) | 否    | 上侧外描边样式。 |
| bottom | [OutlineStyle](ts-appendix-enums.md#outlinestyle11) | 否    | 下侧外描边样式。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct OutlineExample {
  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
        // 线段
        Text('DASHED')
          .outlineStyle(OutlineStyle.DASHED).outlineWidth(5).outlineColor(0xAFEEEE).outlineRadius(10)
          .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
        // 点线
        Text('DOTTED')
          .outline({ width: 5, color: 0x317AF7, radius: 10, style: OutlineStyle.DOTTED })
          .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      }.width('100%').height(150)

      Text('.outline')
        .fontSize(50)
        .width(300)
        .height(300)
        .outline({
          width: { left: 3, right: 6, top: 10, bottom: 15 },
          color: { left: '#e3bbbb', right: Color.Blue, top: Color.Red, bottom: Color.Green },
          radius: { topLeft: 10, topRight: 20, bottomLeft: 40, bottomRight: 80 },
          style: {
            left: OutlineStyle.DOTTED,
            right: OutlineStyle.DOTTED,
            top: OutlineStyle.SOLID,
            bottom: OutlineStyle.DASHED
          }
        }).textAlign(TextAlign.Center)
    }
  }
}
```

![zh-cn_image_0000001219982706](figures/zh-cn_image_0000001219982706.png)
