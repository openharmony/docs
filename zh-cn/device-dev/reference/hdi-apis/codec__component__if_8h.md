# codec_component_if.h


## 概述

主要包括Codec组件接口定义。

Codec模块提供了获取组件信息、给组件发送命令、组件参数设置、buffer轮转和控制等接口定义。创建组件后，可使用下列接口进行编解码处理。

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
| [CodecComponentType](_codec_component_type.md) | struct<br/>Codec组件接口定义。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecComponentTypeGet](_codec.md#codeccomponenttypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*<br/>实例化CodecComponentType对象。&nbsp; | 
| [CodecComponentTypeRelease](_codec.md#codeccomponenttyperelease)&nbsp;(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*instance) | void<br/>释放CodecComponentType对象。&nbsp; | 
