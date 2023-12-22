# Secondary Processing of Preview Streams (C/C++)

You can use the APIs in the **ImageReceiver** class to create a **PreviewOutput** instance and obtain real-time data of the preview stream for secondary processing. For example, you can add a filter algorithm to the preview stream.

## How to Develop

Read [Camera](../reference/native-apis/_o_h___camera.md) for the API reference.

1. Import the NDK, which provides camera-related attributes and methods.
     
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

2. Link the camera NDK dynamic library in the CMake script.

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

3. Obtain the surface ID.
   
   Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and use **getReceivingSurfaceId()** of the instance to obtain the surface ID, which is associated with the preview output stream to obtain the stream data.
 
   ```ts
   async function getPreviewSurfaceId(): Promise<string | undefined> {
     let previewSurfaceId: string | undefined = undefined;
     let previewReceiver: image.ImageReceiver = image.createImageReceiver(320, 240, 2000, 8);
     console.info('before ImageReceiver check');
     if (previewReceiver !== undefined) {
       console.info('ImageReceiver is ok');
       previewSurfaceId = await previewReceiver.getReceivingSurfaceId();
       console.info(`ImageReceived id: ${JSON.stringify(previewSurfaceId)}`);
     } else {
       console.info('ImageReceiver is not ok');
     }
     return previewSurfaceId;
   }
   ```

4. Call **OH_CameraManager_GetSupportedCameraOutputCapability** to obtain the preview output capabilities supported by the current device. Then call **OH_CameraManager_CreatePreviewOutput** to create a **PreviewOutput** instance, with the parameters set to the **cameraManager** pointer, the first item in the **previewProfiles** array, the surface ID obtained in step 3, and the returned **previewOutput** pointer, respectively.
     
   ```c++
    ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
    if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
    }
   ```

5. Configure the session. Call **commitConfig()** to commit the session configuration, and then call **start()** to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```c++
    ret = OH_PreviewOutput_Start(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Start failed.");
    }
   ```

6. Call **stop()** to stop the preview stream. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```c++
    ret = OH_PreviewOutput_Stop(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Stop failed.");
    }
   ```

## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a **PreviewOutput** instance is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.
    
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
    ret = OH_PreviewOutput_RegisterCallback(previewOutput_, GetPreviewOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
    }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a **PreviewOutput** instance is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```c++
    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
    }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```c++
    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
    }
  ```
