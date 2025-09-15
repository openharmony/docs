# 压力管控(C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

从API version 20开始，相机框架提供对系统压力等级的监听。

在长时间使用相机的场景（如直播业务）中，相机应用可以通过监听系统压力等级变化，动态调整画质（如帧率、分辨率等），平衡功耗、发热和系统负载，保证功能长时间可用。

## 状态监听

可以通过注册[OH_CaptureSession_OnSystemPressureLevelChange](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_onsystempressurelevelchange)的回调函数获取系统压力的监听结果。

当系统压力发生变化时，callback返回Camera_SystemPressureLevel参数。

参数的具体内容可参考相机管理器回调接口实例[Camera_SystemPressureLevel](../../reference/apis-camera-kit/capi-camera-h.md#camera_systempressurelevel)。

   ```c++
   void SystemPressureLevelChangeCallback(Camera_CaptureSession* captureSession, Camera_SystemPressureLevel systemPressureLevel)
   {
      OH_LOG_INFO(LOG_APP, "SystemPressureLevelChangeCallback is called.");
   }

   Camera_ErrorCode RegisterSystemPressureCallback(Camera_CaptureSession* captureSession)
   {
       Camera_ErrorCode ret = OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(captureSession,
          SystemPressureLevelChangeCallback);
       if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RegisterSystemPressureLevelChangeCallback failed.");
       }
       return ret;
   }
   ```