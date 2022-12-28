# IStreamOperatorCallback


## **概述**

定义Camera设备流回调操作。

对Camera设备执行流回调的抓捕，结束，错误捕获和帧捕获等操作。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnCaptureStarted](#oncapturestarted)&nbsp;([in]&nbsp;int&nbsp;captureId,&nbsp;[in]&nbsp;int[]&nbsp;streamIds) | 捕获开始回调，在捕获开始时调用。 | 
| [OnCaptureEnded](#oncaptureended)&nbsp;([in]&nbsp;int&nbsp;captureId,&nbsp;[in]&nbsp;struct&nbsp;[CaptureEndedInfo](_capture_ended_info.md)[]&nbsp;infos) | 捕获结束回调，在捕获结束时调用。 | 
| [OnCaptureError](#oncaptureerror)&nbsp;([in]&nbsp;int&nbsp;captureId,&nbsp;[in]&nbsp;struct&nbsp;[CaptureErrorInfo](_capture_error_info.md)[]&nbsp;infos) | 捕获错误回调，在捕获过程中发生错误时调用。 | 
| [OnFrameShutter](#onframeshutter)&nbsp;([in]&nbsp;int&nbsp;captureId,&nbsp;[in]&nbsp;int[]&nbsp;streamIds,&nbsp;[in]&nbsp;unsigned&nbsp;long&nbsp;timestamp) | 帧捕获回调。 | 


## **成员函数说明**


### OnCaptureEnded()

  
```
IStreamOperatorCallback::OnCaptureEnded ([in] int captureId, [in] struct CaptureEndedInfo[] infos )
```

**描述：**

捕获结束回调，在捕获结束时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识回调对应的捕获请求。 | 
| infos | 捕获结束相关信息，具体结束相关信息查看[CaptureEndedInfo](_capture_ended_info.md)。 | 

**参见:**

[OnCaptureStarted](#oncapturestarted)


### OnCaptureError()

  
```
IStreamOperatorCallback::OnCaptureError ([in] int captureId, [in] struct CaptureErrorInfo[] infos )
```

**描述：**

捕获错误回调，在捕获过程中发生错误时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识回调对应的捕获请求。 | 
| infos | 捕获错误信息列表，具体错误信息查看[CaptureErrorInfo](_capture_error_info.md)。 | 


### OnCaptureStarted()

  
```
IStreamOperatorCallback::OnCaptureStarted ([in] int captureId, [in] int[] streamIds )
```

**描述：**

捕获开始回调，在捕获开始时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识回调对应的捕获请求。 | 
| streamIds | 回调对应的流集合。 | 

**参见:**

[OnCaptureEnded](#oncaptureended)


### OnFrameShutter()

  
```
IStreamOperatorCallback::OnFrameShutter ([in] int captureId, [in] int[] streamIds, [in] unsigned long timestamp )
```

**描述：**

帧捕获回调。

通过**Capture**的输入参数[CaptureInfo](_capture_info.md)的enableShutterCallback_使能该回调， 使能后每次捕获均会触发此回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识回调对应的捕获请求。 | 
| streamIds | 回调对应的流集合。 | 
| timestamp | 该接口被调用时的时间戳。 | 

**参见:**

Capture
