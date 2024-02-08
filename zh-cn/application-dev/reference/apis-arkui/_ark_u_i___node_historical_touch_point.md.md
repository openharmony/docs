# ArkUI_NodeHistoricalTouchPoint


## 概述

定义历史点信息的结构类型。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_NodeTouchEventAction](_ark_u_i___native_module.md#arkui_nodetoucheventaction) [action](#action) | 触屏事件类型。  |
| int64_t [timeStamp](#timestamp) | 触屏历史事件时间戳，单位为微秒（us）。  |
| [ArkUI_NodeTouchPoint](_ark_u_i___node_touch_point.md) [actionTouch](#actiontouch) | 历史触摸事件来源类型。  |
| [ArkUI_NodeSourceType](_ark_u_i___native_module.md#arkui_nodesourcetype) [sourceType](#sourcetype) | 历史触摸事件来源类型。  |


## 结构体成员变量说明


### action

```
ArkUI_NodeTouchEventAction ArkUI_NodeHistoricalTouchPoint::action
```
**描述**
触屏事件类型。


### actionTouch

```
ArkUI_NodeTouchPoint ArkUI_NodeHistoricalTouchPoint::actionTouch
```
**描述**
历史触摸事件来源类型。


### sourceType

```
ArkUI_NodeSourceType ArkUI_NodeHistoricalTouchPoint::sourceType
```
**描述**
历史触摸事件来源类型。


### timeStamp

```
int64_t ArkUI_NodeHistoricalTouchPoint::timeStamp
```
**描述**
触屏历史事件时间戳，单位为微秒（us）。
