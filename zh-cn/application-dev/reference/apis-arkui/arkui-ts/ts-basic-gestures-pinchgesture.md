# PinchGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

用于触发捏合手势，触发捏合手势的最少手指为2指，最大为5指，最小识别距离为5vp。

>  **说明：**
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  
>  在捏合手势触发成功后，需要抬起所有手指，重新按下进行捏合才能再次触发捏合手势。


## 接口

PinchGesture(value?: { fingers?: number, distance?: number })

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| fingers | number | 否 | 触发捏合的最少手指数，&nbsp;最小为2指，最大为5指。<br/>默认值：2 <br/>触发手势手指可以多于fingers数目，但只有先落下的与fingers相同数目的手指参与手势计算。 |
| distance | number | 否 | 最小识别距离，单位为vp。<br/>默认值：5 <br/>**说明：** <br/>取值范围：[0, +∞)。当识别距离的值小于等于0时，会被转化为默认值。|
| isFingerCountLimited<sup>15+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指数量不等于设置的触发捏合的最少手指数（即上述fingers参数），手势将不会被识别。只有当触摸屏幕的手指数等于设置的触发捏合手势的最小手指数，并且滑动距离满足阈值要求时，手势才能被成功识别（只有先落下的两根手指参与手势计算，若抬起其中的一个，手势识别失败）。对于已经成功识别的手势，后续改变触摸屏幕的手指数量，将不会触发onActionUpdate[事件](ts-basic-gestures-pinchgesture.md#事件)，但可以触发onActionEnd[事件](ts-basic-gestures-pinchgesture.md#事件)。<br>true：检查触摸屏幕的手指数量。<br>false：不检查触摸屏幕的手指数量。<br>默认值：false|


## 事件

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

>  **说明：**
>
>  在[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)的fingerList元素中，手指索引编号与位置相对应，即fingerList[index]的id为index。对于先按下但未参与当前手势触发的手指，fingerList中对应的位置为空。建议优先使用fingerInfos。

| 名称 | 功能描述 |
| -------- | -------- |
| onActionStart(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功回调。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionUpdate(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | Pinch手势移动过程中回调。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionEnd(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功，手指抬起后触发回调。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Pinch手势识别成功，接收到触摸取消事件触发回调。不返回手势事件信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionCancel(event:&nbsp;Callback<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)>)<sup>18+</sup> | Pinch手势识别成功，接收到触摸取消事件触发回调。返回手势事件信息。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|

## 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型    |描述                                        |
| ----  | ------  | ---------------------------------------- |
| tag<sup>11+</sup>   | string  | 设置Pinch手势标志，用于自定义手势判定时区分绑定的手势。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9)> | 设置Pinch手势支持的事件输入源。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |

## 示例

该示例通过配置PinchGesture实现了三指捏合手势的识别。

```ts
// xxx.ets
@Entry
@Component
struct PinchGestureExample {
  @State scaleValue: number = 1;
  @State pinchValue: number = 1;
  @State pinchX: number = 0;
  @State pinchY: number = 0;

  build() {
    Column() {
      Column() {
        Text('PinchGesture scale:\n' + this.scaleValue)
        Text('PinchGesture center:\n(' + this.pinchX + ',' + this.pinchY + ')')
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin({ top: 100 })
      .scale({ x: this.scaleValue, y: this.scaleValue, z: 1 })
      // 三指捏合触发该手势事件
      .gesture(
      PinchGesture({ fingers: 3 })
        .onActionStart((event: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: GestureEvent) => {
          if (event) {
            this.scaleValue = this.pinchValue * event.scale
            this.pinchX = event.pinchCenterX
            this.pinchY = event.pinchCenterY
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.pinchValue = this.scaleValue
          console.info('Pinch end')
        })
      )
    }.width('100%')
  }
}
```

 ![zh-cn_image_0000001174582848](figures/zh-cn_image_0000001174582848.png)
