# image_packer_native.h


## 概述

图片编码API。

**库：** libimage_packer.so

**引用文件**：&lt;multimedia/image_framework/image/image_packer_native.h&gt;

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) | ImagePacker结构体类型，用于执行ImagePacker相关操作。 | 
| typedef struct [OH_PackingOptions](_image___native_module.md#oh_packingoptions) [OH_PackingOptions](_image___native_module.md#oh_packingoptions) | 图像编码选项。 | 
| typedef struct [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) | 图像序列编码选项。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IMAGE_PACKER_DYNAMIC_RANGE](_image___native_module.md#image_packer_dynamic_range) {<br/>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1<br/>} | 编码指定动态范围。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Create](_image___native_module.md#oh_packingoptions_create) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*\*options) | 创建PackingOptions结构体的指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetMimeType](_image___native_module.md#oh_packingoptions_getmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | 获取MIME类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetMimeType](_image___native_module.md#oh_packingoptions_setmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | 设置MIME类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetQuality](_image___native_module.md#oh_packingoptions_getquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t \*quality) | 获取编码质量。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetQuality](_image___native_module.md#oh_packingoptions_setquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t quality) | 设置编码质量。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | 获取编码时期望的图片动态范围。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t desiredDynamicRange) | 设置编码时期望的图片动态范围。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Release](_image___native_module.md#oh_packingoptions_release) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options) | 释放OH_PackingOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_Create](_image___native_module.md#oh_packingoptionsforsequence_create) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*\*options) | 创建OH_PackingOptionsForSequence结构体的指针。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetFrameCount](_image___native_module.md#oh_packingoptionsforsequence_setframecount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t frameCount) | 设置编码时指定的帧数。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetFrameCount](_image___native_module.md#oh_packingoptionsforsequence_getframecount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*frameCount) | 获取编码时指定的帧数。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetDelayTimeList](_image___native_module.md#oh_packingoptionsforsequence_setdelaytimelist) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | 设定编码时图片的延迟时间数组。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetDelayTimeList](_image___native_module.md#oh_packingoptionsforsequence_getdelaytimelist) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | 获取编码时图片的延迟时间数组。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetDisposalTypes](_image___native_module.md#oh_packingoptionsforsequence_setdisposaltypes) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | 设定编码时图片的过渡帧模式数组。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetDisposalTypes](_image___native_module.md#oh_packingoptionsforsequence_getdisposaltypes) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | 获取编码时图片的过渡帧模式数组。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetLoopCount](_image___native_module.md#oh_packingoptionsforsequence_setloopcount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t loopCount) | 设定编码时图片循环播放次数。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetLoopCount](_image___native_module.md#oh_packingoptionsforsequence_getloopcount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*loopCount) | 获取编码时图片循环播放次数。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_Release](_image___native_module.md#oh_packingoptionsforsequence_release) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options) | 释放OH_PackingOptionsForSequence指针。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Create](_image___native_module.md#oh_imagepackernative_create) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*imagePacker) | 创建OH_ImagePackerNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](_image___native_module.md#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | 将ImageSource编码为指定格式的数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](_image___native_module.md#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | 将Pixelmap编码为指定格式的数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPicture](_image___native_module.md#oh_imagepackernative_packtodatafrompicture) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, uint8_t \*outData, size_t \*size) | 将Picture编码为指定格式的数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmapSequence](_image___native_module.md#oh_imagepackernative_packtodatafrompixelmapsequence) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, uint8_t \*outData, size_t \*outDataSize) | 将Pixelmap序列编码为数据。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](_image___native_module.md#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, int32_t fd) | 将一个ImageSource编码到文件中。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](_image___native_module.md#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, int32_t fd) | 将一个Pixelmap编码到文件中。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPicture](_image___native_module.md#oh_imagepackernative_packtofilefrompicture) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, int32_t fd) | 将一个Picture编码到文件中。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmapSequence](_image___native_module.md#oh_imagepackernative_packtofilefrompixelmapsequence) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, int32_t fd) | 将一个Pixelmap序列编码到文件中。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Release](_image___native_module.md#oh_imagepackernative_release) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker) | 释放OH_ImagePackerNative指针。 | 
