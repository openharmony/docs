# ImageEffect_DataValue

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:05:33.944Z pushedAt=2026-08-04T02:21:08.735Z -->

```c
typedef union ImageEffect_DataValue {...} ImageEffect_DataValue
```

## Overview

The union describes the data values.

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

**Header file**: [image_effect_filter.h](capi-image-effect-filter-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t int32Value | Integer value, corresponding to [EFFECT_DATA_TYPE_INT32](capi-image-effect-filter-h.md#imageeffect_datatype).|
| float floatValue | Single-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_FLOAT](capi-image-effect-filter-h.md#imageeffect_datatype).|
| double doubleValue | Double-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_DOUBLE](capi-image-effect-filter-h.md#imageeffect_datatype).|
| char charValue | Byte value, corresponding to [EFFECT_DATA_TYPE_CHAR](capi-image-effect-filter-h.md#imageeffect_datatype).|
| long longValue | Long integer, corresponding to [EFFECT_DATA_TYPE_LONG](capi-image-effect-filter-h.md#imageeffect_datatype).|
| bool boolValue | Boolean value, corresponding to [EFFECT_DATA_TYPE_BOOL](capi-image-effect-filter-h.md#imageeffect_datatype).|
| void *ptrValue | Pointer value, corresponding to [EFFECT_DATA_TYPE_PTR](capi-image-effect-filter-h.md#imageeffect_datatype).|