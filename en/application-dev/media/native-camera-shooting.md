# Camera Photographing (C/C++)

Photographing is an important function of the camera application. Based on the complex logic of the camera hardware, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../reference/native-apis/_o_h___camera.md) for the API reference.

1. Import the image module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.
   
   ```ts
   // Import the image module on the TS side. The surface ID for the photo output stream is obtained through ImageReceiver.
   import image from '@ohos.multimedia.image';
   private mReceiver: image.ImageReceiver = undefined
   ```

2. Obtain the surface ID.
   
   Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and use **getReceivingSurfaceId()** of the instance to obtain the surface ID, which is associated with the photo output stream to process the stream data.

   ```ts
   // Obtain the surface ID for the photo output stream. (Call the APIs in modeSwitchPage.ets.)
    async getPhotoSurfaceID() {
        if(this.mReceiver) {
        Logger.info(this.tag, 'imageReceiver has been created')
        } else {
        this.createImageReceiver()
        }
        this.photoSurfaceId = await this.mReceiver.getReceivingSurfaceId()
        if(this.photoSurfaceId) {
        Logger.info(this.tag, `createImageReceiver photoSurfaceId: ${this.photoSurfaceId} `)
        } else {
        Logger.info(this.tag, `Get photoSurfaceId failed `)
        }
    }
   ```

3. Link the camera NDK dynamic library in the CMake script.
   ```txt
    target_link_libraries(PUBLIC libcamera_ndk.so)
   ```


4. Import the NDK. The NDK is used for creating photo output data, setting camera parameters, and triggering photographing.

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

5. Create a photo output stream.
   
   Call **OH_CameraManager_GetSupportedCameraOutputCapability** to obtain the photo output streams supported by the current device, and then call **OH_CameraManager_CreatePhotoOutput** to pass in a supported output stream and the surface ID obtained in step 2 to create a photo output stream.

   ```c++
    Camera_Manager* cameraManager = nullptr;
    Camera_Device* cameras = nullptr;
    Camera_CaptureSession* captureSession = nullptr;
    Camera_OutputCapability* cameraOutputCapability = nullptr;
    const Camera_Profile* previewProfile = nullptr;
    const Camera_Profile* photoProfile = nullptr;
    Camera_PreviewOutput* previewOutput = nullptr;
    Camera_PhotoOutput* photoOutput = nullptr;
    Camera_Input* cameraInput = nullptr;
    uint32_t size = 0;
    uint32_t cameraDeviceIndex = 0;

    Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex], &cameraOutputCapability);
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
   ```

6. Set camera parameters.

   You can set camera parameters to adjust photographing functions, including the flash, zoom ratio, and focal length.

   ```c++
    // Check whether the camera has flash.
    Camera_FlashMode flashMode = FLASH_MODE_AUTO;
    bool hasFlash = false;
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

7. Trigger photographing.

   - Call **OH_PhotoOutput_Capture**. In this API, the input parameter is the **photoOutput** instance created by using **createPhotoOutput()**.

     ```c++
      Camera_ErrorCode ret = OH_PhotoOutput_Capture(photoOutput);
      if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
      } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
      }
     ```

   - Call **OH_PhotoOutput_Capture_WithCaptureSetting**. In this API, the first parameter specifies the settings (for example, photo quality and rotation angle) for photographing, and the second parameter is a callback function.

     ```c++
      Camera_PhotoCaptureSetting* photoSetting = nullptr;
      photoSetting->quality = QUALITY_LEVEL_HIGH; // Set the photo quality to high.
      photoSetting->rotation = IMAGE_ROTATION_0; // Set the rotation angle of the photo to 0.
  
      // Use the current photographing settings to take photos.
      ret = OH_PhotoOutput_Capture_WithCaptureSetting(photoOutput, photoSetting);
      if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture_WithCaptureSetting success ");
      } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture_WithCaptureSetting failed. %d ", ret);
      }
     ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'onFrameStart'** event to listen for photographing start events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the bottom layer starts exposure for photographing for the first time. The capture ID is returned.
  
  ```c++
    void PhotoOutputOnFrameStart(Camera_PhotoOutput* photoOutput)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
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
    Camera_ErrorCode ret = OH_PhotoOutput_RegisterCallback(photoOutput, GetPhotoOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
    }
  ```

- Register the **'onFrameEnd'** event to listen for photographing end events. This event can be registered when a **PhotoOutput** instance is created and is triggered when the photographing is complete. [CaptureEndInfo](../reference/apis/js-apis-camera.md#captureendinfo) is returned.
  
  ```c++
    void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
    }
  ```

- Register the **'onError'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
  
  ```c++
    void PhotoOutputOnError(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
    }
  ```

