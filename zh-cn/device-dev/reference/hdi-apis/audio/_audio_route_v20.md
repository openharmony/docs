# AudioRoute


## 概述

音频路由信息。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [AudioRouteNode](_audio_route_node_v20.md)[] [sources](#sources) | 发送端列表，详情参考[AudioRouteNode](_audio_route_node_v20.md)。  | 
| struct [AudioRouteNode](_audio_route_node_v20.md)[] [sinks](#sinks) | 接受端列表，详情参考[AudioRouteNode](_audio_route_node_v20.md)。  | 


## 类成员变量说明


### sinks

```
struct AudioRouteNode [] AudioRoute::sinks
```
**描述**

接受端列表，详情参考[AudioRouteNode](_audio_route_node_v20.md)。


### sources

```
struct AudioRouteNode [] AudioRoute::sources
```
**描述**

发送端列表，详情参考[AudioRouteNode](_audio_route_node_v20.md)。
