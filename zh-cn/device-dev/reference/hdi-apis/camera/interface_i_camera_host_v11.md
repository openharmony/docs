# ICameraHost


## 概述

定义Camera设备功能操作。

打开和预启动Camera设备的相关操作。

**起始版本：** 4.0

**相关模块：**[Camera](_camera_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenCamera_V1_1](#opencamera_v1_1) ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] [ICameraDevice](interface_i_camera_device_v11.md) device) | 打开Camera设备。 | 
| [Prelaunch](#prelaunch) ([in] struct [PrelaunchConfig](_prelaunch_config_v11.md) config) | 预启动Camera设备。 | 


## 成员函数说明


### OpenCamera_V1_1()

```
ICameraHost::OpenCamera_V1_1 ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] ICameraDevice device )
```

**描述**

打开Camera设备。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice对象，通过ICameraDevice对象可以操作具体的Camera设备。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过[GetCameraIds](interface_i_camera_host_v10.md#getcameraids)接口获取当前已有Camera设备列表。 | 
| callbackObj | Camera设备相关的回调函数，具体参见[ICameraDeviceCallback](interface_i_camera_device_callback_v10.md)。 | 
| device | 返回当前要打开的Camera设备ID对应的ICameraDevice对象。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

GetCameraIds


### Prelaunch()

```
ICameraHost::Prelaunch ([in] struct PrelaunchConfig config)
```

**描述**

预启动Camera设备。

当需要加速cameraId指定Camera设备的启动时可调用该接口。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 表示预启动配置信息，当前可忽略。更多细节查看[PrelaunchConfig](_prelaunch_config_v11.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
