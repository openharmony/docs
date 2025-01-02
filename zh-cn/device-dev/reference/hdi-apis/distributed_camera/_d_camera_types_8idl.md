# DCameraTypes.idl


## 概述

Distributed Camera模块HDI接口使用的数据类型。

模块包路径：ohos.hdi.distributed_camera.v1_0

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DHBase](_d_h_base.md) | 分布式硬件设备基础信息。 | 
| struct&nbsp;&nbsp;[DCameraSettings](_d_camera_settings.md) | 分布式相机控制设置。 | 
| struct&nbsp;&nbsp;[DCStreamInfo](_d_c_stream_info.md) | 分布式相机内部流信息，用于创建流时传入相关的配置参数。 | 
| struct&nbsp;&nbsp;[DCCaptureInfo](_d_c_capture_info.md) | 分布式相机内部捕获请求的信息。 | 
| struct&nbsp;&nbsp;[DCameraBuffer](_d_camera_buffer.md) | 分布式相机进程间传递数据的共享内存结构体。 | 
| struct&nbsp;&nbsp;[DCameraHDFEvent](_d_camera_h_d_f_event.md) | 分布式相机的通知事件。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DCSettingsType](_distributed.md#dcsettingstype) {<br/>UPDATE_METADATA = 0 , ENABLE_METADATA = 1 , DISABLE_METADATA = 2 , METADATA_RESULT = 3 ,<br/>SET_FLASH_LIGHT = 4 , FPS_RANGE = 5 , UPDATE_FRAME_METADATA = 6<br/>} | 分布式相机metadata更新类型。 | 
| [DCamRetCode](_distributed.md#dcamretcode) {<br/>SUCCESS = 0 , CAMERA_BUSY = 1 , INVALID_ARGUMENT = 2 , METHOD_NOT_SUPPORTED = 3 ,<br/>CAMERA_OFFLINE = 4 , EXCEED_MAX_NUMBER = 5 , DEVICE_NOT_INIT = 6 , FAILED = 7<br/>} | HDI接口的返回值。 | 
| [DCEncodeType](_distributed.md#dcencodetype) {<br/>ENCODE_TYPE_NULL = 0 , ENCODE_TYPE_H264 = 1 , ENCODE_TYPE_H265 = 2 , ENCODE_TYPE_JPEG = 3 ,<br/>ENCODE_TYPE_MPEG4_ES = 4<br/>} | 流数据的编码类型。 | 
| [DCStreamType](_distributed.md#dcstreamtype) { CONTINUOUS_FRAME = 0 , SNAPSHOT_FRAME = 1 } | 内部流的类型。 | 
