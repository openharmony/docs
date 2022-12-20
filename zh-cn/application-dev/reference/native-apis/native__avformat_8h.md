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
| **OH_AVFormat** | typedef&nbsp;struct&nbsp;OH_AVFormat | 
| [OH_AVPixelFormat](_core.md#ohavpixelformat) | typedef&nbsp;enum&nbsp;[OH_AVPixelFormat](_core.md#ohavpixelformat)<br/>AVPixel&nbsp;格式的枚举。&nbsp; | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#ohavpixelformat)&nbsp;{<br/>[AV_PIXEL_FORMAT_YUVI420](_core.md#ggab04647d11a5a280f7427f9478ae2890ea961a1167e79625d6e72193f4fbb1add7)&nbsp;=&nbsp;1,&nbsp;[AV_PIXEL_FORMAT_NV12](_core.md#ggab04647d11a5a280f7427f9478ae2890eac65005d3e8437c615d4c4e051dfb4533)&nbsp;=&nbsp;2,&nbsp;[AV_PIXEL_FORMAT_NV21](_core.md#ggab04647d11a5a280f7427f9478ae2890eab324169419f675fc7ab9a786a5588543)&nbsp;=&nbsp;3,&nbsp;[AV_PIXEL_FORMAT_SURFACE_FORMAT](_core.md#ggab04647d11a5a280f7427f9478ae2890eabc2c11f0feacf52e43b323383f486608)&nbsp;=&nbsp;4,<br/>[AV_PIXEL_FORMAT_RGBA](_core.md#ggab04647d11a5a280f7427f9478ae2890ea2c15b220da3b7e9043d41f6e789249f0)&nbsp;=&nbsp;5<br/>} | AVPixel&nbsp;格式的枚举。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVFormat_Create](_core.md#ohavformatcreate)&nbsp;(void) | struct&nbsp;OH_AVFormat&nbsp;\*<br/>创建一个OH_AVFormat句柄指针，用以读写数据。&nbsp; | 
| [OH_AVFormat_Destroy](_core.md#ohavformatdestroy)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format) | void<br/>销毁指定OH_AVFormat句柄资源。&nbsp; | 
| [OH_AVFormat_Copy](_core.md#ohavformatcopy)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*to,&nbsp;struct&nbsp;OH_AVFormat&nbsp;\*from) | bool<br/>拷贝OH_AVFormat句柄资源.&nbsp; | 
| [OH_AVFormat_SetIntValue](_core.md#ohavformatsetintvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int32_t&nbsp;value) | bool<br/>向OH_AVFormat写入Int数据.&nbsp; | 
| [OH_AVFormat_SetLongValue](_core.md#ohavformatsetlongvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int64_t&nbsp;value) | bool<br/>向OH_AVFormat写入Long数据。&nbsp; | 
| [OH_AVFormat_SetFloatValue](_core.md#ohavformatsetfloatvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;float&nbsp;value) | bool<br/>向OH_AVFormat写入Float数据。&nbsp; | 
| [OH_AVFormat_SetDoubleValue](_core.md#ohavformatsetdoublevalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;double&nbsp;value) | bool<br/>向OH_AVFormat写入Double数据。&nbsp; | 
| [OH_AVFormat_SetStringValue](_core.md#ohavformatsetstringvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;char&nbsp;\*value) | bool<br/>向OH_AVFormat写入String数据。&nbsp; | 
| [OH_AVFormat_SetBuffer](_core.md#ohavformatsetbuffer)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;uint8_t&nbsp;\*addr,&nbsp;size_t&nbsp;size) | bool<br/>向OH_AVFormat写入一块指定长度的数据。&nbsp; | 
| [OH_AVFormat_GetIntValue](_core.md#ohavformatgetintvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int32_t&nbsp;\*out) | bool<br/>从OH_AVFormat读取Int数据。&nbsp; | 
| [OH_AVFormat_GetLongValue](_core.md#ohavformatgetlongvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int64_t&nbsp;\*out) | bool<br/>从OH_AVFormat读取Long数据。&nbsp; | 
| [OH_AVFormat_GetFloatValue](_core.md#ohavformatgetfloatvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;float&nbsp;\*out) | bool<br/>从OH_AVFormat读取Float数据。&nbsp; | 
| [OH_AVFormat_GetDoubleValue](_core.md#ohavformatgetdoublevalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;double&nbsp;\*out) | bool<br/>从OH_AVFormat读取Double数据。&nbsp; | 
| [OH_AVFormat_GetStringValue](_core.md#ohavformatgetstringvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;char&nbsp;\*\*out) | bool<br/>从OH_AVFormat读取Double数据。&nbsp; | 
| [OH_AVFormat_GetBuffer](_core.md#ohavformatgetbuffer)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;uint8_t&nbsp;\*\*addr,&nbsp;size_t&nbsp;\*size) | bool<br/>从OH_AVFormat读取一块指定长度的数据。&nbsp; | 
| [OH_AVFormat_DumpInfo](_core.md#ohavformatdumpinfo)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format) | const&nbsp;char&nbsp;\*<br/>以字符串的形式输出OH_AVFormat所包含的信息。&nbsp; | 
