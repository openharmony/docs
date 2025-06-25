# OH_PackingOptions

## 概述

OH_PackingOptions是native层封装的图像编码选项结构体，OH_PackingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建PackingOptions结构体的对象使用[OH_PackingOptions_Create](capi-image-packer-native-h.md#oh_packingoptions_create)函数。

释放OH_PackingOptions对象使用[OH_PackingOptions_Release](capi-image-packer-native-h.md#oh_packingoptions_release)函数。

OH_PackingOptions结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| Image_MimeType | mimeType | MIME类型 | [OH_PackingOptions_GetMimeType](capi-image-packer-native-h.md#oh_packingoptions_getmimetype) | 获取MIME类型。|
| Image_MimeType | mimeType | MIME类型 | [OH_PackingOptions_SetMimeType](capi-image-packer-native-h.md#oh_packingoptions_setmimetype) | 设置MIME类型。|
| uint32_t | quality | 编码质量 | [OH_PackingOptions_GetQuality](capi-image-packer-native-h.md#oh_packingoptions_getquality) | 获取编码质量。|
| uint32_t | quality | 编码质量 | [OH_PackingOptions_SetQuality](capi-image-packer-native-h.md#oh_packingoptions_setquality) | 设置编码质量。|
| int32_t | desiredDynamicRange | 图片动态范围 | [OH_PackingOptions_GetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_getdesireddynamicrange) | 获取编码时期望的图片动态范围。|
| int32_t | desiredDynamicRange | 图片动态范围 | [OH_PackingOptions_SetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_setdesireddynamicrange) | 设置编码时期望的图片动态范围。|

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_packer_native.h](capi-image-packer-native-h.md)