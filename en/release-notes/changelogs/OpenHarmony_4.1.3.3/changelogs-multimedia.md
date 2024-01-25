# Multimedia Subsystem Changelog

## cl.multimedia.1 AudioRenderer and AudioCapturer Callbacks Changed

**Access Level**

Public

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

Public

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
