# ICameraHost


## 概述

定义Camera设备功能操作。

打开并执行Camera设备、通知设备状态更改信息、设置回调接口等相关操作。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenCamera_V1_3](#opencamera_v1_3) ([in] String cameraId, [in] ICameraDeviceCallback callbackObj,<br/>[out] [ICameraDevice](interface_i_camera_device_v13.md) device) | 打开Camera设备。 | 
| [OpenSecureCamera](#opensecurecamera) ([in] String cameraId, [in] ICameraDeviceCallback callbackObj,<br/>[out] [ICameraDevice](interface_i_camera_device_v13.md) device) | 使用安全模式打开相机。 | 
| [GetResourceCost](#getresourcecost) ([in] String cameraId, [out] [CameraDeviceResourceCost](_camera_device_resource_cost_v13.md) resourceCost) | 通过cameraHost获取在相机设备上打开相机的资源成本。 | 


## 成员函数说明


### GetResourceCost()

```
ICameraHost::GetResourceCost ([in] String cameraId, [out] CameraDeviceResourceCost resourceCost)
```

**描述**

通过cameraHost获取在相机设备上打开相机的资源成本。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过**[CamRetCode](_camera_v10.md#camretcode)**接口获取当前已有Camera设备列表。 | 
| resourceCost | 需要打开Camera设备的开销。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OpenCamera_V1_3()

```
ICameraHost::OpenCamera_V1_3 ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] ICameraDevice device)
```

**描述**

打开Camera设备。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice对象，通过ICameraDevice对象可以操作具体的Camera设备。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过**[GetCameraIds()](interface_i_camera_host_v10.md#getcameraids)**接口获取当前已有Camera设备列表。 | 
| callbackObj | Camera设备相关的回调函数，具体参见**[ICameraDeviceCallback](interface_i_camera_device_callback_v10.md)**。 | 
| device | 返回当前要打开的Camera设备ID对应的ICameraDevice对象。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OpenSecureCamera()

```
ICameraHost::OpenSecureCamera ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] ICameraDevice device)
```

**描述**

使用安全模式打开相机。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice实例，并通过ICameraDevice操作映射到实例的特定相机设备。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过**[GetCameraIds()](interface_i_camera_host_v10.md#getcameraids)**接口获取当前已有Camera设备列表。 | 
| callbackObj | Camera设备相关的回调函数，具体参见**[ICameraDeviceCallback](interface_i_camera_device_callback_v10.md)**。 | 
| device | 返回当前要打开的Camera设备ID对应的ICameraDevice对象。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
