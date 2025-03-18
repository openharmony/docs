# Camera_ConcurrentInfo


## 概述

文件并发信息。

**起始版本：** 18

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_Device](_camera___device.md) [camera](#camera) | 相机实例。 | 
| [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) [type](#type) | 并发类型。 | 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \* [sceneModes](#sceneModes) | 支持的模式。 | 
| [Camera_OutputCapability](_o_h___camera.md#outputcapability) \* [outputCapabilities](#outputCapabilities) | 与模式对应的输出能力集。 | 
| uint32_t [modeAndCapabilitySize](#modeAndCapabilitySize) | 数组大小。 | 

## 结构体成员变量说明


### camera

```
Camera_Device Camera_ConcurrentInfo::camera
```
**描述**
相机实例。


### type

```
Camera_ConcurrentType Camera_ConcurrentInfo::type
```
**描述**
并发类型。

### sceneModes

```
Camera_SceneMode* Camera_ConcurrentInfo::sceneModes
```
**描述**
支持的模式。

### outputCapabilities

```
Camera_OutputCapability* Camera_ConcurrentInfo::outputCapabilities
```
**描述**
与模式对应的输出能力集。

### modeAndCapabilitySize

```
uint32_t Camera_ConcurrentInfo::modeAndCapabilitySize
```
**描述**
数组大小。