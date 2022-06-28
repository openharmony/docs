# 边框设置

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。<br>
> 从API Version 9开始，父节点的border显示在子节点内容之上。


设置组件边框样式。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| border | {<br/>width?:&nbsp;Length,<br/>color?:&nbsp;Color,<br/>radius?:&nbsp;Length,<br/>style?:&nbsp;BorderStyle<br/>} | - | 统一边框样式设置接口。 |
| borderStyle | BorderStyle | &nbsp;BorderStyle.Solid | 设置元素的边框样式。 |
| borderWidth | Length | 0 | 设置元素的边框宽度。 |
| borderColor | Color | - | 设置元素的边框颜色。 |
| borderRadius | Length | 0 | 设置元素的边框圆角半径。 |


- BorderStyle枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | Dotted | 显示为一系列圆点，圆点半径为borderWidth的一半。 | 
  | Dashed | 显示为一系列短的方形虚线。 | 
  | Solid | 显示为一条实线。 | 


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
