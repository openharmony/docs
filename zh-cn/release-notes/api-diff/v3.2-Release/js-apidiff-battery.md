| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：power;<br>方法or属性：function shutdownDevice(reason: string): void;|NA|@ohos.power.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_FULL|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_HIGH|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_NORMAL|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_LOW|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_WARNING|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_CRITICAL|@ohos.batteryInfo.d.ts|
|新增|NA|类名：BatteryCapacityLevel;<br>方法or属性：LEVEL_SHUTDOWN|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_SOC = "soc"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_CHARGE_STATE = "chargeState"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_HEALTH_STATE = "healthState"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_PLUGGED_TYPE = "pluggedType"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_VOLTAGE = "voltage"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_TECHNOLOGY = "technology"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_TEMPERATURE = "temperature"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_PRESENT = "present"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：CommonEventBatteryChangedKey;<br>方法or属性：EXTRA_CAPACITY_LEVEL = "capacityLevel"|@ohos.batteryInfo.d.ts|
|新增|NA|类名：power;<br>方法or属性：function shutdown(reason: string): void;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function reboot(reason: string): void;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function isActive(): boolean;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function wakeup(detail: string): void;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function suspend(): void;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function getPowerMode(): DevicePowerMode;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void;|@ohos.power.d.ts|
|新增|NA|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode): Promise\<void>;|@ohos.power.d.ts|
|新增|NA|类名：DevicePowerMode;<br>方法or属性：MODE_NORMAL = 600|@ohos.power.d.ts|
|新增|NA|类名：DevicePowerMode;<br>方法or属性：MODE_POWER_SAVE|@ohos.power.d.ts|
|新增|NA|类名：DevicePowerMode;<br>方法or属性：MODE_PERFORMANCE|@ohos.power.d.ts|
|新增|NA|类名：DevicePowerMode;<br>方法or属性：MODE_EXTREME_POWER_SAVE|@ohos.power.d.ts|
|新增|NA|类名：runningLock;<br>方法or属性：function isSupported(type: RunningLockType): boolean;|@ohos.runningLock.d.ts|
|新增|NA|类名：runningLock;<br>方法or属性：function create(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void;|@ohos.runningLock.d.ts|
|新增|NA|类名：runningLock;<br>方法or属性：function create(name: string, type: RunningLockType): Promise\<RunningLock>;|@ohos.runningLock.d.ts|
|新增|NA|类名：RunningLock;<br>方法or属性：hold(timeout: number): void;|@ohos.runningLock.d.ts|
|新增|NA|类名：RunningLock;<br>方法or属性：isHolding(): boolean;|@ohos.runningLock.d.ts|
|新增|NA|类名：RunningLock;<br>方法or属性：unhold(): void;|@ohos.runningLock.d.ts|
|新增|NA|类名：thermal;<br>方法or属性：function registerThermalLevelCallback(callback: Callback\<ThermalLevel>): void;|@ohos.thermal.d.ts|
|新增|NA|类名：thermal;<br>方法or属性：function unregisterThermalLevelCallback(callback?: Callback\<void>): void;|@ohos.thermal.d.ts|
|新增|NA|类名：thermal;<br>方法or属性：function getLevel(): ThermalLevel;|@ohos.thermal.d.ts|
|废弃版本有变化|类名：power;<br>方法or属性：function rebootDevice(reason: string): void;<br>旧版本信息：|类名：power;<br>方法or属性：function rebootDevice(reason: string): void;<br>新版本信息：9<br>代替接口： |@ohos.power.d.ts|
|废弃版本有变化|类名：power;<br>方法or属性：function isScreenOn(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：power;<br>方法or属性：function isScreenOn(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： |@ohos.power.d.ts|
|废弃版本有变化|类名：power;<br>方法or属性：function isScreenOn(): Promise\<boolean>;<br>旧版本信息：|类名：power;<br>方法or属性：function isScreenOn(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： |@ohos.power.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：RunningLock;<br>方法or属性：lock(timeout: number): void;<br>旧版本信息：|类名：RunningLock;<br>方法or属性：lock(timeout: number): void;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：RunningLock;<br>方法or属性：isUsed(): boolean;<br>旧版本信息：|类名：RunningLock;<br>方法or属性：isUsed(): boolean;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：RunningLock;<br>方法or属性：unlock(): void;<br>旧版本信息：|类名：RunningLock;<br>方法or属性：unlock(): void;<br>新版本信息：9<br>代替接口： |@ohos.runningLock.d.ts|
|废弃版本有变化|类名：thermal;<br>方法or属性：function subscribeThermalLevel(callback: AsyncCallback\<ThermalLevel>): void;<br>旧版本信息：|类名：thermal;<br>方法or属性：function subscribeThermalLevel(callback: AsyncCallback\<ThermalLevel>): void;<br>新版本信息：9<br>代替接口： |@ohos.thermal.d.ts|
|废弃版本有变化|类名：thermal;<br>方法or属性：function unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：thermal;<br>方法or属性：function unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： |@ohos.thermal.d.ts|
|废弃版本有变化|类名：thermal;<br>方法or属性：function getThermalLevel(): ThermalLevel;<br>旧版本信息：|类名：thermal;<br>方法or属性：function getThermalLevel(): ThermalLevel;<br>新版本信息：9<br>代替接口： |@ohos.thermal.d.ts|
|废弃版本有变化|类名：BatteryResponse;<br>方法or属性：export interface BatteryResponse<br>旧版本信息：|类名：BatteryResponse;<br>方法or属性：export interface BatteryResponse<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：BatteryResponse;<br>方法or属性：charging: boolean;<br>旧版本信息：|类名：BatteryResponse;<br>方法or属性：charging: boolean;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：BatteryResponse;<br>方法or属性：level: number;<br>旧版本信息：|类名：BatteryResponse;<br>方法or属性：level: number;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：GetStatusOptions;<br>方法or属性：export interface GetStatusOptions<br>旧版本信息：|类名：GetStatusOptions;<br>方法or属性：export interface GetStatusOptions<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：GetStatusOptions;<br>方法or属性：success?: (data: BatteryResponse) => void;<br>旧版本信息：|类名：GetStatusOptions;<br>方法or属性：success?: (data: BatteryResponse) => void;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：GetStatusOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetStatusOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：GetStatusOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetStatusOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：Battery;<br>方法or属性：export default class Battery<br>旧版本信息：|类名：Battery;<br>方法or属性：export default class Battery<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：Battery;<br>方法or属性：static getStatus(options?: GetStatusOptions): void;<br>旧版本信息：|类名：Battery;<br>方法or属性：static getStatus(options?: GetStatusOptions): void;<br>新版本信息：6<br>代替接口：|@system.battery.d.ts|
|废弃版本有变化|类名：BrightnessResponse;<br>方法or属性：export interface BrightnessResponse<br>旧版本信息：|类名：BrightnessResponse;<br>方法or属性：export interface BrightnessResponse<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：BrightnessResponse;<br>方法or属性：value: number;<br>旧版本信息：|类名：BrightnessResponse;<br>方法or属性：value: number;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions;<br>方法or属性：value: number;<br>旧版本信息：|类名：SetBrightnessOptions;<br>方法or属性：value: number;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessOptions;<br>方法or属性：export interface GetBrightnessOptions<br>旧版本信息：|类名：GetBrightnessOptions;<br>方法or属性：export interface GetBrightnessOptions<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessOptions;<br>方法or属性：success?: (data: BrightnessResponse) => void;<br>旧版本信息：|类名：GetBrightnessOptions;<br>方法or属性：success?: (data: BrightnessResponse) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetBrightnessOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SetBrightnessOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessModeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetBrightnessModeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SetBrightnessModeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SetKeepScreenOnOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetBrightnessOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions;<br>方法or属性：complete?: () => void<br>旧版本信息：|类名：SetBrightnessOptions;<br>方法or属性：complete?: () => void<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessModeOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetBrightnessModeOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions;<br>方法or属性：complete?: () => void<br>旧版本信息：|类名：SetBrightnessModeOptions;<br>方法or属性：complete?: () => void<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions;<br>方法or属性：complete?: () => void<br>旧版本信息：|类名：SetKeepScreenOnOptions;<br>方法or属性：complete?: () => void<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions;<br>方法or属性：export interface SetBrightnessOptions<br>旧版本信息：|类名：SetBrightnessOptions;<br>方法or属性：export interface SetBrightnessOptions<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：SetBrightnessOptions;<br>方法or属性：success?: () => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：SetBrightnessModeOptions;<br>方法or属性：success?: () => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：SetKeepScreenOnOptions;<br>方法or属性：success?: () => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：BrightnessModeResponse;<br>方法or属性：export interface BrightnessModeResponse<br>旧版本信息：|类名：BrightnessModeResponse;<br>方法or属性：export interface BrightnessModeResponse<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：BrightnessModeResponse;<br>方法or属性：mode: number;<br>旧版本信息：|类名：BrightnessModeResponse;<br>方法or属性：mode: number;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions;<br>方法or属性：mode: number;<br>旧版本信息：|类名：SetBrightnessModeOptions;<br>方法or属性：mode: number;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessModeOptions;<br>方法or属性：export interface GetBrightnessModeOptions<br>旧版本信息：|类名：GetBrightnessModeOptions;<br>方法or属性：export interface GetBrightnessModeOptions<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessModeOptions;<br>方法or属性：success?: (data: BrightnessModeResponse) => void;<br>旧版本信息：|类名：GetBrightnessModeOptions;<br>方法or属性：success?: (data: BrightnessModeResponse) => void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions;<br>方法or属性：export interface SetBrightnessModeOptions<br>旧版本信息：|类名：SetBrightnessModeOptions;<br>方法or属性：export interface SetBrightnessModeOptions<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions;<br>方法or属性：export interface SetKeepScreenOnOptions<br>旧版本信息：|类名：SetKeepScreenOnOptions;<br>方法or属性：export interface SetKeepScreenOnOptions<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions;<br>方法or属性：keepScreenOn: boolean;<br>旧版本信息：|类名：SetKeepScreenOnOptions;<br>方法or属性：keepScreenOn: boolean;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：export default class Brightness<br>旧版本信息：|类名：Brightness;<br>方法or属性：export default class Brightness<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：static getValue(options?: GetBrightnessOptions): void;<br>旧版本信息：|类名：Brightness;<br>方法or属性：static getValue(options?: GetBrightnessOptions): void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：static setValue(options?: SetBrightnessOptions): void;<br>旧版本信息：|类名：Brightness;<br>方法or属性：static setValue(options?: SetBrightnessOptions): void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：static getMode(options?: GetBrightnessModeOptions): void;<br>旧版本信息：|类名：Brightness;<br>方法or属性：static getMode(options?: GetBrightnessModeOptions): void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：static setMode(options?: SetBrightnessModeOptions): void;<br>旧版本信息：|类名：Brightness;<br>方法or属性：static setMode(options?: SetBrightnessModeOptions): void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness;<br>方法or属性：static setKeepScreenOn(options?: SetKeepScreenOnOptions): void;<br>旧版本信息：|类名：Brightness;<br>方法or属性：static setKeepScreenOn(options?: SetKeepScreenOnOptions): void;<br>新版本信息：7<br>代替接口：|@system.brightness.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getBatteryStats(callback: AsyncCallback\<Array\<BatteryStatsInfo>>): void;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getBatteryStats(callback: AsyncCallback\<Array\<BatteryStatsInfo>>): void;<br>新版本信息：401|@ohos.batteryStatistics.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getAppPowerValue(uid: number): number;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getAppPowerValue(uid: number): number;<br>新版本信息：4600101|@ohos.batteryStatistics.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getAppPowerPercent(uid: number): number;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getAppPowerPercent(uid: number): number;<br>新版本信息：4600101|@ohos.batteryStatistics.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerValue(type: ConsumptionType): number;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerValue(type: ConsumptionType): number;<br>新版本信息：401,4600101|@ohos.batteryStatistics.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerPercent(type: ConsumptionType): number;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerPercent(type: ConsumptionType): number;<br>新版本信息：401,4600101|@ohos.batteryStatistics.d.ts|
|新增(错误码)|类名：brightness;<br>方法or属性：function setValue(value: number): void;<br>旧版本信息：|类名：brightness;<br>方法or属性：function setValue(value: number): void;<br>新版本信息：401,4700101|@ohos.brightness.d.ts|
|访问级别有变化|类名：brightness;<br>方法or属性：declare brightness<br>旧版本信息：|类名：brightness;<br>方法or属性：declare brightness<br>新版本信息：systemapi|@ohos.brightness.d.ts|
