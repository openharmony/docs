# types.h


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [OHOS::Camera::StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md) | 流信息，用于创建流时传入相关的配置参数。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_stream_info.md) | 
| [OHOS::Camera::StreamAttribute](_o_h_o_s_1_1_camera_1_1_stream_attribute.md) | 流的属性。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_stream_attribute.md) | 
| [OHOS::Camera::CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md) | 捕获请求的相关信息。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_info.md) | 
| [OHOS::Camera::CaptureEndedInfo](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md) | 捕获结束相关信息，用于捕获结束回调&nbsp;**OnCaptureEnded**。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md) | 
| [OHOS::Camera::CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md) | 流错误信息，用于回调&nbsp;**OnCaptureError**。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_error_info.md) | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| **OHOS::Camera::CameraAbility**&nbsp;=&nbsp;CameraMetadata | Camera设备能力集合。 | 
| **OHOS::Camera::CameraSetting**&nbsp;=&nbsp;CameraMetadata | Camera设置参数，包括sensor帧率，3A相关参数等。 | 
| **OHOS::Camera::MetaType**&nbsp;=&nbsp;int32_t | 整型。 | 


### 枚举

  | 枚举名称 | 描述 | 
| -------- | -------- |
| [OHOS::Camera::CamRetCode](_camera.md#camretcode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;OHOS::Camera::NO_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::CAMERA_BUSY&nbsp;=&nbsp;-1,&nbsp;OHOS::Camera::INSUFFICIENT_RESOURCES&nbsp;=&nbsp;-2,&nbsp;OHOS::Camera::INVALID_ARGUMENT&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;OHOS::Camera::METHOD_NOT_SUPPORTED&nbsp;=&nbsp;-4,&nbsp;OHOS::Camera::CAMERA_CLOSED&nbsp;=&nbsp;-5,&nbsp;OHOS::Camera::DEVICE_ERROR&nbsp;=&nbsp;-6&nbsp;} | HDI接口的返回值。&nbsp;[更多...](_camera.md#camretcode) | 
| [OHOS::Camera::ResultCallbackMode](_camera.md#resultcallbackmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::PER_FRAME,&nbsp;OHOS::Camera::ON_CHANGED&nbsp;} | metadata的上报模式。&nbsp;[更多...](_camera.md#resultcallbackmode) | 
| [OHOS::Camera::OperationMode](_camera.md#operationmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::NORMAL&nbsp;=&nbsp;0&nbsp;} | 流的使用模式。&nbsp;[更多...](_camera.md#operationmode) | 
| [OHOS::Camera::StreamIntent](_camera.md#streamintent)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;OHOS::Camera::PREVIEW&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::VIDEO&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::STILL_CAPTURE&nbsp;=&nbsp;2,&nbsp;OHOS::Camera::POST_VIEW&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;OHOS::Camera::ANALYZE&nbsp;=&nbsp;4,&nbsp;OHOS::Camera::CUSTOM&nbsp;=&nbsp;5&nbsp;} | 流的类型。&nbsp;[更多...](_camera.md#streamintent) | 
| [OHOS::Camera::EncodeType](_camera.md#encodetype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::ENCODE_TYPE_NULL&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::ENCODE_TYPE_H264&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::ENCODE_TYPE_H265&nbsp;=&nbsp;2,&nbsp;OHOS::Camera::ENCODE_TYPE_JPEG&nbsp;=&nbsp;3&nbsp;} | 流数据的编码类型。&nbsp;[更多...](_camera.md#encodetype) | 
| [OHOS::Camera::StreamSupportType](_camera.md#streamsupporttype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::DYNAMIC_SUPPORTED,&nbsp;OHOS::Camera::RE_CONFIGURED_REQUIRED,&nbsp;OHOS::Camera::NOT_SUPPORTED&nbsp;} | 动态配置流的切换方式，使用场景参考&nbsp;[IsStreamsSupported](_camera.md#isstreamssupported)&nbsp;。&nbsp;[更多...](_camera.md#streamsupporttype) | 
| [OHOS::Camera::CameraStatus](_camera.md#camerastatus)&nbsp;{&nbsp;OHOS::Camera::UN_AVAILABLE&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::AVAILABLE&nbsp;=&nbsp;1&nbsp;} | Camera设备状态。&nbsp;[更多...](_camera.md#camerastatus) | 
| [OHOS::Camera::FlashlightStatus](_camera.md#flashlightstatus)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::FLASHLIGHT_OFF&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::FLASHLIGHT_ON&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::FLASHLIGHT_UNAVAILABLE&nbsp;=&nbsp;2&nbsp;} | 闪光灯状态。&nbsp;[更多...](_camera.md#flashlightstatus) | 
| [OHOS::Camera::CameraEvent](_camera.md#cameraevent):&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::CAMERA_EVENT_DEVICE_ADD&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::CAMERA_EVENT_DEVICE_RMV&nbsp;=&nbsp;1&nbsp;} | Camera事件。&nbsp;[更多...](_camera.md#cameraevent) | 
| [OHOS::Camera::ErrorType](_camera.md#errortype)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::FATAL_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::REQUEST_TIMEOUT&nbsp;=&nbsp;1&nbsp;} | 设备错误类型，用于设备错误回调&nbsp;**OnError**。&nbsp;[更多...](_camera.md#errortype) | 
| [OHOS::Camera::StreamError](_camera.md#streamerror)&nbsp;{&nbsp;OHOS::Camera::UNKNOWN_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::BUFFER_LOST&nbsp;=&nbsp;1&nbsp;} | 流错误类型，用于流错误类型&nbsp;**CaptureErrorInfo**。&nbsp;[更多...](_camera.md#streamerror) | 


## **详细描述**

Camera模块HDI接口使用的数据类型。

**Since：**

1.0

**Version：**

1.0
