# Class (EventResult)

通知Web组件事件消费结果，支持的事件参考[触摸事件的类型](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype)。如果应用不消费该事件，则设置为false，事件被Web组件消费。应用消费了该事件，设置为true，Web组件不消费。示例代码参考[onNativeEmbedGestureEvent事件](./arkts-basic-components-web-events.md#onnativeembedgestureevent11)。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

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