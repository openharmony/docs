# Battery


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [IBatteryCallback.idl](_i_battery_callback_8idl.md) | 电池信息的回调。 | 
| [IBatteryInterface.idl](_i_battery_interface_8idl.md) | 获取、订阅电池信息的接口。 | 
| [Types.idl](_types_8idl.md) | 电池信息相关数据类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IBatteryCallback](interface_i_battery_callback.md) | 电池信息的回调。&nbsp;[更多...](interface_i_battery_callback.md) | 
| [IBatteryInterface](interface_i_battery_interface.md) | 获取、订阅电池信息的接口。&nbsp;[更多...](interface_i_battery_interface.md) | 
| [BatteryInfo](_battery_info.md) | 电池相关信息。&nbsp;[更多...](_battery_info.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [BatteryHealthState](#batteryhealthstate)&nbsp;{&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_UNKNOWN&nbsp;=&nbsp;0,&nbsp;BATTERY_HEALTH_GOOD,&nbsp;BATTERY_HEALTH_OVERHEAT,&nbsp;BATTERY_HEALTH_OVERVOLTAGE,&nbsp;&nbsp;&nbsp;BATTERY_HEALTH_COLD,&nbsp;BATTERY_HEALTH_DEAD,&nbsp;BATTERY_HEALTH_RESERVED&nbsp;} | 电池的健康状态。&nbsp;[更多...](#batteryhealthstate) | 
| [BatteryChargeState](#batterychargestate)&nbsp;{&nbsp;&nbsp;&nbsp;CHARGE_STATE_NONE&nbsp;=&nbsp;0,&nbsp;CHARGE_STATE_ENABLE,&nbsp;CHARGE_STATE_DISABLE,&nbsp;CHARGE_STATE_FULL,&nbsp;&nbsp;&nbsp;CHARGE_STATE_RESERVED&nbsp;} | 电池的充电状态。&nbsp;[更多...](#batterychargestate) | 
| [BatteryPluggedType](#batterypluggedtype)&nbsp;{&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;PLUGGED_TYPE_AC,&nbsp;PLUGGED_TYPE_USB,&nbsp;PLUGGED_TYPE_WIRELESS,&nbsp;&nbsp;&nbsp;PLUGGED_TYPE_BUTT&nbsp;} | 电池的充电设备类型。&nbsp;[更多...](#batterypluggedtype) | 


### 变量

  | 变量 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.battery.v1_0 | 电池信息接口的包路径 | 


## **详细描述**

提供获取、订阅电池信息的接口。

电池模块为电池服务提供的获取、订阅电池信息的接口。 服务获取此模块的对象或代理后，可以调用相关的接口获取电池信息、订阅电池信息的变化。

**Since：**

3.1

**Version：**

1.0


## **枚举类型说明**


### BatteryChargeState

  
```
enum BatteryChargeState
```

**描述：**

电池的充电状态。

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

**描述：**

电池的健康状态。

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

**描述：**

电池的充电设备类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PLUGGED_TYPE_NONE | 表示连接充电器类型未知。 | 
| PLUGGED_TYPE_AC | 表示连接的充电器类型为交流充电器。 | 
| PLUGGED_TYPE_USB | 表示连接的充电器类型为USB充电器。 | 
| PLUGGED_TYPE_WIRELESS | 表示连接的充电器类型为无线充电器。 | 
| PLUGGED_TYPE_BUTT | 预留。 | 
