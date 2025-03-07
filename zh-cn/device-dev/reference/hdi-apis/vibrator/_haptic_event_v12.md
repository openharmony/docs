# HapticEvent


## 概述

表示振动事件。

参数包含振动时间，强度，频率等等。

**起始版本：** 4.1

**相关模块：**[Vibrator](_vibrator_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [EVENT_TYPE](_vibrator_v12.md#event_type)[type](#type) | 振动类型。  | 
| int [time](#time) | 时间。  | 
| int [duration](#duration) | 振动延时。  | 
| int [intensity](#intensity) | 振动强度。  | 
| int [frequency](#frequency) | 振动频率。  | 
| int [index](#index) | 马达id。表示振动的是哪个马达。  | 
| int [pointNum](#pointnum) | 振动点数量。  | 
| struct [CurvePoint](_curve_point_v12.md)[] [points](#points) | 振动点数组。  | 


## 类成员变量说明


### duration

```
int HapticEvent::duration
```
**描述**

振动延时。


### frequency

```
int HapticEvent::frequency
```
**描述**

振动频率。


### index

```
int HapticEvent::index
```
**描述**

马达id。表示振动的是哪个马达。


### intensity

```
int HapticEvent::intensity
```
**描述**

振动强度。


### pointNum

```
int HapticEvent::pointNum
```
**描述**

振动点数量。


### points

```
struct CurvePoint [] HapticEvent::points
```
**描述**

振动点数组。


### time

```
int HapticEvent::time
```
**描述**

时间。


### type

```
enum EVENT_TYPE HapticEvent::type
```
**描述**

振动类型。
