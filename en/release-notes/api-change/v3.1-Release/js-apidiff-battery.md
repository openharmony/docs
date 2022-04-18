# JS API Changes of the Power Management Subsystem

The table below lists the APIs changes of the power management subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.thermal | thermal | function getThermalLevel(): ThermalLevel; | Added|
| ohos.thermal | thermal | function unsubscribeThermalLevel(callback?: AsyncCallback<void>): void; | Added|
| ohos.thermal | thermal | function subscribeThermalLevel(callback: AsyncCallback<ThermalLevel>): void; | Added|
| ohos.thermal | ThermalLevel | EMERGENCY = 6 | Added|
| ohos.thermal | ThermalLevel | WARNING = 5 | Added|
| ohos.thermal | ThermalLevel | OVERHEATED = 4 | Added|
| ohos.thermal | ThermalLevel | HOT = 3 | Added|
| ohos.thermal | ThermalLevel | WARM = 2 | Added|
| ohos.thermal | ThermalLevel | NORMAL = 1 | Added|
| ohos.thermal | ThermalLevel | COOL = 0 | Added|
| ohos.runninglock | runningLock | function createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback<RunningLock>): void;<br>function createRunningLock(name: string, type: RunningLockType): Promise<RunningLock>; | Added|
| ohos.runninglock | runningLock | function isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback<boolean>): void;<br>function isRunningLockTypeSupported(type: RunningLockType): Promise<boolean>; | Added|
