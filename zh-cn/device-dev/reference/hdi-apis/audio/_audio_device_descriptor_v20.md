# AudioDeviceDescriptor


## 概述

音频设备描述符。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [portId](#portid) | 音频端口ID。  | 
| enum [AudioPortPin](_hdi_audio_v20.md#audioportpin)[pins](#pins) | 音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_hdi_audio_v20.md#audioportpin)。  | 
| String [desc](#desc) | 以字符串命名的音频设备。  | 


## 类成员变量说明


### desc

```
String AudioDeviceDescriptor::desc
```
**描述**

以字符串命名的音频设备。


### pins

```
enum AudioPortPin AudioDeviceDescriptor::pins
```
**描述**

音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_hdi_audio_v20.md#audioportpin)。


### portId

```
unsigned int AudioDeviceDescriptor::portId
```
**描述**

音频端口ID。
