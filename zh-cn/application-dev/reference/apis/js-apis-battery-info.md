# 电量信息

该模块主要提供电池状态和充放电状态的查询接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import batteryInfo from '@ohos.batteryInfo';
```

## 属性

描述电池信息。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称      | 类型        | 可读 | 可写 |  说明     |
| --------------- | ------------------- | ---- | ---- | ---------------------|
| batterySOC                                | number                                         | 是   | 否   | 表示当前设备剩余电池电量百分比。                           |
| chargingStatus                            | [BatteryChargeState](#batterychargestate)      | 是   | 否   | 表示当前设备电池的充电状态。                               |
| healthStatus                              | [BatteryHealthState](#batteryhealthstate)      | 是   | 否   | 表示当前设备电池的健康状态。                               |
| pluggedType                               | [BatteryPluggedType](#batterypluggedtype)      | 是   | 否   | 表示当前设备连接的充电器类型。                             |
| voltage                                   | number                                         | 是   | 否   | 表示当前设备电池的电压，单位微伏。                         |
| technology                                | string                                         | 是   | 否   | 表示当前设备电池的技术型号。                               |
| batteryTemperature                        | number                                         | 是   | 否   | 表示当前设备电池的温度，单位0.1摄氏度。                    |
| isBatteryPresent<sup>7+</sup>             | boolean                                        | 是   | 否   | 表示当前设备是否支持电池或者电池是否在位。                 |
| batteryCapacityLevel<sup>9+</sup>         | [BatteryCapacityLevel](#batterycapacitylevel9) | 是   | 否   | 表示当前设备电池电量的等级。                               |
| estimatedRemainingChargeTime<sup>9+</sup> | number                                         | 是   | 否   | 表示当前设备充满电的预估时间，单位毫秒。                   |
| totalEnergy<sup>9+</sup>                  | number                                         | 是   | 否   | 表示当前设备电池的总容量，单位毫安时。此接口为系统接口。   |
| nowCurrent<sup>9+</sup>                   | number                                         | 是   | 否   | 表示当前设备电池的电流，单位毫安。此接口为系统接口。       |
| remainingEnergy<sup>9+</sup>              | number                                         | 是   | 否   | 表示当前设备电池的剩余容量，单位毫安时。此接口为系统接口。 |

## BatteryPluggedType

表示连接的充电器类型的枚举。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称       | 值  | 描述                |
| -------- | ---- | ----------------- |
| NONE     | 0    | 表示连接充电器类型未知。      |
| AC       | 1    | 表示连接的充电器类型为交流充电器。 |
| USB      | 2    | 表示连接的充电器类型为USB。   |
| WIRELESS | 3    | 表示连接的充电器类型为无线充电器。 |

## BatteryChargeState

表示电池充电状态的枚举。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称      | 值  | 描述              |
| ------- | ---- | --------------- |
| NONE    | 0    | 表示电池充电状态未知。     |
| ENABLE  | 1    | 表示电池充电状态为使能状态。  |
| DISABLE | 2    | 表示电池充电状态为停止状态。  |
| FULL    | 3    | 表示电池充电状态为已充满状态。 |

## BatteryHealthState

表示电池健康状态的枚举。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称          | 值  | 描述             |
| ----------- | ---- | -------------- |
| UNKNOWN     | 0    | 表示电池健康状态未知。    |
| GOOD        | 1    | 表示电池健康状态为正常。   |
| OVERHEAT    | 2    | 表示电池健康状态为过热。   |
| OVERVOLTAGE | 3    | 表示电池健康状态为过压。   |
| COLD        | 4    | 表示电池健康状态为低温。   |
| DEAD        | 5    | 表示电池健康状态为僵死状态。 |

## BatteryCapacityLevel<sup>9+</sup>

表示电池电量等级的枚举。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称           | 值 | 描述                         |
| -------------- | ------ | ---------------------------- |
| LEVEL_NONE     | 0      | 表示电池电量等级未知。       |
| LEVEL_FULL     | 1      | 表示电池电量等级为满电量。   |
| LEVEL_HIGH     | 2      | 表示电池电量等级为高电量。   |
| LEVEL_NORMAL   | 3      | 表示电池电量等级为正常电量。 |
| LEVEL_LOW      | 4      | 表示电池电量等级为低电量。   |
| LEVEL_CRITICAL | 5      | 表示电池电量等级为极低电量。 |

## CommonEventBatteryChangedCode<sup>9+</sup>

表示COMMON_EVENT_BATTERY_CHANGED通用事件附加信息的查询键。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称                 | 值 | 描述                                               |
| -------------------- | ------ | -------------------------------------------------- |
| EXTRA_SOC            | 0      | 表示剩余电池电量百分比的查询键。                   |
| EXTRA_VOLTAGE        | 1      | 表示当前设备电池电压的查询键。                     |
| EXTRA_TEMPERATURE    | 2      | 表示当前设备电池温度的查询键。                     |
| EXTRA_HEALTH_STATE   | 3      | 表示当前设备电池健康状态的查询键。                 |
| EXTRA_PLUGGED_TYPE   | 4      | 表示当前设备连接的充电器类型的查询键。             |
| EXTRA_MAX_CURRENT    | 5      | 表示当前设备电池最大电流的查询键。                 |
| EXTRA_MAX_VOLTAGE    | 6      | 表示当前设备电池最大电压的查询键。                 |
| EXTRA_CHARGE_STATE   | 7      | 表示当前设备电池充电状态的查询键。                 |
| EXTRA_CHARGE_COUNTER | 8      | 表示当前设备电池充电次数的查询键。                 |
| EXTRA_PRESENT        | 9      | 表示当前设备是否支持电池或者电池是否在位的查询键。 |
| EXTRA_TECHNOLOGY     | 10     | 表示当前设备电池技术型号的查询键。                 |
