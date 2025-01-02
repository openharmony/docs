# IDCameraProvider


## 概述

定义Distributed Camera设备基本的操作。

启用分布式相机设备、设置流处理、更新控制参数、执行metadata等相关操作。

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [EnableDCameraDevice](#enabledcameradevice) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] String abilityInfo,[in] [IDCameraProviderCallback](interface_i_d_camera_provider_callback.md) callbackObj) | 启用分布式相机并设置回调。有关回调的详细信息可查看[IDCameraProviderCallback](interface_i_d_camera_provider_callback.md)。  | 
| [DisableDCameraDevice](#disabledcameradevice) ([in] struct [DHBase](_d_h_base.md) dhBase) | 禁用分布式相机。  | 
| [AcquireBuffer](#acquirebuffer) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] int streamId,[out] struct [DCameraBuffer](_d_camera_buffer.md) buffer) | 获取帧缓冲区。  | 
| [ShutterBuffer](#shutterbuffer) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] int streamId,[in] struct [DCameraBuffer](_d_camera_buffer.md) buffer) | 当帧缓冲区已满时，通知分布式相机HDF服务。  | 
| [OnSettingsResult](#onsettingsresult) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] struct [DCameraSettings](_d_camera_settings.md) result) | 上报分布式相机设备相关的数据。  | 
| [Notify](#notify) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] struct [DCameraHDFEvent](_d_camera_h_d_f_event.md) event) | Source SA与分布式相机驱动的事件通知接口。  | 


## 成员函数说明


### AcquireBuffer()

```
IDCameraProvider::AcquireBuffer ([in] struct DHBase dhBase, [in] int streamId, [out] struct DCameraBuffer buffer )
```
**描述**

获取帧缓冲区。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| streamId | 用于标识要获取的流。  | 
| buffer | 帧缓冲区。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### DisableDCameraDevice()

```
IDCameraProvider::DisableDCameraDevice ([in] struct DHBase dhBase)
```
**描述**

禁用分布式相机。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### EnableDCameraDevice()

```
IDCameraProvider::EnableDCameraDevice ([in] struct DHBase dhBase, [in] String abilityInfo, [in] IDCameraProviderCallback callbackObj )
```
**描述**

启用分布式相机并设置回调。有关回调的详细信息可查看[IDCameraProviderCallback](interface_i_d_camera_provider_callback.md)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| abilityInfo | 分布式相机静态能力信息。  | 
| callbackObj | 要设置的回调。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### Notify()

```
IDCameraProvider::Notify ([in] struct DHBase dhBase, [in] struct DCameraHDFEvent event )
```
**描述**

Source SA与分布式相机驱动的事件通知接口。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| event | 详细事件内容。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### OnSettingsResult()

```
IDCameraProvider::OnSettingsResult ([in] struct DHBase dhBase, [in] struct DCameraSettings result )
```
**描述**

上报分布式相机设备相关的数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| result | 上报的数据。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### ShutterBuffer()

```
IDCameraProvider::ShutterBuffer ([in] struct DHBase dhBase, [in] int streamId, [in] struct DCameraBuffer buffer )
```
**描述**

当帧缓冲区已满时，通知分布式相机HDF服务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| streamId | 帧缓冲区要增加的流的ID。  | 
| buffer | 输出帧缓冲区。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。
