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
| [native_averrors.h](native__averrors_8h.md) | 声明了媒体播放框架的错误码。  | 
| [native_avformat.h](native__avformat_8h.md) | 声明了格式相关的函数和枚举。  | 
| [native_avmemory.h](native__avmemory_8h.md) | 声明了AVMemory的函数接口。  | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) | typedef enum [OH_AVErrCode](#oh_averrcode)<br/>音视频错误码。  | 
| **OH_AVFormat** | typedef struct OH_AVFormat | 
| [OH_AVPixelFormat](#oh_avpixelformat) | typedef enum [OH_AVPixelFormat](#oh_avpixelformat)<br/>AVPixel 格式的枚举。  | 
| **OH_AVMemory** | typedef struct OH_AVMemory | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) {<br/>**AV_ERR_OK** = 0, **AV_ERR_NO_MEMORY** = 1, **AV_ERR_OPERATE_NOT_PERMIT** = 2, **AV_ERR_INVALID_VAL** = 3, **AV_ERR_IO** = 4, **AV_ERR_TIMEOUT** = 5, **AV_ERR_UNKNOWN** = 6, **AV_ERR_SERVICE_DIED** = 7, **AV_ERR_INVALID_STATE** = 8, **AV_ERR_UNSUPPORT** = 9, **AV_ERR_EXTEND_START** = 100<br/>} | 音视频错误码。  |
| [OH_AVPixelFormat](#oh_avpixelformat) {<br/>**AV_PIXEL_FORMAT_YUVI420** = 1, **AV_PIXEL_FORMAT_NV12** = 2, **AV_PIXEL_FORMAT_NV21** = 3, **AV_PIXEL_FORMAT_SURFACE_FORMAT** = 4, **AV_PIXEL_FORMAT_RGBA** = 5<br/>} | AVPixel 格式的枚举。  |


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVFormat_Create](#oh_avformat_create) (void) | struct OH_AVFormat \*<br/>创建一个OH_AVFormat句柄指针，用以读写数据。  | 
| [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct OH_AVFormat \*format) | void<br/>销毁指定OH_AVFormat句柄资源。  | 
| [OH_AVFormat_Copy](#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | bool<br/>拷贝OH_AVFormat句柄资源.  | 
| [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | bool<br/>向OH_AVFormat写入Int数据.  | 
| [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | bool<br/>向OH_AVFormat写入Long数据。  | 
| [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | bool<br/>向OH_AVFormat写入Float数据。  | 
| [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | bool<br/>向OH_AVFormat写入Double数据。  | 
| [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | bool<br/>向OH_AVFormat写入String数据。  | 
| [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | bool<br/>向OH_AVFormat写入一块指定长度的数据。  | 
| [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | bool<br/>从OH_AVFormat读取Int数据。  | 
| [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | bool<br/>从OH_AVFormat读取Long数据。  | 
| [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | bool<br/>从OH_AVFormat读取Float数据。  | 
| [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | bool<br/>从OH_AVFormat读取Double数据。  | 
| [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | bool<br/>从OH_AVFormat读取Double数据。  | 
| [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | bool<br/>从OH_AVFormat读取一块指定长度的数据。  | 
| [OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) | const char \*<br/>以字符串的形式输出OH_AVFormat所包含的信息。  | 
| [OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct OH_AVMemory \*mem) | uint8_t \*<br/>获取入参的内存虚拟地址。  | 
| [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct OH_AVMemory \*mem) | int32_t<br/>获取入参的内存长度。  | 


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
| AV_ERR_OK  | 操作成功 | 
| AV_ERR_NO_MEMORY  | 无内存 | 
| AV_ERR_OPERATE_NOT_PERMIT  | 无效参数 | 
| AV_ERR_INVALID_VAL  | 无效值 | 
| AV_ERR_IO  | IO 错误 | 
| AV_ERR_TIMEOUT  | 超时错误 | 
| AV_ERR_UNKNOWN  | 未知错误 | 
| AV_ERR_SERVICE_DIED  | 媒体服务死亡 | 
| AV_ERR_INVALID_STATE  | 当前状态不支持此操作 | 
| AV_ERR_UNSUPPORT  | 未支持的接口 | 
| AV_ERR_EXTEND_START  | 扩展错误码初始值 | 


### OH_AVPixelFormat

  
```
enum OH_AVPixelFormat
```
**描述:**
AVPixel 格式的枚举。

@syscap SystemCapability.Multimedia.Media.Core

  | 枚举值 | 描述 | 
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420  | yuv 420 planar | 
| AV_PIXEL_FORMAT_NV12  | NV12. yuv 420 semiplanar | 
| AV_PIXEL_FORMAT_NV21  | NV21. yvu 420 semiplanar | 
| AV_PIXEL_FORMAT_SURFACE_FORMAT  | surface格式 | 
| AV_PIXEL_FORMAT_RGBA  | RGBA8888 | 


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
| to | 接收数据的OH_AVFormat句柄指针  | 
| from | 被拷贝数据的OH_AVFormat句柄指针  | 

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
| format | 指向OH_AVFormat实例的指针  | 

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
| format | 指向OH_AVFormat实例的指针  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读写数据的键值  | 
| addr | 生命周期是format持有，伴随format销毁，如果调用者需要长期持有，必须进行内存拷贝  | 
| size | 读写数据的长度  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读取数据的键值  | 
| out | 读取的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读取数据的键值  | 
| out | 读取的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读取数据的键值  | 
| out | 读取的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读取数据的键值  | 
| out | 读取的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 读取数据的键值  | 
| out | 读取的字符串指针，指向的数据生命周期伴随GetString更新，伴随format销毁，如果调用者需要长期持有，必须进行内存拷贝  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| addr | 写入的数据地址  | 
| size | 写入的数据长度  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| value | 写入的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| value | 写入的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| value | 写入的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| value | 写入的数据  | 

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
| format | 指向OH_AVFormat实例的指针  | 
| key | 写入数据的键值  | 
| value | 写入的数据  | 

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
| mem | 指向OH_AVMemory实例的指针  | 

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
| mem | 指向OH_AVMemory实例的指针  | 

**返回:**

如果内存有效，返回内存长度

如果内存无效，返回-1
