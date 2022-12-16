# 电源服务子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，电源服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.thermal | thermal | getThermalLevel(): ThermalLevel; | 新增 |
| ohos.thermal | thermal | unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void; | 新增 |
| ohos.thermal | thermal | subscribeThermalLevel(callback: AsyncCallback\<ThermalLevel>): void; | 新增 |
| ohos.thermal | ThermalLevel | EMERGENCY = 6 | 新增 |
| ohos.thermal | ThermalLevel | WARNING = 5 | 新增 |
| ohos.thermal | ThermalLevel | OVERHEATED = 4 | 新增 |
| ohos.thermal | ThermalLevel | HOT = 3 | 新增 |
| ohos.thermal | ThermalLevel | WARM = 2 | 新增 |
| ohos.thermal | ThermalLevel | NORMAL = 1 | 新增 |
| ohos.thermal | ThermalLevel | COOL = 0 | 新增 |
| ohos.runninglock | runningLock | createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void;<br>createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>; | 新增 |
| ohos.runninglock | runningLock | isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void;<br>isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>; | 新增 |
