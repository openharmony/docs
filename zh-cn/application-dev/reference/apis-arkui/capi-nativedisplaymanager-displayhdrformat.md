# NativeDisplayManager_DisplayHdrFormat
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

```c
typedef struct {...} NativeDisplayManager_DisplayHdrFormat
```

## 概述

显示设备支持的所有HDR格式。

**起始版本：** 14

**相关模块：** [OH_DisplayManager](capi-oh-displaymanager.md)

**所在头文件：** [oh_display_info.h](capi-oh-display-info-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t hdrFormatLength | 显示设备支持的HDR格式数量。 |
| uint32_t* hdrFormats | 指向显示设备支持的HDR格式数组的指针。 |


