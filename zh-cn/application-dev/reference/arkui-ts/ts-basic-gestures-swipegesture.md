# SwipeGesture

用于触发滑动事件，滑动速度大于100vp/s时可识别成功。

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
| speed | number | 否 | 识别滑动的最小速度（默认为100VP/秒）。<br/>默认值：100 <br/>**说明：** <br/>当滑动速度的值小于等于0时，会被转化为默认值。 |

## SwipeDirection枚举说明

| 名称 | 描述 |
| -------- | -------- |
| All | 所有方向。 |
| Horizontal | 水平方向，手指滑动方向与x轴夹角小于45度时触发。 |
| Vertical | 竖直方向，手指滑动方向与y轴夹角小于45度时触发。 |
| None | 任何方向均不可触发。 |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onAction(event:(event?:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | 滑动手势识别成功回调。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle: number = 0
  @State speed: number = 1

  build() {
    Column() {
      Column() {
        Text("SwipeGesture speed\n" + this.speed)
        Text("SwipeGesture angle\n" + this.rotateAngle)
      }
      .border({ width: 3 })
      .width(300)
      .height(200)
      .margin(100)
      .rotate({ angle: this.rotateAngle })
      // 单指竖直方向滑动时触发该事件
      .gesture(
      SwipeGesture({ direction: SwipeDirection.Vertical })
        .onAction((event?: GestureEvent) => {
          if (event) {
            this.speed = event.speed
            this.rotateAngle = event.angle
          }
        })
      )
    }.width('100%')
  }
}
```

 ![zh-cn_image_0000001231374559.png](figures/zh-cn_image_0000001231374559.png) 