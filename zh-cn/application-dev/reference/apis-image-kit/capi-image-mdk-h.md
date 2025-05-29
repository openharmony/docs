# image_mdk.h

## 概述

声明访问图像矩形、大小、格式和组件数据的函数。

**库：** libimage_ndk.z.so

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosImageRect](capi-ohosimagerect.md) | - | 定义图像矩形信息。 |
| [ImageNative_](capi-imagenative-.md) | ImageNative | 为图像接口定义native层图像对象。 |
| [OhosImageComponent](capi-ohosimagecomponent.md) | - | 定义图像组成信息。 |

### 枚举

| 名称 | 描述 |
| -- | -- |
| [anonymous enum](#anonymous enum) | 图像格式枚举值。 |
| [anonymous enum](#anonymous enum) | 图像组成类型枚举值。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ImageNative* OH_Image_InitImageNative(napi_env env, napi_value source)](#oh_image_initimagenative) | 从输入的JavaScript Native API <b>图像</b> 对象中解析 native {@link ImageNative} 对象。 |
| [int32_t OH_Image_Format(const ImageNative* native, int32_t* format)](#oh_image_format) | 获取native {@link ImageNative} 对象的图像格式。 |
| [int32_t OH_Image_Release(ImageNative* native)](#oh_image_release) | 释放 {@link ImageNative} native对象。Note: 这个方法无法释放 JavaScript Native API <b>Image</b> 对象，而是释放被 [OH_Image_InitImageNative](capi-image-mdk-h.md#oh_image_initimagenative) 解析的 {@link ImageNative} native 对象。 |

## 枚举类型说明

### anonymous enum

```
enum anonymous enum
```

**描述**

图像格式枚举值。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_IMAGE_FORMAT_YCBCR_422_SP = 1000 | YCBCR422 semi-planar 格式 |
| OHOS_IMAGE_FORMAT_JPEG = 2000 | JPEG 编码格式 |

### anonymous enum

```
enum anonymous enum
```

**描述**

图像组成类型枚举值。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y = 1 | 亮度信息 |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_U = 2 | 色度信息 |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_V = 3 | 色差值信息 |
| OHOS_IMAGE_COMPONENT_FORMAT_JPEG = 4 | Jpeg 格式 |


## 函数说明

### OH_Image_InitImageNative()

```
ImageNative* OH_Image_InitImageNative(napi_env env, napi_value source)
```

**描述**

从输入的JavaScript Native API <b>图像</b> 对象中解析 native {@link ImageNative} 对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表示指向 JNI 环境的指针。 |
| napi_value source | 表示 JavaScript Native API <b>图像</b> 对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ImageNative* | 如果操作成果返回 {@link ImageNative} 指针对象，如果操作失败返回空指针。 |

**参考：**

ImageNative, OH_Image_Release

### OH_Image_Format()

```
int32_t OH_Image_Format(const ImageNative* native, int32_t* format)
```

**描述**

获取native {@link ImageNative} 对象的图像格式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageNative* native | 表示 {@link ImageNative} native对象的指针。 |
| int32_t* format | 表示作为转换结果的图像格式对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果从surface获取参数失败返回 IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageNative

### OH_Image_Release()

```
int32_t OH_Image_Release(ImageNative* native)
```

**描述**

释放 {@link ImageNative} native对象。Note: 这个方法无法释放 JavaScript Native API <b>Image</b> 对象，而是释放被 [OH_Image_InitImageNative](capi-image-mdk-h.md#oh_image_initimagenative) 解析的 {@link ImageNative} native 对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImageNative](capi-imagenative-.md)* native | 表示 {@link ImageNative} native对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageNative, OH_Image_InitImageNative


