# codec_callback_if.h


## **概述**

主要包括回调函数接口定义。

Codec模块事件上报、上报输入buffer和输出buffer处理完毕等接口定义。

**Since**:

3.1

**Version**:

2.0

**相关模块:**

[Codec](codec.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackType](_codec_callback_type.md) | Codec回调接口定义。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackTypeGet](codec.md#codeccallbacktypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecCallbackType对象。 | 
| [CodecCallbackTypeRelease](codec.md#codeccallbacktyperelease)&nbsp;(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*instance) | 释放CodecCallbackType对象。 | 
