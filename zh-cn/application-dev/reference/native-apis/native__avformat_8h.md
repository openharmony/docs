# native_avformat.h


## 概述

声明了格式相关的函数和枚举。

**起始版本：**

9

**相关模块：**

[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat) | AVPixel 格式的枚举类。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_YUVI420 = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV12 = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV21 = 3,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_RGBA = 5<br/>} | AVPixel 格式的枚举类。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVFormat_Create](_core.md#oh_avformat_create) (void) | 创建OH_AVFormat句柄，用于读取数据。 | 
| \*[OH_AVFormat_CreateAudioFormat](_core.md#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | 创建音频OH_AVFormat句柄指针，用于读写数据。 | 
| \*[OH_AVFormat_CreateVideoFormat](_core.md#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | 创建视频OH_AVFormat句柄指针，用于读写数据。 | 
| [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) (struct OH_AVFormat \*format) | 销毁OH_AVFormat句柄。 | 
| [OH_AVFormat_Copy](_core.md#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | 复制OH_AVFormat句柄。 | 
| [OH_AVFormat_SetIntValue](_core.md#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | 将int数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetLongValue](_core.md#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | 将long数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetFloatValue](_core.md#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | 将float数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetDoubleValue](_core.md#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | 将double数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetStringValue](_core.md#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | 将string数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetBuffer](_core.md#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | 将指定长度的数据块写入OH_AVFormat。 | 
| [OH_AVFormat_GetIntValue](_core.md#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | 从OH_AVFormat读取int数据。 | 
| [OH_AVFormat_GetLongValue](_core.md#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | 从OH_AVFormat读取long数据。 | 
| [OH_AVFormat_GetFloatValue](_core.md#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | 从OH_AVFormat读取float数据。 | 
| [OH_AVFormat_GetDoubleValue](_core.md#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | 从OH_AVFormat读取double数据。 | 
| [OH_AVFormat_GetStringValue](_core.md#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | 从OH_AVFormat读取string数据。 | 
| [OH_AVFormat_GetBuffer](_core.md#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | 从OH_AVFormat中读取指定长度的数据块。 | 
| \*[OH_AVFormat_DumpInfo](_core.md#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) | 输出OH_AVFormat中包含的字符串。 | 
