# Camera Device Management (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=60bfe55852781ead648072fa4f23a766d98688af translatedAt=2026-08-10T09:20:23.256Z pushedAt=2026-08-10T13:20:27.575Z -->

Before developing a camera application, you must call the camera APIs to create an independent camera device.

## How to Develop

For detailed API descriptions, see [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK.  

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

3. Call [OH_Camera_GetCameraManager()](../../reference/apis-camera-kit/capi-camera-h.md#oh_camera_getcameramanager) to obtain a cameraManager object.

   ```c++
   Camera_ErrorCode CreateCameraManager(Camera_Manager** cameraManager)
   {
       // Create a CameraManager object.
       Camera_ErrorCode ret = OH_Camera_GetCameraManager(cameraManager);
       if (*cameraManager == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
       }
       return ret;
   }
   ```

   > **NOTE**
   >
   > If obtaining the object fails, the camera device may be occupied or unusable. If it is occupied, wait until it is released.

4. Call [OH_CameraManager_GetSupportedCameras()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameras) to obtain the list of cameras supported by the current device. The list stores all camera IDs supported by the device. If the list is not empty, each ID in the list can be used to independently create a camera object. Otherwise, no camera is available on the current device, and subsequent operations cannot be performed.

   ```c++
   Camera_ErrorCode GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t &size)
   {
       // Obtain the camera list.
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameras(cameraManager, cameras, &size);
       if (cameras == nullptr || size == 0 || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
       }
       // When cameras are no longer in use, call OH_CameraManager_DeleteSupportedCameras() to release the camera list and set the pointer to null to prevent memory leaks.
       for (uint32_t index = 0; index < size; index++) {
          OH_LOG_INFO(LOG_APP, "cameraId  =  %{public}s ", (*cameras)[index].cameraId);              // Obtain the camera ID.
          OH_LOG_INFO(LOG_APP, "cameraPosition  =  %{public}d ", (*cameras)[index].cameraPosition);  // Obtain the camera position.
          OH_LOG_INFO(LOG_APP, "cameraType  =  %{public}d ", (*cameras)[index].cameraType);          // Obtain the camera type.
          OH_LOG_INFO(LOG_APP, "connectionType  =  %{public}d ", (*cameras)[index].connectionType);  // Obtain the camera connection type.
       }
       return ret;
   }
   ```

## Status Listening

During camera application development, you can listen for the camera status, including the appearance of a new camera, removal of a camera, and availability of a camera. The camera ID and camera status are included in the callback function. When a new camera appears, the new camera can be added to the supported camera list.

Call [OH_CameraManager_RegisterCallback()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_registercallback) to register the **'cameraStatus'** event. The listening result is returned through a callback, which carries the **Camera_StatusInfo** parameter. For details about the parameter, see [Camera_StatusInfo](../../reference/apis-camera-kit/capi-oh-camera-camera-statusinfo.md).

  ```c++
  void CameraStatusCallback(Camera_Manager* cameraManager, Camera_StatusInfo* status)
  {
     OH_LOG_INFO(LOG_APP, "CameraStatusCallback is called");
  }
  CameraManager_Callbacks* GetCameraManagerListener()
  {
     static CameraManager_Callbacks cameraManagerListener = {
        .onCameraStatus = CameraStatusCallback
     };
     return &cameraManagerListener;
  }
  ```

  ```c++
  Camera_ErrorCode RegisterCameraStatusCallback(Camera_Manager &cameraManager)
  {
      Camera_ErrorCode ret = OH_CameraManager_RegisterCallback(&cameraManager, GetCameraManagerListener());
      if (ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
      }
      return ret;
  }
  ```