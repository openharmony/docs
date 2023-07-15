# CaptureErrorInfo


## 概述

流错误信息，用于回调[OnCaptureError](interface_i_stream_operator_callback.md#oncaptureerror)。

**相关模块:**

[Camera](_camera.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [streamId_](#streamid_) | int<br/>流Id。 | 
| [error_](#error_) | enum&nbsp;[StreamError](_camera.md#streamerror)<br/>错误类型。 | 


## 类成员变量说明


### error_

  
```
enum StreamError CaptureErrorInfo::error_
```

**描述:**

错误类型。


### streamId_

  
```
int CaptureErrorInfo::streamId_
```

**描述:**

流Id。
