# 电源子系统ChangeLog

## cl.powermgr.1  CommonEventBatteryChangedCode接口变更

[ @ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) (电量信息)中的CommonEventBatteryChangedCode枚举类进行如下变更：

- 类名称变更为CommonEventBatteryChangedKey；
- 删除EXTRA_MAX_CURRENT、EXTRA_MAX_VOLTAGE和EXTRA_CHARGE_COUNTER；
- 枚举值类型从数值变更为字符串。

#### 变更影响

基于此前版本开发的应用，需适配接口的变更，否则会影响原有业务逻辑。

#### 关键的接口/组件变更

变更前：

| 名称                 | 值   | 说明                                               |
| -------------------- | ---- | -------------------------------------------------- |
| EXTRA_SOC            | 0    | 表示剩余电池电量百分比的查询键。                   |
| EXTRA_VOLTAGE        | 1    | 表示当前设备电池电压的查询键。                     |
| EXTRA_TEMPERATURE    | 2    | 表示当前设备电池温度的查询键。                     |
| EXTRA_HEALTH_STATE   | 3    | 表示当前设备电池健康状态的查询键。                 |
| EXTRA_PLUGGED_TYPE   | 4    | 表示当前设备连接的充电器类型的查询键。             |
| EXTRA_MAX_CURRENT    | 5    | 表示当前设备电池最大电流的查询键。                 |
| EXTRA_MAX_VOLTAGE    | 6    | 表示当前设备电池最大电压的查询键。                 |
| EXTRA_CHARGE_STATE   | 7    | 表示当前设备电池充电状态的查询键。                 |
| EXTRA_CHARGE_COUNTER | 8    | 表示当前设备电池充电次数的查询键。                 |
| EXTRA_PRESENT        | 9    | 表示当前设备是否支持电池或者电池是否在位的查询键。 |
| EXTRA_TECHNOLOGY     | 10   | 表示当前设备电池技术型号的查询键。                 |
| EXTRA_CAPACITY_LEVEL | 11   | 表示当前设备电池电量等级的查询键。                 |

变更后：

| 名称                 | 值              | 说明                                               |
| -------------------- | --------------- | -------------------------------------------------- |
| EXTRA_SOC            | "soc"           | 表示剩余电池电量百分比的查询键。                   |
| EXTRA_CHARGE_STATE   | "chargeState"   | 表示当前设备电池充电状态的查询键。                 |
| EXTRA_HEALTH_STATE   | "healthState"   | 表示当前设备电池健康状态的查询键。                 |
| EXTRA_PLUGGED_TYPE   | "pluggedType"   | 表示当前设备连接的充电器类型的查询键。             |
| EXTRA_VOLTAGE        | "voltage"       | 表示当前设备电池电压的查询键。                     |
| EXTRA_TECHNOLOGY     | "technology"    | 表示当前设备电池技术型号的查询键。                 |
| EXTRA_TEMPERATURE    | "temperature"   | 表示当前设备电池温度的查询键。                     |
| EXTRA_PRESENT        | "present"       | 表示当前设备是否支持电池或者电池是否在位的查询键。 |
| EXTRA_CAPACITY_LEVEL | "capacityLevel" | 表示当前设备电池电量等级的查询键。                 |

#### 适配指导

请参考[@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) (电量信息)接口的API参考。
## cl.powermgr.2 estimatedRemainingChargeTime系统接口变更

[@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) (电量信息)中的estimatedRemainingChargeTime属性变更为系统接口。

#### 变更影响

基于此前版本开发的应用，需适配新的系统权限，否则会影响原有业务逻辑。

#### 适配指导

请参考[@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) (电量信息)接口的API参考。

## cl.powermgr.3 系统公共事件行为变更

电量信息通过[@ohos.commonEventManager (公共事件模块)](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-commonEventManager.md)提供了如下几种系统公共事件:

- COMMON_EVENT_BATTERY_LOW，表示电池电量低的的公共事件的动作，包含剩余电池电量百分比信息；
- COMMON_EVENT_BATTERY_OKAY，表示电池电量正常的公共事件的动作，包含剩余电池电量百分比信息；
- COMMON_EVENT_POWER_CONNECTED，表示设备连接到外部电源的公共事件的动作，包含设备连接的电源类型信息；
- COMMON_EVENT_POWER_DISCONNECTED，表示设备与外部电源断开的公共事件的动作，包含设备连接的电源类型信息；
- COMMON_EVENT_CHARGING，表示系统开始为电池充电的公共事件的动作，包含充电状态信息；
- COMMON_EVENT_DISCHARGING，表示系统停止为电池充电的公共事件的动作，包含充电状态信息。

这几种公共事件的数据的获取方式从CommonEventData.data变更为CommonEventData.code。

#### 变更影响

基于此前版本开发的应用，需适配新的数据获取方式，否则会影响原有业务逻辑。

#### 适配指导

请参考[ @ohos.commonEventManager (公共事件模块)](../../../application-dev/reference/apis/js-apis-commonEventManager.md)接口的API参考。
