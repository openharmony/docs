# @ohos.multimodalInput.gestureEvent (Gesture Input Event) (System API)

The **gestureEvent** module provides APIs for gesture events reported by devices.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import { Touch } from '@kit.InputKit';
```

## TouchGestureEvent

Defines a touchscreen-gesture event.

**System capability**：SystemCapability.MultimodalInput.Input.Core

| Name               | Type                      | Readable | Writable | Description             |
| ------------------ | ------------------------- | -------- | -------- | ----------------------- |
| action | [TouchGestureAction](#touchgestureaction14) | Yes   | No   | The type of touchscreen-gesture. |
| touches | [Touch](js-apis-touchevent.md#touch)[] | Yes | No | The information of touches. |

## TouchGestureAction<sup>14+</sup>

Enumerate touchscreen-gesture types.

**System capability**：SystemCapability.MultimodalInput.Input.Core

| Name            | Value  | Description                |
| --------------- | ------ | -------------------------- |
| SWIPE_DOWN      | 0      | multi-fingers swipe down.  |
| SWIPE_UP        | 1      | multi-fingers swipe up.    |
| SWIPE_LEFT      | 2      | multi-fingers swipe left.  |
| SWIPE_RIGHT     | 3      | multi-fingers swipe right. |
| PINCH_CLOSED    | 4      | multi-fingers pinch close. |
| PINCH_OPENED    | 5      | multi-fingers pinch open.  |
| GESTURE_END     | 6      | End of gesture.            |
