# 绑定手势方法
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

为组件绑定不同类型的手势事件，并设置事件的响应方法。

>  **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 绑定手势识别

通过如下方法给组件绑定手势识别，手势识别成功后可以通过事件回调通知组件。
可以通过[触摸热区](ts-universal-attributes-touch-target.md)指定可识别手势的区域。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

>  **说明：**
>
>  gesture、priorityGesture和parallelGesture当前不支持使用三目运算符（条件? 表达式1 : 表达式2）切换手势绑定。

### gesture

gesture(gesture: GestureType, mask?: GestureMask): T

绑定手势。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture  |  [GestureType](#gesturetype) | 是   | 绑定的手势类型。 |
| mask  |  [GestureMask](#gesturemask枚举说明) | 否   | 事件响应设置。<br/>默认值：GestureMask.Normal |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |

### priorityGesture

priorityGesture(gesture: GestureType, mask?: GestureMask): T

绑定优先识别手势。

1. 默认情况下，子组件优先识别通过gesture绑定的手势，当父组件配置priorityGesture时，父组件优先识别priorityGesture绑定的手势。

2. 绑定长按手势时，设置触发长按的最短时间小的组件会优先响应，会忽略priorityGesture设置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture  |  [GestureType](#gesturetype) | 是   | 绑定的手势对象。 |
| mask  |  [GestureMask](#gesturemask枚举说明) | 否   | 事件响应设置。<br/>默认值：GestureMask.Normal |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |

### parallelGesture

parallelGesture(gesture: GestureType, mask?: GestureMask): T

绑定可与子组件手势同时触发的手势。手势事件为非冒泡事件。父组件设置parallelGesture时，父子组件相同的手势事件都可以触发，实现类似冒泡效果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture  |  [GestureType](#gesturetype) | 是   | 绑定的手势对象。 |
| mask  |  [GestureMask](#gesturemask枚举说明) | 否   | 事件响应设置。<br/>默认值：GestureMask.Normal |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |


## GestureType

declare type GestureType = TapGesture | LongPressGesture | PanGesture | PinchGesture | SwipeGesture | RotationGesture | GestureGroup;

定义手势类型。取值类型为下表类型中的并集。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型 | 说明 |
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | 点击手势，支持单次点击、多次点击识别。 |
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | 长按手势。 |
| [PanGesture](ts-basic-gestures-pangesture.md) | 平移手势，当滑动的距离达到最小阈值时触发滑动手势事件，默认滑动阈值为5vp。 |
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | 捏合手势。 |
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | 旋转手势。 |
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | 滑动手势，滑动速度大于等于速度阈值时可识别成功，默认最小速度为100vp/s。 |
| [GestureGroup](ts-combined-gestures.md) | 手势识别组，多种手势组合为复合手势，支持连续识别、并行识别和互斥识别。 |

## GestureInterface\<T><sup>11+</sup>

定义Gesture接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### tag<sup>11+</sup>

tag(tag: string): T

设置手势的标志。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| tag  |  string | 是   | 手势的标志。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |

### allowedTypes<sup>14+</sup>

allowedTypes(types: Array\<SourceTool>): T

设置手势响应的输入类型。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| types  |  Array\<[SourceTool](#sourcetool枚举说明9)> | 是   | 手势响应的输入类型。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件。 |


## GestureMask枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 |值| 说明 |
| -------- | ---- |-------- |
| Normal | - |不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 |
| IgnoreInternal | - | 屏蔽子组件的手势，包括子组件上系统内置的手势，如子组件为List组件时，内置的滑动手势同样会被屏蔽。 若父子组件区域存在部分重叠，则只会屏蔽父子组件重叠的部分。|

## 响应手势事件

组件通过手势事件绑定不同GestureType的手势对象，各手势对象在响应手势操作的事件回调中提供手势相关信息。下面通过[TapGesture](./ts-basic-gestures-tapgesture.md)手势对象的[onAction](./ts-basic-gestures-tapgesture.md#onaction)事件响应点击事件，获取事件相关信息。其余手势对象的事件定义见各个手势对象章节。 若需绑定多种手势，请使用[组合手势](ts-combined-gestures.md)。

## SourceType枚举说明<sup>8+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ---- | --- | -------- |
| Unknown | - | 未知设备。 |
| Mouse | - | 鼠标。 |
| TouchScreen | - | 触摸屏。 |

## FingerInfo对象说明<sup>8+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选| 说明 |
| -------- | -------- |  -------- |--------- |-------- |
| id | number | 否  | 否     |手指的索引编号，由按下手指的数量决定，按下一根手指为0，之后每按下1根手指索引编号加一。<br/>**说明：**<br/> 鼠标（索引编号为1001）、手写笔（索引编号为102）、鼠标滚轮（索引编号为0）、触摸板双指滑动（索引编号为0）的索引编号也会被转化为手指的索引编号。<br/>取值范围：[0, 9)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalX | number | 否  |  否     |相对于应用窗口左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalY | number | 否  |  否     |相对于应用窗口左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localX | number | 否  |  否     |相对于当前组件元素原始区域左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localY | number | 否  |  否     |相对于当前组件元素原始区域左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayX<sup>12+</sup> | number | 否  | 否     | 相对于屏幕左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| displayY<sup>12+</sup> | number | 否  |  否     |相对于屏幕左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| hand<sup>15+</sup> | [InteractionHand](#interactionhand枚举说明15) | 否  |  是     |表示事件是由左手点击还是右手点击触发。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| globalDisplayX<sup>20+</sup> | number | 否  |  是     |相对于全局屏幕的左上角的X坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number | 否  |  是     |相对于全局屏幕的左上角的Y坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## SourceTool枚举说明<sup>9+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | - | --------- |
| Unknown | - | 未知输入源。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Finger | - | 手指输入。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Pen | - | 手写笔输入。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MOUSE<sup>12+</sup> | - | 鼠标输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| TOUCHPAD<sup>12+</sup> | - | 触控板输入。触控板单指输入被视为鼠标输入操作。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| JOYSTICK<sup>12+</sup> | - | 手柄输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## InteractionHand枚举说明<sup>15+</sup>

定义事件是由左手点击还是右手点击触发。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 描述 |
| -------- | -------- | -------- |
| NONE | 0 | 未知。 |
| LEFT | 1 | 左手。 |
| RIGHT | 2 | 右手。 |


## 示例

### 示例1(父组件优先识别手势和父子组件同时触发手势)

该示例通过配置priorityGesture和parallelGesture分别实现了父组件优先识别手势和父子组件同时触发手势。

```ts
// xxx.ets
@Entry
@Component
struct GestureSettingsExample {
  @State priorityTestValue: string = ''
  @State parallelTestValue: string = ''

  build() {
    Column() {
      Column() {
        Text('TapGesture:' + this.priorityTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction((event: GestureEvent) => {
                this.priorityTestValue += '\nText'
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // 设置为priorityGesture时，点击文本会忽略Text组件的TapGesture手势事件，优先识别父组件Column的TapGesture手势事件
      .priorityGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.priorityTestValue += '\nColumn'
          }), GestureMask.IgnoreInternal)

      Column() {
        Text('TapGesture:' + this.parallelTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction((event: GestureEvent) => {
                this.parallelTestValue += '\nText'
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // 设置为parallelGesture时，点击文本会同时触发子组件Text与父组件Column的TapGesture手势事件
      .parallelGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.parallelTestValue += '\nColumn'
          }), GestureMask.Normal)
    }
  }
}
```

![zh-cn_image_0000001210195016](figures/zh-cn_image_0000001210195016.gif)

### 示例2（实时监测参与滑动手势的有效触点数量）

该示例通过配置fingerInfos实时监测参与滑动手势的有效触点数量

```ts
// xxx.ets
@Entry
@Component

struct PanGestureWithFingerCount {
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State positionX: number = 0
  @State positionY: number = 0
  @State fingerCount: number = 0  //用于记录参与手势的触点数量

  private panOption: PanGestureOptions = new PanGestureOptions({
    direction: PanDirection.All,
    fingers: 1
  })

  build() {
    Column() {
      // 显示当前有效触点数量
      Text(`触点数量: ${this.fingerCount}`)
        .fontSize(20)
        .margin(10)

      Column() {
        Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin(50)
      .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
      .gesture(
        PanGesture(this.panOption)
          .onActionStart((event: GestureEvent) => {
            console.info('Pan start')
            this.fingerCount = event.fingerInfos?.length || 0  // 记录触点数量
          })
          .onActionUpdate((event: GestureEvent) => {
            if (event) {
              console.info('fingerInfos',JSON.stringify(event.fingerInfos))
              this.offsetX = this.positionX + event.offsetX
              this.offsetY = this.positionY + event.offsetY
              this.fingerCount = event.fingerInfos?.length || 0  // 更新触点数量,记录下参与当前手势的有效触点的数量
            }
          })
          .onActionEnd((event: GestureEvent) => {
            this.positionX = this.offsetX
            this.positionY = this.offsetY
            this.fingerCount = 0  // 触点离开触摸区域后归零
            console.info('Pan end')
          })
          .onActionCancel(() => {
            this.fingerCount = 0  // 手势取消后归零
          })
      )

      Button('切换为双指滑动')
        .onClick(() => {
          this.panOption.setFingers(2)
        })
    }
  }
}
```