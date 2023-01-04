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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| CANCEL | number | Yes| No| Cancellation of the touch action.|
| DOWN | number | Yes| No| Pressing of touch.|
| MOVE | number | Yes| No| Moving of touch.|
| UP | number | Yes| No| Lifting of touch.|

## ToolType

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| FINGER | number | Yes| No| Finger|
| PEN | number | Yes| No| Pen|
| RUBBER | number | Yes| No| Eraser|
| BRUSH | number | Yes| No| Brush|
| PENCIL | number | Yes| No| Pencil|
| AIRBRUSH | number | Yes| No| Air brush|
| MOUSE | number | Yes| No| Mouse|
| LENS | number | Yes| No| Lens|

## SourceType 

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| TOUCH_SCREEN | number | Yes| No| Touchscreen|
| PEN | number | Yes| No| Stylus|
| TOUCH_PAD | number | Yes| No| Touchpad|

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
| toolType | ToolType | Yes| No| Tool type.|

## TouchEvent

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| action | Action | Yes| No| Touch action.|
| touch | Touch | Yes| No| Current touch point.|
| touches | Touch[] | Yes| No| All touch points.|
| sourceType | SourceType | Yes| No| Device type of the touch source.|
