# drawing_image.h


## 概述

文件中定义了与图片相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_image.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Image](_drawing.md#oh_drawing_image) \* [OH_Drawing_ImageCreate](_drawing.md#oh_drawing_imagecreate) (void) | 创建一个图片对象，描述了要绘制的二维像素数组。 |
| void [OH_Drawing_ImageDestroy](_drawing.md#oh_drawing_imagedestroy) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | 销毁图片对象并回收该对象占有内存。 |
| bool [OH_Drawing_ImageBuildFromBitmap](_drawing.md#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 从位图构造图片对象内容，共享或复制位图像素。如果位图被标记为不可变状态， 像素内存是共享的，不是复制。 |
| int32_t [OH_Drawing_ImageGetWidth](_drawing.md#oh_drawing_imagegetwidth) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | 获取图片宽度，即每行的像素个数。 |
| int32_t [OH_Drawing_ImageGetHeight](_drawing.md#oh_drawing_imagegetheight) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*) | 获取图片高度，即像素行数。 |
| void [OH_Drawing_ImageGetImageInfo](_drawing.md#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | 获取图片信息。调用该接口后，传入的图片信息对象被填充。 |
