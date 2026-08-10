# RawFileDescriptor64

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct {...} RawFileDescriptor64
```

## 概述

提供rawfile文件描述符信息，包含rawfile的文件描述符、在HAP包中的起始位置和文件长度。支持2GB以上的大文件。<br>通过[OH_ResourceManager_GetRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor64)获取，使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptor64)释放文件描述符资源。

**起始版本：** 11

**相关模块：** [rawfile](capi-rawfile.md)

**所在头文件：** [raw_file.h](capi-raw-file-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int fd | rawfile文件描述符。 |
| int64_t start | rawfile文件在HAP包中的起始位置，单位为Byte。 |
| int64_t length | rawfile文件的长度，单位为Byte。 |


