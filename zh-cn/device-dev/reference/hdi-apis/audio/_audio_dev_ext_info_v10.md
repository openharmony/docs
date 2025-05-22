# AudioDevExtInfo


## 概述

音频设备拓展信息。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [moduleId](#moduleid) | 音频流绑定的模块ID。  | 
| enum [AudioPortPin](_hdi_audio_v11.md#audioportpin)[type](#type) | 音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_hdi_audio_v11.md#audioportpin)。  | 
| String [desc](#desc) | 地址描述。  | 


## 类成员变量说明


### desc

```
String AudioDevExtInfo::desc
```
**描述**

地址描述。


### moduleId

```
int AudioDevExtInfo::moduleId
```
**描述**

音频流绑定的模块ID。


### type

```
enum AudioPortPin AudioDevExtInfo::type
```
**描述**

音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_hdi_audio_v11.md#audioportpin)。
