# AudioSubPortCapability


## 概述

音频子端口的支持能力。

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
| [portId](#portid) | unsigned&nbsp;int<br/>子端口ID。&nbsp; | 
| [desc](#desc) | String<br/>以字符串命名的子端口。&nbsp; | 
| [mask](#mask) | enum&nbsp;[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)<br/>数据透传模式，详情参考[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)。&nbsp; | 


## 类成员变量说明


### desc

  
```
String AudioSubPortCapability::desc
```
**描述:**
以字符串命名的子端口。


### mask

  
```
enum AudioPortPassthroughMode AudioSubPortCapability::mask
```
**描述:**
数据透传模式，详情参考[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)。


### portId

  
```
unsigned int AudioSubPortCapability::portId
```
**描述:**
子端口ID。
