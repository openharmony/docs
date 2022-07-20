# OHOS::Camera::ICameraHostCallback


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.HostCallback") | IPC通信token校验。 | 
| [OnCameraStatus](_camera.md#oncamerastatus)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[CameraStatus](_camera.md#camerastatus)&nbsp;status)=0 | 用于Camera设备状态变化时上报状态信息给调用者。&nbsp;[更多...](_camera.md#oncamerastatus) | 
| [OnFlashlightStatus](_camera.md#onflashlightstatus)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[FlashlightStatus](_camera.md#flashlightstatus)&nbsp;status)=0 | 用于在闪光灯状态变化时上报状态信息给调用者。&nbsp;[更多...](_camera.md#onflashlightstatus) | 
| [OnCameraEvent](_camera.md#oncameraevent)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[CameraEvent](_camera.md#cameraevent)&nbsp;event)=0 | 在相机事件发生时调用。&nbsp;[更多...](_camera.md#oncameraevent) | 


## **详细描述**

Camera服务的管理回调。
