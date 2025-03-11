# LongPressGesture

用于触发长按手势事件，触发长按手势的最少手指数为1，最短长按时间为500毫秒。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

LongPressGesture(value?: { fingers?: number, repeat?: boolean, duration?: number })

当组件默认支持可拖拽时，如Text、TextInput、TextArea、HyperLink、Image和RichEditor等组件。长按手势与拖拽会出现冲突，事件优先级如下： 

长按触发时间 < 500ms，长按事件优先拖拽事件响应。 

长按触发时间 >= 500ms，拖拽事件优先长按事件响应。 

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| fingers | number | 否 | 触发长按的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1 <br/> **说明：** <br/>手指按下后若发生超过15px的移动，则判定当前长按手势识别失败。|
| repeat | boolean | 否 | 是否连续触发事件回调。<br/>默认值：false |
| duration | number | 否 | 触发长按的最短时间，单位为毫秒（ms）。<br/>默认值：500 <br/>**说明：** <br/>设置小于等于0时，按照默认值500处理。|
| isFingerCountLimited<sup>15+</sup> | boolean | 否 | 是否检查触摸屏幕的手指数量。若触摸屏幕的手指的数量不等于设置的触发长按的最少手指数（即上述fingers参数），手势识别将失败。<br>对于已成功识别的手势，后续触摸屏幕的手指数变化，将不触发repeat事件（若触摸屏幕的手指数恢复到设置的触发长按的最少手指数时，可以触发[onAction](ts-basic-gestures-longpressgesture.md#事件)事件），但可以触发[onActionEnd](ts-basic-gestures-longpressgesture.md#事件)事件。<br>默认值：false。|


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onAction(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | LongPress手势识别成功回调。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionEnd(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | LongPress手势识别成功，最后一根手指抬起后触发回调。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | LongPress手势识别成功，接收到触摸取消事件触发回调。不返回手势事件信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| onActionCancel(event:(event:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void)<sup>18+</sup> | LongPress手势识别成功，接收到触摸取消事件触发回调。返回手势事件信息。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|

## 属性

| 名称 | 类型    |描述                                        |
| ----  | ------  | ---------------------------------------- |
| tag<sup>11+</sup>   | string  | 设置LongPress手势标志，用于自定义手势判定时区分绑定的手势。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9)> | 设置LongPress手势支持的事件输入源。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |


## 示例

该示例通过LongPressGesture实现了长按手势的识别。

```ts
// xxx.ets
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0

  build() {
    Column() {
      Text('LongPress onAction:' + this.count).fontSize(28)
        // 单指长按文本触发该手势事件
        .gesture(
        LongPressGesture({ repeat: true })
          // 由于repeat设置为true，长按动作存在时会连续触发，触发间隔为duration（默认值500ms）
          .onAction((event: GestureEvent) => {
            if (event && event.repeat) {
              this.count++
            }
          })
            // 长按动作一结束触发
          .onActionEnd((event: GestureEvent) => {
            this.count = 0
          })
        )
    }
    .height(200)
    .width(300)
    .padding(20)
    .border({ width: 3 })
    .margin(30)
  }
}
```

![zh-cn_image_0000001174264380](figures/zh-cn_image_0000001174264380.gif)
