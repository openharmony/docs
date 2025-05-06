# Camera_TorchStatusInfo


## Overview

The Camera_TorchStatusInfo struct describes the flashlight status information.

**Since**: 12

**Related module**: [OH_Camera](_o_h___camera.md)

**Header file**: [camera.h](camera_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| bool [isTorchAvailable](#istorchavailable) | Whether the flashlight is available. The value **true** means that the flashlight is available, and **false** means the opposite. | 
| bool [isTorchActive](#istorchactive) | Whether the flashlight is activated. The value **true** means that the flashlight is activated, and **false** means the opposite. | 
| float [torchLevel](#torchlevel) | Flashlight level. The value range is [0, 1]. A larger value indicates a greater luminance. | 


## Member Variable Description


### isTorchActive

```
bool Camera_TorchStatusInfo::isTorchActive
```

**Description**

Whether the flashlight is activated.


### isTorchAvailable

```
bool Camera_TorchStatusInfo::isTorchAvailable
```

**Description**

Whether the flashlight is available.


### torchLevel

```
float Camera_TorchStatusInfo::torchLevel
```

**Description**

Flashlight level. The value range is [0, 1]. A larger value indicates a greater luminance.
