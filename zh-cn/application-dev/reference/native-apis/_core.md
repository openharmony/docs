# Core


## 概述

Core模块提供用于播放框架的基础骨干能力，包含内存、错误码、格式载体等相关函数。

@syscap SystemCapability.Multimedia.Media.Core

**Since:**
9
**Version:**
1.0

## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [native_averrors.h](native__averrors_8h.md) | 声明了媒体播放框架的错误码。&nbsp; | 
| [native_avformat.h](native__avformat_8h.md) | 声明了格式相关的函数和枚举。&nbsp; | 
| [native_avmemory.h](native__avmemory_8h.md) | 声明了AVMemory的函数接口。&nbsp; | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#ohaverrcode) | typedef&nbsp;enum&nbsp;[OH_AVErrCode](#ohaverrcode)<br/>音视频错误码。&nbsp; | 
| **OH_AVFormat** | typedef&nbsp;struct&nbsp;OH_AVFormat | 
| [OH_AVPixelFormat](#ohavpixelformat) | typedef&nbsp;enum&nbsp;[OH_AVPixelFormat](#ohavpixelformat)<br/>AVPixel&nbsp;格式的枚举。&nbsp; | 
| **OH_AVMemory** | typedef&nbsp;struct&nbsp;OH_AVMemory | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#ohaverrcode)&nbsp;{<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref340209544182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1aeaf39666b93f2c3263e52b6bad3da8d2](#gga19325a2ffdf3a9a214794be3960bb3b1aeaf39666b93f2c3263e52b6bad3da8d2)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref570901527182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1ad4ba07b3fe5ca3df1f48345f7f9f631f](#gga19325a2ffdf3a9a214794be3960bb3b1ad4ba07b3fe5ca3df1f48345f7f9f631f)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref1914859333182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a2db9dd1e243f7738320dfa732f041669](#gga19325a2ffdf3a9a214794be3960bb3b1a2db9dd1e243f7738320dfa732f041669)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref943499574182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a96d898ca31466839ae39aede4e5266c2](#gga19325a2ffdf3a9a214794be3960bb3b1a96d898ca31466839ae39aede4e5266c2)&nbsp;=&nbsp;3,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref1846750760182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a70c6b7d0ba398f625e7b9741284e8d35](#gga19325a2ffdf3a9a214794be3960bb3b1a70c6b7d0ba398f625e7b9741284e8d35)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref1854271743182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1ad6ce699f9caf6cbff1b4b50c1b74d8ed](#gga19325a2ffdf3a9a214794be3960bb3b1ad6ce699f9caf6cbff1b4b50c1b74d8ed)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref837161067182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a7a9dc8845fe08a6f04adcf0997bddd85](#gga19325a2ffdf3a9a214794be3960bb3b1a7a9dc8845fe08a6f04adcf0997bddd85)&nbsp;=&nbsp;6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref270995748182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a71e0aa7596904781989f43490a4fad88](#gga19325a2ffdf3a9a214794be3960bb3b1a71e0aa7596904781989f43490a4fad88)&nbsp;=&nbsp;7,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref45008248182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a369dde180c1423e3d7a4844dcbf94938](#gga19325a2ffdf3a9a214794be3960bb3b1a369dde180c1423e3d7a4844dcbf94938)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref145173001182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a393021797634f5e26b1fcd16f701330d](#gga19325a2ffdf3a9a214794be3960bb3b1a393021797634f5e26b1fcd16f701330d)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref716387532182348,link:zh-cn_topic_0000001423612788.xml#gga19325a2ffdf3a9a214794be3960bb3b1a2c08394f90d05e0f08c5fe7b5fa243fd](#gga19325a2ffdf3a9a214794be3960bb3b1a2c08394f90d05e0f08c5fe7b5fa243fd)&nbsp;=&nbsp;100<br/>} | 音视频错误码。&nbsp; | 
| [OH_AVPixelFormat](#ohavpixelformat)&nbsp;{<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref31828121182348,link:zh-cn_topic_0000001423612788.xml#ggab04647d11a5a280f7427f9478ae2890ea961a1167e79625d6e72193f4fbb1add7](#ggab04647d11a5a280f7427f9478ae2890ea961a1167e79625d6e72193f4fbb1add7)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref815458069182348,link:zh-cn_topic_0000001423612788.xml#ggab04647d11a5a280f7427f9478ae2890eac65005d3e8437c615d4c4e051dfb4533](#ggab04647d11a5a280f7427f9478ae2890eac65005d3e8437c615d4c4e051dfb4533)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref1675247079182348,link:zh-cn_topic_0000001423612788.xml#ggab04647d11a5a280f7427f9478ae2890eab324169419f675fc7ab9a786a5588543](#ggab04647d11a5a280f7427f9478ae2890eab324169419f675fc7ab9a786a5588543)&nbsp;=&nbsp;3,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref60331776182348,link:zh-cn_topic_0000001423612788.xml#ggab04647d11a5a280f7427f9478ae2890eabc2c11f0feacf52e43b323383f486608](#ggab04647d11a5a280f7427f9478ae2890eabc2c11f0feacf52e43b323383f486608)&nbsp;=&nbsp;4,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423612788.xml#xref837555144182348,link:zh-cn_topic_0000001423612788.xml#ggab04647d11a5a280f7427f9478ae2890ea2c15b220da3b7e9043d41f6e789249f0](#ggab04647d11a5a280f7427f9478ae2890ea2c15b220da3b7e9043d41f6e789249f0)&nbsp;=&nbsp;5<br/>} | AVPixel&nbsp;格式的枚举。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVFormat_Create](#ohavformatcreate)&nbsp;(void) | struct&nbsp;OH_AVFormat&nbsp;\*<br/>创建一个OH_AVFormat句柄指针，用以读写数据。&nbsp; | 
| [OH_AVFormat_Destroy](#ohavformatdestroy)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format) | void<br/>销毁指定OH_AVFormat句柄资源。&nbsp; | 
| [OH_AVFormat_Copy](#ohavformatcopy)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*to,&nbsp;struct&nbsp;OH_AVFormat&nbsp;\*from) | bool<br/>拷贝OH_AVFormat句柄资源.&nbsp; | 
| [OH_AVFormat_SetIntValue](#ohavformatsetintvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int32_t&nbsp;value) | bool<br/>向OH_AVFormat写入Int数据.&nbsp; | 
| [OH_AVFormat_SetLongValue](#ohavformatsetlongvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int64_t&nbsp;value) | bool<br/>向OH_AVFormat写入Long数据。&nbsp; | 
| [OH_AVFormat_SetFloatValue](#ohavformatsetfloatvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;float&nbsp;value) | bool<br/>向OH_AVFormat写入Float数据。&nbsp; | 
| [OH_AVFormat_SetDoubleValue](#ohavformatsetdoublevalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;double&nbsp;value) | bool<br/>向OH_AVFormat写入Double数据。&nbsp; | 
| [OH_AVFormat_SetStringValue](#ohavformatsetstringvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;char&nbsp;\*value) | bool<br/>向OH_AVFormat写入String数据。&nbsp; | 
| [OH_AVFormat_SetBuffer](#ohavformatsetbuffer)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;uint8_t&nbsp;\*addr,&nbsp;size_t&nbsp;size) | bool<br/>向OH_AVFormat写入一块指定长度的数据。&nbsp; | 
| [OH_AVFormat_GetIntValue](#ohavformatgetintvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int32_t&nbsp;\*out) | bool<br/>从OH_AVFormat读取Int数据。&nbsp; | 
| [OH_AVFormat_GetLongValue](#ohavformatgetlongvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;int64_t&nbsp;\*out) | bool<br/>从OH_AVFormat读取Long数据。&nbsp; | 
| [OH_AVFormat_GetFloatValue](#ohavformatgetfloatvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;float&nbsp;\*out) | bool<br/>从OH_AVFormat读取Float数据。&nbsp; | 
| [OH_AVFormat_GetDoubleValue](#ohavformatgetdoublevalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;double&nbsp;\*out) | bool<br/>从OH_AVFormat读取Double数据。&nbsp; | 
| [OH_AVFormat_GetStringValue](#ohavformatgetstringvalue)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;const&nbsp;char&nbsp;\*\*out) | bool<br/>从OH_AVFormat读取Double数据。&nbsp; | 
| [OH_AVFormat_GetBuffer](#ohavformatgetbuffer)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;const&nbsp;char&nbsp;\*key,&nbsp;uint8_t&nbsp;\*\*addr,&nbsp;size_t&nbsp;\*size) | bool<br/>从OH_AVFormat读取一块指定长度的数据。&nbsp; | 
| [OH_AVFormat_DumpInfo](#ohavformatdumpinfo)&nbsp;(struct&nbsp;OH_AVFormat&nbsp;\*format) | const&nbsp;char&nbsp;\*<br/>以字符串的形式输出OH_AVFormat所包含的信息。&nbsp; | 
| [OH_AVMemory_GetAddr](#ohavmemorygetaddr)&nbsp;(struct&nbsp;OH_AVMemory&nbsp;\*mem) | uint8_t&nbsp;\*<br/>获取入参的内存虚拟地址。&nbsp; | 
| [OH_AVMemory_GetSize](#ohavmemorygetsize)&nbsp;(struct&nbsp;OH_AVMemory&nbsp;\*mem) | int32_t<br/>获取入参的内存长度。&nbsp; | 


## 类型定义说明


### OH_AVErrCode

  
```
typedef enum OH_AVErrCodeOH_AVErrCode
```
**描述:**
音视频错误码。

@syscap SystemCapability.Multimedia.Media.Core


### OH_AVPixelFormat

  
```
typedef enum OH_AVPixelFormatOH_AVPixelFormat
```
**描述:**
AVPixel 格式的枚举。

@syscap SystemCapability.Multimedia.Media.Core


## 枚举类型说明


### OH_AVErrCode

  
```
enum OH_AVErrCode
```
**描述:**
音视频错误码。

@syscap SystemCapability.Multimedia.Media.Core

  | 枚举值 | 描述 | 
| -------- | -------- |
| AV_ERR_OK&nbsp; | 操作成功 | 
| AV_ERR_NO_MEMORY&nbsp; | 无内存 | 
| AV_ERR_OPERATE_NOT_PERMIT&nbsp; | 无效参数 | 
| AV_ERR_INVALID_VAL&nbsp; | 无效值 | 
| AV_ERR_IO&nbsp; | IO&nbsp;错误 | 
| AV_ERR_TIMEOUT&nbsp; | 超时错误 | 
| AV_ERR_UNKNOWN&nbsp; | 未知错误 | 
| AV_ERR_SERVICE_DIED&nbsp; | 媒体服务死亡 | 
| AV_ERR_INVALID_STATE&nbsp; | 当前状态不支持此操作 | 
| AV_ERR_UNSUPPORT&nbsp; | 未支持的接口 | 
| AV_ERR_EXTEND_START&nbsp; | 扩展错误码初始值 | 


### OH_AVPixelFormat

  
```
enum OH_AVPixelFormat
```
**描述:**
AVPixel 格式的枚举。

@syscap SystemCapability.Multimedia.Media.Core

  | 枚举值 | 描述 | 
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420&nbsp; | yuv&nbsp;420&nbsp;planar | 
| AV_PIXEL_FORMAT_NV12&nbsp; | NV12.&nbsp;yuv&nbsp;420&nbsp;semiplanar | 
| AV_PIXEL_FORMAT_NV21&nbsp; | NV21.&nbsp;yvu&nbsp;420&nbsp;semiplanar | 
| AV_PIXEL_FORMAT_SURFACE_FORMAT&nbsp; | surface格式 | 
| AV_PIXEL_FORMAT_RGBA&nbsp; | RGBA8888 | 


## 函数说明


### OH_AVFormat_Copy()

  
```
bool OH_AVFormat_Copy (struct OH_AVFormat * to, struct OH_AVFormat * from )
```
**描述:**
拷贝OH_AVFormat句柄资源.

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| to | 接收数据的OH_AVFormat句柄指针&nbsp; | 
| from | 被拷贝数据的OH_AVFormat句柄指针&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_Create()

  
```
struct OH_AVFormat* OH_AVFormat_Create (void )
```
**描述:**
创建一个OH_AVFormat句柄指针，用以读写数据。

@syscap SystemCapability.Multimedia.Media.Core

**返回:**

返回OH_AVFormat实例的指针


### OH_AVFormat_Destroy()

  
```
void OH_AVFormat_Destroy (struct OH_AVFormat * format)
```
**描述:**
销毁指定OH_AVFormat句柄资源。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 

**返回:**

void


### OH_AVFormat_DumpInfo()

  
```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat * format)
```
**描述:**
以字符串的形式输出OH_AVFormat所包含的信息。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 

**返回:**

返回由键值和数据组成的字符串指针


### OH_AVFormat_GetBuffer()

  
```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat * format, const char * key, uint8_t ** addr, size_t * size )
```
**描述:**
从OH_AVFormat读取一块指定长度的数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读写数据的键值&nbsp; | 
| addr | 生命周期是format持有，伴随format销毁，如果调用者需要长期持有，必须进行内存拷贝&nbsp; | 
| size | 读写数据的长度&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_GetDoubleValue()

  
```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat * format, const char * key, double * out )
```
**描述:**
从OH_AVFormat读取Double数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读取数据的键值&nbsp; | 
| out | 读取的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_GetFloatValue()

  
```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat * format, const char * key, float * out )
```
**描述:**
从OH_AVFormat读取Float数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读取数据的键值&nbsp; | 
| out | 读取的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_GetIntValue()

  
```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat * format, const char * key, int32_t * out )
```
**描述:**
从OH_AVFormat读取Int数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读取数据的键值&nbsp; | 
| out | 读取的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_GetLongValue()

  
```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat * format, const char * key, int64_t * out )
```
**描述:**
从OH_AVFormat读取Long数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读取数据的键值&nbsp; | 
| out | 读取的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_GetStringValue()

  
```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat * format, const char * key, const char ** out )
```
**描述:**
从OH_AVFormat读取Double数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 读取数据的键值&nbsp; | 
| out | 读取的字符串指针，指向的数据生命周期伴随GetString更新，伴随format销毁，如果调用者需要长期持有，必须进行内存拷贝&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetBuffer()

  
```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat * format, const char * key, const uint8_t * addr, size_t size )
```
**描述:**
向OH_AVFormat写入一块指定长度的数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| addr | 写入的数据地址&nbsp; | 
| size | 写入的数据长度&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetDoubleValue()

  
```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat * format, const char * key, double value )
```
**描述:**
向OH_AVFormat写入Double数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| value | 写入的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetFloatValue()

  
```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat * format, const char * key, float value )
```
**描述:**
向OH_AVFormat写入Float数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| value | 写入的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetIntValue()

  
```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat * format, const char * key, int32_t value )
```
**描述:**
向OH_AVFormat写入Int数据.

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| value | 写入的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetLongValue()

  
```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat * format, const char * key, int64_t value )
```
**描述:**
向OH_AVFormat写入Long数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| value | 写入的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVFormat_SetStringValue()

  
```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat * format, const char * key, const char * value )
```
**描述:**
向OH_AVFormat写入String数据。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针&nbsp; | 
| key | 写入数据的键值&nbsp; | 
| value | 写入的数据&nbsp; | 

**返回:**

返回值为TRUE表示成功

返回值为FALSE表示失败


### OH_AVMemory_GetAddr()

  
```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory * mem)
```
**描述:**
获取入参的内存虚拟地址。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针&nbsp; | 

**返回:**

如果内存有效，返回内存的虚拟地址

如果内存无效，返回nullptr


### OH_AVMemory_GetSize()

  
```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory * mem)
```
**描述:**
获取入参的内存长度。

@syscap SystemCapability.Multimedia.Media.Core

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针&nbsp; | 

**返回:**

如果内存有效，返回内存长度

如果内存无效，返回-1
