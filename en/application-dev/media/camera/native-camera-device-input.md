# Device Input Management (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Before developing a camera application, you must [request required permissions](camera-preparation.md).

A camera application invokes and controls a camera device to perform basic operations such as preview, photo capture, and video recording.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

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

3. Call [OH_CameraManager_CreateCameraInput()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createcamerainput) to obtain a cameraInput object.
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
   ```c++
   // Listen for camera status information.
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
   ```c++
   void CreateAndOpenCamera()
   {
       Camera_Manager* cameraManager = nullptr;
       Camera_Input* cameraInput = nullptr;
       Camera_Device* cameras = nullptr;
       uint32_t size = 0;
       uint32_t cameraDeviceIndex = 0;
       // Create a CameraManager object.
       Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
       if (cameraManager == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
           return;
       }
       // Listen for camera status changes.
       ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
       }
       // Obtain the camera list.
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size == 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
            return;
        }
       // Create a camera input stream.
       ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
       if (cameraInput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
           return;
       }
       ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
       }
       // Open a camera.
       ret = OH_CameraInput_Open(cameraInput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraInput_open failed.");
           return;
       }
   }
   ```

   > **NOTE**
   >
   > Before any camera device input, you must complete camera management by following the instructions provided in [Camera Device Management](native-camera-device-management.md).

4. Call [OH_CameraManager_GetSupportedSceneModes()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedscenemodes) to obtain the list of scene modes supported by the current camera device. The list stores all the [Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode) supported by the camera device.

   ```c++
   bool IsSupportedSceneMode(Camera_Device camera, Camera_SceneMode sceneMode)
   {
       Camera_SceneMode* sceneModes = nullptr;
       uint32_t sceneModeSize = 0;
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedSceneModes(&camera, &sceneModes, &sceneModeSize);
       if (sceneModes == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedSceneModes failed.");
           return false;
       }
       for (uint32_t index = 0; index < sceneModeSize; index++) {
           OH_LOG_INFO(LOG_APP, "scene mode = %{public}u ", sceneModes[index]);    // Obtain the specified scene mode.
           if (sceneModes[index] == sceneMode) {
               return true;
           }
       }
       return false;
   }
   ```

5. Call [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) to obtain all output streams supported by the current device, such as preview streams and photo streams. The output streams supported are the value of each **profile** field under **CameraOutputCapability**. Different types of output streams must be added based on the value of [Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode) specified by the camera device.

   ```c++
   Camera_OutputCapability* GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_Device &camera)
   {
       Camera_OutputCapability* cameraOutputCapability = nullptr;
       // The following sample code checks whether the NORMAL_PHOTO mode is supported by the camera.
       bool isSupported = IsSupportedSceneMode(camera, Camera_SceneMode::NORMAL_PHOTO);
       if (!isSupported) {
           OH_LOG_ERROR(LOG_APP, "NORMAL_PHOTO is not supported.");
           return cameraOutputCapability;
       }
       // Obtain the output stream capability supported by the camera.
       const Camera_Profile* previewProfile = nullptr;
       const Camera_Profile* photoProfile = nullptr;
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(cameraManager, &camera,
           Camera_SceneMode::NORMAL_PHOTO, &cameraOutputCapability);
       if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
           return cameraOutputCapability;
       }
       // The following uses the NORMAL_PHOTO mode as an example. You need to add the preview stream and photo stream.
       if (cameraOutputCapability->previewProfiles == nullptr) {
           OH_LOG_ERROR(LOG_APP, "previewProfiles == null");
       } else {
           // Select an appropriate preview resolution from previewProfiles of cameraOutputCapability.
           previewProfile = cameraOutputCapability->previewProfiles[0];
       }
       if (cameraOutputCapability->photoProfiles == nullptr) {
           OH_LOG_ERROR(LOG_APP, "photoProfiles == null");
       } else {
           // Select an appropriate photo resolution from photoProfiles of cameraOutputCapability.
           photoProfile = cameraOutputCapability->photoProfiles[0];
       }
       return cameraOutputCapability;
   }
   ```