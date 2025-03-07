# Distributed Camera


## 概述

Distributed Camera模块接口定义。

Distributed Camera模块包括对分布式相机设备的操作、流的操作和各种回调等，这部分接口与Camera一致。 通过IDCameraProvider与Source SA通信交互，实现分布式功能。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [DCameraTypes.idl](_d_camera_types_8idl.md) | Distributed Camera模块HDI接口使用的数据类型。 | 
| [IDCameraProvider.idl](_i_d_camera_provider_8idl.md) | 分布式相机SA服务和分布式相机HDF服务之间传输接口调用，并为上层提供硬件驱动接口。 | 
| [IDCameraProviderCallback.idl](_i_d_camera_provider_callback_8idl.md) | 声明分布式相机SA服务的回调。调用者需要实现回调。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DHBase](_d_h_base.md) | 分布式硬件设备基础信息。 | 
| struct&nbsp;&nbsp;[DCameraSettings](_d_camera_settings.md) | 分布式相机控制设置。 | 
| struct&nbsp;&nbsp;[DCStreamInfo](_d_c_stream_info.md) | 分布式相机内部流信息，用于创建流时传入相关的配置参数。 | 
| struct&nbsp;&nbsp;[DCCaptureInfo](_d_c_capture_info.md) | 分布式相机内部捕获请求的信息。 | 
| struct&nbsp;&nbsp;[DCameraBuffer](_d_camera_buffer.md) | 分布式相机进程间传递数据的共享内存结构体。 | 
| struct&nbsp;&nbsp;[DCameraHDFEvent](_d_camera_h_d_f_event.md) | 分布式相机的通知事件。 | 
| interface&nbsp;&nbsp;[IDCameraProvider](interface_i_d_camera_provider.md) | 定义Distributed Camera设备基本的操作。 | 
| interface&nbsp;&nbsp;[IDCameraProviderCallback](interface_i_d_camera_provider_callback.md) | 定义Distributed Camera设备功能回调操作。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DCSettingsType](#dcsettingstype) {<br/>UPDATE_METADATA = 0 , ENABLE_METADATA = 1 , DISABLE_METADATA = 2 , METADATA_RESULT = 3 ,<br/>SET_FLASH_LIGHT = 4 , FPS_RANGE = 5 , UPDATE_FRAME_METADATA = 6<br/>} | 分布式相机metadata更新类型。 | 
| [DCamRetCode](#dcamretcode) {<br/>SUCCESS = 0 , CAMERA_BUSY = 1 , INVALID_ARGUMENT = 2 , METHOD_NOT_SUPPORTED = 3 ,<br/>CAMERA_OFFLINE = 4 , EXCEED_MAX_NUMBER = 5 , DEVICE_NOT_INIT = 6 , FAILED = 7<br/>} | HDI接口的返回值。 | 
| [DCEncodeType](#dcencodetype) {<br/>ENCODE_TYPE_NULL = 0 , ENCODE_TYPE_H264 = 1 , ENCODE_TYPE_H265 = 2 , ENCODE_TYPE_JPEG = 3 ,<br/>ENCODE_TYPE_MPEG4_ES = 4<br/>} | 流数据的编码类型。 | 
| [DCStreamType](#dcstreamtype) { CONTINUOUS_FRAME = 0 , SNAPSHOT_FRAME = 1 } | 内部流的类型。 | 


## 枚举类型说明


### DCamRetCode

```
enum DCamRetCode
```

**描述**


HDI接口的返回值。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS | 调用成功。 | 
| CAMERA_BUSY | 设备当前忙。 | 
| INVALID_ARGUMENT | 参数错误。 | 
| METHOD_NOT_SUPPORTED | 不支持当前调用方法。 | 
| CAMERA_OFFLINE | 设备已经下线。 | 
| EXCEED_MAX_NUMBER | 使能的分布式相机设备超过限制。 | 
| DEVICE_NOT_INIT | 设备没有初始化。 | 
| FAILED | 调用失败。 | 


### DCEncodeType

```
enum DCEncodeType
```

**描述**


流数据的编码类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ENCODE_TYPE_NULL | 未设置编码类型。 | 
| ENCODE_TYPE_H264 | 编码类型为H264。 | 
| ENCODE_TYPE_H265 | 编码类型为H265。 | 
| ENCODE_TYPE_JPEG | 编码类型为JPEG。 | 
| ENCODE_TYPE_MPEG4_ES | 编码类型为mpeg4-es。 | 


### DCSettingsType

```
enum DCSettingsType
```

**描述**


分布式相机metadata更新类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| UPDATE_METADATA | 设置整包数据。 | 
| ENABLE_METADATA | 使能数据配置。 | 
| DISABLE_METADATA | 去使能数据配置。 | 
| METADATA_RESULT | 分布式相机返回结果。 | 
| SET_FLASH_LIGHT | 闪光灯设置。 | 
| FPS_RANGE | fps范围设置。 | 
| UPDATE_FRAME_METADATA | 帧数设置。 | 


### DCStreamType

```
enum DCStreamType
```

**描述**


内部流的类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CONTINUOUS_FRAME | 连续流。例如：预览流，录像流。 | 
| SNAPSHOT_FRAME | 单个捕获流。例如：拍照流。 | 
