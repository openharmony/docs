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
| [BatteryHealthState](battery.md#batteryhealthstate)&nbsp;{&nbsp;&nbsp;&nbsp;[BATTERY_HEALTH_UNKNOWN](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa383fc8bba89eb9195e07da10ebff6a6a)&nbsp;=&nbsp;0,&nbsp;[BATTERY_HEALTH_GOOD](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa9019a1cab9aaffb56b968f846eae45c2),&nbsp;[BATTERY_HEALTH_OVERHEAT](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa34cb203c04d3f8b391fd0f193673d2cc),&nbsp;[BATTERY_HEALTH_OVERVOLTAGE](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2faeb20e3755faa28a34b37c20fce37672f),&nbsp;&nbsp;&nbsp;[BATTERY_HEALTH_COLD](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa1ed5e419d57b9ff71ac397d1b17eb420),&nbsp;[BATTERY_HEALTH_DEAD](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa05f1241d31443ffefec7ac784e141341),&nbsp;[BATTERY_HEALTH_RESERVED](battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa9583572172c946660b255d5ac3604f9b)&nbsp;} | 电池的健康状态。&nbsp;[更多...](battery.md#batteryhealthstate) | 
| [BatteryChargeState](battery.md#batterychargestate)&nbsp;{&nbsp;&nbsp;&nbsp;[CHARGE_STATE_NONE](battery.md#gga35791cca3603f7855c6368fbd00b21f1afdc91bf6bc92fdcd784cb274b1a14d28)&nbsp;=&nbsp;0,&nbsp;[CHARGE_STATE_ENABLE](battery.md#gga35791cca3603f7855c6368fbd00b21f1a03dc57c4f65da6b1472ae4f7ed676234),&nbsp;[CHARGE_STATE_DISABLE](battery.md#gga35791cca3603f7855c6368fbd00b21f1a33914f4c27c801d3ba5315ca486655cc),&nbsp;[CHARGE_STATE_FULL](battery.md#gga35791cca3603f7855c6368fbd00b21f1a70b48a2925871d0364ae6344bce944ae),&nbsp;&nbsp;&nbsp;[CHARGE_STATE_RESERVED](battery.md#gga35791cca3603f7855c6368fbd00b21f1a38af1f4d697139ebaa8eb97fb5b34120)&nbsp;} | 电池的充电状态。&nbsp;[更多...](battery.md#batterychargestate) | 
| [BatteryPluggedType](battery.md#batterypluggedtype)&nbsp;{&nbsp;&nbsp;&nbsp;[PLUGGED_TYPE_NONE](battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baa23f13d9ed048300c42930d844ead29c7)&nbsp;=&nbsp;0,&nbsp;[PLUGGED_TYPE_AC](battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baaba143c5ab6146a49e3c1362d3ba38751),&nbsp;[PLUGGED_TYPE_USB](battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baacfe481a50e9915a049edd3debcc7de1c),&nbsp;[PLUGGED_TYPE_WIRELESS](battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baaa8b900a0327e60b02ad7d3501057be38),&nbsp;&nbsp;&nbsp;[PLUGGED_TYPE_BUTT](battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baac85bb1a7b26e14b55cd9bb977c3e66c0)&nbsp;} | 电池的充电设备类型。&nbsp;[更多...](battery.md#batterypluggedtype) | 


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
