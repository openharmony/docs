# PinchGesture

用于触发捏合手势，触发捏合手势的最少手指为2指，最大为5指，最小识别距离为3vp。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

PinchGesture(value?: { fingers?: number, distance?: number })

**参数：**

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| fingers | number | 否 | 触发捏合的最少手指数,&nbsp;最小为2指，最大为5指。<br/>默认值：2 |
| distance | number | 否 | 最小识别距离，单位为vp。<br/>默认值：3.0 |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onActionStart(event: (event?: [GestureEvent](ts-gesture-settings.md))&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功回调。 |
| onActionUpdate(event: (event?: [GestureEvent](ts-gesture-settings.md))&nbsp;=&gt;&nbsp;void) | Pinch手势移动过程中回调。 |
| onActionEnd(event: (event?: [GestureEvent](ts-gesture-settings.md))&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功，手指抬起后触发回调。 |
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功，接收到触摸取消事件触发回调。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct PinchGestureExample {
  @State scaleValue: number = 1

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PinchGesture scale:' + this.scale)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .scale({ x: this.scaleValue, y: this.scaleValue, z: this.scaleValue })
    .gesture(
      PinchGesture()
        .onActionStart((event: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.scaleValue = event.scale
        })
        .onActionEnd(() => {
          console.info('Pinch end')
        })
    )
  }
}
```

![zh-cn_image_0000001174582848](figures/zh-cn_image_0000001174582848.gif)
