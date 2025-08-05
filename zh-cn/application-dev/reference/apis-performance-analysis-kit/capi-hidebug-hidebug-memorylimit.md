# HiDebug_MemoryLimit

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## 概述

应用程序进程内存限制结构类型定义。

**起始版本：** 12

**相关模块：** [HiDebug](capi-hidebug.md)

**所在头文件：** [hidebug_type.h](capi-hidebug-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t rssLimit | 应用程序进程驻留集的限制，以KB为单位。 |
| uint64_t vssLimit | 应用程序进程的虚拟内存限制，以KB为单位。 |


