# Class (EventResult)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhanghaozhi1-->
<!--Designer: @dzichou-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

EventResult是ArkWeb Kit中用于通知Web组件同层事件消费结果的类。在同层嵌入场景下，应用与Web组件共同暴露在事件响应链中。EventResult允许应用向Web组件声明自身是否消费了触摸或鼠标事件，从而决定Web组件是否继续处理该事件。当应用设置消费结果为true时，表示应用已消费该事件，Web组件将不再消费；当设置为false时，表示应用不消费该事件，事件将由Web组件消费。EventResult用于设置触摸事件（[TouchType](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype)）和鼠标事件（[MouseAction](../apis-arkui/arkui-ts/ts-appendix-enums.md#mouseaction8)，仅限左中右按键）的消费结果，通过[MouseButton](../apis-arkui/arkui-ts/ts-appendix-enums.md#mousebutton8)定义鼠标按键的类型，适用于应用与Web组件同层交互的事件协调场景。

触摸事件示例代码参考[onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

鼠标事件示例代码参考[onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>12+</sup>

constructor()

EventResult的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean): void

设置手势事件消费结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。<br>传入null或undefined时为true。 |

**示例：**

触摸事件示例代码参考[onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

## setGestureEventResult<sup>14+</sup>

setGestureEventResult(result: boolean, stopPropagation: boolean): void

设置手势事件消费结果和冒泡控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。<br>传入null或undefined时为true。 |
| stopPropagation | boolean  | 是   | 是否阻止冒泡，在result为true时生效。<br>true表示阻止冒泡，false表示不阻止冒泡。<br>传入null或undefined时为true。 |

**示例：**

触摸事件示例代码参考[onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

## setMouseEventResult<sup>20+</sup>

setMouseEventResult(result: boolean, stopPropagation?: boolean): void

设置鼠标事件消费结果和冒泡控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该鼠标事件。<br>true表示消费该鼠标事件，false表示不消费该鼠标事件。 <br>传入null或undefined时为true。|
| stopPropagation | boolean  | 否   | 是否阻止冒泡，在result为true时生效。<br>true表示阻止冒泡，false表示不阻止冒泡。<br>传入null或undefined时为true。<br>默认值：true。 |

**示例：**

鼠标事件示例代码参考[onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。