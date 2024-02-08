# ArkUI_NodeTouchEvent


## 概述

定义Touch事件的结构类型。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_NodeTouchEventAction](_ark_u_i___native_module.md#arkui_nodetoucheventaction)[action](#action) | 触屏事件的类型。  |
| int64_t [timeStamp](#timestamp) | 触屏事件时间戳，单位为微秒（us）。  |
| [ArkUI_NodeTouchPoint](_ark_u_i___node_touch_point.md)[actionTouch](#actiontouch) | 当前触屏事件的触控点信息。  |
| int32_t(\* [getTouches](#gettouches) )([ArkUI_NodeTouchPoint](_ark_u_i___node_touch_point.md) \*\*points) | 返回此事件发生时所有屏幕接触点信息。  |
| int32_t(\* [getHistoricalPoints](#gethistoricalpoints) )([ArkUI_NodeHistoricalTouchPoint](_ark_u_i___node_historical_touch_point.md) \*\*historicalPoints) | 返回此事件中的历史点信息。这些是在此事件和上一个事件之间发生的运动。  |
| [ArkUI_NodeSourceType](_ark_u_i___native_module.md#arkui_nodesourcetype)[sourceType](#sourcetype) | 触发事件来源的类型。  |
| bool [stopPropagation](#stoppropagation) | 阻止事件进一步向父节点冒泡处理。  |
| bool [preventDefault](#preventdefault) | 阻止当前节点的默认事件处理行为，允许事件进一步向上冒泡。  |


## 结构体成员变量说明


### action

```
ArkUI_NodeTouchEventAction ArkUI_NodeTouchEvent::action
```
**描述**
触屏事件的类型。


### actionTouch

```
ArkUI_NodeTouchPoint ArkUI_NodeTouchEvent::actionTouch
```
**描述**
当前触屏事件的触控点信息。


### getHistoricalPoints

```
int32_t(* ArkUI_NodeTouchEvent::getHistoricalPoints) (ArkUI_NodeHistoricalTouchPoint **historicalPoints)
```
**描述**
返回此事件中的历史点信息。这些是在此事件和上一个事件之间发生的运动。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| historicalPoints | 用来接受数据的指针对象。  |

**返回：**

历史点数据数组元素数量。

**注解：**

框架会在该函数调用时创建历史点数据数组的堆内存对象并返回指针，开发者需要在使用完成后调用delete[]手动释放内存。


### getTouches

```
int32_t(* ArkUI_NodeTouchEvent::getTouches) (ArkUI_NodeTouchPoint **points)
```
**描述**
返回此事件发生时所有屏幕接触点信息。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| points | 用来接受数据的指针对象。  |

**返回：**

屏幕接触点数据数组元素数量。

**注解：**

ArkUI会在该函数调用时创建触控点信息数组的堆内存对象并返回指针，开发者需要在使用完成后调用delete[]手动释放内存。


### preventDefault

```
bool ArkUI_NodeTouchEvent::preventDefault
```
**描述**
阻止当前节点的默认事件处理行为，允许事件进一步向上冒泡。


### sourceType

```
ArkUI_NodeSourceType ArkUI_NodeTouchEvent::sourceType
```
**描述**
触发事件来源的类型。


### stopPropagation

```
bool ArkUI_NodeTouchEvent::stopPropagation
```
**描述**
阻止事件进一步向父节点冒泡处理。


### timeStamp

```
int64_t ArkUI_NodeTouchEvent::timeStamp
```
**描述**
触屏事件时间戳，单位为微秒（us）。
