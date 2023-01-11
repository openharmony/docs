# 资源调度子系统ChangeLog

## cl.resourceschedule.backgroundTaskManager 
对资源调度子系统backgroundTaskManager仓原有接口进行整改，原有API8及之前的接口全部废弃，原有API9接口删除，需要使用新的API9接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更。废弃@ohos.backgroundTaskManager.d.ts文件，新增@ohos.resourceschedule.backgroundTaskManager.d.ts文件，将相关接口变更至对应的文件。

| 类名 | 接口类型 | 接口声明 | 说明 | 
|  -- | -- | -- | -- |
| backgroundTaskManager | namespace | declare namespace backgroundTaskManager | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function resetAllEfficiencyResources(): void; | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function applyEfficiencyResources(request: EfficiencyResourcesRequest): bool; | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts，修改为function applyEfficiencyResources(request: EfficiencyResourcesRequest): void; | 
| backgroundTaskManager | method | function stopBackgroundRunning(context: Context): Promise<void>; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function stopBackgroundRunning(context: Context, callback: AsyncCallback<void>): void; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise<void>; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback<void>): void; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function requestSuspendDelay(reason: string, callback: Callback<void>): DelaySuspendInfo; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function getRemainingDelayTime(requestId: number): Promise<number>; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function getRemainingDelayTime(requestId: number, callback: AsyncCallback<number>): void; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function cancelSuspendDelay(requestId: number): void; | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | export enum BackgroundMode | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | DATA_TRANSFER = 1 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | AUDIO_PLAYBACK = 2 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | AUDIO_RECORDING = 3 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | LOCATION = 4 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | BLUETOOTH_INTERACTION = 5 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | MULTI_DEVICE_CONNECTION = 6 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | WIFI_INTERACTION = 7 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | VOIP = 8 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.BackgroundMode | enum | TASK_KEEPING = 9 | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.DelaySuspendInfo | interface | interface DelaySuspendInfo | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.DelaySuspendInfo | field | requestId: number | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.DelaySuspendInfo | field | actualDelayTime: number | 接口从API9开始废弃，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | export enum ResourceType | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | CPU = 1 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | COMMON_EVENT = 1 << 1 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | TIMER = 1 << 2 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | WORK_SCHEDULER = 1 << 3 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | BLUETOOTH = 1 << 4 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | GPS = 1 << 5 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | AUDIO = 1 << 6 | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | interface | export interface EfficiencyResourcesRequest | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | reason: string | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isProcess?: bool | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isPersist?: bool | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | timeOut: number | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isApply: bool | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | resourceTypes: number | 接口API9变更，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 


**适配指导**<br>

导入backgroundTaskManager模块。
```
import bundle form '@ohos.resourceschedule.backgroundTaskManager'
```
此外还需要适配异常处理，具体参考[backgroundTaskManager接口文档](../../../application-dev/reference/apis/js-apis-resourceschedule-backgroundTaskManager.md)。

## c2.resourceschedule.usageStatistics 
对资源调度子系统deviceUsageStatistics仓原有接口进行整改，原有API8及之前的接口全部废弃，原有API9接口删除，需要使用新的API9接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更，废弃@ohos.bundleState.d.ts文件，新增@ohos.resourceschedule.usageStatistics.d.ts文件，类名也将从bundleState变更为usageStatistics。

| 类名                                      | 接口类型  | 方法/属性/枚举/常量                                          | 变更类型                                                     |
| ----------------------------------------- | --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| bundleState                               | method    | function isIdleState(bundleName: string, callback: AsyncCallback<boolean>): void; | 废弃，移动到usageStatistics.isIdleState                      |
| bundleState                               | method    | function isIdleState(bundleName: string): Promise<boolean>;  | 废弃，移动到usageStatistics.isIdleState                      |
| bundleState                               | method    | function queryAppUsagePriorityGroup(callback: AsyncCallback<number>): void; | 废弃，修改为function queryAppGroup(callback: AsyncCallback<number>): void; |
| bundleState                               | method    | function queryAppUsagePriorityGroup(): Promise<number>;      | 废弃，修改为function queryAppGroup(): Promise<number>;       |
| bundleState                               | method    | function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback<BundleActiveInfoResponse>): void; | 废弃，修改为function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback<BundleStatsMap>): void; |
| bundleState                               | method    | function queryBundleStateInfos(begin: number, end: number): Promise<BundleActiveInfoResponse>; | 废弃， 修改为function queryBundleStatsInfos(begin: number, end: number): Promise<BundleStatsMap>; |
| bundleState                               | method    | function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStateInfo>>; | 废弃，修改为function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStatsInfo>>; |
| bundleState                               | method    | function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStateInfo>>): void; | 废弃，修改为function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStatsInfo>>): void; |
| bundleState                               | method    | function queryBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>; | 废弃，修改为function queryBundleEvents(begin: number, end: number): Promise<Array<BundleEvents>>; |
| bundleState                               | method    | function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void; | 废弃，修改为function queryBundleEvents(begin: number, end: number, callback: AsyncCallback<Array<BundleEvents>>): void; |
| bundleState                               | method    | function queryCurrentBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>; | 废弃，修改为function queryCurrentBundleEvents(begin: number, end: number): Promise<Array<BundleEvents>>; |
| bundleState                               | method    | function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void; | 废弃，修改为function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback<Array<BundleEvents>>): void; |
| bundleState                               | method    | function getRecentlyUsedModules(maxNum?: number): Promise<Array<BundleActiveModuleInfo>>; | 废弃，修改为两个接口function QueryModuleUsageRecords(maxNum: number): Promise<Array<HapModuleInfo>>; function QueryModuleUsageRecords(): Promise<Array<HapModuleInfo>>; |
| bundleState                               | method    | function getRecentlyUsedModules(maxNum?: number, callback: AsyncCallback<Array<BundleActiveModuleInfo>>): void; | 废弃，修改为两个接口function QueryModuleUsageRecords(maxNum: number, callback: AsyncCallback<Array<HapModuleInfo>>): void; function QueryModuleUsageRecords(callback: AsyncCallback<Array<HapModuleInfo>>): void; |
| bundleState                               | method    | function queryAppUsagePriorityGroup(bundleName? : string): Promise<number>; | 废弃，修改为function queryAppGroup(bundleName: string): Promise<number>; |
| bundleState                               | method    | function queryAppUsagePriorityGroup(bundleName? : string, callback: AsyncCallback<number>): void; | 废弃，修改为function queryAppGroup(bundleName: string, callback: AsyncCallback<number>): void; |
| bundleState                               | method    | function setBundleGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback<void>): void; | 废弃，修改为function setAppGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback<void>): void; |
| bundleState                               | method    | function setBundleGroup(bundleName: string, newGroup: GroupType): Promise<void>; | 废弃，修改为function setAppGroup(bundleName: string, newGroup: GroupType): Promise<void>; |
| bundleState                               | method    | function registerGroupCallBack(callback: Callback<BundleActiveGroupCallbackInfo>, callback: AsyncCallback<void>): void; | 废弃，修改为function registerAppGroupCallBack(callback: Callback<AppGroupCallbackInfo>, callback: AsyncCallback<void>): void; |
| bundleState                               | method    | function registerGroupCallBack(callback: Callback<BundleActiveGroupCallbackInfo>): Promise<void>; | 废弃，修改为function registerAppGroupCallBack(callback: Callback<AppGroupCallbackInfo>): Promise<void>; |
| bundleState                               | method    | function unRegisterGroupCallBack(callback: AsyncCallback<void>): void; | 变更，修改为function unregisterAppGroupCallBack(): Promise<void>; |
| bundleState                               | method    | function unRegisterGroupCallBack(): Promise<void>;           | 变更，修改为function unregisterAppGroupCallBack(): Promise<void>; |
| bundleState                               | method    | function queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveEventState>>): void; | 变更，修改为function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback<Array<DeviceEventStats>>): void; |
| bundleState                               | method    | function queryBundleActiveEventStates(begin: number, end: number): Promise<Array<BundleActiveEventState>>; | 接口从API9变更，修改为function queryDeviceEventStats(begin: number, end: number): Promise<Array<DeviceEventStats>>; |
| bundleState                               | method    | function queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveEventState>>): void; | 接口从API9变更，修改为function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback<Array<NotificationEventStats >>): void; |
| bundleState                               | method    | function queryAppNotificationNumber(begin: number, end: number): Promise<Array<BundleActiveEventState>>; | 接口从API9变更，修改为function queryNotificationEventStats(begin: number, end: number): Promise<Array<NotificationEventStats >>; |
| bundleState.BundleActiveGroupCallbackInfo | interface | interface BundleActiveGroupCallbackInfo                      | 变更，修改为usageStatistics.AppGroupCallbackInfo             |
| bundleState.BundleActiveGroupCallbackInfo | field     | bundleName: string                                           | 变更，移动到usageStatistics.AppGroupCallbackInfo             |
| bundleState.BundleActiveGroupCallbackInfo | field     | changeReason: number                                         | 变更，移动到usageStatistics.AppGroupCallbackInfo             |
| bundleState.BundleActiveGroupCallbackInfo | field     | userId: number                                               | 变更，移动到usageStatistics.AppGroupCallbackInfo             |
| bundleState.BundleActiveGroupCallbackInfo | field     | appUsageNewGroup: number                                     | 废弃，修改为appNewGroup                                      |
| bundleState.BundleActiveGroupCallbackInfo | field     | appUsageOldGroup: number                                     | 废弃，修改为appOldGroup                                      |
| bundleState.BundleActiveEventState        | interface | interface BundleActiveEventState                             | 废弃，修改为usageStatistics.DeviceEventStats                 |
| bundleState.BundleActiveEventState        | field     | count: number                                                | 变更，移动到usageStatistics.DeviceEventStats                 |
| bundleState.BundleActiveEventState        | field     | eventId: number                                              | 变更，移动到usageStatistics.DeviceEventStats                 |
| bundleState.BundleActiveEventState        | field     | name: string                                                 | 变更，移动到usageStatistics.DeviceEventStats                 |
| bundleState.BundleActiveModuleInfo        | interface | interface BundleActiveModuleInfo                             | 接口从API9变更，修改为usageStatistics.HapModuleInfo          |
| bundleState.BundleActiveModuleInfo        | field     | formRecords: Array<BundleActiveFormInfo>                     | 变更，修改为formRecords: Array<HapModuleInfo>                |
| bundleState.BundleActiveModuleInfo        | field     | lastModuleUsedTime: number                                   | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | launchedCount: number                                        | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | abilityIconId?: number                                       | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | abilityDescriptionId?: number                                | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | abilityLableId?: number                                      | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | descriptionId?: number;                                      | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | labelId?: number                                             | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | appLabelId?: number                                          | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | abilityName?: string                                         | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | moduleName: string                                           | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | bundleName: string                                           | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.BundleActiveModuleInfo        | field     | deviceId?: string                                            | 变更，移动到usageStatistics.HapModuleInfo                    |
| bundleState.GroupType                     | enum      | enum GroupType                                               | 变更，移动到usageStatistics.GroupType                        |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_ALIVE                                           | 废弃，修改为ALIVE_GROUP                                      |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_DAILY                                           | 废弃，修改为DAILY_GROUP                                      |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_FIXED                                           | 废弃，修改为FIXED_GROUP                                      |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_RARE                                            | 废弃，修改为RARE_GROUP                                       |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_LIMIT                                           | 废弃，修改为LIMITED_GROUP                                    |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_NEVER                                           | 废弃，修改为NEVER_GROUP                                      |
| bundleState.IntervalType                  | enum      | enum IntervalType                                            | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.IntervalType                  | enum      | BY_OPTIMIZED                                                 | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.IntervalType                  | enum      | BY_DAILY                                                     | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.IntervalType                  | enum      | BY_WEEKLY                                                    | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.IntervalType                  | enum      | BY_MONTHLY                                                   | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.IntervalType                  | enum      | BY_ANNUALLY                                                  | 废弃，移动到usageStatistics.IntervalType                     |
| bundleState.BundleActiveInfoResponse      | interface | interface BundleActiveInfoResponse                           | 废弃，修改为usageStatistics.BundleStatsMap                   |
| bundleState.BundleActiveState             | interface | interface BundleActiveState                                  | 废弃，修改为usageStatistics.BundleEvents                     |
| bundleState.BundleActiveState             | field     | stateType?: number                                           | 废弃，修改为eventId                                          |
| bundleState.BundleActiveState             | field     | stateOccurredTime?: number                                   | 废弃，修改为eventOccurredTime                                |
| bundleState.BundleActiveState             | field     | nameOfClass?: string                                         | 废弃，移动到usageStatistics.BundleEvents                     |
| bundleState.BundleActiveState             | field     | indexOfLink?: string                                         | 废弃，移动到usageStatistics.BundleEvents                     |
| bundleState.BundleActiveState             | field     | bundleName?: string                                          | 废弃，移动到usageStatistics.BundleEvents                     |
| bundleState.BundleActiveState             | field     | appUsagePriorityGroup?: number                               | 废弃，修改为appGroup                                         |
| bundleState.BundleStateInfo               | interface | interface BundleStateInfo                                    | 废弃，修改为usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | method    | merge(toMerge: BundleStateInfo): void                        | 废弃                                                         |
| bundleState.BundleStateInfo               | field     | infosEndTime?: number                                        | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | infosBeginTime?: number                                      | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | fgAbilityPrevAccessTime?: number                             | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | fgAbilityAccessTotalTime?: number                            | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | bundleName?: string                                          | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | abilitySeenTotalTime?: number                                | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | abilityPrevSeenTime?: number                                 | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | abilityPrevAccessTime?: number                               | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | abilityInFgTotalTime?: number                                | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState.BundleStateInfo               | field     | id: number                                                   | 废弃，移动到usageStatistics.BundleStatsInfo                  |
| bundleState                               | namespace | declare namespace bundleState                                | 废弃，修改为usageStatistics，移植到ohos.resourceschedule.usageStatistics.d.ts |


**适配指导**<br>

导入usageStatistics模块。
```
import bundle form '@ohos.resourceschedule.usageStatistics'
```
此外还需要适配异常处理，具体参考[usageStatistics接口文档](../../../application-dev/reference/apis/js-apis-resourceschedule-deviceUsageStatistics.md)。


## c3.resourceschedule.workScheduler 
对资源调度子系统workScheduler仓原有接口进行整改，原有API9接口变更为新的API9接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更。废弃@ohos.workScheduler.d.ts文件，新增@ohos.resourceschedule.workScheduler.d.ts文件，将相关接口变更至对应的文件中。

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
| workScheduler | namespace | declare namespace workScheduler | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | interface | export interface WorkInfo | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | idleWaitTime?: number | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isDeepIdle?: boolean | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | repeatCount?: number | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isRepeat?: boolean | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | repeatCycleTime?: number | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | storageRequest?: StorageRequest | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | batteryStatus?: BatteryStatus | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | batteryLevel?: number | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | chargerType?: ChargingType | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isCharging?: boolean | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | networkType?: NetworkType | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isPersisted?: boolean | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | abilityName: string | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | bundleName: string | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | workId: number | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function isLastWorkTimeOut(workId: number): Promise; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function stopAndClearWorks(): boolean; | 接口API8变更，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function stopAndClearWorks(): boolean; | 
| workScheduler | method | function obtainAllWorks(): Promise<Array<WorkInfo>>; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function getWorkStatus(workId: number): Promise<WorkInfo>; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function stopWork(work: WorkInfo, needCancel?: boolean): boolean; | 接口API8变更，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function stopWork(work: WorkInfo, needCancel?: boolean): void; | 
| workScheduler | method | function startWork(work: WorkInfo): boolean; | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function startWork(work: WorkInfo): void; | 
| workScheduler.NetworkType | enum | export enum NetworkType | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ANY = 0 | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_MOBILE | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_BLUETOOTH | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI_P2P | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ETHERNET | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | export enum ChargingType | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_ANY = 0 | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_AC | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_USB | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_WIRELESS | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | export enum BatteryStatus | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW = 0 | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_OKAY | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW_OR_OKAY | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.StorageRequest | enum | export enum StorageRequest | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW = 0 | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_OKAY | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW_OR_OKAY | 接口API9变更，移植到ohos.resourceschedule.workScheduler.d.ts | 


**适配指导**<br>

导入workScheduler模块。
```
import bundle form '@ohos.resourceschedule.workScheduler'
```
此外还需要适配异常处理，具体参考[workScheduler接口文档](../../../application-dev/reference/apis/js-apis-resourceschedule-workScheduler.md)。


## c4.resourceschedule.reminderAgent
对资源调度子系统提醒代理原有接口进行整改，原有API8及之前的接口全部废弃，原有API9接口删除，需要使用新的API9接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更，废弃@ohos.reminderAgent.d.ts文件，新增@ohos.reminderAgentManager.d.ts文件，类名也将从reminderAgent变更为reminderAgentManager。

| 类名                | 接口类型        | 方法/属性/枚举/常量                                          | 变更类型                                                     |
| --------------------- | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| reminderAgent | method | publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback<number>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | publishReminder(reminderReq: ReminderRequest): Promise<number>;  | 废弃，移动到reminderAgentManager |
| reminderAgent | method | cancelReminder(reminderId: number, callback: AsyncCallback<void>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | cancelReminder(reminderId: number): Promise<void>; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | getValidReminders(callback: AsyncCallback<Array<ReminderRequest>>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | getValidReminders(): Promise<Array<ReminderRequest>>; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | cancelAllReminders(callback: AsyncCallback<void>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | cancelAllReminders(): Promise<void>; |  废弃，移动到reminderAgentManager |
| reminderAgent | method | addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback<void>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | addNotificationSlot(slot: NotificationSlot): Promise<void>; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback<void>): void; | 废弃，移动到reminderAgentManager |
| reminderAgent | method | removeNotificationSlot(slotType: notification.SlotType): Promise<void>; | 废弃，移动到reminderAgentManager |
| reminderAgent.ActionButtonType | enum | ACTION_BUTTON_TYPE_CLOSE | 废弃，移动到reminderAgentManager.ActionButtonType |
| reminderAgent.ActionButtonType | enum | ACTION_BUTTON_TYPE_SNOOZE |  废弃，移动到reminderAgentManager.ActionButtonType |
| reminderAgent.ReminderType | enum | REMINDER_TYPE_TIMER | 废弃，移动到reminderAgentManager.ReminderType |
| reminderAgent.ReminderType | enum | REMINDER_TYPE_CALENDAR | 废弃，移动到reminderAgentManager.ReminderType |
| reminderAgent.ReminderType | enum | REMINDER_TYPE_CALENDAR | 废弃，移动到reminderAgentManager.ReminderType |
| reminderAgent.ActionButton | field | title:string | 废弃，移动到reminderAgentManager.ActionButton |
| reminderAgent.ActionButton | field | type:ActionButtonType | 废弃，移动到reminderAgentManager.ActionButton |
| reminderAgent.WantAgent | field | pkgName:string | 废弃，移动到reminderAgentManager.WantAgent |
| reminderAgent.WantAgent | field | abilityName:string | 废弃，移动到reminderAgentManager.WantAgent |
| reminderAgent.MaxScreenWantAgent | field | pkgName:string | 废弃，移动到reminderAgentManager.MaxScreenWantAgent |
| reminderAgent.MaxScreenWantAgent | field | abilityName:string | 废弃，移动到reminderAgentManager.MaxScreenWantAgent |
| reminderAgent.ReminderRequest | field | reminderType:ReminderType | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | actionButton?:ActionButton | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | wantAgent?:WantAgent | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | maxScreenWantAgent?:MaxScreenWantAgent | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | ringDuration?:number | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | snoozeTimes?:number | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | timeInterval?:number | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | title?:string | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | content?:string | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | expiredContent?:string | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | snoozeContent?:string | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | notificationId?:number | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequest | field | slotType?:	notification.SlotType | 废弃，移动到reminderAgentManager.ReminderRequest |
| reminderAgent.ReminderRequestCalendar | field | dateTime:LocalDateTime | 废弃，移动到reminderAgentManager.ReminderRequestCalendar |
| reminderAgent.ReminderRequestCalendar | field | repeatMonths?:Array<number> | 废弃，移动到reminderAgentManager.ReminderRequestCalendar |
| reminderAgent.ReminderRequestCalendar | field | repeatDays?:Array<number> | 废弃，移动到reminderAgentManager.ReminderRequestCalendar |
| reminderAgent.ReminderRequestAlarm | field | hour:number | 废弃，移动到reminderAgentManager.ReminderRequestAlarm |
| reminderAgent.ReminderRequestAlarm | field | minute:number | 废弃，移动到reminderAgentManager.ReminderRequestAlarm |
| reminderAgent.ReminderRequestAlarm | field | daysOfWeek?:Array<number> | 废弃，移动到reminderAgentManager.ReminderRequestAlarm |
| reminderAgent.ReminderRequestTimer | field | triggerTimeInSeconds:number | 废弃，移动到reminderAgentManager.ReminderRequestTimer |
| reminderAgent.LocalDateTime | field | year:number | 废弃，移动到reminderAgentManager.LocalDateTime |
| reminderAgent.LocalDateTime | field | month:number | 废弃，移动到reminderAgentManager.LocalDateTime |
| reminderAgent.LocalDateTime | field | day:number | 废弃，移动到reminderAgentManager.LocalDateTime |
| reminderAgent.LocalDateTime | field | hour:number | 废弃，移动到reminderAgentManager.LocalDateTime |
| reminderAgent.LocalDateTime | field | minute:number | 废弃，移动到reminderAgentManager.LocalDateTime |
| reminderAgent.LocalDateTime | field | second?:number | 废弃，移动到reminderAgentManager.LocalDateTime |


**适配指导**<br>

导入reminderAgentManager模块。
```
import bundle form '@ohos.reminderAgentManager'
```
此外还需要适配异常处理，具体参考[reminderAgentManager接口文档](../../../application-dev/reference/apis/js-apis-reminderAgentManager.md)。


