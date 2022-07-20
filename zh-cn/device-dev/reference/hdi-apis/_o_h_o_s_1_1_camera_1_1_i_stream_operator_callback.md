# OHOS::Camera::IStreamOperatorCallback


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.StreamOperatorCallback") | IPC通信token校验。 | 
| [OnCaptureStarted](_camera.md#oncapturestarted)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 捕获开始回调，在捕获开始时调用。&nbsp;[更多...](_camera.md#oncapturestarted) | 
| [OnCaptureEnded](_camera.md#oncaptureended)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[CaptureEndedInfo](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md)&nbsp;&gt;&gt;&nbsp;&amp;infos)=0 | 捕获结束回调，在捕获结束时调用。&nbsp;[更多...](_camera.md#oncaptureended) | 
| [OnCaptureError](_camera.md#oncaptureerror)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;std::shared_ptr&lt;&nbsp;[CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md)&nbsp;&gt;&gt;&nbsp;&amp;infos)=0 | 捕获错误回调，在捕获过程中发生错误时调用。&nbsp;[更多...](_camera.md#oncaptureerror) | 
| [OnFrameShutter](_camera.md#onframeshutter)&nbsp;(int32_t&nbsp;captureId,&nbsp;const&nbsp;std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;streamIds,&nbsp;uint64_t&nbsp;timestamp)=0 | 帧捕获回调。&nbsp;[更多...](_camera.md#onframeshutter) | 


## **详细描述**

流的操作回调类。
