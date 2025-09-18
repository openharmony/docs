# Preview (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK, which provides camera-related properties and methods.
     
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
     
    The **XComponent**, the capabilities of which are provided by the UI, offers the surface ID for preview streams. For details, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

4. Call [OH_CameraManager_GetSupportedCameraOutputCapability()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapability) to obtain the preview capability supported by the current device based on the surface ID. Then call [OH_CameraManager_CreatePreviewOutput()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createpreviewoutput) to create a PreviewOutput instance, with the parameters set to the **cameraManager** pointer, the first item in the **previewProfiles** array, the surface ID obtained in step 3, and the returned **previewOutput** pointer, respectively.
     
    ```c++
    Camera_PreviewOutput* CreatePreviewOutput(char* previewSurfaceIdstr, Camera_Manager* cameraManager,
        const Camera_Profile* previewProfile)
    {
        Camera_PreviewOutput* previewOutput = nullptr;
        Camera_ErrorCode ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile,
            previewSurfaceIdstr, &previewOutput);
        if (previewOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
        }
        return previewOutput;
    }
    ```

5. Configure the session. Call **commitConfig()** to commit the session configuration, and then call [OH_CaptureSession_Start()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_start) to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

   ```c++
   Camera_ErrorCode SessionStart(Camera_CaptureSession* captureSession)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Start(captureSession);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
       }
       return ret;
   }
   ```

6. Call [OH_CaptureSession_Stop()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_stop) to stop outputting the preview stream. If the call fails, an error code is returned. For details, see[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

   ```c++
   Camera_ErrorCode SessionStop(Camera_CaptureSession* captureSession)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Stop(captureSession);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed.");
       }
       return ret;
   }
   ```

## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a PreviewOutput object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.

  ```c++
  void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
  }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a PreviewOutput object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```c++
  void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).
    
  ```c++
  void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_ERROR(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
  }
  ```
  ```c++
  PreviewOutput_Callbacks* GetPreviewOutputListener(void)
  {
      static PreviewOutput_Callbacks previewOutputListener = {
          .onFrameStart = PreviewOutputOnFrameStart,
          .onFrameEnd = PreviewOutputOnFrameEnd,
          .onError = PreviewOutputOnError
      };
      return &previewOutputListener;
  }
  Camera_ErrorCode RegisterPreviewOutputCallback(Camera_PreviewOutput* previewOutput)
  {
      Camera_ErrorCode ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
      }
      return ret;
  }
  ```
