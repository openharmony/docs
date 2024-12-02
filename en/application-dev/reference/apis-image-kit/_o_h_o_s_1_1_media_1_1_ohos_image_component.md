# OhosImageComponent


## Overview

The **OHOS::Media::OhosImageComponent** struct describes the information about an image component.

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t \* [byteBuffer](#bytebuffer) | Buffer that stores the pixel data. | 
| size_t [size](#size) | Size of the pixel data in the memory. | 
| int32_t [componentType](#componenttype) | Type of the pixel data. | 
| int32_t [rowStride](#rowstride) | Row stride of the pixel data. | 
| int32_t [pixelStride](#pixelstride) | Pixel stride of the pixel data. | 


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

| Value| Description|
| ------ | ----------------------- |
| 1 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y, luminance information|
| 2 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_U, chrominance component.|
| 3 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_V, chrominance component.|
| 4 | OHOS_IMAGE_COMPONENT_FORMAT_JPEG, JPEG format.|

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
