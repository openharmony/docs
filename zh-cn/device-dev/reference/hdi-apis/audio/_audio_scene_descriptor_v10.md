# AudioSceneDescriptor


## 概述

音频场景描述符。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| union [SceneDesc](union_scene_desc_v11.md)[scene](#scene) | 音频场景描述，详情参考[SceneDesc](union_scene_desc_v11.md)。  | 
| struct [AudioDeviceDescriptor](_audio_device_descriptor_v10.md)[desc](#desc) | 音频设备描述符，详情参考[AudioDeviceDescriptor](_audio_device_descriptor_v10.md)。  | 


## 类成员变量说明


### desc

```
struct AudioDeviceDescriptor AudioSceneDescriptor::desc
```
**描述**

音频设备描述符，详情参考[AudioDeviceDescriptor](_audio_device_descriptor_v10.md)。


### scene

```
union SceneDesc AudioSceneDescriptor::scene
```
**描述**

音频场景描述，详情参考[SceneDesc](union_scene_desc_v11.md)。
