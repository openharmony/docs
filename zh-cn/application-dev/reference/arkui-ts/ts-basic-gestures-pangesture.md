# PanGesture

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 接口

PanGesture(options?: { fingers?: number, direction?: PanDirection, distance?: number } | [PanGestureOptions](#pangestureoptions))

- 参数
  | 参数名称 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | 否 | 1 | 触发滑动的最少手指数，最小为1指，&nbsp;最大取值为10指。 |
  | direction | PanDirection | 否 | All | 设置滑动方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。 |
  | distance | number | 否 | 5.0 | 最小滑动识别距离，单位为vp。 |

- PanDirection枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | All | 所有方向可滑动。 | 
  | Horizontal | 水平方向可滑动。 | 
  | Vertical | 竖直方向可滑动。 | 
  | Left | 向左滑动。 | 
  | Right | 向右滑动。 | 
  | Up | 向上滑动。 | 
  | Down | 向下滑动。 | 
  | None | 任何方向都不可滑动。 | 


### PanGestureOptions

通过PanGestureOptions对象接口可以动态修改滑动手势识别器的属性，从而避免通过状态变量修改属性（状态变量修改会导致UI刷新）。

PanGestureOptions(options?: { fingers?: number, direction?: PanDirection, distance?: number })

- 参数
  同PanGesture参数说明。

- 接口
  | 名称 | 功能描述 | 
  | -------- | -------- |
  | setDirection(value:&nbsp;PanDirection) | 设置direction属性。 | 
  | setDistance(value:&nbsp;number) | 设置distance属性。 | 
  | setFingers(value:&nbsp;number) | 设置fingers属性。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- | 
| onActionStart(callback:&nbsp;(event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Pan手势识别成功回调。 | 
| onActionUpdate(callback:&nbsp;(event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Pan手势移动过程中回调。 | 
| onActionEnd(callback:&nbsp;(event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Pan手势识别成功，手指抬起后触发回调。 | 
| onActionCancel(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Pan手势识别成功，接收到触摸取消事件触发回调。 | 

- GestureEvent对象中与Pan手势相关的属性
  | 属性名称 | 属性类型 | 描述 | 
  | -------- | -------- | -------- |
  | offsetX | number | 手势事件偏移量，单位为vp。 | 
  | offsetY | number | 手势事件偏移量，单位为vp。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0
  @State offsetY: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .gesture(
      PanGesture({})
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.offsetX = event.offsetX
          this.offsetY = event.offsetY
        })
        .onActionEnd(() => {
          console.info('Pan end')
        })
    )
  }
}
```

![zh-cn_image_0000001174264374](figures/zh-cn_image_0000001174264374.gif)
