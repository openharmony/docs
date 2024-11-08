# Video Recording (C/C++)

As another important function of the camera application, video recording is the process of cyclic frame capture. To smooth video recording, you can follow step 5 in [Photo Capture](native-camera-shooting.md) to set the resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/_o_h___camera.md) for the API reference.

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
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. Obtain the surface ID.
   
   Create an **AVRecorder** instance, and call **getInputSurface()** of the instance to obtain a surface ID.

4. Create a video output stream.

   Based on the surface ID passed in, obtain the video output streams supported by the current device from **videoProfiles** in the **CameraOutputCapability** class. Then, define video recording parameters and use **createVideoOutput()** to create a video output stream.

   ```c++
    NDKCamera::NDKCamera(char *str)
    {
      Camera_Manager *cameraManager = nullptr;
      Camera_Device* cameras = nullptr;
      Camera_OutputCapability* cameraOutputCapability = nullptr;
      Camera_VideoOutput* videoOutput = nullptr;
      const Camera_VideoProfile* videoProfile;
      uint32_t size = 0;
      uint32_t cameraDeviceIndex = 0;
      char* videoSurfaceId = str;
      Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
      if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
      }
      ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
      if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
      }
      ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                  &cameraOutputCapability);
      if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
      }
      if (cameraOutputCapability->videoProfilesSize < 0) {
        OH_LOG_ERROR(LOG_APP, "videorofilesSize == null");
      }
      videoProfile = cameraOutputCapability->videoProfiles[0];
      // Create a VideoOutput instance.
      ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
      if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
      }
    }
   ```

5. Start video recording.
   
   Call **OH_VideoOutput_Start()** of the **VideoOutput** instance to start the video output stream.

   ```c++
      // Start the video output stream.
      ret = OH_VideoOutput_Start(videoOutput);
      if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
      }
   ```

6. Stop video recording.
     
   Call **OH_VideoOutput_Stop()** of the **VideoOutput** instance to stop the video output stream.

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
    ret = OH_VideoOutput_RegisterCallback(videoOutput, GetVideoOutputListener());
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
    }
  ```
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
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a **VideoOutput** instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```c++
    void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
    }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1).
    
  ```c++
    void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
    }
  ```
