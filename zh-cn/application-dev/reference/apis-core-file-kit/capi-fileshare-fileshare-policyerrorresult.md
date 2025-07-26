# FileShare_PolicyErrorResult

## 概述

授予或使能权限失败的URI策略结果。

**起始版本：** 12

**相关模块：** [fileShare](capi-fileshare.md)

**所在头文件：** [oh_file_share.h](capi-oh-file-share-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* uri | 授予或使能策略失败的URI。 |
| FileShare_PolicyErrorCode code | 授予或使能策略失败的URI对应的错误码。 |
| char* message | 授予或使能策略失败的URI对应的原因。 |


