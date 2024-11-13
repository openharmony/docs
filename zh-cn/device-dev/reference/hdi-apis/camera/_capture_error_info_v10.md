# CaptureErrorInfo


## 概述

流错误信息，用于回调[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流Id。 | 
| enum [StreamError](_camera_v10.md#streamerror)[error_](#error_) | 错误类型。 | 


## 类成员变量说明


### error_

```
enum StreamError CaptureErrorInfo::error_
```

**描述**

错误类型。


### streamId_

```
int CaptureErrorInfo::streamId_
```

**描述**

流Id。
