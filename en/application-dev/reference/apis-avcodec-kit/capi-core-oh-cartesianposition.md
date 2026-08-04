# OH_CartesianPosition

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=884738af8d5a3baf269215666c9a571166d35e17 translatedAt=2026-08-04T08:13:45.352Z pushedAt=2026-08-04T08:13:54.863Z -->

```c
typedef struct OH_CartesianPosition {...} OH_CartesianPosition
```

## Overview

Represents the position of an object sound source in the Cartesian coordinate system. The Cartesian coordinate system uses the x, y, and z axes to define positions in three-dimensional space.

**Since**: 26.0.0

**Related module**: [Core](capi-core.md)

**File to include:** [native_audio_vivid.h](capi-native-audio-vivid-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| float x | Normalized X coordinate of the object sound source in the Cartesian coordinate system, representing the left/right dimension.<br> Value range: [-1.0, 1.0]. |
| float y | Normalized Y coordinate of the object sound source in the Cartesian coordinate system, representing the front/back dimension.<br> Value range: [-1.0, 1.0]. |
| float z | Normalized Z coordinate of the object sound source in the Cartesian coordinate system, representing the up/down dimension.<br> Value range: [-1.0, 1.0]. |