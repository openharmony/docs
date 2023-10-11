# Core


## 概述

Core模块提供用于播放框架的基础骨干能力，包含内存、错误码、格式载体等相关函数。

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_averrors.h](native__averrors_8h.md) | 声明了媒体播放框架的错误码。<br>**引用文件**：<multimedia/player_framework/native_averrors.h> <br>**库**：libnative_media_core.so | 
| [native_avformat.h](native__avformat_8h.md) | 声明了格式相关的函数和枚举。<br>**引用文件**：<multimedia/player_framework/native_avformat.h> <br>**库**：libnative_media_core.so | 
| [native_avmemory.h](native__avmemory_8h.md) | 声明了AVMemory的函数接口。<br>**引用文件**：<multimedia/player_framework/native_avmemory.h> <br>**库**：libnative_media_core.so | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) | 音视频错误码。 | 
| [OH_AVPixelFormat](#oh_avpixelformat) | AVPixel 格式的枚举类。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_OK = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_NO_MEMORY = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_OPERATE_NOT_PERMIT = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_INVALID_VAL = 3,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_IO = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_TIMEOUT = 5,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_UNKNOWN = 6,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_SERVICE_DIED = 7,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_INVALID_STATE = 8,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_UNSUPPORT = 9,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_EXTEND_START = 100<br/>} | 音视频错误码。 | 
| [OH_AVPixelFormat](#oh_avpixelformat) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_YUVI420 = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV12 = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV21 = 3,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_RGBA = 5<br/>} | AVPixel 格式的枚举类。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVFormat_Create](#oh_avformat_create) (void) | 创建OH_AVFormat句柄，用于读取数据。 | 
| \*[OH_AVFormat_CreateAudioFormat](#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | 创建音频OH_AVFormat句柄指针，用于读写数据。 | 
| \*[OH_AVFormat_CreateVideoFormat](#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | 创建视频OH_AVFormat句柄指针，用于读写数据。 | 
| [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct OH_AVFormat \*format) | 销毁OH_AVFormat句柄。 | 
| [OH_AVFormat_Copy](#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | 复制OH_AVFormat句柄。 | 
| [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | 将int数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | 将long数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | 将float数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | 将double数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | 将string数据写入OH_AVFormat。 | 
| [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | 将指定长度的数据块写入OH_AVFormat。 | 
| [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | 从OH_AVFormat读取int数据。 | 
| [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | 从OH_AVFormat读取long数据。 | 
| [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | 从OH_AVFormat读取float数据。 | 
| [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | 从OH_AVFormat读取double数据。 | 
| [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | 从OH_AVFormat读取string数据。 | 
| [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | 从OH_AVFormat中读取指定长度的数据块。 | 
| \*[OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) | 输出OH_AVFormat中包含的字符串。 | 
| \*[OH_AVMemory_Create](#oh_avmemory_create) (int32_t size) | 创建OH_AVMemory实例的指针。 | 
| \*[OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct OH_AVMemory \*mem) | 获取入参的内存虚拟地址。 | 
| [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct OH_AVMemory \*mem) | 获取入参的内存长度。 | 
| [OH_AVMemory_Destroy](#oh_avmemory_destroy) (struct OH_AVMemory \*mem) | 释放OH_AVMemory实例指针的资源。 | 


## 类型定义说明


### OH_AVErrCode

  
```
typedef enum OH_AVErrCode OH_AVErrCode
```

**描述：**

音视频错误码。

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

9


### OH_AVPixelFormat

  
```
typedef enum OH_AVPixelFormat OH_AVPixelFormat
```

**描述：**

视频像素格式的枚举类。

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

9


## 枚举类型说明


### OH_AVErrCode

  
```
enum OH_AVErrCode
```

**描述：**

音视频错误码。

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

9

| 枚举值 | 描述 |
| -------- | -------- |
| AV_ERR_OK | 操作成功 | 
| AV_ERR_NO_MEMORY | 无内存 | 
| AV_ERR_OPERATE_NOT_PERMIT | 操作不允许 | 
| AV_ERR_INVALID_VAL | 无效值 | 
| AV_ERR_IO | IO错误 | 
| AV_ERR_TIMEOUT | 超时错误 | 
| AV_ERR_UNKNOWN | 未知错误 | 
| AV_ERR_SERVICE_DIED | 服务死亡 | 
| AV_ERR_INVALID_STATE | 当前状态不支持此操作 | 
| AV_ERR_UNSUPPORT | 未支持的接口 | 
| AV_ERR_EXTEND_START | 扩展错误码初始值 | 


### OH_AVPixelFormat

  
```
enum OH_AVPixelFormat
```

**描述：**

视频像素格式的枚举类。

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

9

| 枚举值 | 描述 |
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420 | yuv 420 planar | 
| AV_PIXEL_FORMAT_NV12 | NV12. yuv 420 semiplanar | 
| AV_PIXEL_FORMAT_NV21 | NV21. yvu 420 semiplanar | 
| AV_PIXEL_FORMAT_SURFACE_FORMAT | surface格式 | 
| AV_PIXEL_FORMAT_RGBA | RGBA8888 | 


## 函数说明


### OH_AVFormat_Copy()

  
```
bool OH_AVFormat_Copy (struct OH_AVFormat *to, struct OH_AVFormat *from)
```

**描述：**

复制OH_AVFormat句柄。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| to | OH_AVFormat句柄，用于接收数据 | 
| from | 指向复制数据的OH_AVFormat句柄的指针 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_Create()

  
```
struct OH_AVFormat* OH_AVFormat_Create (void)
```

**描述：**

创建OH_AVFormat句柄，用于读取数据。

\@syscap SystemCapability.Multimedia.Media.Core

**返回：**

返回指向OH_AVFormat实例的指针

**起始版本：**

9


### OH_AVFormat_CreateAudioFormat()

  
```
struct OH_AVFormat* OH_AVFormat_CreateAudioFormat (const char *mimeType, int32_t sampleRate, int32_t channelCount)
```

**描述：**

创建音频OH_AVFormat句柄指针，用于读写数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量) | 
| sampleRate | 采样率，单位Hz。 | 
| channelCount | 声道个数，如1为单声道，2为双声道。 | 

**返回：**

返回指向OH_AVFormat实例的指针。

**起始版本：**

10


### OH_AVFormat_CreateVideoFormat()

  
```
struct OH_AVFormat* OH_AVFormat_CreateVideoFormat (const char *mimeType, int32_t width, int32_t height)
```

**描述：**

创建视频OH_AVFormat句柄指针，用于读写数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量) | 
| width | 宽度，单位为px。 | 
| height | 高度，单位为px。 | 

**返回：**

返回指向OH_AVFormat实例的指针。

**起始版本：**

10


### OH_AVFormat_Destroy()

  
```
void OH_AVFormat_Destroy (struct OH_AVFormat *format)
```

**描述：**

销毁OH_AVFormat句柄。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 

**起始版本：**

9


### OH_AVFormat_DumpInfo()

  
```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat *format)
```

**描述：**

输出OH_AVFormat中包含的字符串。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 

**返回：**

返回一个由key和data组成的字符串。

**起始版本：**

9


### OH_AVFormat_GetBuffer()

  
```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat *format, const char *key, uint8_t **addr, size_t *size)
```

**描述：**

从OH_AVFormat中读取指定长度的数据块。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读写数据的键。 | 
| addr | 生命周期与format相同，与format一同销毁。 如果调用者需要长时间保持它，必须进行内存拷贝。 | 
| size | 读写数据的长度。 | 

**返回：**

返回值为true表示成功，为false表示失败。

**起始版本：**

9


### OH_AVFormat_GetDoubleValue()

  
```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat *format, const char *key, double *out)
```

**描述：**

从OH_AVFormat读取double数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 读取数据的键 | 
| out | 读取数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_GetFloatValue()

  
```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat *format, const char *key, float *out)
```

**描述：**

从OH_AVFormat读取Float数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 读取数据的键 | 
| out | 读取数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_GetIntValue()

  
```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat *format, const char *key, int32_t *out)
```

**描述：**

从OH_AVFormat读取int数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 读取数据的键 | 
| out | 读取数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败


### OH_AVFormat_GetLongValue()

  
```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat *format, const char *key, int64_t *out)
```

**描述：**

从OH_AVFormat读取long数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 读取数据的键 | 
| out | 读取数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_GetStringValue()

  
```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat *format, const char *key, const char **out)
```

**描述：**

从OH_AVFormat读取string数据。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 读取数据的键 | 
| out | 读取string指针，out数据的生命周期与format内string对应。 如果调用者需要长时间保持它，必须内存拷贝 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetBuffer()

  
```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)
```

**描述：**

将指定长度的数据块写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| addr | 写入数据的地址 | 
| size | 写入数据的长度 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetDoubleValue()

  
```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat *format, const char *key, double value)
```

**描述：**

将double数据写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| value | 写入数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetFloatValue()

  
```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat *format, const char *key, float value)
```

**描述：**

将float数据写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| value | 写入数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetIntValue()

  
```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat *format, const char *key, int32_t value)
```

**描述：**

将int数据写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| value | 写入数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetLongValue()

  
```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat *format, const char *key, int64_t value)
```

**描述：**

将long数据写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| value | 写入数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVFormat_SetStringValue()

  
```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat *format, const char *key, const char *value)
```

**描述：**

将string数据写入OH_AVFormat。

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针 | 
| key | 写入数据的键 | 
| value | 写入数据的值 | 

**返回：**

返回值为true表示成功，为false表示失败

**起始版本：**

9


### OH_AVMemory_Create()

  
```
OH_AVMemory* OH_AVMemory_Create (int32_t size)
```

**描述：**

创建OH_AVMemory实例的指针

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| size | 创建内存的大小，单位字节 | 

**返回：**

如果创建成功返回OH_AVMemory实例的指针，如果失败，返回nullptr， 使用结束后需要通过OH_AVMemory_Destroy释放内存

**起始版本：**

10


### OH_AVMemory_Destroy()

  
```
OH_AVErrCode OH_AVMemory_Destroy (struct OH_AVMemory *mem)
```

**描述：**

释放OH_AVMemory实例指针的资源

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针 | 

**返回：**

如果释放成功返回AV_ERR_OK, 如果失败返回具体错误码, 参考[OH_AVErrCode](#oh_averrcode)

**起始版本：**

10


### OH_AVMemory_GetAddr()

  
```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory *mem)
```

**描述：**

获取入参的内存虚拟地址

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针 | 

**返回：**

如果内存有效，返回内存的虚拟地址，如果内存无效，返回nullptr

**起始版本：**

9


### OH_AVMemory_GetSize()

  
```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory *mem)
```

**描述：**

获取入参的内存长度

\@syscap SystemCapability.Multimedia.Media.Core

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针 | 

**返回：**

如果内存有效，返回内存长度，如果内存无效，返回-1

**起始版本：**

9
