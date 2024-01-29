# Multimedia Subsystem Changelog

## cl.multimedia.1 Implementation of Error Code 5400102 Corrected

If a parameter passed in to an API is incorrect or an API is called in an incorrect state (for example, **play()** is called before **load()** is complete), the API should throw an error according to the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void
play(soundID: number, callback: AsyncCallback<number>): void
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number, callback: AsyncCallback<void>): void
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
```

Error code 5400102 is declared in these APIs.

```ts
@throws { BusinessError } 5400102 - Operation not allowed.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400102 is thrown, call the API according to the API definition.

## cl.multimedia.2 Implementation of Error Code 5400103 Corrected

If an I/O error occurs during the interaction between the media module and other modules, the API should throw an error according to the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number, callback: AsyncCallback<number>): void
load(fd: number, offset: number, length: number): Promise<number>
unload(soundID: number): Promise<void>
```

Error code 5400103 is declared in these APIs.

```ts
@throws { BusinessError } 5400103 - I/O error.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400103 is thrown, call the API according to the API definition.

## cl.multimedia.3 Implementation of Error Code 5400105 Corrected

If the playback service is dead when an API is called, the API should throw an error according to the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
release(): Promise<void>
```

Error code 5400105 is declared in these APIs.

```ts
@throws { BusinessError } 5400105 - Service died.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400105 is thrown, call the API according to the API definition.

## cl.multimedia.4 Implementation of SoundPool.on('loadComplete') Corrected

According to the API definition, if an error occurs during sound loading, **on('error')** is triggered to throw the error. There is no need for the system to throw errors in **on('loadComplete')**.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
on(type: 'loadComplete', callback: Callback<number>): void
```

No error code is declared in this API.

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If an error occurs during sound playback, **on('error')** will be triggered to throw the error.

## cl.multimedia.5 Implementation of SoundPool.on('playFinished') Corrected

According to the API definition, if an error occurs during sound playback, **on('error')** is triggered to throw the error. There is no need for the system to throw errors in **on('loadComplete')**.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
on(type: 'playFinished', callback: Callback<void>): void
```

No error code is declared in this API.

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If an error occurs during sound playback, **on('error')** will be triggered to throw the error.

## cl.multimedia.6 Implementation of Error Code 401 Corrected

If a mandatory parameter is not passed in to an API, the API should throw an error according to the API declaration.
However, these APIs do not throw exceptions as expected. This error is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void;
play(soundID: number, callback: AsyncCallback<number>): void;
play(soundID: number, params?: PlayParameters): Promise<number>;
stop(streamID: number, callback: AsyncCallback<void>): void;
stop(streamID: number): Promise<void>;
setLoop(streamID: number, loop: number, callback: AsyncCallback<void>): void;
setLoop(streamID: number, loop: number): Promise<void>;
setPriority(streamID: number, priority: number, callback: AsyncCallback<void>): void;
setPriority(streamID: number, priority: number): Promise<void>;
setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback<void>): void;
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>;
setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback<void>): void;
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>;
```

Error code 401 is declared in these APIs.

```ts
@throws { BusinessError } 401 - The parameter check failed. Return by callback.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 401 is thrown, pass in the mandatory parameters and call the API according to the API definition.

## cl.multimedia.1 AudioRenderer and AudioCapturer Callbacks Changed

**Access Level**

Public APIs

**Reason for Change**

The callbacks of the **AudioRenderer** and **AudioCapturer** classes are changed to accurately indicate the device used to play or record the current stream.

**Change Impact**

In non-playback or non-recording state, **AudioRendererChangeInfo.deviceDescriptors** and **AudioCapturerChangeInfo.deviceDescriptors** are empty.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

Before change: 

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

In non-playback or non-recording state, **AudioRendererChangeInfo.deviceDescriptors** and **AudioCapturerChangeInfo.deviceDescriptors** the device that played or recorded the audio stream last time.

After change:

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

In non-playback or non-recording state, **AudioRendererChangeInfo.deviceDescriptors** and **AudioCapturerChangeInfo.deviceDescriptors** are empty.

**Adaptation Guide**

If you want to obtain the current audio capturer or renderer through the callbacks, you must start audio playback or recording first.

## cl.multimedia.2 Behavior Changed for open() and on() of CameraInput

**Access Level**

Public APIs

**Reason for Change**

The preemption mechanism is added to **open()** of the **CameraInput** class to ensure that high-priority applications can preferentially use the camera. As such, the behavior of **open()** and **on()** changes.

**Change Impact**

This change is incompatible with earlier versions. Applications that use the involved APIs may have compatibility issues.

**Change Since**

OpenHarmony SDK 4.1.3.3

**Key API/Component Changes**

Before change: 

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

When application A is using the camera, application B fails to open the camera using **open()**, and the error code **CONFLICT_CAMERA** is returned.

After change:

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

When application A is using the camera, application B can successfully open the camera using **open()** if application B has a higher priority than application A, for example, if application B is in the foreground while application A in the background.

The error code **DEVICE_PREEMPTED** is not returned.

**Adaptation Guide**

If your code involves the use of **on()** in **CameraInput**, add the logic for processing the **DEVICE_PREEMPTED** error code.

## cl.multimedia.1 getValidCommandsSync Changed

**Access Level**

Public APIs

**Reason for Change**

In earlier versions, the return value of **getValidCommandsSync()** is incorrectly defined as int. It is corrected to **AVControlCommandType**.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

getValidCommandsSync(): Array<AVControlCommandType>

**Adaptation Guide**

Before change: 

When you use a created **AVSession** object to obtain the commands supported by the controller, the return value is an int array.

let validCommands = avsession.getController().getValidCommandsSync();

For example, if the application registers only the **play** command callback, validCommands[0] is 0.

After change:

When you use a created **AVSession** object to obtain the commands supported by the controller, the return value is an array of **AVControlCommandType** strings.

let validCommands = avsession.getController().getValidCommandsSync();

For example, if the application registers only the **play** command callback, validCommands[0] is **'play'**.

## cl.multimedia.1 getDevices Changed

**Access Level**

Public APIs

**Reason for Change**

**getDevices** returns a device with an earpiece only when the device is in a call.

**Change Impact**

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece even when the device is not in a call.

**Change Since**

OpenHarmony SDK 4.1.5.1

**Key API/Component Changes**

Before change: 

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece only in the call scenario.

After change:

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece even when the device is not in a call.

**Adaptation Guide**

Add the logic for determining whether a device contains an earpiece in your code.
