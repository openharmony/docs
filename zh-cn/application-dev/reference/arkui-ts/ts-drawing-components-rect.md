# Rect

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


矩形绘制组件。


## 权限列表

无


## 子组件

无


## 接口

Rect(options?: {width?: string | number,height?: string | number,radius?: string | number | Array&lt;string | number&gt;} |
  {width?: string | number,height?: string | number,radiusWidth?: string | number,radiusHeight?: string | number})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | string&nbsp;\|&nbsp;number | 否 | 0 | 宽度。 | 
  | height | string&nbsp;\|&nbsp;number | 否 | 0 | 高度。 | 
  | radius | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Array&lt;string&nbsp;\|&nbsp;number&gt; | 否 | 0 | 圆角半径，支持分别设置四个角的圆角度数。 | 
  | radiusWidth | string&nbsp;\|&nbsp;number | 否 | 0 | 圆角宽度。 | 
  | radiusHeight | string&nbsp;\|&nbsp;number | 否 | 0 | 圆角高度。 | 


## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 参数名称 | 参数类型 | 默认值 | 必填 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| radiusWidth | string&nbsp;\|&nbsp;number | 0 | 否 | 圆角的宽度，仅设置宽时宽高一致。 | 
| radiusHeight | string&nbsp;\|&nbsp;number | 0 | 否 | 圆角的高度，仅设置高时宽高一致。 | 
| radius | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Array&lt;string&nbsp;\|&nbsp;number&gt; | 0 | 否 | 圆角半径大小。 |
| fill | [ResourceColor](../../ui/ts-types.md) | Color.Black | 否 | 设置填充区域颜色。 |
| fillOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 1 | 否 | 设置填充区域透明度。 |
| stroke | [ResourceColor](../../ui/ts-types.md) | Color.Black | 否 | 设置线条颜色。 |
| strokeDashArray | Array&lt;Length&gt; | [] | 否 | 设置线条间隙。 |
| strokeDashOffset | number&nbsp;\|&nbsp;string | 0 | 否 | 线条绘制起点的偏移量。 |
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | 否 | 设置线条端点绘制样式。 |
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | 否 | 设置线条拐角绘制样式。 |
| strokeMiterLimit | number&nbsp;\|&nbsp;string | 4 | 否 | 设置锐角绘制成斜角的极限值。 |
| strokeOpacity | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 1 | 否 | 设置线条透明度。 |
| strokeWidth | Length | 1 | 否 | 设置线条宽度。 |
| antiAlias | boolean | true | 否 | 是否开启抗锯齿效果。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct RectExample {
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 绘制90% * 50矩形
      Rect({ width: '90%', height: 50 })
      // 绘制90% * 50矩形
      Rect().width('90%').height(50)

      Text('with rounded corners').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 绘制90% * 50矩形, 圆角宽高20
      Rect({ width: '90%', height: 50 }).radiusHeight(20).radiusWidth(20)
      // 绘制90% * 50矩形, 圆角宽高20
      Rect({ width: '90%', height: 50 }).radius(20)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264386](figures/zh-cn_image_0000001174264386.png)
