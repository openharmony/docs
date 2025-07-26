# OH_AVDataSourceExt

## 概述

用户自定义数据源，回调支持通过userData传递用户自定义数据。

**起始版本：** 20

**相关模块：** [CodecBase](capi-codecbase.md)

**所在头文件：** [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int64_t size | 数据源的总大小。 |
| [OH_AVDataSourceReadAtExt](capi-native-avcodec-base-h.md#oh_avdatasourcereadatext) readAt | 数据源的数据回调。 |


