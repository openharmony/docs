# 手电筒使用(C++)

手电筒模式的使用是通过手机启用手电筒功能，使设备的手电筒功能持续保持常亮状态。

在使用相机应用并操作手电筒功能时，存在以下几种情况说明：
- 当使用后置摄像头并设置闪光灯模式[Camera_FlashMode](../../reference/apis-camera-kit/_o_h___camera.md#camera_flashmode)关闭时，手电筒功能无法启用。
- 当使用前置摄像头时，手电筒可以正常启用并保持常亮状态。
- 从前置摄像头切换至后置摄像头时，如果手电筒原本处于开启状态，它将会被自动关闭。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口。选择系统提供的NDK接口能力，导入NDK接口的方法如下。

   ```c++
    // 导入NDK接口头文件
    #include "hilog/log.h"
    #include "ohcamera/camera.h"
    #include "ohcamera/camera_input.h"
    #include "ohcamera/capture_session.h"
    #include "ohcamera/camera_manager.h"
   ```

2. 在CMake脚本中链接相关动态库。

    ```txt
     target_link_libraies(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
    ```

3. 通过[OH_CameraManager_IsTorchSupported()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_istorchsupported)方法，检测当前设备是否支持手电筒。

    ```c++
   // 判断设备是否支持手电筒模式
   Camera_OutputCapability* cameraOutputCapability = nullptr;
   Camera_TorchMode torchMode = AUTO;
   bool isTorchSupported = false;
   Camera_ErrorCode ret = OH_CameraManager_IsTorchSupported(cameraManager, &isTorchSupported);
   if (cameraManager == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_IsTorchSupported failed.");
   }
   if (isTorchSupported) {
        OH_LOG_INFO(LOG_APP, "isTorchSupported success.");
   } else {
        OH_LOG_ERROR(LOG_APP, "isTorchSupported failed.");
   }
   ```

4. 通过[OH_CameraManager_IsTorchSupportedByTorchMode()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_istorchsupportedbytorchmode)方法，检测当前设备是否支持设置的手电筒模式。

   ```c++
   bool torchModeSupported = false;
   ret = OH_CameraManager_IsTorchSupportedByTorchMode(cameraManager, torchMode, &torchModeSupported);
   if (cameraManager == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_IsTorchSupported failed.");
   }
   if (torchModeSupported) {
        OH_LOG_INFO(LOG_APP, "isTorchModeSupported success.");
   } else {
        OH_LOG_ERROR(LOG_APP, "isTorchModeSupported failed. %{public}d ", ret);
   }
   ```

5. 通过[OH_CameraManager_SetTorchMode()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_settorchmode)方法，设置当前设备的手电筒模式。

   ```c++
   if (torchModeSupported) {
      OH_LOG_INFO(LOG_APP, "OH_CameraManager_IsTorchModeSupported success.");
      // 设置手电筒模式
      ret = OH_CameraManager_SetTorchMode(cameraManager, torchMode);
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_SetTorchMode failed. %{public}d ", ret);
      } else {
          OH_LOG_INFO(LOG_APP, "OH_CameraManager_SetTorchMode success.");
        }
   } else {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_IsTorchModeSupported failed.");
   }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听手电筒状态，包括手电筒打开、手电筒关闭、手电筒不可用、手电筒恢复可用。手电筒状态发生变化，可通过回调函数获取手电筒模式的变化。

   通过注册cameratorchStatusChange事件，通过回调返回监听结果，callback返回Camera_TorchStatusInfo参数，参数的具体内容可参考相机管理器回调接口实例[Camera_TorchStatusInfo](../../reference/apis-camera-kit/_camera___torch_status_info.md)。

   ```c++
   ret = OH_CameraManager_RegisterTorchStatusCallback(cameraManager, GetTorchStatusCb);
   if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterTorchStatusCallback failed.");
   }
   ```
   ```c++
   void OnTorchStatusChange(Camera_Manager *cameraManager, Camera_TorchStatusInfo* torchStatus)
   {
      OH_LOG_INFO(LOG_APP, "OH_CameraManager_RegisterTorchStatusCallback is called.");
   }
   void GetTorchStatusCb(Camera_Manager *cameraManager, Camera_TorchStatusInfo* torchStatus)
   {
      OH_LOG_INFO(LOG_APP, "GetTorchStatusCb is called.");
   }
   ```