# OhosImageSourceProperty

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:04:03.156Z pushedAt=2026-08-04T02:53:21.312Z -->

```c
struct OhosImageSourceProperty {...}
```

## Overview

The struct describes the property string (in key-value format) of an image source. It is used in [OH_ImageSource_GetImageProperty](capi-image-source-mdk-h.md#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](capi-image-source-mdk-h.md#oh_imagesource_modifyimageproperty).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* value = nullptr | Pointer to the starting address of the property string.|
| size_t size = 0 | Size of the property string.|