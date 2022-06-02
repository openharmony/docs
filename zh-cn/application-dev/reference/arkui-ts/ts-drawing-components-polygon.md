# Polygon

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


多边形绘制组件。


## 权限列表

无


## 子组件

无


## 接口

Polygon(value:{options?: {width: Length, height: Length}})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | 否 | - | 见options参数说明。 |

- options参数说明
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | 是 | - | 宽度。 | 
  | height | Length | 是 | - | 高度。 | 


## 属性

| 参数名称 | 参数类型 | 默认值 | 必填 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | 否 | 多边形所在矩形的宽度。 | 
| height | Length | 0 | 否 | 多边形所在矩形的高度。 | 
| points | Array&lt;Point&gt; | - | 是 | 多边形的顶点坐标列表。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct PolygonExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // 在 100 * 100 的矩形框中绘制一个三角形，起点(0, 0)，经过(50, 100)，终点(100, 0)
        Polygon({ width: 100, height: 100 }).points([[0, 0], [50, 100], [100, 0]])
        // 在 100 * 100 的矩形框中绘制一个四边形，起点(0, 0)，经过(0, 100)和(100, 100)，终点(100, 0)
        Polygon().width(100).height(100).points([[0, 0], [0, 100], [100, 100], [100, 0]])
        // 在 100 * 100 的矩形框中绘制一个五边形，起点(50, 0)，依次经过(0, 50)、(20, 100)和(80, 100)，终点(100, 50)
        Polygon().width(100).height(100).points([[50, 0], [0, 50], [20, 100], [80, 100], [100, 50]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174582856](figures/zh-cn_image_0000001174582856.gif)
