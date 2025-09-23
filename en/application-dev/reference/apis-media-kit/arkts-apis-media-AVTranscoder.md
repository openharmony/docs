# Interface (AVTranscoder)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

AVTranscoder is a transcoding management class. It provides APIs to transcode videos. Before calling any API in AVTranscoder, you must use [createAVTranscoder()](arkts-apis-media-f.md#mediacreateavtranscoder12) to create an AVTranscoder instance.

For details about the AVTranscoder demo, see [Using AVTranscoder for Transcoding](../../media/media/using-avtranscoder-for-transcodering.md).

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

| Name   | Type                                | Read-Only| Optional| Description              |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| fdSrc<sup>12+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       |  No | No  | Source media file descriptor, which specifies the data source.<br> **Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor { fd = resourceHandle; offset = 0; length = 100; }**.<br>**NOTE**<br> - After the resource handle (FD) is transferred to an AVTranscoder instance, do not use the resource handle to perform other read and write operations, including but not limited to transferring this handle to other AVPlayer, AVMetadataExtractor, AVImageGenerator, or AVTranscoder instance. Competition occurs when multiple AVTranscoders use the same resource handle to read and write files at the same time, resulting in errors in obtaining data.|
| fdDst<sup>12+</sup>                               | number                 |  No | No  | Destination media file descriptor, which specifies the data source. After creating an AVTranscoder instance, you must set both **fdSrc** and **fdDst**.<br>**NOTE**<br> - After the resource handle (FD) is transferred to an AVTranscoder instance, do not use the resource handle to perform other read and write operations, including but not limited to transferring this handle to other AVPlayer, AVMetadataExtractor, AVImageGenerator, or AVTranscoder instance. Competition occurs when multiple AVTranscoders use the same resource handle to read and write files at the same time, resulting in errors in obtaining data.|

## prepare<sup>12+</sup>

prepare(config: AVTranscoderConfig): Promise\<void>

Sets video transcoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name| Type                                  | Mandatory| Description                      |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVTranscoderConfig](arkts-apis-media-i.md#avtranscoderconfig12) | Yes  | Video transcoding parameters to set.<!--RP1--><!--RP1End-->|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401  | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.              |
| 5400105  | Service died. Return by promise.       |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  // Configure the parameters based on those supported by the hardware device.
  let avTranscoderConfig: media.AVTranscoderConfig = {
    audioBitrate : 200000,
    audioCodec : media.CodecMimeType.AUDIO_AAC,
    fileFormat : media.ContainerFormatType.CFT_MPEG_4,
    videoBitrate : 3000000,
    videoCodec : media.CodecMimeType.VIDEO_AVC,
  };

  avTranscoder.prepare(avTranscoderConfig).then(() => {
    console.info('prepare success');
  }).catch((err: BusinessError) => {
    console.error('prepare failed and catch error is ' + err.message);
  });
}
```

## start<sup>12+</sup>

start(): Promise\<void>

Starts transcoding. This API uses a promise to return the result.

This API can be called only after the [prepare()](#prepare12) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.start().then(() => {
    console.info('start AVTranscoder success');
  }).catch((err: BusinessError) => {
    console.error('start AVTranscoder failed and catch error is ' + err.message);
  });
}
```

## pause<sup>12+</sup>

pause(): Promise\<void>

Pauses transcoding. This API uses a promise to return the result.

This API can be called only after the [start()](#start12) API is called. You can call [resume()](#resume12) to resume transcoding.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.pause().then(() => {
    console.info('pause AVTranscoder success');
  }).catch((err: BusinessError) => {
    console.error('pause AVTranscoder failed and catch error is ' + err.message);
  });
}
```

## resume<sup>12+</sup>

resume(): Promise\<void>

Resumes transcoding. This API uses a promise to return the result.

This API can be called only after the [pause()](#pause12) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.resume().then(() => {
    console.info('resume AVTranscoder success');
  }).catch((err: BusinessError) => {
    console.error('resume AVTranscoder failed and catch error is ' + err.message);
  });
}
```

## cancel<sup>12+</sup>

cancel(): Promise\<void>

Cancels transcoding. This API uses a promise to return the result.

This API can be called only after the [prepare()](#prepare12), [start()](#start12), [pause()](#pause12), or [resume()](#resume12) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.cancel().then(() => {
    console.info('cancel AVTranscoder success');
  }).catch((err: BusinessError) => {
    console.error('cancel AVTranscoder failed and catch error is ' + err.message);
  });
}
```

## release<sup>12+</sup>

release(): Promise\<void>

Releases the video transcoding resources. This API uses a promise to return the result.

After the resources are released, you can no longer perform any operation on the AVTranscoder instance.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.release().then(() => {
    console.info('release AVTranscoder success');
  }).catch((err: BusinessError) => {
    console.error('release AVTranscoder failed and catch error is ' + err.message);
  });
}
```

## on('progressUpdate')<sup>12+</sup>

on(type: 'progressUpdate', callback: Callback\<number>): void

Subscribes to transcoding progress updates. An application can subscribe to only one transcoding progress update event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'progressUpdate'** in this case. This event is triggered by the system during transcoding.|
| callback | [Callback\<number>](../apis-basic-services-kit/js-apis-base.md#callback) | Yes  | Callback invoked when the event is triggered. **progress** is a number that indicates the current transcoding progress.|

**Example**

```ts
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.on('progressUpdate', (progress: number) => {
    console.info('avTranscoder progressUpdate = ' + progress);
  });
}
```

## off('progressUpdate')<sup>12+</sup>

off(type:'progressUpdate', callback?: Callback\<number>): void

Unsubscribes from transcoding progress updates.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'progressUpdate'** in this case.|
| callback | [Callback\<number>](../apis-basic-services-kit/js-apis-base.md#callback) | No  | Called that has been registered to listen for progress updates. You are advised to use the default value because only the last registered callback is retained in the current callback mechanism.|

**Example**

```ts
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.off('progressUpdate');
}
```

## on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVTranscoder errors. If this event is reported, call [release()](#release12) to exit the transcoding.

An application can subscribe to only one AVTranscoder error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during recording.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. |
| 801      | Capability not supported. |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.              |
| 5400104  | Time out.            |
| 5400105  | Service died.           |
| 5400106  | Unsupported format.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.on('error', (err: BusinessError) => {
    console.info('case avTranscoder.on(error) called, errMessage is ' + err.message);
  });
}
```

## off('error')<sup>12+</sup>

off(type:'error', callback?: ErrorCallback): void

Unsubscribes from AVTranscoder errors. After the unsubscription, your application can no longer receive AVTranscoder errors.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during transcoding.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback that has been registered to listen for AVTranscoder errors.|

**Example**

```ts
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.off('error');
}
```

## on('complete')<sup>12+</sup>

on(type: 'complete', callback: Callback\<void>): void

Subscribes to the event indicating that transcoding is complete. An application can subscribe to only one transcoding completion event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

When this event is reported, the current transcoding operation is complete. You need to call [release()](#release12) to exit the transcoding.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'complete'** in this case. This event is triggered by the system during transcoding.|
| callback | [Callback\<void>](../apis-basic-services-kit/js-apis-base.md#callback) | Yes  | Callback that has been registered to listen for transcoding completion events.|

**Example**

```ts
import { media } from '@kit.MediaKit';

async function test() {
  let avTranscoder: media.AVTranscoder | undefined = undefined;
  // Create an AVTranscoder instance.
  avTranscoder = await media.createAVTranscoder();
  avTranscoder.on('complete', async () => {
    console.info('avTranscoder complete');
    if (avTranscoder != undefined) {
      // Listen for transcoding completion events.
      // Ensure that avTranscoder.release() has released the AVTranscoder instance before you proceed with forwarding, uploading, or storing the transcoded file.
      await avTranscoder.release();
      avTranscoder = undefined;
    }
  });
}
```

## off('complete')<sup>12+</sup>

off(type:'complete', callback?: Callback\<void>): void

Unsubscribes from the event indicating that transcoding is complete.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'complete'** in this case.|
| callback | [Callback\<void>](../apis-basic-services-kit/js-apis-base.md#callback) | No  | Callback that has been registered to listen for transcoding completion events.|

**Example**

```ts
import { media } from '@kit.MediaKit';

async function test() {
  // Create an AVTranscoder instance.
  let avTranscoder = await media.createAVTranscoder();
  avTranscoder.off('complete');
}
```
