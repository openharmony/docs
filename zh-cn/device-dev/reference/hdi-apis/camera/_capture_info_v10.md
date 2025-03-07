# CaptureInfo


## 概述

捕获请求的相关信息。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int[] [streamIds_](#streamids_) | 捕获的流ID集合。 | 
| unsigned char[] [captureSetting_](#capturesetting_) | 捕获的配置信息。 | 
| boolean [enableShutterCallback_](#enableshuttercallback_) | 使能捕获回调，每一次捕获后都会触发[OnFrameShutter](interface_i_stream_operator_callback_v10.md#onframeshutter)。 | 


## 类成员变量说明


### captureSetting_

```
unsigned char [] CaptureInfo::captureSetting_
```

**描述**

捕获的配置信息。


### enableShutterCallback_

```
boolean CaptureInfo::enableShutterCallback_
```

**描述**

使能捕获回调，每一次捕获后都会触发[OnFrameShutter](interface_i_stream_operator_callback_v10.md#onframeshutter)。


### streamIds_

```
int [] CaptureInfo::streamIds_
```

**描述**

捕获的流ID集合。
