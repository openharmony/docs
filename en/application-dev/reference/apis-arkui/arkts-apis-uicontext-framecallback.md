# Class (FrameCallback)

Implements the API for setting the task that needs to be executed during the next frame rendering.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - The following APIs must be used in conjunction with [postFrameCallback](arkts-apis-uicontext-uicontext.md#postframecallback12) and [postDelayedFrameCallback](arkts-apis-uicontext-uicontext.md#postdelayedframecallback12) from [UIContext](arkts-apis-uicontext-uicontext.md). Extend this class and override either the [onFrame](#onframe12) or [onIdle](#onidle12) method to implement specific service logic.

## onFrame<sup>12+</sup>

onFrame(frameTimeInNano: number): void

Called when the next frame is rendered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                | Mandatory| Description                                                   |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------------------------- |
| frameTimeInNano | number | Yes  | Time when the rendering of the next frame starts, in nanoseconds.<br>Value range: [0, +∞)|

**Example**

```ts
import { FrameCallback } from '@kit.ArkUI';

class MyFrameCallback extends FrameCallback {
  private tag: string;

  constructor(tag: string) {
    super();
    this.tag = tag;
  }

  onFrame(frameTimeNanos: number) {
    console.info('MyFrameCallback ' + this.tag + ' ' + frameTimeNanos.toString());
  }
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Invoke postFrameCallback')
          .onClick(() => {
            this.getUIContext().postFrameCallback(new MyFrameCallback("normTask"));
          })
        Button('Invoke postDelayedFrameCallback')
          .onClick(() => {
            this.getUIContext().postDelayedFrameCallback(new MyFrameCallback("delayTask"), 5);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## onIdle<sup>12+</sup>

onIdle(timeLeftInNano: number): void

Called after the rendering of the subsequent frame has finished and there is more than 1 millisecond left before the next VSync signal. If the time left is not more than 1 millisecond, the execution of this API will be deferred to a later frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                | Mandatory| Description                                                   |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------------------------- |
| timeLeftInNano | number | Yes  | Remaining idle time for the current frame, in nanoseconds.<br>Value range: [0, +∞)|

**Example**

```ts
import { FrameCallback } from '@ohos.arkui.UIContext';

class MyIdleCallback extends FrameCallback {
  private tag: string;

  constructor(tag: string) {
    super();
    this.tag = tag;
  }

  onIdle(timeLeftInNano: number) {
    console.info('MyIdleCallback ' + this.tag + ' ' + timeLeftInNano.toString());
  }
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Invoke postFrameCallback')
          .onClick(() => {
            this.getUIContext().postFrameCallback(new MyIdleCallback("normTask"));
          })
        Button('Invoke postDelayedFrameCallback')
          .onClick(() => {
            this.getUIContext().postDelayedFrameCallback(new MyIdleCallback("delayTask"), 5);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
