# 设备输入(C/C++)

在开发一个相机应用前，需要先创建一个独立的相机设备，应用通过调用和控制相机设备，完成预览、拍照和录像等基础操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口。选择系统提供的NDK接口能力，导入NDK接口的方法如下。

   ```c++
    // 导入NDK接口头文件
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
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. 通过OH_Camera_GetCameraManager()方法，获取cameraManager对象。

   ```c++
   Camera_Manager *cameraManager = nullptr;
   Camera_Input* cameraInput = nullptr;
   Camera_Device* cameras = nullptr;
   Camera_OutputCapability* cameraOutputCapability = nullptr;
   const Camera_Profile* previewProfile = nullptr;
   const Camera_Profile* photoProfile = nullptr;
   uint32_t size = 0;
   uint32_t cameraDeviceIndex = 0;
   // 创建CameraManager对象
   Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
   if (cameraManager == nullptr || ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
   }
   ```

   > **说明：**
   >
   > 如果获取对象失败，说明相机可能被占用或无法使用。如果被占用，须等到相机被释放后才能重新获取。

4. 通过OH_CameraManager_GetSupportedCameras()方法，获取当前设备支持的相机列表，列表中存储了设备支持的所有相机ID。若列表不为空，则说明列表中的每个ID都支持独立创建相机对象；否则，说明当前设备无可用相机，不可继续后续操作。
     
   ```c++
   // 获取相机列表
   ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
   if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
   }
   for (int index = 0; index < size; index++) {
      OH_LOG_ERROR(LOG_APP, "cameraId  =  %{public}s ", cameras[index].cameraId);              // 获取相机ID
      OH_LOG_ERROR(LOG_APP, "cameraPosition  =  %{public}d ", cameras[index].cameraPosition);  // 获取相机位置
      OH_LOG_ERROR(LOG_APP, "cameraType  =  %{public}d ", cameras[index].cameraType);          // 获取相机类型
      OH_LOG_ERROR(LOG_APP, "connectionType  =  %{public}d ", cameras[index].connectionType);  // 获取相机连接类型
   }
   ```

5. 通过OH_CameraManager_GetSupportedCameraOutputCapability()方法，获取当前设备支持的所有输出流，如预览流、拍照流等。输出流在CameraOutputCapability中的各个profile字段中。

   ```c++
   // 创建相机输入流
   ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
   if (cameraInput == nullptr || ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
   }
   ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
   if (ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
   }
   // 打开相机
   ret = OH_CameraInput_Open(cameraInput);
   if (ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Open failed.");
   }
   // 获取相机设备支持的输出流能力
   ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                  &cameraOutputCapability);
   if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
   }
   
   if (cameraOutputCapability->previewProfilesSize < 0) {
      OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
   }
   previewProfile = cameraOutputCapability->previewProfiles[0];

   if (cameraOutputCapability->photoProfilesSize < 0) {
      OH_LOG_ERROR(LOG_APP, "photoProfilesSize == null");
   }
   photoProfile = cameraOutputCapability->photoProfiles[0];
   ```
   ```c++
   // 监听cameraInput错误信息
   void OnCameraInputError(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
   {
      OH_LOG_INFO(LOG_APP, "OnCameraInput errorCode = %{public}d", errorCode);
   }

   CameraInput_Callbacks* GetCameraInputListener(void)
   {
      static CameraInput_Callbacks cameraInputCallbacks = {
         .onError = OnCameraInputError
      };
      return &cameraInputCallbacks;
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听相机状态，包括新相机的出现、相机的移除、相机的可用状态。在回调函数中，通过相机ID、相机状态这两个参数进行监听，如当有新相机出现时，可以将新相机加入到应用的备用相机中。

  通过注册cameraStatus事件，通过回调返回监听结果，callback返回Camera_StatusInfo参数，参数的具体内容可参考相机管理器回调接口实例[Camera_StatusInfo](../../reference/apis-camera-kit/_camera___status_info.md)。
  
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