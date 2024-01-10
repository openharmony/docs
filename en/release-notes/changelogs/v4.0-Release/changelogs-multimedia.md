# Multimedia Changelog

## cl.multimedia.1 Changed the Declaration of the Focus Event Callback of Audio Renderer C APIs

For the audio renderer C APIs of API version 10, the focus event callback is changed from **OH_AudioRenderer_OnInterrptEvent** to **OH_AudioRenderer_OnInterruptEvent**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

 ```C
int32_t (*OH_AudioRenderer_OnInterrptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

After change:

 ```C
int32_t (*OH_AudioRenderer_OnInterruptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**Adaptation Guide**

To define the focus event for an audio renderer, use the function pointer **OH_AudioRenderer_OnInterruptEvent**. Example:

Before change:

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterrptEvent = AudioRendererOnInterrptEvent;
```

After change:

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterruptEvent = AudioRendererOnInterrptEvent;
```

## cl.multimedia.2 Changed the Declaration of the Focus Event Callback of Audio Capturer C APIs

For the audio capturer C APIs of API version 10, the focus event callback is changed from **OH_AudioCapturer_OnInterrptEvent** to **OH_AudioCapturer_OnInterruptEvent**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

 ```C
int32_t (*OH_AudioCapturer_OnInterrptEvent)(
        OH_AudioCapturer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

After change:

 ```C
int32_t (*OH_AudioCapturer_OnInterruptEvent)(
        OH_AudioCapturer* capturer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**Adaptation Guide**

To define the focus event for an audio capturer, use the function pointer **OH_AudioCapturer_OnInterruptEvent**. Example:

Before change:

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterrptEvent = AudioCaptureOnInterruptEvent;
```

After change:

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterruptEvent = AudioCaptureOnInterruptEvent;
```


## cl.multimedia.3 Added Error Code Declaration for APIs of API Version 10 with Input Parameters in @ohos.multimedia.audio.d.ts

**Change Impact**

For an API that carries input parameters, if the parameter type or quantity is incorrect, error code 401 is thrown synchronously. If the parameter value is out of the value range, the corresponding error code is thrown directly for a synchronous API and returned through the **error** object for an asynchronous API.
If the API usage meets the definition requirements, there is no compatibility impact.

**Key API/Component Changes**

The following APIs are involved:

 ```ts
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
on(type: 'preferredOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
off(type: 'preferredOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
setAudioEffectMode(mode: AudioEffectMode): Promise<void>;
 ```

The following error code types are added:

 ```ts
// The input parameter type or quantity is incorrect.
@throws { BusinessError } 401 - If input parameter type or number mismatch.
// The input parameter value is out of the value range.
@throws { BusinessError } 6800101 - Invalid parameter error.
// Common internal system error.
@throws { BusinessError } 6800301 - System error.
 ```

**Adaptation Guide**

If error code 401 is thrown, check whether the type and quantity of input parameters comply with the API definition.

If other codes are thrown, check the possible causes and handle the exceptions properly.


## cl.multimedia.4 Implementation Error of AudioRenderer.getCurrentOutputDevices Corrected

According to the definition, the **getCurrentOutputDevices** API of the **AudioRenderer** class should return the **AudioDeviceDescriptors** type, that is, an array of the **AudioDeviceDescriptor** types. However, the **AudioDeviceDescriptor** type is returned in the API implementation and XTS test case in the earlier versions. This error is rectified.

**Change Impact**

Applications that use the involved API may have compatibility issues.

**Key API/Component Changes**

Before change:

```ts
// interface AudioRenderer
getCurrentOutputDevices(callback: AsyncCallback<AudioDeviceDescriptors>): void
getCurrentOutputDevices(): Promise<AudioDeviceDescriptors>;
```

After change:

The API definition remains unchanged, but the API now correctly returns the **AudioDeviceDescriptors** type.

**Adaptation Guide**

If you implement the API according to the declared type, no adaptation is required.
If you refer to the original XTS test case to implement the API and mask the alarm indicating API definition mismatch during invoking, you must change the implementation accordingly.

## cl.multimedia.5 Implementation of Error Code 401 Modified for Synchronous APIs

For certain APIs that contain input parameters and is of API version 10, if a mandatory parameter is not passed in or an incorrect parameter type is passed in, the APIs should throw exceptions in synchronous mode based on the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

**Key API/Component Changes**

Before change:

```ts
// interface AudioRenderer
adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
adjustVolumeByStep(adjustType: VolumeAdjustType): Promise<void>;
adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise<void>;
getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback<number>): void;
getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise<number>;
setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
setAudioEffectMode(mode: AudioEffectMode): Promise<void>;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
```

After change:

```ts
// The description of error code 401 is adjusted.
@throws { BusinessError } 401 - Input parameter type or number mismatch.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If an exception is thrown, pass in parameters according to the API definition.
