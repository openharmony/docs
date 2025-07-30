# @ohos.accessibility.GesturePoint (Gesture Point)

The **GesturePoint** module provides APIs for creating gesture touch point information required for an accessibility application to inject gestures.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { GesturePoint } from '@kit.AccessibilityKit';
```

## GesturePoint

Defines a gesture touch point.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| positionX | number | Yes   | Yes   | X coordinate of the touch point.|
| positionY | number | Yes   | Yes   | Y coordinate of the touch point.|

### constructor<sup>(deprecated)</sup>

constructor(positionX: number, positionY: number);

A constructor used to create a **GesturePoint** instance.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| positionX | number | Yes| X coordinate of the touch point.|
| positionY | number | Yes | Y coordinate of the touch point.|

**Example**

```ts
import { GesturePoint } from '@kit.AccessibilityKit';

let gesturePoint = new GesturePoint(1, 2);
```
