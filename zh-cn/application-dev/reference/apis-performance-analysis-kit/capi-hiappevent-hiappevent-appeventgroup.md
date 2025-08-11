# HiAppEvent_AppEventGroup

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## 概述

一组事件信息，包含事件组的名称，按名称分组的单个事件信息数组，事件数组的长度。

**起始版本：** 12

**相关模块：** [HiAppEvent](capi-hiappevent.md)

**所在头文件：** [hiappevent.h](capi-hiappevent-h.md)

## 汇总

### 成员变量

| 名称                                                      | 描述 |
|---------------------------------------------------------| -- |
| const char* name                                        | 事件数组中相同的事件名称。 |
| const struct [HiAppEvent_AppEventInfo](capi-hiappevent-hiappevent-appeventinfo.md)* appEventInfos | 具有相同事件名称的事件数组。 |
| uint32_t infoLen                                        | 具有相同事件名称的事件数组的长度。 |


