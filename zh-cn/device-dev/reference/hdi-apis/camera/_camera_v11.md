# Camera (V1_1)


## 概述

Camera模块接口定义。

Camera模块涉及相机设备的操作、流的操作、离线流的操作和各种回调等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ICameraDevice.idl](_i_camera_device_8idl_v11.md) | Camera设备操作接口。 | 
| [ICameraHost.idl](_i_camera_host_8idl_v11.md) | Camera服务的管理类，对上层提供HDI接口。 | 
| [IStreamOperator.idl](_i_stream_operator_8idl_v11.md) | 流的操作接口。 | 
| [Types.idl](camera_types_8idl_v11.md) | Camera模块HDI接口使用的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ICameraDevice](interface_i_camera_device_v11.md) | 定义Camera设备基本的操作。 | 
| interface&nbsp;&nbsp;[ICameraHost](interface_i_camera_host_v11.md) | 定义Camera设备功能操作。 | 
| interface&nbsp;&nbsp;[IStreamOperator](interface_i_stream_operator_v11.md) | 定义Camera设备流操作。 | 
| struct&nbsp;&nbsp;[ExtendedStreamInfo](_extended_stream_info_v11.md) | 扩展流信息。 | 
| struct&nbsp;&nbsp;[StreamInfo_V1_1](_stream_info___v1__1_v11.md) | 流信息，用于创建流时传入相关的配置参数。 | 
| struct&nbsp;&nbsp;[PrelaunchConfig](_prelaunch_config_v11.md) | 预启动配置信息，用于[Prelaunch](interface_i_camera_host_v11.md#prelaunch)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ExtendedStreamInfoType](#extendedstreaminfotype) { EXTENDED_STREAM_INFO_QUICK_THUMBNAIL = 0 } | 扩展流信息。 | 
| [OperationMode_V1_1](#operationmode_v1_1) {<br/>NORMAL = 0 , CAPTURE = 1 , VIDEO = 2 , PORTRAIT = 3 , NIGHT = 4 , PROFESSIONAL = 5 , SLOW_MOTION = 6<br/>} | 流的使用模式。 | 


## 枚举类型说明


### ExtendedStreamInfoType

```
enum ExtendedStreamInfoType
```

**描述**

扩展流信息。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| EXTENDED_STREAM_INFO_QUICK_THUMBNAIL | 快速缩略图的扩展流信息. | 


### OperationMode_V1_1

```
enum OperationMode_V1_1
```

**描述**

流的使用模式。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL | 普通模式, 支持拍照和录像场景。 | 
| CAPTURE | 拍照模式, 专用于拍照场景。 如果执行此模式, 不应再执行普通模式。 | 
| VIDEO | 录像模式, 专用于录像场景。 如果执行此模式, 不应再执行普通模式。 | 
| PORTRAIT | 人像模式, 专用于人像场景。 | 
| NIGHT | 夜景模式, 专用于夜间拍照场景。 | 
| PROFESSIONAL | 专业模式, 专用于专业拍照场景。 | 
| SLOW_MOTION | 慢动作模式, 专用于捕捉慢动作。 | 
