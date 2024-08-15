# Deferred Photo Delivery (ArkTS)

As an important feature of the camera, deferred photo delivery enables the system, after receiving a photographing task from an application, to report images of different quality in multiple phases.
- In the first phase, the system quickly reports a low-quality image. The application receives a **PhotoAsset** object through the callback. Through this object, the application can call the mediaLibrary APIs to read the image or flush the image to the disk.
- In the second phase, the deferred photo delivery subservice performs scheduling based on the system pressure and custom scenarios, and sends the postprocessed original image to the mediaLibrary to replace the low-quality image.

Deferred photo delivery further reduces the response delay, delivering a better user experience.

To develop deferred photo delivery, perform the following steps:

- Listen for the **photoAssetAvailable** event through **PhotoOutput** to obtain a **PhotoAsset** object of [photoAccessHelper](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md).
- Call the mediaLibrary APIs to read or flush images to the disk through the **PhotoAsset** object.

> **NOTE**
> 
> - Deferred photo delivery varies according to the device and type. Therefore, if the device or type is changed, the deferred photo delivery capability may change.
> - Applications do not need to proactively enable deferred photo delivery. Instead, the camera framework checks whether the device and type support deferred photo delivery during stream assignment and if so, automatically enables deferred photo delivery.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import dependencies. Specifically, import the camera, image, and mediaLibrary modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   ```

2. Determine the photo output stream.

   You can use the **photoProfiles** attribute of the [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability) class to obtain the photo output streams supported by the device and use [createPhotoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createphotooutput11) to create a photo output stream.

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, 
                           cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${JSON.stringify(err)}`);
     }
     return photoOutput;
   }
   ```

3. Set the **photoAssetAvailable** callback.

   > **NOTE**
   > If the **photoAssetAvailable** callback has been registered and the **photoAvailable** callback is registered after the session starts, the stream will be restarted. Therefore, you are not advised to register both **photoAvailable** and **photoAssetAvailable**.
   
   ```ts
function photoAssetAvailableCallback(err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void {
     if (err) {
       console.error(`photoAssetAvailable error: ${JSON.stringify(err)}.`);
       return;
     }
     console.info('photoOutPutCallBack photoAssetAvailable');
     // You can call mediaLibrary APIs through photoAsset to customize image processing.
     // Processing method 1: Call the mediaLibrary flush API to save the low-quality image in the first phase. After the real image in the second phase is ready, the mediaLibrary proactively replaces the image flushed.
     // Processing method 2: Call the mediaLibrary API to request an image and register the buffer callback to receive the low-quality or high-quality image.
   }
   
   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
     photoOutput.on('photoAssetAvailable', photoAssetAvailableCallback);
   }
   ```
   
   For details about the mediaLibrary API used to flush images to the disk, see [saveCameraPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#savecameraphoto12).

   For details about the mediaLibrary API used to request images, see [requestimagedata](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestimagedata11) and [ondataprepare](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#ondataprepared11).

4. The session configuration and photography triggering mode are the same as those in the common photographing mode. For details, see steps 4-5 in [Camera Photographing (ArkTS)](camera-shooting.md).

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and errors of the photo output stream.

- Register the **'captureStart'** event to listen for photographing start events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the bottom layer starts exposure for photographing for the first time. The capture ID is returned.

  ```ts
  function onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture started, captureId : ${captureStartInfo.captureId}`);
    });
  }
  ```

- Register the **'captureEnd'** event to listen for photographing end events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the photographing is complete. [CaptureEndInfo](../../reference/apis-camera-kit/js-apis-camera.md#captureendinfo) is returned.

  ```ts
  function onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- Register the **'error'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode).

  ```ts
  function onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```
