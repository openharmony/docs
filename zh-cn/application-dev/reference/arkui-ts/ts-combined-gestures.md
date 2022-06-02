# 组合手势

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 接口

GestureGroup(mode: GestureMode, ...gesture: GestureType[])

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | mode | GestureMode                                                  | 是 | - | 设置组合手势识别模式。 |
  | gesture | [TapGesture](ts-basic-gestures-tapgesture.md)<br/>\|&nbsp;[LongPressGesture](ts-basic-gestures-longpressgesture.md)<br/>\|&nbsp;[PanGesture](ts-basic-gestures-pangesture.md)<br/>\|&nbsp;[PinchGesture](ts-basic-gestures-pinchgesture.md)<br/>\|&nbsp;[RotationGesture](ts-basic-gestures-rotationgesture.md) | 是 | - | 可变长参数，1个或者多个基础手势类型，这些手势会被组合识别。 |

- GestureMode枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | Sequence | 顺序识别，按照手势的注册顺序识别手势，直到所有手势识别成功。当有一个手势识别失败时，所有手势识别失败。 | 
  | Parallel | 并发识别，注册的手势同时识别，直到所有手势识别结束，手势识别互相不影响。 | 
  | Exclusive | 互斥识别，注册的手势同时识别，若有一个手势识别成功，则结束手势识别。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 顺序组合手势（GestureMode.Sequence）取消后触发回调。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct GestureGroupExample {
  @State count: number = 0
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State borderStyle: BorderStyle = BorderStyle.Solid

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }.translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .height(100).width(200).padding(10).margin(80).border({ width: 1, style: this.borderStyle })
    .gesture(
      GestureGroup(GestureMode.Sequence,
        LongPressGesture({ repeat: true })
          .onAction((event: GestureEvent) => {
            if (event.repeat) {this.count++}
            console.log('LongPress onAction')
          })
          .onActionEnd(() => {
            console.log('LongPress end')
          }),
        PanGesture({})
          .onActionStart(() => {
            this.borderStyle = BorderStyle.Dashed
            console.log('pan start')
          })
          .onActionUpdate((event: GestureEvent) => {
            this.offsetX = event.offsetX
            this.offsetY = event.offsetY
            console.log('pan update')
          })
      )
      .onCancel(() => {
        console.log('sequence gesture canceled')
      })
    )
  }
}
```

![zh-cn_image_0000001174104384](figures/zh-cn_image_0000001174104384.gif)
