# RotationGesture

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 接口

RotationGesture(options?: { fingers?: number, angle?: number })

- 参数
  | 参数名称 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | 否 | 2 | 触发旋转的最少手指数,&nbsp;最小为2指，最大为5指。 | 
  | angle | number | 否 | 1.0 | 触发旋转手势的最小改变度数，单位为度数。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onActionStart((event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Rotation手势识别成功回调。 | 
| onActionUpdate((event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Rotation手势移动过程中回调。 | 
| onActionEnd((event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Rotation手势识别成功，手指抬起后触发回调。 | 
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Rotation手势识别成功，接收到触摸取消事件触发回调。 | 

- GestureEvent对象中与Rotation手势相关的属性
  | 属性名称 | 属性类型 | 描述 | 
  | -------- | -------- | -------- |
  | angle | number | 旋转角度。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct RotationGestureExample {
  @State angle: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('RotationGesture angle:' + this.angle)
    }
    .height(100).width(200).padding(20).border({ width:1 })
    .margin(80).rotate({ x:1, y:2, z:3, angle: this.angle })
    .gesture(
      RotationGesture()
        .onActionStart((event: GestureEvent) => {
          console.log('Rotation start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.angle = event.angle
        })
        .onActionEnd(() => {
          console.log('Rotation end')
        })
    )
  }
}
```

![zh-cn_image_0000001174264372](figures/zh-cn_image_0000001174264372.gif)
