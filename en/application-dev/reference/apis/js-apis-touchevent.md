# Touch Event

Represents touch events reported by an input device.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {Action,ToolType,SourceType,Touch,TouchEvent} from '@ohos.multimodalInput.touchEvent';
```

## Action

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name   | Value | Description |
| ------ | ----- | ----------- |
| CANCEL | 0 | Cancellation of the touch action.|
| DOWN   | 1 | Pressing of touch.               |
| MOVE   | 2 | Moving of touch.                 |
| UP     | 3 | Lifting of touch.                |

## ToolType

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name | Value | Description |
| ---- | ----- | ----------- |
| FINGER | 0 | Finger|
| PEN | 1 | Pen|
| RUBBER | 2 | Eraser|
| BRUSH | 3 | Brush|
| PENCIL | 4 | Pencil|
| AIRBRUSH | 5 | Air brush|
| MOUSE | 6 | Mouse|
| LENS | 7 | Lens|

## SourceType 

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name | Value | Description |
| ---- | ----- | ----------- |
| TOUCH_SCREEN | 0 | Touchscreen|
| PEN          | 1 | Stylus     |
| TOUCH_PAD    | 2 | Touchpad   |

## Touch

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | number | Yes| No| Pointer ID.|
| pressedTime  | number | Yes| No| Time stamp when touch is pressed.|
| screenX | number | Yes| No| X coordinate of the touch position on the screen.|
| screenY | number | Yes| No| Y coordinate of the touch position on the screen.|
| windowX | number | Yes| No| X coordinate of the touch position in the window.|
| windowY | number | Yes| No| Y coordinate of the touch position in the window.|
| pressure | number | Yes| No| Pressure value. The value range is [0.0, 1.0]. The value 0.0 indicates that the pressure is not supported.|
| width | number | Yes| No| Width of the contact area where touch is pressed.|
| height | number | Yes| No| Height of the contact area where touch is pressed.|
| tiltX | number | Yes| No| Angle relative to the YZ plane. The value range is [-90, 90]. A positive value indicates a rightward tilt.|
| tiltY | number | Yes| No| Angle relative to the XZ plane. The value range is [-90, 90]. A positive value indicates a downward tilt.|
| toolX | number | Yes| No| Center point X of the tool area.|
| toolY | number | Yes| No| Center point Y of the tool area.|
| toolWidth | number | Yes| No| Width of the tool area.|
| toolHeight | number | Yes| No| Height of the tool area.|
| rawX | number | Yes| No| X coordinate of the input device.|
| rawY | number | Yes| No| Y coordinate of the input device.|
| toolType | number | Yes| No| Tool type.|

## TouchEvent

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| action | Action | Yes| No| Touch action.|
| touch | Touch | Yes| No| Current touch point.|
| touches | Touch[] | Yes| No| All touch points.|
| sourceType | SourceType | Yes| No| Device type of the touch source.|
