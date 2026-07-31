# DRM_Statistics

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:12:20.893Z pushedAt=2026-07-31T03:50:32.440Z -->

```c
typedef struct DRM_Statistics {...} DRM_Statistics
```

## Overview

Statistics information of the MediaKeySystem.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t statisticsCount | Number of metrics.|
| char statisticsName[MAX_STATISTICS_COUNT][MAX_STATISTICS_NAME_LEN] | Array of metric names.|
| char statisticsDescription[MAX_STATISTICS_COUNT][MAX_STATISTICS_BUFFER_LEN] | Array of metric descriptions.|