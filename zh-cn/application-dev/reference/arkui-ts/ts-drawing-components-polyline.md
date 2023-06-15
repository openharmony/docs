# Polyline

折线绘制组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Polyline(value?: {width?: string | number, height?: string | number})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | 否 | 0 | 宽度。<br/>**说明：** <br/>异常值按照默认值处理。 |
| height | string \| number | 否 | 0 | 高度。<br/>**说明：** <br/>异常值按照默认值处理。 |



## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| points | Array&lt;Point&gt; | [] | 折线经过坐标点列表。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |
| fill | [ResourceColor](ts-types.md) | Color.Black | 设置填充区域颜色。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |
| fillOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource类型) | 1 | 设置填充区域透明度。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |
| stroke | [ResourceColor](ts-types.md) | - | 设置边框颜色，不设置时，默认没有边框线条。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值不会绘制边框线条。 |
| strokeDashArray | Array&lt;Length&gt; | [] | 设置线条间隙。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |
| strokeDashOffset | number&nbsp;\|&nbsp;string | 0 | 线条绘制起点的偏移量。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | 设置线条端点绘制样式。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | 设置线条拐角绘制样式。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| strokeMiterLimit | number&nbsp;\|&nbsp;string | 4 | 设置斜接长度与边框宽度比值的极限值。斜接长度表示外边框外边交点到内边交点的距离，边框宽度即strokeWidth属性的值。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>该属性取值需在strokeLineJoin属性取值LineJoinStyle.Miter时生效。 <br/>该属性的合法值范围应当大于等于1.0，当取值范围在[0,1)时按1.0处理，其余异常值按默认值处理。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| strokeOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource类型) | 1 | 设置线条透明度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>该属性的取值范围是[0.0, 1.0]，若给定值小于0.0，则取值为0.0；若给定值大于1.0，则取值为1.0，其余异常值按1.0处理 。 |
| strokeWidth | Length | 1 | 设置线条宽度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>该属性若为string类型, 暂不支持百分比。<br/>异常值按照默认值处理。 |
| antiAlias | boolean | true | 是否开启抗锯齿效果。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>异常值按照默认值处理。 |



## Point

点坐标类型。

<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称      | 类型定义             | 描述                                                         |
| --------- | -------------------- | ------------------------------------------------------------ |
| Point | [number,&nbsp;number] | 第一个参数为x轴坐标，第二个参数为y轴坐标（相对坐标）。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct PolylineExample {
  build() {
    Column({ space: 10 }) {
      // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(20,60)，到达终点(100, 100)
      Polyline({ width: 100, height: 100 })
        .points([[0, 0], [20, 60], [100, 100]])
        .fillOpacity(0)
        .stroke(Color.Blue)
        .strokeWidth(3)
      // 在 100 * 100 的矩形框中绘制一段折线，起点(20, 0)，经过(0,100)，到达终点(100, 90)
      Polyline()
        .width(100)
        .height(100)
        .fillOpacity(0)
        .stroke(Color.Red)
        .strokeWidth(8)
        .points([[20, 0], [0, 100], [100, 90]])
          // 设置折线拐角处为圆弧
        .strokeLineJoin(LineJoinStyle.Round)
          // 设置折线两端为半圆
        .strokeLineCap(LineCapStyle.Round)
    }.width('100%')
  }
}
```

![zh-cn_image_0000001219744185](figures/zh-cn_image_0000001219744185.png)
