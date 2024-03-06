#  @ohos.graphics.displaySync (Variable Frame Rate)
The displaySync module allows your application to draw its custom UI content at a specified frame rate.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import displaySync from '@ohos.graphics.displaySync';
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
private backDisplaySyncBigger: displaySync.DisplaySync = displaySync.create();
```

## IntervalInfo

Defines the interval information.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name            | Type                                     | Read-only| Mandatory| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| timestamp      | number | Yes  | No  | Timestamp of the current frame.|
| targetTimestamp | number| Yes  | No  | Expected timestamp of the next frame.|


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
| rateRange       | [ExpectedFrameRateRange](../arkui-ts/ts-animatorproperty.md#expectedframeraterange)| Yes  | Expected frame rate range.|


**Example**

```ts
let range : ExpectedFrameRateRange = {
  expected: 10,
  min:0,
  max:120
};
this.backDisplaySyncBigger.setExpectedFrameRateRange(range)
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
let _this = this
let bigger = (frameInfo: displaySync.IntervalInfo) => {
_this.drawFirstSize += 1;
    console.info(_this.TAG, 'bigger:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}
this.backDisplaySyncBigger.setExpectedFrameRateRange(range)
this.backDisplaySyncBigger.on("frame", bigger)
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
let _this = this
let bigger = (frameInfo: displaySync.IntervalInfo) => {
_this.drawFirstSize += 1;
    console.info(_this.TAG, 'bigger:' + frameInfo.timestamp + ' TargetTimeStamp: ' + frameInfo.targetTimestamp);
}
this.backDisplaySyncBigger.off("frame", bigger)
```

### start

start(): void

Starts callback for each frame.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
Button('StartBigger')
        .fontSize(30)
        .fontColor(Color.Black)
        .onClick(() => {
          this.backDisplaySyncBigger.start()
        })
```

### stop

stop(): void

Stops callback for each frame.


**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Example**

```ts
Button('StopBigger')
        .fontSize(30)
        .fontColor(Color.Black)
        .onClick(() => {
          this.backDisplaySyncBigger.stop()
        })
```
