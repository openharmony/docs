# native_avsource.h


## 概述

声明用于音视频解封装的Native API。

**库：** libnative_media_avsource.so

**引用文件：** <multimedia/player_framework/native_avsource.h>

**起始版本：** 10

**相关模块：**[AVSource](_a_v_source.md)

**相关示例：**[AVCodec](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVSource](_a_v_source.md#oh_avsource) [OH_AVSource](_a_v_source.md#oh_avsource) | 为媒体资源接口定义native层对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithDataSource](_a_v_source.md#oh_avsource_createwithdatasource) ([OH_AVDataSource](_o_h___a_v_data_source.md) \*dataSource) | 为用户自定义数据源的资源对象创建OH_AVSource实例对象，可以通过调用OH_AVSource_Destroy释放实例。  | 
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithURI](_a_v_source.md#oh_avsource_createwithuri) (char \*uri) | 为统一资源标识符对应的资源对象创建OH_AVSource实例对象。 | 
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithFD](_a_v_source.md#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | 为文件描述符对应的资源对象创建OH_AVSource实例对象。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVSource_Destroy](_a_v_source.md#oh_avsource_destroy) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | 销毁OH_AVSource实例并清理内部资源。 | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetSourceFormat](_a_v_source.md#oh_avsource_getsourceformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | 获取媒体资源文件的基础信息。 | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetTrackFormat](_a_v_source.md#oh_avsource_gettrackformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source, uint32_t trackIndex) | 获取轨道的基础信息。 | 
| OH_AVFormat \* [OH_AVSource_GetCustomMetadataFormat](_a_v_source.md#oh_avsource_getcustommetadataformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | 获取自定义元数据的基础信息。 | 
