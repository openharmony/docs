# Multimedia Subsystem Changelog

## cl.multimedia.1 Implementation Error of AudioRenderer.getCurrentOutputDevices Corrected

According to the definition, the **getCurrentOutputDevices** API of the **AudioRenderer** class should return the **AudioDeviceDescriptors** type, that is, an array of the **AudioDeviceDescriptor** types. However, the **AudioDeviceDescriptor** type is returned in the API implementation and XTS test case in the earlier versions. This error is rectified.

**Change Impact**

Applications that use the involved API may have compatibility issues.

**Key API/Component Changes**

Before change:

```ts
// AudioRenderer API
getCurrentOutputDevices(callback: AsyncCallback<AudioDeviceDescriptors>): void
getCurrentOutputDevices(): Promise<AudioDeviceDescriptors>;
```

After change:

The API definition remains unchanged, but the API now correctly returns the **AudioDeviceDescriptors** type.

**Adaptation Guide**

If you implement the API according to the declared type, no adaptation is required.
If you refer to the original XTS test case to implement the API and mask the alarm indicating API definition mismatch during invoking, you must change the implementation accordingly.

## cl.multimedia.2 Implementation of Error Code 401 Modified for Synchronous APIs

For certain APIs that contain input parameters and is of API version 10, if a mandatory parameter is not passed in or an incorrect parameter type is passed in, the APIs should throw exceptions in synchronous mode based on the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

**Key API/Component Changes**

Before change:

```ts
// AudioRenderer API
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
