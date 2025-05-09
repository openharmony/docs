# 绑定手势方法

为组件绑定不同类型的手势事件，并设置事件的响应方法。

>  **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 绑定手势识别

通过如下属性给组件绑定手势识别，手势识别成功后可以通过事件回调通知组件。
可以通过[触摸热区](ts-universal-attributes-touch-target.md)指定可识别手势的区域。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| gesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定手势。<br/>- gesture:&nbsp;绑定的手势类型。&nbsp;<br>- mask:&nbsp;事件响应设置。 |
| priorityGesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定优先识别手势。<br/>- gesture: 绑定的手势类型。 <br/>- mask: 事件响应设置。<br/>1、默认情况下，子组件优先识别通过gesture绑定的手势，当父组件配置priorityGesture时，父组件优先识别priorityGesture绑定的手势。<br/>2、长按手势时，设置触发长按的最短时间小的组件会优先响应，会忽略priorityGesture设置。|
| parallelGesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定可与子组件手势同时触发的手势。<br/>- gesture:&nbsp;绑定的手势类型。&nbsp;<br>- mask:&nbsp;事件响应设置。<br/>手势事件为非冒泡事件。父组件设置parallelGesture时，父子组件相同的手势事件都可以触发，实现类似冒泡效果。 |


## GestureType

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 描述 |
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | 点击手势，支持单次点击、多次点击识别。 |
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | 长按手势。 |
| [PanGesture](ts-basic-gestures-pangesture.md) | 平移手势，滑动最小距离为5vp时识别成功。 |
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | 捏合手势。 |
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | 旋转手势。 |
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | 滑动手势，滑动最小速度为100vp/s时识别成功。 |
| [GestureGroup](ts-combined-gestures.md) | 手势识别组，多种手势组合为复合手势，支持连续识别、并行识别和互斥识别。 |


## GestureMask枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 描述 |
| -------- | -------- |
| Normal | 不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 |
| IgnoreInternal | 屏蔽子组件的手势，包括子组件上系统内置的手势，如子组件为List组件时，内置的滑动手势同样会被屏蔽。 若父子组件区域存在部分重叠，则只会屏蔽父子组件重叠的部分。|

## 响应手势事件

组件通过手势事件绑定不同GestureType的手势对象，各手势对象在响应手势操作的事件回调中提供手势相关信息。下面通过TapGesture手势对象的onAction事件响应点击事件，获取事件相关信息。其余手势对象的事件定义见各个手势对象章节。 若需绑定多种手势请使用 [组合手势](ts-combined-gestures.md)。

**TapGesture事件说明**

| 名称 | 功能描述 |
| -------- | -------- |
| onAction((event:GestureEvent)&nbsp;=&gt;&nbsp;void) | Tap手势识别成功回调。 |

## GestureEvent对象说明

继承于[BaseEvent](ts-gesture-customize-judge.md#baseevent对象说明8)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| repeat | boolean | 是否为重复触发事件，用于LongPressGesture手势触发场景。<br>true：表示为重复触发事件。<br>false：表示非重复触发事件。 |
| offsetX | number | 手势事件偏移量X，单位为vp，用于PanGesture手势触发场景，从左向右滑动offsetX为正，反之为负。 |
| offsetY | number | 手势事件偏移量Y，单位为vp，用于PanGesture手势触发场景，从上向下滑动offsetY为正，反之为负。 |
| angle | number | 用于RotationGesture手势触发场景时，表示旋转角度。<br/>用于SwipeGesture手势触发场景时，表示滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数。<br/>**说明：**<br/>角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。 |
| scale | number | 缩放比例，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞) |
| pinchCenterX | number | 捏合手势中心点的x轴坐标，单位为vp，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞) |
| pinchCenterY | number | 捏合手势中心点的y轴坐标，单位为vp，用于PinchGesture手势触发场景。<br/>取值范围：[0, +∞) |
| speed<sup>8+</sup> | number | 滑动手势速度，即所有手指相对当前组件元素原始区域滑动的平均速度，单位为vp/秒，用于SwipeGesture手势触发场景。<br/>取值范围：[0, +∞) |
| fingerList<sup>8+</sup> | [FingerInfo](#fingerinfo对象说明8)[] | 输入源为触屏产生的手势，fingerList中会包含触发事件的所有触点信息；由鼠标发起的手势，fingerList中只会有一条记录；触摸板的事件大类与鼠标一致，所以由触摸板发起的手势，fingerList只会携带一条记录。<br/>**说明：**<br/>手指索引编号与位置对应，即fingerList[index]的id为index。先按下且未参与当前手势触发的手指在fingerList中对应位置为空。 |
| velocityX<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。单位为vp/s。 |
| velocityY<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。单位为vp/s。 |
| velocity<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的主方向速度。为xy轴方向速度的平方和的算术平方根。单位为vp/s。 |

## SourceType枚举说明<sup>8+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 描述 |
| -------- | -------- |
| Unknown | 未知设备。 |
| Mouse | 鼠标。 |
| TouchScreen | 触摸屏。 |

## FingerInfo对象说明<sup>8+</sup>

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| id | number | 手指的索引编号。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalX | number | 相对于应用窗口左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| globalY | number | 相对于应用窗口左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localX | number | 相对于当前组件元素原始区域左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| localY | number | 相对于当前组件元素原始区域左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayX<sup>12+</sup> | number | 相对于屏幕左上角的x轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| displayY<sup>12+</sup> | number | 相对于屏幕左上角的y轴坐标，单位为vp。<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| hand<sup>15+</sup> | [InteractionHand](#interactionhand枚举说明15) | 表示事件是由左手点击还是右手点击触发。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |

## SourceTool枚举说明<sup>9+</sup>

| 名称 | 描述 |
| -------- | -------- |
| Unknown | 未知输入源。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Finger | 手指输入。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Pen | 手写笔输入。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Mouse<sup>12+</sup> | 鼠标输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| Touchpad<sup>12+</sup> | 触控板输入。触控板单指输入被视为鼠标输入操作。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| Joystick<sup>12+</sup> | 手柄输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## InteractionHand枚举说明<sup>15+</sup>

定义事件是由左手点击还是右手点击触发。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 描述 |
| -------- | -------- |
| NONE | 未知。 |
| LEFT | 左手。 |
| RIGHT | 右手。 |


## 示例

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
