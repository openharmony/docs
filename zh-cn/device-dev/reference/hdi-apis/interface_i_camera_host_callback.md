# ICameraHostCallback


## **概述**

定义Camera设备功能回调操作。

设置回调接口、返回设备状态编号、闪光灯状态以及相应的事件ID。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnCameraStatus](#oncamerastatus)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[in]&nbsp;enum&nbsp;[CameraStatus](camera.md#camerastatus)&nbsp;status) | 用于Camera设备状态变化时上报状态信息给调用者。 | 
| [OnFlashlightStatus](#onflashlightstatus)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[in]&nbsp;enum&nbsp;[FlashlightStatus](camera.md#flashlightstatus)&nbsp;status) | 用于在闪光灯状态变化时上报状态信息给调用者。 | 
| [OnCameraEvent](#oncameraevent)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[in]&nbsp;enum&nbsp;[CameraEvent](camera.md#cameraevent)&nbsp;event) | 在相机事件发生时调用。 | 


## **成员函数说明**


### OnCameraEvent()

  
```
ICameraHostCallback::OnCameraEvent ([in] String cameraId, [in] enum CameraEvent event )
```

**描述：**

在相机事件发生时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 表示相机事件绑定的相机ID。 | 
| event | 表示相机事件类型。事件类型查看[CameraEvent](camera.md#cameraevent)。 | 


### OnCameraStatus()

  
```
ICameraHostCallback::OnCameraStatus ([in] String cameraId, [in] enum CameraStatus status )
```

**描述：**

用于Camera设备状态变化时上报状态信息给调用者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 状态发生变化的Camera设备ID。 | 
| status | 最新的设备状态。 | 


### OnFlashlightStatus()

  
```
ICameraHostCallback::OnFlashlightStatus ([in] String cameraId, [in] enum FlashlightStatus status )
```

**描述：**

用于在闪光灯状态变化时上报状态信息给调用者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 状态发生变化的闪关灯所绑定的Camera设备ID。 | 
| status | 最新的闪光灯状态。状态值查看[CameraStatus](camera.md#camerastatus)。 | 
