# Types.idl


## **概述**

Camera模块HDI接口使用的数据类型。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Camera](camera.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [StreamInfo](_stream_info.md) | 流信息，用于创建流时传入相关的配置参数。 | 
| [StreamAttribute](_stream_attribute.md) | 流的属性。 | 
| [CaptureInfo](_capture_info.md) | 捕获请求的相关信息。 | 
| [CaptureEndedInfo](_capture_ended_info.md) | 捕获结束相关信息，用于捕获结束回调[OnCaptureEnded](interface_i_stream_operator_callback.md#oncaptureended)。 | 
| [CaptureErrorInfo](_capture_error_info.md) | 流错误信息，用于回调[OnCaptureError](interface_i_stream_operator_callback.md#oncaptureerror)。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [CamRetCode](camera.md#camretcode)&nbsp;{&nbsp;&nbsp;&nbsp;NO_ERROR&nbsp;=&nbsp;0,&nbsp;CAMERA_BUSY&nbsp;=&nbsp;-1,&nbsp;INSUFFICIENT_RESOURCES&nbsp;=&nbsp;-2,&nbsp;INVALID_ARGUMENT&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;METHOD_NOT_SUPPORTED&nbsp;=&nbsp;-4,&nbsp;CAMERA_CLOSED&nbsp;=&nbsp;-5,&nbsp;DEVICE_ERROR&nbsp;=&nbsp;-6,&nbsp;NO_PERMISSION&nbsp;=&nbsp;-7&nbsp;} | HDI接口的返回值。 | 
| [ResultCallbackMode](camera.md#resultcallbackmode)&nbsp;{&nbsp;PER_FRAME&nbsp;=&nbsp;0,&nbsp;ON_CHANGED&nbsp;=&nbsp;1&nbsp;} | metadata的上报模式。 | 
| [OperationMode](camera.md#operationmode)&nbsp;{&nbsp;NORMAL&nbsp;=&nbsp;0&nbsp;} | 流的使用模式。 | 
| [StreamIntent](camera.md#streamintent)&nbsp;{&nbsp;PREVIEW&nbsp;=&nbsp;0,&nbsp;VIDEO&nbsp;=&nbsp;1,&nbsp;STILL_CAPTURE&nbsp;=&nbsp;2,&nbsp;POST_VIEW&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;ANALYZE&nbsp;=&nbsp;4,&nbsp;CUSTOM&nbsp;=&nbsp;5&nbsp;} | 流的类型。 | 
| [EncodeType](camera.md#encodetype)&nbsp;{&nbsp;ENCODE_TYPE_NULL&nbsp;=&nbsp;0,&nbsp;ENCODE_TYPE_H264&nbsp;=&nbsp;1,&nbsp;ENCODE_TYPE_H265&nbsp;=&nbsp;2,&nbsp;ENCODE_TYPE_JPEG&nbsp;=&nbsp;3&nbsp;} | 流数据的编码类型。 | 
| [StreamSupportType](camera.md#streamsupporttype)&nbsp;{&nbsp;DYNAMIC_SUPPORTED&nbsp;=&nbsp;0,&nbsp;RE_CONFIGURED_REQUIRED&nbsp;=&nbsp;1,&nbsp;NOT_SUPPORTED&nbsp;=&nbsp;2&nbsp;} | 对动态配置流的支持类型，使用场景参考[IsStreamsSupported](interface_i_stream_operator.md#isstreamssupported)。 | 
| [CameraStatus](camera.md#camerastatus)&nbsp;{&nbsp;UN_AVAILABLE&nbsp;=&nbsp;0,&nbsp;AVAILABLE&nbsp;=&nbsp;1&nbsp;} | Camera设备状态。 | 
| [FlashlightStatus](camera.md#flashlightstatus)&nbsp;{&nbsp;FLASHLIGHT_OFF&nbsp;=&nbsp;0,&nbsp;FLASHLIGHT_ON&nbsp;=&nbsp;1,&nbsp;FLASHLIGHT_UNAVAILABLE&nbsp;=&nbsp;2&nbsp;} | 闪光灯状态。 | 
| [CameraEvent](camera.md#cameraevent)&nbsp;{&nbsp;CAMERA_EVENT_DEVICE_ADD&nbsp;=&nbsp;0,&nbsp;CAMERA_EVENT_DEVICE_RMV&nbsp;=&nbsp;1&nbsp;} | Camera事件。 | 
| [ErrorType](camera.md#errortype)&nbsp;{&nbsp;&nbsp;&nbsp;FATAL_ERROR&nbsp;=&nbsp;0,&nbsp;REQUEST_TIMEOUT&nbsp;=&nbsp;1,&nbsp;DRIVER_ERROR&nbsp;=&nbsp;2,&nbsp;DEVICE_PREEMPT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;DEVICE_DISCONNECT&nbsp;=&nbsp;4,&nbsp;DCAMERA_ERROR_BEGIN&nbsp;=&nbsp;1024,&nbsp;DCAMERA_ERROR_DEVICE_IN_USE,&nbsp;DCAMERA_ERROR_NO_PERMISSION&nbsp;} | 设备错误类型，用于设备错误回调[OnError](interface_i_camera_device_callback.md#onerror)。 | 
| [StreamError](camera.md#streamerror)&nbsp;{&nbsp;UNKNOWN_ERROR&nbsp;=&nbsp;0,&nbsp;BUFFER_LOST&nbsp;=&nbsp;1&nbsp;} | 流错误类型，用于流错误类型[CaptureErrorInfo](_capture_error_info.md)。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.camera.v1_0 | Camera设备接口的包路径。 | 
| sequenceable ohos.hdi.camera.v1_0.BufferProducerSequenceable | ohos.hdi.camera.v1_0序列，可用缓冲区生成器。 | 
