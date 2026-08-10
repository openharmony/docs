# RawFileDescriptor

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct {...} RawFileDescriptor
```

## 概述

提供rawfile文件描述符信息，包含rawfile的文件描述符、在HAP包中的起始位置和文件长度。<br>通过[OH_ResourceManager_GetRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptordata)获取，使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptordata)释放文件描述符资源。

**起始版本：** 8

**相关模块：** [rawfile](capi-rawfile.md)

**所在头文件：** [raw_file.h](capi-raw-file-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int fd | rawfile文件描述符。 |
| long start | rawfile文件在HAP包中的起始位置，单位为Byte。 |
| long length | rawfile文件的长度，单位为Byte。 |


