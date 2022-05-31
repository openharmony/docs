# 电源服务子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，电源服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_TECHNOLOGY | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_PRESENT | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_CHARGE_COUNTER | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_CHARGE_STATE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_MAX_VOLTAGE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_MAX_CURRENT | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_PLUGGED_TYPE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_HEALTH_STATE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_TEMPERATURE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_VOLTAGE | 新增 |
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_SOC = 0 | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_CRITICAL | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_LOW | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_NORMAL | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_HIGH | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_FULL | 新增 |
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_NONE | 新增 |
| ohos.batteryinfo | batteryInfo | const remainingEnergy: number; | 新增 |
| ohos.batteryinfo | batteryInfo | const nowCurrent: number; | 新增 |
| ohos.batteryinfo | batteryInfo | const totalEnergy: number; | 新增 |
| ohos.batteryinfo | batteryInfo | const estimatedRemainingChargeTime: number; | 新增 |
| ohos.batteryinfo | batteryInfo | const batteryCapacityLevel: BatteryCapacityLevel; | 新增 |
| ohos.power | DevicePowerMode | MODE_EXTREME_POWER_SAVE | 新增 |
| ohos.power | DevicePowerMode | MODE_PERFORMANCE | 新增 |
| ohos.power | DevicePowerMode | MODE_POWER_SAVE | 新增 |
| ohos.power | DevicePowerMode | MODE_NORMAL = 600 | 新增 |
| ohos.power | power | setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void;<br>setPowerMode(mode: DevicePowerMode): Promise\<void>; | 新增 |
| ohos.power | power | getPowerMode(callback: AsyncCallback\<DevicePowerMode>): void;<br>getPowerMode(): Promise\<DevicePowerMode>; | 新增 |
| ohos.power | power | suspendDevice(): void; | 新增 |
| ohos.power | power | wakeupDevice(detail: string): void; | 新增 |

