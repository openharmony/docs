# @ohos.multimodalInput.gestureEvent (Gesture Event) (System API)

The **gestureEvent** module provides gesture events reported by devices.

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

Defines a touchscreen gesture event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name              | Type                     | Readable| Writable| Description            |
| ------------------ | ------------------------- | ---- | ---- | ---------------- |
| action | [TouchGestureAction](#touchgestureaction18) | Yes  | No  | Enumerates touchscreen gesture types.|
| touches | [Touch](js-apis-touchevent.md#touch)[] | Yes| No| Touch point information.|

## TouchGestureAction<sup>18+</sup>

Enumerates touchscreen gesture types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name           | Value | Description            |
| --------------- | --- | --------------- |
| SWIPE_DOWN | 0   | Multi-finger downward swipe.  |
| SWIPE_UP | 1   | Multi-finger upward swipe.  |
| SWIPE_LEFT | 2   | Multi-finger leftward swipe.  |
| SWIPE_RIGHT | 3   | Multi-finger rightward swipe.  |
| PINCH_CLOSED | 4   | Multi-finger pinch closed.      |
| PINCH_OPENED | 5   | Multi-finger pinch opened.      |
| GESTURE_END | 6   | Gesture ended.      |
