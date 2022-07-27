# Camera


## **汇总**


### 文件

| 文件 | 描述 |
| -------- | -------- |
| [icamera_device.h](icamera__device_8h.md) | Camera设备操作接口。 |
| [icamera_device_callback.h](icamera__device__callback_8h.md) | Camera设备的回调接口，主要包含Camera设备发生错误时和上报metadata的回调函数。 |
| [icamera_host.h](icamera__host_8h.md) | Camera服务的管理类，对上层提供HDI接口。 |
| [icamera_host_callback.h](icamera__host__callback_8h.md) | ICameraHost的回调接口，提供Camera设备和闪关灯状态变化的回调函数，回调函数由调用者实现。 |
| [ioffline_stream_operator.h](ioffline__stream__operator_8h.md) | 离线流的操作接口。 |
| [istream_operator.h](istream__operator_8h.md) | 流的操作接口。 |
| [istream_operator_callback.h](istream__operator__callback_8h.md) | [IStreamOperator](istream__operator_8h.md)相关的回调，这些回调均由调用者实现。 |
| [types.h](types_8h.md) | Camera模块HDI接口使用的数据类型。 |


### 类

| 类 | 描述 |
| -------- | -------- |
| [OHOS::Camera::ICameraDevice](_o_h_o_s_1_1_camera_1_1_i_camera_device.md) | Camera设备操作。[更多...](_o_h_o_s_1_1_camera_1_1_i_camera_device.md) |
| [OHOS::Camera::ICameraDeviceCallback](_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md) | Camera设备操作回调。[更多...](_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md) |
| [OHOS::Camera::ICameraHost](_o_h_o_s_1_1_camera_1_1_i_camera_host.md) | Camera服务的管理类。[更多...](_o_h_o_s_1_1_camera_1_1_i_camera_host.md) |
| [OHOS::Camera::ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md) | Camera服务的管理回调。[更多...](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md) |
| [OHOS::Camera::IOfflineStreamOperator](_o_h_o_s_1_1_camera_1_1_i_offline_stream_operator.md) | 离线流的操作类。[更多...](_o_h_o_s_1_1_camera_1_1_i_offline_stream_operator.md) |
| [OHOS::Camera::IStreamOperator](_o_h_o_s_1_1_camera_1_1_i_stream_operator.md) | 流的操作类。[更多...](_o_h_o_s_1_1_camera_1_1_i_stream_operator.md) |
| [OHOS::Camera::IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md) | 流的操作回调类。[更多...](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md) |
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

| 枚举 | 描述 |
| -------- | -------- |
| [OHOS::Camera::CamRetCode](#camretcode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;OHOS::Camera::NO_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::CAMERA_BUSY&nbsp;=&nbsp;-1,&nbsp;OHOS::Camera::INSUFFICIENT_RESOURCES&nbsp;=&nbsp;-2,&nbsp;OHOS::Camera::INVALID_ARGUMENT&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;OHOS::Camera::METHOD_NOT_SUPPORTED&nbsp;=&nbsp;-4,&nbsp;OHOS::Camera::CAMERA_CLOSED&nbsp;=&nbsp;-5,&nbsp;OHOS::Camera::DEVICE_ERROR&nbsp;=&nbsp;-6&nbsp;} | HDI接口的返回值。&nbsp;[更多...](#camretcode) |
| [OHOS::Camera::ResultCallbackMode](#resultcallbackmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::PER_FRAME,&nbsp;OHOS::Camera::ON_CHANGED&nbsp;} | metadata的上报模式。&nbsp;[更多...](#resultcallbackmode) |
| [OHOS::Camera::OperationMode](#operationmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::NORMAL&nbsp;=&nbsp;0&nbsp;} | 流的使用模式。&nbsp;[更多...](#operationmode) |
| [OHOS::Camera::StreamIntent](#streamintent)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;OHOS::Camera::PREVIEW&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::VIDEO&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::STILL_CAPTURE&nbsp;=&nbsp;2,&nbsp;OHOS::Camera::POST_VIEW&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;OHOS::Camera::ANALYZE&nbsp;=&nbsp;4,&nbsp;OHOS::Camera::CUSTOM&nbsp;=&nbsp;5&nbsp;} | 流的类型。&nbsp;[更多...](#streamintent) |
| [OHOS::Camera::EncodeType](#encodetype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::ENCODE_TYPE_NULL&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::ENCODE_TYPE_H264&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::ENCODE_TYPE_H265&nbsp;=&nbsp;2,&nbsp;OHOS::Camera::ENCODE_TYPE_JPEG&nbsp;=&nbsp;3&nbsp;} | 流数据的编码类型。&nbsp;[更多...](#encodetype) |
| [OHOS::Camera::StreamSupportType](#streamsupporttype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;OHOS::Camera::DYNAMIC_SUPPORTED,&nbsp;OHOS::Camera::RE_CONFIGURED_REQUIRED,&nbsp;OHOS::Camera::NOT_SUPPORTED&nbsp;} | 动态配置流的切换方式，使用场景参考&nbsp;[IsStreamsSupported](#isstreamssupported)&nbsp;。&nbsp;[更多...](#streamsupporttype) |
| [OHOS::Camera::CameraStatus](#camerastatus)&nbsp;{&nbsp;OHOS::Camera::UN_AVAILABLE&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::AVAILABLE&nbsp;=&nbsp;1&nbsp;} | Camera设备状态。&nbsp;[更多...](#camerastatus) |
| [OHOS::Camera::FlashlightStatus](#flashlightstatus)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::FLASHLIGHT_OFF&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::FLASHLIGHT_ON&nbsp;=&nbsp;1,&nbsp;OHOS::Camera::FLASHLIGHT_UNAVAILABLE&nbsp;=&nbsp;2&nbsp;} | 闪光灯状态。&nbsp;[更多...](#flashlightstatus) |
| [OHOS::Camera::CameraEvent](#cameraevent):&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::CAMERA_EVENT_DEVICE_ADD&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::CAMERA_EVENT_DEVICE_RMV&nbsp;=&nbsp;1&nbsp;} | Camera事件。&nbsp;[更多...](#cameraevent) |
| [OHOS::Camera::ErrorType](#errortype)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;OHOS::Camera::FATAL_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::REQUEST_TIMEOUT&nbsp;=&nbsp;1&nbsp;} | 设备错误类型，用于设备错误回调&nbsp;[OnError](#onerror)。&nbsp;[更多...](#errortype) |
| [OHOS::Camera::StreamError](#streamerror)&nbsp;{&nbsp;OHOS::Camera::UNKNOWN_ERROR&nbsp;=&nbsp;0,&nbsp;OHOS::Camera::BUFFER_LOST&nbsp;=&nbsp;1&nbsp;} | 流错误类型，用于流错误类型&nbsp;[CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md)。&nbsp;[更多...](#streamerror) |


### 函数

| 函数 | 描述 |
| -------- | -------- |
| **OHOS::Camera::ICameraDevice::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.Device") | IPC通信token校验。 |
| [OHOS::Camera::ICameraDevice::GetStreamOperator](#getstreamoperator)&nbsp;(const&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperator](_o_h_o_s_1_1_camera_1_1_i_stream_operator.md)&nbsp;&gt;&nbsp;&amp;streamOperator)=0 | 获取流操作句柄。&nbsp;[更多...](#getstreamoperator) |
| [OHOS::Camera::ICameraDevice::UpdateSettings](#updatesettings)&nbsp;(const&nbsp;std::shared_ptr&lt;&nbsp;CameraSetting&nbsp;&gt;&nbsp;&amp;settings)=0 | 更新设备控制参数。&nbsp;[更多...](#updatesettings) |
| [OHOS::Camera::ICameraDevice::SetResultMode](#setresultmode)&nbsp;(const&nbsp;[ResultCallbackMode](#resultcallbackmode)&nbsp;&amp;mode)=0 | 设置metadata上报模式，逐帧上报还是设备状态变化时上报。&nbsp;[更多...](#setresultmode) |
| [OHOS::Camera::ICameraDevice::GetEnabledResults](#getenabledresults)&nbsp;(std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 查询使能的metadata。&nbsp;[更多...](#getenabledresults) |
| [OHOS::Camera::ICameraDevice::EnableResult](#enableresult)&nbsp;(const&nbsp;std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 打开metadata上报开关。&nbsp;[更多...](#enableresult) |
| [OHOS::Camera::ICameraDevice::DisableResult](#disableresult)&nbsp;(const&nbsp;std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 关闭metadata上报开关。&nbsp;[更多...](#disableresult) |
| [OHOS::Camera::ICameraDevice::Close](#close)&nbsp;()=0 | 关闭Camera设备。&nbsp;[更多...](#close) |
| **OHOS::Camera::ICameraDeviceCallback::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.DeviceCallback") | IPC通信token校验。 |
| [OHOS::Camera::ICameraDeviceCallback::OnError](#onerror)&nbsp;([ErrorType](#errortype)&nbsp;type,&nbsp;int32_t&nbsp;errorCode)=0 | 设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。&nbsp;[更多...](#onerror) |
| [OHOS::Camera::ICameraDeviceCallback::OnResult](#onresult)&nbsp;(uint64_t&nbsp;timestamp,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;result)=0 | 上报Camera设备相关的metadata的回调，上报方式查看&nbsp;[SetResultMode](#setresultmode)。&nbsp;[更多...](#onresult) |
| **OHOS::Camera::ICameraHost::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.Host") | IPC通信token校验。 |
| [OHOS::Camera::ICameraHost::Get](#get)&nbsp;(const&nbsp;char&nbsp;\*serviceName) | 获取ICameraHost实例。&nbsp;[更多...](#get) |
| [OHOS::Camera::ICameraHost::SetCallback](#setcallback)&nbsp;(const&nbsp;OHOS::sptr&lt;&nbsp;[ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md)&nbsp;&gt;&nbsp;&amp;callback)=0 | 设置ICameraHost回调接口，回调函数参考&nbsp;[ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md)。&nbsp;[更多...](#setcallback) |
| [OHOS::Camera::ICameraHost::GetCameraIds](#getcameraids)&nbsp;(std::vector&lt;&nbsp;std::string&nbsp;&gt;&nbsp;&amp;cameraIds)=0 | 获取当前可用的Camera设备ID列表。&nbsp;[更多...](#getcameraids) |
| [OHOS::Camera::ICameraHost::GetCameraAbility](#getcameraability)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;std::shared_ptr&lt;&nbsp;CameraAbility&nbsp;&gt;&nbsp;&amp;ability)=0 | 获取Camera设备能力集合。&nbsp;[更多...](#getcameraability) |
| [OHOS::Camera::ICameraHost::OpenCamera](#opencamera)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;const&nbsp;OHOS::sptr&lt;&nbsp;[ICameraDeviceCallback](_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[ICameraDevice](_o_h_o_s_1_1_camera_1_1_i_camera_device.md)&nbsp;&gt;&nbsp;&amp;device)=0 | 打开Camera设备。&nbsp;[更多...](#opencamera) |
| [OHOS::Camera::ICameraHost::SetFlashlight](#setflashlight)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;bool&nbsp;&amp;isEnable)=0 | 打开或关闭闪光灯。&nbsp;[更多...](#setflashlight) |
| **OHOS::Camera::ICameraHostCallback::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.HostCallback") | IPC通信token校验。 |
| [OHOS::Camera::ICameraHostCallback::OnCameraStatus](#oncamerastatus)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[CameraStatus](#camerastatus)&nbsp;status)=0 | 用于Camera设备状态变化时上报状态信息给调用者。&nbsp;[更多...](#oncamerastatus) |
| [OHOS::Camera::ICameraHostCallback::OnFlashlightStatus](#onflashlightstatus)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[FlashlightStatus](#flashlightstatus)&nbsp;status)=0 | 用于在闪光灯状态变化时上报状态信息给调用者。&nbsp;[更多...](#onflashlightstatus) |
| [OHOS::Camera::ICameraHostCallback::OnCameraEvent](#oncameraevent)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;[CameraEvent](#cameraevent)&nbsp;event)=0 | 在相机事件发生时调用。&nbsp;[更多...](#oncameraevent) |
| **OHOS::Camera::IOfflineStreamOperator::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.OfflineStreamOperator") | IPC通信token校验。 |
| [OHOS::Camera::IOfflineStreamOperator::CancelCapture](#cancelcapture-12)&nbsp;(int&nbsp;captureId)=0 | 取消捕获请求。&nbsp;[更多...](#cancelcapture-12) |
| [OHOS::Camera::IOfflineStreamOperator::ReleaseStreams](#releasestreams-12)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 释放离线流。&nbsp;[更多...](#releasestreams-12) |
| [OHOS::Camera::IOfflineStreamOperator::Release](#release)&nbsp;()=0 | 释放所有离线流。&nbsp;[更多...](#release) |
| **OHOS::Camera::IStreamOperator::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.StreamOperator") | IPC通信token校验。 |
| [OHOS::Camera::IStreamOperator::IsStreamsSupported](#isstreamssupported)&nbsp;([OperationMode](#operationmode)&nbsp;mode,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;modeSetting,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)&nbsp;&gt;&gt;&nbsp;&amp;info,&nbsp;[StreamSupportType](#streamsupporttype)&nbsp;&amp;type)=0 | 查询是否支持添加参数对应的流&nbsp;[更多...](#isstreamssupported) |
| [OHOS::Camera::IStreamOperator::CreateStreams](#createstreams)&nbsp;(const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)&nbsp;&gt;&gt;&nbsp;&amp;streamInfos)=0 | 创建流。&nbsp;[更多...](#createstreams) |
| [OHOS::Camera::IStreamOperator::ReleaseStreams](#releasestreams-22)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 释放流。&nbsp;[更多...](#releasestreams-22) |
| [OHOS::Camera::IStreamOperator::CommitStreams](#commitstreams)&nbsp;([OperationMode](#operationmode)&nbsp;mode,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;modeSetting)=0 | 配置流。&nbsp;[更多...](#commitstreams) |
| [OHOS::Camera::IStreamOperator::GetStreamAttributes](#getstreamattributes)&nbsp;(std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamAttribute](_o_h_o_s_1_1_camera_1_1_stream_attribute.md)&nbsp;&gt;&gt;&nbsp;&amp;attributes)=0 | 获取流的属性。&nbsp;[更多...](#getstreamattributes) |
| [OHOS::Camera::IStreamOperator::AttachBufferQueue](#attachbufferqueue)&nbsp;(int&nbsp;streamId,&nbsp;const&nbsp;OHOS::sptr&lt;&nbsp;OHOS::IBufferProducer&nbsp;&gt;&nbsp;&amp;producer)=0 | 绑定生产者句柄和指定流。&nbsp;[更多...](#attachbufferqueue) |
| [OHOS::Camera::IStreamOperator::DetachBufferQueue](#detachbufferqueue)&nbsp;(int&nbsp;streamId)=0 | 解除生产者句柄和指定流的绑定关系。&nbsp;[更多...](#detachbufferqueue) |
| [OHOS::Camera::IStreamOperator::Capture](#capture)&nbsp;(int&nbsp;captureId,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;[CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md)&nbsp;&gt;&nbsp;&amp;info,&nbsp;bool&nbsp;isStreaming)=0 | 捕获图像。&nbsp;[更多...](#capture) |
| [OHOS::Camera::IStreamOperator::CancelCapture](#cancelcapture-22)&nbsp;(int&nbsp;captureId)=0 | 取消捕获。&nbsp;[更多...](#cancelcapture-22) |
| [OHOS::Camera::IStreamOperator::ChangeToOfflineStream](#changetoofflinestream)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds,&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[IOfflineStreamOperator](_o_h_o_s_1_1_camera_1_1_i_offline_stream_operator.md)&nbsp;&gt;&nbsp;&amp;offlineOperator)=0 | 将指定流转换成离线流。&nbsp;[更多...](#changetoofflinestream) |
| **OHOS::Camera::IStreamOperatorCallback::DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.StreamOperatorCallback") | IPC通信token校验。 |
| [OHOS::Camera::IStreamOperatorCallback::OnCaptureStarted](#oncapturestarted)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 捕获开始回调，在捕获开始时调用。&nbsp;[更多...](#oncapturestarted) |
| [OHOS::Camera::IStreamOperatorCallback::OnCaptureEnded](#oncaptureended)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[CaptureEndedInfo](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md)&nbsp;&gt;&gt;&nbsp;&amp;infos)=0 | 捕获结束回调，在捕获结束时调用。&nbsp;[更多...](#oncaptureended) |
| [OHOS::Camera::IStreamOperatorCallback::OnCaptureError](#oncaptureerror)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md)&nbsp;&gt;&gt;&nbsp;&amp;infos)=0 | 捕获错误回调，在捕获过程中发生错误时调用。&nbsp;[更多...](#oncaptureerror) |
| [OHOS::Camera::IStreamOperatorCallback::OnFrameShutter](#onframeshutter)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;streamIds,&nbsp;uint64_t&nbsp;timestamp)=0 | 帧捕获回调。&nbsp;[更多...](#onframeshutter) |


### 变量

| 变量 | 描述 |
| -------- | -------- |
| [OHOS::Camera::StreamInfo::streamId_](#streamid-14) | 流的ID，用于在设备内唯一标识一条流。 |
| [OHOS::Camera::StreamInfo::width_](#width-12) | 图像宽度。 |
| [OHOS::Camera::StreamInfo::height_](#height-12) | 图像高度。 |
| [OHOS::Camera::StreamInfo::format_](#format) | 图像格式。 |
| [OHOS::Camera::StreamInfo::dataspace_](#dataspace) | 图像颜色空间。 |
| [OHOS::Camera::StreamInfo::intent_](#intent) | 流类型。 |
| [OHOS::Camera::StreamInfo::tunneledMode_](#tunneledmode) | 隧道模式，值为true时开启，false关闭。 |
| [OHOS::Camera::StreamInfo::bufferQueue_](#bufferqueue) | 图形提供的生产者句柄。 |
| [OHOS::Camera::StreamInfo::minFrameDuration_](#minframeduration) | 最小帧间隔。 |
| [OHOS::Camera::StreamInfo::encodeType_](#encodetype) | 编码类型。 |
| [OHOS::Camera::StreamAttribute::streamId_](#streamid-24) | 流的ID，用于在设备内唯一标识一条流。 |
| [OHOS::Camera::StreamAttribute::width_](#width-22) | 图像宽度。 |
| [OHOS::Camera::StreamAttribute::height_](#height-22) | 图像高度。 |
| [OHOS::Camera::StreamAttribute::overrideFormat_](#overrideformat) | 重写的图像格式。 |
| [OHOS::Camera::StreamAttribute::overrideDataspace_](#overridedataspace) | 重写的图像颜色空间。 |
| [OHOS::Camera::StreamAttribute::producerUsage_](#producerusage) | 重写后的生产者的使用方式。 |
| [OHOS::Camera::StreamAttribute::producerBufferCount_](#producerbuffercount) | 重写后的生产者缓存数量。 |
| [OHOS::Camera::StreamAttribute::maxBatchCaptureCount_](#maxbatchcapturecount) | 连拍支持的最大捕获帧数量。 |
| [OHOS::Camera::StreamAttribute::maxCaptureCount_](#maxcapturecount) | 最大的并发捕获请求个数，默认为1。 |
| [OHOS::Camera::CaptureInfo::streamIds_](#streamids) | 捕获的流ID集合。 |
| [OHOS::Camera::CaptureInfo::captureSetting_](#capturesetting) | 捕获的配置信息。 |
| [OHOS::Camera::CaptureInfo::enableShutterCallback_](#enableshuttercallback) | 使能捕获回调。 |
| [OHOS::Camera::CaptureEndedInfo::streamId_](#streamid-34) | 捕获的流ID。 |
| [OHOS::Camera::CaptureEndedInfo::frameCount_](#framecount) | 捕获结束时已经抓取的帧数。 |
| [OHOS::Camera::CaptureErrorInfo::streamId_](#streamid-44) | 流ID。 |
| [OHOS::Camera::CaptureErrorInfo::error_](#error) | 错误类型。 |


## **详细描述**

Camera模块接口定义。

Camera模块涉及相机设备的操作、流的操作、离线流的操作和各种回调等。

**Since：**

1.0


## **枚举类型说明**


### CameraEvent


```
enum OHOS::Camera::CameraEvent : uint32_t
```

**描述：**

Camera事件。

| 枚举值 | **描述** |
| -------- | -------- |
| CAMERA_EVENT_DEVICE_ADD | Camera设备增加事件。 |
| CAMERA_EVENT_DEVICE_RMV | Camera设备删除事件。 |


### CameraStatus


```
enum OHOS::Camera::CameraStatus
```

**描述：**

Camera设备状态。

| 枚举值 | **描述** |
| -------- | -------- |
| UN_AVAILABLE | 设备当前不在位或者不可用。 |
| AVAILABLE | 设备当前可用。 |


### CamRetCode


```
enum OHOS::Camera::CamRetCode : int32_t
```

**描述：**

HDI接口的返回值。

| 枚举值 | **描述** |
| -------- | -------- |
| NO_ERROR | 调用成功。 |
| CAMERA_BUSY | 设备当前忙。 |
| INSUFFICIENT_RESOURCES | 资源不足。 |
| INVALID_ARGUMENT | 参数错误。 |
| METHOD_NOT_SUPPORTED | 不支持当前调用方法。 |
| CAMERA_CLOSED | Camera设备已经关闭。 |
| DEVICE_ERROR | 驱动层发生严重错误。 |


### EncodeType


```
enum OHOS::Camera::EncodeType : int32_t
```

**描述：**

流数据的编码类型。

| 枚举值 | **描述** |
| -------- | -------- |
| ENCODE_TYPE_NULL | 未设置编码类型。 |
| ENCODE_TYPE_H264 | 编码类型为H264。 |
| ENCODE_TYPE_H265 | 编码类型为H265。 |
| ENCODE_TYPE_JPEG | 编码类型为JPEG。 |


### ErrorType


```
enum OHOS::Camera::ErrorType : uint32_t
```

**描述：**

设备错误类型，用于设备错误回调 **OnError**。

| 枚举值 | **描述** |
| -------- | -------- |
| FATAL_ERROR | 严重错误，需要关闭Camera设备。 |
| REQUEST_TIMEOUT | 请求超时，需要关闭Camera设备。 |


### FlashlightStatus


```
enum OHOS::Camera::FlashlightStatus : uint32_t
```

**描述：**

闪光灯状态。

| 枚举值 | **描述** |
| -------- | -------- |
| FLASHLIGHT_OFF | 闪光灯关闭。 |
| FLASHLIGHT_ON | 闪光灯开启。 |
| FLASHLIGHT_UNAVAILABLE | 闪光灯当前不可用。 |


### OperationMode


```
enum OHOS::Camera::OperationMode : int32_t
```

**描述：**

流的使用模式。

| 枚举值 | **描述** |
| -------- | -------- |
| NORMAL | 普通模式。 |


### ResultCallbackMode


```
enum OHOS::Camera::ResultCallbackMode : int32_t
```

**描述：**

metadata的上报模式。

| 枚举值 | **描述** |
| -------- | -------- |
| PER_FRAME | 每帧上报。 |
| ON_CHANGED | 设备状态变化时上报。 |


### StreamError


```
enum OHOS::Camera::StreamError
```

**描述：**

流错误类型，用于流错误类型 [CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md)。

| 枚举值 | **描述** |
| -------- | -------- |
| UNKNOWN_ERROR | 流未知错误。 |
| BUFFER_LOST | 丢包。 |


### StreamIntent


```
enum OHOS::Camera::StreamIntent : int32_t
```

**描述：**

流的类型。

| 枚举值 | **描述** |
| -------- | -------- |
| PREVIEW | 流数据用于显示，即预览流。 |
| VIDEO | 流数据用于编码生成录像，即录像流。 |
| STILL_CAPTURE | 流数据用于编码生成照片，即拍照流。 |
| POST_VIEW | 流数据用于保存缩略图。 |
| ANALYZE | 流数据用于图像分析。 |
| CUSTOM | 自定义类型。 |


### StreamSupportType


```
enum OHOS::Camera::StreamSupportType : int32_t
```

**描述：**

动态配置流的切换方式，使用场景参考 [IsStreamsSupported](#isstreamssupported) 。

| 枚举值 | 描述 |
| -------- | -------- |
| DYNAMIC_SUPPORTED | 支持动态配置流，对应的流参数直接生效。 |
| RE_CONFIGURED_REQUIRED | 不支持动态配置流，对应的参数需要停止流然后重新配置流才能生效。 |
| NOT_SUPPORTED | 不支持对应的流参数配置。 |


## **函数说明**


### AttachBufferQueue()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::AttachBufferQueue (int streamId, const OHOS::sptr < OHOS::IBufferProducer > & producer )
```

**描述：**

绑定生产者句柄和指定流。

如果在 [CreateStreams](#createstreams) 创建流时已经指定了生产者句柄，则不需要调用该接口。如果需要重新绑定， 需先调用 [DetachBufferQueue](#detachbufferqueue) 进行解绑，然后再绑定。 对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，那么不需要绑定生产者句柄， 此时在创建流时 [CreateStreams](#createstreams) 的 [StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md) 参数的生产者句柄bufferQueue_为空，而 tunneledMode_需设置为false。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamId | [IN]&nbsp;用于标识要绑定的流。 |
| producer | [IN]&nbsp;生产者句柄。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[DetachBufferQueue](#detachbufferqueue)

**Since：**

1.0

**Version：**

1.0


### CancelCapture() [1/2]


```
virtual CamRetCode OHOS::Camera::IOfflineStreamOperator::CancelCapture (int captureId)
```

**描述：**

取消捕获请求。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;用于标识要取消的捕获请求。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。


### CancelCapture() [2/2]


```
virtual CamRetCode OHOS::Camera::IStreamOperator::CancelCapture (int captureId)
```

**描述：**

取消捕获。

取消连续捕获时会调用 **OnCaptureEnded**。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | 用于标识要取消的捕获请求 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[Capture](#capture)

**Since：**

1.0

**Version：**

1.0


### Capture()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::Capture (int captureId, const std::shared_ptr< CaptureInfo > & info, bool isStreaming )
```

**描述：**

捕获图像。

本接口必须在调用 [CommitStreams](#commitstreams) 配置流之后调用。 图像捕获有两种模式，分别是连续捕获和单次捕获。

- 连续捕获即触发之后模块内部进行连续的捕获， 消费者可以连续收到图像数据，不需要多次调用本接口，若再次调用了本接口， 则停止当前捕获，更新捕获信息，再进行一次新的捕获，多用于预览、录像或者连拍场景。

- 单次捕获即触发之后只捕获一帧图像数据，用于单次拍照场景。 捕获启动时，会调用 **OnCaptureStarted** 来通知调用者捕获已经启动。

连续捕获需调用 [CancelCapture](#cancelcapture-22) 来停止捕获。 捕获结束时，会调用 **OnCaptureEnded** 来通知调用者捕获的帧计数等信息。 [CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md) 的 enableShutterCallback_ 使能 **OnFrameShutter**，使能后每次捕获触发 **OnFrameShutter** 对于多个流同时捕获的场景，本模块内部保证同时上报多路流捕获数据。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;捕获请求的唯一标识，由调用者指定，调用者需保证在Camera设备打开期间，捕获请求ID是唯一的。 |
| info | [IN]&nbsp;捕获请求的参数信息，具体信息查看&nbsp;[CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md)。 |
| isStreaming | [IN]&nbsp;是否连续捕获，true表示连续捕获，否则为单次捕获。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

OnFrameShutter

**Since：**

1.0

**Version：**

1.0


### ChangeToOfflineStream()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::ChangeToOfflineStream (const std::vector< int > & streamIds, OHOS::sptr< IStreamOperatorCallback > & callback, OHOS::sptr< IOfflineStreamOperator > & offlineOperator )
```

**描述：**

将指定流转换成离线流。

离线流只能由拍照流转换而来，其他流不支持。 一些设备处理能力有限，可能导致拍照时算法处理时间较长，从而引起捕获请求堆积在模块内部，而转换为离线 流之后，可关闭底层设备，由离线流接替，进行后续的处理。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamIds | [IN]&nbsp;用于指定要转换成离线流的流集合。 |
| callback | [IN]&nbsp;用于设置离线流的回调。 |
| offlineOperator | [OUT]&nbsp;转换后的离线流。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### Close()


```
virtual void OHOS::Camera::ICameraDevice::Close ()
```

**描述：**

关闭Camera设备。

**参见：**

[OpenCamera](#opencamera)

**Since：**

1.0

**Version：**

1.0


### CommitStreams()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::CommitStreams (OperationMode mode, const std::shared_ptr< CameraMetadata > & modeSetting )
```

**描述：**

配置流。

本接口需在调用 [CreateStreams](#createstreams) 创建流之后调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| mode | [IN]&nbsp;流运行的模式，支持的模式定义在&nbsp;**OperationMode**。 |
| modeSetting | [IN]&nbsp;流的配置参数，包括帧率，ZOOM等信息。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### CreateStreams()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::CreateStreams (const std::vector< std::shared_ptr< StreamInfo >> & streamInfos)
```

**描述：**

创建流。

此函数接口依据输入的流信息创建流，调用该接口之前需先通过 [IsStreamsSupported](#isstreamssupported) 查询HAL是否支持要创建的流。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamInfos | [IN]&nbsp;流信息列表，流信息定义在&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)。输入的流信息可能会被修改，需通过&nbsp;[GetStreamAttributes](#getstreamattributes)&nbsp;获取最新的流属性。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### DetachBufferQueue()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::DetachBufferQueue (int streamId)
```

**描述：**

解除生产者句柄和指定流的绑定关系。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamId | [IN]&nbsp;用于标识要解除绑定的流。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看[CamRetCode](#camretcode)。

**参见：**

[AttachBufferQueue](#attachbufferqueue)

**Since：**

1.0

**Version：**

1.0


### DisableResult()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::DisableResult (const std::vector< MetaType > & results)
```

**描述：**

关闭metadata上报开关。

屏蔽之后，相应的**OnResult**不再上报，需 [EnableResult](#enableresult) 使能之后才上报。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| results | [IN]&nbsp;需要关闭上报开关的metadata。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[EnableResult](#enableresult)

**Since：**

1.0

**Version：**

1.0


### EnableResult()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::EnableResult (const std::vector< MetaType > & results)
```

**描述：**

打开metadata上报开关。

**OnResult** 只上报此接口使能后的metadata。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| results | [IN]&nbsp;需要打开上报开关的metadata。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[DisableResult](#disableresult)

**Since：**

1.0

**Version：**

1.0


### Get()


```
static sptr<ICameraHost> OHOS::Camera::ICameraHost::Get (const char * serviceName)
```

**描述：**

获取ICameraHost实例。

此接口为Camera调用入口，需要先通过该接口获取ICameraHost实例，然后通过ICameraHost实例进行其它操作。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| serviceName | [IN]&nbsp;要获取的ICameraHost实例的名称，当前实现中实例名称固定为camera_service。 |

**返回：**

成功返回ICameraHost实例，失败返回nullptr。

**Since：**

1.0

**Version：**

1.0


### GetCameraAbility()


```
virtual CamRetCode OHOS::Camera::ICameraHost::GetCameraAbility (const std::string & cameraId, std::shared_ptr< CameraAbility > & ability )
```

**描述：**

获取Camera设备能力集合。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | [IN]&nbsp;用于指定要操作的Camera设备，通过&nbsp;[GetCameraIds](#getcameraids)&nbsp;获取。 |
| ability | [OUT]&nbsp;返回cameraId对应Camera设备的能力集合。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[GetCameraIds](#getcameraids)

**Since：**

1.0

**Version：**

1.0


### GetCameraIds()


```
virtual CamRetCode OHOS::Camera::ICameraHost::GetCameraIds (std::vector< std::string > & cameraIds)
```

**描述：**

获取当前可用的Camera设备ID列表。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraIds | [OUT]&nbsp;返回当前可用的设备列表 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[GetCameraAbility](#getcameraability)

**Since：**

1.0

**Version：**

1.0


### GetEnabledResults()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::GetEnabledResults (std::vector< MetaType > & results)
```

**描述：**

查询使能的metadata。

[EnableResult](#enableresult) 使能需要上报的metadata之后，可通过此接口查询使能的metadata。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| results | [OUT]&nbsp;所有使能的metadata。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### GetStreamAttributes()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::GetStreamAttributes (std::vector< std::shared_ptr< StreamAttribute >> & attributes)
```

**描述：**

获取流的属性。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| attributes | [OUT]&nbsp;用于获取流的属性。在调用[CreateStreams](#createstreams)&nbsp;时，通过参数streamInfos携带的流信息可能会被重写，因此通过该接口获取的流属性可能会和&nbsp;[CreateStreams](#createstreams)&nbsp;输入的流信息存在差异。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### GetStreamOperator()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::GetStreamOperator (const OHOS::sptr< IStreamOperatorCallback > & callback, OHOS::sptr< IStreamOperator > & streamOperator )
```

**描述：**

获取流操作句柄。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| callback | [IN]&nbsp;设置流回调接口，详细可查看&nbsp;[IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md)，&nbsp;用于上报捕获开始&nbsp;**OnCaptureStarted**，捕获结束&nbsp;**OnCaptureEnded**，&nbsp;**OnCaptureError**&nbsp;捕获错误等信息。 |
| streamOperator | [OUT]&nbsp;返回流操作句柄。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### IsStreamsSupported()


```
virtual CamRetCode OHOS::Camera::IStreamOperator::IsStreamsSupported (OperationMode mode, const std::shared_ptr< CameraMetadata > & modeSetting, const std::vector< std::shared_ptr< StreamInfo >> & info, StreamSupportType & type )
```

**描述：**

查询是否支持添加参数对应的流。

流是指从底层设备输出，经本模块内部各环节处理，最终传递到上层服务或者应用的一组数据序列 本模块支持的流的类型有预览流，录像流，拍照流等，更多类型可查看 **StreamIntent**。

此函数接口根据输入的运行模式和配置信息以及当前模块中正在运行的流，查询是否支持动态添加流。

- 如果本模块支持在不停止其他流的情况下添加新流，或者即使停止其他流但上层服务或应用不感知，则通过type参数返回DYNAMIC_SUPPORTED，上层服务或应用可以直接添加新流。

- 如果本模块支持添加新流但需要上层服务或应用先停止所有流的捕获，则通过type参数返回RE_CONFIGURED_REQUIRED。

- 如果不支持添加输入的新流，则返回NOT_SUPPORTED。

此函数需要在调用 [CreateStreams](#createstreams) 创建流之前调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| mode | [IN]&nbsp;流运行的模式，支持的模式参考&nbsp;**OperationMode**。 |
| modeSetting | [IN]&nbsp;流的配置，包括帧率，3A等配置信息。 |
| info | [IN]&nbsp;流的配置信息，具体参考&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)。 |
| type | [OUT]&nbsp;对动态配置流的支持类型，支持类型定义在&nbsp;**StreamSupportType**。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### OnCameraEvent()


```
virtual void OHOS::Camera::ICameraHostCallback::OnCameraEvent (const std::string & cameraId, CameraEvent event )
```

**描述：**

在相机事件发生时调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | 表示相机事件绑定的相机ID。 |
| event | 表示相机事件类型。 |

**Since：**

1.0

**Version：**

1.0


### OnCameraStatus()


```
virtual void OHOS::Camera::ICameraHostCallback::OnCameraStatus (const std::string & cameraId, CameraStatus status )
```

**描述：**

用于Camera设备状态变化时上报状态信息给调用者。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | [IN]&nbsp;状态发生变化的Camera设备ID。 |
| status | [IN]&nbsp;最新的设备状态。 |

**Since：**

1.0

**Version：**

1.0


### OnCaptureEnded()


```
virtual void OHOS::Camera::IStreamOperatorCallback::OnCaptureEnded (int32_t captureId, const std::vector< std::shared_ptr< CaptureEndedInfo >> & infos )
```

**描述：**

捕获结束回调，在捕获结束时调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;用于标识回调对应的捕获请求。 |
| infos | [IN]&nbsp;捕获结束相关信息。 |

**参见：**

[OnCaptureStarted](#oncapturestarted)

**Since：**

1.0

**Version：**

1.0


### OnCaptureError()


```
virtual void OHOS::Camera::IStreamOperatorCallback::OnCaptureError (int32_t captureId, const std::vector< std::shared_ptr< CaptureErrorInfo >> & infos )
```

**描述：**

捕获错误回调，在捕获过程中发生错误时调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;用于标识回调对应的捕获请求。 |
| infos | [IN]&nbsp;捕获错误信息列表。 |

**Since：**

1.0

**Version：**

1.0


### OnCaptureStarted()


```
virtual void OHOS::Camera::IStreamOperatorCallback::OnCaptureStarted (int32_t captureId, const std::vector< int32_t > & streamIds )
```

**描述：**

捕获开始回调，在捕获开始时调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;用于标识回调对应的捕获请求。 |
| streamIds | [IN]&nbsp;回调对应的流集合。 |

**参见：**

[OnCaptureEnded](#oncaptureended)

**Since：**

1.0

**Version：**

1.0


### OnError()


```
virtual void OHOS::Camera::ICameraDeviceCallback::OnError (ErrorType type, int32_t errorCode )
```

**描述：**

设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| type | [IN]&nbsp;错误类型，具体错误类型可参考&nbsp;**ErrorType**。 |
| errorCode | [IN]&nbsp;错误码，当前暂未使用。 |

**Since：**

1.0

**Version：**

1.0


### OnFlashlightStatus()


```
virtual void OHOS::Camera::ICameraHostCallback::OnFlashlightStatus (const std::string & cameraId, FlashlightStatus status )
```

**描述：**

用于在闪光灯状态变化时上报状态信息给调用者。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | [IN]&nbsp;状态发生变化的闪关灯所绑定的Camera设备ID。 |
| status | [IN]&nbsp;最新的闪光灯状态。 |

**Since：**

1.0

**Version：**

1.0


### OnFrameShutter()


```
virtual void OHOS::Camera::IStreamOperatorCallback::OnFrameShutter (int32_t captureId, const std::vector< int32_t > & streamIds, uint64_t timestamp )
```

**描述：**

帧捕获回调。

通过 **Capture** 的输入参数 [CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md) 的enableShutterCallback_使能该回调， 使能后每次捕获均会触发此回调。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| captureId | [IN]&nbsp;用于标识回调对应的捕获请求。 |
| streamIds | [IN]&nbsp;回调对应的流集合。 |
| timestamp | [IN]&nbsp;该接口被调用时的时间戳。 |

**参见：**

Capture

**Since：**

1.0

**Version：**

1.0


### OnResult()


```
virtual void OHOS::Camera::ICameraDeviceCallback::OnResult (uint64_t timestamp, const std::shared_ptr< CameraMetadata > & result )
```

**描述：**

上报Camera设备相关的metadata的回调，上报方式查看 [SetResultMode](#setresultmode)。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| timestamp | [IN]&nbsp;metadata上报的时间戳。 |
| result | [IN]&nbsp;上报的metadata，上报的metadata由&nbsp;**EnableResult**&nbsp;指定，&nbsp;可通过&nbsp;**GetEnabledResults**&nbsp;查询，**DisableResult**&nbsp;关闭上报开关。 |

**Since：**

1.0

**Version：**

1.0


### OpenCamera()


```
virtual CamRetCode OHOS::Camera::ICameraHost::OpenCamera (const std::string & cameraId, const OHOS::sptr< ICameraDeviceCallback > & callback, OHOS::sptr< ICameraDevice > & device )
```

**描述：**

打开Camera设备。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice对象，通过ICameraDevice对象可以操作具体的Camera设备。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | [IN]&nbsp;需要打开的Camera设备ID，可通过&nbsp;[GetCameraIds](#getcameraids)&nbsp;接口获取当前已有Camera设备列表。 |
| callback | [IN]&nbsp;Camera设备相关的回调函数，具体参见&nbsp;[ICameraDeviceCallback](_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md)。 |
| device | [OUT]&nbsp;返回当前要打开的Camera设备ID对应的ICameraDevice对象。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[GetCameraIds](#getcameraids)

**Since：**

1.0

**Version：**

1.0


### Release()


```
virtual CamRetCode OHOS::Camera::IOfflineStreamOperator::Release ()
```

**描述：**

释放所有离线流。

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### ReleaseStreams() [1/2]


```
virtual CamRetCode OHOS::Camera::IOfflineStreamOperator::ReleaseStreams (const std::vector< int > & streamIds)
```

**描述：**

释放离线流。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamIds | 用于标识要释放的离线流集合。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### ReleaseStreams() [2/2]


```
virtual CamRetCode OHOS::Camera::IStreamOperator::ReleaseStreams (const std::vector< int > & streamIds)
```

**描述：**

释放流。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| streamIds | [IN]&nbsp;要释放的流ID列表。 |

**返回：**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### SetCallback()


```
virtual CamRetCode OHOS::Camera::ICameraHost::SetCallback (const OHOS::sptr< ICameraHostCallback > & callback)
```

**描述：**

设置ICameraHost回调接口，回调函数参考 [ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md)。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| callback | [IN]&nbsp;要设置的回调函数。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### SetFlashlight()


```
virtual CamRetCode OHOS::Camera::ICameraHost::SetFlashlight (const std::string & cameraId, bool & isEnable )
```

**描述：**

打开或关闭闪光灯。

该接口只能由打开cameraId指定Camera设备的调用者调用。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cameraId | [IN]&nbsp;闪光灯对应的Camera设备ID。 |
| isEnable | [IN]&nbsp;true打开闪光灯，false关闭闪光灯。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**参见：**

[GetCameraIds](#getcameraids)

**Since：**

1.0

**Version：**

1.0


### SetResultMode()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::SetResultMode (const ResultCallbackMode & mode)
```

**描述：**

设置metadata上报模式，逐帧上报还是设备状态变化时上报。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| mode | [IN]&nbsp;metadata的上报模式，逐帧上报或者设备状态变化时上报，查看&nbsp;**ResultCallbackMode**。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


### UpdateSettings()


```
virtual CamRetCode OHOS::Camera::ICameraDevice::UpdateSettings (const std::shared_ptr< CameraSetting > & settings)
```

**描述：**

更新设备控制参数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| settings | [IN]&nbsp;Camera设置参数，包括sensor帧率，3A相关参数等。 |

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看 [CamRetCode](#camretcode)。

**Since：**

1.0

**Version：**

1.0


## **变量说明**


### bufferQueue_


```
OHOS::sptr<OHOS::IBufferProducer> OHOS::Camera::StreamInfo::bufferQueue_
```

**描述：**

图形提供的生产者句柄。


### captureSetting_


```
std::shared_ptr<CameraMetadata> OHOS::Camera::CaptureInfo::captureSetting_
```

**描述：**

捕获的配置信息。


### dataspace_


```
int OHOS::Camera::StreamInfo::dataspace_
```

**描述：**

图像颜色空间。


### enableShutterCallback_


```
bool OHOS::Camera::CaptureInfo::enableShutterCallback_
```

**描述：**

使能捕获回调，每一次捕获后都会触发 **OnFrameShutter**。


### encodeType_


```
EncodeType OHOS::Camera::StreamInfo::encodeType_
```

**描述：**

编码类型。


### error_


```
StreamError OHOS::Camera::CaptureErrorInfo::error_
```

**描述：**

错误类型。


### format_


```
int OHOS::Camera::StreamInfo::format_
```

**描述：**

图像格式。


### frameCount_


```
int OHOS::Camera::CaptureEndedInfo::frameCount_
```

**描述：**

捕获结束时已经抓取的帧数。


### height_ [1/2]


```
int OHOS::Camera::StreamInfo::height_
```

**描述：**

图像高度。


### height_ [2/2]


```
int OHOS::Camera::StreamAttribute::height_
```

**描述：**

图像高度。


### intent_


```
StreamIntent OHOS::Camera::StreamInfo::intent_
```

**描述：**

流类型。


### maxBatchCaptureCount_


```
int OHOS::Camera::StreamAttribute::maxBatchCaptureCount_
```

**描述：**

连拍支持的最大捕获帧数量。


### maxCaptureCount_


```
int OHOS::Camera::StreamAttribute::maxCaptureCount_
```

**描述：**

最大的并发捕获请求个数，默认为1。


### minFrameDuration_


```
int OHOS::Camera::StreamInfo::minFrameDuration_
```

**描述：**

最小帧间隔。


### overrideDataspace_


```
int OHOS::Camera::StreamAttribute::overrideDataspace_
```

**描述：**

重写的图像颜色空间。


### overrideFormat_


```
int OHOS::Camera::StreamAttribute::overrideFormat_
```

**描述：**

重写的图像格式。


### producerBufferCount_


```
int OHOS::Camera::StreamAttribute::producerBufferCount_
```

**描述：**

重写后的生产者缓存数量。


### producerUsage_


```
int OHOS::Camera::StreamAttribute::producerUsage_
```

**描述：**

重写后的生产者的使用方式。


### streamId_ [1/4]


```
int OHOS::Camera::StreamInfo::streamId_
```

**描述：**

流的ID，用于在设备内唯一标识一条流。


### streamId_ [2/4]


```
int OHOS::Camera::StreamAttribute::streamId_
```

**描述：**

流的ID，用于在设备内唯一标识一条流。


### streamId_ [3/4]


```
int OHOS::Camera::CaptureEndedInfo::streamId_
```

**描述：**

捕获的流ID。


### streamId_ [4/4]


```
int OHOS::Camera::CaptureErrorInfo::streamId_
```

**描述：**

流ID。


### streamIds_


```
std::vector<int> OHOS::Camera::CaptureInfo::streamIds_
```

**描述：**

捕获的流ID集合。


### tunneledMode_


```
bool OHOS::Camera::StreamInfo::tunneledMode_
```

**描述：**

隧道模式，值为true时开启，false关闭。

开启隧道模式后，HAL不直接和上层交互，通过图形提供的生产者句柄来传递帧数据， 对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，此时需要关闭隧道模式。


### width_ [1/2]


```
int OHOS::Camera::StreamInfo::width_
```

**描述：**

图像宽度。


### width_ [2/2]


```
int OHOS::Camera::StreamAttribute::width_
```

**描述：**

图像宽度。
