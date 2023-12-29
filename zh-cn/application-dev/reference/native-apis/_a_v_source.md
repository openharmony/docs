# AVSource


## 概述

AVSource模块提供用于构造音视频资源对象功能的函数。

\@syscap SystemCapability.Multimedia.Media.Spliter

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avsource.h](native__avsource_8h.md) | 声明用于构造音视频资源对象的Native API。<br>**引用文件**：<multimedia/player_framework/native_avsource.h> <br>**库**：libnative_media_avsource.so| 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVSource_CreateWithURI](#oh_avsource_createwithuri) (char \*uri) | 为统一资源标识符对应的资源对象创建OH_AVSource实例对象。 | 
| \*[OH_AVSource_CreateWithFD](#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | 为文件描述符对应的资源对象创建OH_AVSource实例对象。 | 
| [OH_AVSource_Destroy](#oh_avsource_destroy) (OH_AVSource \*source) | 销毁OH_AVSource实例并清理内部资源。同一实例只能被销毁一次。 | 
| \*[OH_AVSource_GetSourceFormat](#oh_avsource_getsourceformat) (OH_AVSource \*source) | 获取媒体资源文件的基础信息。 | 
| \*[OH_AVSource_GetTrackFormat](#oh_avsource_gettrackformat) (OH_AVSource \*source, uint32_t trackIndex) | 获取轨道的基础信息。 | 


## 函数说明


### OH_AVSource_CreateWithFD()

  
```
OH_AVSource* OH_AVSource_CreateWithFD (int32_t fd, int64_t offset, int64_t size)
```

**描述：**

为文件描述符对应的资源对象创建OH_AVSource实例对象。

可以通过调用OH_AVSource_Destroy释放实例。

该接口如果传入offset不为文件起始位置，或size不为文件大小时，可能会因数据获取不完整导致 OH_AVSource创建失败、后续解封装失败等未定义错误。

\@syscap SystemCapability.Multimedia.Media.Spliter

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 数据资源的文件描述符。 | 
| offset | 开始读取数据的位置。 | 
| size | 文件的字节数大小。 | 

**返回：**

返回一个指向OH_AVSource实例的指针。

**起始版本：**

10


### OH_AVSource_CreateWithURI()

  
```
OH_AVSource* OH_AVSource_CreateWithURI (char *uri)
```

**描述：**

为统一资源标识符对应的的资源对象创建OH_AVSource实例对象，可以通过调用OH_AVSource_Destroy释放实例。

\@syscap SystemCapability.Multimedia.Media.Spliter

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 远程媒体资源的统一资源标识符。 | 

**返回：**

返回一个指向OH_AVSource实例的指针。

**起始版本：**

10


### OH_AVSource_Destroy()

  
```
OH_AVErrCode OH_AVSource_Destroy (OH_AVSource *source)
```

**描述：**

销毁OH_AVSource实例并清理内部资源。

同一实例只能被销毁一次。

销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。

\@syscap SystemCapability.Multimedia.Media.Spliter

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。 | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVSource_GetSourceFormat()

  
```
OH_AVFormat* OH_AVSource_GetSourceFormat (OH_AVSource *source)
```

**描述：**

获取媒体资源文件的基础信息。

\@syscap SystemCapability.Multimedia.Media.Spliter

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。 | 

**返回：**

返回媒体资源文件的基础信息。

**起始版本：**

10


### OH_AVSource_GetTrackFormat()

  
```
OH_AVFormat* OH_AVSource_GetTrackFormat (OH_AVSource *source, uint32_t trackIndex)
```

**描述：**

获取轨道的基础信息。

\@syscap SystemCapability.Multimedia.Media.Spliter

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。 | 
| trackIndex | 需要获取信息的轨道的索引。 | 

**返回：**

返回轨道的基础信息。

**起始版本：**

10
