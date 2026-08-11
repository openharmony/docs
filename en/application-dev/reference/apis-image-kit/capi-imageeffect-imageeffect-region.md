# ImageEffect_Region

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:05:53.854Z pushedAt=2026-08-04T02:15:18.483Z -->

```c
typedef struct ImageEffect_Region {...} ImageEffect_Region
```

## Overview

The struct describes the image region.

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

**Header file**: [image_effect_filter.h](capi-image-effect-filter-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t x0 | Start coordinate of the X axis.|
| int32_t y0 | Start coordinate of the Y axis.|
| int32_t x1 | End coordinate of the X axis.|
| int32_t y1 | End coordinate of the Y axis.|