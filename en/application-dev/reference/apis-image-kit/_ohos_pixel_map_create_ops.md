# OhosPixelMapCreateOps


## Overview

The **OhosPixelMapCreateOps** struct defines the options used for creating a pixel map. The parameters need to be initialized.

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [width](#width) | Image width, in pixels. | 
| uint32_t [height](#height) | Image height, in pixels. | 
| int32_t [pixelFormat](#pixelformat) | Image format. | 
| uint32_t [editable](#editable) | Editing type of the image. | 
| uint32_t [alphaType](#alphatype) | Alpha type of the image. | 
| uint32_t [scaleMode](#scalemode) | Scale mode of the image. | 


## Member Variable Description


### alphaType

```
uint32_t OhosPixelMapCreateOps::alphaType
```

**Description**

Alpha type of the image. The options are as follows:

| Value| Description|
| ------ | ----------------------- |
| 0 | Unknown alpha type.|
| 1 | There is no alpha or the image is opaque.|
| 2 | Premultiplied alpha.|
| 3 | Unpremultiplied alpha, that is, straight alpha.|


### editable

```
uint32_t OhosPixelMapCreateOps::editable
```

**Description**

Editing type of the image. The value **true** means that the image pixel can be edited, and **false** means the opposite.


### height

```
uint32_t OhosPixelMapCreateOps::height
```

**Description**

Image height, in pixels.


### pixelFormat

```
int32_t OhosPixelMapCreateOps::pixelFormat
```

**Description**

Image format. The options are as follows:

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

### scaleMode

```
uint32_t OhosPixelMapCreateOps::scaleMode
```

**Description**

Scale mode of the image. The options are as follows:

| Value| Description|
| ------ | -------------------------------------------------- |
| 1 | The image is scaled in such a way that it fits the dimensions of the target and centered in the target.|
| 0 | The image size is reduced to fit the dimensions of the target.|

### width

```
uint32_t OhosPixelMapCreateOps::width
```

**Description**

Image width, in pixels.
