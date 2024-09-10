# AudioRouteNode


## 概述

音频路由节点。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [portId](#portid) | 音频端口ID。  | 
| enum [AudioPortRole](_hdi_audio_v20.md#audioportrole)[role](#role) | 指定端口角色为发送端或接收端，详情参考[AudioPortRole](_hdi_audio_v20.md#audioportrole)。  | 
| enum [AudioPortType](_hdi_audio_v20.md#audioporttype)[type](#type) | 指定端口类型可以为设备类型、复合类型、绘画类型，详情参考[AudioPortType](_hdi_audio_v20.md#audioporttype)。  | 
| struct [AudioInfo](_audio_info_v20.md)[ext](#ext) | 音频端口特定信息，详情参考[AudioInfo](_audio_info_v20.md)。  | 


## 类成员变量说明


### ext

```
struct AudioInfo AudioRouteNode::ext
```
**描述**

音频端口特定信息，详情参考[AudioInfo](_audio_info_v20.md)。


### portId

```
int AudioRouteNode::portId
```
**描述**

音频端口ID。


### role

```
enum AudioPortRole AudioRouteNode::role
```
**描述**

指定端口角色为发送端或接收端，详情参考[AudioPortRole](_hdi_audio_v20.md#audioportrole)。


### type

```
enum AudioPortType AudioRouteNode::type
```
**描述**

指定端口类型可以为设备类型、复合类型、绘画类型，详情参考[AudioPortType](_hdi_audio_v20.md#audioporttype)。
