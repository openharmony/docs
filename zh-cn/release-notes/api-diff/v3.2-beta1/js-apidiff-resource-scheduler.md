# 资源调度子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，资源调度子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.bundleState | bundleState | getRecentlyUsedModules(maxNum?: number, callback: AsyncCallback\<Array\<BundleActiveModuleInfo>>): void;<br>getRecentlyUsedModules(maxNum?: number): Promise\<Array\<BundleActiveModuleInfo>>; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | formRecords: Array\<BundleActiveFormInfo>; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | lastModuleUsedTime: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | launchedCount: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | abilityIconId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | abilityDescriptionId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | abilityLableId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | descriptionId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | labelId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | appLabelId?: number; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | abilityName?: string; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | moduleName: string; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | bundleName: string; | 新增 |
| ohos.bundleState | BundleActiveModuleInfo | deviceId?: string; | 新增 |
| ohos.bundleState | BundleActiveFormInfo | count: number; | 新增 |
| ohos.bundleState | BundleActiveFormInfo | formLastUsedTime: number; | 新增 |
| ohos.bundleState | BundleActiveFormInfo | formId: number; | 新增 |
| ohos.bundleState | BundleActiveFormInfo | formDimension: number; | 新增 |
| ohos.bundleState | BundleActiveFormInfo | formName: string; | 新增 |
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_LOW_OR_OKAY | 新增 |
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_OKAY | 新增 |
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_LOW = 0 | 新增 |
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_LOW_OR_OKAY | 新增 |
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_OKAY | 新增 |
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_LOW = 0 | 新增 |
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_WIRELESS | 新增 |
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_USB | 新增 |
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_AC | 新增 |
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_ANY = 0 | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_ETHERNET | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_WIFI_P2P | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_BLUETOOTH | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_WIFI | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_MOBILE | 新增 |
| ohos.workScheduler | NetworkType | NETWORK_TYPE_ANY = 0 | 新增 |
| ohos.workScheduler | workScheduler | isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>isLastWorkTimeOut(workId: number): Promise\<boolean>; | 新增 |
| ohos.workScheduler | workScheduler | stopAndClearWorks(): boolean; | 新增 |
| ohos.workScheduler | workScheduler | obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>obtainAllWorks(): Promise\<Array\<WorkInfo>>; | 新增 |
| ohos.workScheduler | workScheduler | getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void;<br>getWorkStatus(workId: number): Promise\<WorkInfo>; | 新增 |
| ohos.workScheduler | workScheduler | stopWork(work: WorkInfo, needCancel?: boolean): boolean; | 新增 |
| ohos.workScheduler | workScheduler | startWork(work: WorkInfo): boolean; | 新增 |
| ohos.workScheduler | WorkInfo | idleWaitTime?: number; | 新增 |
| ohos.workScheduler | WorkInfo | isDeepIdle?: boolean; | 新增 |
| ohos.workScheduler | WorkInfo | repeatCount?: number; | 新增 |
| ohos.workScheduler | WorkInfo | isRepeat?: boolean; | 新增 |
| ohos.workScheduler | WorkInfo | repeatCycleTime?: number; | 新增 |
| ohos.workScheduler | WorkInfo | storageRequest?: StorageRequest; | 新增 |
| ohos.workScheduler | WorkInfo | batteryStatus?: BatteryStatus; | 新增 |
| ohos.workScheduler | WorkInfo | batteryLevel?: number; | 新增 |
| ohos.workScheduler | WorkInfo | chargerType?: ChargingType; | 新增 |
| ohos.workScheduler | WorkInfo | isCharging?: boolean; | 新增 |
| ohos.workScheduler | WorkInfo | networkType?: NetworkType; | 新增 |
| ohos.workScheduler | WorkInfo | isPersisted?: boolean; | 新增 |
| ohos.workScheduler | WorkInfo | abilityName: string; | 新增 |
| ohos.workScheduler | WorkInfo | bundleName: string; | 新增 |
| ohos.workScheduler | WorkInfo | workId: number; | 新增 |
| ohos.WorkSchedulerExtensionAbility | WorkSchedulerExtensionAbility | onWorkStop(work: workScheduler.WorkInfo): void; | 新增 |
| ohos.WorkSchedulerExtensionAbility | WorkSchedulerExtensionAbility | onWorkStart(work: workScheduler.WorkInfo): void; | 新增 |

