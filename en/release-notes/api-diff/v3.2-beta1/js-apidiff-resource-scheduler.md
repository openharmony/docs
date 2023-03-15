# JS API Changes of the Distributed Scheduler Subsystem

The table below lists the APIs changes of the distributed scheduler subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.bundleState | bundleState | getRecentlyUsedModules(maxNum?: number, callback: AsyncCallback\<Array\<BundleActiveModuleInfo>>): void;<br>getRecentlyUsedModules(maxNum?: number): Promise\<Array\<BundleActiveModuleInfo>>; | Added|
| ohos.bundleState | BundleActiveModuleInfo | formRecords: Array\<BundleActiveFormInfo>; | Added|
| ohos.bundleState | BundleActiveModuleInfo | lastModuleUsedTime: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | launchedCount: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | abilityIconId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | abilityDescriptionId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | abilityLableId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | descriptionId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | labelId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | appLabelId?: number; | Added|
| ohos.bundleState | BundleActiveModuleInfo | abilityName?: string; | Added|
| ohos.bundleState | BundleActiveModuleInfo | moduleName: string; | Added|
| ohos.bundleState | BundleActiveModuleInfo | bundleName: string; | Added|
| ohos.bundleState | BundleActiveModuleInfo | deviceId?: string; | Added|
| ohos.bundleState | BundleActiveFormInfo | count: number; | Added|
| ohos.bundleState | BundleActiveFormInfo | formLastUsedTime: number; | Added|
| ohos.bundleState | BundleActiveFormInfo | formId: number; | Added|
| ohos.bundleState | BundleActiveFormInfo | formDimension: number; | Added|
| ohos.bundleState | BundleActiveFormInfo | formName: string; | Added|
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_LOW_OR_OKAY | Added|
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_OKAY | Added|
| ohos.workScheduler | StorageRequest | STORAGE_LEVEL_LOW = 0 | Added|
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_LOW_OR_OKAY | Added|
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_OKAY | Added|
| ohos.workScheduler | BatteryStatus | BATTERY_STATUS_LOW = 0 | Added|
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_WIRELESS | Added|
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_USB | Added|
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_AC | Added|
| ohos.workScheduler | ChargingType | CHARGING_PLUGGED_ANY = 0 | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_ETHERNET | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_WIFI_P2P | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_BLUETOOTH | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_WIFI | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_MOBILE | Added|
| ohos.workScheduler | NetworkType | NETWORK_TYPE_ANY = 0 | Added|
| ohos.workScheduler | workScheduler | isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>isLastWorkTimeOut(workId: number): Promise\<boolean>; | Added|
| ohos.workScheduler | workScheduler | stopAndClearWorks(): boolean; | Added|
| ohos.workScheduler | workScheduler | obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>obtainAllWorks(): Promise\<Array\<WorkInfo>>; | Added|
| ohos.workScheduler | workScheduler | getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void;<br>getWorkStatus(workId: number): Promise\<WorkInfo>; | Added|
| ohos.workScheduler | workScheduler | stopWork(work: WorkInfo, needCancel?: boolean): boolean; | Added|
| ohos.workScheduler | workScheduler | startWork(work: WorkInfo): boolean; | Added|
| ohos.workScheduler | WorkInfo | idleWaitTime?: number; | Added|
| ohos.workScheduler | WorkInfo | isDeepIdle?: boolean; | Added|
| ohos.workScheduler | WorkInfo | repeatCount?: number; | Added|
| ohos.workScheduler | WorkInfo | isRepeat?: boolean; | Added|
| ohos.workScheduler | WorkInfo | repeatCycleTime?: number; | Added|
| ohos.workScheduler | WorkInfo | storageRequest?: StorageRequest; | Added|
| ohos.workScheduler | WorkInfo | batteryStatus?: BatteryStatus; | Added|
| ohos.workScheduler | WorkInfo | batteryLevel?: number; | Added|
| ohos.workScheduler | WorkInfo | chargerType?: ChargingType; | Added|
| ohos.workScheduler | WorkInfo | isCharging?: boolean; | Added|
| ohos.workScheduler | WorkInfo | networkType?: NetworkType; | Added|
| ohos.workScheduler | WorkInfo | isPersisted?: boolean; | Added|
| ohos.workScheduler | WorkInfo | abilityName: string; | Added|
| ohos.workScheduler | WorkInfo | bundleName: string; | Added|
| ohos.workScheduler | WorkInfo | workId: number; | Added|
| ohos.WorkSchedulerExtensionAbility | WorkSchedulerExtensionAbility | onWorkStop(work: workScheduler.WorkInfo): void; | Added|
| ohos.WorkSchedulerExtensionAbility | WorkSchedulerExtensionAbility | onWorkStart(work: workScheduler.WorkInfo): void; | Added|
