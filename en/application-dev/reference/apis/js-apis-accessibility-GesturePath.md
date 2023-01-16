# @ohos.accessibility.GesturePath

 The **GesturePath** module provides APIs for creating gesture path information required for an accessibility application to inject gestures.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import GesturePath from '@ohos.accessibility.GesturePath';
```

## GesturePath

Defines a gesture path.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name          | Type                                    | Readable  | Writable  | Description    |
| ------------ | ---------------------------------------- | ---- | ---- | ------ |
| points       | Array&lt;[GesturePoint](js-apis-accessibility-GesturePoint.md#gesturepoint)&gt; | Yes   | Yes   | Gesture touch point.   |
| durationTime | number                                   | Yes   | Yes   | Total gesture duration, in milliseconds.|

### constructor

constructor(durationTime: number);

Constructor used to create a **GesturePath** object.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| durationTime | number | Yes| Total gesture duration, in milliseconds.|

**Example**

```ts
let gesturePath = new GesturePath.GesturePath(20);
```
