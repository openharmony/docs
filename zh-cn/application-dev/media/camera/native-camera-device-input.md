# 设备输入(C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

在开发相机应用时，需要先[申请相关权限](camera-preparation.md)。

相机应用通过调用和控制相机设备，完成预览、拍照和录像等基础操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口。选择系统提供的NDK接口能力，导入NDK接口的方法如下。

   ```c++
   // 导入NDK接口头文件。
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   ```

2. 在CMake脚本中链接相关动态库。

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. 通过[OH_CameraManager_CreateCameraInput()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createcamerainput)方法，获取cameraInput对象。
   ```c++
   // 监听cameraInput错误信息。
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
   // 监听cameraStatus信息。
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
       // 创建CameraManager对象。
       Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
       if (cameraManager == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
           return;
       }
       // 监听相机状态变化。
       ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
       }
       // 获取相机列表。
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size == 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
            return;
        }
       // 创建相机输入流。
       ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
       if (cameraInput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
           return;
       }
       ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
       }
       // 打开相机。
       ret = OH_CameraInput_Open(cameraInput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraInput_open failed.");
           return;
       }
   }
   ```

   > **说明：**
   >
   > 在相机设备输入之前需要先完成相机管理，详细开发步骤请参考[相机管理](native-camera-device-management.md)。

4. 通过[OH_CameraManager_GetSupportedSceneModes()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedscenemodes)方法，获取当前相机设备支持的模式列表，列表中存储了相机设备支持的所有模式[Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode)。

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
           OH_LOG_INFO(LOG_APP, "scene mode = %{public}u ", sceneModes[index]);    // 获取相机指定模式。
           if (sceneModes[index] == sceneMode) {
               return true;
           }
       }
       return false;
   }
   ```

5. 通过[OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode)方法，获取当前设备支持的所有输出流，如预览流、拍照流等。输出流在CameraOutputCapability中的各个profile字段中。根据相机设备指定模式[Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode)的不同，需要添加不同类型的输出流。


   ```c++
   Camera_OutputCapability* GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_Device &camera)
   {
       Camera_OutputCapability* cameraOutputCapability = nullptr;
       // 示例代码以NORMAL_PHOTO模式为例，查询NORMAL_PHOTO在camera中是否支持。
       bool isSupported = IsSupportedSceneMode(camera, Camera_SceneMode::NORMAL_PHOTO);
       if (!isSupported) {
           OH_LOG_ERROR(LOG_APP, "NORMAL_PHOTO is not supported.");
           return cameraOutputCapability;
       }
       // 获取相机设备支持的输出流能力。
       const Camera_Profile* previewProfile = nullptr;
       const Camera_Profile* photoProfile = nullptr;
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(cameraManager, &camera,
           Camera_SceneMode::NORMAL_PHOTO, &cameraOutputCapability);
       if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
           return cameraOutputCapability;
       }
       // 以NORMAL_PHOTO模式为例，需要添加预览流、拍照流。
       if (cameraOutputCapability->previewProfiles == nullptr) {
           OH_LOG_ERROR(LOG_APP, "previewProfiles == null");
       } else {
           // 根据所需从cameraOutputCapability->previewProfiles中选择合适的预览分辨率。
           previewProfile = cameraOutputCapability->previewProfiles[0];
       }
       if (cameraOutputCapability->photoProfiles == nullptr) {
           OH_LOG_ERROR(LOG_APP, "photoProfiles == null");
       } else {
           // 根据所需从cameraOutputCapability->photoProfiles中选择合适的拍照分辨率。
           photoProfile = cameraOutputCapability->photoProfiles[0];
       }
       return cameraOutputCapability;
   }
   ```