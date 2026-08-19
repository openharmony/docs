# Interface (AVAdsController)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @zhaoyunfei-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51bfafdbb2845b3bdd99760e6fdc9b98c7427928 translatedAt=2026-08-17T10:24:30.929Z pushedAt=2026-08-19T03:38:24.962Z -->

Provides APIs for controlling ad content, including managing ad resources in the ad playback controller and listening for ad events. You can add and remove ad sources, skip the current ad, and disable remaining ads. This module can be used to insert and manage ad content during video playback. Use [createAVAdsController()](arkts-apis-media-f.md#mediacreateavadscontroller) to create an instance.

> **NOTE**
>
> - The initial APIs of this interface are supported since API version 26.0.0.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## addAdsMediaSource

addAdsMediaSource(src: MediaSource, start: number): Promise\<string>

Adds an ad media source to the ad controller and specifies the position where the ad is inserted during the playback of the main media resource. For example, you can insert an ad before the main content is played in the video player or during the playback. If multiple ads are inserted at the same position, they are played in the sequence in which they are added. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](arkts-apis-media-MediaSource.md) | Yes | Media source of the ad to be inserted into the main content. |
| start | number | Yes | Position where the ad is inserted during the playback of the main media resources, which is calculated from the start of the main media resource playback. The unit is milliseconds. The value must be a non-negative integer and cannot exceed the total duration of the main media resource. Otherwise, error code 5400108 will be triggered. |

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| Promise\<string> | Promise used to return the ID of the media source added to the ad controller. The **removeAdsMediaSource** API can remove the corresponding ad source based on this ID. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | Insert a media asset whose start value exceeds the value of the main content. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
    let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/ad.mp4', headers);
    let adsId: string = await adsController.addAdsMediaSource(mediaSource, 5000);
    console.info(`Succeeded in adding ads media source, adsId: ${adsId}`);
  }
}
```

## removeAdsMediaSource

removeAdsMediaSource(id: string): void

Removes the specified ad media source from the ad controller. If the ad is being played, it will be removed after the playback is complete. For example, you can call this method to remove an ad when its content expires or the user has purchased the ad-free option.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| id | string | Yes | ID of the ad media source, which is returned by the **addAdsMediaSource** API. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the AdsController. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
    let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/ad.mp4', headers);
    let adsId: string = await adsController.addAdsMediaSource(mediaSource, 5000);
    adsController.removeAdsMediaSource(adsId);
  }
}
```

## skipCurrentAdsMediaSource

skipCurrentAdsMediaSource(): void

Skips the ad that is being played. After the ad is skipped, the playback of the main content resumes immediately, and the **onAdsListenerAdsSkipped** callback is triggered. For example, when a user taps the ad skip button on the player, this API can be called to skip the current ad and continue playing the main content.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.skipCurrentAdsMediaSource();
  }
}
```

## disableAllAdsMediaSource

disableAllAdsMediaSource(): void

Disables the playback of remaining ad content in the current session. Subsequent ads that have not been played will not be played. For example, when a user has purchased the ad-free option or ads should not be displayed according to the content review mechanism, this API can be called to disable all subsequent ads.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.disableAllAdsMediaSource();
  }
}
```

## release

release(): void

Releases the **AVAdsController** object. After the release, the registered callback will not be triggered. You need to call this method to release the ad controller before releasing the AVPlayer.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.release();
  }
}
```

## onAdsEventListenerLoadingError

onAdsEventListenerLoadingError(callback: OnAdsEventLoadingErrorHandle): void

Registers a callback for handling ad content loading failures.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAdsEventLoadingErrorHandle](arkts-apis-media-t.md#onadseventloadingerrorhandle) | Yes | Callback for handling ad content loading failures, which is implemented by the user.<br>The first parameter is used to pass the ad ID, and the second parameter is used to pass the failure cause. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.onAdsEventListenerLoadingError((adsId: string, reason: BusinessError) => {
      console.error(`Failed to load ads, adsId: ${adsId}, Code: ${reason.code}, message: ${reason.message}`);
    });
  }
}
```

## onAdsListenerAdsStarted

onAdsListenerAdsStarted(callback: OnAdsEventAdsStartedHandle): void

Registers a callback triggered when a new ad is played.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAdsEventAdsStartedHandle](arkts-apis-media-t.md#onadseventadsstartedhandle) | Yes   | Callback triggered when the ad starts playing. It is usually used when the main content playback screen is switched to the ad playback screen.<br>The first parameter indicates the ID of the ad being played, and the second parameter indicates the ad duration, in milliseconds. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.onAdsListenerAdsStarted((adsId: string, duration: number) => {
      console.info(`Ads started, adsId: ${adsId}, duration: ${duration}ms`);
    });
  }
}
```

## onAdsListenerAdsSkipped

onAdsListenerAdsSkipped(callback: Callback\<string>): void

Registers a callback triggered when an ad is skipped.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name     | Type     | Mandatory | Description                 |
| -------- | -------- | --------- | --------------------------- |
| callback | Callback\<string> | Yes   | Callback for ad skipping. It is usually used to resume the playback of the main content. The parameter is the ID of the ad that is skipped. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.onAdsListenerAdsSkipped((adsId: string) => {
      console.info(`Ads skipped, adsId: ${adsId}`);
    });
  }
}
```

## onAdsListenerAdsCompleted

onAdsListenerAdsCompleted(callback: Callback\<string>): void

Registers a callback triggered when the ad content playback is complete.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name     | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| callback | Callback\<string> | Yes   | Callback invoked when the ad playback is complete. It is usually used to resume the playback of the main content. The parameter is the ID of the ad that has been played. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.onAdsListenerAdsCompleted((adsId: string) => {
      console.info(`Ads completed, adsId: ${adsId}`);
    });
  }
}
```

## offAdsEventListenerLoadingError

offAdsEventListenerLoadingError(callback?: OnAdsEventLoadingErrorHandle): void

Unregisters the callback for handling ad content loading failures.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAdsEventLoadingErrorHandle](arkts-apis-media-t.md#onadseventloadingerrorhandle) | No | Callback for handling ad content loading failures.<br>If this parameter is specified, only the specified callback is unregistered. If this parameter is not specified, all callbacks for the event are unregistered by default. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.offAdsEventListenerLoadingError();
  }
}
```

## offAdsListenerAdsStarted

offAdsListenerAdsStarted(callback?: OnAdsEventAdsStartedHandle): void

Unregisters the callback triggered when a new ad is played.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAdsEventAdsStartedHandle](arkts-apis-media-t.md#onadseventadsstartedhandle) | No | Callback triggered when the ad starts playing. It is usually used when the main content playback screen is switched to the ad playback screen.<br>If this parameter is specified, only the specified callback is unregistered. If this parameter is not specified, all callbacks for the event are unregistered by default.|

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.offAdsListenerAdsStarted();
  }
}
```

## offAdsListenerAdsSkipped

offAdsListenerAdsSkipped(callback?: Callback\<string>): void

Unregisters the callback triggered when an ad is skipped.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| callback | Callback\<string> | No   | Callback for ad skipping.<br>If this parameter is specified, only the specified callback is unregistered. If this parameter is not specified, all callbacks for the event are unregistered by default. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.offAdsListenerAdsSkipped();
  }
}
```

## offAdsListenerAdsCompleted

offAdsListenerAdsCompleted(callback?: Callback\<string>): void

Unregisters the callback triggered when the ad content playback is complete.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | Callback\<string> | No | Callback invoked when the ad playback is complete.<br>If this parameter is specified, only the specified callback is unregistered. If this parameter is not specified, all callbacks for the event are unregistered by default. |

**Example**

```ts
async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  let adsController: media.AVAdsController | undefined = await media.createAVAdsController(player);
  if (adsController) {
    adsController.offAdsListenerAdsCompleted();
  }
}
```