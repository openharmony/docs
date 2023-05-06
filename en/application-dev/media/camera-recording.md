# Camera Recording

Video recording is also an important function of the camera application. Video recording is the process of cyclic capturing of frames. To smooth videos, you can follow step 4 in [Camera Photographing](camera-shooting.md) to set the resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the media module. The [APIs](../reference/apis/js-apis-media.md) provided by this module are used to obtain the surface ID and create a photo output stream.
     
   ```ts
   import media from '@ohos.multimedia.media';
   ```

2. Create a surface.
   
   Call **createAVRecorder()** of the media module to create an **AVRecorder** instance, and call **getInputSurface()** of the instance to obtain the surface ID, which is associated with the view output stream to process the data output by the stream.
 
   ```ts
   let AVRecorder;
   media.createAVRecorder((error, recorder) => {
      if (recorder != null) {
          AVRecorder = recorder;
          console.info('createAVRecorder success');
      } else {
          console.info(`createAVRecorder fail, error:${error}`);
      }
   });
   // For details about AVRecorderConfig, see the next section.
   AVRecorder.prepare(AVRecorderConfig, (err) => {
      if (err == null) {
          console.log('prepare success');
      } else {
          console.log('prepare failed and error is ' + err.message);
      }
   })

   let videoSurfaceId = null; 
   AVRecorder.getInputSurface().then((surfaceId) => {
      console.info('getInputSurface success');
      videoSurfaceId = surfaceId; 
   }).catch((err) => {
      console.info('getInputSurface failed and catch error is ' + err.message); 
   });
   ```

3. Create a video output stream.
     
    Obtain the video output streams supported by the current device from **videoProfiles** in the **CameraOutputCapability** class. Then, define video recording parameters and use **createVideoOutput()** to create a video output stream.
     
   ```ts
   let videoProfilesArray = cameraOutputCapability.videoProfiles;
   if (!videoProfilesArray) {
       console.error("createOutput videoProfilesArray == null || undefined");
   } 
   
   // Define video recording parameters.
   let videoConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: {
           fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file encapsulation format. Only MP4 is supported.
           videoBitrate: 100000, // Video bit rate.
           videoCodec: media.CodecMimeType.VIDEO_MPEG4, // Video file encoding format. Both MPEG-4 and AVC are supported.
           videoFrameWidth: 640, // Video frame width.
           videoFrameHeight: 480, // Video frame height.
           videoFrameRate: 30 // Video frame rate.
       },
       url: 'fd://35',
       rotation: 0
   } 
   // Create an AVRecorder instance.
   let avRecorder;
   media.createAVRecorder((error, recorder) => {
     if (recorder != null) {
         avRecorder = recorder;
         console.info('createAVRecorder success');
     } else {
         console.info(`createAVRecorder fail, error:${error}`);
     }
    });
   // Set video recording parameters.
   avRecorder.prepare(videoConfig);
   // Create a VideoOutput instance.
   let videoOutput;
   try {
       videoOutput = cameraManager.createVideoOutput(videoProfilesArray[0], videoSurfaceId);
   } catch (error) {
       console.error('Failed to create the videoOutput instance. errorCode = ' + error.code);
   }
   ```

4. Start video recording.
   
   Call **start()** of the **VideoOutput** instance to start the video output stream, and then call **start()** of the **AVRecorder** instance to start recording.

   ```
   videoOutput.start(async (err) => {
       if (err) {
           console.error('Failed to start the video output ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the video output start success.');
   });
    
   avRecorder.start().then(() => {
       console.info('avRecorder start success');
   }
   ```

5. Stop video recording.
     
   Call **stop()** of the **AVRecorder** instance to stop recording, and then call **stop()** of the **VideoOutput** instance to stop the video output stream.
     
   ```ts
   videoRecorder.stop().then(() => {
       console.info('stop success');
   }
   
   videoOutput.stop((err) => {
       if (err) {
           console.error('Failed to stop the video output ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the video output stop success.');
   });
   ```


## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and recording stream output errors.

- Register the 'frameStart' event to listen for recording start events. This event can be registered when a **VideoOutput** object is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording is started as long as a result is returned.
    
  ```ts
  videoOutput.on('frameStart', () => {
      console.info('Video frame started');
  })
  ```

- Register the 'frameEnd' event to listen for recording end events. This event can be registered when a **VideoOutput** object is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```ts
  videoOutput.on('frameEnd', () => {
      console.info('Video frame ended');
  })
  ```

- Register the 'error' event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  videoOutput.on('error', (error) => {
      console.info(`Video output error code: ${error.code}`);
  })
  ```
