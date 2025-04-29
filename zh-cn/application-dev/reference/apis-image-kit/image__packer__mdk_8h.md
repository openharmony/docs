# image_packer_mdk.h


## 概述

声明用于将图像编码到缓冲区或文件的方法。

可用于将像素数据编码到目标缓冲区或文件中。

编码过程如下：

通过OH_ImagePacker_Create方法创建编码器实例对象。

然后通过OH_ImagePacker_InitNative将编码器实例对象转换为编码器原生实例对象。

接下来用OH_ImagePacker_PackToData或者OH_ImagePacker_PackToFile将源以特定的编码选项编码进目标区域。

最后通过OH_ImagePacker_Release释放编码器实例对象。

**库：** libimage_packer_ndk.z.so

**引用文件**：&lt;multimedia/image_framework/image_packer_mdk.h&gt;

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 11

**相关模块：** [Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [ImagePacker_Opts_](_image_packer___opts__.md) | 定义图像编码选项信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ImagePacker_Native_ [ImagePacker_Native](image.md#imagepacker_native) | 为编码器方法定义native层编码器对象。  | 
| typedef struct [ImagePacker_Opts_](_image_packer___opts__.md) [ImagePacker_Opts](image.md#imagepacker_opts) | 定义图像编码选项的别名。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ImagePacker_Create](image.md#oh_imagepacker_create) (napi_env env, napi_value \*res) | 获取JavaScript native层API ImagePacker对象。  | 
| [ImagePacker_Native](image.md#imagepacker_native) \* [OH_ImagePacker_InitNative](image.md#oh_imagepacker_initnative) (napi_env env, napi_value packer) | 从输入JavaScript native层API ImagePacker对象中，转换成ImagePacker_Native值。  | 
| int32_t [OH_ImagePacker_PackToData](image.md#oh_imagepacker_packtodata) ([ImagePacker_Native](image.md#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](image.md#imagepacker_opts) \*opts, uint8_t \*outData, size_t \*size) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出到指定的缓存区outData中。 | 
| int32_t [OH_ImagePacker_PackToFile](image.md#oh_imagepacker_packtofile) ([ImagePacker_Native](image.md#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](image.md#imagepacker_opts) \*opts, int fd) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层API PixelMap对象或者ImageSource对象编码并输出到指定的文件中。 | 
| int32_t [OH_ImagePacker_Release](image.md#oh_imagepacker_release) ([ImagePacker_Native](image.md#imagepacker_native) \*native) | 释放native层编码器对象[ImagePacker_Native](image.md#imagepacker_native)。 | 
