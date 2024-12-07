# AudioEffectBuffer


## 概述

定义音效进程输入输出buffer。

**起始版本：** 4.0

**相关模块：**[HdiEffect](_hdi_effect.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [frameCount](#framecount) | 帧缓冲区中的帧计数  | 
| int [datatag](#datatag) | 用于使用简化的数据点类型标记，祥见 [AudioEffectBufferTag](_hdi_effect.md#audioeffectbuffertag) | 
| byte[] [rawData](#rawdata) | 音频数据指向缓冲区的起点, 数据类型由datatag定义  | 


## 类成员变量说明


### datatag

```
int AudioEffectBuffer::datatag
```
**描述**

用于使用简化的数据点类型标记，祥见 [AudioEffectBufferTag](_hdi_effect.md#audioeffectbuffertag)


### frameCount

```
unsigned int AudioEffectBuffer::frameCount
```
**描述**

帧缓冲区中的帧计数


### rawData

```
byte [] AudioEffectBuffer::rawData
```
**描述**

音频数据指向缓冲区的起点, 数据类型由datatag定义
