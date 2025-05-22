# AudioAdapterDescriptor


## 概述

音频适配器描述符。

一个音频适配器（adapter）是一个声卡的端口驱动集合，包含输出端口、输入端口， 其中一个端口对应着多个PIN脚，一个Pin脚对应着一个实体的器件（例如喇叭、有线耳机）。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [adapterName](#adaptername) | 音频适配器的名称。  | 
| struct [AudioPort](_audio_port_v10.md)[] [ports](#ports) | 一个音频适配器支持的端口列表，详情参考[AudioPort](_audio_port_v10.md)。  | 


## 类成员变量说明


### adapterName

```
String AudioAdapterDescriptor::adapterName
```
**描述**

音频适配器的名称。


### ports

```
struct AudioPort [] AudioAdapterDescriptor::ports
```
**描述**

一个音频适配器支持的端口列表，详情参考[AudioPort](_audio_port_v10.md)。
