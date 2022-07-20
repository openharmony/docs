# OHOS::Camera::IStreamOperator


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.StreamOperator") | IPC通信token校验。 | 
| [IsStreamsSupported](_camera.md#isstreamssupported)&nbsp;([OperationMode](_camera.md#operationmode)&nbsp;mode,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;modeSetting,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)&nbsp;&gt;&gt;&nbsp;&amp;info,&nbsp;[StreamSupportType](_camera.md#streamsupporttype)&nbsp;&amp;type)=0 | 查询是否支持添加参数对应的流&nbsp;[更多...](_camera.md#isstreamssupported) | 
| [CreateStreams](_camera.md#createstreams)&nbsp;(const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md)&nbsp;&gt;&gt;&nbsp;&amp;streamInfos)=0 | 创建流。&nbsp;[更多...](_camera.md#createstreams) | 
| [ReleaseStreams](_camera.md#releasestreams-22)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 释放流。&nbsp;[更多...](_camera.md#releasestreams-22) | 
| [CommitStreams](_camera.md#commitstreams)&nbsp;([OperationMode](_camera.md#operationmode)&nbsp;mode,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;modeSetting)=0 | 配置流。&nbsp;[更多...](_camera.md#commitstreams) | 
| [GetStreamAttributes](_camera.md#getstreamattributes)&nbsp;(std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[StreamAttribute](_o_h_o_s_1_1_camera_1_1_stream_attribute.md)&nbsp;&gt;&gt;&nbsp;&amp;attributes)=0 | 获取流的属性。&nbsp;[更多...](_camera.md#getstreamattributes) | 
| [AttachBufferQueue](_camera.md#attachbufferqueue)&nbsp;(int&nbsp;streamId,&nbsp;const&nbsp;OHOS::sptr&lt;&nbsp;OHOS::IBufferProducer&nbsp;&gt;&nbsp;&amp;producer)=0 | 绑定生产者句柄和指定流。&nbsp;[更多...](_camera.md#attachbufferqueue) | 
| [DetachBufferQueue](_camera.md#detachbufferqueue)&nbsp;(int&nbsp;streamId)=0 | 解除生产者句柄和指定流的绑定关系。&nbsp;[更多...](_camera.md#detachbufferqueue) | 
| [Capture](_camera.md#capture)&nbsp;(int&nbsp;captureId,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;[CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md)&nbsp;&gt;&nbsp;&amp;info,&nbsp;bool&nbsp;isStreaming)=0 | 捕获图像。&nbsp;[更多...](_camera.md#capture) | 
| [CancelCapture](_camera.md#cancelcapture-22)&nbsp;(int&nbsp;captureId)=0 | 取消捕获。&nbsp;[更多...](_camera.md#cancelcapture-22) | 
| [ChangeToOfflineStream](_camera.md#changetoofflinestream)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds,&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[IOfflineStreamOperator](_o_h_o_s_1_1_camera_1_1_i_offline_stream_operator.md)&nbsp;&gt;&nbsp;&amp;offlineOperator)=0 | 将指定流转换成离线流。&nbsp;[更多...](_camera.md#changetoofflinestream) | 


## **详细描述**

流的操作类。
