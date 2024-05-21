# OhosImageComponent


## Overview

The **OHOS::Media::OhosImageComponent** struct defines the information about an image component.

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [byteBuffer](#bytebuffer) | Buffer that stores the pixel data.| 
| [size](#size) | Size of the pixel data in the memory.| 
| [componentType](#componenttype) | Type of the pixel data.| 
| [rowStride](#rowstride) | Row stride of the pixel data.| 
| [pixelStride](#pixelstride) | Pixel stride of the pixel data.| 


## Member Variable Description


### byteBuffer

```
uint8_t* OhosImageComponent::byteBuffer
```

**Description**

Buffer that stores the pixel data.


### componentType

```
int32_t OhosImageComponent::componentType
```

**Description**

Type of the pixel data.


### pixelStride

```
int32_t OhosImageComponent::pixelStride
```

**Description**

Pixel stride of the pixel data.


### rowStride

```
int32_t OhosImageComponent::rowStride
```

**Description**

Row stride of the pixel data.


### size

```
size_t OhosImageComponent::size
```

**Description**

Size of the pixel data in the memory.
