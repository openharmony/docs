# HiAppEvent_AppEventInfo

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## 概述

单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。

**起始版本：** 12

**相关模块：** [HiAppEvent](capi-hiappevent.md)

**所在头文件：** [hiappevent.h](capi-hiappevent-h.md)

## 汇总

### 成员变量

| 名称                                                    | 描述 |
|-------------------------------------------------------| -- |
| const char* domain                                    | 事件领域。 |
| const char* name                                      | 事件名称。 |
| enum [EventType](capi-hiappevent-h.md#eventtype) type | 事件类型。 |
| const char* params                                    | Json格式字符串类型的事件参数列表。 |


