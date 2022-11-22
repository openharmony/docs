# ICameraDeviceCallback


## **概述**

定义Camera设备回调操作。

设置回调接口、返回错误信息和相关的metadata的回调。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnError](#onerror)&nbsp;([in]&nbsp;enum&nbsp;[ErrorType](camera.md#errortype)&nbsp;type,&nbsp;[in]&nbsp;int&nbsp;errorCode) | 设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。 | 
| [OnResult](#onresult)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;timestamp,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;result) | 上报Camera设备相关的metadata的回调，上报方式查看[SetResultMode](interface_i_camera_device.md#setresultmode)。 | 


## **成员函数说明**


### OnError()

  
```
ICameraDeviceCallback::OnError ([in] enum ErrorType type, [in] int errorCode )
```

**描述：**

设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| type | 错误类型，具体可参考[ErrorType](camera.md#errortype)。 | 
| errorCode | 错误码，当前暂未使用。 | 


### OnResult()

  
```
ICameraDeviceCallback::OnResult ([in] unsigned long timestamp, [in] unsigned char[] result )
```

**描述：**

上报Camera设备相关的metadata的回调，上报方式查看[SetResultMode](interface_i_camera_device.md#setresultmode)。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| timestamp | metadata上报的时间戳。 | 
| result | 上报的metadata，由[EnableResult](interface_i_camera_device.md#enableresult)指定，&nbsp;可通过[GetEnabledResults](interface_i_camera_device.md#getenabledresults)查询，[DisableResult](interface_i_camera_device.md#disableresult)关闭上报开关。 | 
