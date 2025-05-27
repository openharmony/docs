# Camera_ConcurrentInfo


## Overview

The Camera_ConcurrentInfo struct describes the camera's concurrency information.

**Since**: 18

**Related module**: [OH_Camera](_o_h___camera.md)

**Header file**: [camera.h](camera_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Camera_Device](_camera___device.md) [camera](#camera) | Camera instance.| 
| [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) [type](#type) | Concurrency type of the camera.| 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \* [sceneModes](#scenemodes) | Scene modes supported by the camera.| 
| [Camera_OutputCapability](_camera___output_capability.md) \* [outputCapabilities](#outputcapabilities) | Output capabilities of the camera.| 
| uint32_t [modeAndCapabilitySize](#modeandcapabilitysize) | Output capability size of the camera.| 


## Member Variable Description


### camera

```
Camera_Device camera
```

**Description**

Camera instance.


### modeAndCapabilitySize

```
uint32_t modeAndCapabilitySize
```

**Description**

Output capability size of the camera.


### outputCapabilities

```
Camera_OutputCapability* outputCapabilities
```

**Description**

Output capabilities of the camera.


### sceneModes

```
Camera_SceneMode* sceneModes
```

**Description**

Scene modes supported by the camera.


### type

```
Camera_ConcurrentType type
```

**Description**

Concurrency type of the camera.
