# Image_String

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=80c0a43cc0af3435c23af3413e3b0da162d4ceb8 translatedAt=2026-08-03T03:58:30.089Z pushedAt=2026-08-04T03:50:05.515Z -->

```c
struct Image_String {...}
typedef struct Image_String Image_MimeType
typedef struct Image_String Image_String
```

## Overview

String struct used to describe the address and length of string data. Image_MimeType is an alias of Image_String, used to represent MIME types.

When this struct is used as an input parameter, the caller is responsible for ensuring that data and size are valid. When it is used as an output parameter, the allocation and release of data are subject to the specific API description.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_common.h](capi-image-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char *data = nullptr | Pointer to the starting address of the string data. |
| size_t size = 0 | Length of the string data. |