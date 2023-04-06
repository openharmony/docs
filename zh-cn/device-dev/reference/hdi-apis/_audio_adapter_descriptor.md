# AudioAdapterDescriptor


## **概述**

音频适配器描述符。

一个音频适配器（adapter）是一个声卡的端口驱动集合，包含输出端口、输入端口， 其中一个端口对应着多个PIN脚，一个PIN脚对应着一个实体的器件（例如喇叭、有线耳机）。

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [adapterName](_audio.md#adaptername) | 音频适配器的名称 | 
| [portNum](_audio.md#portnum) | 一个音频适配器支持的端口数目 | 
| [ports](_audio.md#ports) | 一个音频适配器支持的端口列表 | 
