# OHOS::Camera::ICameraDeviceCallback


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.DeviceCallback") | IPC通信token校验。 | 
| [OnError](_camera.md#onerror)&nbsp;([ErrorType](_camera.md#errortype)&nbsp;type,&nbsp;int32_t&nbsp;errorCode)=0 | 设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。&nbsp;[更多...](_camera.md#onerror) | 
| [OnResult](_camera.md#onresult)&nbsp;(uint64_t&nbsp;timestamp,&nbsp;const&nbsp;std::shared_ptr&lt;&nbsp;CameraMetadata&nbsp;&gt;&nbsp;&amp;result)=0 | 上报camera设备相关的metadata的回调，上报方式查看&nbsp;[SetResultMode](_camera.md#setresultmode)。&nbsp;[更多...](_camera.md#onresult) | 


## **详细描述**

Camera设备操作回调。
