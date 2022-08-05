# Types.idl


## **概述**

**所属模块:**

[Battery](battery.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [BatteryInfo](_battery_info.md) | 电池相关信息。&nbsp;[更多...](_battery_info.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [BatteryHealthState](battery.md#batteryhealthstate)&nbsp;{&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_UNKNOWN&nbsp;=&nbsp;0,&nbsp;BATTERY_HEALTH_GOOD,&nbsp;BATTERY_HEALTH_OVERHEAT,&nbsp;BATTERY_HEALTH_OVERVOLTAGE,&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_COLD,&nbsp;BATTERY_HEALTH_DEAD,&nbsp;BATTERY_HEALTH_RESERVED&nbsp;} | 电池的健康状态。&nbsp;[更多...](battery.md#batteryhealthstate) | 
| [BatteryChargeState](battery.md#batterychargestate)&nbsp;{&nbsp;&nbsp;&nbsp;CHARGE_STATE_NONE&nbsp;=&nbsp;0,&nbsp;CHARGE_STATE_ENABLE,&nbsp;CHARGE_STATE_DISABLE,&nbsp;CHARGE_STATE_FULL,&nbsp;&nbsp;&nbsp;CHARGE_STATE_RESERVED&nbsp;} | 电池的充电状态。&nbsp;[更多...](battery.md#batterychargestate) | 
| [BatteryPluggedType](battery.md#batterypluggedtype)&nbsp;{&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;PLUGGED_TYPE_AC,&nbsp;PLUGGED_TYPE_USB,&nbsp;PLUGGED_TYPE_WIRELESS,&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_BUTT&nbsp;} | 电池的充电设备类型。&nbsp;[更多...](battery.md#batterypluggedtype) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.battery.v1_0 | 电池信息接口的包路径 | 


## **详细描述**

电池信息相关数据类型。

电池信息中使用的数据类型，包括健康状态、充电状态、充电设备类型和电池信息结构。

**Since：**

3.1

**Version：**

1.0
