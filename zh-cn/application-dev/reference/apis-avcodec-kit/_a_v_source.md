# AVSource


## 概述

AVSource模块提供用于构造媒体资源对象功能的函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avsource.h](native__avsource_8h.md) | 声明用于音视频媒体数据解析的接口。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVSource](#oh_avsource) [OH_AVSource](#oh_avsource) | 为媒体资源接口定义native层对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithDataSource](#oh_avsource_createwithdatasource) ([OH_AVDataSource](_o_h___a_v_data_source.md) \*dataSource) | 为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用OH_AVSource_Destroy接口释放实例。  |
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithURI](#oh_avsource_createwithuri) (char \*uri) | 为统一资源标识符对应的的资源对象创建OH_AVSource实例。  | 
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithFD](#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | 为文件描述符对应的资源对象创建OH_AVSource实例。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVSource_Destroy](#oh_avsource_destroy) ([OH_AVSource](#oh_avsource) \*source) | 销毁OH_AVSource实例并清理内部资源。  | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetSourceFormat](#oh_avsource_getsourceformat) ([OH_AVSource](#oh_avsource) \*source) | 获取媒体资源文件的基础信息。  | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetTrackFormat](#oh_avsource_gettrackformat) ([OH_AVSource](#oh_avsource) \*source, uint32_t trackIndex) | 获取轨道的基础信息。  | 


## 类型定义说明


### OH_AVSource

```
typedef struct OH_AVSource OH_AVSource
```
**描述**
为媒体资源接口定义native层对象。

**起始版本：** 10


## 函数说明


### OH_AVSource_CreateWithDataSource()

```
OH_AVSource* OH_AVSource_CreateWithDataSource (OH_AVDataSource * dataSource)
```
**描述**
为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用OH_AVSource_Destroy接口释放实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dataSource | 用户自定义数据源。  | 

**返回：**

如果执行成功，则返回一个指向OH_AVSource实例的指针，否则返回NULL。

可能的故障原因：
1. dataSource为nullptr；
2. dataSource-&gt;size == 0；
3. 设置数据源失败；
4. 内存不足；
5. 解码器引擎为nullptr。 


### OH_AVSource_CreateWithFD()

```
OH_AVSource* OH_AVSource_CreateWithFD (int32_t fd, int64_t offset, int64_t size)
```
**描述**
为文件描述符对应的资源对象创建OH_AVSource实例。可以通过调用OH_AVSource_Destroy接口释放实例。

该接口如果传入offset不为文件起始位置，或size不为文件大小时，可能会因数据获取不完整导致 OH_AVSource创建失败、后续解封装失败等未定义错误。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 数据资源的文件描述符。  | 
| offset | 开始读取数据的位置。  | 
| size | 文件的字节数大小。  | 

**返回：**

执行成功返回一个指向OH_AVSource实例的指针, 否则返回NULL。

可能的故障原因：

1. fd无效；
2. 传入offset不是文件起始位置；
3. size错误；
4. 资源无效；
5. 文件格式不支持。 


### OH_AVSource_CreateWithURI()

```
OH_AVSource* OH_AVSource_CreateWithURI (char *uri)
```
**描述**
为统一资源标识符对应的的资源对象创建OH_AVSource实例，可以通过调用OH_AVSource_Destroy接口释放实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 远程媒体资源的统一资源标识符。  | 

**返回：**

执行成功返回一个指向OH_AVSource实例的指针, 否则返回NULL。

可能的故障原因：

1. 网络异常；
2. 资源无效；
3. 文件格式不支持。 


### OH_AVSource_Destroy()

```
OH_AVErrCode OH_AVSource_Destroy (OH_AVSource *source)
```
**描述**
销毁OH_AVSource实例并清理内部资源。同一实例只能被销毁一次。销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。  | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：
    
    1. source指针无效；
    2. 空指针或非OH_AVSource实例。


### OH_AVSource_GetSourceFormat()

```
OH_AVFormat* OH_AVSource_GetSourceFormat (OH_AVSource *source)
```
**描述**
获取媒体资源文件的基础信息。

需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](_core.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。  | 

**返回：**

执行成功返回文件的基础信息, 否则返回NULL。

可能的故障原因：

1. source指针无效；
2. 空指针或非OH_AVSource实例；
3. source没有初始化。


### OH_AVSource_GetTrackFormat()

```
OH_AVFormat* OH_AVSource_GetTrackFormat (OH_AVSource *source, uint32_t trackIndex)
```
**描述**
获取轨道的基础信息。

需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](_core.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。  | 
| trackIndex | 需要获取信息的轨道的索引。  | 

**返回：**

执行成功返回轨道的基础信息，否则返回NULL。

可能的故障原因：

1. source指针无效，空指针或非OH_AVSource实例；
2. 轨道的索引超出范围;
3. source没有初始化。
