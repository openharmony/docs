# Camera Device Management (C/C++)

Before developing a camera application, you must call the camera APIs to create an independent camera device.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/_o_h___camera.md) for the API reference.

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
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. Call [OH_Camera_GetCameraManager()](../../reference/apis-camera-kit/_o_h___camera.md#oh_camera_getcameramanager) to obtain a **cameraManager** object.

   ```c++
   Camera_Manager *cameraManager = nullptr;
   Camera_Input* cameraInput = nullptr;
   Camera_Device* cameras = nullptr;
   uint32_t size = 0;
   uint32_t cameraDeviceIndex = 0;
   // Create a CameraManager object.
   Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
   if (cameraManager == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
   }
   ```

   > **NOTE**
   >
   > If obtaining the object fails, the camera device may be occupied or unusable. If it is occupied, wait until it is released.

4. Call [OH_CameraManager_GetSupportedCameras()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_getsupportedcameras) to obtain the list of cameras supported by the current device. The list stores the IDs of all cameras supported. If the list is not empty, each ID in the list can be used to create an independent camera object. If the list is empty, no camera is available for the current device and subsequent operations cannot be performed.

   ```c++
   // Obtain the camera list.
   ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
   if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
   }
   for (int index = 0; index < size; index++) {
      OH_LOG_INFO(LOG_APP, "cameraId  =  %{public}s ", cameras[index].cameraId);              // Obtain the camera ID.
      OH_LOG_INFO(LOG_APP, "cameraPosition  =  %{public}d ", cameras[index].cameraPosition);  // Obtain the camera position.
      OH_LOG_INFO(LOG_APP, "cameraType  =  %{public}d ", cameras[index].cameraType);          // Obtain the camera type.
      OH_LOG_INFO(LOG_APP, "connectionType  =  %{public}d ", cameras[index].connectionType);  // Obtain the camera connection type.
   }
   ```


## Status Listening

During camera application development, you can listen for the camera status, including the appearance of a new camera, removal of a camera, and availability of a camera. The camera ID and camera status are included in the callback function. When a new camera appears, the new camera can be added to the supported camera list.

Register the **'cameraStatus'** event and return the listening result through a callback, which carries the **Camera_StatusInfo** parameter. For details about the parameter, see [Camera_StatusInfo](../../reference/apis-camera-kit/_camera___status_info.md).

   ```c++
   ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
   if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
   }
   ```
   ```c++
   void CameraManagerStatusCallback(Camera_Manager* cameraManager, Camera_StatusInfo* status)
   {
      OH_LOG_INFO(LOG_APP, "CameraManagerStatusCallback is called");
   }
   CameraManager_Callbacks* GetCameraManagerListener()
   {
      static CameraManager_Callbacks cameraManagerListener = {
         .onCameraStatus = CameraManagerStatusCallback
      };
      return &cameraManagerListener;
   }
   ```
