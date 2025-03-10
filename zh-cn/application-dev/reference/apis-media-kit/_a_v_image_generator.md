# AVImageGenerator


## 概述

提供用于从视频资源中获取指定时间视频帧的API。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [avimage_generator.h](avimage__generator_8h.md) | 定义AVImageGenerator接口。使用AVImageGenerator提供的Native API从视频资源中获取指定时间视频帧。  | 
| [avimage_generator_base.h](avimage__generator__base_8h.md) | 定义AVImageGenerator的枚举。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVImageGenerator](#oh_avimagegenerator) [OH_AVImageGenerator](#oh_avimagegenerator) | 定义OH_AVImageGenerator类型。  | 
| typedef enum [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1) [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions) | 指定时间点与视频帧对应关系的枚举。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1) {<br> OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC = 0,<br>  OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC = 1, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC = 2, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST = 3 } | 指定时间点与视频帧对应关系的枚举。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVImageGenerator](#oh_avimagegenerator) \* [OH_AVImageGenerator_Create](#oh_avimagegenerator_create) (void) | 创建OH_AVImageGenerator实例。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_SetFDSource](#oh_avimagegenerator_setfdsource) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator, int32_t fd, int64_t offset, int64_t size) | 通过媒体文件描述设置数据源。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_FetchFrameByTime](#oh_avimagegenerator_fetchframebytime) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator, int64_t timeUs, [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions) options, OH_PixelmapNative \*\*pixelMap) | 从视频资源中获取特定时间的视频帧。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_Release](#oh_avimagegenerator_release) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator) | 释放用于OH_AVImageGenerator的资源以及销毁OH_AVImageGenerator对象。  | 


## 类型定义说明


### OH_AVImageGenerator

```
typedef struct OH_AVImageGenerator OH_AVImageGenerator
```
**描述**
定义OH_AVImageGenerator类型。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


### OH_AVImageGenerator_QueryOptions

```
typedef enum OH_AVImageGenerator_QueryOptions OH_AVImageGenerator_QueryOptions
```
**描述**
指定时间点与视频帧对应关系的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


## 枚举类型说明


### OH_AVImageGenerator_QueryOptions

```
enum OH_AVImageGenerator_QueryOptions
```
**描述**
指定时间点与视频帧对应关系的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC  | 此选项用于选取传入时间点或之后的关键帧。   | 
| OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC  | 此选项用于选取传入时间点或之前的关键帧。   | 
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC  | 此选项用于选取离传入时间点最近的关键帧。   | 
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST  | 此选项用于选取离传入时间点最近的帧，该帧不一定是关键帧。   | 


## 函数说明


### OH_AVImageGenerator_Create()

```
OH_AVImageGenerator* OH_AVImageGenerator_Create(void)
```
**描述**
创建OH_AVImageGenerator实例。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

**返回：**

如果创建成功返回指向OH_AVImageGenerator实例的指针，否则返回空指针。

可能的失败原因：HstEngineFactory未能创建AVMetadataHelperEngine。


### OH_AVImageGenerator_FetchFrameByTime()

```
OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator, int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)
```
**描述**
从视频资源中获取特定时间的视频帧。

此函数必须在[SetFDSource](#oh_avimagegenerator_setfdsource)之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| generator | 指向OH_AVImageGenerator实例的指针。  | 
| timeUs | 需要获取的视频帧在视频中的时间点，单位为微秒（μs）。  | 
| options | 关于给定时间Us和视频帧之间关系的时间选项，请参阅[OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1)。  | 
| pixelMap | 获取的视频帧对象。详细信息请参阅{@link OH_PixelmapNative}。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入generator为空指针或者输入参数无效。

AV_ERR_OPERATE_NOT_PERMIT：操作不允许。

AV_ERR_UNSUPPORTED_FORMAT：格式不支持。

AV_ERR_NO_MEMORY：内部内存分配失败。

### OH_AVImageGenerator_Release()

```
OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)
```
**描述**
释放用于OH_AVImageGenerator的资源以及销毁OH_AVImageGenerator对象。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| generator | 指向OH_AVImageGenerator实例的指针。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入generator为空指针或者输入参数无效。


### OH_AVImageGenerator_SetFDSource()

```
OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator, int32_t fd, int64_t offset, int64_t size)
```
**描述**
通过媒体文件描述设置数据源。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| generator | 指向OH_AVImageGenerator实例的指针。  | 
| fd | 媒体源的文件描述符。  | 
| offset | 媒体源在文件描述符中的偏移量。  | 
| size | 媒体源的大小。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入generator为空指针或者输入参数无效。

AV_ERR_OPERATE_NOT_PERMIT：操作不允许。

AV_ERR_NO_MEMORY：内部内存分配失败。
