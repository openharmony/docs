| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：ResourceType;<br>方法or属性：RUNNING_LOCK = 1 \<\< 7|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：SENSOR = 1 \<\< 8|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|新增|NA|类名：deviceStandby;<br>方法or属性：function getExemptedApps(resourceTypes: number, callback: AsyncCallback\<Array\<ExemptedAppInfo>>): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：deviceStandby;<br>方法or属性：function getExemptedApps(resourceTypes: number): Promise\<Array\<ExemptedAppInfo>>;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：deviceStandby;<br>方法or属性：function requestExemptionResource(request: ResourceRequest): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：deviceStandby;<br>方法or属性：function releaseExemptionResource(request: ResourceRequest): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：NETWORK = 1|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：RUNNING_LOCK = 1 \<\< 1|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：TIMER = 1 \<\< 2|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：WORK_SCHEDULER = 1 \<\< 3|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：AUTO_SYNC = 1 \<\< 4|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：PUSH = 1 \<\< 5|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceType;<br>方法or属性：FREEZE = 1 \<\< 6|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ExemptedAppInfo;<br>方法or属性：resourceTypes: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceRequest;<br>方法or属性：resourceTypes: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ExemptedAppInfo;<br>方法or属性：name: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceRequest;<br>方法or属性：name: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ExemptedAppInfo;<br>方法or属性：duration: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceRequest;<br>方法or属性：duration: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceRequest;<br>方法or属性：uid: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：ResourceRequest;<br>方法or属性：reason: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function isIdleStateSync(bundleName: string): boolean;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroupSync(): number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：usageStatistics;<br>方法or属性：function queryAppGroupSync(bundleName: string): number;|@ohos.resourceschedule.usageStatistics.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<Array\<WorkInfo>>): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<boolean>): void;|@ohos.resourceschedule.workScheduler.d.ts|
|新增|NA|类名：WorkSchedulerExtensionAbility;<br>方法or属性：context: WorkSchedulerExtensionContext;|@ohos.WorkSchedulerExtensionAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#startBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#stopBackgroundRunning|@ohos.ability.particleAbility.d.ts|
|废弃版本有变化|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>旧版本信息：|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>新版本信息：10<br>代替接口：|@ohos.resourceschedule.workScheduler.d.ts|
|废弃版本有变化|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>旧版本信息：|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>新版本信息：10<br>代替接口：|@ohos.resourceschedule.workScheduler.d.ts|
|访问级别有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>新版本信息：systemapi|@ohos.bundleState.d.ts|
|访问级别有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(<br>    byInterval: IntervalType,<br>    begin: number,<br>    end: number<br>  ): Promise\<Array\<BundleStateInfo>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(<br>    byInterval: IntervalType,<br>    begin: number,<br>    end: number<br>  ): Promise\<Array\<BundleStateInfo>>;<br>新版本信息：systemapi|@ohos.bundleState.d.ts|
|访问级别有变化|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>新版本信息：systemapi|@ohos.bundleState.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：CPU = 1<br>旧版本信息：|类名：ResourceType;<br>方法or属性：CPU = 1<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：COMMON_EVENT = 1 \<\< 1<br>旧版本信息：|类名：ResourceType;<br>方法or属性：COMMON_EVENT = 1 \<\< 1<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：TIMER = 1 \<\< 2<br>旧版本信息：|类名：ResourceType;<br>方法or属性：TIMER = 1 \<\< 2<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：WORK_SCHEDULER = 1 \<\< 3<br>旧版本信息：|类名：ResourceType;<br>方法or属性：WORK_SCHEDULER = 1 \<\< 3<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：BLUETOOTH = 1 \<\< 4<br>旧版本信息：|类名：ResourceType;<br>方法or属性：BLUETOOTH = 1 \<\< 4<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：GPS = 1 \<\< 5<br>旧版本信息：|类名：ResourceType;<br>方法or属性：GPS = 1 \<\< 5<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：ResourceType;<br>方法or属性：AUDIO = 1 \<\< 6<br>旧版本信息：|类名：ResourceType;<br>方法or属性：AUDIO = 1 \<\< 6<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：resourceTypes: number;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：resourceTypes: number;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：isApply: boolean;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：isApply: boolean;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：timeOut: number;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：timeOut: number;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：isPersist?: boolean;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：isPersist?: boolean;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：isProcess?: boolean;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：isProcess?: boolean;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：EfficiencyResourcesRequest;<br>方法or属性：reason: string;<br>旧版本信息：|类名：EfficiencyResourcesRequest;<br>方法or属性：reason: string;<br>新版本信息：systemapi|@ohos.resourceschedule.backgroundTaskManager.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：id: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：id: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：abilityInFgTotalTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：abilityInFgTotalTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：abilityPrevAccessTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：abilityPrevAccessTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：abilityPrevSeenTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：abilityPrevSeenTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：abilitySeenTotalTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：abilitySeenTotalTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：bundleName?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：bundleName?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：fgAbilityAccessTotalTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：fgAbilityAccessTotalTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：fgAbilityPrevAccessTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：fgAbilityPrevAccessTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：infosBeginTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：infosBeginTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleStatsInfo;<br>方法or属性：infosEndTime?: number;<br>旧版本信息：|类名：BundleStatsInfo;<br>方法or属性：infosEndTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapFormInfo;<br>方法or属性：formName: string;<br>旧版本信息：|类名：HapFormInfo;<br>方法or属性：formName: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapFormInfo;<br>方法or属性：formDimension: number;<br>旧版本信息：|类名：HapFormInfo;<br>方法or属性：formDimension: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapFormInfo;<br>方法or属性：formId: number;<br>旧版本信息：|类名：HapFormInfo;<br>方法or属性：formId: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapFormInfo;<br>方法or属性：formLastUsedTime: number;<br>旧版本信息：|类名：HapFormInfo;<br>方法or属性：formLastUsedTime: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapFormInfo;<br>方法or属性：count: number;<br>旧版本信息：|类名：HapFormInfo;<br>方法or属性：count: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：DeviceEventStats;<br>方法or属性：count: number;<br>旧版本信息：|类名：DeviceEventStats;<br>方法or属性：count: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：deviceId?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：bundleName: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：moduleName: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：moduleName: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：abilityName?: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：abilityName?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：appLabelId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：appLabelId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：labelId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：labelId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：descriptionId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：descriptionId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：abilityLableId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：abilityLableId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：abilityDescriptionId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：abilityDescriptionId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：abilityIconId?: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：abilityIconId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：launchedCount: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：launchedCount: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：lastModuleUsedTime: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：lastModuleUsedTime: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：HapModuleInfo;<br>方法or属性：formRecords: Array\<HapFormInfo>;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：formRecords: Array\<HapFormInfo>;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：DeviceEventStats;<br>方法or属性：name: string;<br>旧版本信息：|类名：DeviceEventStats;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：DeviceEventStats;<br>方法or属性：eventId: number;<br>旧版本信息：|类名：DeviceEventStats;<br>方法or属性：eventId: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：appGroup?: number;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：appGroup?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：indexOfLink?: string;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：indexOfLink?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：nameOfClass?: string;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：nameOfClass?: string;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：eventOccurredTime?: number;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：eventOccurredTime?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：BundleEvents;<br>方法or属性：eventId?: number;<br>旧版本信息：|类名：BundleEvents;<br>方法or属性：eventId?: number;<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：IntervalType;<br>方法or属性：BY_OPTIMIZED = 0<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_OPTIMIZED = 0<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：IntervalType;<br>方法or属性：BY_DAILY = 1<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_DAILY = 1<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：IntervalType;<br>方法or属性：BY_WEEKLY = 2<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_WEEKLY = 2<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：IntervalType;<br>方法or属性：BY_MONTHLY = 3<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_MONTHLY = 3<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：IntervalType;<br>方法or属性：BY_ANNUALLY = 4<br>旧版本信息：|类名：IntervalType;<br>方法or属性：BY_ANNUALLY = 4<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：ALIVE_GROUP = 10<br>旧版本信息：|类名：GroupType;<br>方法or属性：ALIVE_GROUP = 10<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：DAILY_GROUP = 20<br>旧版本信息：|类名：GroupType;<br>方法or属性：DAILY_GROUP = 20<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：FIXED_GROUP = 30<br>旧版本信息：|类名：GroupType;<br>方法or属性：FIXED_GROUP = 30<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：RARE_GROUP = 40<br>旧版本信息：|类名：GroupType;<br>方法or属性：RARE_GROUP = 40<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：LIMITED_GROUP = 50<br>旧版本信息：|类名：GroupType;<br>方法or属性：LIMITED_GROUP = 50<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|访问级别有变化|类名：GroupType;<br>方法or属性：NEVER_GROUP = 60<br>旧版本信息：|类名：GroupType;<br>方法or属性：NEVER_GROUP = 60<br>新版本信息：systemapi|@ohos.resourceschedule.usageStatistics.d.ts|
|权限有变化|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>新版本信息：ohos.permission.KEEP_BACKGROUND_RUNNING|@ohos.ability.particleAbility.d.ts|
|权限有变化|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>;<br>旧版本信息：|类名：backgroundTaskManager;<br>方法or属性：function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>;<br>新版本信息：ohos.permission.KEEP_BACKGROUND_RUNNING|@ohos.backgroundTaskManager.d.ts|
|权限有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>;<br>新版本信息：ohos.permission.BUNDLE_ACTIVE_INFO|@ohos.bundleState.d.ts|
|权限有变化|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(<br>    byInterval: IntervalType,<br>    begin: number,<br>    end: number<br>  ): Promise\<Array\<BundleStateInfo>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleStateInfoByInterval(<br>    byInterval: IntervalType,<br>    begin: number,<br>    end: number<br>  ): Promise\<Array\<BundleStateInfo>>;<br>新版本信息：ohos.permission.BUNDLE_ACTIVE_INFO|@ohos.bundleState.d.ts|
|权限有变化|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>旧版本信息：|类名：bundleState;<br>方法or属性：function queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>;<br>新版本信息：ohos.permission.BUNDLE_ACTIVE_INFO|@ohos.bundleState.d.ts|
|model有变化|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>;<br>新版本信息：FAModelOnly|@ohos.ability.particleAbility.d.ts|
|model有变化|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>旧版本信息：|类名：particleAbility;<br>方法or属性：function cancelBackgroundRunning(): Promise\<void>;<br>新版本信息：FAModelOnly|@ohos.ability.particleAbility.d.ts|
