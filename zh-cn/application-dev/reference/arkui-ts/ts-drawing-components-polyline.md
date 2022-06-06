# Polyline

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


折线绘制组件。


## 权限列表

无


## 子组件

无


## 接口

Polyline(options?: {width: Length, height: Length})

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
| width | Length | 0 | 否 | 折线所在矩形的宽度。 | 
| height | Length | 0 | 否 | 折线所在矩形的高度。 | 
| points | Array&lt;Point&gt; | - | 是 | 折线经过坐标点列表。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct PolylineExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(20,60)，到达终点(100, 100)
        Polyline({ width: 100, height: 100 }).points([[0, 0], [20, 60], [100, 100]])
        // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(0,100)，到达终点(100, 100)
        Polyline().width(100).height(100).points([[0, 0], [0, 100], [100, 100]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001219744185](figures/zh-cn_image_0000001219744185.gif)
