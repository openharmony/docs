# Photo Capture (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-10T09:20:13.418Z pushedAt=2026-08-10T12:53:45.423Z -->

## Overview

Photo capture is an important function of the camera. Based on the complex logic of the camera device, the photo capture module allows you to set information such as resolution, flash, focal length, photo quality, and rotation angle in intermediate steps to ensure the quality of captured photos. 

Currently, two photo capture solutions are available: [deferred capture](./camera-deferred-capture.md) and single-shot capture. **This document uses single-shot capture as the basis for description**. 

- Deferred capture allows the camera to output a low-quality image as a thumbnail to improve the perceived capture speed, while also using a high-quality image to ensure that the final image quality reaches the level of the system camera. This meets the requirements of image processing algorithms without blocking the foreground capture speed, thereby building competitive camera performance and improving user experience. 

- Single-shot capture returns a high-quality image after multi-frame fusion and multiple underlying algorithm processing during the capture process. As a result, the Shot2See latency (the process from when the user taps the capture control to when the thumbnail appears in the thumbnail display area) is relatively long. In addition, single-shot capture supports adjusting the [quality prioritization strategy](#quality-prioritization-strategy) through the [high-performance capture](#high-performance-capture) feature to speed up image output or improve image quality. 

## How to Develop

For detailed API descriptions, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

1. Import the [Image](../../reference/apis-image-kit/arkts-apis-image-Image.md) interface. To access the data output by the camera, you must use the image interface capabilities provided by the system. Here is how to import the Image interface.

   ```ts
   import { image } from '@kit.ImageKit';
   import { camera } from '@kit.CameraKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a photo output stream.

   Obtain the photo output streams supported by the current device from **photoProfiles** in [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability). Call [createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11), passing in a supported output stream [profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile), to create a photo output stream.

   <!-- @[camera_getPhotoOutput](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   getPhotoOutput(cameraManager: camera.CameraManager,
     cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: camera.Profile[] = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray || photoProfilesArray.length === 0) {
       console.error('photoProfilesArray is null or []');
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       this.photoProfileObj = photoProfilesArray[0]
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. Set the callback for the [on('photoAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11) event and save the photo buffer as an image.

   For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   To view the saved photos and videos in Gallery, you need to save them to the media library. For details, see [Saving Media Assets](../medialibrary/photoAccessHelper-savebutton.md).

   When the buffer is obtained through the [photoOutput.on('photoAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11) API, save the buffer to the media library in a security component.

   <!-- @[camera_photoAvailable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   setPhotoOutputCb(photoOutput: camera.PhotoOutput, context: Context) {
     // After the callback is set, calling the capture method of photoOutput returns the photo buffer to the callback.
     photoOutput.on('photoAvailable', (errCode: BusinessError, photo: camera.Photo): void => {
       console.info('getPhoto start');
       if (errCode || photo === undefined) {
         console.error('getPhoto failed, err: ${errCode}');
         return;
       }
         // To view saved images and videos in Gallery, use a security component to create media assets.
         this.mediaLibSavePhotoSingle(context, photo.main)
     });
   }

   mediaLibSavePhotoSingle(context: Context, imageObj: image.Image) {
     imageObj.getComponent(image.ComponentType.JPEG, async (errCode: BusinessError, component: image.Component) => {
       if (errCode || component === undefined) {
         Logger.error('getComponent failed');
         return;
       }
       const buffer: ArrayBuffer = component.byteBuffer;
       if (!buffer) {
         Logger.error('byteBuffer is null');
         return;
       }
       let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
       let extension: string = 'jpg';
       let options: photoAccessHelper.CreateOptions = {
         title: 'testPhoto'
       }
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
         photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension, options);
       assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, buffer)
       assetChangeRequest.saveCameraPhoto();
       let accessHelper: photoAccessHelper.PhotoAccessHelper =
         photoAccessHelper.getPhotoAccessHelper(context);
       await accessHelper.applyChanges(assetChangeRequest);
       let imageSource = image.createImageSource(buffer);
       let pixelmap = imageSource.createPixelMapSync();
       this.callback(pixelmap, assetChangeRequest.getAsset().uri);
       accessHelper.release();
       // Release the buffer after processing; failure to release it properly will prevent subsequent photo capture from obtaining the buffer.
       imageObj.release();
     });
   }
   ```

4. Set camera parameters.

   You can set camera parameters to adjust photo capture functions, including the flash, zoom ratio, and focal length.

   <!-- @[camera_param_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

   ``` TypeScript
   configuringSession(photoSession: camera.PhotoSession | camera.VideoSession): void {
     // Check whether the camera has flash.
     let flashStatus: boolean = false;
     try {
       flashStatus = photoSession.hasFlash();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to hasFlash. error: ${err}`);
     }
     console.info(`Returned with the flash light support status: ${flashStatus}`);
     if (flashStatus) {
       // Check whether turning off the flash mode is supported.
       let flashModeStatus: boolean = false;
       try {
         flashModeStatus = photoSession?.isFlashModeSupported(camera.FlashMode.FLASH_MODE_CLOSE);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to check whether the flash mode is supported. error: ${err}`);
       }
       if (flashModeStatus) {
         // Set the flash mode to off.
         try {
           photoSession?.setFlashMode(camera.FlashMode.FLASH_MODE_CLOSE);
         } catch (error) {
           let err = error as BusinessError;
           console.error(`Failed to set the flash mode. error: ${err}`);
         }
       }
     }
     // Check whether the continuous auto focus is supported.
     let focusModeStatus: boolean = false;
     try {
       focusModeStatus = photoSession?.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to check whether the focus mode is supported. error: ${err}`);
     }
     if (focusModeStatus) {
       // Set the focus mode to continuous auto focus.
       try {
         photoSession?.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to set the focus mode. error: ${err}`);
       }
     }
     // Obtain the zoom ratio range supported by the camera.
     let zoomRatioRange: number[] = [];
     try {
       zoomRatioRange = photoSession?.getZoomRatioRange();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to get the zoom ratio range. error: ${err}`);
     }
     if (zoomRatioRange.length <= 0 ) {
       return;
     }
     // Set a zoom ratio.
     try {
       photoSession?.setZoomRatio(zoomRatioRange[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to set the zoom ratio value. error: ${err}`);
     }
   }
   ```

5. Trigger photo capture.

   Call [capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2) in **PhotoOutput** to capture a photo. In this API, the first parameter specifies the settings (for example, photo quality and rotation angle) for photo capture, and the second parameter is a callback function.

   To obtain the photo rotation angle (specified by **rotation**), call [getPhotoRotation](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#getphotorotation12) in [PhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md).

   > **NOTE**
   >
   > For details about the photo's geographical location information (specified by [Location](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)), you can refer to the implementation in the [capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-3) example.

   <!-- @[camera_capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   capture(captureLocation?: camera.Location): void {
     let captureLocationDefault: camera.Location = {
       latitude: 0,
       longitude: 0,
       altitude: 0
     };
     if (captureLocation != undefined) {
       captureLocationDefault = captureLocation;
     }
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,  // Set the image quality to high.
       // Set the image rotation angle. The value of camera.ImageRotation.ROTATION_0 is obtained from the getPhotoRotation method described in the instructions.
       rotation: camera.ImageRotation.ROTATION_0,
       location: captureLocation,  // Set the image location.
       mirror: false  // Set the mirror switch (disabled by default).
     };
     try {
       if (this.photoOutput == undefined) {
         console.info(`photoOutput is undefined.`);
         return;
       }
       this.photoOutput.capture(settings, (err: BusinessError) => {
         if (err) {
           console.error(`Failed to capture the photo. error: ${err}`);
           return;
         }
         console.info('Callback invoked to indicate the photo capture request success.');
       });
     } catch (error) {
       console.error(`capture call failed. error: ${error}`);
     }
   }
   ```

## High-Performance Capture

Starting from API version 21, the high-performance capture feature is supported, which allows you to set an explicit [quality prioritization strategy](#quality-prioritization-strategy) during single-shot capture.

The experience of single-shot capture is primarily measured by image output speed and final image quality. Therefore, to meet the differentiated requirements of developers in different scenarios, the emphasis on these two metrics varies. For example, street snapshots require quickly capturing the moment, while landscape or portrait photography pursues ultimate image quality.

> **NOTE**
>
> Only single-shot capture supports setting the quality prioritization strategy. If the quality prioritization strategy is set in deferred capture, the setting will not take effect. 

### Quality Prioritization Strategy

When using single-shot capture, two quality prioritization strategy types are supported: speed priority and quality priority, which correspond to different [PhotoQualityPrioritization](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21) enumeration values. 

- [SPEED](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21) corresponds to speed priority, which reduces image quality to improve capture speed. If no explicit quality prioritization strategy is set during single-shot capture, **single-shot capture defaults to the speed priority state**. 

- [HIGH_QUALITY](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21) corresponds to quality priority, which takes a longer time to obtain a higher-quality image. 

### How to Correctly Set the Quality Prioritization Strategy

To correctly set the quality prioritization strategy in single-shot capture, the high-performance capture feature provides the following two APIs:

- [isPhotoQualityPrioritizationSupported](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#isphotoqualityprioritizationsupported21): Queries whether the current device supports the specified quality prioritization strategy. The value **true** indicates that the strategy is supported, and **false** indicates that it is not. Before setting a quality prioritization strategy, you must first query whether the strategy to be set is available on the current device. 

- [setPhotoQualityPrioritization](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#setphotoqualityprioritization21): Sets the quality prioritization strategy. This API is used to set the corresponding quality prioritization strategy to implement high-performance capture.

### How to Develop

The high-performance capture APIs need to be called during the enabling step of the [Camera Session Management (ArkTS)](camera-session-management.md) process.  

The specific calling timing is as follows:  

- Call after [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) completes in the enabling step of the [Camera Session Management (ArkTS)](camera-session-management.md) process. 

  ```ts
  async function startSession(photoSession: camera.PhotoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      photoSession.addInput(cameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to addInput. error: ${err.code}`);
    }
    let canAddPreviewOutput : boolean = false;
    try {
      canAddPreviewOutput = photoSession.canAddOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    } 
    if (!canAddPreviewOutput) {
      console.error(`Failed to add preview output.`);
      return;
    }
    try {
      photoSession.addOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    }
    let canAddPhotoOutput : boolean = false
    try {
      canAddPhotoOutput = photoSession.canAddOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput error: ${err.code}`);
    }
    if (!canAddPhotoOutput) {
      console.error(`Failed to add photo output.`);
      return;
    }
    try {
      photoSession.addOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput. error: ${err.code}`);
    }
    try {
      await photoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to commitConfig. error: ${err.code}`);
      return;
    }
   
    try {
      await photoSession.start();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start. error: ${err.code}`);
    }
    modeSwitchToHigh(photoSession, photoOutput);
  }

  async function modeSwitchToHigh(photoSession: camera.PhotoSession, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      if (photoSession) {
        let quality: camera.PhotoQualityPrioritization = camera.PhotoQualityPrioritization.HIGH_QUALITY;
        let isSupported = false;
        isSupported = photoOutput.isPhotoQualityPrioritizationSupported(quality);
        if (isSupported) {
          photoOutput.setPhotoQualityPrioritization(quality);
        } else {
          console.error(`session is not supported`);
        }
      } else {
        console.error(`session is null`);
      }
    } catch {
      console.error(`catch error`);
    }
  }
  ```

- Call before [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) in the enabling step of the [Camera Session Management (ArkTS)](camera-session-management.md) process. 

  ```ts
  async function startSession(photoSession: camera.PhotoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      photoSession.addInput(cameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to addInput. error: ${err.code}`);
    }
    let canAddPreviewOutput : boolean = false;
    try {
      canAddPreviewOutput = photoSession.canAddOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    } 
    if (!canAddPreviewOutput) {
      console.error(`Failed to add preview output.`);
      return;
    }
    try {
      photoSession.addOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    }
    let canAddPhotoOutput : boolean = false
    try {
      canAddPhotoOutput = photoSession.canAddOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput error: ${err.code}`);
    }
    if (!canAddPhotoOutput) {
      console.error(`Failed to add photo output.`);
      return;
    }
    try {
      photoSession.addOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput. error: ${err.code}`);
    }
    modeSwitchToHigh(photoSession, photoOutput);
    try {
      await photoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to commitConfig. error: ${err.code}`);
      return;
    }
   
    try {
      await photoSession.start();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start. error: ${err.code}`);
    }
  }

  async function modeSwitchToHigh(photoSession: camera.PhotoSession, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      if (photoSession) {
        let quality: camera.PhotoQualityPrioritization = camera.PhotoQualityPrioritization.HIGH_QUALITY;
        let isSupported = false;
        isSupported = photoOutput.isPhotoQualityPrioritizationSupported(quality);
        if (isSupported) {
          photoOutput.setPhotoQualityPrioritization(quality);
        } else {
          console.error(`session is not supported`);
        }
      } else {
        console.error(`session is null`);
      }
    } catch {
      console.error(`catch error`);
    }
  }
  ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'captureStart'** event to listen for photo capture start events. This event can be registered when a PhotoOutput instance is created and is triggered when the camera device starts photo capture. The capture ID is returned.

  <!-- @[capture_start_with_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

  ``` TypeScript
  // Listen for the start of photo capture.
  photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo): void => {
    Logger.info(TAG, `photoOutputCallBack captureStartWithInfo success: ${JSON.stringify(captureStartInfo)}`);
  });
  ```

- Register the **'captureEnd'** event to listen for photo capture end events. This event can be registered when a PhotoOutput instance is created and is triggered when the photo capture is complete. [CaptureEndInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#captureendinfo) is returned.

  <!-- @[capture_end](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

  ``` TypeScript
  // Listen for photo capture completion.
  photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo): void => {
    Logger.info(TAG, `photoOutputCallBack captureEnd captureId:
      ${captureEndInfo.captureId}, frameCount: ${captureEndInfo.frameCount}`);
  });
  ```

- Register the **'captureReady'** event to obtain the result of the next photo capture. This event can be registered when a PhotoOutput instance is created and is triggered when the camera device is ready for taking a photo. The information about the next photo capture is returned.

  <!-- @[capture_ready](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

  ``` TypeScript
  photoOutput.on('captureReady', (err: BusinessError) => {
    if (err !== undefined && err.code !== 0) {
      return;
    }
    console.info(`photo capture ready`);
  });
  ```

- Register a fixed error callback to listen for error results of the photo output stream. The callback returns the corresponding error code when the photo output API is used incorrectly. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

  <!-- @[photoOutput_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

  ``` TypeScript
  // Listen for photo capture exceptions.
  photoOutput.on('error', (data: BusinessError): void => {
    Logger.info(TAG, `photoOutput data: ${JSON.stringify(data)}`);
  });
  ```