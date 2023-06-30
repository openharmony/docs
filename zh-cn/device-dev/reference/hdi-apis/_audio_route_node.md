# AudioRouteNode


## 概述

音频路由节点。

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
| [portId](#portid) | int<br/>音频端口ID。&nbsp; | 
| [role](#role) | enum&nbsp;[AudioPortRole](_audio.md#audioportrole)<br/>指定端口角色为发送端或接收端，详情参考[AudioPortRole](_audio.md#audioportrole)。&nbsp; | 
| [type](#type) | enum&nbsp;[AudioPortType](_audio.md#audioporttype)<br/>指定端口类型可以为设备类型、复合类型、绘画类型，详情参考[AudioPortType](_audio.md#audioporttype)。&nbsp; | 
| [ext](#ext) | struct&nbsp;[AudioInfo](_audio_info.md)<br/>音频端口特定信息，详情参考[AudioInfo](_audio_info.md)。&nbsp; | 


## 类成员变量说明


### ext

  
```
struct AudioInfo AudioRouteNode::ext
```
**描述:**
音频端口特定信息，详情参考[AudioInfo](_audio_info.md)。


### portId

  
```
int AudioRouteNode::portId
```
**描述:**
音频端口ID。


### role

  
```
enum AudioPortRole AudioRouteNode::role
```
**描述:**
指定端口角色为发送端或接收端，详情参考[AudioPortRole](_audio.md#audioportrole)。


### type

  
```
enum AudioPortType AudioRouteNode::type
```
**描述:**
指定端口类型可以为设备类型、复合类型、绘画类型，详情参考[AudioPortType](_audio.md#audioporttype)。
