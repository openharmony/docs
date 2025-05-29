# @ohos.multimodalInput.mouseEvent (Mouse Event)

The **mouseEvent** module provides mouse events reported by a device. It is inherited from [InputEvent](./js-apis-inputevent.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { Action, Button, Axis, AxisValue, MouseEvent } from '@kit.InputKit';
```

## Action

Enumerates mouse event types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Value| Description                |
| ----------- | -------- | -------------------- |
| CANCEL      | 0   | Canceled.            |
| MOVE        | 1   | Moving of the mouse pointer.            |
| BUTTON_DOWN | 2   | Pressing of a mouse button.        |
| BUTTON_UP   | 3   | Release of a mouse button.        |
| AXIS_BEGIN  | 4   | Beginning of the mouse axis event.|
| AXIS_UPDATE | 5   | Updating of the mouse axis event.|
| AXIS_END    | 6   | Mouse axis event ended.|
| ACTION_DOWN<sup>11+</sup> | 7   | Finger pressing on the touchpad.|
| ACTION_UP<sup>11+</sup> | 8   | Finger lift from the touchpad.|

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
| SCROLL_VERTICAL   | 0 | Vertical scroll axis.|
| SCROLL_HORIZONTAL | 1 | Horizontal scroll axis.|
| PINCH             | 2 | Pinch axis.  |


## AxisValue

Defines the mouse axis type and axis value.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name   | Type  | Readable  | Writable  | Description  |
| ----- | ------ | ---- | ---- | ---- |
| axis  | [Axis](#axis)   | Yes   | No   | Axis type. |
| value | number | Yes   | No   | Axis value. |

## ToolType<sup>11+</sup>

Enumerates tool types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name     | Value | Description   |
| ------- | ------| ----- |
| UNKNOWN<sup>11+</sup> | 0 | Unknown type. |
| MOUSE<sup>11+</sup>  | 1 | Mouse.|
| JOYSTICK<sup>11+</sup> | 2 | Joystick.|
| TOUCHPAD<sup>11+</sup> | 3 | Touchpad.|

## MouseEvent

Defines the mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| action         | [Action](#action)      | Yes   | No   | Enumerates mouse event actions.                                  |
| screenX        | number      | Yes   | No   | Horizontal coordinate of the mouse pointer on the screen.                            |
| screenY        | number      | Yes   | No   | Vertical coordinate of the mouse pointer on the screen.                            |
| windowX        | number      | Yes   | No   | Horizontal coordinate of the mouse pointer in the window.                              |
| windowY        | number      | Yes   | No   | Vertical coordinate of the mouse pointer in the window.                              |
| rawDeltaX      | number      | Yes   | No   | Horizontal coordinate offset relative to the previous reported mouse pointer position.|
| rawDeltaY      | number      | Yes   | No   | Vertical coordinate offset relative to the previous reported mouse pointer position.                         |
| button         | [Button](#button)      | Yes   | No   | Mouse button.                      |        
| pressedButtons | [Button](#button)[]    | Yes   | No   | Button being pressed.                             |
| axes           | [AxisValue](#axisvalue)[] | Yes   | No   | All axis data contained in the event.                              |
| pressedKeys    | [KeyCode](js-apis-keycode.md#keycode)[]   | Yes   | No   | List of pressed keys.                           |
| ctrlKey        | boolean     | Yes   | No   | Whether ctrlKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.   |
| altKey         | boolean     | Yes   | No   | Whether altKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                        |
| shiftKey       | boolean     | Yes   | No   | Whether shiftKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                      |
| logoKey        | boolean     | Yes   | No   | Whether logoKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                       |
| fnKey          | boolean     | Yes   | No   | Whether fnKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.                         |
| capsLock       | boolean     | Yes   | No   | Whether capsLock is active.<br>The value **true** indicates that capsLock is active, and the value **false** indicates the opposite. |
| numLock        | boolean     | Yes   | No   | Whether numLock is active.<br>The value **true** indicates that numLock is active, and the value **false** indicates the opposite.                       |
| scrollLock     | boolean     | Yes   | No   | Whether scrollLock is active.<br>The value **true** indicates that scrollLock is active, and the value **false** indicates the opposite.                    |
| toolType<sup>11+</sup> | [ToolType](#tooltype11) | Yes   | No   | Tool type.                    |
