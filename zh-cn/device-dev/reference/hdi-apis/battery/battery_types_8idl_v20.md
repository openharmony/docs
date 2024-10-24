# Types.idl


## 概述

电池信息相关数据类型。

电池信息中使用的数据类型，包括健康状态、充电状态、充电设备类型和电池信息结构。

模块包路径：ohos.hdi.battery.v2_0

**起始版本：** 3.2

**相关模块：**[Battery](battery_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[BatteryInfo](_battery_info_v20.md) | 电池相关信息。 | 
| struct&nbsp;&nbsp;[ChargingLimit](_charging_limit_v20.md) | 定义电池充电电流或电压的限制。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BatteryHealthState](battery_v20.md#batteryhealthstate) {<br/>BATTERY_HEALTH_UNKNOWN = 0, BATTERY_HEALTH_GOOD, BATTERY_HEALTH_OVERHEAT, BATTERY_HEALTH_OVERVOLTAGE,&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_COLD, BATTERY_HEALTH_DEAD, BATTERY_HEALTH_RESERVED<br/>} | 电池的健康状态。 | 
| [BatteryChargeState](battery_v20.md#batterychargestate) {<br/>CHARGE_STATE_NONE = 0, CHARGE_STATE_ENABLE, CHARGE_STATE_DISABLE, CHARGE_STATE_FULL, CHARGE_STATE_RESERVED<br/>} | 电池的充电状态。 | 
| [BatteryPluggedType](battery_v20.md#batterypluggedtype) {<br/>PLUGGED_TYPE_NONE = 0, PLUGGED_TYPE_AC, PLUGGED_TYPE_USB, PLUGGED_TYPE_WIRELESS,&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_BUTT<br/>} | 电池的充电设备类型。 | 
| [ChargingLimitType](battery_v20.md#charginglimittype) { TYPE_CURRENT = 0 , TYPE_VOLTAGE } | 定义电池充电限制类型。 | 
| [ChargeType](battery_v20.md#chargetype) {<br/>CHARGE_TYPE_NONE = 0 , CHARGE_TYPE_WIRED_NORMAL , CHARGE_TYPE_WIRED_QUICK , CHARGE_TYPE_WIRED_SUPER_QUICK ,<br/>CHARGE_TYPE_WIRELESS_NORMAL , CHARGE_TYPE_WIRELESS_QUICK , CHARGE_TYPE_WIRELESS_SUPER_QUICK<br/>} | 表示插入的充电器类型。 | 
