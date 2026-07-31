# drawing_image.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了与图片相关的功能函数。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_image.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Image* OH_Drawing_ImageCreate(void)](#oh_drawing_imagecreate) | 创建一个图片对象，描述了要绘制的二维像素数组。使用完毕后，必须调用[OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy)销毁该图片对象并回收内存，否则会导致内存泄漏。 |
| [void OH_Drawing_ImageDestroy(OH_Drawing_Image* image)](#oh_drawing_imagedestroy) | 销毁图片对象并回收该对象占用的内存。与[OH_Drawing_ImageCreate](#oh_drawing_imagecreate)配对使用，用于销毁由其创建的图片对象。销毁后不应再使用该图片对象指针，否则可能导致未定义行为。 |
| [bool OH_Drawing_ImageBuildFromBitmap(OH_Drawing_Image* image, OH_Drawing_Bitmap* bitmap)](#oh_drawing_imagebuildfrombitmap) | 从位图构造图片对象内容，共享或复制位图像素。在已有位图数据需要在画布上绘制图片的场景中，可使用此接口将位图数据构造为图片对象。如果位图被标记为不可变状态，像素内存是共享的；如果位图未被标记为不可变状态（即位图为可变状态），像素内存会被复制。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image、bitmap任意一个为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [int32_t OH_Drawing_ImageGetWidth(OH_Drawing_Image* image)](#oh_drawing_imagegetwidth) | 获取图片宽度，单位为物理像素px，即每行的像素个数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [int32_t OH_Drawing_ImageGetHeight(OH_Drawing_Image* image)](#oh_drawing_imagegetheight) | 获取图片高度，单位为物理像素px，即像素行数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_ImageGetImageInfo(OH_Drawing_Image* image, OH_Drawing_Image_Info* imageInfo)](#oh_drawing_imagegetimageinfo) | 获取图片信息。调用该接口后，传入的图片信息对象被填充。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image、imageInfo任意一个为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。 |

## 函数说明

### OH_Drawing_ImageCreate()

```c
OH_Drawing_Image* OH_Drawing_ImageCreate(void)
```

**描述**

创建一个图片对象，描述了要绘制的二维像素数组。使用完毕后，必须调用[OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy)销毁该图片对象并回收内存，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* | 返回指向创建的图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针。 |

### OH_Drawing_ImageDestroy()

```c
void OH_Drawing_ImageDestroy(OH_Drawing_Image* image)
```

**描述**

销毁图片对象并回收该对象占用的内存。与[OH_Drawing_ImageCreate](#oh_drawing_imagecreate)配对使用，用于销毁由其创建的图片对象。销毁后不应再使用该图片对象指针，否则可能导致未定义行为。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | 指向由[OH_Drawing_ImageCreate](#oh_drawing_imagecreate)创建的图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针，用于销毁该图片对象并回收内存。销毁后不应再使用该指针，否则可能导致未定义行为。 |

### OH_Drawing_ImageBuildFromBitmap()

```c
bool OH_Drawing_ImageBuildFromBitmap(OH_Drawing_Image* image, OH_Drawing_Bitmap* bitmap)
```

**描述**

从位图构造图片对象内容，共享或复制位图像素。在已有位图数据需要在画布上绘制图片的场景中，可使用此接口将位图数据构造为图片对象。如果位图被标记为不可变状态，像素内存是共享的；如果位图未被标记为不可变状态（即位图为可变状态），像素内存会被复制。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image、bitmap任意一个为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | 指向图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针，作为目标对象用于接收从位图构造的图片对象内容。当位图被标记为不可变状态时，图片对象的像素内存与位图共享，而非独立复制。 |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象[OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)的指针，作为源数据用于构造图片对象内容。如果位图被标记为不可变状态，像素内存是共享的；如果位图未被标记为不可变状态（即位图为可变状态），像素内存会被复制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示构造图片内容成功，函数返回false表示构造图片内容失败。 |

### OH_Drawing_ImageGetWidth()

```c
int32_t OH_Drawing_ImageGetWidth(OH_Drawing_Image* image)
```

**描述**

获取图片宽度，单位为物理像素px，即每行的像素个数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | 指向要获取宽度的图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 函数返回图片宽度，单位为物理像素px，即每行的像素个数。 |

### OH_Drawing_ImageGetHeight()

```c
int32_t OH_Drawing_ImageGetHeight(OH_Drawing_Image* image)
```

**描述**

获取图片高度，单位为物理像素px，即像素行数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | 指向要获取高度的图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 函数返回图片高度，单位为物理像素px，即像素行数。 |

### OH_Drawing_ImageGetImageInfo()

```c
void OH_Drawing_ImageGetImageInfo(OH_Drawing_Image* image, OH_Drawing_Image_Info* imageInfo)
```

**描述**

获取图片信息。调用该接口后，传入的图片信息对象被填充。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>image、imageInfo任意一个为NULL时返回错误码OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | 指向要获取信息的图片对象[OH_Drawing_Image](capi-drawing-oh-drawing-image.md)的指针，作为图片信息的数据来源。 |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | 指向图片信息对象[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)的指针，作为输出参数用于接收获取到的图片信息，调用该接口后该对象会被填充。开发者可通过声明[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)结构体创建。 |

