# SwipeGesture

用于触发滑动事件，滑动最小速度为100vp/s时识别成功。

>  **说明：**
>
>  从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

**参数：**

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| fingers | number | 否 | 触发滑动的最少手指数，默认为1，最小为1指，最大为10指。<br/>默认值：1 |
| direction | [SwipeDirection](#swipedirection枚举说明) | 否 | 触发滑动手势的滑动方向。<br/>默认值：SwipeDirection.All |
| speed | number | 否 | 识别滑动的最小速度（默认为100VP/秒）。<br/>默认值：100 |

## SwipeDirection枚举说明

| 名称 | 描述 |
| -------- | -------- |
| All | 所有方向。 |
| Horizontal | 水平方向。 |
| Vertical | 竖直方向。 |
| None | 任何方向均不可触发。 |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onAction(event:(event?:&nbsp;[GestureEvent](ts-gesture-settings.md))&nbsp;=&gt;&nbsp;void) | 滑动手势识别成功回调。 |

![zh-cn_image_0000001231374559](figures/zh-cn_image_0000001231374661.png)
## 示例

```ts
// xxx.ets
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle : number = 0
  @State speed : number = 1

  build() {
    Column() {
      Text("SwipGesture speed ： " + this.speed)
      Text("SwipGesture angle ： " + this.rotateAngle)
    }
    .position({x: 80, y: 200})
    .border({width:2})
    .width(260).height(260)
    .rotate({x: 0, y: 0, z: 1, angle: this.rotateAngle})
    .gesture(
      SwipeGesture({fingers: 1, direction: SwipeDirection.Vertical})
        .onAction((event: GestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![zh-cn_image_0000001231374559](figures/zh-cn_image_0000001231374559.gif)
