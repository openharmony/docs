# Interface (AudioSessionManager)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

This interface implements audio session management.

Before calling any API in AudioSessionManager, you must use [getSessionManager](arkts-apis-audio-AudioManager.md#getsessionmanager12) to obtain an AudioSessionManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## activateAudioSession<sup>12+</sup>

activateAudioSession(strategy: AudioSessionStrategy): Promise\<void>

Activates an audio session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type                                             | Mandatory| Description        |
| ------ |-------------------------------------------------| ---- | ------------ |
| strategy | [AudioSessionStrategy](arkts-apis-audio-i.md#audiosessionstrategy12) | Yes  | Audio session strategy.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | ---------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters unspecified. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.|
| 6800301 | System error. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let strategy: audio.AudioSessionStrategy = {
  concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
};

audioSessionManager.activateAudioSession(strategy).then(() => {
  console.info('activateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## deactivateAudioSession<sup>12+</sup>

deactivateAudioSession(): Promise\<void>

Deactivates this audio session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | ---------------------------------------------|
| 6800301 | System error. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.deactivateAudioSession().then(() => {
  console.info('deactivateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## isAudioSessionActivated<sup>12+</sup>

isAudioSessionActivated(): boolean

Checks whether this audio session is activated.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                             | Description                                   |
| ------------------------------------------------- |---------------------------------------|
| boolean | Check result. The value **true** means that the audio session is activated, and **false** means the opposite.|

**Example**

```ts
let isActivated = audioSessionManager.isAudioSessionActivated();
```

## on('audioSessionDeactivated')<sup>12+</sup>

on(type: 'audioSessionDeactivated', callback: Callback\<AudioSessionDeactivatedEvent>): void

Subscribes to the audio session deactivation event, which is triggered when an audio session is deactivated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                                                                       | Mandatory| Description                                                        |
| -------- |---------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The event **'audioSessionDeactivated'** is triggered when the audio session is deactivated.|
| callback | Callback<[AudioSessionDeactivatedEvent](arkts-apis-audio-i.md#audiosessiondeactivatedevent12)> | Yes  | Callback used to return the reason why the audio session is deactivated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters unspecified. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
  console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
});
```

## off('audioSessionDeactivated')<sup>12+</sup>

off(type: 'audioSessionDeactivated', callback?: Callback\<AudioSessionDeactivatedEvent>): void

Unsubscribes from the audio session deactivation event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The event **'audioSessionDeactivated'** is triggered when the audio session is deactivated.|
| callback |Callback<[AudioSessionDeactivatedEvent](arkts-apis-audio-i.md#audiosessiondeactivatedevent12)> | No  | Callback used to return the reason why the audio session is deactivated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioSessionManager.off('audioSessionDeactivated');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let audioSessionDeactivatedCallback = (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
  console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
};

audioSessionManager.on('audioSessionDeactivated', audioSessionDeactivatedCallback);

audioSessionManager.off('audioSessionDeactivated', audioSessionDeactivatedCallback);
```
