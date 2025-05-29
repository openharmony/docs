# Types.idl


## 概述

Camera模块HDI接口使用的数据类型。

模块包路径：ohos.hdi.camera.v1_3

引用

- ohos.hdi.camera.v1_0.Types

- ohos.hdi.camera.v1_2.Types

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CameraDeviceResourceCost](_camera_device_resource_cost_v13.md) | 相机设备资源开销，用于**ICameraDevice::[GetResourceCost()](interface_i_camera_host_v13.md#getresourcecost)**。 | 
| struct&nbsp;&nbsp;[StreamDescription](_stream_description_v13.md) | 流描述信息，使用于[IVideoProcessSession::Prepare](interface_i_video_process_session_v13.md#prepare)。 | 
| struct&nbsp;&nbsp;[CaptureEndedInfoExt](_capture_ended_info_ext_v13.md) | 拍照结束信息，使用于[IStreamOperatorCallback::OnCaptureEndedExt](interface_i_stream_operator_callback_v13.md#oncaptureendedext)。 | 
| struct&nbsp;&nbsp;[ImageBufferInfoExt](_image_buffer_info_ext_v13.md) | 图片流信息，使用于[IImageProcessCallback::OnProcessDoneExt](interface_i_image_process_callback_v13.md#onprocessdoneext)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OperationMode](_camera_v13.md#operationmode) : ohos.hdi.camera.v1_2.OperationMode_V1_2 {<br/>[PROFESSIONAL_V1_3](_camera_v13.md) = PROFESSIONAL, [PROFESSIONAL_PHOTO](_camera_v13.md) = 11, [PROFESSIONAL_VIDEO](_camera_v13.md) = 12, [HIGH_FRAME_RATE](_camera_v13.md) = 13,[HIGH_RESOLUTION_PHOTO](_camera_v13.md) = 14, [SECURE](_camera_v13.md) = 15, [QUICK_SHOT_PHOTO](_camera_v13.md) = 16, [LIGHT_PAINTING](_camera_v13.md) = 17,[PANORAMA_PHOTO](_camera_v13.md) = 18, [TIMELAPSE_PHOTO](_camera_v13.md) = 19, [APERTURE_VIDEO](_camera_v13.md) = 20, [FLUORESCENCE_PHOTO](_camera_v13.md) = 21,<br/>[SUN_BLOCK](_camera_v13.md) = 22} | 流使用模式。 | 
| [ExtendedStreamInfoType](_camera_v13.md#extendedstreaminfotype) : ohos.hdi.camera.v1_2.ExtendedStreamInfoType_V1_2 {<br/>[EXTENDED_STREAM_INFO_RAW](_camera_v13.md) = 2, [EXTENDED_STREAM_INFO_DEPTH](_camera_v13.md) = 3, [EXTENDED_STREAM_INFO_META](_camera_v13.md) = 4, [EXTENDED_STREAM_INFO_SECURE](_camera_v13.md) = 5,<br/>[EXTENDED_STREAM_INFO_MAKER_INFO](_camera_v13.md) = 6, [EXTENDED_STREAM_INFO_EXIF](_camera_v13.md) = 7, [EXTENDED_STREAM_INFO_GAINMAP](_camera_v13.md) = 8, [EXTENDED_STREAM_INFO_UNREFOCUS](_camera_v13.md) = 9,<br/>[EXTENDED_STREAM_INFO_LINEAR](_camera_v13.md) = 10, [EXTENDED_STREAM_INFO_FRAGMENT](_camera_v13.md) =11, [EXTENDED_STREAM_INFO_UV](_camera_v13.md) = 12} | 扩展流信息的类型。 | 
| [StreamType](_camera_v13.md#streamtype) {<br/>[STREAM_TYPE_PREVIEW](_camera_v13.md) = 0, [STREAM_TYPE_VIDEO](_camera_v13.md) = 1, [STREAM_TYPE_STILL_CAPTURE](_camera_v13.md) = 2, [STREAM_TYPE_POST_VIEW](_camera_v13.md) = 3,<br/>[STREAM_TYPE_ANALYZE](_camera_v13.md) = 4, [STREAM_TYPE_CUSTOM](_camera_v13.md) = 5, [STREAM_TYPE_DEPTH](_camera_v13.md) = 6} | 流类型。 | 
| [ExecutionMode](_camera_v13.md#executionmode) : ohos.hdi.camera.v1_2.ExecutionMode { [DEFAULT](_camera_v13.md) = 3 } | 执行模式的类型。 | 
| [ErrorType](_camera_v13.md#errortype) : ohos.hdi.camera.v1_0.ErrorType { [SENSOR_DATA_ERROR](_camera_v13.md) = 5 } | 设备错误类型，用于设备错误回调**[OnError()](interface_i_video_process_callback_v13.md#onerror)**。 | 
| [MediaStreamType](_camera_v13.md#mediastreamtype) { [MEDIA_STREAM_TYPE_VIDEO](_camera_v13.md) = 0, [MEDIA_STREAM_TYPE_METADATA](_camera_v13.md) = 1, [MEDIA_STREAM_TYPE_MAKER](_camera_v13.md) = 2 } | 相机媒体流类型。 | 
| [EncodeType](_camera_v13.md#encodetype) : ohos.hdi.camera.v1_0.EncodeType { [ENCODE_TYPE_HEIC](_camera_v13.md) = 4 } | 流数据的编码类型。 | 
| [StreamError](_camera_v13.md#streamerror) : ohos.hdi.camera.v1_0.StreamError { [HIGH_TEMPERATURE_ERROR](_camera_v13.md) = 2 } | 流错误类型，用于流错误类型**[CaptureErrorInfo](_capture_error_info_v10.md)**。 | 
