# Types.idl


## 概述

Camera模块HDI接口使用的数据类型。

模块包路径：ohos.hdi.camera.v1_2

引用：ohos.hdi.camera.v1_1.Types

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ImageBufferInfo](_image_buffer_info_v12.md) | 定义 ImageBufferInfo，它由[IImageProcessCallback::OnProcessDone](interface_i_image_process_callback_v12.md#onprocessdone) 使用。 | 
| struct&nbsp;&nbsp;[CaptureStartedInfo](_capture_started_info_v12.md) | 定义CaptureStartedInfo，该信息由[IStreamOperatorCallback::OnCaptureStartedV1_2](interface_i_stream_operator_callback_v12.md#oncapturestartedv1_2)使用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CamRetCode](_camera_v12.md#camretcode) {<br/>NO_ERROR = 0, CAMERA_BUSY = -1, INSUFFICIENT_RESOURCES = -2, INVALID_ARGUMENT = -3,&nbsp;&nbsp;&nbsp;METHOD_NOT_SUPPORTED = -4, CAMERA_CLOSED = -5, DEVICE_ERROR = -6, NO_PERMISSION = -7 ,DEVICE_CONFLICT = -8<br/>} | HDI接口的返回值。 | 
| [ExtendedStreamInfoType_V1_2](_camera_v12.md#extendedstreaminfotype_v1_2) { EXTENDED_STREAM_INFO_QUICK_THUMBNAIL = 0 , EXTENDED_STREAM_INFO_SKETCH = 1 } | 扩展流信息的类型。 | 
| [OperationMode_V1_2](_camera_v12.md#operationmode_v1_2) {<br/>NORMAL&nbsp;&nbsp;= 0 , CAPTURE = 1 , VIDEO = 2 , PORTRAIT = 3 ,<br/>NIGHT = 4 , PROFESSIONAL = 5 , SLOW_MOTION = 6 , SCAN_CODE = 7 , CAPTURE_MACRO = 8 , VIDEO_MACRO = 9 , SUPER_STAB = 10<br/>} | 流使用模式。 | 
| [DeferredDeliveryImageType](_camera_v12.md#deferreddeliveryimagetype) { NONE = 0 , STILL_IMAGE = 1 , MOVING_IMAGE = 2 } | 延迟拍照的类型。 | 
| [SessionStatus](_camera_v12.md#sessionstatus) {<br/>SESSION_STATUS_READY = 0 , SESSION_STATUS_READY_SPACE_LIMIT_REACHED = 1 , SESSSON_STATUS_NOT_READY_TEMPORARILY = 2 , SESSION_STATUS_NOT_READY_OVERHEAT = 3 ,<br/>SESSION_STATUS_NOT_READY_PREEMPTED = 4<br/>} | 会话状态的类型。 | 
| [ErrorCode](_camera_v12.md#errorcode) {<br/>TIMEOUT = 0 , ERROR = 1 , BUSY = 3 , HIGH_TEMPERATURE = 4 ,<br/>ABORT = 5<br/>} | 错误代码的类型。 | 
| [ExecutionMode](_camera_v12.md#executionmode) { HIGH_PREFORMANCE = 0 , BALANCED = 1 , LOW_POWER = 2 } | 执行模式的类型。 | 
