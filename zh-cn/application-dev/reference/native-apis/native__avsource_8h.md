# native_avsource.h


## 概述

声明用于构造音视频资源对象的Native API。

**起始版本：**

10

**相关模块：**

[AVSource](_a_v_source.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVSource_CreateWithURI](_a_v_source.md#oh_avsource_createwithuri) (char \*uri) | 为统一资源标识符对应的的资源对象创建OH_AVSource实例对象。 | 
| \*[OH_AVSource_CreateWithFD](_a_v_source.md#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | 为文件描述符对应的资源对象创建OH_AVSource实例对象。 | 
| [OH_AVSource_Destroy](_a_v_source.md#oh_avsource_destroy) (OH_AVSource \*source) | 销毁OH_AVSource实例并清理内部资源。同一实例只能被销毁一次。 | 
| \*[OH_AVSource_GetSourceFormat](_a_v_source.md#oh_avsource_getsourceformat) (OH_AVSource \*source) | 获取媒体资源文件的基础信息。 | 
| \*[OH_AVSource_GetTrackFormat](_a_v_source.md#oh_avsource_gettrackformat) (OH_AVSource \*source, uint32_t trackIndex) | 获取轨道的基础信息。 | 
