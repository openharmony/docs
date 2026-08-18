# YUV Photo Capture (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9a88338888413bc410a855d79b95bea9e0b612b8 translatedAt=2026-08-10T09:18:38.192Z pushedAt=2026-08-10T13:52:24.624Z -->

Starting from API version 23, the camera framework provides YUV image capture capability. Compared with standard photo capture, YUV capture obtains unencoded image data that fully retains the raw luminance and chrominance information captured by the sensor, making it suitable for video encoding or professional processing. However, the capture process incurs higher power consumption, and saving the data requires more storage space.

## How to Develop

For detailed camera API descriptions, see [Camera Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md).

1. Import dependent modules.

   To obtain photo output data, you need to use the system-provided `image`, `dataSharePredicates`, and `photoAccessHelper` API capabilities as follows.

   <!-- @[import_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

   ``` TypeScript
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { dataSharePredicates } from '@kit.ArkData';
   import { image } from '@kit.ImageKit';
   import { fileIo } from '@kit.CoreFileKit';
   ```

2. Obtain the full output capability of the camera device.

   Use the [getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23) method to obtain the capabilities of all output streams supported by the current camera device, including preview streams, photo streams, and video streams. The output streams are available in the profile fields of [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability), where photo streams support the YUV format.

   <!-- @[get_full_outputCapability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

   ``` TypeScript
     getFullOutputCapability(cameraManager: camera.CameraManager, cameraDevice: camera.CameraDevice,
       sceneMode: camera.SceneMode): camera.CameraOutputCapability | undefined {
       let cameraOutputCapability = cameraManager.getSupportedFullOutputCapability(cameraDevice, sceneMode);
       if (!cameraOutputCapability) {
         console.error('cameraManager.getSupportedFullOutputCapability error');
         return undefined;
       }
       // ...
       return cameraOutputCapability;
   }
   ```

3. Create a photo output stream.

   Use the `photoProfiles` property in [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) to obtain the photo output streams supported by the current device.

   Call the [createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11) method and pass in a supported output stream [profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile) to create a photo output stream.

   Obtain the full output capability `cameraOutputCapability` supported by the camera through [getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23), as described in step 2. From the `photoProfiles` of `cameraOutputCapability`, select a profile that supports the YUV format as the `photoProfile` parameter for creating the photo output stream.

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, photoProfile: camera.Profile): camera.PhotoOutput | undefined {
     // Create a photo output stream.
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfile);
     } catch (error) {
       let err = error as BusinessError;
       console.error("Failed to createPhotoOutput. error: ${err}");
     }
     return photoOutput;
   }
   ```

4. Set the callback for the photo output stream.

   Set the callback for one-shot photo capture [onCapturePhotoAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#oncapturephotoavailable23) or deferred photo capture [on('photoAssetAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoassetavailable12), and save the captured pixelMap data as an image. If your app needs to quickly obtain the returned image, segmented capture callback is recommended.

   For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   To view the saved images and videos in Gallery, you need to save them to the media library first. For details about how to save, see [Saving Media Assets](../medialibrary/photoAccessHelper-savebutton.md).

   To obtain the buffer from the [onCapturePhotoAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#oncapturephotoavailable23) API, first save the [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) data to the media library through a security component.

   - **one-shot photo capture (onCapturePhotoAvailable) development process**:

     - Register the one-shot photo capture callback before calling [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11-1) on the session.

     - In the one-shot photo capture callback function, obtain the image information, parse the pixelMap data, and perform custom business processing.

     - Return the processed pixelMap through the callback for image display or write it to a file through a security component to save the image.

- After use, unregister the one-shot photo capture callback function.

     <!-- @[set_photo_cb_single](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

     ``` TypeScript
     setPhotoOutputCbSingle(photoOutput: camera.PhotoOutput, context: Context) {
       // After the callback is set, calling the capture method of photoOutput returns the captured pixelMap through the callback.
       photoOutput.onCapturePhotoAvailable((capturePhoto: camera.CapturePhoto): void => {
         if (capturePhoto === undefined) {
           Logger.error(TAG_LOG, 'getPhoto failed');
           return;
         }
     
         Logger.info(TAG_LOG, 'photoAvailable success');
         this.mediaLibSavePhotoSingle(context, capturePhoto.main)
       });
     }
     
     async mediaLibSavePhotoSingle(context: Context, imageObj: image.Image | image.Picture) {
       let picture: image.Picture = imageObj as image.Picture;
       Logger.info(TAG_LOG, 'picture GetMainPixelmap E');
       await this.GetMainPixelmap(context, picture);
       Logger.info(TAG_LOG, 'picture GetMainPixelmap X');
     
       Logger.info(TAG_LOG, 'picture Release E');
       await this.Release(picture);
       Logger.info(TAG_LOG, 'picture Release X');
     }
     
     async packToFileFromPixelMap(context : Context, pixelMap : image.PixelMap) {
       const imagePackerApi = image.createImagePacker();
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 95 };
       const path : string = context.cacheDir + '/pixel_map.jpg';
       let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
       try {
         await imagePackerApi.packToFile(pixelMap, file.fd, packOpts);
         this.srcFileUri = file.path;
       } catch (error) {
         Logger.error(TAG_LOG, `Failed to pack the pixelMap to file. And the errorcode: ${error.code} ,error.message: ${error.message}`);
       }
     }
     
     async saveFile(srcFileUri: string, phAccessHelper: photoAccessHelper.PhotoAccessHelper){
       try {
         // Specify the URI of the image in the application sandbox to be saved to the media library.
         let srcFileUris: string[] = [
           srcFileUri
         ];
         // Specify the creation options for the photo to be saved, including the file extension and photo type. The title and photo subtype are optional.
         let photoCreationConfigs: photoAccessHelper.PhotoCreationConfig[] = [
           {
             title: 'test', // Optional.
             fileNameExtension: 'jpg',
             photoType: photoAccessHelper.PhotoType.IMAGE,
             subtype: photoAccessHelper.PhotoSubtype.DEFAULT, // Optional.
           }
         ];
         // Obtain the target URI of the media library through dialog-based authorization.
         let desFileUris: string[] = await phAccessHelper.showAssetsCreationDialog(srcFileUris, photoCreationConfigs);
         // Write the photo content from the application sandbox to the target URI of the media library.
         let desFile: fileIo.File = await fileIo.open(desFileUris[0], fileIo.OpenMode.WRITE_ONLY);
         let srcFile: fileIo.File = await fileIo.open(srcFileUri, fileIo.OpenMode.READ_ONLY);
         await fileIo.copyFile(srcFile.fd, desFile.fd);
         fileIo.closeSync(srcFile);
         fileIo.closeSync(desFile);
         console.info('create asset by dialog successfully');
       } catch (err) {
         console.error(`failed to create asset by dialog successfully errCode is: ${err.code}, ${err.message}`);
       }
     }
     
     // Obtain the pixelMap of the main photo captured.
     async GetMainPixelmap(context: Context, pictureObj : image.Picture) {
       let funcName = 'getMainPixelmap';
       if (pictureObj != null) {
         let mainPixelmap: image.PixelMap = pictureObj.getMainPixelmap();
         if (mainPixelmap != null) {
           // Encode.
           await this.packToFileFromPixelMap(context, mainPixelmap);
           // Save.
           let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
           this.saveFile(this.srcFileUri, phAccessHelper);
     
           this.callback(mainPixelmap, '');
           mainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
             if (imageInfo != null) {
               Logger.info(TAG_LOG, 'GetMainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width +
                 ' pixelFormat:' + imageInfo.pixelFormat + ' isHdr:' + imageInfo.isHdr);
             }
           }).catch((error: BusinessError) => {
             Logger.error(TAG_LOG, `Failed error.code: ${error.code} ,error.message: ${error.message}`);
           });
         } else {
           Logger.error(TAG_LOG, 'PictureObj getMainPixelmap is null');
         }
       } else {
         Logger.error(TAG_LOG, 'PictureObj is null');
       }
     }
     
     // Release resources.
     async Release(pictureObj : image.Picture) {
       let funcName = 'Release';
       if (pictureObj != null) {
         pictureObj.release();
         if (pictureObj.getMainPixelmap() == null) {
           Logger.info(TAG_LOG, 'PictureObj release Success !');
         } else {
           Logger.error(TAG_LOG, 'PictureObj release Failed !');
         }
       } else {
         Logger.error(TAG_LOG, 'PictureObj is null');
       }
     }
     ```

   - **deferred photo capture (PhotoAvailable) development process**:

     - Before the session [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11-1), register the deferred photo capture callback.

     - In the deferred photo capture callback function, obtain image information, parse the pixelMap data, and perform custom business processing.

     - Pass the processed pixelMap back for image display or save the image to a file through a security control.

     - After calling [capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2) to take a photo, promptly call [saveCameraPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#savecameraphoto12) to save the image or [discardCameraPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#discardcameraphoto12) to cancel saving. Otherwise, subsequent photo capture will be affected.

     - Unregister the deferred photo capture callback function after use.

     <!-- @[set_photo_cb_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

     ``` TypeScript
     // Save the image.
     async mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
       phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
       try {
         let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
           new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
         Logger.info(TAG_LOG, `saveCameraPhoto E`);
         await assetChangeRequest.saveCameraPhoto(photoAccessHelper.ImageFileType.JPEG);
         await phAccessHelper.applyChanges(assetChangeRequest);
         Logger.info(TAG_LOG, `saveCameraPhoto X`);
         await phAccessHelper.release();
       } catch (error) {
         Logger.error(TAG_LOG, `apply saveCameraPhoto failed with error: ${error.code}, ${error.message}`);
       }
     }
     
     async mediaLibRequestBuffer(photoAsset: photoAccessHelper.PhotoAsset, context: Context,
       callback: (pixelMap: image.PixelMap, url: string) => void) {
       // Obtain the image pixelMap information.
       try {
         Logger.info(TAG_LOG, 'quickRequestImage E');
     
         class MediaDataHandler implements photoAccessHelper.QuickImageDataHandler<image.Picture> {
           onDataPrepared(data: image.Picture, imageSource: image.ImageSource, map: Map<string, string>) {
             if (data != undefined) {
               console.info(`On photoAssetAvailable callback data is not undefined`);
               let pixelMap: image.PixelMap = data.getMainPixelmap();
               callback(pixelMap, photoAsset.uri);
             } else if (data === undefined && imageSource != undefined) {
               console.info(`On photoAssetAvailable callback data is undefined, and imageSource is not undefined`);
               imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
                 callback(pixelMap, photoAsset.uri);
               }).catch((error: BusinessError) => {
                 console.error(`On photoAssetAvailable callback createPixelMap failed, error: ${error.message}`);
               })
             } else {
               console.error(`On photoAssetAvailable callback data and imageSource are both undefined`);
               return;
             }
           }
         }
         // Create a data share predicate.
         let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
         // Configure the media asset retrieval conditions.
         let fetchOptions: photoAccessHelper.FetchOptions = {
           fetchColumns: [],
           predicates: predicates
         };
         // Configure the request strategy to balanced mode.
         let requestOptions: photoAccessHelper.RequestOptions = {
           deliveryMode: photoAccessHelper.DeliveryMode.BALANCE_MODE,
         }
     
         const handler = new MediaDataHandler();
         await photoAccessHelper.MediaAssetManager.quickRequestImage(context, photoAsset, requestOptions, handler);
       } catch (error) {
         Logger.error(TAG_LOG, `mediaLibRequestBuffer failed with error: ${error.code}, ${error.message}`);
       }
     }
     
     
     public setPhotoOutputCbDouble(cameraPhotoOutput: camera.PhotoOutput) {
       Logger.info(TAG_LOG, 'setPhotoOutputCbDouble ...');
       cameraPhotoOutput.on('photoAssetAvailable',
         async (_err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): Promise<void> => {
           try {
             Logger.info(TAG_LOG, `on photoAssetAvailable callback uri:${photoAsset.uri}`);
             let accessHelper: photoAccessHelper.PhotoAccessHelper =
               photoAccessHelper.getPhotoAccessHelper(this.context);
             await this.mediaLibSavePhoto(photoAsset, accessHelper);
             await this.mediaLibRequestBuffer(photoAsset, this.context, this.callback);
           } catch (_err) {
             Logger.error(TAG_LOG, `photoAssetAvailable err:${_err.code}`);
           }
         });
     }
     ```

5. Trigger capture.

Call the [capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2) method of `photoOutput` to execute the capture task. This method has two parameters. The first parameter is the capture settings (`setting`), where you can configure the image quality, image rotation angle, and other information. The second parameter is an asynchronous callback used to return the result. If the API call fails, a corresponding error code is returned.

You can obtain the capture rotation angle through the [getPhotoRotation](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#getphotorotation12) method in `PhotoOutput`.

You can obtain the image geographic location information through the [geoLocationManager.getCurrentLocation](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation) method in `geoLocationManager`. For usage, refer to the [capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-3) example.

   <!-- @[capture_photo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

   ``` TypeScript
   public async capture(isFront: boolean) {
     Logger.info(TAG_LOG, 'capture start.');
     const degree = await this.getPhotoDegree();
     let rotation = this.getPhotoRotation(this.output!, degree);
     rotation = camera.ImageRotation.ROTATION_0;
     Logger.info(TAG_LOG, `rotation: ${rotation}.`);
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,  // Set the image quality.
       rotation,  // Set the image rotation angle.
       mirror: isFront  // Set the mirror enable switch.
     };
     this.output?.capture(settings, (err: BusinessError) => {
       if (err) {
         Logger.error(TAG_LOG, `Failed to capture the photo. error: ${JSON.stringify(err)}`);
         return;
       }
       Logger.info(TAG_LOG, 'Callback invoked to indicate the photo capture request success.');
     });
   }
   ```

## Status Monitoring

During camera app development, you can monitor the photo output stream status at any time, including the start of the photo stream, the start and end of capture frames, whether the next capture is ready, and errors in the photo output stream.

- Register the `captureStart` callback to listen for the capture start result. You can start listening once `photoOutput` is created. This event is triggered when the camera device is about to start the current capture, and it returns the `captureId` of this capture.

  <!-- @[set_capture_start_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

  ``` TypeScript
  onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture started, captureId : ${captureStartInfo.captureId}`);
    });
  }
  ```

- Register the `captureEnd` callback to listen for the capture end result. You can start listening once `photoOutput` is created. This event returns the related information after the capture is fully completed, as described in [CaptureEndInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#captureendinfo).

  <!-- @[set_capture_end_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

  ``` TypeScript
  onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- Register the `captureReady` callback to listen for whether the next capture can be taken. You can start listening once `photoOutput` is created. This event is triggered when the next capture is ready, and it returns the related information about the readiness for the next capture.

  <!-- @[set_capture_ready_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

  ``` TypeScript
  captureReadyCallback(err: BusinessError): void {
    if (err !== undefined && err.code !== 0) {
      Logger.error(TAG_LOG, `Callback Error, errorCode: ${err.code}`);
      return;
    }
    Logger.info(TAG_LOG, `photo capture ready`);
  }
  
  registerPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    Logger.info(TAG_LOG, `register PhotoOutput Capture Ready...`);
    photoOutput.on('captureReady', this.captureReadyCallback);
  }
  
  unregisterPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    Logger.info(TAG_LOG, `unregister PhotoOutput Capture Ready...`);
    photoOutput.off('captureReady');
  }
  ```

- Register a fixed `error` callback to listen for error results of the photo output stream. The callback returns the corresponding error code when the photo output interface encounters an error. For details about the error codes, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

  <!-- @[set_photo_error_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->

  ``` TypeScript
  onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```