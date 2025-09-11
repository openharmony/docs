# Class (EventResult)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Represents the event consumption result sent to the **Web** component. For details about the supported events, see [TouchType](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype), [MouseAction](../apis-arkui/arkui-ts/ts-appendix-enums.md#mouseaction8), and left, middle, and right buttons in [MouseButton](../apis-arkui/arkui-ts/ts-appendix-enums.md#mousebutton8).

If the application does not consume the event, set the consumption result to **false**, and the event will be consumed by the **Web** component. If the application consumes the event, set the consumption result to **true**, and the **Web** component will not consume the event. If the consumption result is not set according to the preceding specifications, exceptions may occur.

For details about the sample code of the touch event, see [onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11).
For details about the sample code of the mouse event, see [onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>12+</sup>

constructor()

Constructs a **EventResult** object.

**System capability**: SystemCapability.Web.Webview.Core

## setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean): void

Sets the gesture event consumption result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| result          | boolean  | Yes   | Whether to consume the gesture event.<br>The value **true** means to consume the gesture event, and **false** means the opposite. The default value is **true**.|

**Example**

For details, see [onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11).

## setGestureEventResult<sup>14+</sup>

setGestureEventResult(result: boolean, stopPropagation: boolean): void

Sets the gesture event consumption result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| result          | boolean  | Yes   | Whether to consume the gesture event.<br>The value **true** means to consume the gesture event, and **false** means the opposite.<br>The default value is **true**.|
| stopPropagation | boolean  | Yes  | Whether to stop propagation. This parameter is valid only when **result** is set to **true**.<br>The value **true** means to stop propagation, and **false** means the opposite.<br>The default value is **true**.|

**Example**

For details, see [onNativeEmbedGestureEvent](./arkts-basic-components-web-events.md#onnativeembedgestureevent11).

## setMouseEventResult<sup>20+</sup>

setMouseEventResult(result: boolean, stopPropagation?: boolean): void

Sets the mouse event consumption result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| result          | boolean  | Yes   | Whether to consume the mouse event.<br>The value **true** means to consume the mouse event, and **false** means the opposite.<br>The default value is **true**.|
| stopPropagation | boolean  | No  | Whether to stop propagation. This parameter is valid only when **result** is set to **true**.<br>The value **true** means to stop propagation, and **false** means the opposite.<br>The default value is **true**.|

**Example**

For details, see [onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20).
