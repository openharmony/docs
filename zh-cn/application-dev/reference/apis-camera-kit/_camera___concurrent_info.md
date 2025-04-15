# Camera_ConcurrentInfo


## 概述

相机并发能力信息。

**起始版本：** 18

**相关模块：**[OH_Camera](_o_h___camera.md)

**所在头文件：**[camera.h](camera_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_Device](_camera___device.md) [camera](#camera) | 相机实例。 | 
| [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) [type](#type) | 相机并发状态。 | 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \* [sceneModes](#scenemodes) | 相机并发支持的模式。 | 
| [Camera_OutputCapability](_camera___output_capability.md) \* [outputCapabilities](#outputcapabilities) | 相机输出能力集。 | 
| uint32_t [modeAndCapabilitySize](#modeandcapabilitysize) | 相机输出能力集大小。 | 


## 结构体成员变量说明


### camera

```
Camera_Device camera
```

**描述**

相机实例。


### modeAndCapabilitySize

```
uint32_t modeAndCapabilitySize
```

**描述**

相机输出能力集大小。


### outputCapabilities

```
Camera_OutputCapability* outputCapabilities
```

**描述**

相机输出能力集。


### sceneModes

```
Camera_SceneMode* sceneModes
```

**描述**

相机并发支持的模式。


### type

```
Camera_ConcurrentType type
```

**描述**

相机并发状态。

