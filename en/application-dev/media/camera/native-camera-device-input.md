# Device Input Management (C/C++)

Before developing a camera application, request the camera permission. For details, see [Camera Development Preparations](camera-preparation.md).

A camera application invokes and controls a camera device to perform basic operations such as preview, photo capture, and video recording.

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

3. Call [OH_CameraManager_CreateCameraInput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_createcamerainput) to obtain a **cameraInput** object.

   ```c++
   Camera_Manager *cameraManager = nullptr;
   Camera_Input* cameraInput = nullptr;
   Camera_Device* cameras = nullptr;
   Camera_OutputCapability* cameraOutputCapability = nullptr;
   const Camera_Profile* previewProfile = nullptr;
   const Camera_Profile* photoProfile = nullptr;
   uint32_t size = 0;
   uint32_t cameraDeviceIndex = 0;
   // Create a CameraManager object.
   Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
   if (cameraManager == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraMananger failed.");
   }
   // Listen for camera status changes.
   ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
   if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
   }
   // Obtain the camera list.
    ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
    if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
    }
   // Create a camera input stream.
   ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
   if (cameraInput == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
   }
   ret == OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
   if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
   }
   // Open the camera.
   ret = OH_CameraInput_Open(cameraInput);
   if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraInput_open failed.");
   }
   ```
   ```c++
   // Listen for camera input errors.
   void OnCameraInputError(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
   {
      OH_LOG_INFO(LOG_APP, "OnCameraInput errorCode: %{public}d", errorCode);
   }

   CameraInput_Callbacks* GetCameraInputListener(void)
   {
      static CameraInput_Callbacks cameraInputCallbacks = {
         .onError = OnCameraInputError
      };
      return &cameraInputCallbacks;
   }
   ```

   > **NOTE**
   >
   > Before any camera device input, you must complete camera management by following the instructions provided in [Camera Device Management](native-camera-device-management.md).

4. Call [OH_CameraManager_GetSupportedSceneModes()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_getsupportedscenemodes) to obtain the list of scene modes supported by the current camera device. The list stores all the [Camera_SceneModes](../../reference/apis-camera-kit/_o_h___camera.md#camera_scenemode) supported by the camera device.

   ```c++
   Camera_SceneMode* sceneModes = nullptr;
   uint32_t length = 0;
   uint32_t sceneModeIndex = 0;
   ret = OH_CameraManager_GetSupportedSceneModes(&cameras[cameraDeviceIndex], &sceneModes, &length);
   if (sceneModes == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedSceneModes failed.");
   }
   for (int index = 0; index < length; index++) {
      OH_LOG_INFO(LOG_APP, "scene mode = %{public}s ", sceneModes[index]);    // Obtain the specified scene mode.
   }
   ```

5. Call [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) to obtain all output streams supported by the current device, such as preview streams and photo streams. The output streams supported are the value of each **profile** field under **CameraOutputCapability**. Different types of output streams must be added based on the value of [Camera_SceneMode](../../reference/apis-camera-kit/_o_h___camera.md#camera_scenemode) specified by the camera device.

   ```c++
   // Obtain the output streams supported by the camera device.
   Camera_OutputCapability* cameraOutputCapability = nullptr;
   const Camera_Profile* previewProfile = nullptr;
   const Camera_Profile* photoProfile = nullptr;
   ret = OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(cameraManager, &cameras[cameraDeviceIndex], sceneModes[sceneModeIndex]
                                                                     &cameraOutputCapability);
   if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
   OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
   }
   // The following uses the NORMAL_PHOTO mode as an example. You need to add the preview stream and photo stream.
   if (cameraOutputCapability->previewProfilesSize < 0) {
   OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
   }
   previewProfile = cameraOutputCapability->previewProfiles[0];
   
   if (cameraOutputCapability->photoProfilesSize < 0) {
   OH_LOG_ERROR(LOG_APP, "photoProfilesSize == null");
   }
   photoProfile = cameraOutputCapability->photoProfiles[0];
   ```