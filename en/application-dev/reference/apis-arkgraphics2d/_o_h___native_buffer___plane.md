# OH_NativeBuffer_Plane


## Overview

The OH_NativeBuffer_Plane struct describes the plane information of an image.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Related module**: [OH_NativeBuffer](_o_h___native_buffer.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint64_t [offset](#offset) | Offset of the image plane, in bytes. | 
| uint32_t [rowStride](#rowstride) | Distance from the first value in an image row to the first value in the next row, in bytes. | 
| uint32_t [columnStride](#columnstride) | Distance from the first value in an image column to the first value in the next column, in bytes. | 


## Member Variable Description


### columnStride

```
uint32_t OH_NativeBuffer_Plane::columnStride
```
**Description**

Distance from the first value in an image column to the first value in the next column, in bytes.


### offset

```
uint64_t OH_NativeBuffer_Plane::offset
```
**Description**

Offset of the image plane, in bytes.


### rowStride

```
uint32_t OH_NativeBuffer_Plane::rowStride
```
**Description**

Distance from the first value in an image row to the first value in the next row, in bytes.
