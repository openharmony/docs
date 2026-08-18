# ArkWeb_AnyNativeAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @csliutt-private-->
<!--Designer: @ringking0-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_AnyNativeAPI
```

## 概述

ArkWeb_AnyNativeAPI是ArkWeb Native API的基础结构体类型，用于统一表示通过[OH_ArkWeb_GetNativeAPI](capi-arkweb-interface-h.md#oh_arkweb_getnativeapi)接口获取到的各类Native API结构体指针。该结构体包含一个size_t类型的size成员，用于记录当前结构体的大小。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_interface.h](capi-arkweb-interface-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体对应的大小。 |


