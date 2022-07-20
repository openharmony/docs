# codec_callback_if.h


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [CodecCallbackType](_codec_callback_type.md) | Codec回调接口定义。&nbsp;[更多...](_codec_callback_type.md) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [CodecCallbackTypeGet](_codec.md#codeccallbacktypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecCallbackType对象。&nbsp;[更多...](_codec.md#codeccallbacktypeget) | 
| [CodecCallbackTypeRelease](_codec.md#codeccallbacktyperelease)&nbsp;(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*instance) | 释放CodecCallbackType对象。&nbsp;[更多...](_codec.md#codeccallbacktyperelease) | 


## **详细描述**

主要包括回调函数接口定义。

Codec模块事件上报、上报输入buffer和输出buffer处理完毕等接口定义。

**Since：**

3.1

**Version：**

2.0
