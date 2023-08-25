| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function cancelSuspendDelay(requestId: number): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number): Promise\<number>;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context): Promise\<void>;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function applyEfficiencyResources(request: EfficiencyResourcesRequest): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：backgroundTaskManager;<br>方法or属性：function resetAllEfficiencyResources(): void;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：DelaySuspendInfo;<br>方法or属性：requestId: number;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：DelaySuspendInfo;<br>方法or属性：actualDelayTime: number;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：DATA_TRANSFER = 1|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：AUDIO_PLAYBACK = 2|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：AUDIO_RECORDING = 3|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：LOCATION = 4|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：BLUETOOTH_INTERACTION = 5|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：MULTI_DEVICE_CONNECTION = 6|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：WIFI_INTERACTION = 7|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：VOIP = 8|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：BackgroundMode;<br>方法or属性：TASK_KEEPING = 9|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：CPU = 1|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：COMMON_EVENT = 1 \<\< 1|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：TIMER = 1 \<\< 2|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：WORK_SCHEDULER = 1 \<\< 3|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：BLUETOOTH = 1 \<\< 4|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：GPS = 1 \<\< 5|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：AUDIO = 1 \<\< 6|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：resourceTypes: number;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：isApply: boolean;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：timeOut: number;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：isPersist?: boolean;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：isProcess?: boolean;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：EfficiencyResourcesRequest;<br>方法or属性：reason: string;|@ohos.resourceschedule.backgroundTaskManager.d.ts|
| 新增 | NA   | 类名：AppGroupCallbackInfo; <br>方法or属性：bundleName: string; | @ohos.resourceschedule.usageStatistics.d.ts |
| 新增 | NA   | 类名：AppGroupCallbackInfo; <br/>方法or属性：appOldGroup: number; | @ohos.resourceschedule.usageStatistics.d.ts |
| 新增 | NA   | 类名：AppGroupCallbackInfo; <br/>方法or属性：appNewGroup: number; | @ohos.resourceschedule.usageStatistics.d.ts |
| 新增 | NA   | 类名：AppGroupCallbackInfo; <br/>方法or属性：userId: number; | @ohos.resourceschedule.usageStatistics.d.ts |
| 新增 | NA   | 类名：AppGroupCallbackInfo; <br/>方法or属性：changeReason: number; | @ohos.resourceschedule.usageStatistics.d.ts |
|新增|NA|类名：usageStatistics;<br>方法or属性：function isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function isIdleState(bundleName: string): Promise\<boolean>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroup(callback: AsyncCallback\<number>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroup(): Promise\<number>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroup(bundleName : string, callback: AsyncCallback\<number>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroup(bundleName : string): Promise\<number>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback\<BundleStatsMap>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleStatsInfos(begin: number, end: number): Promise\<BundleStatsMap>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback\<Array\<BundleStatsInfo>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise\<Array\<BundleStatsInfo>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleEvents(begin: number, end: number, callback: AsyncCallback\<Array\<BundleEvents>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryBundleEvents(begin: number, end: number): Promise\<Array\<BundleEvents>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback\<Array\<BundleEvents>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryCurrentBundleEvents(begin: number, end: number): Promise\<Array\<BundleEvents>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback\<Array\<HapModuleInfo>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryModuleUsageRecords(maxNum: number): Promise\<Array\<HapModuleInfo>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryModuleUsageRecords(callback: AsyncCallback\<Array\<HapModuleInfo>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryModuleUsageRecords(): Promise\<Array\<HapModuleInfo>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function setAppGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback\<void>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function setAppGroup(bundleName: string, newGroup: GroupType): Promise\<void>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function registerAppGroupCallBack(groupCallback: Callback\<AppGroupCallbackInfo>, callback: AsyncCallback\<void>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function registerAppGroupCallBack(groupCallback: Callback\<AppGroupCallbackInfo>): Promise\<void>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function unregisterAppGroupCallBack(callback: AsyncCallback\<void>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function unregisterAppGroupCallBack(): Promise\<void>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback\<Array\<DeviceEventStats>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryDeviceEventStats(begin: number, end: number): Promise\<Array\<DeviceEventStats>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback\<Array\<DeviceEventStats>>): void;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryNotificationEventStats(begin: number, end: number): Promise\<Array\<DeviceEventStats>>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：id: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：abilityInFgTotalTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：abilityPrevAccessTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：abilityPrevSeenTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：abilitySeenTotalTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：bundleName?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：bundleName?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：fgAbilityAccessTotalTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：fgAbilityPrevAccessTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：infosBeginTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleStatsInfo;<br>方法or属性：infosEndTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapFormInfo;<br>方法or属性：formName: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapFormInfo;<br>方法or属性：formDimension: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapFormInfo;<br>方法or属性：formId: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapFormInfo;<br>方法or属性：formLastUsedTime: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapFormInfo;<br>方法or属性：count: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：DeviceEventStats;<br>方法or属性：count: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：deviceId?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：bundleName: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：moduleName: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：abilityName?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：appLabelId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：labelId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：descriptionId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：abilityLableId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：abilityDescriptionId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：abilityIconId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：launchedCount: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：lastModuleUsedTime: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：formRecords: Array\<HapFormInfo>;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：DeviceEventStats;<br>方法or属性：name: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：DeviceEventStats;<br>方法or属性：eventId: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：appGroup?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：indexOfLink?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：nameOfClass?: string;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：eventOccurredTime?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：BundleEvents;<br>方法or属性：eventId?: number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：IntervalType;<br>方法or属性：BY_OPTIMIZED = 0|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：IntervalType;<br>方法or属性：BY_DAILY = 1|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：IntervalType;<br>方法or属性：BY_WEEKLY = 2|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：IntervalType;<br>方法or属性：BY_MONTHLY = 3|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：IntervalType;<br>方法or属性：BY_ANNUALLY = 4|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：ALIVE_GROUP = 10|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：DAILY_GROUP = 20|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：FIXED_GROUP = 30|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：RARE_GROUP = 40|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：LIMITED_GROUP = 50|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：GroupType;<br>方法or属性：NEVER_GROUP = 60|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function startWork(work: WorkInfo): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function stopWork(work: WorkInfo, needCancel?: boolean): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function getWorkStatus(workId: number): Promise\<WorkInfo>;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function obtainAllWorks(): Promise\<Array\<WorkInfo>>;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function stopAndClearWorks(): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number): Promise\<boolean>;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：workId: number;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：bundleName: string;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：abilityName: string;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：isPersisted?: boolean;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：networkType?: NetworkType;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：isCharging?: boolean;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：chargerType?: ChargingType;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：batteryLevel?: number;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：batteryStatus?: BatteryStatus;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：storageRequest?: StorageRequest;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：repeatCycleTime?: number;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：isRepeat?: boolean;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：repeatCount?: number;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：isDeepIdle?: boolean;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：idleWaitTime?: number;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkInfo;<br>方法or属性：parameters?: {[key: string]: number \| string \| boolean};|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_ANY = 0|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_MOBILE|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_WIFI|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_BLUETOOTH|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_WIFI_P2P|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：NetworkType;<br>方法or属性：NETWORK_TYPE_ETHERNET|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：ChargingType;<br>方法or属性：CHARGING_PLUGGED_ANY = 0|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：ChargingType;<br>方法or属性：CHARGING_PLUGGED_AC|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：ChargingType;<br>方法or属性：CHARGING_PLUGGED_USB|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：ChargingType;<br>方法or属性：CHARGING_PLUGGED_WIRELESS|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：BatteryStatus;<br>方法or属性：BATTERY_STATUS_LOW = 0|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：BatteryStatus;<br>方法or属性：BATTERY_STATUS_OKAY|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：BatteryStatus;<br>方法or属性：BATTERY_STATUS_LOW_OR_OKAY|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：StorageRequest;<br>方法or属性：STORAGE_LEVEL_LOW = 0|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：StorageRequest;<br>方法or属性：STORAGE_LEVEL_OKAY|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：StorageRequest;<br>方法or属性：STORAGE_LEVEL_LOW_OR_OKAY|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkSchedulerExtensionAbility;<br>方法or属性：onWorkStart(work: workScheduler.WorkInfo): void;|@ohos.WorkSchedulerExtensionAbility.d.ts|
|新增|NA|类名：WorkSchedulerExtensionAbility;<br>方法or属性：onWorkStop(work: workScheduler.WorkInfo): void;|@ohos.WorkSchedulerExtensionAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.startBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.startBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.stopBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.stopBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：declare backgroundTaskManager<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：declare backgroundTaskManager<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function cancelSuspendDelay(requestId: number): void;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function cancelSuspendDelay(requestId: number): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.cancelSuspendDelay|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.getRemainingDelayTime|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number): Promise\<number>;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function getRemainingDelayTime(requestId: number): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.getRemainingDelayTime|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.requestSuspendDelay|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.startBackgroundRunning|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.startBackgroundRunning|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.stopBackgroundRunning|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context): Promise\<void>;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function stopBackgroundRunning(context: Context): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.stopBackgroundRunning|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：DelaySuspendInfo;<br>方法or属性：interface DelaySuspendInfo<br>旧版本信息：|类名：DelaySuspendInfo;<br>方法or属性：interface DelaySuspendInfo<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.DelaySuspendInfo|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：DelaySuspendInfo;<br>方法or属性：requestId: number;<br>旧版本信息：|类名：DelaySuspendInfo;<br>方法or属性：requestId: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.DelaySuspendInfo|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：DelaySuspendInfo;<br>方法or属性：actualDelayTime: number;<br>旧版本信息：|类名：DelaySuspendInfo;<br>方法or属性：actualDelayTime: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.DelaySuspendInfo|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：export enum BackgroundMode<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：export enum BackgroundMode<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：DATA_TRANSFER = 1<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：DATA_TRANSFER = 1<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：AUDIO_PLAYBACK = 2<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：AUDIO_PLAYBACK = 2<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：AUDIO_RECORDING = 3<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：AUDIO_RECORDING = 3<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：LOCATION = 4<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：LOCATION = 4<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：BLUETOOTH_INTERACTION = 5<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：BLUETOOTH_INTERACTION = 5<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：MULTI_DEVICE_CONNECTION = 6<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：MULTI_DEVICE_CONNECTION = 6<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：WIFI_INTERACTION = 7<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：WIFI_INTERACTION = 7<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：VOIP = 8<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：VOIP = 8<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：BackgroundMode;<br>方法or属性：TASK_KEEPING = 9<br>旧版本信息：|类名：BackgroundMode;<br>方法or属性：TASK_KEEPING = 9<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager.BackgroundMode|@ohos.backgroundTaskManager.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：declare bundleState<br>旧版本信息：|类名：bundleState;<br>方法or属性：declare bundleState<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.isIdleState|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function isIdleState(bundleName: string): Promise\<boolean>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function isIdleState(bundleName: string): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.isIdleState|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryAppUsagePriorityGroup(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryAppUsagePriorityGroup(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryAppGroup|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryAppUsagePriorityGroup(): Promise\<number>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryAppUsagePriorityGroup(): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryAppGroup|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback\<BundleActiveInfoResponse>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback\<BundleActiveInfoResponse>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleStatsInfos|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleStatsInfos|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback\<Array\<BundleStateInfo>>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback\<Array\<BundleStateInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleStatsInfoByInterval|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise\<Array\<BundleStateInfo>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise\<Array\<BundleStateInfo>>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleStatsInfoByInterval|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryBundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryCurrentBundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：bundleState;<br>方法or属性：function queryCurrentBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryCurrentBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.queryCurrentBundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：interface BundleStateInfo<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：interface BundleStateInfo<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：id: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：id: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：abilityInFgTotalTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：abilityInFgTotalTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：abilityPrevAccessTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：abilityPrevAccessTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：abilityPrevSeenTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：abilityPrevSeenTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：abilitySeenTotalTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：abilitySeenTotalTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：bundleName?: string;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：bundleName?: string;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：fgAbilityAccessTotalTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：fgAbilityAccessTotalTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：fgAbilityPrevAccessTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：fgAbilityPrevAccessTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：infosBeginTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：infosBeginTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：infosEndTime?: number;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：infosEndTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleStateInfo;<br>方法or属性：merge(toMerge: BundleStateInfo): void;<br>旧版本信息：|类名：BundleStateInfo;<br>方法or属性：merge(toMerge: BundleStateInfo): void;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsInfo|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：interface BundleActiveState<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：interface BundleActiveState<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：appUsagePriorityGroup?: number;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：appUsagePriorityGroup?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：indexOfLink?: string;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：indexOfLink?: string;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：nameOfClass?: string;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：nameOfClass?: string;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：stateOccurredTime?: number;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：stateOccurredTime?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveState;<br>方法or属性：stateType?: number;<br>旧版本信息：|类名：BundleActiveState;<br>方法or属性：stateType?: number;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleEvents|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：BundleActiveInfoResponse;<br>方法or属性：interface BundleActiveInfoResponse<br>旧版本信息：|类名：BundleActiveInfoResponse;<br>方法or属性：interface BundleActiveInfoResponse<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.BundleStatsMap|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：export enum IntervalType<br>旧版本信息：|类名：IntervalType;<br>方法or属性：export enum IntervalType<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：BY_OPTIMIZED = 0<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_OPTIMIZED = 0<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：BY_DAILY = 1<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_DAILY = 1<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：BY_WEEKLY = 2<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_WEEKLY = 2<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：BY_MONTHLY = 3<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_MONTHLY = 3<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
|废弃版本有变化|类名：IntervalType;<br>方法or属性：BY_ANNUALLY = 4<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_ANNUALLY = 4<br>新版本信息：9<br>代替接口： ohos.resourceschedule.usageStatistics.IntervalType|@ohos.bundleState.d.ts|
