# Camera Photographing (ArkTS)

Photographing is an important function of the camera application. Based on the complex logic of the camera hardware, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the image module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.
     
   ```ts
   import image from '@ohos.multimedia.image';
   import camera from '@ohos.multimedia.camera';
   import { BusinessError } from '@ohos.base';
   ```

2. Obtain the surface ID.
   
   Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and use **getReceivingSurfaceId()** of the instance to obtain the surface ID, which is associated with the photo output stream to process the data output by the stream.
 
   ```ts
   async function getImageReceiverSurfaceId(): Promise<string | undefined> {
     let photoSurfaceId: string | undefined = undefined;
     let receiver: image.ImageReceiver = image.createImageReceiver(640, 480, 4, 8);
     console.info('before ImageReceiver check');
     if (receiver !== undefined) {
       console.info('ImageReceiver is ok');
       photoSurfaceId = await receiver.getReceivingSurfaceId();
       console.info(`ImageReceived id: ${JSON.stringify(photoSurfaceId)}`);
     } else {
       console.info('ImageReceiver is not ok');
     }
     return photoSurfaceId;
   }
   ```

3. Create a photo output stream.
   
   Obtain the photo output streams supported by the current device from **photoProfiles** in **CameraOutputCapability**, and then call **createPhotoOutput()** to pass in a supported output stream and the surface ID obtained in step 1 to create a photo output stream.

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, photoSurfaceId: string): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0], photoSurfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${JSON.stringify(err)}`);
     }
     return photoOutput;
   }
   ```

4. Set camera parameters.

   You can set camera parameters to adjust photographing functions, including the flash, zoom ratio, and focal length.

   ```ts
   function configuringSession(captureSession: camera.CaptureSession): void {
     // Check whether the camera has flash.
     let flashStatus: boolean = false;
     try {
       flashStatus = captureSession.hasFlash();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to hasFlash. error: ${JSON.stringify(err)}`);
     }
     console.info(`Promise returned with the flash light support status: ${flashStatus}`);
     if (flashStatus) {
       // Check whether the auto flash mode is supported.
       let flashModeStatus: boolean = false;
       try {
         let status: boolean = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
         flashModeStatus = status;
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to check whether the flash mode is supported. error: ${JSON.stringify(err)}`);
       }
       if (flashModeStatus) {
         // Set the flash mode to auto.
         try {
           captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
         } catch (error) {
           let err = error as BusinessError;
           console.error(`Failed to set the flash mode. error: ${JSON.stringify(err)}`);
         }
       }
     }
     // Check whether the continuous auto focus is supported.
     let focusModeStatus: boolean = false;
     try {
       let status: boolean = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       focusModeStatus = status;
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to check whether the focus mode is supported. error: ${JSON.stringify(err)}`);
     }
     if (focusModeStatus) {
       // Set the focus mode to continuous auto focus.
       try {
         captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to set the focus mode. error: ${JSON.stringify(err)}`);
       }
     }
     // Obtain the zoom ratio range supported by the camera.
     let zoomRatioRange: Array<number> = [];
     try {
       zoomRatioRange = captureSession.getZoomRatioRange();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to get the zoom ratio range. error: ${JSON.stringify(err)}`);
     }
     if (zoomRatioRange.length <= 0 ) {
       return;
     }
     // Set a zoom ratio.
     try {
       captureSession.setZoomRatio(zoomRatioRange[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to set the zoom ratio value. error: ${JSON.stringify(err)}`);
     }
   }
   ```

5. Trigger photographing.

   Call **capture()** in the **PhotoOutput** class to capture a photo. In this API, the first parameter specifies the settings (for example, photo quality and rotation angle) for photographing, and the second parameter is a callback function.
 
   ```ts
   function capture(captureLocation: camera.Location, photoOutput: camera.PhotoOutput): void {
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH, // Set the photo quality to high.
       rotation: camera.ImageRotation.ROTATION_0, // Set the rotation angle of the photo to 0.
       location: captureLocation, // Set the geolocation information of the photo.
       mirror: false // Disable mirroring (disabled by default).
     };
     photoOutput.capture(settings, (err: BusinessError) => {
       if (err) {
         console.error(`Failed to capture the photo. error: ${JSON.stringify(err)}`);
         return;
       }
       console.info('Callback invoked to indicate the photo capture request success.');
     });
   }
   ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'captureStart'** event to listen for photographing start events. This event can be registered when a **PhotoOutput** object is created and is triggered when the bottom layer starts exposure for photographing for the first time. The capture ID is returned.
    
  ```ts
  function onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStart', (err: BusinessError, captureId: number) => {
      console.info(`photo capture stated, captureId : ${captureId}`);
    });
  }
  ```

- Register the **'captureEnd'** event to listen for photographing end events. This event can be registered when a **PhotoOutput** object is created and is triggered when the photographing is complete. [CaptureEndInfo](../reference/apis/js-apis-camera.md#captureendinfo) is returned.
    
  ```ts
  function onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- Register the **'error'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  function onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.info(`Photo output error code: ${error.code}`);
    });
  }
  ```
