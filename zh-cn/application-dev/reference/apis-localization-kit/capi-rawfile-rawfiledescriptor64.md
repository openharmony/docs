# RawFileDescriptor64

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供较大rawfile文件描述符信息。RawFileDescriptor64是[OH_ResourceManager_GetRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor64)的输出参数,涵盖了rawfile文件的文件描述符以及在HAP包中的起始位置和长度。

**起始版本：** 11

**相关模块：** [rawfile](capi-rawfile.md)

**所在头文件：** [raw_file.h](capi-raw-file-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int fd | rawfile文件描述符，单位为int。 |
| int64_t start | rawfile在HAP包中的起始位置，单位为int64_t。 |
| int64_t length | rawfile在HAP包中的长度，单位为int64_t。 |


