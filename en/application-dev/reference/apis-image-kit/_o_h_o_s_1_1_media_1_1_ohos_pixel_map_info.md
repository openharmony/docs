# OHOS::Media::OhosPixelMapInfo


## Overview

The **OHOS::Media::OhosPixelMapInfo** struct defines the information about a pixel map.

**System capability**: SystemCapability.Multimedia.Image

**Deprecated from**: 10

**Since**: 8

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [width](#width) | Image width, in pixels.| 
| [height](#height) | Image height, in pixels.| 
| [rowSize](#rowsize) | Number of bytes per row. In the case of Direct Memory Access (DMA), the formula is as follows: Image width x Number of bytes of each pixel + Padding. In the case of other types of memory, the formula is as follows: Image width x Number of bytes of each pixel.| 
| [pixelFormat](#pixelformat) | Pixel format.| 


## Member Variable Description


### height

```
uint32_t OHOS::Media::OhosPixelMapInfo::height
```

**Description**

Image height, in pixels.


### pixelFormat

```
int32_t OHOS::Media::OhosPixelMapInfo::pixelFormat
```

**Description**

Pixel format.


### rowSize

```
uint32_t OHOS::Media::OhosPixelMapInfo::rowSize
```

**Description**

Number of bytes per row. In the case of DMA, the formula is as follows: Image width x Number of bytes of each pixel + Padding. In the case of other types of memory, the formula is as follows: Image width x Number of bytes of each pixel.


### width

```
uint32_t OHOS::Media::OhosPixelMapInfo::width
```

**Description**

Image width, in pixels.
