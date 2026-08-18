# 无障碍悬浮事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供无障碍悬浮事件能力。在开启无障碍模式后，Touch事件会转换为无障碍悬浮事件，开发者可通过监听该事件响应无障碍模式下的单指触摸交互，适用于需要为障碍用户提升应用可访问性的场景。该模块提供onAccessibilityHover和onAccessibilityHoverTransparent接口，用于在无障碍模式下监听和处理单指触摸产生的悬浮事件。适用于需要为视障用户提供触摸交互无障碍支持的组件开发场景。开发者可借助该模块捕获无法被无障碍聚焦的组件的Touch事件，提升应用的无障碍访问能力。

>  **说明：**
>
> - 从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 目前仅支持通过开启无障碍模式触发。

## onAccessibilityHover

onAccessibilityHover(callback: AccessibilityCallback): T

开启无障碍模式后，单指触摸绑定该回调的组件时触发该回调。

> **说明：**
>
> 本接口与[onAccessibilityHoverTransparent](#onaccessibilityhovertransparent20)为互补关系：onAccessibilityHover处理可被无障碍识别为可聚焦组件的悬浮事件（回调参数为AccessibilityHoverEvent）；onAccessibilityHoverTransparent处理无法被无障碍识别为可聚焦组件的触摸事件（回调参数为TouchEvent）。同一组件同一时刻仅会触发其中一个回调。若需同时监听两类组件，可将两个接口分别绑定到不同组件上。该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                    | 必填  | 说明                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [AccessibilityCallback](#accessibilitycallback) | 是   |  提供开启无障碍模式后的无障碍悬浮回调事件，当单指触摸绑定该回调的可被无障碍识别为可聚焦的组件时触发该回调。 |

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
| event | [AccessibilityHoverEvent](#accessibilityhoverevent对象说明) | 是   | 无障碍悬浮事件对象，用于获取触发无障碍悬浮事件时的详细信息，包括无障碍悬浮动作类型（type）、手指相对于组件/窗口/屏幕的坐标（x、y、windowX、windowY、displayX、displayY、globalDisplayX、globalDisplayY）等属性。                                   |

## AccessibilityHoverEvent对象说明

继承于[BaseEvent](ts-universal-events-click.md#baseevent8)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型       | 只读 | 可选 | 说明      |
| --------------- | ---------- | ------- | ------- | ------- |
| type             | [AccessibilityHoverType](ts-appendix-enums.md#accessibilityhovertype12) | 否 | 否 | 无障碍悬浮动作类型，包括HOVER_ENTER（手指进入组件）、HOVER_MOVE（手指在组件内移动）、HOVER_EXIT（手指离开组件）和HOVER_CANCEL（悬浮事件被取消）。                |
| x                      | number                         | 否 | 否 | 手指位置相对于当前组件左上角的x轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| y                      | number                         | 否 | 否 | 手指位置相对于当前组件左上角的y轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| windowX                | number                         | 否 | 否 | 手指位置相对于应用窗口左上角的x轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| windowY                | number                         | 否 | 否 | 手指位置相对于应用窗口左上角的y轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| displayX               | number                         | 否 | 否 | 手指位置相对于应用屏幕左上角的x轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| displayY               | number                         | 否 | 否 | 手指位置相对于应用屏幕左上角的y轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br> |
| globalDisplayX<sup>20+</sup> | number                   | 否 | 是 | 手指位置相对于全局屏幕左上角的x轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number                   | 否 | 是 | 手指位置相对于全局屏幕左上角的y轴坐标。<br>单位：vp<br>取值范围：[0, +∞)<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## onAccessibilityHoverTransparent<sup>20+</sup>

onAccessibilityHoverTransparent(callback: AccessibilityTransparentCallback): T

当开启朗读类辅助应用（如屏幕朗读器）且手指触摸在组件区域，同时该组件及子组件全部没有被无障碍悬浮识别为可聚焦时，会触发该回调，并通过回调参数返回该触摸事件对应的TouchEvent。仅支持手指触摸。不支持触摸位置位于以下组件区域内的场景，包括[UIExtension](../../apis-arkui/js-apis-arkui-uiExtension.md)、[Web](../../apis-arkweb/arkts-basic-components-web.md)、<!--Del-->[FormComponent](ts-basic-components-formcomponent-sys.md)、<!--DelEnd-->[XComponent](ts-basic-components-xcomponent.md)，以及与第三方UI框架对接的场景。在上述场景下，该回调接口无法生效。

组件无法被无障碍悬浮识别为可聚焦的主要原因包括，组件的无障碍重要性[accessibilityLevel](ts-universal-attributes-accessibility.md#accessibilitylevel)为"no"或者"no-hide-descendants"；组件无文本且未配置无障碍文本[accessibilityText](ts-universal-attributes-accessibility.md#accessibilitytext)，同时不支持点击或长按操作。

> **说明：**
>
> 本接口与[onAccessibilityHover](#onaccessibilityhover)为互补关系，同一组件同一时刻仅会触发其中一个回调。该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名        | 类型                    | 必填  | 说明                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [AccessibilityTransparentCallback](#accessibilitytransparentcallback20) | 是   |  提供开启朗读类辅助应用后未能响应的用户输入的触摸事件。当手指触摸在组件区域，且该组件及子组件全部没有被无障碍悬浮识别为可聚焦时，触发该回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## AccessibilityTransparentCallback<sup>20+</sup>

type AccessibilityTransparentCallback = (event: TouchEvent) => void

提供开启朗读类辅助应用后未能被无障碍悬浮响应的触摸事件回调类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                | 必填 | 说明                                                         |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event | [TouchEvent](ts-universal-events-touch.md#touchevent对象说明)| 是   | 原始Touch事件对象，用于获取无法被无障碍悬浮识别为可聚焦组件的触摸事件的详细信息，包括触摸点坐标、触摸类型等属性。 <br>**说明：** TouchEvent对象的触摸事件类型[TouchType](ts-appendix-enums.md#touchtype)为四种无障碍悬浮事件类型中的一种，分别为HOVER_ENTER、HOVER_MOVE、HOVER_EXIT和HOVER_CANCEL。 |

## 示例

### 示例1 (使用onAccessibilityHover事件)

该示例主要演示使用onAccessibilityHover事件，对无障碍模式下的按钮进行设置。

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
        .onAccessibilityHover((isHover: boolean) => {
          // 通过onAccessibilityHover事件动态修改按钮在无障碍悬浮（手指触摸进入/退出）时的文本内容与背景颜色
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

该示例代码在无障碍模式下通过onAccessibilityHoverTransparent接口捕获无法无障碍聚焦的组件的触摸事件，最后再将事件信息显示在组件下方的文本中。

从API version 20开始，新增了入参类型为AccessibilityTransparentCallback的[onAccessibilityHoverTransparent](#onaccessibilityhovertransparent20)接口。

```ts
@Entry
@Component
struct OnAccessibilityHoverTransparentExample {
  @State text: string = '';
  @State eventType: string = '';

  build() {
    Column({ space: 50 }) {
      Column() {
        Button('Test Button')
          .accessibilityLevel('no')
      }.margin({ top: 20 })

      Text(this.text)
    }
    .width('100%')
    .height('100%')
    .onAccessibilityHoverTransparent((event: TouchEvent) => {
      if (event) {
        // 手指按下触发
        if (event.type === TouchType.HOVER_ENTER) {
          this.eventType = 'HOVER_ENTER';
        }
        // 触摸移动时触发
        if (event.type === TouchType.HOVER_MOVE) {
          this.eventType = 'HOVER_MOVE';
        }
        // 抬手时触发
        if (event.type === TouchType.HOVER_EXIT) {
          this.eventType = 'HOVER_EXIT';
        }
        // 取消当前触发事件
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

