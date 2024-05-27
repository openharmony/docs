# @ohos.multimodalInput.inputEvent (Input Event)

The **inputEvent** module provides the basic events reported by the device.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import InputEvent from '@kit.InputKit.d.ts';
```

## InputEvent 

Represents an input event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name        | Type  | Readable  | Writable  | Description            |
| ---------- | ------ | ---- | ---- | -------------- |
| id         | number | Yes   | No   | Event ID.|
| deviceId   | number | Yes   | No   | ID of the device that reports the input event.   |
| actionTime | number | Yes   | No   | Time when the input event is reported.     |
| screenId   | number | Yes   | No   | ID of the target screen.        |
| windowId   | number | Yes   | No   | ID of the target window.        |
