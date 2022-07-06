# 位置设置

设置组件的对齐方式、布局方向和显示位置。

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| align | [Alignment](ts-appendix-enums.md#alignment枚举说明) | Center | 设置元素内容的对齐方式，只有当设置的width和height大小超过元素本身内容大小时生效。 |
| direction | Direction | Auto | 设置元素水平方向的布局，可选值参照Direction枚举说明。 |
| position | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | - | 使用绝对定位，设置元素锚点相对于父容器顶部起点偏移位置。在布局容器中，设置该属性不影响父容器布局，仅在绘制时进行位置调整。 |
| markAnchor | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | 设置元素在位置定位时的锚点，以元素顶部起点作为基准点进行偏移。 |
| offset | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | 相对布局完成位置坐标偏移量，设置该属性，不影响父容器布局，仅在绘制时进行位置调整。 |


- Direction枚举说明
  | 名称 | 描述 |
  | -------- | -------- |
  | Ltr | 元素从左到右布局。 |
  | Rtl | 元素从右到左布局。 |
  | Auto | 使用系统默认布局方向。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct PositionExample {
  build() {
    Column() {
      Column({space: 10}) {
        Text('align').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Text('top start')
          .align(Alignment.TopStart)
          .height(50)
          .width('90%')
          .fontSize(16)
          .backgroundColor(0xFFE4C4)

        Text('direction').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Text('1').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('2').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
          Text('3').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('4').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .direction(Direction.Rtl)
      }
    }
    .width('100%').margin({ top: 5 }).direction(Direction.Rtl)
  }
}
```

![zh-cn_image_0000001174264368](figures/zh-cn_image_0000001174264368.gif)

```ts
// xxx.ets
@Entry
@Component
struct PositionExample2 {
  build() {
    Column({ space: 20 }) {
      Text('position').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row({ space: 20 }) {
        Text('1').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }) .fontSize(16)
        Text('2 position(25, 15)')
          .size({ width: '60%', height: '30' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .position({ x: 25, y: 15 })
        Text('3').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4 position(50%, 70%)')
          .size({ width: '50%', height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .position({ x: '50%', y: '70%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })

      Text('markAnchor').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Stack({ alignContent: Alignment.TopStart }) {
        Row()
          .size({ width: '100', height: '100' })
          .backgroundColor(0xdeb887)
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
          .position({ x: '100%', y: '100%' })
      }.margin({ top: 25 }).border({ width: 1, style: BorderStyle.Dashed })

      Text('offset').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row() {
        Text('1').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('2\noffset(15, 15)')
          .size({ width: 120, height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .offset({ x: 15, y: 15 })
        Text('3').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4\noffset(-10%, 20%)')
          .size({ width: 150, height: '50' }) .backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .offset({ x: '-10%', y: '20%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })
    }
    .width('100%').margin({ top: 25 })
  }
}
```

![zh-cn_image_0000001174104392](figures/zh-cn_image_0000001174104392.gif)
