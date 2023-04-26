# Camera Photographing

Photographing is an important function of the camera application. Based on the complex logic of the camera hardware, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the image module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.
     
   ```ts
   import image from '@ohos.multimedia.image';
   ```

2. Obtain the surface ID.
   
   Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and use **getReceivingSurfaceId()** of the instance to obtain the surface ID, which is associated with the photo output stream to process the data output by the stream.
 
   ```ts
   function getImageReceiverSurfaceId() {
       let receiver = image.createImageReceiver(640, 480, 4, 8);
       console.info('before ImageReceiver check');
       if (receiver !== undefined) {
         console.info('ImageReceiver is ok');
         let photoSurfaceId = receiver.getReceivingSurfaceId();
         console.info('ImageReceived id: ' + JSON.stringify(photoSurfaceId));
       } else {
         console.info('ImageReceiver is not ok');
       }
   }
   ```

3. Create a photo output stream.
   
   Obtain the photo output streams supported by the current device from **photoProfiles** in **CameraOutputCapability**, and then call **createPhotoOutput()** to pass in a supported output stream and the surface ID obtained in step 1 to create a photo output stream.

   ```ts
   let photoProfilesArray = cameraOutputCapability.photoProfiles;
   if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
   }
   let photoOutput;
   try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0], photoSurfaceId);
   } catch (error) {
      console.error('Failed to createPhotoOutput errorCode = ' + error.code);
   }
   ```

4. Set camera parameters.
   
   You can set camera parameters to adjust photographing functions, including the flash, zoom ratio, and focal length.
 
   ```ts
   // Check whether the camera has flash.
   let flashStatus;
   try {
       flashStatus = captureSession.hasFlash();
   } catch (error) {
       console.error('Failed to hasFlash. errorCode = ' + error.code);
   }
   console.info('Promise returned with the flash light support status:' + flashStatus); 
   if (flashStatus) {
       // Check whether the auto flash mode is supported.
       let flashModeStatus;
       try {
           let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
           flashModeStatus = status;    
       } catch (error) {
           console.error('Failed to check whether the flash mode is supported. errorCode = ' + error.code);
       }    
       if(flashModeStatus) {
           // Set the flash mode to auto.
           try {
               captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
           } catch (error) {
               console.error('Failed to set the flash mode. errorCode = ' + error.code);
           }
       }
   } 
   // Check whether the continuous auto focus is supported.
   let focusModeStatus;
   try {
       let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       focusModeStatus = status;
   } catch (error) {
       console.error('Failed to check whether the focus mode is supported. errorCode = ' + error.code);
   } 
   if (focusModeStatus) {
       // Set the focus mode to continuous auto focus.
       try {
           captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) { 
          console.error('Failed to set the focus mode. errorCode = ' + error.code);
       }
   } 
   // Obtain the zoom ratio range supported by the camera.
   let zoomRatioRange;
   try {
       zoomRatioRange = captureSession.getZoomRatioRange();
   } catch (error) {
       console.error('Failed to get the zoom ratio range. errorCode = ' + error.code);
   } 
   // Set a zoom ratio.
   try {
       captureSession.setZoomRatio(zoomRatioRange[0]);
   } catch (error) {
       console.error('Failed to set the zoom ratio value. errorCode = ' + error.code);
   }
   ```

5. Trigger photographing.
   
   Call **capture()** in the **PhotoOutput** class to capture a photo. In this API, the first parameter specifies the settings (for example, photo quality and rotation angle) for photographing, and the second parameter is a callback function.
 
   ```ts
   let settings = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,                                     // Set the photo quality to high.
       rotation: camera.ImageRotation.ROTATION_0,                                           // Set the rotation angle of the photo to 0.
       location: captureLocation,                                                           // Set the geolocation information of the photo.
       mirror: false                                                                        // Disable mirroring (disabled by default).
   };
   photoOutput.capture(settings, async (err) => {
       if (err) {
           console.error('Failed to capture the photo ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the photo capture request success.');
   });
   ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the 'captureStart' event to listen for photographing start events. This event can be registered when a **PhotoOutput** object is created and is triggered when the bottom layer starts exposure for photographing for the first time. The capture ID is returned.
    
  ```ts
  photoOutput.on('captureStart', (captureId) => {
      console.info(`photo capture stated, captureId : ${captureId}`);
  })
  ```

- Register the 'captureEnd' event to listen for photographing end events. This event can be registered when a **PhotoOutput** object is created and is triggered when the photographing is complete. [CaptureEndInfo](../reference/apis/js-apis-camera.md#captureendinfo) is returned.
    
  ```ts
  photoOutput.on('captureEnd', (captureEndInfo) => {
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
  })
  ```

- Register the 'error' event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  photoOutput.on('error', (error) => {
      console.info(`Photo output error code: ${error.code}`);
  })
  ```
