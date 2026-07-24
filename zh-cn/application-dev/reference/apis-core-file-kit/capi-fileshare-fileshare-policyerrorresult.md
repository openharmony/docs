# FileShare_PolicyErrorResult
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @leiyuqian-->
<!--Adviser: @jinqiuheng-->
```c
typedef struct FileShare_PolicyErrorResult {...} FileShare_PolicyErrorResult
```

## 概述

授予或激活权限失败的URI策略结果，用于记录失败URI、错误码和失败原因。

**起始版本：** 12

**相关模块：** [fileShare](capi-fileshare.md)

**所在头文件：** [oh_file_share.h](capi-oh-file-share-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char *uri | 授予或激活权限失败的URI。 |
| [FileShare_PolicyErrorCode](capi-oh-file-share-h.md#fileshare_policyerrorcode) code | 授予或激活权限失败的URI对应的错误码。 |
| char *message | 授予或激活权限失败的URI对应的原因，由系统管理，无需手动释放。 |
