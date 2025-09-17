# Interface (AVScreenCaptureRecorder)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

AVScreenCaptureRecorder is a class for screen capture management. It provides APIs for screen capture. Before calling any API in AVScreenCaptureRecorder, you must use [createAVScreenCaptureRecorder()](arkts-apis-media-f.md#mediacreateavscreencapturerecorder12) to create an AVScreenCaptureRecorder instance.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## init<sup>12+</sup>

init(config: AVScreenCaptureRecordConfig): Promise\<void>

Initializes screen capture and sets screen capture parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name| Type                                                        | Mandatory| Description                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| config | [AVScreenCaptureRecordConfig](arkts-apis-media-i.md#avscreencapturerecordconfig12) | Yes  | Screen capture parameters to set.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. Return by promise. |
| 5400103  | IO error. Return by promise.                   |
| 5400105  | Service died. Return by promise.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

public getFileFd(): number {
    let filesDir = '/data/storage/el2/base/haps';
    let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    return file.fd;
}

let avCaptureConfig: media.AVScreenCaptureRecordConfig = {
    fd: this.getFileFd(), // Before passing in an FD to this parameter, the file (generally an MP4 file) must be created by the caller and granted with the write permissions.
    frameWidth: 640,
    frameHeight: 480
    // Add other parameters.
};

avScreenCaptureRecorder.init(avCaptureConfig).then(() => {
    console.info('Succeeded in initing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to init avScreenCaptureRecorder, error: ' + err.message);
});
```

## startRecording<sup>12+</sup>

startRecording(): Promise\<void>

Starts screen capture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                            |
| -------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.startRecording().then(() => {
    console.info('Succeeded in starting avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to start avScreenCaptureRecorder, error: ' + err.message);
});
```

## stopRecording<sup>12+</sup>

stopRecording(): Promise\<void>

Stops screen capture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.stopRecording().then(() => {
    console.info('Succeeded in stopping avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to stop avScreenCaptureRecorder, error: ' + err.message);
});
```

## skipPrivacyMode<sup>12+</sup>

skipPrivacyMode(windowIDs: Array\<number>): Promise\<void>

During screen capture, the application can exempt its privacy windows from security purposes. This API uses a promise to return the result.
For example, if a user enters a password in this application during screen capture, the application will not display a black screen.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| windowIDs | Array\<number> | Yes  | IDs of windows that require privacy exemption, including the main window IDs and subwindow IDs. For details about how to obtain window properties, see [Window API Reference](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9).|

**Return value**

| Type          | Description                            |
| -------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowIDs = [];
avScreenCaptureRecorder.skipPrivacyMode(windowIDs).then(() => {
    console.info('Succeeded in skipping privacy mode');
}).catch((err: BusinessError) => {
    console.info('Failed to skip privacy mode, error: ' + err.message);
});
```

## setMicEnabled<sup>12+</sup>

setMicEnabled(enable: boolean): Promise\<void>

Enables or disables the microphone. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| enable | boolean | Yes  | Whether to enable the microphone. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                                   |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.setMicEnabled(true).then(() => {
    console.info('Succeeded in setMicEnabled avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to setMicEnabled avScreenCaptureRecorder, error: ' + err.message);
});
```

## release<sup>12+</sup>

release(): Promise\<void>

Releases this AVScreenCaptureRecorder instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.release().then(() => {
    console.info('Succeeded in releasing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.error(`Failed to release avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
});
```

## on('stateChange')<sup>12+</sup>

on(type: 'stateChange', callback: Callback\<AVScreenCaptureStateCode>): void

Subscribes to screen capture state changes. An application can subscribe to only one screen capture state change event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case.           |
| callback | function | Yes  | Callback invoked when the event is triggered. [AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12) indicates the new state.|

**Example**

```ts
avScreenCaptureRecorder.on('stateChange', (state: media.AVScreenCaptureStateCode) => {
    console.info('avScreenCaptureRecorder stateChange to ' + state);
});
```

## on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVScreenCaptureRecorder errors. You can handle the errors based on the application logic. An application can subscribe to only one AVScreenCaptureRecorder error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type         | Mandatory| Description                                   |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type, which is **'error'** in this case.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 201      | permission denied.     |
| 5400103  | IO error. Return by ErrorCallback. |
| 5400105  | Service died. Return by ErrorCallback. |

**Example**

```ts
avScreenCaptureRecorder.on('error', (err: BusinessError) => {
    console.error('avScreenCaptureRecorder error:' + err.message);
});
```

## off('stateChange')<sup>12+</sup>

 off(type: 'stateChange', callback?: Callback\<AVScreenCaptureStateCode>): void

Unsubscribes from screen capture state changes. You can specify a callback to cancel the specified subscription.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case.           |
| callback | function | No  | Callback used for unsubscription. [AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12) indicates the new state. If this parameter is not specified, the last subscription is canceled.|

**Example**

```ts
avScreenCaptureRecorder.off('stateChange');
```

## off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from AVScreenCaptureRecorder errors. You can specify a callback to cancel the specified subscription.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                      |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'error'** in this case.               |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used for unsubscription. If this parameter is not specified, the last subscription is canceled.|

**Example**

```ts
avScreenCaptureRecorder.off('error');
```
