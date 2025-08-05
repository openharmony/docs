# Class (EventResult)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--SE: @zhufenghao-->
<!--TSE: @ghiker-->

通知Web组件同层事件消费结果，支持的事件：[触摸事件的类型](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype)和[鼠标事件的类型](../apis-arkui/arkui-ts/ts-appendix-enums.md#mouseaction8)，鼠标仅支持[左中右按键](../apis-arkui/arkui-ts/ts-appendix-enums.md#mousebutton8)。

如果应用不消费该事件，则应设置消费结果为false，事件将会被Web组件消费；反之如果应用消费了该事件，则应将消费结果设置为true，Web组件将不消费该事件。若应用设置消费结果不符合以上使用规格，可能将产生和开发者预期不匹配的现象。

触摸事件示例代码参考[onNativeEmbedGestureEvent事件](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。
鼠标事件示例代码参考[onNativeEmbedMouseEvent事件](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

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
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。默认值为true。 |

**示例：**

请参考[onNativeEmbedGestureEvent事件](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

## setGestureEventResult<sup>14+</sup>

setGestureEventResult(result: boolean, stopPropagation: boolean): void

设置手势事件消费结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。<br>默认值为true。 |
| stopPropagation | boolean  | 是   | 是否阻止冒泡，在result为true时生效。<br>true表示阻止冒泡，false表示不阻止冒泡。<br>默认值为true。 |

**示例：**

请参考[onNativeEmbedGestureEvent事件](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

## setMouseEventResult<sup>20+</sup>

setMouseEventResult(result: boolean, stopPropagation?: boolean): void

设置鼠标事件消费结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该鼠标事件。<br>true表示消费该鼠标事件，false表示不消费该鼠标事件。<br>默认值为true。 |
| stopPropagation | boolean  | 否   | 是否阻止冒泡，在result为true时生效。<br>true表示阻止冒泡，false表示不阻止冒泡。<br>默认值为true。 |

**示例：**

请参考[onNativeEmbedMouseEvent事件](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。