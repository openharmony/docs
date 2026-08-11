# Video Recording (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=472b8a70c8f480fabd11928a604dcdb48eb0acbf translatedAt=2026-08-10T09:15:40.920Z pushedAt=2026-08-10T12:05:24.178Z -->

Before developing a camera application, you must [request required permissions](camera-preparation.md).

A camera application invokes and controls a camera device to perform basic operations such as preview, photo capture, and video recording.

Video recording is also one of the most important features of a camera app. Recording is the capture of cyclic frames. For custom recording configurations, refer to step 4 in [Photo Capture](camera-shooting.md) to set parameters such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

For detailed API descriptions, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

1. Import the media module.

   Creating the SurfaceId for the recording output stream and the recording output data requires the media APIs provided by the system, that is, [@ohos.multimedia.media (Media Service)](../../reference/apis-media-kit/arkts-apis-media.md). The following shows how to import the media APIs.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { camera } from '@kit.CameraKit';
   import { media } from '@kit.MediaKit';
   ```

2. Create a surface.

   Call createAVRecorder() of the media module to create an [AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md) instance, and call [getInputSurface](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#getinputsurface9) of the instance to obtain the surface ID, which is associated with the video output stream to process the stream data.

   <!-- @[camera_video_getVideoSurface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   this.avRecorder = await this.createAVRecorder();
   if (this.avRecorder === undefined) {
     Logger.error(TAG, 'Failed to create the avRecorder.');
     return;
   }
   await this.prepareAVRecorder();
   let videoSurfaceId = await this.avRecorder.getInputSurface();
   ```

3. Create a video output stream.

   Obtain the video output streams supported by the current device from **videoProfiles** in [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability). Then, define video recording parameters and use [createVideoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createvideooutput) to create a video output stream.

   > **NOTE**
   >
   > 1. The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio in the code snippet below is 640:480 (which is equal to 4:3), then the aspect ratio of the resolution of the preview stream must also be 4:3. This means that the resolution can be 640:480, 960:720, 1440:1080, or the like.
   >
   > 2. Before setting the resolution width and height of the preview output stream, call [AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9) to obtain the configurable width and height range for video frames.
   >
   > 3. To obtain the video rotation angle (specified by **rotation**), call [getVideoRotation](../../reference/apis-camera-kit/arkts-apis-camera-VideoOutput.md#getvideorotation12) in [VideoOutput](../../reference/apis-camera-kit/arkts-apis-camera-VideoOutput.md).
   >
   > 4. To configure the frame rate for a video output stream, select a suitable **videoProfile** from **videoProfiles** of [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability). Ensure that [frameRateRange](../../reference/apis-camera-kit/arkts-apis-camera-i.md#frameraterange) of the selected [VideoProfile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#videoprofile) meets your service requirements.

   <!-- @[camera_video_createAVRecorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

   ``` TypeScript
   createVideoOutputFn(cameraManager: camera.CameraManager, videoProfileObj: camera.VideoProfile,
     surfaceId: string): camera.VideoOutput | undefined {
     let videoOutput: camera.VideoOutput | undefined = undefined;
     try {
       videoOutput = cameraManager.createVideoOutput(videoProfileObj, surfaceId);
       Logger.info(TAG, `createVideoOutputFn success: ${videoOutput}`);
     } catch (error) {
       let err = error as BusinessError;
       Logger.error(TAG, `createVideoOutputFn failed: ${err.code}`);
     }
     return videoOutput;
   }
   ```

4. Start video recording.

   > **NOTE**
   >
   >  - Before setting the preview stream frame rate, call [getActiveFrameRate](../../reference/apis-camera-kit/arkts-apis-camera-PreviewOutput.md#getactiveframerate12) to query the frame rate of the current recording stream.
   >
   > - If a frame rate range has been set for the recording stream, the preview stream frame rate must be set to the same range.
   >
   > - If a fixed frame rate has been set for the recording stream, the preview stream frame rate must be set to a divisor of the recording frame rate and must also be a fixed frame rate.
   >
   > - On some devices, if the front camera recording resolution is set to 3280*2160, the video may appear upside down in recording mode. It is recommended that you call [setVideoStabilizationMode](../../reference/apis-camera-kit/arkts-apis-camera-Stabilization.md#setvideostabilizationmode11) after [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) to avoid this issue.

   Call [start](../../reference/apis-camera-kit/arkts-apis-camera-VideoOutput.md#start-1) of the VideoOutput instance to start the video output stream, and then call [start](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#start9) of the AVRecorder instance to start recording.

   <!-- @[camera_video_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

   ``` TypeScript
   async startVideo(): Promise<void> {
     Logger.info(TAG, 'startVideo is called');
     try {
       await this.videoOutput?.start();
       await this.avRecorder?.start();
       this.isRecording = true;
     } catch (error) {
       let err = error as BusinessError;
       Logger.error(TAG, `startVideo err: ${err.code}`);
     }
     Logger.info(TAG, 'startVideo End of call');
   }
   ```

5. Stop video recording.

   Call [stop](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#stop9-1) of the AVRecorder instance to stop recording, and then call [stop](../../reference/apis-camera-kit/arkts-apis-camera-VideoOutput.md#stop-1) of the VideoOutput instance to stop the video output stream.

   <!-- @[camera_video_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

   ``` TypeScript
   async stopVideo(): Promise<void> {
     Logger.info(TAG, 'stopVideo is called');
     if (!this.isRecording) {
       Logger.info(TAG, 'not in recording');
       return;
     }
     try {
       if (this.avRecorder) {
         await this.avRecorder.stop();
       }
       if (this.videoOutput) {
         await this.videoOutput.stop();
       }
       this.isRecording = false;
     } catch (error) {
       let err = error as BusinessError;
       Logger.error(TAG, `stopVideo err: ${err.code}`);
     }
     Logger.info(TAG, 'stopVideo End of call');
   }
   ```

## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a VideoOutput instance is created and is triggered when the bottom layer starts exposure for recording for the first time. The recording is considered to have started when this event is triggered.

  <!-- @[camera_video_frameStart](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

  ``` TypeScript
  videoOutput.on('frameStart', (err: BusinessError) => {
    if (err !== undefined && err.code !== 0) {
      return;
    }
    console.info('Video frame started');
  });
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a VideoOutput instance is created and is triggered when the last frame of recording ends. The recording stream is considered to have ended when this event is triggered.

  <!-- @[camera_video_frameEnd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    

  ``` TypeScript
  videoOutput.on('frameEnd', (err: BusinessError) => {
    if (err !== undefined && err.code !== 0) {
      return;
    }
    console.info('Video frame ended');
  });
  ```

- Register a fixed error callback to listen for recording output errors. The callback returns the error code corresponding to the error that occurs when the recording output API is used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

  <!-- @[camera_video_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->   

  ``` TypeScript
  videoOutput.on('error', (error: BusinessError) => {
    console.error(`Video output error code: ${error.code}`);
  });
  ```

<!--RP1-->
<!--RP1End-->