# native_avformat.h


## 概述

声明了OH_AVFormat相关的函数和枚举。

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVFormat](_core.md#oh_avformat) [OH_AVFormat](_core.md#oh_avformat) | 为媒体格式接口定义native层对象。  |
| typedef enum [OH_AVPixelFormat](_core.md#oh_avpixelformat-1) [OH_AVPixelFormat](_core.md#oh_avpixelformat) | 视频像素格式的枚举类。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat-1) {<br/>AV_PIXEL_FORMAT_YUVI420 = 1,<br/>AV_PIXEL_FORMAT_NV12 = 2,<br/>AV_PIXEL_FORMAT_NV21 = 3,<br/>AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>AV_PIXEL_FORMAT_RGBA = 5<br/>} | 视频像素格式的枚举类 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_Create](_core.md#oh_avformat_create) (void) | 创建OH_AVFormat实例，用于读写数据。 | 
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_CreateAudioFormat](_core.md#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | 创建音频OH_AVFormat实例指针并预设置指定参数，用于读写数据。 | 
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_CreateVideoFormat](_core.md#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | 创建视频OH_AVFormat实例指针并预设置指定参数，用于读写数据。 | 
| void [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) (struct [OH_AVFormat](_core.md#oh_avformat) \*format) | 销毁OH_AVFormat实例。 | 
| bool [OH_AVFormat_Copy](_core.md#oh_avformat_copy) (struct [OH_AVFormat](_core.md#oh_avformat) \*to, struct [OH_AVFormat](_core.md#oh_avformat) \*from) | 复制OH_AVFormat实例。 | 
| bool [OH_AVFormat_SetIntValue](_core.md#oh_avformat_setintvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int32_t value) | 对OH_AVFormat的key赋int类型的值。 | 
| bool [OH_AVFormat_SetLongValue](_core.md#oh_avformat_setlongvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int64_t value) | 对OH_AVFormat的key赋long类型的值。 | 
| bool [OH_AVFormat_SetFloatValue](_core.md#oh_avformat_setfloatvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, float value) | 对OH_AVFormat的key赋float类型的值。 | 
| bool [OH_AVFormat_SetDoubleValue](_core.md#oh_avformat_setdoublevalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, double value) | 对OH_AVFormat的key赋double类型的值。 | 
| bool [OH_AVFormat_SetStringValue](_core.md#oh_avformat_setstringvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const char \*value) | 对OH_AVFormat的key赋string类型的值。 | 
| bool [OH_AVFormat_SetBuffer](_core.md#oh_avformat_setbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const uint8_t \*addr, size_t size) | 将指定长度的数据块写入OH_AVFormat。 | 
| bool [OH_AVFormat_GetIntValue](_core.md#oh_avformat_getintvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int32_t \*out) | 从OH_AVFormat的key获取int类型的值。 | 
| bool [OH_AVFormat_GetLongValue](_core.md#oh_avformat_getlongvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int64_t \*out) | 从OH_AVFormat的key获取long类型的值。 | 
| bool [OH_AVFormat_GetFloatValue](_core.md#oh_avformat_getfloatvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, float \*out) | 从OH_AVFormat的key获取float类型的值。 | 
| bool [OH_AVFormat_GetDoubleValue](_core.md#oh_avformat_getdoublevalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, double \*out) | 从OH_AVFormat的key获取double类型的值。 | 
| bool [OH_AVFormat_GetStringValue](_core.md#oh_avformat_getstringvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const char \*\*out) | 从OH_AVFormat的key获取string类型的值。 | 
| bool [OH_AVFormat_GetBuffer](_core.md#oh_avformat_getbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | 从OH_AVFormat中读取指定长度的数据块。 | 
| const char \* [OH_AVFormat_DumpInfo](_core.md#oh_avformat_dumpinfo) (struct [OH_AVFormat](_core.md#oh_avformat) \*format) | 返回OH_AVFormat中包含的key-value组成的字符串。 | 
