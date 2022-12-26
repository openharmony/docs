# JS API Changes of the Power Management Subsystem

The table below lists the APIs changes of the power management subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_TECHNOLOGY | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_PRESENT | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_CHARGE_COUNTER | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_CHARGE_STATE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_MAX_VOLTAGE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_MAX_CURRENT | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_PLUGGED_TYPE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_HEALTH_STATE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_TEMPERATURE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_VOLTAGE | Added|
| ohos.batteryinfo | CommonEventBatteryChangedCode | EXTRA_SOC = 0 | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_CRITICAL | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_LOW | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_NORMAL | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_HIGH | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_FULL | Added|
| ohos.batteryinfo | BatteryCapacityLevel | LEVEL_NONE | Added|
| ohos.batteryinfo | batteryInfo | const remainingEnergy: number; | Added|
| ohos.batteryinfo | batteryInfo | const nowCurrent: number; | Added|
| ohos.batteryinfo | batteryInfo | const totalEnergy: number; | Added|
| ohos.batteryinfo | batteryInfo | const estimatedRemainingChargeTime: number; | Added|
| ohos.batteryinfo | batteryInfo | const batteryCapacityLevel: BatteryCapacityLevel; | Added|
| ohos.power | DevicePowerMode | MODE_EXTREME_POWER_SAVE | Added|
| ohos.power | DevicePowerMode | MODE_PERFORMANCE | Added|
| ohos.power | DevicePowerMode | MODE_POWER_SAVE | Added|
| ohos.power | DevicePowerMode | MODE_NORMAL = 600 | Added|
| ohos.power | power | setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void;<br>setPowerMode(mode: DevicePowerMode): Promise\<void>; | Added|
| ohos.power | power | getPowerMode(callback: AsyncCallback\<DevicePowerMode>): void;<br>getPowerMode(): Promise\<DevicePowerMode>; | Added|
| ohos.power | power | suspendDevice(): void; | Added|
| ohos.power | power | wakeupDevice(detail: string): void; | Added|
