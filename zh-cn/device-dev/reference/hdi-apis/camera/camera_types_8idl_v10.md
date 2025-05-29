# Types.idl


## 概述

Camera模块HDI接口使用的数据类型。

模块包路径：ohos.hdi.camera.v1_0

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[StreamInfo](_stream_info_v10.md) | 流信息，用于创建流时传入相关的配置参数。 | 
| struct&nbsp;&nbsp;[StreamAttribute](_stream_attribute_v10.md) | 流的属性。 | 
| struct&nbsp;&nbsp;[CaptureInfo](_capture_info_v10.md) | 捕获请求的相关信息。 | 
| struct&nbsp;&nbsp;[CaptureEndedInfo](_capture_ended_info_v10.md) | 捕获结束相关信息，用于捕获结束回调[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)。 | 
| struct&nbsp;&nbsp;[CaptureErrorInfo](_capture_error_info_v10.md) | 流错误信息，用于回调[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CamRetCode](_camera_v10.md#camretcode) {&nbsp;&nbsp;&nbsp;NO_ERROR = 0, CAMERA_BUSY = -1, INSUFFICIENT_RESOURCES = -2, INVALID_ARGUMENT = -3,&nbsp;&nbsp;&nbsp;METHOD_NOT_SUPPORTED = -4, CAMERA_CLOSED = -5, DEVICE_ERROR = -6, NO_PERMISSION = -7 } | HDI接口的返回值。 | 
| [ResultCallbackMode](_camera_v10.md#resultcallbackmode) { PER_FRAME = 0, ON_CHANGED = 1 } | metadata的上报模式。 | 
| [OperationMode](_camera_v10.md#operationmode) { NORMAL = 0 } | 流的使用模式。 | 
| [StreamIntent](_camera_v10.md#streamintent) { PREVIEW = 0, VIDEO = 1, STILL_CAPTURE = 2, POST_VIEW = 3,&nbsp;&nbsp;&nbsp;ANALYZE = 4, CUSTOM = 5 } | 流的类型。 | 
| [EncodeType](_camera_v10.md#encodetype) { ENCODE_TYPE_NULL = 0, ENCODE_TYPE_H264 = 1, ENCODE_TYPE_H265 = 2, ENCODE_TYPE_JPEG = 3 } | 流数据的编码类型。 | 
| [StreamSupportType](_camera_v10.md#streamsupporttype) { DYNAMIC_SUPPORTED = 0, RE_CONFIGURED_REQUIRED = 1, NOT_SUPPORTED = 2 } | 对动态配置流的支持类型，使用场景参考[IsStreamsSupported](interface_i_stream_operator_v10.md#isstreamssupported)。 | 
| [CameraStatus](_camera_v10.md#camerastatus) { UN_AVAILABLE = 0, AVAILABLE = 1 } | Camera设备状态。 | 
| [FlashlightStatus](_camera_v10.md#flashlightstatus) { FLASHLIGHT_OFF = 0, FLASHLIGHT_ON = 1, FLASHLIGHT_UNAVAILABLE = 2 } | 闪光灯状态。 | 
| [CameraEvent](_camera_v10.md#cameraevent) { CAMERA_EVENT_DEVICE_ADD = 0, CAMERA_EVENT_DEVICE_RMV = 1 } | Camera事件。 | 
| [ErrorType](_camera_v10.md#errortype) {&nbsp;&nbsp;&nbsp;FATAL_ERROR = 0, REQUEST_TIMEOUT = 1, DRIVER_ERROR = 2, DEVICE_PREEMPT = 3,&nbsp;&nbsp;&nbsp;DEVICE_DISCONNECT = 4, DCAMERA_ERROR_BEGIN = 1024, DCAMERA_ERROR_DEVICE_IN_USE, DCAMERA_ERROR_NO_PERMISSION } | 设备错误类型，用于设备错误回调 [OnError](interface_i_camera_device_callback_v10.md#onerror)。 | 
| [StreamError](_camera_v10.md#streamerror) { UNKNOWN_ERROR = 0, BUFFER_LOST = 1 } | 流错误类型，用于流错误类型[CaptureErrorInfo](_capture_error_info_v10.md)。 | 
