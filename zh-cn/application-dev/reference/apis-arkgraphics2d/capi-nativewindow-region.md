# Region
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 概述

表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。

**起始版本：** 8

**相关模块：** [NativeWindow](capi-nativewindow.md)

**所在头文件：** [external_window.h](capi-external-window-h.md)

## 汇总

### 成员变量

| 名称               | 描述                                             |
| ------------------ | ------------------------------------------------ |
| * rects            | 如果rects是空指针nullptr，默认Buffer大小为脏区。 |
| int32_t rectNumber | 如果rectNumber为0，默认Buffer大小为脏区。        |

