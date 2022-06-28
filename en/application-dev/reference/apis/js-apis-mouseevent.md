# Mouse Event

Represents mouse events reported by an input device.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {Action,Button,Axis,AxisValue,MouseEvent} from '@ohos.multimodalInput.mouseEvent';
```

## Action

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| CANCEL | number | Yes| No| Cancellation of a mouse action.|
| MOVE | number | Yes| No| Moving of the mouse pointer.|
| BUTTON_DOWN | number | Yes| No| Pressing of a mouse button.|
| BUTTON_UP | number | Yes| No| Release of a mouse button.|
| AXIS_BEGIN | number | Yes| No| Beginning of the axis event associated with the mouse.|
| AXIS_UPDATE | number | Yes| No| Updating of the axis event associated with the mouse.|
| AXIS_END | number | Yes| No| Ending of the axis event associated with the mouse.|


## Button

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| LEFT | number | Yes| No| Left button on the mouse.|
| MIDDLE | number | Yes| No| Middle button on the mouse.|
| RIGHT | number | Yes| No| Right button on the mouse.|
| SIDE | number | Yes| No| Side button on the mouse.|
| EXTRA | number | Yes| No| Extended button on the mouse.|
| FORWARD | number | Yes| No| Forward button on the mouse.|
| BACK | number | Yes| No| Back button on the mouse.|
| TASK | number | Yes| No| Task button on the mouse.|

## Axis

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| SCROLL_VERTICAL | number | Yes| No| Vertical scroll axis.|
| SCROLL_HORIZONTAL | number | Yes| No| Horizontal scroll axis.|
| PINCH | number | Yes| No| Pinch axis.|


## AxisValue

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| axis | Axis | Yes| No| Axis type.|
| value | number | Yes| No| Axis value.|


## MouseEvent

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| action | Action | Yes| No| Mouse event action.|
| screenX | number | Yes| No| X coordinate of the mouse pointer on the screen.|
| screenY | number | Yes| No| Y coordinate of the mouse pointer on the screen.|
| windowX | number | Yes| No| X coordinate of the mouse pointer in the window.|
| windowY | number | Yes| No| Y coordinate of the mouse pointer in the window.|
| rawDeltaX | number | Yes| No| X axis offset relative to the previous reported mouse pointer position. When the mouse pointer is at the edge of the screen, the value may be less than the difference of the X coordinate reported twice.|
| rawDeltaY | number | Yes| No| Y axis offset relative to the previous reported mouse pointer position.|
| button | Button | Yes| No| Button that is currently pressed or released.|
| pressedButtons | Button[] | Yes| No| Button that is being pressed.|
| axes | AxisValue[] | Yes| No| All axis data contained in the event.|
| pressedKeys | KeyCode[] | Yes| No| List of pressed keys.|
| ctrlKey | boolean | Yes| No| Whether ctrlKey is being pressed.|
| altKey | boolean | Yes| No| Whether altKey is being pressed.|
| shiftKey | boolean | Yes| No| Whether shiftKey is being pressed.|
| logoKey | boolean | Yes| No| Whether logoKey is being pressed.|
| fnKey | boolean | Yes| No| Whether fnKey is being pressed.|
| capsLock | boolean | Yes| No| Whether capsLock is active.|
| numLock | boolean | Yes| No| Whether numLock is active.|
| scrollLock | boolean | Yes| No| Whether scrollLock is active.|
