# 无障碍悬浮事件

在开启无障碍模式后，Touch事件会转换为无障碍悬浮事件。

>  **说明：**
>
>  - 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 目前仅支持通过开启无障碍模式触发。

## onAccessibilityHover

onAccessibilityHover(callback: AccessibilityCallback): T

开启无障碍模式后，单指触摸绑定该回调的组件时触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                    | 必填  | 说明                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [AccessibilityCallback](#accessibilitycallback) | 是   |  提供开启无障碍模式后的无障碍悬浮回调事件，当开启无障碍模式后，单指触摸绑定该回调的组件时触发该回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## AccessibilityCallback

type AccessibilityCallback = (isHover: boolean, event: AccessibilityHoverEvent) => void

提供开启无障碍模式后的无障碍悬浮回调事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                | 必填 | 说明                                                         |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| isHover             | boolean                             | 是   | 表示开启无障碍模式后，手指在组件上触发由Touch事件转换成的无障碍悬浮事件，手指进入时为true，退出时为false。 |
| event | [AccessibilityHoverEvent](#accessibilityhoverevent对象说明) | 是   | 获得AccessibilityHoverEvent对象。                                   |

## AccessibilityHoverEvent对象说明

继承于[BaseEvent](ts-gesture-customize-judge.md#baseevent对象说明8)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型       | 必填 | 说明      |
| --------------- | ---------- | ------- | ------- |
| type             | [AccessibilityHoverType](#accessibilityhovertype) | 否 | 无障碍悬浮动作。                |
| x                      | number                         | 否 | 手指位置相对于当前组件左上角的x轴坐标。<br/>单位：vp<br/> |
| y                      | number                         | 否 | 手指位置相对于当前组件左上角的y轴坐标。<br/>单位：vp<br/> |
| windowX                | number                         | 否 | 手指位置相对于应用窗口左上角的x轴坐标。<br/>单位：vp<br/> |
| windowY                | number                         | 否 | 手指位置相对于应用窗口左上角的y轴坐标。<br/>单位：vp<br/> |
| displayX               | number                         | 否 | 手指位置相对于应用屏幕左上角的x轴坐标。<br/>单位：vp<br/> |
| displayY               | number                         | 否 | 手指位置相对于应用屏幕左上角的y轴坐标。<br/>单位：vp<br/> |

## AccessibilityHoverType

定义无障碍悬浮类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                               |
| ------- | ---- | ---------------------------------- |
| HOVER_ENTER | 0    | 手指按下时触发。 |
| HOVER_MOVE  | 1    | 触摸移动时触发。 |
| HOVER_EXIT  | 2    | 抬手触发。 |
| HOVER_CANCEL | 3    | 打断取消当前触发的事件。 |

## onAccessibilityHoverTransparent<sup>20+</sup>

onAccessibilityHoverTransparent(callback: AccessibilityTransparentCallback): T

当前触摸位置处于注册了回调接口的组件区域，但未能响应无障碍悬浮事件。仅支持手指触摸。不支持如下组件在触摸位置中的场景，包括[UIExtension](../../apis-arkui/js-apis-arkui-uiExtension.md)、[Web](../../apis-arkweb/arkts-basic-components-web.md)、<!--Del-->[FormComponent](ts-basic-components-formcomponent-sys.md)、<!--DelEnd-->[XComponent](ts-basic-components-xcomponent.md)与第三方UI框架对接。在上述场景下，该回调接口无法生效。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名        | 类型                    | 必填  | 说明                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [AccessibilityTransparentCallback](ts-universal-accessibility-hover-event.md#accessibilitytransparentcallback20) | 是   |  提供开启无障碍模式后未能响应的用户输入的触摸事件，当开启无障碍模式后，单指触摸未能响应无障碍悬浮事件位置时触发该回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## AccessibilityTransparentCallback<sup>20+</sup>

type AccessibilityTransparentCallback = (event: TouchEvent) => void

提供开启无障碍模式后未能响应的用户输入的触摸事件。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                | 必填 | 说明                                                         |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event | [TouchEvent](ts-universal-events-touch.md#touchevent对象说明)| 是   | 原始touch事件。 <br/>**说明：** TouchEvent对象的触摸事件的类型[TouchType](ts-appendix-enums.md#touchtype)为四种无障碍悬浮事件类型中的一种，四种无障碍悬浮事件类型为HOVER_ENTER、HOVER_MOVE、HOVER_EXIT和HOVER_CANCEL。

## 示例

### 示例1 (使用onAccessibilityHover事件)

该示例主要演示通过使用onAccessibilityHover事件，对无障碍模式下的按钮进行设置。

```ts
// xxx.ets
@Entry
@Component
struct OnAccessibilityHoverEventExample {
  @State hoverText: string = 'no hover';
  @State color: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Button(this.hoverText)
        .width(180).height(80)
        .backgroundColor(this.color)
        .onAccessibilityHover((isHover: boolean, event: AccessibilityHoverEvent) => {
          // 通过onAccessibilityHover事件动态修改按钮在是否有鼠标悬浮时的文本内容与背景颜色
          if (isHover) {
            this.hoverText = 'hover';
            this.color = Color.Pink;
          } else {
            this.hoverText = 'no hover';
            this.color = Color.Blue;
          }
        })
    }.padding({ top: 30 }).width('100%')
  }
}
```

### 示例2 (捕获无法无障碍聚焦的组件的触摸事件)

该示例代码会在无障碍模式下捕获无法无障碍聚焦的组件的触摸事件，并将事件信息显示在组件下方的文本中。

```ts
@Entry
@Component
struct TestExample {
  @State text: string = '';
  @State eventType: string = '';

  build() {
    Column({ space: 50 }) {
      Column() {
        Button("Test Button")
          .accessibilityLevel("no")
      }.margin({ top: 20 })

      Text(this.text)
    }
    .width('100%')
    .height('100%')
    .onAccessibilityHoverTransparent((event?: TouchEvent) => {
      if (event) {
        if (event.type === TouchType.HOVER_ENTER) {
          this.eventType = 'HOVER_ENTER';
        }
        if (event.type === TouchType.HOVER_MOVE) {
          this.eventType = 'HOVER_MOVE';
        }
        if (event.type === TouchType.HOVER_EXIT) {
          this.eventType = 'HOVER_EXIT';
        }
        if (event.type === TouchType.HOVER_CANCEL) {
          this.eventType = 'HOVER_CANCEL';
        }
        this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
          + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height;
      }
    })
  }
}
```

