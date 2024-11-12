# Photo Capture (ArkTS)

Photo capture is an important function of the camera application. Based on the complex logic of the camera hardware, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the image module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.

   ```ts
   import { image } from '@kit.ImageKit';
   import { camera } from '@kit.CameraKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a photo output stream.

   Obtain the photo output streams supported by the current device from **photoProfiles** in the [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability) class, and then call [createPhotoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createphotooutput11) to pass in a supported output stream and the surface ID obtained in step 1 to create a photo output stream.

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
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

3. Set the callback for the **'photoAvailable'** event and save the photo buffer as an image.

    For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

    To view the saved images and videos in Gallery, you must save them to the media library. For details, see [Creating a Media Asset Using SaveButton](../medialibrary/photoAccessHelper-savebutton.md).

    Specifically, when [photoOutput.on('photoAvailable')](../../reference/apis-camera-kit/js-apis-camera.md#onphotoavailable11) is called and a buffer is obtained, the buffer must be stored in the security component to the media library.
   ```ts
   let context = getContext(this);

   function setPhotoOutputCb(photoOutput: camera.PhotoOutput) {
   // After the callback is set, call capture() of photoOutput to transfer the photo buffer back to the callback.
     photoOutput.on('photoAvailable', (errCode: BusinessError, photo: camera.Photo): void => {
        console.info('getPhoto start');
        console.info(`err: ${JSON.stringify(errCode)}`);
        if (errCode || photo === undefined) {
          console.error('getPhoto failed');
          return;
        }
        let imageObj: image.Image = photo.main;
        imageObj.getComponent(image.ComponentType.JPEG, (errCode: BusinessError, component: image.Component): void => {
          console.info('getComponent start');
          if (errCode || component === undefined) {
            console.error('getComponent failed');
            return;
          }
          let buffer: ArrayBuffer;
          if (component.byteBuffer) {
            buffer = component.byteBuffer;
          } else {
            console.error('byteBuffer is null');
            return;
          }
          // To view the saved image and video resources in Gallery, use a security component to create media assets.

          // After the buffer processing is complete, the buffer must be released. Otherwise, no buffer is available for subsequent photo capture.
          imageObj.release(); 
        });
      });
   }
   ```

4. Set camera parameters.

   You can set camera parameters to adjust photo capture functions, including the flash, zoom ratio, and focal length.

   ```ts
   function configuringSession(photoSession: camera.PhotoSession): void {
     // Check whether the camera has flash.
     let flashStatus: boolean = false;
     try {
       flashStatus = photoSession.hasFlash();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to hasFlash. error: ${JSON.stringify(err)}`);
     }
     console.info(`Returned with the flash light support status: ${flashStatus}`);
     if (flashStatus) {
       // Check whether the auto flash mode is supported.
       let flashModeStatus: boolean = false;
       try {
         let status: boolean = photoSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
         flashModeStatus = status;
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to check whether the flash mode is supported. error: ${JSON.stringify(err)}`);
       }
       if (flashModeStatus) {
         // Set the flash mode to auto.
         try {
           photoSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
         } catch (error) {
           let err = error as BusinessError;
           console.error(`Failed to set the flash mode. error: ${JSON.stringify(err)}`);
         }
       }
     }
     // Check whether the continuous auto focus is supported.
     let focusModeStatus: boolean = false;
     try {
       let status: boolean = photoSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       focusModeStatus = status;
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to check whether the focus mode is supported. error: ${JSON.stringify(err)}`);
     }
     if (focusModeStatus) {
       // Set the focus mode to continuous auto focus.
       try {
         photoSession.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to set the focus mode. error: ${JSON.stringify(err)}`);
       }
     }
     // Obtain the zoom ratio range supported by the camera.
     let zoomRatioRange: Array<number> = [];
     try {
       zoomRatioRange = photoSession.getZoomRatioRange();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to get the zoom ratio range. error: ${JSON.stringify(err)}`);
     }
     if (zoomRatioRange.length <= 0 ) {
       return;
     }
     // Set a zoom ratio.
     try {
       photoSession.setZoomRatio(zoomRatioRange[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to set the zoom ratio value. error: ${JSON.stringify(err)}`);
     }
   }
   ```

5. Trigger photo capture.

   Call [capture](../../reference/apis-camera-kit/js-apis-camera.md#capture-2) in the **PhotoOutput** class to capture a photo. In this API, the first parameter specifies the settings (for example, photo quality and rotation angle) for photo capture, and the second parameter is a callback function.

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

- Register the **'captureStart'** event to listen for photo capture start events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the camera device starts photo capture. The capture ID is returned.

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

- Register the **'captureEnd'** event to listen for photo capture end events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the photo capture is complete. [CaptureEndInfo](../../reference/apis-camera-kit/js-apis-camera.md#captureendinfo) is returned.

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

- Register the **'captureReady'** event to obtain the result of the next photo capture. This event can be registered when a **PhotoOutput** instance is created and is triggered when the camera device is ready for taking a photo. The information about the next photo capture is returned.

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
