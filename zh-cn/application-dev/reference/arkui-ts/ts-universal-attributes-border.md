# 边框设置

设置组件边框样式。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| border | {<br/>width?:&nbsp;[Length](ts-types.md#length),<br/>color?:&nbsp;[ResourceColor](ts-types.md#resourcecolor),<br/>radius?:&nbsp;[Length](ts-types.md#length),<br/>style?:&nbsp;[BorderStyle](ts-appendix-enums.md#borderstyle)<br/>} | 统一边框样式设置接口。 |
| borderStyle | [BorderStyle](ts-appendix-enums.md#borderstyle) | 设置元素的边框样式。<br/>默认值：BorderStyle.Solid |
| borderWidth | [Length](ts-types.md#length) | 设置元素的边框宽度。 |
| borderColor | [ResourceColor](ts-types.md#resourcecolor) | 设置元素的边框颜色。 |
| borderRadius | [Length](ts-types.md#length) | 设置元素的边框圆角半径。 |



## 示例

```ts
// xxx.ets
@Entry
@Component
struct BorderExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
      // 线段
      Text('dashed')
        .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      // 点线
      Text('dotted')
        .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
    }.width('100%').height(150)
  }
}
```

![zh-cn_image_0000001219982705](figures/zh-cn_image_0000001219982705.gif)
