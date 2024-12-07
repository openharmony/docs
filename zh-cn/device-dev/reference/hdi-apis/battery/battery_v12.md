# Battery (V1_2)


## 概述

提供获取和订阅电池信息的接口。

电池模块为电池服务提供的获取、订阅电池信息的接口。 服务获取此模块的对象或代理后，可以调用相关的接口获取电池信息、订阅电池信息的变化。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IBatteryCallback.idl](_i_battery_callback_8idl_v12.md) | 提供电池信息的回调。 | 
| [IBatteryInterface.idl](_i_battery_interface_8idl_v12.md) | 获取、订阅电池信息的接口。 | 
| [Types.idl](battery_types_8idl_v12.md) | 电池信息相关数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IBatteryCallback](interface_i_battery_callback_v12.md) | 表示电池信息的回调。 | 
| interface&nbsp;&nbsp;[IBatteryInterface](interface_i_battery_interface_v12.md) | 获取、订阅电池信息的接口。 | 
| struct&nbsp;&nbsp;[BatteryInfo](_battery_info_v12.md) | 电池相关信息。 | 
| struct&nbsp;&nbsp;[ChargingLimit](_charging_limit_v12.md) | 定义电池充电电流或电压的限制。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BatteryHealthState](#batteryhealthstate) {<br/>BATTERY_HEALTH_UNKNOWN = 0, BATTERY_HEALTH_GOOD, BATTERY_HEALTH_OVERHEAT, BATTERY_HEALTH_OVERVOLTAGE,&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_COLD, BATTERY_HEALTH_DEAD, BATTERY_HEALTH_RESERVED<br/>} | 电池的健康状态。 | 
| [BatteryChargeState](#batterychargestate) {<br/>CHARGE_STATE_NONE = 0, CHARGE_STATE_ENABLE, CHARGE_STATE_DISABLE, CHARGE_STATE_FULL, CHARGE_STATE_RESERVED<br/>} | 电池的充电状态。 | 
| [BatteryPluggedType](#batterypluggedtype) {<br/>PLUGGED_TYPE_NONE = 0, PLUGGED_TYPE_AC, PLUGGED_TYPE_USB, PLUGGED_TYPE_WIRELESS,&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_BUTT<br/>} | 电池的充电设备类型。 | 
| [ChargingLimitType](#charginglimittype) { TYPE_CURRENT = 0 , TYPE_VOLTAGE } | 电池充电限制类型。 | 
| [ChargeType](#chargetype) {<br/>CHARGE_TYPE_NONE = 0 , CHARGE_TYPE_WIRED_NORMAL , CHARGE_TYPE_WIRED_QUICK , CHARGE_TYPE_WIRED_SUPER_QUICK ,<br/>CHARGE_TYPE_WIRELESS_NORMAL , CHARGE_TYPE_WIRELESS_QUICK , CHARGE_TYPE_WIRELESS_SUPER_QUICK<br/>} | 表示插入的充电器类型。 | 


## 枚举类型说明


### BatteryChargeState

```
enum BatteryChargeState
```

**描述**

电池的充电状态。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CHARGE_STATE_NONE | 表示电池充电状态未知。 | 
| CHARGE_STATE_ENABLE | 表示电池充电状态为使能状态。 | 
| CHARGE_STATE_DISABLE | 表示电池充电状态为停止状态。 | 
| CHARGE_STATE_FULL | 表示电池充电状态为已充满状态。 | 
| CHARGE_STATE_RESERVED | 预留。 | 


### BatteryHealthState

```
enum BatteryHealthState
```

**描述**

电池的健康状态。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| BATTERY_HEALTH_UNKNOWN | 表示电池健康状态未知。 | 
| BATTERY_HEALTH_GOOD | 表示电池健康状态为正常。 | 
| BATTERY_HEALTH_OVERHEAT | 表示电池健康状态为过热。 | 
| BATTERY_HEALTH_OVERVOLTAGE | 表示电池健康状态为过压。 | 
| BATTERY_HEALTH_COLD | 表示电池健康状态为低温。 | 
| BATTERY_HEALTH_DEAD | 表示电池健康状态为耗尽。 | 
| BATTERY_HEALTH_RESERVED | 预留。 | 


### BatteryPluggedType

```
enum BatteryPluggedType
```

**描述**

电池的充电设备类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PLUGGED_TYPE_NONE | 表示连接充电器类型未知。 | 
| PLUGGED_TYPE_AC | 表示连接的充电器类型为交流充电器。 | 
| PLUGGED_TYPE_USB | 表示连接的充电器类型为USB充电器。 | 
| PLUGGED_TYPE_WIRELESS | 表示连接的充电器类型为无线充电器。 | 
| PLUGGED_TYPE_BUTT | 预留。 | 


### ChargeType

```
enum ChargeType
```

**描述**

表示插入的充电器类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| CHARGE_TYPE_NONE | 未知类型 | 
| CHARGE_TYPE_WIRED_NORMAL | 有线普通型 | 
| CHARGE_TYPE_WIRED_QUICK | 有线快速型 | 
| CHARGE_TYPE_WIRED_SUPER_QUICK | 有线超快速型 | 
| CHARGE_TYPE_WIRELESS_NORMAL | 无线普通型 | 
| CHARGE_TYPE_WIRELESS_QUICK | 无线快速型 | 
| CHARGE_TYPE_WIRELESS_SUPER_QUICK | 无线超快速型 | 


### ChargingLimitType

```
enum ChargingLimitType
```

**描述**

电池充电限制类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_CURRENT | 限制类型：充电电流 | 
| TYPE_VOLTAGE | 限制类型：充电电压 | 
