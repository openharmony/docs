# SwipeGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

用于触发滑动事件，滑动速度大于速度阈值时可识别成功，默认最小速度为100vp/s。

>  **说明：**
>
>  从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

### SwipeGesture

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

继承自[GestureInterface\<T>](ts-gesture-settings.md#gestureinterfacet11)，设置滑动手势事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | { fingers?: number; direction?: SwipeDirection; speed?: number } | 否 | 设置滑动事件参数。 <br> - fingers：触发滑动的最少手指数，默认为1，最小为1指，最大为10指。<br/>默认值：1 <br> - direction：触发滑动手势的滑动方向。<br/>默认值：SwipeDirection.All <br> - speed：识别滑动的最小速度。<br/>默认值：100VP/s <br/>**说明：** <br/>当滑动速度的值小于等于0时，会被转化为默认值。 |

### SwipeGesture<sup>15+</sup>

SwipeGesture(options?: SwipeGestureHandlerOptions)

设置滑动手势事件。与[SwipeGesture](#swipegesture-1)相比，options参数新增了对isFingerCountLimited参数，表示是否检查触摸屏幕的手指数量。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SwipeGestureHandlerOptions](./ts-uigestureevent.md#swipegesturehandleroptions) | 否 | 滑动事件处理器配置参数。 |

## SwipeDirection枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ---- | -- | ----- |
| All | - | 所有方向。 |
| Horizontal | - | 水平方向，手指滑动方向与x轴夹角小于45度时触发。 |
| Vertical | - | 竖直方向，手指滑动方向与y轴夹角小于45度时触发。 |
| None | - | 任何方向均不可触发。 |


## 事件

>  **说明：**
>
>  在[GestureEvent](ts-gesture-common.md#gestureevent对象说明)的fingerList元素中，手指索引编号与位置相对应，即fingerList[index]的id为index。对于先按下但未参与当前手势触发的手指，fingerList中对应的位置为空。建议优先使用fingerInfos。

**原子化服务API：** 从API version 8开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onAction

onAction(event: (event: GestureEvent) => void)

Swipe手势识别成功时触发回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-common.md#gestureevent对象说明)) => void | 是   | 手势事件回调函数。 |

## 示例

该示例通过配置SwipeGesture实现了滑动手势的识别。

```ts
// xxx.ets
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle: number = 0;
  @State speed: number = 1;

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
        .onAction((event: GestureEvent) => {
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