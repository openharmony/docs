# OhosPixelMapInfos


## Overview

The **OhosPixelMapInfos** struct defines the information about a pixel map.

**Since**

10

**Related Modules**

[Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [width](#width) | Image width, in pixels.| 
| [height](#height) | Image height, in pixels.| 
| [rowSize](#rowsize) | Number of bytes per row. In the case of Direct Memory Access (DMA), the formula is as follows: Image width x Roundup(64-fold byte count per pixel). (The roundup means that each row is automatically padded.) In the case of other types of memory, the formula is as follows: Image width x byte count per pixel.| 
| [pixelFormat](#pixelformat) | Pixel format.| 


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

Number of bytes per row.


### width

```
uint32_t OhosPixelMapInfos::width
```

**Description**

Image width, in pixels.
