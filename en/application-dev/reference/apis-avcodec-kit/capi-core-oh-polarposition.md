# OH_PolarPosition

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=884738af8d5a3baf269215666c9a571166d35e17 translatedAt=2026-08-04T08:13:37.755Z pushedAt=2026-08-04T08:13:56.220Z -->

```c
typedef struct OH_PolarPosition {...} OH_PolarPosition
```

## Overview

Represents a position in the polar coordinate system (also known as the spherical coordinate system). The polar coordinate system uses azimuth, elevation, and distance to define the position of an object sound source in 3D space.

**Since**: 26.0.0

**Related module**: [Core](capi-core.md)

**File to include:** [native_audio_vivid.h](capi-native-audio-vivid-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| float azimuth | Azimuth of the object sound source position in the polar coordinate system.<br> Value range is [-180.0, 180.0], where 0.0 indicates directly ahead, 90.0 indicates left, -90.0 indicates right, and -180.0 or 180.0 indicates directly behind. |
| float elevation | Elevation of the object sound source position in the polar coordinate system.<br> Value range is [-90.0, 90.0], where 0.0 indicates horizontal, 90.0 indicates directly above, and -90.0 indicates directly below. |
| float distance | Normalized distance of the object sound source position in the polar coordinate system.<br> Value range is [0.0, 1.0]. |