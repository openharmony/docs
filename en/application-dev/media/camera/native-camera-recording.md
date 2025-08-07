# Video Recording (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

As another important function of the camera application, video recording is the process of cyclic frame capture. To smooth video recording, you can follow step 5 in [Photo Capture](native-camera-shooting.md) to set the resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK, which provides camera-related attributes and methods.
     
   ```c++
   // Include the NDK header files.
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. Obtain the surface ID.
   
   Create an AVRecorder instance, and call **getInputSurface()** of the instance to obtain a surface ID.

4. Create a video output stream.

   Based on the surface ID passed in, call [OH_CameraManager_GetSupportedCameraOutputCapability](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapability) to obtain [Camera_OutputCapability](../../reference/apis-camera-kit/capi-oh-camera-camera-outputcapability.md). From there, you can access **videoProfiles** to obtain the video output streams supported by the device. Then, define video recording parameters and use **OH_CameraManager_CreateVideoOutput** to create a video output stream.

   ```c++
   Camera_VideoOutput* CreateVideoOutput(Camera_Manager* cameraManager, char* videoSurfaceIdStr,
       const Camera_VideoProfile* videoProfile)
   {
       // Create a VideoOutput instance.
       Camera_VideoOutput* videoOutput = nullptr;
       Camera_ErrorCode ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceIdStr,
           &videoOutput);
       if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
       }
       return videoOutput;
   }
   ```

5. Start video recording.
   
   Call [OH_VideoOutput_Start()](../../reference/apis-camera-kit/capi-video-output-h.md#oh_videooutput_start) to start the video output stream.

   ```c++
   // Start the video output stream.
   Camera_ErrorCode VideoOutputStart(Camera_VideoOutput* videoOutput)
   {
       Camera_ErrorCode ret = OH_VideoOutput_Start(videoOutput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
       }
       return ret;
   }
   ```

6. Stop video recording.
     
   Call [OH_VideoOutput_Stop()](../../reference/apis-camera-kit/capi-video-output-h.md#oh_videooutput_stop) to stop the video output stream.

   ```c++
   // Stop the video output stream.
   Camera_ErrorCode VideoOutputStop(Camera_VideoOutput* videoOutput)
   {
       Camera_ErrorCode ret = OH_VideoOutput_Stop(videoOutput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
       }
       return ret;
   }
   ```


## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a VideoOutput instance is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording starts as long as the event is triggered.

  ```c++
  void VideoOutputOnFrameStart(Camera_VideoOutput* videoOutput)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
  }
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a VideoOutput instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```c++
  void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).
    
  ```c++
  void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```
  ```c++
  VideoOutput_Callbacks* GetVideoOutputListener(void)
  {
      static VideoOutput_Callbacks videoOutputListener = {
          .onFrameStart = VideoOutputOnFrameStart,
          .onFrameEnd = VideoOutputOnFrameEnd,
          .onError = VideoOutputOnError
      };
      return &videoOutputListener;
  }

  Camera_ErrorCode RegisterVideoOutputCallback(Camera_VideoOutput* videoOutput)
  {
      Camera_ErrorCode ret = OH_VideoOutput_RegisterCallback(videoOutput, GetVideoOutputListener());
      if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
      }
      return ret;
  }
  ```
