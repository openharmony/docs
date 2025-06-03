# image_packer_mdk.h

## 概述

声明用于将图像编码到缓冲区或文件的api。可用于将像素数据编码到目标缓冲区或文件中。<br>编码过程如下：<br>通过OH_ImagePacker_Create方法创建编码器实例对象。<br>然后通过OH_ImagePacker_InitNative将编码器实例对象转换为编码器原生实例对象。<br>接下来用OH_ImagePacker_PackToData或者OH_ImagePacker_PackToFile将源以特定的编码选项编码进目标区域。<br>最后通过OH_ImagePacker_Release释放编码器实例对象。<br>

**库：** libimage_packer_ndk.z.so

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 11

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ImagePacker_Opts_](capi-imagepacker-opts-.md) | ImagePacker_Opts | 定义图像编码选项信息。 |
| [ImagePacker_Native_](capi-imagepacker-native-.md) | ImagePacker_Native | 为编码器方法定义native层编码器对象。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ImagePacker_Create(napi_env env, napi_value *res)](#oh_imagepacker_create) | 获取JavaScript native层API ImagePacker对象。 |
| [ImagePacker_Native* OH_ImagePacker_InitNative(napi_env env, napi_value packer)](#oh_imagepacker_initnative) | 从输入JavaScript native层API ImagePacker对象中，转换成ImagePacker_Native值。 |
| [int32_t OH_ImagePacker_PackToData(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, uint8_t* outData, size_t* size)](#oh_imagepacker_packtodata) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出<br>到指定的缓存区outData中。 |
| [int32_t OH_ImagePacker_PackToFile(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, int fd)](#oh_imagepacker_packtofile) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出<br>到指定的文件中。 |
| [int32_t OH_ImagePacker_Release(ImagePacker_Native* native)](#oh_imagepacker_release) | 释放native层编码器对象{@link ImagePacker_Native}。注: 此API不用于释放JavaScript原生API ImagePacker对象，它用于释放native层对象{@link ImagePacker_Native}。<br>通过调用[OH_ImagePacker_InitNative](capi-imagepacker-opts-.md#oh_imagepacker_initnative)解析。 |

## 函数说明

### OH_ImagePacker_Create()

```
int32_t OH_ImagePacker_Create(napi_env env, napi_value *res)
```

**描述**

获取JavaScript native层API ImagePacker对象。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| napi_value *res | 表明JavaScript native层API ImagePacker对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)IMAGE_RESULT_SUCCESS；如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER。 |

### OH_ImagePacker_InitNative()

```
ImagePacker_Native* OH_ImagePacker_InitNative(napi_env env, napi_value packer)
```

**描述**

从输入JavaScript native层API ImagePacker对象中，转换成ImagePacker_Native值。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| napi_value packer | 表明JavaScript native层API ImagePacker对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ImagePacker_Native* | 如果操作成功则返回{@link ImagePacker_Native}指针，否则返回空指针。 |

**参考：**

[OH_ImagePacker_Release](#oh_imagepacker_release)

### OH_ImagePacker_PackToData()

```
int32_t OH_ImagePacker_PackToData(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, uint8_t* outData, size_t* size)
```

**描述**

通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出<br>到指定的缓存区outData中。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImagePacker_Native](capi-imagepacker-native-.md)* native | 表明指向native层{@link ImagePacker}的指针。 |
| napi_value source | 表明待编码JavaScript native层API PixelMap对象或者ImageSource对象。 |
| [ImagePacker_Opts](capi-imagepacker-opts-.md)* opts | 表明位图编码的选项，查看{@link ImagePacker_Opts}。 |
| uint8_t* outData | 输出的指定缓存区。 |
| size_t* size | 输出的指定缓存区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) OHOS_IMAGE_RESULT_SUCCESS；<br>  returns 如果参数无效返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) IMAGE_RESULT_INVALID_PARAMETER；<br>  returns 如果输出缓冲区异常返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_DATA_ABNORMAL；<br>  returns 如果格式不匹配返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_MISMATCHED_FORMAT；<br>  returns 如果malloc内部缓冲区错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_MALLOC_ABNORMAL；<br>  returns 如果init编解码器内部错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_DECODE_ABNORMAL；<br>  returns 如果编码器在编码过程中出现错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_ENCODE_FAILED。 |

**参考：**

[OH_ImagePacker_PackToFile](#oh_imagepacker_packtofile)

### OH_ImagePacker_PackToFile()

```
int32_t OH_ImagePacker_PackToFile(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, int fd)
```

**描述**

通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出<br>到指定的文件中。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImagePacker_Native](capi-imagepacker-native-.md)* native | 表明指向native层{@link ImagePacker}的指针。 |
| napi_value source | 表明待编码JavaScript native层API PixelMap对象或者ImageSource对象。 |
| [ImagePacker_Opts](capi-imagepacker-opts-.md)* opts | 表明位图编码的选项，查看{@link ImagePacker_Opts}。 |
| int fd | 输出的指定文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) OHOS_IMAGE_RESULT_SUCCESS；<br>  returns 如果参数无效返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) IMAGE_RESULT_INVALID_PARAMETER；<br>  returns 如果输出缓冲区异常返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_DATA_ABNORMAL；<br>  returns 如果格式不匹配返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_MISMATCHED_FORMAT；<br>  returns 如果malloc内部缓冲区错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_MALLOC_ABNORMAL；<br>  returns 如果init编解码器内部错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_DECODE_ABNORMAL；<br>  returns 如果编码器在编码过程中出现错误返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) ERR_IMAGE_ENCODE_FAILED。 |

**参考：**

[OH_ImagePacker_PackToData](#oh_imagepacker_packtodata)

### OH_ImagePacker_Release()

```
int32_t OH_ImagePacker_Release(ImagePacker_Native* native)
```

**描述**

释放native层编码器对象{@link ImagePacker_Native}。注: 此API不用于释放JavaScript原生API ImagePacker对象，它用于释放native层对象{@link ImagePacker_Native}。<br>通过调用[OH_ImagePacker_InitNative](capi-imagepacker-opts-.md#oh_imagepacker_initnative)解析。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImagePacker_Native](capi-imagepacker-native-.md)* native | 表明native层{@link ImagePacker_Native}值的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回[IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode) IMAGE_RESULT_SUCCESS。 |

**参考：**

[OH_ImagePacker_InitNative](#oh_imagepacker_initnative)


