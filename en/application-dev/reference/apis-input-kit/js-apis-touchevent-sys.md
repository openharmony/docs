# @ohos.multimodalInput.touchEvent (Touch Event) (System API)

The **touchEvent** module provides screen touch events reported by a device. It is inherited from [InputEvent](./js-apis-inputevent.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.multimodalInput.touchEvent (Touch Event)](js-apis-touchevent.md).

## Modules to Import

```js
import { FixedMode, Touch, TouchEvent } from '@kit.InputKit';
```

## FixedMode

Enumerates coordinate correction modes. This API takes effect only for mobile phones.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**System API**: This is a system API.

| Name         | Value | Description  |
| ------------ | ------ | ---- |
| NONE       |  0 | Normal mode.|
| AUTO |  1 | One-handed mode.|

## Touch

Defines the touch point information.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**System API**: This is a system API.

| Name         | Type  | Read-Only  | Optional  | Description                                 |
| ----------- | ------ | ---- | ---- | ----------------------------------- |
| fixedDisplayX | number| No   | Yes   | **screenX** correction value in one-handed mode.<br> **NOTE**: This API takes effect only for mobile phones.|
| fixedDisplayY | number| No   | Yes   | **screenY** correction value in one-handed mode.<br> **NOTE**: This API takes effect only for mobile phones.   |

## TouchEvent

Defines a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**System API**: This is a system API.

| Name        | Type      | Read-Only  | Optional  | Description       |
| ---------- | ---------- | ---- | ---- | --------- |
| fixedMode  | [FixedMode](#fixedmode)   | No   | Yes   | Defines the coordinate correction mode.<br> **NOTE**: This API takes effect only for mobile phones.|
| isInject<sup>20+</sup>  | boolean   | No   | Yes   | Whether the touch event is an injection event. For details about injection events, see [@ohos.multimodalInput.inputEventClient](js-apis-inputeventclient-sys.md).<br> **NOTE**: This API takes effect only for mobile phones.|
