# OH_ImageSourceNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## 概述

OH_ImageSourceNative是native层封装的ImageSource结构体，用于创建图片数据。OH_ImageSourceNative结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

有多种方式创建OH_ImageSourceNative，具体如下：

| 函数 | 描述 |
| -------- | -------- |
| [OH_ImageSourceNative_CreateFromUri](capi-image-source-native-h.md#oh_imagesourcenative_createfromuri) |通过uri创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromFd](capi-image-source-native-h.md#oh_imagesourcenative_createfromfd) |通过fd创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromData](capi-image-source-native-h.md#oh_imagesourcenative_createfromdata) |通过缓冲区数据创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromRawFile](capi-image-source-native-h.md#oh_imagesourcenative_createfromrawfile) |通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap) |通过图片解码参数创建OH_PixelmapNative对象。|
| [OH_ImageSourceNative_CreatePixelmapList](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmaplist) |通过图片解码参数创建OH_PixelmapNative数组。|

释放OH_ImageSourceNative对象使用[OH_ImageSourceNative_Release](capi-image-source-native-h.md#oh_imagesourcenative_release)函数。

OH_ImageSourceNative结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| int32_t | delayTimeList | 图像延迟时间数组 | [OH_ImageSourceNative_GetDelayTimeList](capi-image-source-native-h.md#oh_imagesourcenative_getdelaytimelist) |获取图像延迟时间数组。 |
| OH_ImageSource_Info | info | ImageSource信息 | [OH_ImageSourceNative_GetImageInfo](capi-image-source-native-h.md#oh_imagesourcenative_getimageinfo) |获取指定序号的图片信息。|
| Image_String | value | 配置项 | [OH_ImageSourceNative_GetImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) |获取图片指定属性键的值。|
| Image_String | value | 配置项 | [OH_ImageSourceNative_ModifyImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty) |通过指定的键修改图片属性的值。|
| uint32_t | frameCount | 图像帧数 | [OH_ImageSourceNative_GetFrameCount](capi-image-source-native-h.md#oh_imagesourcenative_getframecount) |获取图像帧数。|

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_source_native.h](capi-image-source-native-h.md)