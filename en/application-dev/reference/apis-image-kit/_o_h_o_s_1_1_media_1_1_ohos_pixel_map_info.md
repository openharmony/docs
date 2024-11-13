# OhosPixelMapInfo


## Overview

The **OHOS::Media::OhosPixelMapInfo** struct describes the information about a PixelMap.

**System capability**: SystemCapability.Multimedia.Image

**Deprecated from**: 10

**Since**: 8

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [width](#width) | Image width, in pixels. | 
| uint32_t [height](#height) | Image height, in pixels. | 
| uint32_t [rowSize](#rowsize) | Number of bytes per row. | 
| int32_t [pixelFormat](#pixelformat) | Pixel format. | 


## Member Variable Description


### height

```
uint32_t OhosPixelMapInfo::height
```

**Description**

Image height, in pixels.


### pixelFormat

```
int32_t OhosPixelMapInfo::pixelFormat
```

**Description**

Pixel format. The options are as follows:

| Value| Description|
| ------ | ----------------- |
| 0 | Unknown format.|
| 2 | RGB_565.|
| 3 | RGBA_8888.|
| 4 | BGRA_8888.|
| 5 | RGB_888.|
| 6 | ALPHA_8.|
| 7 | RGBA_F16.|
| 8 | NV21.|
| 9 | NV12.|

### rowSize

```
uint32_t OhosPixelMapInfo::rowSize
```

**Description**

Number of bytes per row. In the case of DMA, the formula is as follows: Image width x Number of bytes of each pixel + Padding. In the case of other types of memory, the formula is as follows: Image width x Number of bytes of each pixel.


### width

```
uint32_t OhosPixelMapInfo::width
```

**Description**

Image width, in pixels.
