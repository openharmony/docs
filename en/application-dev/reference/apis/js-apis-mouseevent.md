# Mouse Event

Represents mouse events reported by an input device.

>  **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {Action,Button,Axis,AxisValue,MouseEvent} from '@ohos.multimodalInput.mouseEvent';
```

## Action

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Value| Description                |
| ----------- | -------- | -------------------- |
| CANCEL      | 0   | Cancellation of a mouse action.            |
| MOVE        | 1   | Moving of the mouse pointer.            |
| BUTTON_DOWN | 2   | Pressing of a mouse button.        |
| BUTTON_UP   | 3   | Release of a mouse button.        |
| AXIS_BEGIN  | 4   | Beginning of the axis event associated with the mouse.|
| AXIS_UPDATE | 5   | Updating of the axis event associated with the mouse.|
| AXIS_END    | 6   | Ending of the axis event associated with the mouse.|


## Button

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name     | Value | Description   |
| ------- | ------| ----- |
| LEFT    | 0 | Left button on the mouse. |
| MIDDLE  | 1 | Middle button on the mouse. |
| RIGHT   | 2 | Right button on the mouse. |
| SIDE    | 3 | Side button on the mouse.|
| EXTRA   | 4 | Extended button on the mouse.|
| FORWARD | 5 | Forward button on the mouse.|
| BACK    | 6 | Back button on the mouse.|
| TASK    | 7 | Task button on the mouse.|

## Axis

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name               | Value    | Description   |
| ----------------- | ------- | ----- |
| SCROLL_VERTICAL   | 0 | Vertical scroll axis.|
| SCROLL_HORIZONTAL | 1 | Horizontal scroll axis.|
| PINCH             | 2 | Pinch axis.  |


## AxisValue

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name   | Type  | Readable  | Writable  | Description  |
| ----- | ------ | ---- | ---- | ---- |
| axis  | Axis   | Yes   | No   | Axis type. |
| value | number | Yes   | No   | Axis value. |


## MouseEvent

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| action         | Action      | Yes   | No   | Mouse event action.                                  |
| screenX        | number      | Yes   | No   | Horizontal coordinate of the mouse pointer on the screen.                            |
| screenY        | number      | Yes   | No   | Vertical coordinate of the mouse pointer on the screen.                            |
| windowX        | number      | Yes   | No   | Horizontal coordinate of the mouse pointer in the window.                              |
| windowY        | number      | Yes   | No   | Vertical coordinate of the mouse pointer in the window.                              |
| rawDeltaX      | number      | Yes   | No   | Horizontal coordinate offset relative to the previous reported mouse pointer position.|
| rawDeltaY      | number      | Yes   | No   | Vertical coordinate offset relative to the previous reported mouse pointer position.                         |
| button         | Button      | Yes   | No   | Mouse button                              
| pressedButtons | Button[]    | Yes   | No   | Button being pressed.                             |
| axes           | AxisValue[] | Yes   | No   | All axis data contained in the event.                              |
| pressedKeys    | KeyCode[]   | Yes   | No   | List of pressed keys.                           |
| ctrlKey        | boolean     | Yes   | No   | Whether ctrlKey is being pressed.                       |
| altKey         | boolean     | Yes   | No   | Whether altKey is being pressed.                        |
| shiftKey       | boolean     | Yes   | No   | Whether shiftKey is being pressed.                      |
| logoKey        | boolean     | Yes   | No   | Whether logoKey is being pressed.                       |
| fnKey          | boolean     | Yes   | No   | Whether fnKey is being pressed.                         |
| capsLock       | boolean     | Yes   | No   | Whether capsLock is active.                      |
| numLock        | boolean     | Yes   | No   | Whether numLock is active.                       |
| scrollLock     | boolean     | Yes   | No   | Whether scrollLock is active.                    |
