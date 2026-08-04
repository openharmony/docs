# LongPressGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

用于触发长按手势事件，触发长按手势的最少手指数为1，默认最短长按时间为500毫秒。可配置duration参数控制最短长按时长，适用于需要通过用户长按操作触发组件交互的场景。

>  **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 从API version 18开始，在优先响应系统双指长按手势的设备上，应用的双指长按手势不生效。


## 接口

### LongPressGesture

LongPressGesture(value?: { fingers?: number; repeat?: boolean; duration?: number })

创建长按手势对象。继承自[GestureInterface\<T>](ts-gesture-common.md#gestureinterfacet11)。

当组件默认支持可拖拽时，如Text、TextInput、TextArea、Hyperlink、Image和RichEditor等组件，长按手势与拖拽会出现冲突，事件优先级如下：

当长按触发时间小于500毫秒时，系统优先响应长按事件而非拖拽事件。

当长按触发时间达到或超过500毫秒时，系统优先响应拖拽事件而非长按事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | { fingers?: number; repeat?: boolean; duration?: number } | 否 | 设置长按手势参数。<br> - fingers：触发长按的最少手指数，最小值为1，&nbsp;最大值为10。<br/>默认值：1 <br> - repeat：是否连续触发事件回调。true表示连续触发事件回调，false表示不连续触发事件回调。<br/>默认值：false <br> - duration：触发长按的最短时间，单位为毫秒（ms）。<br/>默认值：500 |

### LongPressGesture<sup>15+</sup>

LongPressGesture(options?: LongPressGestureHandlerOptions)

创建长按手势对象。与[LongPressGesture](#longpressgesture-1)相比，options参数新增了对isFingerCountLimited参数，表示是否检查触摸屏幕的手指数量。

当组件默认支持可拖拽时，如Text、TextInput、TextArea、Hyperlink、Image和RichEditor等组件，长按手势与拖拽会出现冲突，事件优先级如下：

当长按触发时间小于500毫秒时，系统优先响应长按事件而非拖拽事件。

当长按触发时间达到或超过500毫秒时，系统优先响应拖拽事件而非长按事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [LongPressGestureHandlerOptions](./ts-gesturehandler.md#longpressgesturehandleroptions) | 否 | 长按手势处理器配置参数。当需要自定义长按手势的处理器配置（如是否检查触摸屏幕的手指数量、手势识别参数等）时传入；不传入时，使用长按手势的默认处理器配置。 |


## 事件

>  **说明：**
>
> - 在[GestureEvent](ts-gesture-common.md#gestureevent对象说明)的fingerList元素中，手指索引编号与位置相对应，即fingerList[index]的id为index。对于先按下但未参与当前手势触发的手指，fingerList中对应的位置为空。建议优先使用fingerInfos。
>
> - 长按手势触发后，[GestureEvent](ts-gesture-common.md#gestureevent对象说明)中fingerList和fingerInfos的信息仅在有手指按下时才会更新，手指抬起时不会更新。

### onAction

onAction(event: (event: GestureEvent) => void)

设置长按手势识别成功回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-common.md#gestureevent对象说明)) => void | 是   | 长按手势识别成功回调函数，用于在长按手势识别成功时接收GestureEvent手势事件信息。 |

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

设置长按手势结束回调。长按手势识别成功后，最后一根手指抬起时触发回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-common.md#gestureevent对象说明)) => void | 是   | 长按手势结束回调函数，用于在长按手势识别成功后最后一根手指抬起时接收GestureEvent手势事件信息。 |

### onActionCancel

onActionCancel(event: () => void)

设置长按手势取消回调。长按手势识别成功后，接收到触摸取消事件时触发回调。不返回手势事件信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | 是   | 长按手势取消回调函数。 |

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

设置长按手势取消回调。长按手势识别成功后，接收到触摸取消事件时触发回调。返回手势事件信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-common.md#gestureevent对象说明)> | 是   | 长按手势取消回调函数，用于在长按手势识别成功后接收到触摸取消事件时接收GestureEvent手势事件信息。 |

## 示例

该示例通过LongPressGesture实现了长按手势的识别。从API version 22开始，支持通过[LongPressGestureHandlerOptions](./ts-gesturehandler.md#longpressgesturehandleroptions)的allowableMovement属性设置识别手势的最大移动距离。

```ts
// xxx.ets
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0;

  build() {
    Column() {
      Text('LongPress onAction:' + this.count).fontSize(28)
        // 单指长按文本触发该手势事件。
        .gesture(
        // 设置长按手势识别器识别的手势的最大移动距离为200px。
        LongPressGesture({ repeat: true, allowableMovement: 200 })
          // 由于repeat设置为true，长按动作存在时会连续触发，触发间隔为duration（默认值500ms）。
          .onAction((event: GestureEvent) => {
            if (event && event.repeat) {
              this.count++;
            }
          })
            // 长按动作一结束触发。
          .onActionEnd(() => {
            this.count = 0;
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

![longPressGesture](figures/longPressGesture.gif)
