# OH_AudioObjectPosition

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1094148adf008b31cba87a5e551e39916719d2b6 translatedAt=2026-08-04T08:13:32.507Z pushedAt=2026-08-04T08:13:52.011Z -->

```c
typedef struct OH_AudioObjectPosition {...} OH_AudioObjectPosition
```

## Overview

Represents the position of an audio object sound source in 3D space. The position can be represented using Cartesian coordinates or polar coordinates.

**Since**: 26.0.0

**Related module**: [Core](capi-core.md)

**File to include:** [native_audio_vivid.h](capi-native-audio-vivid-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| bool isCartesian | Whether the object sound source uses Cartesian coordinates.<br>true indicates that Cartesian coordinates are used, and false indicates that the Cartesian coordinate system is not used and the polar coordinate system is used instead. |
| union {<br>[OH_CartesianPosition](capi-core-oh-cartesianposition.md) cartesian;<br>[OH_PolarPosition](capi-core-oh-polarposition.md) polar; <br>} pos | Union that contains the position data in Cartesian coordinates or polar coordinates.<br>cartesian: position represented in Cartesian coordinates.<br>polar: position represented in polar coordinates. |