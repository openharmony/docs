# Macro Photography Settings (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=03da8d98875c99278437bdd28f12d4fdb3efd8f7 translatedAt=2026-08-10T09:20:01.977Z pushedAt=2026-08-10T13:22:08.851Z -->

Starting from API version 19, you can configure macro photography. This feature allows the camera to focus closely and capture detailed images of small objects through optimized optical design and algorithms.

## How to Develop

For detailed API descriptions, refer to [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK.  

   <!-- @[import_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.h) -->

   ``` C
   #include <cstdint>
   #include <native_buffer/buffer_common.h>
   #include <unistd.h>
   #include <string>
   #include <thread>
   #include <cstdio>
   #include <fcntl.h>
   #include <map>
   #include <string>
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
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   
   namespace OHOS_CAMERA_SAMPLE {
   class NDKCamera {
     public:
       struct CameraBuildingConfig {
           char *str;
           uint32_t focusMode;
           uint32_t cameraDeviceIndex;
           bool isVideo;
           bool isHdr;
           char *videoId;
       };
       ~NDKCamera();
       explicit NDKCamera(CameraBuildingConfig config);
       // ...
   };
   } // namespace OHOS_CAMERA_SAMPLE
   ```

2. Link the dynamic libraries in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. Call [OH_CaptureSession_IsMacroSupported()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_ismacrosupported) to check whether the current device supports macro photography.

   <!-- @[is_macro_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   bool NDKCamera::IsMacroSupported(Camera_CaptureSession* captureSession)
   {
       // Check whether the device supports macro capability.
       bool isMacroSupported = false;
       if (captureSession == nullptr) {
           OH_LOG_ERROR(LOG_APP, "IsMacroSupported: session is nullptr.");
           return isMacroSupported;
       }
       Camera_ErrorCode ret = OH_CaptureSession_IsMacroSupported(captureSession, &isMacroSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsMacroSupported failed.");
       }
       if (isMacroSupported) {
           OH_LOG_INFO(LOG_APP, "support macro capability.");
       } else {
           OH_LOG_ERROR(LOG_APP, "No support macro capability.");
       }
       return isMacroSupported;
   }
   ```

4. Call [OH_CaptureSession_EnableMacro()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_enablemacro) to enable or disable macro photography.

   <!-- @[enable_macro](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   void NDKCamera::EnableMacro(bool isMacro)
   {
       OH_LOG_INFO(LOG_APP, "EnableMacro: isMacro is %{public}d", isMacro);
       if (IsMacroSupported(captureSession_)) {
           Camera_ErrorCode ret = OH_CaptureSession_EnableMacro(captureSession_, isMacro);
           if (ret != CAMERA_OK) {
               OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_EnableMacro failed.");
           }
       }
   }
   ```

## Status Listening

Starting from API version 20, you can listen for macro photography status changes.

Call [OH_CaptureSession_RegisterMacroStatusChangeCallback()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_registermacrostatuschangecallback) to register a callback for listening.

<!-- @[macro_status_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

``` C++
void MacroStatusCallback(Camera_CaptureSession *captureSession, bool isMacroDetected)
{
    OH_LOG_INFO(LOG_APP, "MacroStatusCallback isMacro: %{public}d", isMacroDetected);
}
        
// Register the callback function.
Camera_ErrorCode NDKCamera::RegisterMacroStatusCallback()
{
    Camera_ErrorCode ret = OH_CaptureSession_RegisterMacroStatusChangeCallback(captureSession_, MacroStatusCallback);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RegisterMacroStatusChangeCallback failed.");
    }
    return ret;
}

// Unregister.
Camera_ErrorCode NDKCamera::UnregisterMacroStatusCallback()
{
    Camera_ErrorCode ret = OH_CaptureSession_UnregisterMacroStatusChangeCallback(captureSession_, MacroStatusCallback);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_UnregisterMacroStatusChangeCallback failed.");
    }
    return ret;
}
```