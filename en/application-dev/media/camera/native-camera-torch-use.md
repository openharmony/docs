# Using the Flashlight (C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

To use the flashlight mode, you manipulate your phone to turn on the flashlight, which then stays on persistently.

When you use the flashlight mode with a camera application, the following situations may occur:

- When the rear camera is used and [Camera_FlashMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_flashmode) is set to **off**, the flashlight cannot be turned on.
- When the front camera is used, the flashlight can be turned on and remains steady on.
- When you switch from the front camera to the rear camera, the flashlight will be automatically turned off if it was turned on previously.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK.  

   ```c++
   // Include the NDK header files.
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
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

3. Call [OH_CameraManager_IsTorchSupported()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_istorchsupported) to check whether the current device supports the flashlight.

   ```c++
   bool IsTorchSupported(Camera_Manager* cameraManager)
   {
       // Check whether the device supports the flashlight.
       bool isTorchSupported = false;
       if (cameraManager == nullptr) {
           OH_LOG_ERROR(LOG_APP, "cameraManager is nullptr.");
           return isTorchSupported;
       }
       Camera_ErrorCode ret = OH_CameraManager_IsTorchSupported(cameraManager, &isTorchSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_IsTorchSupported failed.");
       }
       if (isTorchSupported) {
           OH_LOG_INFO(LOG_APP, "isTorchSupported success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "isTorchSupported failed.");
       }
       return isTorchSupported;
   }

   ```

4. Call [OH_CameraManager_IsTorchSupportedByTorchMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_istorchsupportedbytorchmode) to check whether the current device supports a specific flashlight mode.

   ```c++
   bool IsTorchSupportedByTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)
   {
       bool torchModeSupported = false;
       Camera_ErrorCode ret = OH_CameraManager_IsTorchSupportedByTorchMode(cameraManager, torchMode, &torchModeSupported);
       if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_IsTorchSupported failed.");
       }
       if (torchModeSupported) {
            OH_LOG_INFO(LOG_APP, "isTorchModeSupported success.");
       } else {
            OH_LOG_ERROR(LOG_APP, "isTorchModeSupported failed. %{public}d ", ret);
       }
       return torchModeSupported;
   }

   ```

5. Call [OH_CameraManager_SetTorchMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_settorchmode) to set the flashlight mode.

   ```c++
   Camera_ErrorCode SetTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)
   {
       // Set the flashlight mode when the specified mode is supported.
       Camera_ErrorCode ret = OH_CameraManager_SetTorchMode(cameraManager, torchMode);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_SetTorchMode failed. %{public}d ", ret);
       } else {
           OH_LOG_INFO(LOG_APP, "OH_CameraManager_SetTorchMode success.");
       }
       return ret;
   }
   ```


## Status Listening

During camera application development, you can listen for changes of the flashlight status, including on, off, unavailable, and available, by using the callback function.

Register the **torchStatus** event and return the listening result through a callback, which carries the **Camera_TorchStatusInfo** parameter. For details about the parameter, see [Camera_TorchStatusInfo](../../reference/apis-camera-kit/capi-oh-camera-camera-torchstatusinfo.md).

   ```c++
   void TorchStatusCallback(Camera_Manager *cameraManager, Camera_TorchStatusInfo* torchStatus)
   {
      OH_LOG_INFO(LOG_APP, "TorchStatusCallback is called.");
   }
   Camera_ErrorCode RegisterTorchStatusCallback(Camera_Manager *cameraManager)
   {
       Camera_ErrorCode ret = OH_CameraManager_RegisterTorchStatusCallback(cameraManager, TorchStatusCallback);
       if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterTorchStatusCallback failed.");
       }
       return ret;
   }
   ```
