# Camera Subsystem Changelog

OpenHarmony 4.1.6.1 has the following changes.

## cl.camera.1 API getSupportedOutputCapability Changed

**Access Level**

Public API

**Reason for Change**

The input parameter **mode: SceneMode** is added so that the API **getSupportedOutputCapability** can be used to query the output capability supported by the camera in the specified scene mode.

**Change Impact**

The API **getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability** is deprecated in API version 11 and will be retained for five more versions.

The API **getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability** is added in API version 11.

**Key API/Component Changes**

- Involved API:

  getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability

- Before change:

  The input parameter is **camera: CameraDevice**.

- After change:

  The input parameter **mode: SceneMode** is added.

**Adaptation Guide**

Call **getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode\>** to obtain the scene modes supported by the camera, and then call **getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability** to obtain the output capability supported by the camera in the specified scene mode.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

## cl.camera.2 API createPhotoOutput Changed

**Access Level**

Public API

**Reason for Change**

The input parameter **surfaceId: string** is deleted so that the API **createPhotoOutput** can be used to create a **PhotoOutput** object only based on the photo configuration.

**Change Impact**

The API **createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput** is deprecated in API version 11 and will be retained for five more versions.

The API **createPhotoOutput (profile: Profile): PhotoOutput** is added in API version 11.

**Key API/Component Changes**

- Involved API:

  createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

- Before change:

  The input parameters are **profile** (specifying the supported photo configuration) and **surfaceId** (specifying the surface ID obtained from **ImageReceiver**).

- After change:

  The input parameter contains only **profile**.

**Adaptation Guide**

Use **createPhotoOutput(profile: Profile): PhotoOutput** to create a **PhotoOutput** object.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

## cl.camera.3 API createCaptureSession Changed

**Access Level**

Public API

**Reason for Change**

Since API version 11, sessions are classified into photo sessions and video sessions, which are created by using the new API **createSession\<T extends Session\>(mode: SceneMode): T**.

**Change Impact**

The API **createCaptureSession(): CaptureSession** is deprecated in API version 11 and will be retained for five more versions.

The API **createSession\<T extends Session\>(mode: SceneMode): T** is added in API version 11.

**Key API/Component Changes**

- Involved API:

  createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

- Before change:

  **createCaptureSession(): CaptureSession** is used to create a **CaptureSession** instance.

- After change:

  **createSession\<T extends Session\>(mode: SceneMode): T** is used to create a **PhotoSession** or **VideoSession** instance.

**Adaptation Guide**

Call **createSession\<T extends Session\>(mode: SceneMode): T** to create a **PhotoSession** or **VideoSession** instance.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

## cl.camera.4 API CaptureSession Changed

**Access Level**

Public API

**Reason for Change**

**CaptureSession** is used to store all resources **CameraInput** and **CameraOutput** required for running a camera, and apply to the camera device for a photo session or video session.

**Change Impact**

**CaptureSession** and its APIs are deprecated in API version 11 and will be retained for five more versions.

**PhotoSession** and **VideoSession** are added in API version 11 to distinguish photo sessions and video sessions.

**Key API/Component Changes**

- Involved API:

  CaptureSession

- Before change:

  **createCaptureSession(): CaptureSession** is used to create a **CaptureSession** instance.

- After change:

  **createSession\<T extends Session\>(mode: SceneMode): T** is used to create a **PhotoSession** or **VideoSession** instance.

**Adaptation Guide**

Use the **PhotoSession** and **VideoSession** classes.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

## cl.camera.5 APIs start() and stop() of PreviewOutput Changed

**Access Level**

Public API

**Reason for Change**

The start and stop operations of **PreviewOutput** can be included in the start and stop operations of the session.

**Change Impact**

The **start()** and **stop()** APIs of the **PreviewOutput** class is deprecated in API version 11 version and will be retained for five more versions. The operations are included in the start and stop operations of the session.

**Key API/Component Changes**

- Involved API:

  **start()** and **stop()** APIs of the **PreviewOutput** class

- Before change:

  interface PreviewOutput extends CameraOutput
    start(callback: AsyncCallback\<void\>): void
    start(): Promise\<void\>
    stop(callback: AsyncCallback\<void\>): void
    stop(): Promise\<void\>

- After change:

  The **start()** and **stop()** APIs of the **PhotoSession** or **VideoSession** class are used to trigger the start and end operations.

**Adaptation Guide**

No adaptation is required. The start and stop operations of **PreviewOutput** are triggered by the **start()** and **stop()** APIs of the **PhotoSession** or **VideoSession** class.

## cl.camera.6 APIs for Subscribing to or Unsubscribing from the captureStart Event Changed

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Access Level**

Public API

**Reason for Change**

The **'captureStart'** event is used to listen for the start of photographing, and the capture ID is returned through the callback. In API version 11, the **'captureStartWithInfo'** event is used, and more information is returned.

**Change Impact**

The APIs for subscribing to or unsubscribing from the **'captureStart'** event are deprecated in API version 11 and will be retained for five more versions.

The APIs for subscribing to or unsubscribing from the **'captureStartWithInfo'** events are added to API version 11. The **CaptureStartInfo** struct is returned through the callback, which can be extended to obtain more information.

**Key API/Component Changes**

- Involved API:

  on(type: 'captureStart', callback: AsyncCallback\<number\>): void
  off(type: 'captureStart', callback?: AsyncCallback\<number\>): void

- Before change:

  The **'captureStart'** event is used, and the capture ID is returned through the callback.

- After change:

  The **CaptureStartInfo** struct is used to return more information.
  The API **on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void** is added.
  The API **off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo\>): void** is added.

**Adaptation Guide**

Use the new APIs to obtain the **CaptureStartInfo** struct.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3
