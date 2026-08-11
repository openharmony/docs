# Image_Scale

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:57:53.424Z pushedAt=2026-08-04T03:01:43.872Z -->

```c
typedef struct Image_Scale {...} Image_Scale
```

## Overview

The struct describes the image scale factor.

**Since**: 22

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_common.h](capi-image-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| float x | Scale factor of the width. It must not be **0**.|
| float y | Scale factor of the height. It must not be **0**.|