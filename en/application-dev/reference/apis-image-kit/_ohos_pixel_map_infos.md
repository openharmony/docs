# OhosPixelMapInfos


## Overview

The **OhosPixelMapInfos** struct describes the information about a PixelMap.

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [width](#width) | Image width, in pixels. | 
| uint32_t [height](#height) | Image height, in pixels. | 
| uint32_t [rowSize](#rowsize) | Number of bytes that each row of the image occupies in the memory.| 
| int32_t [pixelFormat](#pixelformat) | Pixel format. | 


## Member Variable Description


### height

```
uint32_t OhosPixelMapInfos::height
```

**Description**

Image height, in pixels.


### pixelFormat

```
int32_t OhosPixelMapInfos::pixelFormat
```

**Description**

Pixel format.


### rowSize

```
uint32_t OhosPixelMapInfos::rowSize
```

**Description**

Number of bytes that each row of the image occupies in the memory.

In the case of DMA, the formula is as follows: Image width x Number of bytes of each pixel + Number of padding bytes at the end of each row. In the case of other types of memory, the formula is as follows: Image width x Number of bytes of each pixel.


### width

```
uint32_t OhosPixelMapInfos::width
```

**Description**

Image width, in pixels.
