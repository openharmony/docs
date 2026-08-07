# RawDir

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct RawDir RawDir
```

## 概述

RawDir表示一个已打开的rawfile目录对象，可用于遍历目录和目录下文件。通过[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)函数获取，使用完后须调用[OH_ResourceManager_CloseRawDir](capi-raw-dir-h.md#oh_resourcemanager_closerawdir)关闭并释放。

**起始版本：** 8

**相关模块：** [rawfile](capi-rawfile.md)

**所在头文件：** [raw_dir.h](capi-raw-dir-h.md)

