# AudioDeviceDescriptor


## 概述

音频设备描述符。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [portId](#portid) | unsigned&nbsp;int<br/>音频端口ID。&nbsp; | 
| [pins](#pins) | enum&nbsp;[AudioPortPin](_audio.md#audioportpin)<br/>音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_audio.md#audioportpin)。&nbsp; | 
| [desc](#desc) | String<br/>以字符串命名的音频设备。&nbsp; | 


## 类成员变量说明


### desc

  
```
String AudioDeviceDescriptor::desc
```
**描述:**
以字符串命名的音频设备。


### pins

  
```
enum AudioPortPin AudioDeviceDescriptor::pins
```
**描述:**
音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_audio.md#audioportpin)。


### portId

  
```
unsigned int AudioDeviceDescriptor::portId
```
**描述:**
音频端口ID。
