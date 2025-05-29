# OH_BatteryInfo

## 概述

提供BatteryInfo模块的电池相关信息的能力。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Core

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ohbattery_info.h](ohbattery__info_8h.md) | 声明电池API以获取当前电池容量和电源类型的信息，定义电池相应常见事件。<br/>**库：** libohbattery_info.so | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) {<br/>PLUGGED_TYPE_NONE , PLUGGED_TYPE_AC , PLUGGED_TYPE_USB , PLUGGED_TYPE_WIRELESS , PLUGGED_TYPE_BUTT } | 定义插入类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_BatteryInfo_GetCapacity](#oh_batteryinfo_getcapacity) () | 返回当前电池容量。 | 
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) [OH_BatteryInfo_GetPluggedType](#oh_batteryinfo_getpluggedtype) () | 返回当前插入的类型。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char\* [COMMON_EVENT_KEY_CAPACITY](#common_event_key_capacity) = "soc" | 标识电池容量变化后发送的常见事件。 | 
| static const char\* [COMMON_EVENT_KEY_CHARGE_STATE](#common_event_key_charge_state) = "chargeState" | 标识充电状态更改后发送的常见事件。 | 
| static const char\* [COMMON_EVENT_KEY_PLUGGED_TYPE](#common_event_key_plugged_type) = "pluggedType" | 标识插入类型更改后发送的常见事件。 | 


## 枚举类型说明


### BatteryInfo_BatteryPluggedType

```
enum BatteryInfo_BatteryPluggedType
```

**描述**

定义插入类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| PLUGGED_TYPE_NONE | 电源已拔下。 | 
| PLUGGED_TYPE_AC | 电源是交流充电。 | 
| PLUGGED_TYPE_USB | 电源是USB DC充电。 | 
| PLUGGED_TYPE_WIRELESS | 电源为无线充电。 | 
| PLUGGED_TYPE_BUTT | 预留枚举。 | 


## 函数说明


### OH_BatteryInfo_GetCapacity()

```
int32_t OH_BatteryInfo_GetCapacity ()
```

**描述**

返回当前电池容量。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Core

**起始版本：** 13

**返回：**

返回介于0和100之间的数字。


### OH_BatteryInfo_GetPluggedType()

```
BatteryInfo_BatteryPluggedType OH_BatteryInfo_GetPluggedType ()
```

**描述**

返回当前插入的类型。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Core

**起始版本：** 13

**返回：**

PLUGGED_TYPE_NONE：表示电源被拔下。

PLUGGED_TYPE_AC：表示电源是AC充电。

PLUGGED_TYPE_USB：表示电源是USB DC充电。

PLUGGED_TYPE_WIRELESS：表示电源是无线充电。

PLUGGED_TYPE_BUTT：表示类型未知。


## 变量说明


### COMMON_EVENT_KEY_CAPACITY

```
const char* COMMON_EVENT_KEY_CAPACITY = "soc"
```

**描述**

标识电池容量变化后发送的常见事件。

**起始版本：** 13


### COMMON_EVENT_KEY_CHARGE_STATE

```
const char* COMMON_EVENT_KEY_CHARGE_STATE = "chargeState"
```

**描述**

标识充电状态更改后发送的常见事件。

**起始版本：** 13


### COMMON_EVENT_KEY_PLUGGED_TYPE

```
const char* COMMON_EVENT_KEY_PLUGGED_TYPE = "pluggedType"
```

**描述**

标识插入类型更改后发送的常见事件。

**起始版本：** 13
