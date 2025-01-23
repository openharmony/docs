# Video Recording (ArkTS)

As another important function of the camera application, video recording is the process of cyclic frame capture. To smooth video recording, you can follow step 4 in [Photo Capture](camera-shooting.md) to set the resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the media module.

   The [APIs](../../reference/apis-media-kit/js-apis-media.md) provided by this module are used to obtain the surface ID and create a video output stream.
     
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { camera } from '@kit.CameraKit';
   import { media } from '@kit.MediaKit';
   ```

2. Create a surface.
   
   Call **createAVRecorder()** of the media module to create an **AVRecorder** instance, and call [getInputSurface](../../reference/apis-media-kit/js-apis-media.md#getinputsurface9) of the instance to obtain the surface ID, which is associated with the video output stream to process the stream data.

   ```ts
   async function getVideoSurfaceId(aVRecorderConfig: media.AVRecorderConfig): Promise<string | undefined> {  // For details about aVRecorderConfig, see the next section.
     let avRecorder: media.AVRecorder | undefined = undefined;
     try {
       avRecorder = await media.createAVRecorder();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`createAVRecorder call failed. error code: ${err.code}`);
     }
     if (avRecorder === undefined) {
       return undefined;
     }
     avRecorder.prepare(aVRecorderConfig, (err: BusinessError) => {
       if (err == null) {
         console.info('prepare success');
       } else {
         console.error('prepare failed and error is ' + err.message);
       }
     });
     let videoSurfaceId = await avRecorder.getInputSurface();
     return videoSurfaceId;
   }
   ```

3. Create a video output stream.

   Obtain the video output streams supported by the current device from **videoProfiles** in the [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability) class. Then, define video recording parameters and use [createVideoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createvideooutput) to create a video output stream.

   > **NOTE**
   >
   > The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio in the code snippet below is 640:480 (which is equal to 4:3), then the aspect ratio of the resolution of the preview stream must also be 4:3. This means that the resolution can be 640:480, 960:720, 1440:1080, or the like.
   >
   > To obtain the video rotation angle (specified by **rotation**), call [getVideoRotation](../../reference/apis-camera-kit/js-apis-camera.md#getvideorotation12) in the [VideoOutput](../../reference/apis-camera-kit/js-apis-camera.md#videooutput) class.

   ```ts
   async function getVideoOutput(cameraManager: camera.CameraManager, videoSurfaceId: string, cameraOutputCapability: camera.CameraOutputCapability): Promise<camera.VideoOutput | undefined> {
     let videoProfilesArray: Array<camera.VideoProfile> = cameraOutputCapability.videoProfiles;
     if (!videoProfilesArray) {
       console.error("createOutput videoProfilesArray == null || undefined");
       return undefined;
     }
     // AVRecorderProfile
     let aVRecorderProfile: media.AVRecorderProfile = {
       fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file container format. Only MP4 is supported.
       videoBitrate: 100000, // Video bit rate.
       videoCodec: media.CodecMimeType.VIDEO_AVC, // Video file encoding format. AVC is supported.
       videoFrameWidth: 640, // Video frame width.
       videoFrameHeight: 480, // Video frame height.
       videoFrameRate: 30 // Video frame rate.
     };
     // Define video recording parameters. The ratio of the resolution width (videoFrameWidth) to the resolution height (videoFrameHeight) of the video output stream must be the same as that of the preview stream.
     let aVRecorderConfig: media.AVRecorderConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: aVRecorderProfile,
       url: 'fd://35',
       rotation: 90 // The value of rotation is 90, which is obtained through getPhotoRotation.
     };
     // Create an AVRecorder instance.
     let avRecorder: media.AVRecorder | undefined = undefined;
     try {
       avRecorder = await media.createAVRecorder();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`createAVRecorder call failed. error code: ${err.code}`);
     }
     if (avRecorder === undefined) {
       return undefined;
     }
     // Set video recording parameters.
     avRecorder.prepare(aVRecorderConfig);
     // Create a VideoOutput instance.
     let videoOutput: camera.VideoOutput | undefined = undefined;
     // The width and height of the videoProfile object passed in by createVideoOutput must be the same as those of aVRecorderProfile.
     let videoProfile: undefined | camera.VideoProfile = videoProfilesArray.find((profile: camera.VideoProfile) => {
       return profile.size.width === aVRecorderProfile.videoFrameWidth && profile.size.height === aVRecorderProfile.videoFrameHeight;
     });
     if (!videoProfile) {
       console.error('videoProfile is not found');
       return;
     }
     try {
       videoOutput = cameraManager.createVideoOutput(videoProfile, videoSurfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error('Failed to create the videoOutput instance. errorCode = ' + err.code);
     }
     return videoOutput;
   }
   ```

4. Start video recording.
   
   Call [start](../../reference/apis-camera-kit/js-apis-camera.md#start-1) of the **VideoOutput** instance to start the video output stream, and then call [start](../../reference/apis-media-kit/js-apis-media.md#start9) of the **AVRecorder** instance to start recording.

   ```ts
   async function startVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
     videoOutput.start(async (err: BusinessError) => {
       if (err) {
         console.error(`Failed to start the video output ${err.message}`);
         return;
       }
       console.info('Callback invoked to indicate the video output start success.');
     });
     try {
       await avRecorder.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`avRecorder start error: ${JSON.stringify(err)}`);
     }
   }
   ```

5. Stop video recording.

   Call [stop](../../reference/apis-media-kit/js-apis-media.md#stop9-3) of the **AVRecorder** instance to stop recording, and then call [stop](../../reference/apis-camera-kit/js-apis-camera.md#stop-1) of the **VideoOutput** instance to stop the video output stream.
     
   ```ts
   async function stopVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
     try {
       await avRecorder.stop();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
     }
     videoOutput.stop((err: BusinessError) => {
       if (err) {
         console.error(`Failed to stop the video output ${err.message}`);
         return;
       }
       console.info('Callback invoked to indicate the video output stop success.');
     });
   }
   ```


## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a **VideoOutput** instance is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording starts as long as a result is returned.
    
  ```ts
  function onVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
    videoOutput.on('frameStart', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Video frame started');
    });
  }
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a **VideoOutput** instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```ts
  function onVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
    videoOutput.on('frameEnd', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Video frame ended');
    });
  }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  function onVideoOutputError(videoOutput: camera.VideoOutput): void {
    videoOutput.on('error', (error: BusinessError) => {
      console.error(`Video output error code: ${error.code}`);
    });
  }
  ```

<!--RP1-->
<!--RP1End-->
