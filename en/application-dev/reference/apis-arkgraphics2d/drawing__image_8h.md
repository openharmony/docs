# drawing_image.h


## Overview

The **drawing_image.h** file declares the functions related to the image in the drawing module.

**File to include**: &lt;native_drawing/drawing_image.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Image](_drawing.md#oh_drawing_image) \* [OH_Drawing_ImageCreate](_drawing.md#oh_drawing_imagecreate) (void) | Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.|
| void [OH_Drawing_ImageDestroy](_drawing.md#oh_drawing_imagedestroy) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_ImageBuildFromBitmap](_drawing.md#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared, not copied.|
| int32_t [OH_Drawing_ImageGetWidth](_drawing.md#oh_drawing_imagegetwidth) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | Obtains the image width, that is, the number of pixels in each line.|
| int32_t [OH_Drawing_ImageGetHeight](_drawing.md#oh_drawing_imagegetheight) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | Obtains the image height, that is, the number of pixel lines.|
| void [OH_Drawing_ImageGetImageInfo](_drawing.md#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | Obtains the image information. After this function is called, the passed-in image information object is filled.|
