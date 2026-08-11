# resourcemanager

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 概述

通过resourcemanager模块，开发者可以在Native层通过资源ID或资源名称获取应用资源或系统资源，实现多语言、多设备和多屏幕密度的资源适配。具体包括：<br> - 获取基础类型资源：获取颜色值（ARGB格式）、整数、浮点数、布尔值等基础类型资源。<br> - 获取字符串资源：获取普通字符串、格式化字符串（支持%d、%s、%f占位符）、字符串数组、复数字符串。<br> - 获取媒体资源：获取媒体资源的原始二进制数据或Base64编码。<br> - 资源覆盖：运行时动态加载和移除overlay资源，实现主题切换或资源覆盖。<br> 本模块依赖rawfile模块，需先通过rawfile模块获取[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)对象。

**起始版本：** 12
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [resmgr_common.h](capi-resmgr-common-h.md) | 提供resourcemanager模块所需的枚举类型和结构体定义。<br> 本头文件定义了错误码、屏幕方向、颜色模式、设备类型、屏幕密度等枚举，以及设备配置结构体，为ohresmgr.h中的资源获取函数提供数据类型支持。 |
| [ohresmgr.h](capi-ohresmgr-h.md) | 提供资源管理Native层获取资源的能力。 |