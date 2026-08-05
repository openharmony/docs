# OH_PictureNative_MetadataCopyItem

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=92177e27e9e27a18151783969cb0ac50486d8081 translatedAt=2026-08-03T04:01:20.276Z pushedAt=2026-08-04T03:00:48.623Z -->

```c
typedef struct OH_PictureNative_MetadataCopyItem {...} OH_PictureNative_MetadataCopyItem
```

## Overview

This struct is used to specify metadata copy rules when creating a deep copy of a PictureNative object. It describes how to copy metadata from one type to another.

**Since:** 26.0.0

**Related module:** [Image_NativeModule](capi-image-nativemodule.md)

**File to include:** [picture_native.h](capi-picture-native-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) srcType | Source metadata type, which specifies the metadata type to copy from the source image.<br>**Since:** 26.0.0 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) dstType | Destination metadata type, which specifies the metadata type to store in the destination image.<br>**Since:** 26.0.0 |