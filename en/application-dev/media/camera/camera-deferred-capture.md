# Deferred Photo Delivery (ArkTS)

As an important feature of the camera, deferred photo delivery enables the system, after receiving a photo capture task from an application, to report images of different quality levels in multiple phases.
- In the first phase, the system promptly delivers an image that has undergone lightweight processing, offering a balance between reduced quality and swift image availability. The application receives a PhotoAsset object through the callback. Through this object, the application can call the media library APIs to read the image or flush the image to the disk.
- In the second phase, the camera framework enhances the image to achieve full quality, either in response to the application's request for higher quality or when the system is not busy. The enhanced image is then sent back to the media library to replace the previously provided one.

Deferred photo delivery further reduces the response delay, delivering a better user experience.

To develop deferred photo delivery, perform the following steps:

- Listen for the **photoAssetAvailable** event through **PhotoOutput** to obtain a PhotoAsset object of [photoAccessHelper](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md).
- Call the media library APIs to read or flush images to the disk through the PhotoAsset object.

> **NOTE**
> 
> - Deferred photo delivery varies according to the device and type. Therefore, if the device or type is changed, the deferred photo delivery capability may change.
> - Applications do not need to proactively enable deferred photo delivery. Instead, the camera framework checks whether the device and type support deferred photo delivery during stream configuration and if so, automatically enables deferred photo delivery.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import dependencies. Specifically, import the camera, image, and media library modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
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
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. Set the **photoAssetAvailable** callback.

   > **NOTE**
   > 
   > If the **photoAssetAvailable** callback has been registered and the **photoAvailable** callback is registered after the session starts, the stream will be restarted. In this case, only the **photoAssetAvailable** callback takes effect. Therefore, you are not advised to register both **photoAvailable** and **photoAssetAvailable**.

   ```ts
   function getPhotoAccessHelper(context: Context): photoAccessHelper.PhotoAccessHelper {
     let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
     return phAccessHelper;
   }

   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput, context: Context): void {
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset) => {
       if (err) {
         console.error(`photoAssetAvailable error: ${err}.`);
         return;
       }
       console.info('photoOutPutCallBack photoAssetAvailable');
       // You can call media library APIs through photoAsset to customize image processing.
       // Processing method 1: Call the media library API to save the image in the first phase. After the image in the second phase is ready, the media library proactively replaces the image flushed.
       mediaLibSavePhoto(photoAsset, getPhotoAccessHelper(context));
       // Processing method 2: Call the media library API to request an image and register the buffer callback to receive the first-phase or second-phase image.
       mediaLibRequestBuffer(photoAsset, context);
     });
   }

   async function mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
     phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
     try {
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
       assetChangeRequest.saveCameraPhoto();
       await phAccessHelper.applyChanges(assetChangeRequest);
       console.info('apply saveCameraPhoto successfully');
     } catch (err) {
       console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
     }
   }

   class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
     onDataPrepared(data: ArrayBuffer) {
       if (data === undefined) {
         console.error('Error occurred when preparing data');
         return;
       }
       // The application can customize the processing after obtaining the image buffer.
       console.info('on image data prepared');
     }
   }

   async function mediaLibRequestBuffer(photoAsset: photoAccessHelper.PhotoAsset, context: Context) {
     let requestOptions: photoAccessHelper.RequestOptions = {
       // Configure the image return mode based on service requirements.
       // FAST_MODE: callback for receiving the first-phase image
       // HIGH_QUALITY_MODE: callback for receiving the second-phase image
       // BALANCE_MODE: callback for receiving both images
       deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
     }
     const handler = new MediaDataHandler();
     await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, handler);
     console.info('requestImageData successfully');
   }
   ```

   For details about the API used to flush images, see [saveCameraPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#savecameraphoto12).

   For details about the APIs used to request images, see [requestImageData](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestimagedata11) and [onDataPrepared](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#ondataprepared11).

4. The session configuration and photo capture triggering mode are the same as those in the common photo capture mode. For details, see steps 4-5 in [Photo Capture (ArkTS)](camera-shooting.md).

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and errors of the photo output stream.

- Register the **'captureStart'** event to listen for photo capture start events. This event can be registered when a PhotoOutput instance is created and is triggered when the camera device starts photo capture. The capture ID is returned.

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

- Register the **'captureEnd'** event to listen for photo capture end events. This event can be registered when a PhotoOutput instance is created and is triggered when the photo capture is complete. [CaptureEndInfo](../../reference/apis-camera-kit/js-apis-camera.md#captureendinfo) is returned.

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

- Register the **'captureReady'** event to obtain the result of the next photo capture. This event can be registered when a PhotoOutput instance is created and is triggered when the camera device is ready for taking a photo. The information about the next photo capture is returned.

  ```ts
  function onPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureReady', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture ready`);
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
