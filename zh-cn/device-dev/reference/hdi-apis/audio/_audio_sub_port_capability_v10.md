# AudioSubPortCapability


## 概述

音频子端口的支持能力。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [portId](#portid) | 子端口ID。  | 
| String [desc](#desc) | 以字符串命名的子端口。  | 
| enum [AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode)[mask](#mask) | 数据透传模式，详情参考[AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode)。  | 


## 类成员变量说明


### desc

```
String AudioSubPortCapability::desc
```
**描述**

以字符串命名的子端口。


### mask

```
enum AudioPortPassthroughMode AudioSubPortCapability::mask
```
**描述**

数据透传模式，详情参考[AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode)。


### portId

```
unsigned int AudioSubPortCapability::portId
```
**描述**

子端口ID。
