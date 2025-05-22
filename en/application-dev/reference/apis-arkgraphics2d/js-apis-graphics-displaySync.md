#  @ohos.graphics.displaySync (Variable Frame Rate)
The displaySync module allows your application to draw its custom UI content at a specified frame rate.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { displaySync } from '@kit.ArkGraphics2D';
```

## displaySync.create
create(): DisplaySync

Creates a **DisplaySync** object, through which you can set the frame rate of the custom UI content.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [DisplaySync](#displaysync)  | **DisplaySync** object created.              |

**Example**

```ts
let backDisplaySync: displaySync.DisplaySync = displaySync.create();
```
## IntervalInfo

You can obtain the timestamp information from the event callback, including the timestamp when the current frame arrives and the timestamp when the next frame is expected to arrive.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name            | Type                                     | Read-only| Optional| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| timestamp      | number | Yes  | No  | Time when the current frame arrives, in nanoseconds.|
| targetTimestamp | number| Yes  | No  | Expected arrival time of the next frame, in nanoseconds.|

## DisplaySync

 An object that implements the setting of the frame rate and callback. It provides APIs for you to set the frame rate, register a callback, and start/stop the callback.

 Before calling any of the following APIs, you must use [displaySync.create()](#displaysynccreate) to create a **DisplaySync** instance.

### setExpectedFrameRateRange

setExpectedFrameRateRange(rateRange: ExpectedFrameRateRange) : void

Sets the expected frame rate range.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name          | Type                                      | Mandatory| Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| rateRange       | [ExpectedFrameRateRange](../apis-arkui/arkui-ts/ts-explicit-animation.md#expectedframeraterange11)| Yes  | Expected frame rate range.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2.Incorrect parameters types. 3. Parameter verification failed. or check ExpectedFrameRateRange if valid.|

**Example**

```ts
let range : ExpectedFrameRateRange = {
  expected: 10,
  min:0,
  max:120
};

// Set the expected frame rate range.
backDisplaySync?.setExpectedFrameRateRange(range)
```

### on('frame')

on(type: 'frame', callback: Callback\<IntervalInfo\>): void

Subscribes to change events of each frame.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name          | Type                                      | Mandatory| Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| type | 'frame'| Yes  | Event type. The value is fixed at **'frame'**.|
| callback    | Callback<[IntervalInfo](#intervalinfo)>| Yes  | Callback used for subscription.|


**Example**

```ts
let callback = (frameInfo: displaySync.IntervalInfo) => {
    console.info("DisplaySync", 'TimeStamp:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}

// Subscribe to the event.
backDisplaySync?.on("frame", callback)
```

### off('frame')

off(type: 'frame', callback\?: Callback\<IntervalInfo\>): void

Unsubscribes from change events of each frame.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name          | Type                                      | Mandatory| Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| type | 'frame'| Yes  | Event type. The value is fixed at **'frame'**.|
| callback    | Callback<[IntervalInfo](#intervalinfo)>| No  | Callback used for unsubscription. If no value is passed in, all subscriptions to the specified event are canceled.|


**Example**

```ts
let callback = (frameInfo: displaySync.IntervalInfo) => {
    console.info("DisplaySync", 'TimeStamp:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}

backDisplaySync?.on("frame", callback)

// Unsubscribe from the event.
backDisplaySync?.off("frame", callback)
```

### start

start(): void

Starts callback for each frame.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
let range : ExpectedFrameRateRange = {
  expected: 10,
  min:0,
  max:120
};

backDisplaySync?.setExpectedFrameRateRange(range)

let callback = (frameInfo: displaySync.IntervalInfo) => {
    console.info("DisplaySync", 'TimeStamp:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}

backDisplaySync?.on("frame", callback)

// Start callback for each frame.
backDisplaySync?.start()
```

> **NOTE**
>
> The **start()** API associates a **DisplaySync** object with a UI instance and window. If the start operation is performed on a non-UI page or in an asynchronous callback, the context of the current UI may not be obtained, causing the API call to fail and consequently the subscription function to fail. Therefore, you can use [runScopedTask](../apis-arkui/js-apis-arkui-UIContext.md#runscopedtask) of **UIContext** to specify the UI context for executing the **start()** API.

**Example**

```ts
import { displaySync } from '@kit.ArkGraphics2D';
import { UIContext } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct Index {
  // Create a DisplaySync instance.
  backDisplaySync: displaySync.DisplaySync = displaySync.create();

  aboutToAppear() {
    // Obtain a UIContext instance.
    let uiContext: UIContext = this.getUIContext();
    // Call start() in the current UI context.
    uiContext?.runScopedTask(() => {
      this.backDisplaySync?.start();
    })
  }

  build() {
    // ...
  }
}

```

### stop

stop(): void

Stops callback for each frame.


**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Example**

```ts
let range : ExpectedFrameRateRange = {
  expected: 10,
  min:0,
  max:120
};

backDisplaySync?.setExpectedFrameRateRange(range)

let callback = (frameInfo: displaySync.IntervalInfo) => {
    console.info("DisplaySync", 'TimeStamp:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}

backDisplaySync?.on("frame", callback)

backDisplaySync?.start()

// ...

// Stop callback for each frame.
backDisplaySync?.stop()
```
