# Camera_CaptureStartInfo


## Overview

The Camera_CaptureStartInfo struct describes the capture start information.

**Since**: 12

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [captureId](#captureid) | Capture ID. | 
| int64_t [time](#time) | Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration. | 


## Member Variable Description


### captureId

```
int32_t Camera_CaptureStartInfo::captureId
```

**Description**

Capture ID.


### time

```
int64_t Camera_CaptureStartInfo::time
```

**Description**

Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration.
