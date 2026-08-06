# OH_PictureNative_AuxiliaryPictureCopyItem

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=92177e27e9e27a18151783969cb0ac50486d8081 translatedAt=2026-08-03T04:01:01.928Z pushedAt=2026-08-04T03:00:52.493Z -->

```c
typedef struct OH_PictureNative_AuxiliaryPictureCopyItem {...} OH_PictureNative_AuxiliaryPictureCopyItem
```

## Overview

This struct is used to specify the copy rule for auxiliary pictures when creating a deep copy of a PictureNative object. It describes how to copy an auxiliary picture from one type to another.

**Since:** 26.0.0

**Related module:** [Image_NativeModule](capi-image-nativemodule.md)

**Header file:** [picture_native.h](capi-picture-native-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) srcType | Source auxiliary picture type, which specifies the type of auxiliary picture to copy from the source image.<br>**Since:** 26.0.0 |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) dstType | Destination auxiliary picture type, which specifies the type in which the copied auxiliary picture is stored in the destination image.<br>**Since:** 26.0.0 |