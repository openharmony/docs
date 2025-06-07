# Image_Region


## Overview

The Image_Region struct describes the region of an image to decode.

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)

**Header file**: [image_common.h](image__common_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [x](#x) | X coordinate of the region. It cannot be greater than the width of the original image. | 
| uint32_t [y](#y) | Y coordinate of the region. It cannot be greater than the height of the original image. | 
| uint32_t [width](#width) | Width of the output image, in px. | 
| uint32_t [height](#height) | Height of the output image, in px. | 


## Member Variable Description


### height

```
uint32_t Image_Region::height
```
**Description**

Height of the output image, in px.


### width

```
uint32_t Image_Region::width
```
**Description**

Width of the output image, in px.


### x

```
uint32_t Image_Region::x
```
**Description**

X coordinate of the region. It cannot be greater than the width of the original image.


### y

```
uint32_t Image_Region::y
```
**Description**

Y coordinate of the region. It cannot be greater than the height of the original image.
