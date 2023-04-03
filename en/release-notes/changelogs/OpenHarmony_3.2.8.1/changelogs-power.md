# Power Subsystem ChangeLog

## cl.powermgr.1 Error Information Return Method Change of APIs

The following APIs used service logic return values to indicate error information, which did not comply with the error code specifications of OpenHarmony. Therefore, they are modified in API version 9 and later.

- Power consumption statistics: [@ohos.batteryStatistics](../../../application-dev/reference/apis/js-apis-batteryStatistics.md)
 - Brightness: [@ohos.brightness](../../../application-dev/reference/apis/js-apis-brightness.md)
 - Power manager: [@ohos.power](../../../application-dev/reference/apis/js-apis-power.md)
 - RunningLock: [@ohos.runningLock](../../../application-dev/reference/apis/js-apis-runninglock.md)
 - Thermal manager: [@ohos.thermal](../../../application-dev/reference/apis/js-apis-thermal.md)

Asynchronous API: An error message is returned via **AsyncCallback** or the **error** object of **Promise**.

Synchronous API: An error message is returned via an exception.

#### Change Impacts

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

#### Key API/Component Changes

Error code processing is added for the following APIs:
  - getBatteryStats(callback: AsyncCallback<Array&lt;BatteryStatsInfo&gt;>): void
  - getAppPowerValue(uid: number): number
  - getAppPowerPercent(uid: number): number
  - getHardwareUnitPowerValue(type: ConsumptionType): number
  - getHardwareUnitPowerPercent(type: ConsumptionType): number
  - setValue(value: number): void
  - shutdown(reason: string): void;
  - isActive(): boolean
  - wakeup(detail: string): void
  - suspend(): void
  - getPowerMode(): DevicePowerMode
  - setPowerMode(mode: DevicePowerMode, callback: AsyncCallback&lt;void&gt;): void
  - setPowerMode(mode: DevicePowerMode): Promise&lt;void&gt;
  - hold(timeout: number): void
  - isHolding(): boolean
  - unhold(): void
  - isSupported(type: RunningLockType): boolean
  - isSupported(type: RunningLockType): boolean
  - create(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void
  - create(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;
  - registerThermalLevelCallback(callback: Callback&lt;ThermalLevel&gt;): void
  - unregisterThermalLevelCallback(callback?: Callback&lt;void&gt;): void
  - getLevel(): ThermalLevel

#### Adaptation Guide

For details, see the API reference document of each API.
## cl.powermgr.2 System API Change

#### Change Impacts

The application developed based on earlier versions needs to adapt to new API names and the new method for returning API error information. Otherwise, the original service logic will be affected.

#### Key API/Component Changes

| Bundle Name       | Original API                              | New API                        |
| ----------- | ------------------------------------ | ------------------------------ |
| @ohos.power | shutdownDevice(reason: string): void | shutdown(reason: string): void |
| @ohos.power | rebootDevice(reason: string): void   | reboot(reason: string): void   |
| @ohos.power | wakeupDevice(detail: string): void   | wakeup(detail: string): void   |
| @ohos.power | suspendDevice(): void                | suspend(): void                |

#### Adaptation Guide

For details, see [@ohos.power](../../../application-dev/reference/apis/js-apis-power.md).
