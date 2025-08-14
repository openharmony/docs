# ringtonePlayer (Ringtone Player) (System API)

The ringtonePlayer module provides APIs for playing, configuring, and obtaining ringtones.

This module must work with [@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager-sys.md) to manage ringtones.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## RingtoneOptions

Enumerates the ringtone parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name     | Type           |Mandatory  | Description                             |
| --------- | -------------- | ---- | --------------------------------- |
| volume    | number         | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|
| loop      | boolean        | Yes  | Whether to enable loop playback. The value **true** means to enable loop playback, and **false** means the opposite.|

## RingtonePlayer

Provides APIs for setting and obtaining ringtone parameters as well as playing and stopping ringtones. Before calling any API in RingtonePlayer, you must use [getRingtonePlayer](./js-apis-systemSoundManager-sys.md#getringtoneplayer11) to obtain a RingtonePlayer instance.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name | Type                       | Read-Only| Optional| Description              |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state | [media.AVPlayerState](../apis-media-kit/arkts-apis-media-t.md#avplayerstate9) | Yes  | No  | Audio renderer state.|

**Example**

```ts
import { media } from '@kit.MediaKit';
let state: media.AVPlayerState = systemRingtonePlayer.state;
```

### getTitle

getTitle(callback: AsyncCallback&lt;string&gt;): void

Obtains the title of the ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| callback | AsyncCallback&lt;string&gt;              | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the title obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.getTitle((err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to get system ringtone title. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the system ringtone title is obtained ${value}.`);
});
```

### getTitle

getTitle(): Promise&lt;string&gt;

Obtains the title of the ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type                 | Description                             |
| --------------------- | -------------------------------- |
| Promise&lt;string&gt; | Promise used to return the title obtained.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.getTitle().then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system ringtone title is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system ringtone title ${err}`);
});
```

### getAudioRendererInfo

getAudioRendererInfo(callback: AsyncCallback&lt;audio.AudioRendererInfo&gt;): void

Obtains the information about the audio renderer used by the ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| callback | AsyncCallback&lt;[audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the renderer information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioRendererInfo: audio.AudioRendererInfo | undefined = undefined;

systemRingtonePlayer.getAudioRendererInfo((err: BusinessError, value: audio.AudioRendererInfo) => {
  if (err) {
    console.error(`Failed to get ringtone AudioRendererInfo. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate the value of the ringtone AudioRendererInfo is obtained.`);
  audioRendererInfo = value;
});
```

### getAudioRendererInfo

getAudioRendererInfo(): Promise&lt;audio.AudioRendererInfo&gt;

Obtains the information about the audio renderer used by the ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;[audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)&gt; | Promise used to return the renderer information.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioRendererInfo: audio.AudioRendererInfo | undefined = undefined;

systemRingtonePlayer.getAudioRendererInfo().then((value: audio.AudioRendererInfo) => {
  console.info(`Promise returned to indicate that the value of the ringtone AudioRendererInfo is obtained ${value}.`);
  audioRendererInfo = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the ringtone AudioRendererInfo ${err}`);
});
```

### configure

configure(options: RingtoneOptions, callback: AsyncCallback&lt;void&gt;): void

Sets ringtone parameters. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| options  | [RingtoneOptions](#ringtoneoptions)      | Yes  | Ringtone parameters.            |
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class RingtoneOptions {
  volume: number = 0;
  loop: boolean = false;
}
let ringtoneOptions: RingtoneOptions = {volume: 0.5, loop: true};

systemRingtonePlayer.configure(ringtoneOptions, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to configure ringtone options. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful setting of ringtone options.`);
});
```

### configure

configure(options: RingtoneOptions): Promise&lt;void&gt;

Sets ringtone parameters. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| options  | [RingtoneOptions](#ringtoneoptions)      | Yes  | Ringtone parameters.             |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class RingtoneOptions {
  volume: number = 0;
  loop: boolean = false;
}
let ringtoneOptions: RingtoneOptions = {volume: 0.5, loop: true};

systemRingtonePlayer.configure(ringtoneOptions).then(() => {
  console.info(`Promise returned to indicate a successful setting of ringtone options.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to configure ringtone options. ${err}`);
});
```

### start

start(callback: AsyncCallback&lt;void&gt;): void

Starts playing the ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.start((err: BusinessError) => {
  if (err) {
    console.error(`Failed to start playing ringtone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful starting of ringtone.`);
});
```

### start

start(): Promise&lt;void&gt;

Starts playing the ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.start().then(() => {
  console.info(`Promise returned to indicate a successful starting of ringtone.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start playing ringtone. ${err}`);
});
```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

Stops playing the ringtone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.stop((err: BusinessError) => {
  if (err) {
    console.error(`Failed to stop playing ringtone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful stopping of ringtone.`);
});
```

### stop

stop(): Promise&lt;void&gt;

Stops playing the ringtone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.stop().then(() => {
  console.info(`Promise returned to indicate a successful stopping of ringtone.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop playing ringtone. ${err}`);
});
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

Releases the ringtone player. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | -----------------------------------------| ---- | ------------------------- |
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release ringtone player. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate a successful releasing of ringtone player.`);
});
```

### release

release(): Promise&lt;void&gt;

Releases the ringtone player. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemRingtonePlayer.release().then(() => {
  console.info(`Promise returned to indicate a successful releasing of ringtone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release ringtone player. ${err}`);
});
```

### on('audioInterrupt')

on(type: 'audioInterrupt', callback: Callback&lt;audio.InterruptEvent&gt;): void

Subscribes to the audio interruption event, which is triggered when the audio focus is changed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                                      |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The event **'audioInterrupt'** is triggered when the audio focus is changed.|
| callback | Callback&lt;[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)&gt; | Yes  | Callback used to return the event information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // An identifier specifying whether rendering is in progress.
let isDucked: boolean; // An identifier specifying whether the audio volume is reduced.

systemRingtonePlayer.on('audioInterrupt', async(interruptEvent: audio.InterruptEvent) => {
  if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
    // The system forcibly interrupts audio rendering. The application must update the status and displayed content accordingly.
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
        // The audio stream has been paused and temporarily loses the focus. It will receive the interruptEvent corresponding to resume when it is able to regain the focus.
        console.info('Force paused. Update playing status and stop writing');
        isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_STOP:
        // The audio stream has been stopped and permanently loses the focus. The user must manually trigger the operation to resume rendering.
        console.info('Force stopped. Update playing status and stop writing');
        isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_DUCK:
        // The audio stream is rendered at a reduced volume.
        console.info('Force ducked. Update volume status');
        isDucked = true; // A simplified processing indicating several operations for updating the volume status.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
        // The audio stream is rendered at the normal volume.
        console.info('Force ducked. Update volume status');
        isDucked = false; // A simplified processing indicating several operations for updating the volume status.
        break;
      default:
        break;
    }
  } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
    // The application can choose to take action or ignore.
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_RESUME:
        // It is recommended that the application continue rendering. (The audio stream has been forcibly paused and temporarily lost the focus. It can resume rendering now.)
        console.info('Resume force paused renderer or ignore');
        // To continue rendering, the application must perform the required operations.
        break;
      default:
        break;
    }
  }
});
```

### off('audioInterrupt') <sup>10+</sup>

off(type: 'audioInterrupt'): void

Unsubscribes from the audio interruption event.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| :----- | :----- | :--- | :------------------------------------------------ |
| type   | string | Yes  | Event type. The event **'audioInterrupt'** is triggered when the audio focus is changed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
systemRingtonePlayer.off('audioInterrupt');
```

<!--no_check-->