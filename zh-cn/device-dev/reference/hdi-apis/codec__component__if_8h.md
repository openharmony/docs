# codec_component_if.h


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [CodecComponentType](_codec_component_type.md) | Codec组件接口定义。&nbsp;[更多...](_codec_component_type.md) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [CodecComponentTypeGet](_codec.md#codeccomponenttypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecComponentType对象。&nbsp;[更多...](_codec.md#codeccomponenttypeget) | 
| [CodecComponentTypeRelease](_codec.md#codeccomponenttyperelease)&nbsp;(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*instance) | 释放CodecComponentType对象。&nbsp;[更多...](_codec.md#codeccomponenttyperelease) | 


## **详细描述**

主要包括Codec组件接口定义。

Codec模块提供了获取组件信息、给组件发送命令、组件参数设置、buffer轮转和控制等接口定义。创建组件后，可使用下列接口进行编解码处理。

**Since：**

3.1

**Version：**

2.0
