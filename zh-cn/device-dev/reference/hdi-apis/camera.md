# Camera


## **概述**

Camera模块接口定义。

Camera模块涉及相机设备的操作、流的操作、离线流的操作和各种回调等。

**Since**:

3.2

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [ICameraDevice.idl](_i_camera_device_8idl.md) | Camera设备操作接口。 | 
| [ICameraDeviceCallback.idl](_i_camera_device_callback_8idl.md) | Camera设备的回调接口，主要包含Camera设备发生错误时和上报metadata的回调函数。 | 
| [ICameraHost.idl](_i_camera_host_8idl.md) | Camera服务的管理类，对上层提供HDI接口。 | 
| [ICameraHostCallback.idl](_i_camera_host_callback_8idl.md) | ICameraHost的回调接口，提供Camera设备和闪关灯状态变化的回调函数，回调函数由调用者实现。 | 
| [IOfflineStreamOperator.idl](_i_offline_stream_operator_8idl.md) | 离线流的操作接口。 | 
| [IStreamOperator.idl](_i_stream_operator_8idl.md) | 流的操作接口。 | 
| [IStreamOperatorCallback.idl](_i_stream_operator_callback_8idl.md) | [IStreamOperator](interface_i_stream_operator.md)相关的回调，这些回调均由调用者实现。 | 
| [Types.idl](camera_2v1__0_2_types_8idl.md) | Camera模块HDI接口使用的数据类型。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ICameraDevice](interface_i_camera_device.md) | 定义Camera设备基本的操作。 | 
| [ICameraDeviceCallback](interface_i_camera_device_callback.md) | 定义Camera设备回调操作。 | 
| [ICameraHost](interface_i_camera_host.md) | 定义Camera设备功能操作。 | 
| [ICameraHostCallback](interface_i_camera_host_callback.md) | 定义Camera设备功能回调操作。 | 
| [IOfflineStreamOperator](interface_i_offline_stream_operator.md) | 定义Camera设备离线流操作。 | 
| [IStreamOperator](interface_i_stream_operator.md) | 定义Camera设备流操作。 | 
| [IStreamOperatorCallback](interface_i_stream_operator_callback.md) | 定义Camera设备流回调操作。 | 
| [StreamInfo](_stream_info.md) | 流信息，用于创建流时传入相关的配置参数。 | 
| [StreamAttribute](_stream_attribute.md) | 流的属性。 | 
| [CaptureInfo](_capture_info.md) | 捕获请求的相关信息。 | 
| [CaptureEndedInfo](_capture_ended_info.md) | 捕获结束相关信息，用于捕获结束回调[OnCaptureEnded](interface_i_stream_operator_callback.md#oncaptureended)。 | 
| [CaptureErrorInfo](_capture_error_info.md) | 流错误信息，用于回调[OnCaptureError](interface_i_stream_operator_callback.md#oncaptureerror)。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [CamRetCode](#camretcode)&nbsp;{&nbsp;&nbsp;&nbsp;NO_ERROR&nbsp;=&nbsp;0,&nbsp;CAMERA_BUSY&nbsp;=&nbsp;-1,&nbsp;INSUFFICIENT_RESOURCES&nbsp;=&nbsp;-2,&nbsp;INVALID_ARGUMENT&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;METHOD_NOT_SUPPORTED&nbsp;=&nbsp;-4,&nbsp;CAMERA_CLOSED&nbsp;=&nbsp;-5,&nbsp;DEVICE_ERROR&nbsp;=&nbsp;-6,&nbsp;NO_PERMISSION&nbsp;=&nbsp;-7&nbsp;} | HDI接口的返回值。 | 
| [ResultCallbackMode](#resultcallbackmode)&nbsp;{&nbsp;PER_FRAME&nbsp;=&nbsp;0,&nbsp;ON_CHANGED&nbsp;=&nbsp;1&nbsp;} | metadata的上报模式。 | 
| [OperationMode](#operationmode)&nbsp;{&nbsp;NORMAL&nbsp;=&nbsp;0&nbsp;} | 流的使用模式。 | 
| [StreamIntent](#streamintent)&nbsp;{&nbsp;PREVIEW&nbsp;=&nbsp;0,&nbsp;VIDEO&nbsp;=&nbsp;1,&nbsp;STILL_CAPTURE&nbsp;=&nbsp;2,&nbsp;POST_VIEW&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;ANALYZE&nbsp;=&nbsp;4,&nbsp;CUSTOM&nbsp;=&nbsp;5&nbsp;} | 流的类型。 | 
| [EncodeType](#encodetype)&nbsp;{&nbsp;ENCODE_TYPE_NULL&nbsp;=&nbsp;0,&nbsp;ENCODE_TYPE_H264&nbsp;=&nbsp;1,&nbsp;ENCODE_TYPE_H265&nbsp;=&nbsp;2,&nbsp;ENCODE_TYPE_JPEG&nbsp;=&nbsp;3&nbsp;} | 流数据的编码类型。 | 
| [StreamSupportType](#streamsupporttype)&nbsp;{&nbsp;DYNAMIC_SUPPORTED&nbsp;=&nbsp;0,&nbsp;RE_CONFIGURED_REQUIRED&nbsp;=&nbsp;1,&nbsp;NOT_SUPPORTED&nbsp;=&nbsp;2&nbsp;} | 对动态配置流的支持类型，使用场景参考[IsStreamsSupported](interface_i_stream_operator.md#isstreamssupported)。 | 
| [CameraStatus](#camerastatus)&nbsp;{&nbsp;UN_AVAILABLE&nbsp;=&nbsp;0,&nbsp;AVAILABLE&nbsp;=&nbsp;1&nbsp;} | Camera设备状态。 | 
| [FlashlightStatus](#flashlightstatus)&nbsp;{&nbsp;FLASHLIGHT_OFF&nbsp;=&nbsp;0,&nbsp;FLASHLIGHT_ON&nbsp;=&nbsp;1,&nbsp;FLASHLIGHT_UNAVAILABLE&nbsp;=&nbsp;2&nbsp;} | 闪光灯状态。 | 
| [CameraEvent](#cameraevent)&nbsp;{&nbsp;CAMERA_EVENT_DEVICE_ADD&nbsp;=&nbsp;0,&nbsp;CAMERA_EVENT_DEVICE_RMV&nbsp;=&nbsp;1&nbsp;} | Camera事件。 | 
| [ErrorType](#errortype)&nbsp;{&nbsp;&nbsp;&nbsp;FATAL_ERROR&nbsp;=&nbsp;0,&nbsp;REQUEST_TIMEOUT&nbsp;=&nbsp;1,&nbsp;DRIVER_ERROR&nbsp;=&nbsp;2,&nbsp;DEVICE_PREEMPT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;DEVICE_DISCONNECT&nbsp;=&nbsp;4,&nbsp;DCAMERA_ERROR_BEGIN&nbsp;=&nbsp;1024,&nbsp;DCAMERA_ERROR_DEVICE_IN_USE,&nbsp;DCAMERA_ERROR_NO_PERMISSION&nbsp;} | 设备错误类型，用于设备错误回调[OnError](interface_i_camera_device_callback.md#onerror)。 | 
| [StreamError](#streamerror)&nbsp;{&nbsp;UNKNOWN_ERROR&nbsp;=&nbsp;0,&nbsp;BUFFER_LOST&nbsp;=&nbsp;1&nbsp;} | 流错误类型，用于流错误类型[CaptureErrorInfo](_capture_error_info.md)。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.camera.v1_0 | Camera设备接口的包路径。 | 
| sequenceable&nbsp;ohos.hdi.camera.v1_0.BufferProducerSequenceable | ohos.hdi.camera.v1_0序列，可用缓冲区生成器。 | 


## **枚举类型说明**


### CameraEvent

  
```
enum CameraEvent
```

**描述：**

Camera事件。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_EVENT_DEVICE_ADD | Camera设备增加事件。 | 
| CAMERA_EVENT_DEVICE_RMV | Camera设备删除事件。 | 


### CameraStatus

  
```
enum CameraStatus
```

**描述：**

Camera设备状态。

  | 枚举值 | 描述 | 
| -------- | -------- |
| UN_AVAILABLE | 设备当前不在位或者不可用。 | 
| AVAILABLE | 设备当前可用。 | 


### CamRetCode

  
```
enum CamRetCode
```

**描述：**

HDI接口的返回值。

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


### EncodeType

  
```
enum EncodeType
```

**描述：**

流数据的编码类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ENCODE_TYPE_NULL | 未设置编码类型 | 
| ENCODE_TYPE_H264 | 编码类型为H264。 | 
| ENCODE_TYPE_H265 | 编码类型为H265。 | 
| ENCODE_TYPE_JPEG | 编码类型为JPEG。 | 


### ErrorType

  
```
enum ErrorType
```

**描述：**

设备错误类型，用于设备错误回调[OnError](interface_i_camera_device_callback.md#onerror)。

  | 枚举值 | 描述 | 
| -------- | -------- |
| FATAL_ERROR | 严重错误，需要关闭Camera设备。 | 
| REQUEST_TIMEOUT | 请求超时，需要关闭Camera设备。 | 
| DRIVER_ERROR | 驱动程序中发生错误。 | 
| DEVICE_PREEMPT | 设备被抢占。 | 
| DEVICE_DISCONNECT | 设备已断开连接。 | 
| DCAMERA_ERROR_BEGIN | 分布式像机错误开始的标识。 | 
| DCAMERA_ERROR_DEVICE_IN_USE | 分布式像机设备忙。 | 
| DCAMERA_ERROR_NO_PERMISSION | 没有访问分布式摄像机设备的权限。 | 


### FlashlightStatus

  
```
enum FlashlightStatus
```

**描述：**

闪光灯状态。

  | 枚举值 | 描述 | 
| -------- | -------- |
| FLASHLIGHT_OFF | 闪光灯关闭。 | 
| FLASHLIGHT_ON | 闪光灯开启。 | 
| FLASHLIGHT_UNAVAILABLE | 闪光灯当前不可用。 | 


### OperationMode

  
```
enum OperationMode
```

**描述：**

流的使用模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL | 普通模式。 | 


### ResultCallbackMode

  
```
enum ResultCallbackMode
```

**描述：**

metadata的上报模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PER_FRAME | 逐帧上报。 | 
| ON_CHANGED | 设备状态变化时上报。 | 


### StreamError

  
```
enum StreamError
```

**描述：**

流错误类型，用于流错误类型[CaptureErrorInfo](_capture_error_info.md)。

  | 枚举值 | 描述 | 
| -------- | -------- |
| UNKNOWN_ERROR | 流未知错误。 | 
| BUFFER_LOST | 丢包。 | 


### StreamIntent

  
```
enum StreamIntent
```

**描述：**

流的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PREVIEW | 流数据用于显示，即预览流。 | 
| VIDEO | 流数据用于编码生成录像，即录像流。 | 
| STILL_CAPTURE | 流数据用于编码生成照片，即拍照流。 | 
| POST_VIEW | 流数据用于保存缩略图。 | 
| ANALYZE | 流数据用于图像分析。 | 
| CUSTOM | 自定义类型。 | 


### StreamSupportType

  
```
enum StreamSupportType
```

**描述：**

对动态配置流的支持类型，使用场景参考[IsStreamsSupported](interface_i_stream_operator.md#isstreamssupported)。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DYNAMIC_SUPPORTED | 支持动态配置流，对应的流参数直接生效。 | 
| RE_CONFIGURED_REQUIRED | 不支持动态配置流，对应的参数需要停止流然后重新配置流才能生效。 | 
| NOT_SUPPORTED | 不支持对应的流参数配置。 | 
