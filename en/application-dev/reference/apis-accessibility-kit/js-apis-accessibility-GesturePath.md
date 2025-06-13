# @ohos.accessibility.GesturePath (Gesture Path)

The **GesturePath** module provides APIs for creating gesture path information required for an accessibility application to inject gestures.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { GesturePath } from '@kit.AccessibilityKit';
```

## GesturePath

Defines a gesture path.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Properties

| Name          | Type                                                                             | Readable  | Writable  | Description    |
| ------------ |---------------------------------------------------------------------------------| ---- | ---- | ------ |
| points       | Array&lt;[GesturePoint](js-apis-accessibility-GesturePoint.md#gesturepoint)&gt; | Yes   | Yes   | Gesture touch point.   |
| durationTime | number                                                                          | Yes   | Yes   | Total gesture duration, in milliseconds.|

### constructor<sup>(deprecated)</sup>

constructor(durationTime: number);

A constructor used to create a **GesturePath** instance.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| durationTime | number | Yes| Total gesture duration, in milliseconds.|

**Example**

```ts
import { GesturePath } from '@kit.AccessibilityKit';

let gesturePath = new GesturePath(20);
```
