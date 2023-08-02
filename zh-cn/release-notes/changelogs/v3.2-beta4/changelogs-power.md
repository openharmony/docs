# 电源子系统ChangeLog

## cl.powermgr.1 API错误信息返回方式变更

下列API使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9进行变更。

- 耗电统计：[@ohos.batteryStatistics](../../../application-dev/reference/apis/js-apis-batteryStatistics.md)
 - 屏幕亮度：[@ohos.brightness](../../../application-dev/reference/apis/js-apis-brightness.md)
 - 系统电源管理：[@ohos.power](../../../application-dev/reference/apis/js-apis-power.md)
 - Runninglock锁：[@ohos.runningLock](../../../application-dev/reference/apis/js-apis-runninglock.md)
 - 热管理：[@ohos.thermal](../../../application-dev/reference/apis/js-apis-thermal.md)

异步接口：通过AsyncCallback或Promise的error对象返回错误信息。

同步接口：通过抛出异常的方式返回错误信息。

#### 变更影响

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

#### 关键的接口/组件变更

在以下接口增加错误码处理：
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

#### 适配指导

请参考各接口的API参考。
## cl.powermgr.2 系统接口变更

#### 变更影响

基于此前版本开发的应用，需适配新接口名和错误信息返回方式，否则会影响原有业务逻辑。

#### 关键的接口/组件变更

| 包名        | 旧接口                               | 新接口                         |
| ----------- | ------------------------------------ | ------------------------------ |
| @ohos.power | shutdownDevice(reason: string): void | shutdown(reason: string): void |
| @ohos.power | rebootDevice(reason: string): void   | reboot(reason: string): void   |
| @ohos.power | wakeupDevice(detail: string): void   | wakeup(detail: string): void   |
| @ohos.power | suspendDevice(): void                | suspend(): void                |

#### 适配指导

请参考系统电源管理[@ohos.power](../../../application-dev/reference/apis/js-apis-power.md)的API参考。
