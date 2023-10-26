| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：ChargeType;<br>方法or属性：NONE|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRED_NORMAL|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRED_QUICK|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRED_SUPER_QUICK|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRELESS_NORMAL|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRELESS_QUICK|@ohos.charger.d.ts|
|新增|NA|类名：ChargeType;<br>方法or属性：WIRELESS_SUPER_QUICK|@ohos.charger.d.ts|
|新增|NA|类名：power;<br>方法or属性：function isStandby(): boolean;|@ohos.power.d.ts|
|废弃版本有变化|类名：power;<br>方法or属性：function isScreenOn(): Promise\<boolean>;<br>旧版本信息：|类名：power;<br>方法or属性：function isScreenOn(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： power#isActive|@ohos.power.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>;<br>新版本信息：9<br>代替接口： RunningLock#isSupported|@ohos.runningLock.d.ts|
|废弃版本有变化|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>新版本信息：9<br>代替接口： RunningLock#create|@ohos.runningLock.d.ts|
|废弃版本有变化|类名：RunningLockType;<br>方法or属性：BACKGROUND = 1<br>旧版本信息：|类名：RunningLockType;<br>方法or属性：BACKGROUND = 1<br>新版本信息：10<br>代替接口：|@ohos.runningLock.d.ts|
|新增(错误码)|类名：batteryStats;<br>方法or属性：function getBatteryStats(): Promise\<Array\<BatteryStatsInfo>>;<br>旧版本信息：|类名：batteryStats;<br>方法or属性：function getBatteryStats(): Promise\<Array\<BatteryStatsInfo>>;<br>新版本信息：202,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：batteryStats;<br>方法or属性：function getBatteryStats(callback: AsyncCallback\<Array\<BatteryStatsInfo>>): void;<br>旧版本信息：401|类名：batteryStats;<br>方法or属性：function getBatteryStats(callback: AsyncCallback\<Array\<BatteryStatsInfo>>): void;<br>新版本信息：202,401,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：batteryStats;<br>方法or属性：function getAppPowerValue(uid: number): number;<br>旧版本信息：4600101|类名：batteryStats;<br>方法or属性：function getAppPowerValue(uid: number): number;<br>新版本信息：202,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：batteryStats;<br>方法or属性：function getAppPowerPercent(uid: number): number;<br>旧版本信息：4600101|类名：batteryStats;<br>方法or属性：function getAppPowerPercent(uid: number): number;<br>新版本信息：202,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerValue(type: ConsumptionType): number;<br>旧版本信息：401,4600101|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerValue(type: ConsumptionType): number;<br>新版本信息：202,401,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerPercent(type: ConsumptionType): number;<br>旧版本信息：401,4600101|类名：batteryStats;<br>方法or属性：function getHardwareUnitPowerPercent(type: ConsumptionType): number;<br>新版本信息：202,401,4600101|@ohos.batteryStatistics.d.ts|
|错误码有变化|类名：brightness;<br>方法or属性：function setValue(value: number): void;<br>旧版本信息：401,4700101|类名：brightness;<br>方法or属性：function setValue(value: number): void;<br>新版本信息：202,401,4700101|@ohos.brightness.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function shutdown(reason: string): void;<br>旧版本信息：201,401,4900101|类名：power;<br>方法or属性：function shutdown(reason: string): void;<br>新版本信息：201,202,401,4900101|@ohos.power.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function reboot(reason: string): void;<br>旧版本信息：201,401,4900101|类名：power;<br>方法or属性：function reboot(reason: string): void;<br>新版本信息：201,202,401,4900101|@ohos.power.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function wakeup(detail: string): void;<br>旧版本信息：401,4900101|类名：power;<br>方法or属性：function wakeup(detail: string): void;<br>新版本信息：202,401,4900101|@ohos.power.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function suspend(isImmediate?: boolean): void;<br>旧版本信息：4900101|类名：power;<br>方法or属性：function suspend(isImmediate?: boolean): void;<br>新版本信息：202,4900101|@ohos.power.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,4900101|@ohos.power.d.ts|
|错误码有变化|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode): Promise\<void>;<br>旧版本信息：201,401|类名：power;<br>方法or属性：function setPowerMode(mode: DevicePowerMode): Promise\<void>;<br>新版本信息：201,202,401,4900101|@ohos.power.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_INVALID = -17<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_INVALID = -17<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_APP<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_APP<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_BLUETOOTH<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_BLUETOOTH<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_IDLE<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_IDLE<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_PHONE<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_PHONE<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_RADIO<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_RADIO<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_SCREEN<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_SCREEN<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_USER<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_USER<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_WIFI<br>旧版本信息：|类名：ConsumptionType;<br>方法or属性：CONSUMPTION_TYPE_WIFI<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：BatteryStatsInfo;<br>方法or属性：uid: number;<br>旧版本信息：|类名：BatteryStatsInfo;<br>方法or属性：uid: number;<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：BatteryStatsInfo;<br>方法or属性：type: ConsumptionType;<br>旧版本信息：|类名：BatteryStatsInfo;<br>方法or属性：type: ConsumptionType;<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|访问级别有变化|类名：BatteryStatsInfo;<br>方法or属性：power: number;<br>旧版本信息：|类名：BatteryStatsInfo;<br>方法or属性：power: number;<br>新版本信息：systemapi|@ohos.batteryStatistics.d.ts|
|权限有变化|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>旧版本信息：|类名：runningLock;<br>方法or属性：function createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>;<br>新版本信息：ohos.permission.RUNNING_LOCK|@ohos.runningLock.d.ts|
|函数有变化|类名：power;<br>方法or属性：function suspend(): void;|类名：power;<br>方法or属性：function suspend(isImmediate?: boolean): void;|@ohos.power.d.ts|
