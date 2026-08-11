# Multi-Camera Concurrent Mode (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=0621a1292f318505a386f6e1294f16ca68e36951 translatedAt=2026-08-10T09:12:48.800Z pushedAt=2026-08-10T10:40:52.659Z -->

Starting from API version 18, multi-camera concurrent opening is supported, allowing an app to simultaneously open the front and rear cameras for preview and video recording. (Concurrent photo capture with both front and rear cameras is not yet available.)

>**NOTE**
>
> Operating both cameras at the same time imposes significant restrictions on available features. The current implementation supports seven core functions, as listed below. When using multi-camera concurrent mode, avoid accessing or enabling any capabilities beyond them.
>   1. Flash
>   2. Exposure
>   3. Zoom
>   4. Exposure compensation
>   5. Focus
>   6. Stabilization
>   7. Color space

## How to Develop

Read [Camera](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

1. Import dependencies related to the camera, media library, and image modules.

   ```ts
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { camera } from '@kit.CameraKit';
   import { media } from '@kit.MediaKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the corresponding front and rear cameras through [getCameraDevice](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getcameradevice18). If the API returns `undefined`, it indicates, based on the configuration in the example, that the current device does not support a default-type camera at the specified position (front or rear), and the multi-camera concurrent opening feature cannot be implemented.

   ```ts
   function getSupportedCamerasFn(cameraManager: camera.CameraManager)
   {
     let cameras = cameraManager.getSupportedCameras();

     // Exit if fewer than two cameras are available (multi-camera not supported).
     if (cameras.length < 2) {
      return;
     }

     // Obtain the logical rear and front cameras.
     let curCameraDeviceBack = cameraManager.getCameraDevice(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_DEFAULT);
     let curCameraDeviceFront = cameraManager.getCameraDevice(camera.CameraPosition.CAMERA_POSITION_FRONT, camera.CameraType.CAMERA_TYPE_DEFAULT);
   }
   ```

3. Obtain the corresponding concurrent capability set. Use [getCameraConcurrentInfos](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getcameraconcurrentinfos18) to obtain an array of [CameraConcurrentInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraconcurrentinfo18) objects, which contain the modes and output capabilities supported by the camera in the corresponding concurrent mode. **In a multi-camera concurrent opening scenario, the configured modes and output capabilities must fall within the concurrent capability set.** If [getCameraConcurrentInfos](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getcameraconcurrentinfos18) returns an empty array, the current device does not support the concurrent feature.

   ```ts
   function getSupportedOutputCapabilityFn(cameraManager: camera.CameraManager, curCameraDeviceFront: camera.CameraDevice, curCameraDeviceBack: camera.CameraDevice)
   {
     // Check whether the current camera supports photo mode and obtain the original capability set.
     let sceneModes = cameraManager.getSupportedSceneModes(curCameraDeviceFront);
     if (sceneModes === undefined) {
       return;
     }
     let isSupported: boolean = sceneModes.includes(camera.SceneMode.NORMAL_PHOTO); 
     if (!isSupported) {
       return;
     }
     let cameraOutputCapability = cameraManager.getSupportedOutputCapability(curCameraDeviceFront, camera.SceneMode.NORMAL_PHOTO);

     let deviceArray: Array<camera.CameraDevice> = [curCameraDeviceFront, curCameraDeviceBack];

     // Obtain the concurrent capability set.
     let concurrentInfo: Array<camera.CameraConcurrentInfo> = cameraManager.getCameraConcurrentInfos(deviceArray);

     if (concurrentInfo.length === 0) {
      return;
     }

     // Replace the original capability set with the concurrent capability set.
     for (let i = 0; i < concurrentInfo.length; i++) {
       if (concurrentInfo[i].device.cameraPosition == camera.CameraPosition.CAMERA_POSITION_FRONT) {
         cameraOutputCapability = concurrentInfo[i].outputCapabilities[0];
         break;
       }
     }
   }
   ```

4. Determine the preview output stream.

   ```ts
   function getPreviewOutputFn(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, surfaceId: string)
   {
     // Create a preview output stream using the preview profile with the format 1003 and size 1920*1080 as an example.
     let previewProfileObj: camera.Profile = {
       format: 1003,
       size: {
         width: 1920,
         height: 1080
       }
     };
     // Check whether the corresponding previewProfile exists. The previewProfile must be within the range of the concurrent capability information array obtained from getCameraConcurrentInfos.
     let previewProfiles = cameraOutputCapability.previewProfiles;
     if (previewProfiles.length < 1) {
       return;
     }
     let index = previewProfiles.findIndex((previewProfile: camera.Profile) => {
       return previewProfile.size.width === previewProfileObj.size.width &&
       previewProfile.size.height === previewProfileObj.size.height &&
       previewProfile.format === previewProfileObj.format;
     });
     if (index === -1) {
       return;
     }

     // Create a previewOutput object.
     let previewOutput = cameraManager.createPreviewOutput(previewProfileObj, surfaceId);
     if (previewOutput === undefined) {
       return;
     }
   }
   ```

5. Determine the photo output stream.

   ```ts
   function getPhotoOutputFn(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability)
   {
    // Create a photo output stream using the photo profile with the format 2000 and size 1920*1080 as an example.
     let photoProfileObj: camera.Profile = {
       format: 2000,
       size: {
         width: 1920,
         height: 1080
       }
     };
     // Query whether the corresponding photoProfile exists. The corresponding photoProfile must be within the range of the concurrent capability information array obtained from getCameraConcurrentInfos.
     let photoProfiles = cameraOutputCapability.photoProfiles;
     if (photoProfiles.length < 1) {
      return;
     }
     let index = photoProfiles.findIndex((photoProfile: camera.Profile) => {
       return photoProfile.size.width === photoProfileObj.size.width &&
       photoProfile.size.height === photoProfileObj.size.height &&
       photoProfile.format === photoProfileObj.format;
     });
     if (index === -1) {
       return;
     }
     let photoOutput = cameraManager.createPhotoOutput(photoProfileObj);
     if (photoOutput === undefined) {
       return;
     }
   }
   ```

6. Determine the video output stream.

   ```ts
   async function createAVRecorder(): Promise<media.AVRecorder | undefined> {
     let avRecorder: media.AVRecorder | undefined = undefined;
     try {
       avRecorder = await media.createAVRecorder();
     } catch (error) {
     console.error('createAVRecorder error')
     }
     return avRecorder;
   }

   function initFd(context: common.Context): number {
     let filesDir = context.filesDir;
     let filePath = filesDir + `/${Date.now()}.mp4`;
     AppStorage.setOrCreate<string>('filePath', filePath);
     let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
     return file.fd;
   }

   async function prepareAVRecorder(videoProfileObj: camera.VideoProfile, curCameraDevice: camera.CameraDevice, avRecorder: media.AVRecorder, context: common.Context): Promise<void> {
     let fd = initFd(context);
     let videoConfig: media.AVRecorderConfig = {
       audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: {
         audioBitrate: 48000,
         audioChannels: 2,
         audioCodec: media.CodecMimeType.AUDIO_AAC,
         audioSampleRate: 48000,
         fileFormat: media.ContainerFormatType.CFT_MPEG_4,
         videoBitrate: 512000,
         videoCodec: media.CodecMimeType.VIDEO_AVC,
         videoFrameWidth: videoProfileObj.size.width,
         videoFrameHeight: videoProfileObj.size.height,
         videoFrameRate: videoProfileObj.frameRateRange.min
       },
       url: `fd://${fd.toString()}`,
       rotation: curCameraDevice?.cameraOrientation
     };
     await avRecorder?.prepare(videoConfig).catch((err: BusinessError): void => {
       console.error(`prepareAVRecorder prepare err`);
     });
   }

   async function getVideoOutputFn(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, concurrentInfo: Array<camera.CameraConcurrentInfo>, curCameraDeviceFront: camera.CameraDevice, context: common.Context)
   {
    // Create a video output stream. This example uses a videoProfile with format 1003 and size 1920*1080. The corresponding videoProfile must fall within the concurrent capability info array obtained from getCameraConcurrentInfos.
     let videoProfileObj: camera.VideoProfile = {
       format: 1003,
       size: {
         width: 1920,
         height: 1080
       },
       frameRateRange: {
         min: 30,
         max: 60
       }
     };

     // Replace the capability set.
     for (let i = 0; i < concurrentInfo.length; i++) {
       if (concurrentInfo[i].device.cameraPosition == camera.CameraPosition.CAMERA_POSITION_FRONT) {
         cameraOutputCapability = concurrentInfo[i].outputCapabilities[1];
         break;
       }
     }
     let videoProfiles = cameraOutputCapability.videoProfiles;
     if (videoProfiles.length < 1) {
       return;
     }
     let index = videoProfiles.findIndex((videoProfile: camera.VideoProfile) => {
       return videoProfile.size.width === videoProfileObj.size.width &&
         videoProfile.size.height === videoProfileObj.size.height &&
         videoProfile.format === videoProfileObj.format &&
         videoProfile.frameRateRange.min <= 60 &&
         videoProfile.frameRateRange.max <= 60;
     });
     if (index === -1) {
       return;
     }
     videoProfileObj = videoProfiles[index];
     let avRecorder = await createAVRecorder();
     if (avRecorder === undefined) {
       return;
     }
     await prepareAVRecorder(videoProfileObj, curCameraDeviceFront, avRecorder, context);
     let videoSurfaceId = await avRecorder.getInputSurface();
     let videoOutput = cameraManager.createVideoOutput(videoProfileObj, videoSurfaceId);
     if (videoOutput === undefined) {
       return;
     }
   }
   ```

7. Open the camera. Call [open](../../reference/apis-camera-kit/arkts-apis-camera-CameraInput.md#open18) to open the specified camera in multi-camera concurrent mode. Before using this API, check whether the camera supports concurrent capabilities and call [getCameraConcurrentInfos](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getcameraconcurrentinfos18) to obtain the concurrent capability set in the multi-camera concurrent mode. Do not use [open](../../reference/apis-camera-kit/arkts-apis-camera-CameraInput.md#open18) without querying the concurrency capability set, as this will result in camera opening failure.

   ```ts
   async function initCamera(cameraManager: camera.CameraManager, cameraDevice: camera.CameraDevice) {
     let cameraInput: camera.CameraInput | undefined = undefined;
     try {
       cameraInput = cameraManager.createCameraInput(cameraDevice);
       console.info('createCameraInputFn success');
     } catch (error) {
       console.error(`createCameraInputFn failed`);
     }
     if (cameraInput === undefined) {
       return;
     }
     let isOpenSuccess = false;
     try {

       // The current version supports opening the camera in camera.CameraConcurrentType.CAMERA_LIMITED_CAPABILITY mode.
       await cameraInput.open(camera.CameraConcurrentType.CAMERA_LIMITED_CAPABILITY);
       isOpenSuccess = true;
     } catch (error) {
       console.error(`createCameraInput failed`);
     }
     if (!isOpenSuccess) {
       return;
     }
   }
   ```

8. Implement the session flow.

   ```ts
    // Listen for capture session error changes.
   function onSessionErrorChange(session: camera.PhotoSession | camera.VideoSession): void {
     try {
       session.on('error', (captureSessionError: BusinessError): void => {
       });
     } catch (error) {
       console.error('onCaptureSessionErrorChange error');
     }
   }

   let handlePhotoAssetCb: (photoAsset: photoAccessHelper.PhotoAsset) => void = () => {
   };

   // Listen for photo capture events.
   function photoOutputCallBack(photoOutput: camera.PhotoOutput): void {
     try {

       // Listen for capture start events.
       photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo): void => {
     });

     // Listen for frame shutter events.
     photoOutput.on('frameShutter', (err: BusinessError, frameShutterInfo: camera.FrameShutterInfo): void => {
     });

    // Listen for capture end events.
     photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo): void => {
     });

     // Listen for photo capture errors.
     photoOutput.on('error', (data: BusinessError): void => {
     });
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset) => {
       if (photoAsset === undefined) {
         return;
       }
       handlePhotoAssetCb(photoAsset);
     });
     } catch (err) {
     }
   }

   // Session flow.
   async function sessionFlowFn(cameraManager: camera.CameraManager, cameraInput: camera.CameraInput,
     previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput | undefined, videoOutput: camera.VideoOutput | undefined, curSceneMode: camera.SceneMode): Promise<void> {
     let session: camera.PhotoSession | camera.VideoSession | undefined = undefined;
     try {

       // Create a CaptureSession instance.
       if (curSceneMode === camera.SceneMode.NORMAL_PHOTO) {
         session = cameraManager.createSession(curSceneMode) as camera.PhotoSession;
       } else if (curSceneMode === camera.SceneMode.NORMAL_VIDEO) {
         session = cameraManager.createSession(curSceneMode) as camera.VideoSession;
       }
       if (session === undefined) {
         return;
       }
       onSessionErrorChange(session);

       // Start configuration for the session.
       session.beginConfig();

       // Add the camera input stream to the session.
       session.addInput(cameraInput);

       // Add the preview output stream to the session.
       session.addOutput(previewOutput);

       if (curSceneMode === camera.SceneMode.NORMAL_PHOTO) {
         if (photoOutput === undefined) {
           return;
         }

         // Photo capture event listeners.
         photoOutputCallBack(photoOutput);

         // Add the photo output stream to the session.
         session.addOutput(photoOutput);
       } else if (curSceneMode === camera.SceneMode.NORMAL_VIDEO) {
         if (videoOutput === undefined) {
           return;
         }

         // Add the video output stream to the session.
         session.addOutput(videoOutput);
       }

       // Commit the configuration.
       await session.commitConfig();
     } catch (error) {
       console.error(`sessionFlowFn fail`);
     }
   }
   ```

9. Capture photos. Use the `photoOutput` configured in step 8 to take photos with either the front or rear camera. Concurrent photo capture with both front and rear cameras is not supported in the multi-camera concurrent opening state.

    ```ts
    async function takePicture(photoOutput: camera.PhotoOutput): Promise<void> {
      if (photoOutput === undefined) {
        return;
      }
      if (photoOutput === null) {
        return;
      }

      if (photoOutput) {
        await photoOutput.capture();
      } else {
        console.info('photoOutput is undefined or null');
      }
    }
    ```

10. Record a video.

    ```ts
    let isRecording = false;

    // Start recording.
    async function startVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
      try {
        await videoOutput?.start();
        await avRecorder?.start();
        isRecording = true;
      } catch (error) {
        console.error(`startVideo err`);
      }
    }

    // Stop recording.
    async function stopVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
      if (!isRecording) {
        return;
      }
      try {
        if (avRecorder) {
          await avRecorder.stop();
        }
        if (videoOutput) {
          await videoOutput.stop();
        }
        isRecording = false;
      } catch (error) {
        console.error(`stopVideo err`);
      }
    }
    ```

11. The following provides examples of configurable capabilities for front and rear cameras in multi-camera concurrent mode. (Currently, only the seven core functions listed at the beginning of this document are supported.)

    ```ts
    // Flash.
    function hasFlashFn(flashMode: camera.FlashMode, session: camera.PhotoSession | camera.VideoSession | undefined = undefined): void {

      // Check whether the camera device has flash.
      let hasFlash = session?.hasFlash();

      // Check whether a flash mode is supported.
      let isFlashModeSupported = session?.isFlashModeSupported(flashMode);

      // Set the flash mode.
      if (isFlashModeSupported) {
        session?.setFlashMode(flashMode);
      }
    }

    // Exposure.
    function hasExposureFn(ExposureMode: camera.ExposureMode, session: camera.PhotoSession | camera.VideoSession | undefined = undefined): void {

      // Check whether an exposure mode is supported.
      let hasFlash = session?.isExposureModeSupported(ExposureMode);

      // Set the exposure mode.
      if (hasFlash) {
        session?.setExposureMode(ExposureMode);
      }
    }

    // Obtain the zoom ratio range.
    function getZoomRatioRange(session: camera.PhotoSession | camera.VideoSession | undefined = undefined): Array<number> {
      let zoomRatioRange: Array<number> = [];
      if (session !== undefined) {
        zoomRatioRange = session.getZoomRatioRange();
      }
      return zoomRatioRange;
    }

    // Zoom.
    function setZoomRatioFn(zoomRatio: number, session: camera.PhotoSession | camera.VideoSession | undefined = undefined): void {

      // Obtain the supported zoom ratio range.
      let zoomRatioRange = getZoomRatioRange();
      try {
        session?.setZoomRatio(zoomRatio);
      } catch (error) {
        console.error(`setZoomRatioFn fail`);
      }
    }

    // Exposure compensation.
    function setExposureBiasFn(exposureBias: number, session: camera.PhotoSession | camera.VideoSession | undefined = undefined): void {

      // Obtain the exposure compensation values of the camera device.
      let biasRangeArray: Array<number> | undefined = [];
      biasRangeArray = session?.getExposureBiasRange();

      // Set an exposure compensation value for the device.
      session?.setExposureBias(exposureBias);
    }

    // Focus mode.
    function setFocusMode(focusMode: camera.FocusMode, session: camera.PhotoSession | camera.VideoSession | undefined = undefined): void {

      // Check whether a focus mode is supported.
      let isSupported = session?.isFocusModeSupported(focusMode);

      // Set the focus mode.
      if (!isSupported) {
        return;
      }
      session?.setFocusMode(focusMode);
    }
    ```