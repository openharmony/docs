# 电量信息

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

该模块主要提供电池状态和充放电状态的查询接口。


## 导入模块

```js
import batteryInfo from '@ohos.batteryInfo';
```

## 系统能力

SystemCapability.PowerManager.BatteryManager.Core

## 属性

描述电池信息。

| 名称                            | 类型                                       | 可读   | 可写   | 描述                    |
| ----------------------------- | ---------------------------------------- | ---- | ---- | --------------------- |
| batterySOC                    | number                                   | 是    | 否    | 表示当前设备剩余电池电量百分比。      |
| chargingStatus                | [BatteryChargeState](#batterychargestate) | 是    | 否    | 表示当前设备电池的充电状态。        |
| healthStatus                  | [BatteryHealthState](#batteryhealthstate) | 是    | 否    | 表示当前设备电池的健康状态。        |
| pluggedType                   | [BatteryPluggedType](#batterypluggedtype) | 是    | 否    | 表示当前设备连接的充电器类型。       |
| voltage                       | number                                   | 是    | 否    | 表示当前设备电池的电压，单位微伏。     |
| technology                    | string                                   | 是    | 否    | 表示当前设备电池的技术型号。        |
| batteryTemperature            | number                                   | 是    | 否    | 表示当前设备电池的温度，单位0.1摄氏度。 |
| isBatteryPresent<sup>7+</sup> | boolean                                  | 是    | 否    | 表示当前设备是否支持电池或者电池是否在位。 |

- 示例：
  ```js
  import batteryInfo from '@ohos.batteryInfo';
  var batterySoc = batteryInfo.batterySOC;
  ```


## BatteryPluggedType

表示连接的充电器类型的枚举。


| 名称       | 默认值  | 描述                |
| -------- | ---- | ----------------- |
| NONE     | 0    | 表示连接充电器类型未知。      |
| AC       | 1    | 表示连接的充电器类型为交流充电器。 |
| USB      | 2    | 表示连接的充电器类型为USB。   |
| WIRELESS | 3    | 表示连接的充电器类型为无线充电器。 |


## BatteryChargeState

表示电池充电状态的枚举。


| 名称      | 默认值  | 描述              |
| ------- | ---- | --------------- |
| NONE    | 0    | 表示电池充电状态未知。     |
| ENABLE  | 1    | 表示电池充电状态为使能状态。  |
| DISABLE | 2    | 表示电池充电状态为停止状态。  |
| FULL    | 3    | 表示电池充电状态为已充满状态。 |


## BatteryHealthState

表示电池的健康状态的枚举。


| 名称          | 默认值  | 描述             |
| ----------- | ---- | -------------- |
| UNKNOWN     | 0    | 表示电池健康状态未知。    |
| GOOD        | 1    | 表示电池健康状态为正常。   |
| OVERHEAT    | 2    | 表示电池健康状态为过热。   |
| OVERVOLTAGE | 3    | 表示电池健康状态为过压。   |
| COLD        | 4    | 表示电池健康状态为低温。   |
| DEAD        | 5    | 表示电池健康状态为僵死状态。 |
