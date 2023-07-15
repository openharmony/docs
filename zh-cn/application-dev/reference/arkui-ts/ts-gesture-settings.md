# 绑定手势方法

为组件绑定不同类型的手势事件，并设置事件的响应方法。

>  **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 绑定手势识别

通过如下属性给组件绑定手势识别，手势识别成功后可以通过事件回调通知组件。

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| gesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定手势。<br/>- gesture:&nbsp;绑定的手势类型，&nbsp;<br>- mask:&nbsp;事件响应设置。 |
| priorityGesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定优先识别手势。<br/>- gesture: 绑定的手势类型， <br/>- mask: 事件响应设置。<br/>1、默认情况下，子组件优先识别通过gesture绑定的手势，当父组件配置priorityGesture时，父组件优先识别priorityGesture绑定的手势。<br/>2、长按手势时，设置触发长按的最短时间小的组件会优先响应，会忽略priorityGesture设置。|
| parallelGesture | gesture:&nbsp;[GestureType](#gesturetype),<br/>mask?:&nbsp;[GestureMask](#gesturemask枚举说明) | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定可与子组件手势同时触发的手势。<br/>- gesture:&nbsp;绑定的手势类型。&nbsp;<br>- mask:&nbsp;事件响应设置。<br/>手势事件为非冒泡事件。父组件设置parallelGesture时，父子组件相同的手势事件都可以触发，实现类似冒泡效果。若父子组件中同时绑定单击手势事件和双击手势事件，则只响应单击手势事件。 |


## GestureType
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
| 名称 | 描述 |
| -------- | -------- |
| Normal | 不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 |
| IgnoreInternal | 屏蔽子组件的手势，包括子组件上系统内置的手势，如子组件为List组件时，内置的滑动手势同样会被屏蔽。 |

## 响应手势事件

组件通过手势事件绑定不同GestureType的手势对象，各手势对象在响应手势操作的事件回调中提供手势相关信息。下面通过TapGesture手势对象的onAction事件响应点击事件，获取事件相关信息。其余手势对象的事件定义见各个手势对象章节。 若需绑定多种手势请使用 [组合手势](ts-combined-gestures.md)。

**TapGesture事件说明**

| 名称 | 功能描述 |
| -------- | -------- |
| onAction((event?:GestureEvent)&nbsp;=&gt;&nbsp;void) | Tap手势识别成功回调。 |

## GestureEvent对象说明
| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| repeat | boolean | 是否为重复触发事件，用于LongPressGesture手势触发场景。 |
| offsetX | number | 手势事件x轴相对偏移量，单位为vp，用于PanGesture手势触发场景，从左向右滑动offsetX为正，反之为负。 |
| offsetY | number | 手势事件y轴相对偏移量，单位为vp，用于PanGesture手势触发场景，从上向下滑动offsetY为正，反之为负。 |
| angle | number | 用于RotationGesture手势触发场景时，表示旋转角度。<br/>用于SwipeGesture手势触发场景时，表示滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数。<br/>>&nbsp;&nbsp;**说明：**<br/>>&nbsp;角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。 |
| scale | number | 缩放比例，用于PinchGesture手势触发场景。 |
| pinchCenterX | number | 捏合手势中心点相对于当前组件元素左上角x轴坐标，单位为vp，用于PinchGesture手势触发场景。 |
| pinchCenterY | number | 捏合手势中心点相对于当前组件元素左上角y轴坐标，单位为vp，用于PinchGesture手势触发场景。 |
| speed<sup>8+</sup> | number | 滑动手势速度，即所有手指滑动的平均速度，单位为vp/秒，用于SwipeGesture手势触发场景。 |
| fingerList<sup>8+</sup> | [FingerInfo](#fingerinfo对象说明)[] | 触发事件的所有手指信息，用于LongPressGesture与TapGesture手势触发场景。 |
| timestamp<sup>8+</sup> | number | 事件时间戳。 |
| target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md#eventtarget8对象说明) | 触发手势事件的元素对象显示区域。 |
| source<sup>8+</sup> | [SourceType](#sourcetype枚举说明) | 事件输入设备。 |
| pressure<sup>9+</sup> | number | 按压的压力大小。 |
| tiltX<sup>9+</sup> | number | 手写笔在设备平面上的投影与设备平面X轴的夹角。 |
| tiltY<sup>9+</sup> | number | 手写笔在设备平面上的投影与设备平面Y轴的夹角。 |
| sourceTool<sup>9+</sup> | [SourceTool](#sourcetool枚举说明) | 事件输入源。 |
| velocityX<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。 |
| velocityY<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。 |
| velocity<sup>10+</sup> | number | 用于[PanGesture](ts-basic-gestures-pangesture.md)手势中，获取当前手势的主方向速度。为xy轴方向速度的平方和的算术平方根。 |

## SourceType枚举说明
| 名称 | 描述 |
| -------- | -------- |
| Unknown | 未知设备。 |
| Mouse | 鼠标。 |
| TouchScreen | 触摸屏。 |

## FingerInfo对象说明
| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| id | number | 手指的索引编号。 |
| globalX | number | 相对于应用窗口左上角的x轴坐标。 |
| globalY | number | 相对于应用窗口左上角的y轴坐标。 |
| localX | number | 相对于当前组件元素左上角的x轴坐标。 |
| localY | number | 相对于当前组件元素左上角的y轴坐标。 |

## SourceTool枚举说明
| 名称 | 描述 |
| -------- | -------- |
| Unknown | 未知输入源。 |
| Finger | 手指输入。 |
| Pen | 手写笔输入。 |


## 示例

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
            .onAction(() => {
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
            .onAction(() => {
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
