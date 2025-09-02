# 相机管理 (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

在开发一个相机应用前，需要先通过调用相机接口来创建一个独立的相机设备。

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

3. 通过[OH_Camera_GetCameraManager()](../../reference/apis-camera-kit/capi-camera-h.md#oh_camera_getcameramanager)方法，获取cameraManager对象。

   ```c++
   Camera_ErrorCode CreateCameraManager(Camera_Manager** cameraManager)
   {
       // 创建CameraManager对象。
       Camera_ErrorCode ret = OH_Camera_GetCameraManager(cameraManager);
       if (cameraManager == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
       }
       return ret;
   }
   ```

   > **说明：**
   >
   > 如果获取对象失败，说明相机可能被占用或无法使用。如果被占用，须等到相机被释放后才能重新获取。

4. 通过[OH_CameraManager_GetSupportedCameras()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameras)方法，获取当前设备支持的相机列表，列表中存储了设备支持的所有相机ID。若列表不为空，则说明列表中的每个ID都支持独立创建相机对象；否则，说明当前设备无可用相机，不可继续后续操作。
     
   ```c++
   Camera_ErrorCode GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t &size)
   {
       // 获取相机列表。
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameras(cameraManager, cameras, &size);
       if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
       }
       for (int index = 0; index < size; index++) {
          OH_LOG_INFO(LOG_APP, "cameraId  =  %{public}s ", (*cameras)[index].cameraId);              // 获取相机ID。
          OH_LOG_INFO(LOG_APP, "cameraPosition  =  %{public}d ", (*cameras)[index].cameraPosition);  // 获取相机位置。
          OH_LOG_INFO(LOG_APP, "cameraType  =  %{public}d ", (*cameras)[index].cameraType);          // 获取相机类型。
          OH_LOG_INFO(LOG_APP, "connectionType  =  %{public}d ", (*cameras)[index].connectionType);  // 获取相机连接类型。
       }
       return ret;
   }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听相机状态，包括新相机的出现、相机的移除、相机的可用状态。在回调函数中，通过相机ID、相机状态这两个参数进行监听，如当有新相机出现时，可以将新相机加入到应用的备用相机中。

  通过注册cameraStatus事件，通过回调返回监听结果，callback返回Camera_StatusInfo参数，参数的具体内容可参考相机管理器回调接口实例[Camera_StatusInfo](../../reference/apis-camera-kit/capi-oh-camera-camera-statusinfo.md)。
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