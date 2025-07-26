# OH_AVDataSourceExt


## 概述

用户自定义数据源,回调支持通过userData传递用户自定义数据。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 20

**相关模块：**[CodecBase](_codec_base.md)

**所在头文件：**[native_avcodec_base.h](native__avcodec__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int64_t [size](#size) | 数据源的总大小。  | 
| [OH_AVDataSourceReadAtExt](_codec_base.md#oh_avdatasourcereadatext) [readAt](#readat) | 数据源的数据回调。  | 


## 结构体成员变量说明


### size

```
int64_t OH_AVDataSourceExt::size
```

**描述**

数据源的总大小。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 20


### readAt

```
OH_AVDataSourceReadAtExt OH_AVDataSourceExt::readAt
```

**描述**

数据源的数据回调。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 20

