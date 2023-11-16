# 自定义手势判定

为组件提供自定义手势判定能力。开发者可根据需要，在手势识别期间，决定是否响应手势。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## onGestureJudgeBegin
onGestureJudgeBegin(callback: (gestureInfo: GestureInfo, event: BaseGestureEvent) => GestureJudgeResult)

**参数：**
| 参数名        | 参数类型                    | 必填  | 参数描述                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | (gestureInfo: [GestureInfo](#gestureinfo对象说明), event: [BaseGestureEvent](#basegestureevent对象说明)) => [GestureJudgeResult](ts-appendix-enums.md#gesturejudgeresult11) | 是     |  给组件绑定自定义手势判定回调，当绑定到该组件的手势被接受时，会触发用户定义的回调来获取结果。 |

## GestureInfo对象说明

| 名称            | 类型                        | 描述         |
| ---------------  | -------------------------   | -----------|
| tag              | string                      | 手势标记。  |
| type             | [GestureControl.GestureType](ts-appendix-enums.md#gesturetype11)  | 手势类型。 |
| isSystemGesture  | boolean                     | 判断当前手势是否为系统手势。|

## BaseEvent对象说明
| 名称    | 类型                                      | 描述         |
| ---------| ----------------------------------------  | -----------|
| target   | [EventTarget](ts-universal-events-click.md#eventtarget8对象说明) | 触发手势事件的元素对象显示区域。  |
| timestamp| number | 事件时间戳。  |
| source   | [SourceType](ts-gesture-settings.md#sourcetype枚举说明) | 事件输入设备。  |
| pressure | number | 按压的压力大小。  |
| titleX | number | 手写笔在设备平面上的投影与设备平面X轴的夹角。  |
| titleY | number | 手写笔在设备平面上的投影与设备平面Y轴的夹角。  |
| sourceTool | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明) | 事件输入源。  |
## BaseGestureEvent对象说明
继承于[BaseEvent](#baseevent对象说明)。
| 名称      | 类型                                      | 描述         |
| ---------  | ----------------------------------------  | -----------|
| fingerList | [FingerInfo[]](ts-gesture-settings.md#fingerinfo对象说明) | 触发事件的所有手指信息。  |

## TapGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。

## LongPressGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。
| 名称      | 类型                                      | 描述         |
| ---------  | ----------------------------------------  | -----------|
| repeat     | boolean | 是否为重复触发事件。  |

## PanGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。
| 名称      | 类型                                      | 描述         |
| ---------  | ----------------------------------------  | -----------|
| offsetX    | number | 手势事件x轴相对当前组件元素原始区域的偏移量，单位为vp，从左向右滑动offsetX为正，反之为负。  |
| offsetY    | number | 手势事件y轴相对当前组件元素原始区域的偏移量，单位为vp，从上向下滑动offsetY为正，反之为负。  |
| velocityX  | number | 获取当前手势的x轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从左往右为正，反之为负。  |
| velocityY  | number | 获取当前手势的y轴方向速度。坐标轴原点为屏幕左上角，分正负方向速度，从上往下为正，反之为负。|
| velocity   | number | 获取当前的主方向速度。为xy轴方向速度的平方和的算术平方根。  |

## PinchGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。
| 名称         | 类型                                      | 描述         |
| ------------  | ----------------------------------------  | -----------|
| scale         | number | 缩放比例。  |
| pinchCenterX  | number | 捏合手势中心点相对于当前组件元素原始区域左上角x轴坐标，单位为vp。  |
| pinchCenterY  | number | 捏合手势中心点相对于当前组件元素原始区域左上角y轴坐标，单位为vp。  |

## RotationGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。
| 名称         | 类型                                      | 描述         |
| ------------  | ----------------------------------------  | -----------|
| angle         | number | 表示旋转角度，单位为deg。<br/>**说明：**<br/>角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。  |

## SwipeGestureEvent对象说明
继承于[BaseGestureEvent](#basegestureevent对象说明)。可将该对象作为[onGestureJudgeBegin](#ongesturejudgebegin)的event参数来传递。
| 名称         | 类型                                      | 描述         |
| ------------  | ----------------------------------------  | -----------|
| angle         | number | 表示滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数，单位为deg。<br/>**说明：**<br/>角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。|
| speed         | number | 滑动手势速度，即所有手指相对当前组件元素原始区域滑动的平均速度，单位为vp/秒。  |
## 示例

### 示例1
```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State message: string = '';

  build() {
    Column() {
      Row({ space: 20 }) {
        Text(this.message).width(100).height(40).backgroundColor(Color.Pink)
      }.margin(20)
    }
    .width('100%')
    .height(200)
    .borderWidth(2)
    .onDragStart(() => {
      this.message = 'drag'
      console.log("Drag start.")
    })
    .gesture(
      TapGesture()// set gesture tag
        .tag("tap1")
    )
    .gesture(
      LongPressGesture()// set gesture tag
        .tag("longPress1")
        .onAction(() => {
          this.message = 'longPress'
        })
    )
    .gesture(
      SwipeGesture()// set gesture tag
        .tag("swipe1")
    )
    .gesture(
      PanGesture()// set gesture tag
        .tag("pan1")
    )
    .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent) => {
      // If the gesture type is longPress, convert event to LongPressGestureEvent
      if (gestureInfo.type == GestureControl.GestureType.LONG_PRESS_GESTURE) {
        let longPressEvent = event as LongPressGestureEvent;
        console.log("repeat " + longPressEvent.repeat)
      }
      // If the gesture type is swipe, convert event to SwipeGestureEvent
      if (gestureInfo.type == GestureControl.GestureType.SWIPE_GESTURE) {
        let swipeEvent = event as SwipeGestureEvent;
        console.log("angle " + swipeEvent.angle)
      }
      // If the gesture type is swipe, convert event to PanGestureEvent
      if (gestureInfo.type == GestureControl.GestureType.PAN_GESTURE) {
        let panEvent = event as PanGestureEvent;
        console.log("velocity " + panEvent.velocity)
      }
      // Custom decision criteria
      if (gestureInfo.type == GestureControl.GestureType.DRAG) {
        // return REJECT will make drag gesture fail.
        return GestureJudgeResult.REJECT;
      } else if (gestureInfo.tag == 'longPress1' && event.fingerList.length > 0 && event.fingerList[0].localY < 100) {
        // return CONTINUE will continue system decision.
        return GestureJudgeResult.CONTINUE;
      }
      return GestureJudgeResult.CONTINUE;
    })
  }
}
```
### 示例2
```ts
// xxx.ets
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Index {
  scroller: Scroller = new Scroller()

  build() {
    Scroll(this.scroller) {
      Column({ space: 8 }) {
        Text("Drag 上下两层 上层绑定长按，下层绑定拖拽。先长按后平移上半区红色区域只会响应长按，先长按后平移下半区蓝色区域只会响应拖拽").width('100%').fontSize(20).fontColor('0xffdd00')
          .backgroundColor(0xeeddaa00)
        Stack({ alignContent: Alignment.Center }) {
          Column() {
            // Simulate the upper and lower half zones
            Stack().width('200vp').height('100vp').backgroundColor(Color.Red)
            Stack().width('200vp').height('100vp').backgroundColor(Color.Blue)
          }.width('200vp').height('200vp')
          // The lower layer of the Stack is the image layer bound with drag and drop
          Image($r('sys.media.ohos_app_icon'))
            .onDragStart(()=>{
              promptAction.showToast({ message: "Drag 下半区蓝色区域，Image响应" })
            })
            .width('200vp').height('200vp')
          // The upper layer of the Stack is a floating layer bound with a long press
          Stack() {
            // overlay
          }
          .width('200vp')
          .height('200vp')
          .hitTestBehavior(HitTestMode.Transparent)
          .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent) => {
            // Determine whether the tag has value
            if (gestureInfo.tag) {
              console.log("gestureInfo tag" + gestureInfo.tag.toString())
            }
            console.log("gestureInfo Type " + gestureInfo.type.toString() + " isSystemGesture " + gestureInfo.isSystemGesture);
            console.log("pressure " + event.pressure + " fingerList.length " + event.fingerList.length
              + " timeStamp " + event.timestamp + " sourceType " + event.source.toString() + " titleX " + event.tiltX + " titleY " + event.tiltY + " sourcePool " + event.sourceTool.toString());
            // If it is long press, determine whether the position of the click is in the upper half
            if (gestureInfo.type == GestureControl.GestureType.LONG_PRESS_GESTURE) {
              if (event.fingerList.length > 0 && event.fingerList[0].localY < 100) {
                return GestureJudgeResult.CONTINUE
              } else {
                return GestureJudgeResult.REJECT
              }
            }
            return GestureJudgeResult.CONTINUE
          })
          .gesture(GestureGroup(GestureMode.Parallel,
            LongPressGesture()
              .onAction((event: GestureEvent) => {
                promptAction.showToast({ message: "LongPressGesture 长按上半区 红色区域，红色区域响应" })
              })
              .tag("tap111")
          ))

        }.width('100%')
      }.width('100%')
    }
  }
}
```