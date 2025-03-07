# ICameraHost


## 概述

定义Camera设备功能操作。

打开并执行Camera设备、通知设备状态更改信息、设置回调接口等相关操作。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenCameraV1_2](#opencamerav1_2) ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] [ICameraDevice](interface_i_camera_device_v12.md) device) | 打开Camera设备。 | 
| [NotifyDeviceStateChangeInfo](#notifydevicestatechangeinfo) ([in] int notifyType, [in] int deviceState) | 将设备状态更改通知设备供应商。 | 
| [SetCallbackV1_2](#setcallbackv1_2) ([in] [ICameraHostCallback](interface_i_camera_host_callback_v12.md) callbackObj) | 设置ICameraHost回调接口，回调函数参考[ICameraHostCallback](interface_i_camera_host_callback_v12.md)。 | 
| [SetFlashlightV1_2](#setflashlightv1_2) ([in] float level) | 打开或关闭闪光灯。 | 
| [PreCameraSwitch](#precameraswitch) ([in] String cameraId) | 切换镜头时预热相机设备。 | 
| [PrelaunchWithOpMode](#prelaunchwithopmode) ([in] struct PrelaunchConfig config, [in] int operationMode) | 预启动Camera设备。 | 


## 成员函数说明


### NotifyDeviceStateChangeInfo()

```
ICameraHost::NotifyDeviceStateChangeInfo ([in] int notifyType, [in] int deviceState)
```

**描述**

将设备状态更改通知设备供应商。

通过调用此函数，可以通知设备供应商设备状态更改。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| notifyType | 通知的类型。 | 
| deviceState | 设备的状态。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### OpenCameraV1_2()

```
ICameraHost::OpenCameraV1_2 ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] ICameraDevice device)
```

**描述**

打开Camera设备。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice对象，通过ICameraDevice对象可以操作具体的Camera设备。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过[GetCameraIds](interface_i_camera_host_v10.md#getcameraids)接口获取当前已有Camera设备列表。 | 
| callbackObj | Camera设备相关的回调函数，具体参见[ICameraDeviceCallback](interface_i_camera_device_callback_v10.md)。 | 
| device | 返回当前要打开的Camera设备ID对应的ICameraDevice对象。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### PreCameraSwitch()

```
ICameraHost::PreCameraSwitch ([in] String cameraId)
```

**描述**

切换镜头时预热相机设备。

当用户触摸摄像头应用镜头开关图标时可以调用此功能以加速启动的相机设备，由cameraId指定。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 指示相机设备的ID，可以通过调用 [GetCameraIds](interface_i_camera_host_v10.md#getcameraids)获取。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### PrelaunchWithOpMode()

```
ICameraHost::PrelaunchWithOpMode ([in] struct PrelaunchConfig config, [in] int operationMode)
```

**描述**

预启动Camera设备。

当用户触摸摄像头应用图标时可以调用此函数以加速启动的相机设备，由cameraId指定。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 预启动配置. 详细可查看[PrelaunchConfig](_prelaunch_config_v11.md)。 | 
| operationMode | 流操作模式. 详细可查看[OperationMode_V1_2](_camera_v12.md#operationmode_v1_2)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### SetCallbackV1_2()

```
ICameraHost::SetCallbackV1_2 ([in] ICameraHostCallback callbackObj)
```

**描述**

设置ICameraHost回调接口，回调函数参考[ICameraHostCallback](interface_i_camera_host_callback_v12.md)。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要设置的回调函数。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### SetFlashlightV1_2()

```
ICameraHost::SetFlashlightV1_2 ([in] float level)
```

**描述**

打开或关闭闪光灯。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 指定是打开还是关闭闪光灯。值 1 表示打开闪光灯，0 表示相反。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。
