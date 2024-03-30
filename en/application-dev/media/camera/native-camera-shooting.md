# Camera Photographing (C/C++)

Photographing is an important function of the camera application. Based on the complex logic of the camera hardware, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

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
   
    Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and call **getReceivingSurfaceId()** of the instance to obtain the surface ID.

4. Create a photo output stream.
   
   Based on the surface ID passed in, call **OH_CameraManager_GetSupportedCameraOutputCapability()** to obtain the photo output streams supported by the current device, and then call **OH_CameraManager_CreatePhotoOutput()** to pass in a supported output stream and the surface ID obtained in step 3 to create a photo output stream.

   ```c++
    NDKCamera::NDKCamera(char *str)
    {
        Camera_Manager* cameraManager = nullptr;
        Camera_Device* cameras = nullptr;
        Camera_OutputCapability* cameraOutputCapability = nullptr;
        Camera_PhotoOutput* photoOutput = nullptr;
        Camera_CaptureSession* captureSession = nullptr;
        const Camera_Profile* photoProfile = nullptr;
        uint32_t size = 0;
        uint32_t cameraDeviceIndex = 0;
        char* photoSurfaceId = str;
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
        }
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
        }
        ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex], &cameraOutputCapability);
        if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "GetSupportedCameraOutputCapability failed.");
        }
        photoProfile = cameraOutputCapability->photoProfiles[0];
        if (photoProfile == nullptr) {
            OH_LOG_ERROR(LOG_APP, "Get photoProfiles failed.");
        }
        ret = OH_CameraManager_CreatePhotoOutput(cameraManager, photoProfile, photoSurfaceId, &photoOutput);
        if (photoOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePhotoOutput failed.");
        }
    }
   ```

5. Set camera parameters.

   You can set camera parameters to adjust photographing functions, including the flash, zoom ratio, and focal length.

   ```c++
    // Check whether the camera has flash.
    Camera_FlashMode flashMode = FLASH_MODE_AUTO;
    bool hasFlash = false;
    ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
    if (captureSession == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
    }
    ret = OH_CaptureSession_HasFlash(captureSession, &hasFlash);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_HasFlash failed.");
    }
    if (hasFlash) {
        OH_LOG_INFO(LOG_APP, "hasFlash success");
    } else {
        OH_LOG_ERROR(LOG_APP, "hasFlash fail");
    }
    // Check whether a flash mode is supported.
    bool isSupported = false;
    ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
    }
    if (isSupported) {
        OH_LOG_INFO(LOG_APP, "isFlashModeSupported success");
        // Set the flash mode.
        ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
        }
        // Obtain the flash mode in use.
        ret = OH_CaptureSession_GetFlashMode(captureSession, &flashMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode: %{public}d ", flashMode);
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
        }
    } else {
        OH_LOG_ERROR(LOG_APP, "isFlashModeSupported fail");
    }

    // Check whether the continuous auto focus is supported.
    Camera_FocusMode focusMode = FOCUS_MODE_CONTINUOUS_AUTO;
    bool isFocusModeSupported = false;
    ret = OH_CaptureSession_IsFocusModeSupported(captureSession, focusMode, &isFocusModeSupported);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFocusModeSupported failed.");
    }
    if (isFocusModeSupported) {
        OH_LOG_INFO(LOG_APP, "isFocusModeSupported success");
        ret = OH_CaptureSession_SetFocusMode(captureSession, focusMode);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFocusMode failed. %{public}d ", ret);
        }
        ret = OH_CaptureSession_GetFocusMode(captureSession, &focusMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFocusMode success. focusMode%{public}d ", focusMode);
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFocusMode failed. %d ", ret);
        }
    } else {
        OH_LOG_ERROR(LOG_APP, "isFocusModeSupported fail");
    }

    // Obtain the zoom ratio range supported by the camera.
    float minZoom;
    float maxZoom;
    ret = OH_CaptureSession_GetZoomRatioRange(captureSession, &minZoom, &maxZoom);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
    } else {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
            minZoom, maxZoom);
    }
    // Set a zoom ratio.
    ret = OH_CaptureSession_SetZoomRatio(captureSession, maxZoom);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
    }
    // Obtain the zoom ratio of the camera.
    ret = OH_CaptureSession_GetZoomRatio(captureSession, &maxZoom);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom: %{public}f ", maxZoom);
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
    }
   ```

6. Trigger photographing.

    Call **OH_PhotoOutput_Capture()**.

     ```c++
      ret = OH_PhotoOutput_Capture(photoOutput);
      if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
      } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
      }
     ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'onFrameStart'** event to listen for photographing start events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the bottom layer starts exposure for photographing for the first time. The capture ID is returned.
    
  ```c++
    ret = OH_PhotoOutput_RegisterCallback(photoOutput, GetPhotoOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
    }
  ```
  ```c++
    void PhotoOutputOnFrameStart(Camera_PhotoOutput* photoOutput)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
    }
    void PhotoOutputOnFrameShutter(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameShutter");
    }
    PhotoOutput_Callbacks* GetPhotoOutputListener()
    {
        static PhotoOutput_Callbacks photoOutputListener = {
            .onFrameStart = PhotoOutputOnFrameStart,
            .onFrameShutter = PhotoOutputOnFrameShutter,
            .onFrameEnd = PhotoOutputOnFrameEnd,
            .onError = PhotoOutputOnError
        };
        return &photoOutputListener;
    }
  ```

- Register the **'onFrameEnd'** event to listen for photographing end events. This event can be registered when a **PhotoOutput** instance is created.
    
  ```c++
    void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
    }
  ```

- Register the **'onError'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1).
    
  ```c++
    void PhotoOutputOnError(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
    }
  ```
