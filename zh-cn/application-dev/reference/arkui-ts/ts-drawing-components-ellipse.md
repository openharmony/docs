# Ellipse

椭圆绘制组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Ellipse(options?: {width?: string | number, height?: string | number})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数:**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| width | string \| number | 否 | 宽度。<br/>默认值：0<br/>**说明：**<br/>异常值按照默认值处理。 |
| height | string \| number | 否 | 高度。<br/>默认值：0<br/>**说明：**<br/>异常值按照默认值处理。 |



## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| fill | [ResourceColor](ts-types.md) | Color.Black | 设置填充区域颜色。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>异常值按照默认值处理。 |
| fillOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource类型) | 1 | 设置填充区域透明度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>异常值按照默认值处理。 |
| stroke | [ResourceColor](ts-types.md) | - |设置边框颜色，不设置时，默认没有边框。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>异常值不会绘制边框。 |
| strokeDashArray | Array&lt;Length&gt; | [] | 设置边框间隙。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>异常值按照默认值处理。 |
| strokeDashOffset | number&nbsp;\|&nbsp;string | 0 | 边框绘制起点的偏移量。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>异常值按照默认值处理。 |
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | 设置边框端点绘制样式。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | 设置边框拐角绘制样式。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>Ellipse组件无法形成拐角，该属性设置无效。 |
| strokeMiterLimit | number&nbsp;\|&nbsp;string | 4 | 设置斜接长度与边框宽度比值的极限值。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>Ellipse组件无法设置尖角图形，该属性设置无效。 |
| strokeOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource类型) | 1 | 设置边框透明度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>该属性的取值范围是[0.0, 1.0]，若给定值小于0.0，则取值为0.0；若给定值大于1.0，则取值为1.0，其余异常值按1.0处理 。 |
| strokeWidth | Length | 1 | 设置边框宽度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>该属性若为string类型, 暂不支持百分比。<br/>异常值按照默认值处理。 |
| antiAlias | boolean | true | 是否开启抗锯齿效果。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |



## 示例

```ts
// xxx.ets
@Entry
@Component
struct EllipseExample {
  build() {
    Column({ space: 10 }) {
      // 绘制一个 150 * 80 的椭圆
      Ellipse({ width: 150, height: 80 })
      // 绘制一个 150 * 100 、线条为蓝色的椭圆环
      Ellipse()
        .width(150)
        .height(100)
        .fillOpacity(0)
        .stroke(Color.Blue)
        .strokeWidth(3)
    }.width('100%')
  }
}
```

![zh-cn_image_0000001174104394](figures/zh-cn_image_0000001174104394.png)
