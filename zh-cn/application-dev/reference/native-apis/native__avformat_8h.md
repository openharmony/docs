# native_avformat.h


## 概述

声明了格式相关的函数和枚举。

**Since:**
9
**Version:**
1.0
**相关模块:**

[Core](_core.md)


## 汇总


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| **OH_AVFormat** | typedef struct OH_AVFormat | 
| [OH_AVPixelFormat](_core.md#ohavpixelformat) | typedef enum [OH_AVPixelFormat](_core.md#ohavpixelformat)<br/>AVPixel 格式的枚举。  | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#ohavpixelformat) {<br/> **AV_PIXEL_FORMAT_YUVI420** = 1,  **AV_PIXEL_FORMAT_NV12** = 2,  **AV_PIXEL_FORMAT_NV21** = 3,  **AV_PIXEL_FORMAT_SURFACE_FORMAT** = 4,  **AV_PIXEL_FORMAT_RGBA** = 5<br/>} | AVPixel 格式的枚举。  | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVFormat_Create](_core.md#ohavformatcreate) (void) | struct OH_AVFormat \*<br/>创建一个OH_AVFormat句柄指针，用以读写数据。  | 
| [OH_AVFormat_Destroy](_core.md#ohavformatdestroy) (struct OH_AVFormat \*format) | void<br/>销毁指定OH_AVFormat句柄资源。  | 
| [OH_AVFormat_Copy](_core.md#ohavformatcopy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | bool<br/>拷贝OH_AVFormat句柄资源.  | 
| [OH_AVFormat_SetIntValue](_core.md#ohavformatsetintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | bool<br/>向OH_AVFormat写入Int数据.  | 
| [OH_AVFormat_SetLongValue](_core.md#ohavformatsetlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | bool<br/>向OH_AVFormat写入Long数据。  | 
| [OH_AVFormat_SetFloatValue](_core.md#ohavformatsetfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | bool<br/>向OH_AVFormat写入Float数据。  | 
| [OH_AVFormat_SetDoubleValue](_core.md#ohavformatsetdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | bool<br/>向OH_AVFormat写入Double数据。  | 
| [OH_AVFormat_SetStringValue](_core.md#ohavformatsetstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | bool<br/>向OH_AVFormat写入String数据。  | 
| [OH_AVFormat_SetBuffer](_core.md#ohavformatsetbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | bool<br/>向OH_AVFormat写入一块指定长度的数据。  | 
| [OH_AVFormat_GetIntValue](_core.md#ohavformatgetintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | bool<br/>从OH_AVFormat读取Int数据。  | 
| [OH_AVFormat_GetLongValue](_core.md#ohavformatgetlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | bool<br/>从OH_AVFormat读取Long数据。  | 
| [OH_AVFormat_GetFloatValue](_core.md#ohavformatgetfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | bool<br/>从OH_AVFormat读取Float数据。  | 
| [OH_AVFormat_GetDoubleValue](_core.md#ohavformatgetdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | bool<br/>从OH_AVFormat读取Double数据。  | 
| [OH_AVFormat_GetStringValue](_core.md#ohavformatgetstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | bool<br/>从OH_AVFormat读取Double数据。  | 
| [OH_AVFormat_GetBuffer](_core.md#ohavformatgetbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | bool<br/>从OH_AVFormat读取一块指定长度的数据。  | 
| [OH_AVFormat_DumpInfo](_core.md#ohavformatdumpinfo) (struct OH_AVFormat \*format) | const char \*<br/>以字符串的形式输出OH_AVFormat所包含的信息。  | 
