# SwipeGesture

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 接口

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

- 参数
  | 参数名称 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | 否 | 1 | 触发滑动的最少手指数，默认为1，最小为1指，最大为10指。 |
  | direction | SwipeDirection | 否 | SwipeDirection.All | 滑动方向。 |
  | speed | number | 否 | 100 | 识别滑动的最小速度（100VP/秒）。 |

- SwipeDirection枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | All | 所有方向。 | 
  | Horizontal | 水平方向。 | 
  | Vertical | 竖直方向。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- | -------- |
| onAction(callback:(event?:&nbsp;SwipeGestureEvent)&nbsp;=&gt;&nbsp;void) | 滑动手势识别成功回调。 | 


- SwipeGestureEvent对象说明
  | 参数名 | 类型 | 说明 | 
  | -------- | -------- | -------- |
  | angle | number | 滑动手势的角度。 | 
  | speed | number | 滑动手势的速度。 | 


## 示例

```
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
      SwipeGesture({fingers: 1, direction:SwipeDirection.Vertical})
        .onAction((event: SwipeGestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![zh-cn_image_0000001231374559](figures/zh-cn_image_0000001231374559.gif)
