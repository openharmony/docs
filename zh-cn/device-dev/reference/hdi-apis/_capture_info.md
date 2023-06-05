# CaptureInfo


## 概述

捕获请求的相关信息。

**相关模块:**

[Camera](_camera.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [streamIds_](#streamids_) | int[]<br/>捕获的流ID集合。 | 
| [captureSetting_](#capturesetting_) | unsigned&nbsp;char[]<br/>捕获的配置信息。 | 
| [enableShutterCallback_](#enableshuttercallback_) | boolean<br/>使能捕获回调，每一次捕获后都会触发[OnFrameShutter](interface_i_stream_operator_callback.md#onframeshutter)。 | 


## 类成员变量说明


### captureSetting_

  
```
unsigned char [] CaptureInfo::captureSetting_
```

**描述:**

捕获的配置信息。


### enableShutterCallback_

  
```
boolean CaptureInfo::enableShutterCallback_
```

**描述:**

使能捕获回调，每一次捕获后都会触发[OnFrameShutter](interface_i_stream_operator_callback.md#onframeshutter)。


### streamIds_

  
```
int [] CaptureInfo::streamIds_
```

**描述:**

捕获的流ID集合。
