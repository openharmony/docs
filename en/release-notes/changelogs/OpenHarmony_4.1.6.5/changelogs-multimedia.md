# Multimedia Subsystem Changelog

## c1.multimedia.1 APIs setAudioParameter and getAudioParameter of the AudioManager Class in ohos.multimedia.audio Are Deprecated

**Access Level**

Public API

**Reason for Change**

Third-party applications and audio chips can no longer modify configurations through custom parameters. Instead, the configuration modification is now controlled by the system. Dedicated APIs are provided for common functionalities.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**Deprecated Since**

OpenHarmony SDK 4.1.6.5

**Deprecated APIs**

In the **AudioManager** class:

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;

setAudioParameter(key: string, value: string): Promise&lt;void&gt;;

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void;

getAudioParameter(key: string): Promise&lt;string&gt;;

**Adaptation Guide**

For system applications, use the alternative APIs according to the deprecated API hints.

setExtraParameters(mainKey: string, kvpairs: Record&lt;string, string&gt;): Promise&lt;void&gt;;

getExtraParameters(mainKey: string, subKeys?: Array&lt;string&gt;): Promise&lt;Record&lt;string, string&gt;&gt;;

In the preceding APIs, **mainKey** is the same as the original parameter **key**, and **kvpairs** is the key-value pairs in the string of the original parameter **value**.

For third-party applications, the preceding APIs are not available. Use the public APIs of the **AudioManager** class as required.

The deprecated APIs will be retained for five more SDK versions. Make your adaptation plan as required.

## c1.multimedia.2 API setMicrophoneMute of the AudioVolumeGroupManager Class in ohos.multimedia.audio Is Deprecated

**Access Level**

Public API

**Reason for Change**

The **setMicrophoneMute** API is a public API but requires the **ohos.permission.MANAGE_AUDIO_CONFIG** permission, which cannot be granted to third-party applications. According to the SDK specifications, the API is changed to a system API.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**Deprecated Since**

OpenHarmony SDK 4.1.6.5

**Deprecated APIs**

In the **AudioVolumeGroupManager** class:

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void;

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;;

**Adaptation Guide**

For system applications, use the alternative API according to the deprecated API hints. The alternative API provides the same functionality.

setMicMute(mute: boolean): Promise&lt;void&gt;;

Third-party applications cannot obtain the **ohos.permission.MANAGE_AUDIO_CONFIG** permission and therefore cannot actually use the original API. This change has no impact and requires no adaptation.

The deprecated APIs will be retained for five more SDK versions. Make your adaptation plan as required.

## c1.multimedia.3 Behavior of the usages Attribute of CaptureFilterOptions in ohos.multimedia.audio Is Changed

**Access Level**

Public API

**Reason for Change**

The **usages** attribute is used to filter audio clips by usage during internal audio recording. When the attribute is **STREAM_USAGE_VOICE_COMMUNICATION**, the application must have the **ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO** permission, which cannot be granted to third-party applications. According to the SDK specifications, the attribute must be removed from the public API.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

Before change:
```
/**
 * Filter by stream usages. If you want to capture voice streams, additional permission is needed.
 * @permission ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 10
 */
```
An application can use **STREAM_USAGE_VOICE_COMMUNICATION** to filter audio clips, under the prerequisites that it has the **ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO** permission.

After change:
```
/**
 * Filter by stream usages. But not allow to capture voice streams.
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 11
 */
```
Applications can no longer use **STREAM_USAGE_VOICE_COMMUNICATION** to filter audio clips, and the declaration of the **ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO** permission is deleted. When an application without this permission uses **STREAM_USAGE_VOICE_COMMUNICATION**, an **AudioCapturer** object cannot be created and the **ERROR_SYSTEM** error is returned.

**Adaptation Guide**

Third-party applications cannot obtain the permission and therefore cannot actually use **STREAM_USAGE_VOICE_COMMUNICATION**. This change has no impact and requires no adaptation.

System applications cannot use **STREAM_USAGE_VOICE_COMMUNICATION** even if they have the **ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO** permission. Therefore, remove **STREAM_USAGE_VOICE_COMMUNICATION** from your code.

## c1.multimedia.4 APIs for Subscribing to or Unsubscribing from the interrupt Event of the AudioManager Class in ohos.multimedia.audio Is Deprecated

**Access Level**

Public API

**Reason for Change**

In SDK 10, the system uses the built-in focus mode. For details, see [Audio Playback Concurrency Policy](../../../application-dev/media/audio-playback-concurrency.md).

The APIs are related to the external focus and cannot be used to preempt the built-in focus. As such, they are deprecated.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**Deprecated Since**

OpenHarmony SDK 4.1.6.5

**Deprecated APIs**

In the **AudioManager** class:

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback&lt;InterruptAction&gt;): void;

off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback&lt;InterruptAction&gt;): void;

**Adaptation Guide**

Implement concurrency policy control for audio playback based on the built-in focus mode. For details, see [Audio Playback Concurrency Policy](../../../application-dev/media/audio-playback-concurrency.md).

## c1.multimedia.5 API write of the AudioRenderer Class and read of the AudioCapturer Class in ohos.multimedia.audio Are Deprecated

**Access Level**

Public API

**Reason for Change**

The APIs for subscribing to the **'writeData'** and **'readData'** events are added to the **AudioRenderer** and **AudioCapturer** classes. Using the subscription APIs, you no longer need to manage data processing moments, avoiding the underrun/overrun problem caused by inaccurate data rotation time.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**Deprecated Since**

OpenHarmony SDK 4.1.6.5

**Deprecated APIs**

In the **AudioRenderer** class:

write(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void;

write(buffer: ArrayBuffer): Promise&lt;number&gt;;

In the **AudioCapturer** class:

read(size: number, isBlockingRead: boolean, callback: AsyncCallback&lt;ArrayBuffer&gt;): void;

read(size: number, isBlockingRead: boolean): Promise&lt;ArrayBuffer&gt;;

**Adaptation Guide**

Use the new APIs according to the deprecated API hints.

New **AudioRenderer** APIs:

on(type: 'writeData', callback: Callback&lt;ArrayBuffer&gt;): void;

off(type: 'writeData', callback?: Callback&lt;ArrayBuffer&gt;): void;

When the callback is received, the application needs to write the playback data to the ArrayBuffer. After the callback is complete, the system automatically obtains the data from the ArrayBuffer for output.

New **AudioCapturer** APIs:

on(type: 'readData', callback: Callback&lt;ArrayBuffer&gt;): void;

off(type: 'readData', callback?: Callback&lt;ArrayBuffer&gt;): void;

When the callback is received, the application needs to read the recording data from the ArrayBuffer. After the callback is complete, the system writes the subsequent recording data in the ArrayBuffer to prepare for the next callback trigger.

The deprecated APIs will be retained for five more SDK versions. Make your adaptation plan as required.

## c1.multimedia.6 Obtaining Preferred Recording Device Behavior in ohos.multimedia.audio Is Changed in the Internal Recording Scenario

**Access Level**

Public API

**Reason for Change**

In the internal recording scenario, no microphone is used for recording. The correct device type should be returned.

**Change Impact**

This change is a compatible change. No adaptation is required.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

In the **AudioRoutingManager** class:

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise&lt;AudioDeviceDescriptors&gt;;

Before change:

When the input type is **SOURCE_TYPE_PLAYBACK_CAPTURE**, **AudioDeviceDescriptor** of a **DeviceType.MIC** device is returned.

After change:

When the input type is **SOURCE_TYPE_PLAYBACK_CAPTURE**, **AudioDeviceDescriptor** of a **DeviceType.INVALID** device is returned.

**Adaptation Guide**

The return value in the internal recording scenario is corrected. No adaptation is required.

## c1.multimedia.7 Behavior of Subscription APIs of the AudioManager Class in ohos.multimedia.audio Is Changed

**Access Level**

Public API

**Reason for Change**

The implementation of the subscription APIs does not comply with the general subscription API specifications, and the subscription callbacks may be overwritten.

**Change Impact**

If an application makes multiple subscriptions, all subscribed-to callbacks will be traversed and triggered in sequence when the subscribed-to event occurs.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

In the **AudioVolumeManager** class:

on(type: 'volumeChange', callback: Callback&lt;VolumeEvent&gt;): void;

In the **AudioVolumeGroupManager** class:

on(type: 'ringerModeChange', callback: Callback&lt;AudioRingMode&gt;): void;

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void;

In the **AudioRoutingManager** class:

on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback&lt;DeviceChangeAction&gt;): void;

In the **AudioStreamManager** class:

on(type: 'audioRendererChange', callback: Callback&lt;AudioRendererChangeInfoArray&gt;): void;

on(type: 'audioCapturerChange', callback: Callback&lt;AudioCapturerChangeInfoArray&gt;): void;

Before change:

When an event is subscribed to for multiple times, only the last callback is triggered.

After change:

When an event is subscribed to for multiple times, all callbacks that are not unsubscribed from are triggered.

**Adaptation Guide**

If an event is subscribed to only once, no adaptation is required.

If an event is subscribed to for multiple times, no adaptation is required if you want all subscribed-to callbacks will be traversed and triggered, no adaptation is required.

If an event is subscribed to for multiple times, but you only want the last callback to be triggered, use **off** to unsubscribe from the previous callbacks.

## c1.multimedia.8 Error Code Is Added for the System API availableDevice in ohos.multimedia.audio

**Access Level**

System API

**Reason for Change**

The corresponding error code is added to the system API.

**Change Impact**

This change is a compatible change. No adaptation is required.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

In the **AudioRoutingManager** class:

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors;

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback&lt;DeviceChangeAction&gt;): void;

off(type: 'availableDeviceChange', callback?: Callback&lt;DeviceChangeAction&gt;): void;

Before change:

When a third-party application calls these system APIs, the default result is returned but the subscription does not take effect.

After change:

When a third-party application calls these system APIs, error code 202 is thrown.

**Adaptation Guide**

For system applications, no adaptation is required.

For third-party applications, they should not use system APIs.

## c1.multimedia.9 Permission Statement Is Added for the createPlayer API in ohos.multimedia.audioHaptic

**Access Level**

Public API

**Reason for Change**

**AudioHapticPlayer** supports the haptic feedback, which depends on the **ohos.permission.VIBRATE** permission.

**Change Impact**

This change is a non-compatible change. To use the haptic feedback, your application must obtain the permission.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

In the **AudioHapticManager** class:

createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise&lt;AudioHapticPlayer&gt;;

Before change:

```
/**
 * Create an audio haptic player. This method uses a promise to return the result.
 * @param { number } id - Source id.
 * @param { AudioHapticPlayerOptions } options - Options when creating audio haptic player.
 * @returns { Promise&lt;AudioHapticPlayer&gt; } Promise used to return the result.
 * @throws { BusinessError } 401 - The parameter check failed.
 * @throws { BusinessError } 5400102 - Operation not allowed.
 * @throws { BusinessError } 5400103 - I/O error.
 * @throws { BusinessError } 5400106 - Unsupport format.
 * @syscap SystemCapability.Multimedia.AudioHaptic.Core
 * @since 11
 */
```

There is no permission statement. However, applications without the permission cannot trigger the haptic feedback. Only audio playback is supported.

After change:

```
/**
 * Create an audio haptic player. This method uses a promise to return the result. If haptics is needed, caller
 * should have the permission of ohos.permission.VIBRATE.
 * @permission ohos.permission.VIBRATE
 * @param { number } id - Source id.
 * @param { AudioHapticPlayerOptions } options - Options when creating audio haptic player.
 * @returns { Promise&lt;AudioHapticPlayer&gt; } Promise used to return the result.
 * @throws { BusinessError } 201 - Permission denied.
 * @throws { BusinessError } 401 - The parameter check failed.
 * @throws { BusinessError } 5400102 - Operation not allowed.
 * @throws { BusinessError } 5400103 - I/O error.
 * @throws { BusinessError } 5400106 - Unsupport format.
 * @syscap SystemCapability.Multimedia.AudioHaptic.Core
 * @since 11
 */
```

The **ohos.permission.VIBRATE** permission statement and permission usage comments are provided.

**Adaptation Guide**

The API behavior is not changed. To enable the haptic feedback, an application must request the **ohos.permission.VIBRATE** permission.

## c1.multimedia.10 Error Code Implementation of the AudioManager Class in ohos.multimedia.audio Is Corrected

**Access Level**

Public API

**Reason for Change**

The error code is declared as a number, but the type string is used in the implementation.

**Change Impact**

The declaration remains unchanged. If your code complies with the API definition, no adaptation is required.

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

In the **AudioManager** class:

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;

getVolume(volumeType: AudioVolumeType): Promise<number>;

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;

getMaxVolume(volumeType: AudioVolumeType): Promise<number>;

isMute(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;

isMute(volumeType: AudioVolumeType): Promise<boolean>;

Before change:

The value of **BusinessError.code** returned by the APIs asynchronously is of the string type.

After change:

The value of **BusinessError.code** returned by the APIs asynchronously is of the number type.

**Adaptation Guide**

The declaration is not changed. The error code is of the number type.

If you found that the returned error code does not comply with the definition and used the string for verification, adapt to the original API definition and use the **AudioErrors** error code of the number type.
