# OH_NativeBuffer_Planes


## Overview

The OH_NativeBuffer_Planes struct describes the plane information of images in an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Related module**: [OH_NativeBuffer](_o_h___native_buffer.md)

**Header file**: [native_buffer.h](native__buffer_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [planeCount](#planecount) | Number of planes.| 
| [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md) [planes](#planes) [4] | Array holding the plane information of each image.| 


## Member Variable Description


### planeCount

```
uint32_t OH_NativeBuffer_Planes::planeCount
```

**Description**

Number of planes.


### planes

```
OH_NativeBuffer_Plane OH_NativeBuffer_Planes::planes[4]
```

**Description**

Array holding the plane information of each image.
