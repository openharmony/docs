# ohbattery_info.h


## 概述

声明电池API以获取当前电池容量和电源类型的信息，定义电池相应常见事件。

**库：** libohbattery_info.so

**系统能力：** SystemCapability.PowerManager.BatteryManager.Core

**起始版本：** 13

**相关模块：**[OH_BatteryInfo](oh__batteryinfo.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BatteryInfo_BatteryPluggedType](oh__batteryinfo.md#batteryinfo_batterypluggedtype) {<br/>PLUGGED_TYPE_NONE , PLUGGED_TYPE_AC , PLUGGED_TYPE_USB , PLUGGED_TYPE_WIRELESS , PLUGGED_TYPE_BUTT } | 定义插入类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_BatteryInfo_GetCapacity](oh__batteryinfo.md#oh_batteryinfo_getcapacity) () | 返回当前电池容量。 | 
| [BatteryInfo_BatteryPluggedType](oh__batteryinfo.md#batteryinfo_batterypluggedtype)[OH_BatteryInfo_GetPluggedType](oh__batteryinfo.md#oh_batteryinfo_getpluggedtype) () | 返回当前插入的类型。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char\* [COMMON_EVENT_KEY_CAPACITY](oh__batteryinfo.md#common_event_key_capacity) = "soc" | 标识电池容量变化后发送的常见事件。 | 
| static const char\* [COMMON_EVENT_KEY_CHARGE_STATE](oh__batteryinfo.md#common_event_key_charge_state) = "chargeState" | 标识充电状态更改后发送的常见事件。 | 
| static const char\* [COMMON_EVENT_KEY_PLUGGED_TYPE](oh__batteryinfo.md#common_event_key_plugged_type) = "pluggedType" | 标识插入类型更改后发送的常见事件。 | 
