# OhosImageSourceDelayTimeList

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:03:58.383Z pushedAt=2026-08-04T02:53:35.233Z -->

```c
struct OhosImageSourceDelayTimeList {...}
```

## Overview

The struct describes the delay time list of an image source. The delay time list is obtained by calling [OH_ImageSource_GetDelayTime](capi-image-source-mdk-h.md#oh_imagesource_getdelaytime).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t* delayTimeList | Pointer to the starting address of the image source delay time list.|
| size_t size = 0 | Size of the image source delay time list.|