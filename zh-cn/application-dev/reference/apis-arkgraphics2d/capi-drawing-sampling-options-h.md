# drawing_sampling_options.h

## 概述

文件中定义了与采样相关的功能函数。用于图片或者纹理等图像的采样。

**引用文件：** drawing_sampling_options.h

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) | OH_Drawing_FilterMode | 过滤模式枚举。 |
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) | OH_Drawing_MipmapMode | 多级渐远纹理模式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate(OH_Drawing_FilterMode filterMode,OH_Drawing_MipmapMode mipmapMode)](#oh_drawing_samplingoptionscreate) | 创建一个采样选项对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>mipmapMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_SamplingOptionsDestroy(OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_samplingoptionsdestroy) | 销毁采样选项对象并回收该对象占有内存。 |

## 枚举类型说明

### OH_Drawing_FilterMode

```
enum OH_Drawing_FilterMode
```

**描述**

过滤模式枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| FILTER_MODE_NEAREST | 邻近过滤模式。 |
| FILTER_MODE_LINEAR | 线性过滤模式。 |

### OH_Drawing_MipmapMode

```
enum OH_Drawing_MipmapMode
```

**描述**

多级渐远纹理模式枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MIPMAP_MODE_NONE | 忽略多级渐远纹理级别。 |
| MIPMAP_MODE_NEAREST | 邻近多级渐远级别采样。 |
| MIPMAP_MODE_LINEAR | 两个邻近多级渐远纹理之间，线性插值采样。 |


## 函数说明

### OH_Drawing_SamplingOptionsCreate()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate(OH_Drawing_FilterMode filterMode,OH_Drawing_MipmapMode mipmapMode)
```

**描述**

创建一个采样选项对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>mipmapMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) filterMode | 过滤采样模式[OH_Drawing_FilterMode](capi-drawing-sampling-options-h.md#oh_drawing_filtermode)。 |
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) mipmapMode | 多级渐远纹理采样模式[OH_Drawing_MipmapMode](capi-drawing-sampling-options-h.md#oh_drawing_mipmapmode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* | 函数会返回一个指针，指针指向创建的采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)。 |

### OH_Drawing_SamplingOptionsDestroy()

```
void OH_Drawing_SamplingOptionsDestroy(OH_Drawing_SamplingOptions* samplingOptions)
```

**描述**

销毁采样选项对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* samplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)的指针。 |


