# Interface (AudioManager)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

This interface implements audio volume and device management.

Before calling any API in AudioManager, you must use [getAudioManager](arkts-apis-audio-f.md#audiogetaudiomanager) to obtain an AudioManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## getAudioScene<sup>8+</sup>

getAudioScene\(callback: AsyncCallback<AudioScene\>\): void

Obtains the audio scene. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| :------- | :-------------------------------------------------- | :--- | :--------------------------- |
| callback | AsyncCallback<[AudioScene](arkts-apis-audio-e.md#audioscene8)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio scene obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioScene((err: BusinessError, value: audio.AudioScene) => {
  if (err) {
    console.error(`Failed to obtain the audio scene mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the audio scene mode is obtained ${value}.`);
});
```

## getAudioScene<sup>8+</sup>

getAudioScene\(\): Promise<AudioScene\>

Obtains the audio scene. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                         | Description                        |
| :-------------------------------------------- | :--------------------------- |
| Promise<[AudioScene](arkts-apis-audio-e.md#audioscene8)> | Promise used to return the audio scene.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioScene().then((value: audio.AudioScene) => {
  console.info(`Promise returned to indicate that the audio scene mode is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to obtain the audio scene mode ${err}`);
});
```

## getAudioSceneSync<sup>10+</sup>

getAudioSceneSync\(\): AudioScene

Obtains the audio scene. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                         | Description                        |
| :-------------------------------------------- | :--------------------------- |
| [AudioScene](arkts-apis-audio-e.md#audioscene8) | Audio scene.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: audio.AudioScene = audioManager.getAudioSceneSync();
  console.info(`indicate that the audio scene mode is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the audio scene mode ${error}`);
}
```

## on('audioSceneChange')<sup>20+</sup>

on(type: 'audioSceneChange', callback: Callback\<AudioScene\>): void

Subscribes to the audio scene change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'audioSceneChange'** is triggered when the audio scene is changed.|
| callback | Callback\<[AudioScene](arkts-apis-audio-e.md#audioscene8)> | Yes  | Callback used to return the current audio scene.|

**Example**

```ts
audioManager.on('audioSceneChange', (audioScene: audio.AudioScene) => {
  console.info(`audio scene : ${audioScene}.`);
});
```

## off('audioSceneChange')<sup>20+</sup>

off(type: 'audioSceneChange', callback?: Callback\<AudioScene\>): void

Unsubscribes from the audio scene change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'audioSceneChange'** is triggered when the audio scene is changed.|
| callback | Callback\<[AudioScene](arkts-apis-audio-e.md#audioscene8)> | No| Callback used to return the current audio scene.|

**Example**

```ts
// Cancel all subscriptions to the event.
audioManager.off('audioSceneChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let audioSceneChangeCallback = (audioScene: audio.AudioScene) => {
  console.info(`audio scene : ${audioScene}.`);
};

audioManager.on('audioSceneChange', audioSceneChangeCallback);

audioManager.off('audioSceneChange', audioSceneChangeCallback);
```

## getVolumeManager<sup>9+</sup>

getVolumeManager(): AudioVolumeManager

Obtains an AudioVolumeManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                     | Description                         |
|-----------------------------------------| ----------------------------- |
| [AudioVolumeManager](arkts-apis-audio-AudioVolumeManager.md) | AudioVolumeManager instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioVolumeManager: audio.AudioVolumeManager = audioManager.getVolumeManager();
```

## getStreamManager<sup>9+</sup>

getStreamManager(): AudioStreamManager

Obtains an AudioStreamManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                        | Description                         |
|--------------------------------------------| ----------------------------- |
| [AudioStreamManager](arkts-apis-audio-AudioStreamManager.md) | AudioStreamManager instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamManager: audio.AudioStreamManager = audioManager.getStreamManager();
```

## getRoutingManager<sup>9+</sup>

getRoutingManager(): AudioRoutingManager

Obtains an AudioRoutingManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                      | Description                         |
|------------------------------------------| ----------------------------- |
| [AudioRoutingManager](arkts-apis-audio-AudioRoutingManager.md) | AudioRoutingManager instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioRoutingManager: audio.AudioRoutingManager = audioManager.getRoutingManager();
```

## getSessionManager<sup>12+</sup>

getSessionManager(): AudioSessionManager

Obtains an AudioSessionManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                          | Description                         |
|----------------------------------------------| ----------------------------- |
| [AudioSessionManager](arkts-apis-audio-AudioSessionManager.md) | AudioSessionManager instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
```

## getSpatializationManager<sup>18+</sup>

getSpatializationManager(): AudioSpatializationManager

Obtains an AudioSpatializationManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                                      | Description                         |
|------------------------------------------| ----------------------------- |
| [AudioSpatializationManager](arkts-apis-audio-AudioSpatializationManager.md) | AudioSpatializationManager instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
let audioSpatializationManager: audio.AudioSpatializationManager = audioManager.getSpatializationManager();
```

## setAudioParameter<sup>(deprecated)</sup>

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and are not common parameters. Sample parameters are used in the sample code below.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| key      | string                    | Yes  | Key of the audio parameter to set.  |
| value    | string                    | Yes  | Value of the audio parameter to set.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setAudioParameter('key_example', 'value_example', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the audio parameter. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio parameter.');
});
```

## setAudioParameter<sup>(deprecated)</sup>

setAudioParameter(key: string, value: string): Promise&lt;void&gt;

Sets an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and are not common parameters. Sample parameters are used in the sample code below.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | string | Yes  | Key of the audio parameter to set.|
| value  | string | Yes  | Value of the audio parameter to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setAudioParameter('key_example', 'value_example').then(() => {
  console.info('Promise returned to indicate a successful setting of the audio parameter.');
});
```

## getAudioParameter<sup>(deprecated)</sup>

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. Its substitute is available only to system applications.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                        |
| -------- | --------------------------- | ---- | ---------------------------- |
| key      | string                      | Yes  | Key of the audio parameter whose value is to be obtained.      |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio parameter value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioParameter('key_example', (err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to obtain the value of the audio parameter. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

## getAudioParameter<sup>(deprecated)</sup>

getAudioParameter(key: string): Promise&lt;string&gt;

Obtains the value of an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. Its substitute is available only to system applications.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | string | Yes  | Key of the audio parameter whose value is to be obtained.|

**Return value**

| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise&lt;string&gt; | Promise used to return the value of the audio parameter.|

**Example**

```ts
audioManager.getAudioParameter('key_example').then((value: string) => {
  console.info(`Promise returned to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

## setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

Sets the volume for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.
> 
> Applications cannot directly adjust the system volume. They can use the system volume panel to control the volume. For details about the samples and introduction, see [AVVolumePanel Reference](ohos-multimedia-avvolumepanel.md).

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

## setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

Sets the volume for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.
>
> Applications cannot directly adjust the system volume. They can use the system volume panel to control the volume. For details about the samples and introduction, see [AVVolumePanel Reference](ohos-multimedia-avvolumepanel.md).

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume of a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getvolumedeprecated) instead. For API version 20 and later, you are advised to use [getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream volume obtained; otherwise, **err** is an error object. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the volume of a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getvolumedeprecated) instead. For API version 20 and later, you are advised to use [getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value} .`);
});
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated) instead. For API version 20 and later, you are advised to use [getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the minimum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated) instead. For API version 20 and later, you are advised to use [getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the minimum volume.|

**Example**

```ts
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained. ${value}`);
});
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated) instead. For API version 20 and later, you are advised to use [getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                  |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.          |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the maximum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated) instead. For API version 20 and later, you are advised to use [getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum volume.|

**Example**

```ts
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data: number) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

## mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes a stream. This API uses an asynchronous callback to return the result.

When the minimum volume of a stream cannot be set to 0, muting the stream is not supported. Example scenarios: alarms or phone calls.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Whether to mute the stream. **true** to mute, **false** otherwise.|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

## mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

Mutes or unmutes a stream. This API uses a promise to return the result.

When the minimum volume of a stream cannot be set to 0, muting the stream is not supported. Example scenarios: alarms or phone calls.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Whether to mute the stream. **true** to mute, **false** otherwise.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**


```ts
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is muted. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [isMute](arkts-apis-audio-AudioVolumeGroupManager.md#ismutedeprecated) instead. For API version 20 and later, you are advised to use [isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                           |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isMute(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained. ${value}`);
});
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is muted. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [isMute](arkts-apis-audio-AudioVolumeGroupManager.md#ismutedeprecated) instead. For API version 20 and later, you are advised to use [isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result, indicating whether the stream is muted. **true** if muted, **false** otherwise.|

**Example**

```ts
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

## isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is active. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [isActive](arkts-apis-audio-AudioStreamManager.md#isactivedeprecated) instead. For API version 20 and later, you are advised to use [isStreamActive](arkts-apis-audio-AudioStreamManager.md#isstreamactive20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                             |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                     |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is active or **false** if not active; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isActive(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the active status of the stream. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});
```

## isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is active. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. From API version 9 to 19, you are advised to use [isActive](arkts-apis-audio-AudioStreamManager.md#isactivedeprecated) instead. For API version 20 and later, you are advised to use [isStreamActive](arkts-apis-audio-AudioStreamManager.md#isstreamactive20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                    |
| ---------------------- | -------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result, indicating whether the stream is active. **true** if active, **false** otherwise.|

**Example**

```ts
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});
```

## setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

Sets the ringer mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | Yes  | Ringer mode.          |
| callback | AsyncCallback&lt;void&gt;       | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the ringer mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

## setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

Sets the ringer mode. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.


**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | Yes  | Ringer mode.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

## getRingerMode<sup>(deprecated)</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

Obtains the ringer mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRingerMode](arkts-apis-audio-AudioVolumeGroupManager.md#getringermode9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                                | Mandatory| Description                    |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the ringer mode obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getRingerMode((err: BusinessError, value: audio.AudioRingMode) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

## getRingerMode<sup>(deprecated)</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

Obtains the ringer mode. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRingerMode](arkts-apis-audio-AudioVolumeGroupManager.md#getringermode9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | Promise used to return the ringer mode.|

**Example**

```ts
audioManager.getRingerMode().then((value: audio.AudioRingMode) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

## getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the audio devices with a specific flag. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDevices](arkts-apis-audio-AudioRoutingManager.md#getdevices9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag)                                    | Yes  | Audio device flag.    |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio devices obtained; otherwise, **err** is an error object.|

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err: BusinessError, value: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the device list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device list is obtained.');
});
```

## getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the audio devices with a specific flag. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDevices](arkts-apis-audio-AudioRoutingManager.md#getdevices9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                     | Mandatory| Description            |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag) | Yes  | Audio device flag.|

**Return value**

| Type                                                        | Description                     |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt; | Promise used to return the device list.|

**Example**

```ts
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

## setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets a device to the active state. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCommunicationDevice](arkts-apis-audio-AudioRoutingManager.md#setcommunicationdevice9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description         |
| ---------- | ------------------------------------- | ---- |-------------|
| deviceType | [ActiveDeviceType](arkts-apis-audio-e.md#activedevicetypedeprecated) | Yes  | Active audio device type.  |
| active     | boolean                               | Yes  | Active state to set. **true** to set the device to the active state, **false** otherwise.|
| callback   | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device is set to the active status.');
});
```

## setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise&lt;void&gt;

Sets a device to the active state. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCommunicationDevice](arkts-apis-audio-AudioRoutingManager.md#setcommunicationdevice9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](arkts-apis-audio-e.md#activedevicetypedeprecated) | Yes  | Active audio device type.|
| active     | boolean                               | Yes  | Active state to set. **true** to set the device to the active state, **false** otherwise.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**


```ts
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(() => {
  console.info('Promise returned to indicate that the device is set to the active status.');
});
```

## isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a device is active. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isCommunicationDeviceActive](arkts-apis-audio-AudioRoutingManager.md#iscommunicationdeviceactive9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description                    |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](arkts-apis-audio-e.md#activedevicetypedeprecated) | Yes  | Active audio device type.      |
| callback   | AsyncCallback&lt;boolean&gt;          | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the device is active or **false** if not active; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the active status of the device is obtained.');
});
```

## isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType): Promise&lt;boolean&gt;

Checks whether a device is active. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isCommunicationDeviceActive](arkts-apis-audio-AudioRoutingManager.md#iscommunicationdeviceactive9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](arkts-apis-audio-e.md#activedevicetypedeprecated) | Yes  | Active audio device type.|

**Return value**

| Type                  | Description                                  |
| ---------------------- |---------------------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result, indicating whether the device is active. **true** if active, **false** otherwise.|

**Example**

```ts
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the device is obtained ${value}.`);
});
```

## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes the microphone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | Yes  | Mute status to set. **true** to mute, **false** otherwise.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setMicrophoneMute(true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. **true** to mute, **false** otherwise.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```

## isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the microphone is muted. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMicrophoneMute](arkts-apis-audio-AudioVolumeGroupManager.md#ismicrophonemute9) instead.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                        | Mandatory| Description                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the microphone is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isMicrophoneMute((err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

## isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

Checks whether the microphone is muted. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMicrophoneMute](arkts-apis-audio-AudioVolumeGroupManager.md#ismicrophonemute9) instead.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result, indicating whether the microphone is muted. **true** if muted, **false** otherwise.|

**Example**

```ts
audioManager.isMicrophoneMute().then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

## on('deviceChange')<sup>(deprecated)</sup>

on(type: 'deviceChange', callback: Callback<DeviceChangeAction\>): void

Subscribes to the event indicating that the connection status of an audio device is changed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [on('deviceChange')](arkts-apis-audio-AudioRoutingManager.md#ondevicechange9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                                | Mandatory| Description                                      |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | Yes  | Event type. The event **'deviceChange'** is triggered when the connection status of an audio device is changed.|
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)\> | Yes  | Callback used to return the device change details.|

**Example**

```ts
audioManager.on('deviceChange', (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type} `);
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType} `);
});
```

## off('deviceChange')<sup>(deprecated)</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

Unsubscribes from the audio device change event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [off('deviceChange')](arkts-apis-audio-AudioRoutingManager.md#offdevicechange9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | Yes  | Event type. The event **'deviceChange'** is triggered when the connection status of an audio device is changed.|
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)> | No  | Callback used to return the device change details.|

**Example**

```ts
// Cancel all subscriptions to the event.
audioManager.off('deviceChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let deviceChangeCallback = (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type} `);
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType} `);
};

audioManager.on('deviceChange', deviceChangeCallback);

audioManager.off('deviceChange', deviceChangeCallback);
```

## on('interrupt')<sup>(deprecated)</sup>

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void

Subscribes to the audio interruption event, which is triggered when the audio focus is changed. This API uses an asynchronous callback to return the result.

Same as [on('audioInterrupt')](arkts-apis-audio-AudioRenderer.md#onaudiointerrupt9), this API is used to listen for focus is changed. However, this API is used in scenarios without audio streams (no AudioRenderer instance is created), such as frequency modulation (FM) and voice wakeup.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. You are advised to use [on('audioInterrupt')](arkts-apis-audio-AudioCapturer.md#onaudiointerrupt10) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                                     | Mandatory| Description                                                        |
| --------- |---------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                                                  | Yes  | Event type. The event **'interrupt'** is triggered when the audio focus is changed.|
| interrupt | [AudioInterrupt](arkts-apis-audio-i.md#audiointerruptdeprecated)             | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](arkts-apis-audio-i.md#interruptactiondeprecated)> | Yes  | Callback used to return the event information.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let interAudioInterrupt: audio.AudioInterrupt = {
  streamUsage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  contentType: audio.ContentType.CONTENT_TYPE_UNKNOWN,
  pauseWhenDucked: true
};

audioManager.on('interrupt', interAudioInterrupt, (interruptAction: audio.InterruptAction) => {
  if (interruptAction.actionType === 0) {
    console.info('An event to gain the audio focus starts.');
    console.info(`Focus hint: ${interruptAction.hint} `);
  }
  if (interruptAction.actionType === 1) {
    console.info('An audio interruption event starts.');
    console.info(`Audio interruption hint: ${interruptAction.hint} `);
  }
});
```

## off('interrupt')<sup>(deprecated)</sup>

off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void

Unsubscribes from the audio interruption event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. You are advised to use [off('audioInterrupt')](arkts-apis-audio-AudioCapturer.md#offaudiointerrupt10) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                                     | Mandatory| Description                                                        |
| --------- |---------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                                                  | Yes  | Event type. The event **'interrupt'** is triggered when the audio focus is changed.|
| interrupt | [AudioInterrupt](arkts-apis-audio-i.md#audiointerruptdeprecated)                       | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](arkts-apis-audio-i.md#interruptactiondeprecated)> | No  | Callback used to return the event information.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let interAudioInterrupt: audio.AudioInterrupt = {
  streamUsage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  contentType: audio.ContentType.CONTENT_TYPE_UNKNOWN,
  pauseWhenDucked: true
};

// Cancel all subscriptions to the event.
audioManager.off('interrupt', interAudioInterrupt);

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let interruptCallback = (interruptAction: audio.InterruptAction) => {
  if (interruptAction.actionType === 0) {
    console.info('An event to gain the audio focus starts.');
    console.info(`Focus hint: ${interruptAction.hint} `);
  }
  if (interruptAction.actionType === 1) {
    console.info('An audio interruption event starts.');
    console.info(`Audio interruption hint: ${interruptAction.hint} `);
  }
};

audioManager.on('interrupt', interAudioInterrupt, interruptCallback);

audioManager.off('interrupt', interAudioInterrupt, interruptCallback);
```
