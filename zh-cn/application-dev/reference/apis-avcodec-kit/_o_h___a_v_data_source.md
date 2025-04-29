# OH_AVDataSource


## 概述

用户自定义数据源。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**相关模块：**[CodecBase](_codec_base.md)

**所在头文件：**[native_avcodec_base.h](native__avcodec__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int64_t [size](#size) | 数据源的总大小。  | 
| [OH_AVDataSourceReadAt](_codec_base.md#oh_avdatasourcereadat) [readAt](#readat) | 数据源的数据回调。  | 


## 结构体成员变量说明


### readAt

```
OH_AVDataSourceReadAt OH_AVDataSource::readAt
```

**描述**

数据源的数据回调。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### size

```
int64_t OH_AVDataSource::size
```

**描述**

数据源的总大小。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12
