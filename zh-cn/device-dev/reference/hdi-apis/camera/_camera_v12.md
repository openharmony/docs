# Camera (V1_2)


## 概述

Camera模块接口定义。Camera模块涉及相机设备的操作、流的操作、离线流的操作和各种回调等。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ICameraDevice.idl](_i_camera_device_8idl_v12.md) | Camera设备操作接口。 | 
| [ICameraHost.idl](_i_camera_host_8idl_v12.md) | Camera服务的管理类，对上层提供HDI接口。 | 
| [ICameraHostCallback.idl](_i_camera_host_callback_8idl_v12.md) | ICameraHost的回调接口，提供Camera设备和闪关灯状态变化的回调函数，回调函数由调用者实现。 | 
| [IImageProcessService.idl](_i_image_process_service_8idl_v12.md) | 声明用于图像处理服务的API。 | 
| [IStreamOperator.idl](_i_stream_operator_8idl_v12.md) | 流的操作接口。 | 
| [IStreamOperatorCallback.idl](_i_stream_operator_callback_8idl_v12.md) | [IStreamOperator](interface_i_stream_operator_v12.md)相关的回调，这些回调均由调用者实现。 | 
| [Types.idl](camera_types_8idl_v12.md) | Camera模块HDI接口使用的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ICameraDevice](interface_i_camera_device_v12.md) | 定义Camera设备基本的操作。 | 
| interface&nbsp;&nbsp;[ICameraHost](interface_i_camera_host_v12.md) | 定义Camera设备功能操作。 | 
| interface&nbsp;&nbsp;[ICameraHostCallback](interface_i_camera_host_callback_v12.md) | 定义Camera设备功能回调操作。 | 
| interface&nbsp;&nbsp;[IImageProcessCallback](interface_i_image_process_callback_v12.md) | 定义声明图像处理回调。 | 
| interface&nbsp;&nbsp;[IImageProcessService](interface_i_image_process_service_v12.md) | 声明图像处理进程服务。 | 
| interface&nbsp;&nbsp;[IImageProcessSession](interface_i_image_process_session_v12.md) | 图像处理会话进程。 | 
| interface&nbsp;&nbsp;[IStreamOperator](interface_i_stream_operator_v12.md) | 定义Camera设备流操作。 | 
| interface&nbsp;&nbsp;[IStreamOperatorCallback](interface_i_stream_operator_callback_v12.md) | 定义Camera设备流回调操作。 | 
| struct&nbsp;&nbsp;[ImageBufferInfo](_image_buffer_info_v12.md) | 定义 ImageBufferInfo，它由[IImageProcessCallback::OnProcessDone](interface_i_image_process_callback_v12.md#onprocessdone) 使用。 | 
| struct&nbsp;&nbsp;[CaptureStartedInfo](_capture_started_info_v12.md) | 定义CaptureStartedInfo，该信息由[IStreamOperatorCallback::OnCaptureStartedV1_2](interface_i_stream_operator_callback_v12.md#oncapturestartedv1_2)使用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CamRetCode](#camretcode) {<br/>NO_ERROR = 0, CAMERA_BUSY = -1, INSUFFICIENT_RESOURCES = -2, INVALID_ARGUMENT = -3,&nbsp;&nbsp;&nbsp;METHOD_NOT_SUPPORTED = -4, CAMERA_CLOSED = -5, DEVICE_ERROR = -6, NO_PERMISSION = -7 ,DEVICE_CONFLICT = -8<br/>} | HDI接口的返回值。 | 
| [ExtendedStreamInfoType_V1_2](#extendedstreaminfotype_v1_2) { EXTENDED_STREAM_INFO_QUICK_THUMBNAIL = 0 , EXTENDED_STREAM_INFO_SKETCH = 1 } | 扩展流信息的类型。 | 
| [OperationMode_V1_2](#operationmode_v1_2) {<br/>NORMAL&nbsp;&nbsp;= 0 , CAPTURE = 1 , VIDEO = 2 , PORTRAIT = 3 ,<br/>NIGHT = 4 , PROFESSIONAL = 5 , SLOW_MOTION = 6 , SCAN_CODE = 7 , CAPTURE_MACRO = 8 , VIDEO_MACRO = 9 , SUPER_STAB = 10<br/>} | 流使用模式。 | 
| [DeferredDeliveryImageType](#deferreddeliveryimagetype) { NONE = 0 , STILL_IMAGE = 1 , MOVING_IMAGE = 2 } | 延迟拍照的类型。 | 
| [SessionStatus](#sessionstatus) {<br/>SESSION_STATUS_READY = 0 , SESSION_STATUS_READY_SPACE_LIMIT_REACHED = 1 , SESSSON_STATUS_NOT_READY_TEMPORARILY = 2 , SESSION_STATUS_NOT_READY_OVERHEAT = 3 ,<br/>SESSION_STATUS_NOT_READY_PREEMPTED = 4<br/>} | 会话状态的类型。 | 
| [ErrorCode](#errorcode) {<br/>TIMEOUT = 0 , ERROR = 1 , BUSY = 3 , HIGH_TEMPERATURE = 4 ,<br/>ABORT = 5<br/>} | 错误代码的类型。 | 
| [ExecutionMode](#executionmode) { HIGH_PREFORMANCE = 0 , BALANCED = 1 , LOW_POWER = 2 } | 执行模式的类型。 | 


## 枚举类型说明


### CamRetCode

```
enum CamRetCode
```

**描述**

HDI接口的返回值。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| NO_ERROR | 调用成功。 | 
| CAMERA_BUSY | 设备当前忙。 | 
| INSUFFICIENT_RESOURCES | 资源不足。 | 
| INVALID_ARGUMENT | 参数错误。 | 
| METHOD_NOT_SUPPORTED | 不支持当前调用方法。 | 
| CAMERA_CLOSED | Camera设备已经关闭。 | 
| DEVICE_ERROR | 驱动层发生严重错误。 | 
| NO_PERMISSION | 无权限访问设备。 | 
| DEVICE_CONFLICT | 设备冲突。 | 


### DeferredDeliveryImageType

```
enum DeferredDeliveryImageType
```

**描述**

延迟拍照的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| NONE | 不支持延迟拍照。 | 
| STILL_IMAGE | 支持静止图像。 | 
| MOVING_IMAGE | 支持动态图像。 | 


### ErrorCode

```
enum ErrorCode
```

**描述**

错误代码的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| TIMEOUT | 超时。 | 
| ERROR | 错误。 | 
| BUSY | 忙碌。 | 
| HIGH_TEMPERATURE | 高温。 | 
| ABORT | 中止。 | 


### ExecutionMode

```
enum ExecutionMode
```

**描述**

执行模式的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| HIGH_PREFORMANCE | 高性能模式。 | 
| BALANCED | 平衡模式。 | 
| LOW_POWER | 低功耗模式。 | 


### ExtendedStreamInfoType_V1_2

```
enum ExtendedStreamInfoType_V1_2
```

**描述**

扩展流信息的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| EXTENDED_STREAM_INFO_QUICK_THUMBNAIL | 快速缩略图的扩展流信息。 | 
| EXTENDED_STREAM_INFO_SKETCH | sketch的扩展流信息。 | 


### OperationMode_V1_2

```
enum OperationMode_V1_2
```

**描述**

流使用模式。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL | 普通模式，支持照片和视频场景。 | 
| CAPTURE | 拍摄模式，专用于照片场景 如果实现了此模式，则不应再实现 NORMAL 模式。 | 
| VIDEO | 视频模式，专用于视频秒控 如果实现了此模式，则不应再实现 NORMAL 模式。 | 
| PORTRAIT | 人像模式，专用于人像照片拍摄。 | 
| NIGHT | 夜间模式，专用于夜间拍摄场景。 | 
| PROFESSIONAL | 专业模式，专用于专业拍照场景。 | 
| SLOW_MOTION | 慢动作模式，专用于捕捉慢动作。 | 
| SCAN_CODE | 扫描模式，专用于扫码。 | 
| CAPTURE_MACRO | 微距模式，专用于微距拍照。 | 
| VIDEO_MACRO | 微距模式，专用于微距录像。 | 
| SUPER_STAB | 超级防抖模式，专用于使用超级防抖模式。 | 


### SessionStatus

```
enum SessionStatus
```

**描述**

会话状态的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_STATUS_READY | 会话已准备就绪。 | 
| SESSION_STATUS_READY_SPACE_LIMIT_REACHED | 会话已准备就绪，但已达到存储限制。 | 
| SESSSON_STATUS_NOT_READY_TEMPORARILY | 会话暂时未就绪。 | 
| SESSION_STATUS_NOT_READY_OVERHEAT | 由于过热，会话未就绪。 | 
| SESSION_STATUS_NOT_READY_PREEMPTED | 由于被抢占，会话未就绪。 | 
