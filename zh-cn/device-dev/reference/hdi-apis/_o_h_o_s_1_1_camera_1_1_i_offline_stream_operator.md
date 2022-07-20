# OHOS::Camera::IOfflineStreamOperator


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.OfflineStreamOperator") | IPC通信token校验。 | 
| [CancelCapture](_camera.md#cancelcapture-12)&nbsp;(int&nbsp;captureId)=0 | 取消捕获请求。&nbsp;[更多...](_camera.md#cancelcapture-12) | 
| [ReleaseStreams](_camera.md#releasestreams-12)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int&nbsp;&gt;&nbsp;&amp;streamIds)=0 | 释放离线流。&nbsp;[更多...](_camera.md#releasestreams-12) | 
| [Release](_camera.md#release)&nbsp;()=0 | 释放所有离线流。&nbsp;[更多...](_camera.md#release) | 


## **详细描述**

离线流的操作类。
