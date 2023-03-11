| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: backgroundTaskManager<br>Method or attribute name: function applyEfficiencyResources(request: EfficiencyResourcesRequest): boolean;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: backgroundTaskManager<br>Method or attribute name: function resetAllEfficiencyResources(): void;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: CPU = 1|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: COMMON_EVENT = 1 << 1|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: TIMER = 1 << 2|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: WORK_SCHEDULER = 1 << 3|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: BLUETOOTH = 1 << 4|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: GPS = 1 << 5|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: ResourceType<br>Method or attribute name: AUDIO = 1 << 6|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: resourceTypes: number;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: isApply: boolean;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: timeOut: number;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: isPersist?: boolean;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: isProcess?: boolean;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.backgroundTaskManager<br>Class name: EfficiencyResourcesRequest<br>Method or attribute name: reason: string;|NA|@ohos.backgroundTaskManager.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: workId: number;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: bundleName: string;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: abilityName: string;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: isPersisted?: boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: networkType?: NetworkType;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: isCharging?: boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: chargerType?: ChargingType;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: batteryLevel?: number;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: batteryStatus?: BatteryStatus;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: storageRequest?: StorageRequest;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: repeatCycleTime?: number;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: isRepeat?: boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: repeatCount?: number;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: isDeepIdle?: boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: idleWaitTime?: number;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: WorkInfo<br>Method or attribute name: parameters?: {[key: string]: any};|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function startWork(work: WorkInfo): boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function stopWork(work: WorkInfo, needCancel?: boolean): boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function getWorkStatus(workId: number): Promise<WorkInfo>;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function obtainAllWorks(): Promise<Array<WorkInfo>>;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function stopAndClearWorks(): boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: workScheduler<br>Method or attribute name: function isLastWorkTimeOut(workId: number): Promise<boolean>;|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_ANY = 0|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_MOBILE|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_WIFI|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_BLUETOOTH|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_WIFI_P2P|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: NetworkType<br>Method or attribute name: NETWORK_TYPE_ETHERNET|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: ChargingType|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: ChargingType<br>Method or attribute name: CHARGING_PLUGGED_ANY = 0|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: ChargingType<br>Method or attribute name: CHARGING_PLUGGED_AC|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: ChargingType<br>Method or attribute name: CHARGING_PLUGGED_USB|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: ChargingType<br>Method or attribute name: CHARGING_PLUGGED_WIRELESS|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: BatteryStatus|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: BatteryStatus<br>Method or attribute name: BATTERY_STATUS_LOW = 0|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: BatteryStatus<br>Method or attribute name: BATTERY_STATUS_OKAY|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: BatteryStatus<br>Method or attribute name: BATTERY_STATUS_LOW_OR_OKAY|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: StorageRequest|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: StorageRequest<br>Method or attribute name: STORAGE_LEVEL_LOW = 0|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: StorageRequest<br>Method or attribute name: STORAGE_LEVEL_OKAY|NA|@ohos.workScheduler.d.ts|
|Deleted|Module name: ohos.workScheduler<br>Class name: StorageRequest<br>Method or attribute name: STORAGE_LEVEL_LOW_OR_OKAY|NA|@ohos.workScheduler.d.ts|
