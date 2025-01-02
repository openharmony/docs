# @ohos.multimodalInput.gestureEvent (Gesture Input Event)

The **gestureEvent** module provides APIs for gesture events reported by devices.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { Rotate, Pinch, ThreeFingersSwipe, FourFingersSwipe, ActionType } from '@kit.InputKit';
```

## Pinch

Defines a pinch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| type         | [ActionType](#actiontype)   | Yes   | No   | Pinch event type.                                  |
| scale        | number      | Yes   | No   | Pinch scale factor. The value is greater than or equal to 0.                            |

## Rotate<sup>11+</sup>

Defines a rotate event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| type | [ActionType](#actiontype)   | Yes   | No   | Rotate event type.                                  |
| angle | number      | Yes   | No   | Angle of rotation.                            |

## ThreeFingersSwipe

Defines a three-finger swipe event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| type         | [ActionType](#actiontype)   | Yes   | No   | Three-finger swipe event type.                                  |
| x        | number      | Yes   | No   | X coordinate.                            |
| y        | number      | Yes   | No   | Y coordinate.                            |

## FourFingersSwipe

Defines a four-finger swipe event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name            | Type       | Readable  | Writable  | Description                                      |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| type         | [ActionType](#actiontype)   | Yes   | No   | Four-finger swipe event type.                                  |
| x        | number      | Yes   | No   | X coordinate.                            |
| y        | number      | Yes   | No   | Y coordinate.                            |

## ThreeFingersTap<sup>11+</sup>

Defines a three-finger tap event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name              | Type                     | Readable| Writable| Description            |
| ------------------ | ------------------------- | ---- | ---- | ---------------- |
| type | [ActionType](#actiontype) | Yes  | No  | Three-finger tap event type.|

## ActionType

Enumerates gesture event types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Value | Description            |
| ----------- | --- | --------------- |
| CANCEL      | 0   | Canceled.            |
| BEGIN       | 1   | Started.        |
| UPDATE      | 2   | Updated.        |
| END         | 3   | Ended.        |
