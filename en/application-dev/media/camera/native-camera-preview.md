# Camera Preview (C/C++)

Preview is the image you see after you start the camera application but before you take photos or record videos.

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
     
    The **\<XComponent>**, the capabilities of which are provided by the UI, offers the surface ID for preview streams. For details, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

4. Call **OH_CameraManager_GetSupportedCameraOutputCapability()** to obtain the preview capability supported by the current device based on the surface ID. Then call **OH_CameraManager_CreatePreviewOutput()** to create a **PreviewOutput** instance, with the parameters set to the **cameraManager** pointer, the first item in the **previewProfiles** array, the surface ID obtained in step 3, and the returned **previewOutput** pointer, respectively.
     
    ```c++
      NDKCamera::NDKCamera(char *str)
      {
        Camera_Manager *cameraManager = nullptr;
        Camera_Device* cameras = nullptr;
        Camera_OutputCapability* cameraOutputCapability = nullptr;
        Camera_PreviewOutput* previewOutput = nullptr;
        const Camera_Profile* previewProfile = nullptr;
        uint32_t size = 0;
        uint32_t cameraDeviceIndex = 0;
        char* previewSurfaceId = str;
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
        if (cameraOutputCapability->previewProfilesSize < 0) {
          OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
        }
        previewProfile = cameraOutputCapability->previewProfiles[0];

        ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
        if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
        }
      }
    ```

5. Configure the session. Call **commitConfig()** to commit the session configuration, and then call **start()** to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1).
     
   ```c++
    ret = OH_PreviewOutput_Start(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Start failed.");
    }
   ```

6. Call **stop()** to stop outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1).
     
   ```c++
    ret = OH_PreviewOutput_Stop(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Stop failed.");
    }
   ```

## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a **PreviewOutput** object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.
    
  ```c++
    ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
    }
  ```
  ```c++
    void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
    }
    PreviewOutput_Callbacks* GetPreviewOutputListener(void)
    {
        static PreviewOutput_Callbacks previewOutputListener = {
            .onFrameStart = PreviewOutputOnFrameStart,
            .onFrameEnd = PreviewOutputOnFrameEnd,
            .onError = PreviewOutputOnError
        };
        return &previewOutputListener;
    }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a **PreviewOutput** object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```c++
    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
    }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1).
    
  ```c++
    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
    }
  ```
