# codec_callback_if.h


## 概述

主要包括回调函数接口定义。

Codec模块事件上报、上报输入buffer和输出buffer处理完毕等接口定义。

**Since:**
3.1
**Version:**
2.0
**相关模块:**

[Codec](_codec.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackType](_codec_callback_type.md) | struct<br/>Codec回调接口定义。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackTypeGet](_codec.md#codeccallbacktypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*<br/>实例化CodecCallbackType对象。&nbsp; | 
| [CodecCallbackTypeRelease](_codec.md#codeccallbacktyperelease)&nbsp;(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*instance) | void<br/>释放CodecCallbackType对象。&nbsp; | 
