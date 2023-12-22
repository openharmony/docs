# Camera Recording (C/C++)

As another important function of the camera application, video recording is the process of cyclic frame capture. To smooth video recording, you can follow step 4 in [Camera Photographing (Native)](native-camera-shooting.md) to set the resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../reference/native-apis/_o_h___camera.md) for the API reference.

1. Import the media module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.
     
   ```ts
   // Import the media module on the TS side.
   import media from '@ohos.multimedia.media';
   ```

2. Create a surface.
   
   Call **createAVRecorder()** of the media module to create an **AVRecorder** instance, and call **getInputSurface()** of the instance to obtain the surface ID, which is associated with the video output stream to process the stream data.

   ```ts
    // Obtain the surface ID for the video stream on the TS side. (Call the APIs in modeSwitchPage.ets.)
    async getVideoSurfaceID(){
      // Create an AVRecorder instance.
      this.videoRecorder = await media.createAVRecorder()
      this.fileAsset = await this.mediaUtil.createAndGetUri(mediaLibrary.MediaType.VIDEO)
      this.fd = await this.mediaUtil.getFdPath(this.fileAsset)
      this.videoConfig.url = `fd://${this.fd}`

      if (deviceInfo.deviceType == 'default') {
        Logger.info(this.tag, `deviceType = default`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_ES
      }
      if (deviceInfo.deviceType == 'phone') {
        Logger.info(this.tag, `deviceType = phone`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
        this.videoConfig.profile.videoCodec = media.CodecMimeType.VIDEO_MPEG4;
        if (this.cameraDeviceIndex == 1) {
          this.videoConfig.rotation = this.photoRotationMap.rotation270;
        } else {
          this.videoConfig.rotation = this.photoRotationMap.rotation90;
        }
      }
      if (deviceInfo.deviceType == 'tablet') {
        Logger.info(this.tag, `deviceType = tablet`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
      }

      this.videoConfig.profile.videoFrameWidth = 640;
      this.videoConfig.profile.videoFrameHeight = 480;
      this.videoConfig.profile.videoFrameRate = 30;
      // Set video recording parameters.
      await this.videoRecorder.prepare(this.videoConfig)
      this.videoSurfaceId = await this.videoRecorder.getInputSurface()
    }
   ```
3. Link the camera NDK dynamic library in the CMake script.

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

4. Import the NDK. The NDK is used for creating video output data, setting camera parameters, and triggering recording.

   ```c++
    // Include the NDK header files in camera_manager.cpp.
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

5. Create a video output stream.

   Obtain the video output streams supported by the current device from **videoProfiles** in the **CameraOutputCapability** class. Then, define video recording parameters and use **createVideoOutput()** to create a video output stream.

   **NOTE**: The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio in the code snippet below is 640:480 (which is equal to 4:3), then the aspect ratio of the resolution of the preview stream must also be 4:3. This means that the resolution can be 640:480, 960:720, 1440:1080, or the like.

   ```ts
     // Configure AVRecorderProfile on the TS side. (Call the APIs in modeSwitchPage.ets.)
     let aVRecorderProfile: media.AVRecorderProfile = {
       fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file encapsulation format. Only MP4 is supported.
       videoBitrate: 100000, // Video bit rate.
       videoCodec: media.CodecMimeType.VIDEO_MPEG4, // Video file encoding format. Both MPEG-4 and AVC are supported.
       videoFrameWidth: 640, // Video frame width.
       videoFrameHeight: 480, // Video frame height.
       videoFrameRate: 30 // Video frame rate.
     };
     // Define video recording parameters. The ratio of the resolution width (videoFrameWidth) to the resolution height (videoFrameHeight) of the video output stream must be the same as that of the preview stream.
     let aVRecorderConfig: media.AVRecorderConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: aVRecorderProfile,
       url: 'fd://35',
       rotation: 90 // 90° is the default vertical display angle. You can use other values based on project requirements.
     };
   ```
   ```c++
    // Obtain the output streams supported by the camera.
    ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                &cameraOutputCapability);
    if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
    }
    if (cameraOutputCapability->videorofilesSize < 0) {
      console.error("videorofilesSize == null");
    }
    videoProfile = cameraOutputCapability->videoProfiles[0];
     // Create a VideoOutput instance.
    ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
    if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
    }
   ```

6. Start video recording.
   
   Call **start()** of the **VideoOutput** instance to start the video output stream, and then call **start()** of the **AVRecorder** instance to start recording.

   ```c++
      // Start the video output stream.
      ret = OH_VideoOutput_Start(videoOutput);
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
      }
   ```
   ```ts
     // Start video recording.
     try {
       await avRecorder.start();
     } catch (error) {
       console.error(`avRecorder start error: ${JSON.stringify(err)}`);
     }
   ```

7. Stop video recording.
   
   Call **stop()** of the **AVRecorder** instance to stop recording, and then call **stop()** of the **VideoOutput** instance to stop the video output stream.
   ```ts
     // Stop video recording.
     try {
       await avRecorder.stop();
     } catch (error) {
       console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
     }
   ```
   ```c++
      // Stop the video output stream.
      ret = OH_VideoOutput_Stop(videoOutput);
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
      }
   ```


## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a **VideoOutput** instance is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording starts as long as a result is returned.
    
  ```c++
  void VideoOutputOnFrameStart(Camera_VideoOutput* videoOutput)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
  }

  VideoOutput_Callbacks* GetVideoOutputListener(void)
  {
      static VideoOutput_Callbacks videoOutputListener = {
          .onFrameStart = VideoOutputOnFrameStart,
          .onFrameEnd = VideoOutputOnFrameEnd,
          .onError = VideoOutputOnError
      };
      return &videoOutputListener;
  }
  ret = OH_VideoOutput_RegisterCallback(videoOutput_, GetVideoOutputListener());
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
  }
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a **VideoOutput** instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```c++
  void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```c++
  void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```
