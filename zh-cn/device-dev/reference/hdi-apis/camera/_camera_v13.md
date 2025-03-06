# Camera   (V1_3)


## 概述

Camera模块接口定义。

Camera模块涉及相机设备的操作、流的操作、离线流的操作和各种回调等。

**起始版本：** 5.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ICameraDevice.idl](_i_camera_device_8idl_v13.md) | Camera设备操作接口。 | 
| [ICameraHost.idl](_i_camera_host_8idl_v13.md) | Camera服务的管理类，对上层提供HDI接口。 | 
| [IImageProcessService.idl](_i_image_process_service_8idl_v13.md) | 声明用于图像处理服务的API。 | 
| [IStreamOperator.idl](_i_stream_operator_8idl_v13.md) | 流的操作接口。 | 
| [IStreamOperatorCallback.idl](_i_stream_operator_callback_8idl_v13.md) | [IStreamOperator](interface_i_stream_operator_v13.md)相关的回调，这些回调均由调用者实现。 | 
| [IVideoProcessCallback.idl](_i_video_process_callback_8idl_v13.md) | 声明视频流进程的回调。 | 
| [IVideoProcessService.idl](_i_video_process_service_8idl_v13.md) | 声明用于视频处理服务的API。 | 
| [IVideoProcessSession.idl](_i_video_process_session_8idl_v13.md) | 声明用于视频处理会话的API。 | 
| [Types.idl](_types_8idl_v13.md) | Camera模块HDI接口使用的数据类型。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ICameraDevice](interface_i_camera_device_v13.md) | 定义Camera设备基本的操作。 | 
| interface&nbsp;&nbsp;[ICameraHost](interface_i_camera_host_v13.md) | 定义Camera设备功能操作。 | 
| interface&nbsp;&nbsp;[IImageProcessCallback](interface_i_image_process_callback_v13.md) | 定义声明图像处理回调。 | 
| interface&nbsp;&nbsp;[IImageProcessService](interface_i_image_process_service_v13.md) | 声明图像处理进程服务。 | 
| interface&nbsp;&nbsp;[IStreamOperator](interface_i_stream_operator_v13.md) | 定义Camera设备流操作。 | 
| interface&nbsp;&nbsp;[IStreamOperatorCallback](interface_i_stream_operator_callback_v13.md) | 定义Camera设备流回调操作。 | 
| interface&nbsp;&nbsp;[IVideoProcessCallback](interface_i_video_process_callback_v13.md) | 定义声明图像处理回调。 | 
| interface&nbsp;&nbsp;[IVideoProcessService](interface_i_video_process_service_v13.md) | 声明视频处理进程服务。 | 
| interface&nbsp;&nbsp;[IVideoProcessSession](interface_i_video_process_session_v13.md) | 图像处理会话进程。 | 
| struct&nbsp;&nbsp;[CameraDeviceResourceCost](_camera_device_resource_cost_v13.md) | 相机设备资源开销，用于**ICameraDevice::[GetResourceCost()](interface_i_camera_host_v13.md#getresourcecost)**。 | 
| struct&nbsp;&nbsp;[StreamDescription](_stream_description_v13.md) | 流描述信息，使用于[IVideoProcessSession::Prepare](interface_i_video_process_session_v13.md#prepare)。 | 
| struct&nbsp;&nbsp;[CaptureEndedInfoExt](_capture_ended_info_ext_v13.md) | 拍照结束信息，使用于[IStreamOperatorCallback::OnCaptureEndedExt](interface_i_stream_operator_callback_v13.md#oncaptureendedext)。 | 
| struct&nbsp;&nbsp;[ImageBufferInfoExt](_image_buffer_info_ext_v13.md) | 图片流信息，使用于[IImageProcessCallback::OnProcessDoneExt](interface_i_image_process_callback_v13.md#onprocessdoneext)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OperationMode](#operationmode) : ohos.hdi.camera.v1_2.OperationMode_V1_2 {<br/>PROFESSIONAL_V1_3 = PROFESSIONAL, PROFESSIONAL_PHOTO = 11, PROFESSIONAL_VIDEO = 12, HIGH_FRAME_RATE = 13,<br/>HIGH_RESOLUTION_PHOTO = 14, SECURE = 15, QUICK_SHOT_PHOTO = 16, LIGHT_PAINTING = 17, PANORAMA_PHOTO = 18, TIMELAPSE_PHOTO = 19,<br/>APERTURE_VIDEO = 20, FLUORESCENCE_PHOTO = 21, SUN_BLOCK = 22} | 流使用模式。 | 
| [ExtendedStreamInfoType](#extendedstreaminfotype) : ohos.hdi.camera.v1_2.ExtendedStreamInfoType_V1_2 {<br/>EXTENDED_STREAM_INFO_RAW = 2, EXTENDED_STREAM_INFO_DEPTH = 3, EXTENDED_STREAM_INFO_META = 4, EXTENDED_STREAM_INFO_SECURE = 5,<br/>EXTENDED_STREAM_INFO_MAKER_INFO = 6, EXTENDED_STREAM_INFO_EXIF = 7, EXTENDED_STREAM_INFO_GAINMAP = 8, EXTENDED_STREAM_INFO_UNREFOCUS = 9,<br/>EXTENDED_STREAM_INFO_LINEAR = 10, EXTENDED_STREAM_INFO_FRAGMENT =11, EXTENDED_STREAM_INFO_UV = 12} | 扩展流信息的类型。 | 
| [StreamType](#streamtype) {<br/>STREAM_TYPE_PREVIEW = 0, STREAM_TYPE_VIDEO = 1, STREAM_TYPE_STILL_CAPTURE = 2, STREAM_TYPE_POST_VIEW = 3, STREAM_TYPE_ANALYZE = 4,<br/>STREAM_TYPE_CUSTOM = 5, STREAM_TYPE_DEPTH = 6} | 流类型。 | 
| [ExecutionMode](#executionmode) : ohos.hdi.camera.v1_2.ExecutionMode { DEFAULT = 3 } | 执行模式的类型。 | 
| [ErrorType](#errortype) : ohos.hdi.camera.v1_0.ErrorType { SENSOR_DATA_ERROR = 5 } | 设备错误类型，用于设备错误回调**[OnError()](interface_i_video_process_callback_v13.md#onerror)**。 | 
| [MediaStreamType](#mediastreamtype) { MEDIA_STREAM_TYPE_VIDEO = 0,<br/>MEDIA_STREAM_TYPE_METADATA = 1, MEDIA_STREAM_TYPE_MAKER = 2 } | 相机媒体流类型。 | 
| [EncodeType](#encodetype) : ohos.hdi.camera.v1_0.EncodeType { ENCODE_TYPE_HEIC = 4 } | 流数据的编码类型。 | 
| [StreamError](#streamerror) : ohos.hdi.camera.v1_0.StreamError { HIGH_TEMPERATURE_ERROR = 2 } | 流错误类型，用于流错误类型**[CaptureErrorInfo](_capture_ended_info_v10.md)**。 | 


## 枚举类型说明


### EncodeType

```
enum EncodeType : ohos.hdi.camera.v1_0.EncodeType
```

**描述**

流数据的编码类型。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| ENCODE_TYPE_HEIC | HEIC编码格式。 | 


### ErrorType

```
enum ErrorType : ohos.hdi.camera.v1_0.ErrorType
```

**描述**

设备错误类型，用于设备错误回调**[OnError()](interface_i_video_process_callback_v13.md#onerror)**。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_DATA_ERROR | 传感器数据错误。<br/>**起始版本：**5.0 | 


### ExecutionMode

```
enum ExecutionMode : ohos.hdi.camera.v1_2.ExecutionMode
```

**描述**

执行模式的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| DEFAULT | 默认模式。 | 


### ExtendedStreamInfoType

```
enum ExtendedStreamInfoType : ohos.hdi.camera.v1_2.ExtendedStreamInfoType_V1_2
```

**描述**

扩展流信息的类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| EXTENDED_STREAM_INFO_RAW | raw图的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_DEPTH | 深度流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_META | meta流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_SECURE | 安全流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_MAKER_INFO | 维测流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_EXIF | exif流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_GAINMAP | 高显图的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_UNREFOCUS | unrefocus流的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_LINEAR | 线型图的的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_FRAGMENT | 水平裁切图的扩展流信息。<br/>**起始版本：**5.0 | 
| EXTENDED_STREAM_INFO_UV | uv附图的扩展流信息。<br/>**起始版本：**5.0 | 


### MediaStreamType

```
enum MediaStreamType
```

**描述**

相机媒体流类型。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_STREAM_TYPE_VIDEO | 视频媒体流。<br/>**起始版本：**5.0 | 
| MEDIA_STREAM_TYPE_METADATA | metadata媒体流。<br/>**起始版本：**5.0 | 
| MEDIA_STREAM_TYPE_MAKER | 维测媒体流。<br/>**起始版本：**5.0 | 


### OperationMode

```
enum OperationMode : ohos.hdi.camera.v1_2.OperationMode_V1_2
```

**描述**

流使用模式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PROFESSIONAL_V1_3 | 专业模式，专用于专业拍照场景。<br/>**起始版本：**4.1 | 
| PROFESSIONAL_PHOTO | 专业拍照模式，专用于专业拍照场景。<br/>**起始版本：**5.0 | 
| PROFESSIONAL_VIDEO | 专业录像模式，专用于专业录像场景。<br/>**起始版本：**5.0 | 
| HIGH_FRAME_RATE | 慢动作模式，专门用于视频录制慢动作。<br/>**起始版本：**5.0 | 
| HIGH_RESOLUTION_PHOTO | 高分辨率照片模式，专门用于捕捉记录高像素。<br/>**起始版本：**5.0 | 
| SECURE | 安全模式，专用于安全模式。<br/>**起始版本：**5.0 | 
| QUICK_SHOT_PHOTO | 闪拍模式，专为快速拍照模式设计。<br/>**起始版本：**5.0 | 
| LIGHT_PAINTING | 流光快门模式，专用于光绘模式。<br/>**起始版本：**5.0 | 
| PANORAMA_PHOTO | 全景模式，专用于全景模式。<br/>**起始版本：**5.0 | 
| TIMELAPSE_PHOTO | 延时摄影模式，专用于延时摄影模式。<br/>**起始版本：**5.0 | 
| APERTURE_VIDEO | 大光圈模式，专用于大光圈模式。<br/>**起始版本：**5.0 | 
| FLUORESCENCE_PHOTO | 荧光拍照模式，专用于荧光拍照模式。<br/>**起始版本：**5.0 | 
| SUN_BLOCK | 防晒检测模式，专用于防晒检测模式。<br/>**起始版本：**5.0 | 


### StreamError

```
enum StreamError : ohos.hdi.camera.v1_0.StreamError
```

**描述**

流错误类型，用于流错误类型**[CaptureErrorInfo](_capture_error_info_v10.md)**。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HIGH_TEMPERATURE_ERROR | 当传感器温度高于阈值，cameraHal将会停止上报画中画流并且通过OnCaptureError回调上报高温错误码。<br/>**起始版本：**5.0 | 


### StreamType

```
enum StreamType
```

**描述**

流类型。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| STREAM_TYPE_PREVIEW | 流数据用于显示，即预览流。 | 
| STREAM_TYPE_VIDEO | 数据用于编码生成录像，即录像流。 | 
| STREAM_TYPE_STILL_CAPTURE | 流数据用于编码生成照片，即拍照流。 | 
| STREAM_TYPE_POST_VIEW | 流数据用于保存缩略图。 | 
| STREAM_TYPE_ANALYZE | 流数据用于图像分析。 | 
| STREAM_TYPE_CUSTOM | 自定义类型。 | 
| STREAM_TYPE_DEPTH | 深度流类型。 | 
