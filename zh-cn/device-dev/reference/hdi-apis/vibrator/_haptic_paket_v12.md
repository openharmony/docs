# HapticPaket


## 概述

高清振动数据包。

参数包含具体的高清振动数据。

**起始版本：** 4.1

**相关模块：**[Vibrator](_vibrator_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [time](#time) | 时间。  | 
| int [eventNum](#eventnum) | 振动事件数量。  | 
| struct [HapticEvent](_haptic_event_v12.md)[] [events](#events) | 振动事件数组。  | 


## 类成员变量说明


### eventNum

```
int HapticPaket::eventNum
```
**描述**

振动事件数量。


### events

```
struct HapticEvent [] HapticPaket::events
```
**描述**

振动事件数组。


### time

```
int HapticPaket::time
```
**描述**

时间。
