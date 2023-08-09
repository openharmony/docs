# Using Performance Improvement Features (for System Applications Only)

The camera startup performance is affected by time-consuming operations such as power-on of underlying components and initialization of the process pipeline. To improve the camera startup speed and thumbnail display speed, OpenHarmony introduces some features. The capabilities of these features are related to underlying components. You need to check whether these capabilities are supported before using them.

These features are involved in the processes of starting the camera device, configuring streams, and taking photos. This topic describes the three scenarios.

## Deferred Stream Configuration

A typical camera startup process includes starting the camera device, configuring a data stream, and starting the data stream. Before configuring the data stream, you need to obtain the surface ID of the **\<XComponent>**.

The deferred stream configuration feature decouples stream configuration and start from the surface. Before the **\<XComponent>** provides the surface for the camera application, the system configures and starts the stream. This way, the surface only needs to be available before the stream is started. This improves the startup speed and prevents the implementation of other startup optimization schemas from being affected.

![deferred-surface-scene](figures/deferred-surface-scene.png)

Before optimization: Stream configuration depends on a **Surface** object, which is available after UI loading is complete. In other words, you can create a session, configure input and output streams, and start the session only after the UI is loaded. The camera HDI is responsible for stream configuration.

After optimization: Stream configuration does not depend on the **Surface** object. UI loading and stream configuration are executed concurrently. After the parameters are prepared, you can create a session.

### Available APIs

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

| API| Description|
| ---- | ---- |
| createDeferredPreviewOutput(profile: Profile): Promise\<PreviewOutput> | Creates a deferred **PreviewOutput** instance and adds it to the data stream instead of a common **PreviewOutput** instance during stream configuration.|
| addDeferredSurface(surfaceId: string): Promise\<void> | Adds a surface for delayed preview. This API can run after **session.commitConfig()** or **session.start()** is called.|

### Development Example

The figure below shows the recommended API call process.

![](figures/deferred-surface-sequence-diagram.png)

```js
import camera from '@ohos.multimedia.camera';

function async preview(context: Context, cameraInfo: camera.Device, previewProfile: camera.Profile, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput camera.CameraInput = await cameraManager.createCameraInput(cameraInfo)
  const previewOutput: camera.PreviewOutput = await cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = await cameraManager.createPhotoOutput(photoProfile);
  const session: camera.CaptureSession  = await this.mCameraManager.createCaptureSession();
  await session.beginConfig();
  await session.addInput(cameraInput);
  await session.addOutput(previewOutput);
  await session.addOutput(photoOutput);
  await session.commitConfig();
  await session.start();
  await previewOutput.addDeferredSurface(surfaceId);
}
```

## Quick Thumbnail

The photographing performance depends on the algorithm processing speed. A complex algorithm chain provides better image effect while requiring longer processing time.

To improve the photographing speed perceived by end users, the quick thumbnail feature is introduced. When the user takes a photo, a thumbnail is output and reported to the camera application for display before a real image is reported.

In this way, the photographing process is optimized, which fulfills the processing requirements of the post-processing algorithm without blocking the photographing speed of the foreground.

### Available APIs

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

| API| Description|
| ---- | ---- |
| isQuickThumbnailSupported() : boolean | Checks whether the quick thumbnail feature is supported.|
| enableQuickThumbnail(enabled:bool): void | Enables or disables the quick thumbnail feature.|
| on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void | Listens for camera thumbnails.|

> **NOTE**
>
> - **isQuickThumbnailSupported** and **enableQuickThumbnail** must be called after **CaptureSession.addOutput** and **CaptureSession.addInput** but before **CaptureSession.commitConfig()**.
> - **on()** takes effect after **enableQuickThumbnail(true)** is called.

### Development Example

The figure below shows the recommended API call process.

![](figures/quick-thumbnail-sequence-diagram.png)

```js
import camera from '@ohos.multimedia.camera'

this.cameraManager = camera.getCameraManager(globalThis.abilityContext);
let cameras = this.cameraManager.getSupportedCameras()
// Create a CaptureSession instance.
this.captureSession = await this.cameraManager.createCaptureSession()
// Start configuration for the session.
await this.captureSession.beginConfig()
// Add a CameraInput instance to the session.
this.cameraInput = await this.cameraManager.createCameraInput(cameras[0])
await this.cameraInput.open()
await this.captureSession.addInput(this.cameraInput)
// Add a PhotoOutput instance to the session.
this.photoOutPut = await this.cameraManager.createPhotoOutput(photoProfile, surfaceId)
await this.captureSession.addOutput(this.photoOutPut)
boolean isSupported = this.photoOutPut.isQuickThumbnailSupported()
if (isSupported) {
    // Enable the quick thumbnail feature.
    this.photoOutPut.enableQuickThumbnail(true)
    this.photoOutPut.on('quickThumbnail', (err, pixelmap) => {
    if (err || pixelmap === undefined) {
        Logger.error(this.tag, 'photoOutPut on thumbnail failed ')
        return
    }
    // Display or save the PixelMap instance.
    this.showOrSavePicture(pixelmap)
  })
}
```

## Prelaunch

Generally, the startup of the camera application is triggered when the user touches the camera icon on the home screen. The home screen senses the touch event and instructs the application manager to start the camera application. This takes a relatively long time. After the camera application is started, the camera startup process starts. A typical camera startup process includes starting the camera device, configuring a data stream, and starting the data stream, which is also time-consuming.

The prelaunch feature triggers the action of starting the camera device before the camera application is started. In other words, when the user touches the camera icon on the home screen, the system starts the camera device. At this time, the camera application is not started yet. The figure below shows the camera application process before and after the prelaunch feature is introduced.

![prelaunch-scene](figures/prelaunch-scene.png)

### Available APIs

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

| API| Description|
| ---- | ---- |
| isPrelaunchSupported(camera: CameraDevice) : boolean |  Checks whether the camera supports prelaunch.|
| setPrelaunchConfig(prelaunchConfig: PrelaunchConfig) : void | Sets the prelaunch parameters.|
| prelaunch() : void | Prelaunches the camera. This API is called when a user clicks the system camera icon to start the camera application.|

### Development Example

The figure below shows the recommended API call process.

![](figures/prelaunch-sequence-diagram.png)

- **Home screen**

  ```js
  import camera from '@ohos.multimedia.camera'

  this.cameraManager = camera.getCameraManager(globalThis.abilityContext);
  try {
    this.cameraManager.prelaunch(); 
  } catch (error) {
    console.error(`catch error: Code: ${error.code}, message: ${error.message}`)
  }
  ```

- **Camera application**

  To use the prelaunch feature, the camera application must configure the **ohos.permission.CAMERA** permission.

  For details about how to request and verify the permissions, see [Permission Application Guide](../security/accesstoken-guidelines.md).

  ```js
  import camera from '@ohos.multimedia.camera'

  this.cameraManager = camera.getCameraManager(globalThis.abilityContext);
  let cameras = this.cameraManager.getSupportedCameras()
  if(this.cameraManager.isPrelaunchSupported(cameras[0])) {
    try {
      this.cameraManager.setPrelaunchConfig({cameraDevice: cameras[0]});
    } catch (error) {
      console.error(`catch error: Code: ${error.code}, message: ${error.message}`)
    }
  }
  ```
