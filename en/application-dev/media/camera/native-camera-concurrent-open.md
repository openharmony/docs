# Multi-Camera Concurrent Mode (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-10T09:18:10.395Z pushedAt=2026-08-10T13:12:35.800Z -->

Starting from API version 18, concurrent camera opening is supported, which allows an app to simultaneously open the front and rear cameras for preview and video recording. (Simultaneous photo capture with both front and rear cameras is coming soon.)

>**NOTE**
>
> Operating both cameras at the same time imposes significant restrictions on available features. The current implementation supports seven core functions, as listed below. When using multi-camera concurrent mode, avoid accessing or enabling any capabilities beyond them.
>   1. Flash
>   2. Exposure
>   3. Zoom
>   4. Exposure compensation
>   5. Focus
>   6. Stabilization
>   7. Color space

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK, which provides camera-related properties and methods.

   ```c++
   #include <cstdint>
   #include <unistd.h>
   #include <string>
   #include <thread>
   #include <cstdio>
   #include <fcntl.h>
   #include <map>
   #include <vector>
   #include <native_buffer/native_buffer.h>
   #include "iostream"
   #include "mutex"
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "napi/native_api.h"
   #include "ohcamera/camera_manager.h"
   #include "common/log_common.h"
   ```

2. Link the dynamic libraries in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
      libohcamera.so
      libace_napi.z.so
      libnative_buffer.so
      libhilog_ndk.z.so
      librawfile.z.so)
   ```

3. Obtain the corresponding front camera and rear camera through the [OH_CameraManager_GetCameraDevice](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getcameradevice) method. If the API returns `CAMERA_SERVICE_FATAL_ERROR`, it indicates, based on the configuration in the example, that the current device does not support the default camera type at the specified position (front or rear), and concurrent camera opening cannot be implemented.

   ```c++
   void GetSupportedCameras(Camera_Manager *cameraManager)
   {
       Camera_Device *cameras;
       uint32_t size = 0;
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
       if (cameras == nullptr || &size == nullptr || ret != CAMERA_OK) {
           return;
       }

       // Obtain the rear camera.
       ret = OH_CameraManager_GetCameraDevice(cameraManager, Camera_Position::CAMERA_POSITION_BACK, Camera_Type::CAMERA_TYPE_DEFAULT, &cameras[0]);

       // Obtain the front camera.
       ret = OH_CameraManager_GetCameraDevice(cameraManager, Camera_Position::CAMERA_POSITION_FRONT, Camera_Type::CAMERA_TYPE_DEFAULT, &cameras[1]);
   }
   ```

4. Obtain the corresponding concurrent capability set. Use the [OH_CameraManager_GetCameraConcurrentInfos](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getcameraconcurrentinfos) method to obtain the [Camera_ConcurrentInfo](../../reference/apis-camera-kit/capi-oh-camera-camera-concurrentinfo.md) camera concurrent capability set object array. The array contains the camera modes and camera output capabilities supported by the simultaneously opened front and rear cameras in the specified concurrent camera opening mode. **In the concurrent camera opening scenario, the configured mode and output capabilities must fall within the scope of the concurrent capability set.**

   ```c++
   void GetSupportedOutputCapability(Camera_Manager *cameraManager, Camera_Device *cameras)
   {
       Camera_ConcurrentInfo* cameraConcurrentInfo;
       uint32_t infoSize = 0;
       Camera_ErrorCode ret = OH_CameraManager_GetCameraConcurrentInfos(cameraManager, cameras, 2, &cameraConcurrentInfo, &infoSize);
       if (cameraConcurrentInfo == nullptr || cameraConcurrentInfo->outputCapabilities == nullptr
           || cameraConcurrentInfo->outputCapabilities->previewProfiles == nullptr || ret != CAMERA_OK) {
           return;
      }
   }
   ```

5. Create a PreviewOutput object based on the concurrency capability set.

   ```c++
   void CreatePreviewOutput(Camera_Manager *cameraManager, Camera_ConcurrentInfo* cameraConcurrentInfo, char* previewSurfaceId)
   {
       Camera_Profile *profile = cameraConcurrentInfo->outputCapabilities->previewProfiles[0];
       if (profile == nullptr) {
           return;
       }
       Camera_PreviewOutput *previewOutput;
       Camera_ErrorCode ret = OH_CameraManager_CreatePreviewOutput(cameraManager, profile, previewSurfaceId, &previewOutput);
       if (previewOutput == nullptr || ret != CAMERA_OK) {
           return;
       }
   }
   ```

6. Open the camera. Call [OH_CameraInput_OpenConcurrentCameras](../../reference/apis-camera-kit/capi-camera-input-h.md#oh_camerainput_openconcurrentcameras) to open the specified camera in multi-camera concurrent mode. Before using this API, check whether the camera supports concurrent capabilities and call [OH_CameraManager_GetCameraConcurrentInfos](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getcameraconcurrentinfos) to obtain the concurrent capability set in the multi-camera concurrent mode. Do not use [OH_CameraInput_OpenConcurrentCameras](../../reference/apis-camera-kit/capi-camera-input-h.md#oh_camerainput_openconcurrentcameras) without querying the concurrency capability set, as this will result in camera opening failure.

   ```c++
   void CameraInputOpen(Camera_Manager *cameraManager, Camera_Device *cameras)
   {
       Camera_Input *cameraInput;
       Camera_ErrorCode ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[0], &cameraInput);
       if (cameraInput == nullptr || ret != CAMERA_OK) {
           return;
       }
       // The current version supports opening the camera only in CAMERA_CONCURRENT_TYPE_LIMITED_CAPABILITY mode.
       ret = OH_CameraInput_OpenConcurrentCameras(cameraInput, Camera_ConcurrentType::CAMERA_CONCURRENT_TYPE_LIMITED_CAPABILITY);
       if (ret != CAMERA_OK) {
           return;
       }
   }
   ```

7. Implement the session flow. Configure the corresponding camera input stream [Camera_Input](../../reference/apis-camera-kit/capi-oh-camera-camera-input.md) and the required camera output streams. This example uses the preview output stream [Camera_PreviewOutput](../../reference/apis-camera-kit/capi-oh-camera-camera-previewoutput.md).

   ```c++
   void SessionFlowFn(Camera_CaptureSession *captureSession, Camera_Input *cameraInput, Camera_PreviewOutput *previewOutput)
   {
       // Start configuration for the session.
       Camera_ErrorCode ret = OH_CaptureSession_BeginConfig(captureSession);

       // Add the camera input stream to the session.
       ret = OH_CaptureSession_AddInput(captureSession, cameraInput);

       // Add the preview output stream to the session.
       ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);

       // Commit the configuration.
       ret = OH_CaptureSession_CommitConfig(captureSession);

       // Start the session.
       ret = OH_CaptureSession_Start(captureSession);

       return;
   }
   ```

8. The following provides examples of configurable capabilities for front and rear cameras in multi-camera concurrent mode. (Currently, only the seven core functions listed at the beginning of this document are supported.)

   ```c++
   // Flash.
   void HasFlashFn(uint32_t mode, Camera_CaptureSession *captureSession)
   {
       Camera_FlashMode flashMode = static_cast<Camera_FlashMode>(mode);
       // Check whether the camera device has flash.
       bool hasFlash = false;
       Camera_ErrorCode ret = OH_CaptureSession_HasFlash(captureSession, &hasFlash);
       if (captureSession == nullptr || ret != CAMERA_OK || !hasFlash) {
           return;
       }

       // Check whether a flash mode is supported.
       bool isSupported = false;
      ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
       if (ret != CAMERA_OK || !isSupported) {
           return;
       }

       // Set the flash mode.
       ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
       if (ret != CAMERA_OK) {
           return;
       }

       // Obtain the flash mode in use.
       ret = OH_CaptureSession_GetFlashMode(captureSession, &flashMode);
    }

   // Exposure
   void IsExposureModeSupportedFn(uint32_t mode, Camera_CaptureSession *captureSession)
   {
       Camera_ExposureMode exposureMode = static_cast<Camera_ExposureMode>(mode);
       bool isExposureModeSupported = false;
       Camera_ErrorCode ret = OH_CaptureSession_IsExposureModeSupported(captureSession, exposureMode, &isExposureModeSupported);
       if (&isExposureModeSupported == nullptr || ret != CAMERA_OK) {
           return;
       }
       ret = OH_CaptureSession_SetExposureMode(captureSession, exposureMode);
       if (ret != CAMERA_OK) {
           return;
       }
       ret = OH_CaptureSession_GetExposureMode(captureSession, &exposureMode);
   }
   ```