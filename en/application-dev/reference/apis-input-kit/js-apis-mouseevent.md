# @ohos.multimodalInput.mouseEvent (Mouse Event)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

The **mouseEvent** module provides mouse events reported by a device. It is inherited from [InputEvent](./js-apis-inputevent.md).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { MouseAction, Button, Axis, AxisValue, MouseToolType, MouseEvent } from '@kit.InputKit';
```

## Action

Enumerates mouse event types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Value| Description                |
| ----------- | -------- | -------------------- |
| CANCEL      | 0   | Canceled. The down event of the mouse is interrupted unexpectedly and does not close normally. For example, the **CANCEL** event is triggered when the mouse button is pressed but not released, the window transitions to the background, or an abnormal destruction occurs.|
| MOVE        | 1   | Moving of the mouse pointer.            |
| BUTTON_DOWN | 2   | Mouse button press.        |
| BUTTON_UP   | 3   | Mouse button release.        |
| AXIS_BEGIN  | 4   | Beginning of the mouse axis event.|
| AXIS_UPDATE | 5   | Updating of the mouse axis event.|
| AXIS_END    | 6   | Mouse axis event ended.|
| ACTION_DOWN<sup>11+</sup> | 7   | Touchpad press.|
| ACTION_UP<sup>11+</sup> | 8   | Touchpad release.|

## Button

Enumerates mouse buttons.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name     | Value | Description   |
| ------- | ------| ----- |
| LEFT    | 0 | Left button. |
| MIDDLE  | 1 | Middle button. |
| RIGHT   | 2 | Right button |
| SIDE    | 3 | Side button.|
| EXTRA   | 4 | Extended button.|
| FORWARD | 5 | Forward button.|
| BACK    | 6 | Back button.|
| TASK    | 7 | Task button.|

## Axis

Enumerates mouse axis types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name               | Value    | Description   |
| ----------------- | ------- | ----- |
| SCROLL_VERTICAL   | 0 | Vertical scroll axis of the mouse.|
| SCROLL_HORIZONTAL | 1 | Horizontal scroll axis of the mouse.|
| PINCH             | 2 | Pinch axis of the mouse.  |


## AxisValue

Defines the mouse axis type and axis value.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name   | Type  | Read-Only  | Optional  | Description  |
| ----- | ------ | ---- | ---- | ---- |
| axis  | [Axis](#axis)   | No   | No   | Enumerates mouse axis types. |
| value | number | No   | No   | Mouse axis value. |

## ToolType<sup>11+</sup>

Enumerates tool types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name     | Value | Description   |
| ------- | ------| ----- |
| UNKNOWN | 0 | Unknown type. |
| MOUSE  | 1 | Mouse.|
| JOYSTICK | 2 | Joystick.|
| TOUCHPAD | 3 | Touchpad.|

## MouseEvent

Defines the mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Read-Only  | Optional  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| action         | [Action](#action)      | No   | No   | Enumerates mouse event types.                        |
| screenX        | number      | No   | No   | X coordinate of the mouse event in the relative coordinate system with the upper-left corner of the specified screen as the origin. Currently, only integers are supported. The unit is pixels.|
| screenY        | number      | No   | No   | Y coordinate of the mouse event in the relative coordinate system with the upper-left corner of the specified screen as the origin. Currently, only integers are supported. The unit is pixels.|
| windowX        | number      | No   | No   | X coordinate in the relative coordinate system with the upper-left corner of the window where the mouse is located as the origin. Currently, only integers are supported. The unit is pixels.|
| windowY        | number      | No   | No   | Y coordinate in the relative coordinate system with the upper-left corner of the window where the mouse is located as the origin. Currently, only integers are supported. The unit is pixels.|
| rawDeltaX      | number      | No   | No   | X coordinate offset of the current mouse event relative to the last event. Currently, only integers are supported. The unit is pixels.|
| rawDeltaY      | number      | No   | No   | Y coordinate offset of the current mouse event relative to the last event. Currently, only integers are supported. The unit is pixels.|
| button         | [Button](#button)      | No   | No   | Enumerates mouse buttons.                      |        
| pressedButtons | [Button](#button)[]    | No   | No   | Button being pressed.                             |
| axes           | [AxisValue](#axisvalue)[] | No   | No   | Defines the mouse axis type and axis value.                              |
| pressedKeys    | [KeyCode](js-apis-keycode.md#keycode)[]   | No   | No   | List of pressed keys.                           |
| ctrlKey        | boolean     | No   | No   | Whether ctrlKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.   |
| altKey         | boolean     | No   | No   | Whether altKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                        |
| shiftKey       | boolean     | No   | No   | Whether shiftKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                      |
| logoKey        | boolean     | No   | No   | Whether logoKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                       |
| fnKey          | boolean     | No   | No   | Whether fnKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                         |
| capsLock       | boolean     | No   | No   | Whether capsLock is enabled.<br>The value **true** indicates that capsLock is enabled, and the value **false** indicates the opposite. |
| numLock        | boolean     | No   | No   | Whether numLock is enabled.<br>The value **true** indicates that numLock is enabled, and the value **false** indicates the opposite.                       |
| scrollLock     | boolean     | No   | No   | Whether scrollLock is enabled.<br>The value **true** indicates that scrollLock is enabled, and the value **false** indicates the opposite.                    |
| toolType<sup>11+</sup> | [ToolType](#tooltype11) | No   | No   | Tool type.                    |
| globalX<sup>20+</sup> | number | No   | Yes   | X coordinate of the mouse event in the global coordinate system with the upper-left corner of the primary screen as the origin, in px. <!--Del-->When being used as an input parameter, this parameter is mandatory if the value of [MouseEventData.useGlobalCoordinate](./js-apis-inputeventclient-sys.md#mouseeventdata11) is **true**, and its value can only be an integer. Otherwise, you do not need to set this parameter. In this case, the X coordinate of the relative coordinate system with the upper left corner of the specified screen as the origin is used to calculate the injected event. <!--DelEnd-->When being used as an output parameter, its value is reported by the system.|
| globalY<sup>20+</sup> | number | No   | Yes   | Y coordinate of the mouse event in the global coordinate system with the upper-left corner of the primary screen as the origin, in px. <!--Del--> When being used as an input parameter, this parameter is mandatory if the value of [MouseEventData.useGlobalCoordinate](./js-apis-inputeventclient-sys.md#mouseeventdata11) is **true**, and its value can only be an integer. Otherwise, you do not need to set this parameter. In this case, the Y coordinate of the relative coordinate system with the upper left corner of the specified screen as the origin is used to calculate the injected event. <!--DelEnd-->When being used as an output parameter, its value is reported by the system.|
