# Types.idl


## 概述

电池信息相关数据类型。

电池信息中使用的数据类型，包括健康状态、充电状态、充电设备类型和电池信息结构。

模块包路径：ohos.hdi.battery.v1_0

**起始版本：** 3.1

**相关模块：**[Battery](battery_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[BatteryInfo](_battery_info_v10.md) | 电池相关信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| 名称 | 电池的健康状态。 | 
| [BatteryHealthState](battery_v10.md#batteryhealthstate) { BATTERY_HEALTH_UNKNOWN = 0, BATTERY_HEALTH_GOOD, BATTERY_HEALTH_OVERHEAT, BATTERY_HEALTH_OVERVOLTAGE,&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_COLD, BATTERY_HEALTH_DEAD, BATTERY_HEALTH_RESERVED } | 电池的充电状态。 | 
| [BatteryChargeState](battery_v10.md#batterychargestate) { CHARGE_STATE_NONE = 0, CHARGE_STATE_ENABLE, CHARGE_STATE_DISABLE, CHARGE_STATE_FULL, CHARGE_STATE_RESERVED }<br/>[BatteryPluggedType](battery_v10.md#batterypluggedtype) { PLUGGED_TYPE_NONE = 0, PLUGGED_TYPE_AC, PLUGGED_TYPE_USB, PLUGGED_TYPE_WIRELESS,&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_BUTT } | 电池的充电设备类型。 | 
