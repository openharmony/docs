# drawing_bitmap.h

## 概述

文件中定义了与位图相关的功能函数。

<!--RP1-->
**相关示例：** [NDKAPIDrawing (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**引用文件：** <native_drawing/drawing_bitmap.h>

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_BitmapFormat](capi-drawing-oh-drawing-bitmapformat.md) | OH_Drawing_BitmapFormat | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap* OH_Drawing_BitmapCreate(void)](#oh_drawing_bitmapcreate) | 用于创建一个位图对象。 |
| [void OH_Drawing_BitmapDestroy(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapdestroy) | 用于销毁位图对象并回收该对象占有内存。 |
| [OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels(OH_Drawing_Image_Info* imageInfo, void* pixels, uint32_t rowBytes)](#oh_drawing_bitmapcreatefrompixels) | 用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>imageInfo、pixels任意一个为NULL或者rowBytes等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_BitmapBuild(OH_Drawing_Bitmap* bitmap,const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat* bitmapFormat)](#oh_drawing_bitmapbuild) | 用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、bitmapFormat任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [uint32_t OH_Drawing_BitmapGetWidth(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetwidth) | 用于获取指定位图的宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [uint32_t OH_Drawing_BitmapGetHeight(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetheight) | 用于获取指定位图的高度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetcolorformat) | 用于获取指定位图的像素存储格式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetalphaformat) | 用于获取指定位图的像素透明度分量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void* OH_Drawing_BitmapGetPixels(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetpixels) | 用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_BitmapGetImageInfo(OH_Drawing_Bitmap* bitmap, OH_Drawing_Image_Info* imageInfo)](#oh_drawing_bitmapgetimageinfo) | 用于获取指定位图的信息。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、imageInfo任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_BitmapReadPixels(OH_Drawing_Bitmap* bitmap, const OH_Drawing_Image_Info* dstInfo,void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY)](#oh_drawing_bitmapreadpixels) | 将位图中的矩形区域像素数据读取到指定的内存缓冲区中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、dstInfo、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |

## 函数说明

### OH_Drawing_BitmapCreate()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate(void)
```

**描述**

用于创建一个位图对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* | 函数会返回一个指针，指针指向创建的位图对象。 |

### OH_Drawing_BitmapDestroy()

```
void OH_Drawing_BitmapDestroy(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于销毁位图对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

### OH_Drawing_BitmapCreateFromPixels()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels(OH_Drawing_Image_Info* imageInfo, void* pixels, uint32_t rowBytes)
```

**描述**

用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>imageInfo、pixels任意一个为NULL或者rowBytes等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | 指向图片信息对象[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)的指针。 |
| void* pixels | 指向像素存储的内存首地址，内存由开发者申请，保证有效性。 |
| uint32_t rowBytes | 每行像素的大小，小于等于0时无效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* | 函数返回一个指针，指针指向创建的位图对象[OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)。 |

### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild(OH_Drawing_Bitmap* bitmap,const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat* bitmapFormat)
```

**描述**

用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、bitmapFormat任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |
| const uint32_t width | 位图要初始化设置的宽度。 |
| const uint32_t height | 位图要初始化设置的高度。 |
| const [OH_Drawing_BitmapFormat](capi-drawing-oh-drawing-bitmapformat.md)* bitmapFormat | 位图要初始化设置的像素格式，包括像素的颜色类型和透明度类型。 |

### OH_Drawing_BitmapGetWidth()

```
uint32_t OH_Drawing_BitmapGetWidth(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于获取指定位图的宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数返回位图的宽度。 |

### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于获取指定位图的高度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数返回位图的高度。 |

### OH_Drawing_BitmapGetColorFormat()

```
OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于获取指定位图的像素存储格式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat) | 函数返回位图的像素存储格式，支持格式参考[OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat)。 |

### OH_Drawing_BitmapGetAlphaFormat()

```
OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于获取指定位图的像素透明度分量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat) | 函数返回位图的像素透明度分量，支持格式参考[OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat)。 |

### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels(OH_Drawing_Bitmap* bitmap)
```

**描述**

用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 函数返回位图的像素地址。 |

### OH_Drawing_BitmapGetImageInfo()

```
void OH_Drawing_BitmapGetImageInfo(OH_Drawing_Bitmap* bitmap, OH_Drawing_Image_Info* imageInfo)
```

**描述**

用于获取指定位图的信息。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、imageInfo任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象[OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)的指针。 |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | 指向图片信息对象[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)的指针。 |

### OH_Drawing_BitmapReadPixels()

```
bool OH_Drawing_BitmapReadPixels(OH_Drawing_Bitmap* bitmap, const OH_Drawing_Image_Info* dstInfo,void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY)
```

**描述**

将位图中的矩形区域像素数据读取到指定的内存缓冲区中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>bitmap、dstInfo、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | 指向位图对象[OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)的指针。 |
| const [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* dstInfo | 指向图片信息对象[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)的指针。 |
| void* dstPixels | 目标像素存储区域。 |
| size_t dstRowBytes | 目标像素数据每行的字节数，应大于或等于图片信息对象中的最小每行字节数。 |
| int32_t srcX | 源位图中读取像素数据的起始x轴坐标，应小于源位图的宽度。 |
| int32_t srcY | 源位图中读取像素数据的起始y轴坐标，应小于源位图的高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回接口调用成功与否的结果。true表示复制成功，false表示复制失败。 |