# @ohos.accessibility.GesturePath (Gesture Path)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

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

| Name          | Type                                                                         | Read-Only  | Optional  | Description    |
| ------------ |---------------------------------------------------------------------------------| ---- | ---- | ------ |
| points       | Array&lt;[GesturePoint](js-apis-accessibility-GesturePoint.md#gesturepoint)&gt; | No   | No   | Gesture touch point.   |
| durationTime | number                                                                          | No   | No   | Total gesture duration, in milliseconds.|

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
