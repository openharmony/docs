# Resource Scheduler Subsystem ChangeLog

## cl.resourceschedule.backgroundTaskManager
 
Rectified original APIs of **backgroundTaskManager** of the resource scheduler subsystem. All APIs in API version 8 and earlier versions are deprecated, and original APIs in API version 9 are deleted. New APIs in API version 9 need to be used. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt the modules and APIs in API version 9 and their methods for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enumerations, and constants are changed in API version 9 and later versions. The **@ohos.backgroundTaskManager.d.ts** file is deprecated and related APIs are migrated to the newly added **@ohos.resourceschedule.backgroundTaskManager.d.ts** file.

| Class| API Type| Declaration| Description| 
|  -- | -- | -- | -- |
| backgroundTaskManager | namespace | declare namespace backgroundTaskManager | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function resetAllEfficiencyResources(): void; | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function applyEfficiencyResources(request: EfficiencyResourcesRequest): bool; | This API is changed in API version 9 to **function applyEfficiencyResources(request: EfficiencyResourcesRequest): void;** and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function stopBackgroundRunning(context: Context): Promise<void>; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function stopBackgroundRunning(context: Context, callback: AsyncCallback<void>): void; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise<void>; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback<void>): void; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function requestSuspendDelay(reason: string, callback: Callback<void>): DelaySuspendInfo; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function getRemainingDelayTime(requestId: number): Promise<number>; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function getRemainingDelayTime(requestId: number, callback: AsyncCallback<number>): void; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function cancelSuspendDelay(requestId: number): void; | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | export enum BackgroundMode | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | DATA_TRANSFER = 1 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | AUDIO_PLAYBACK = 2 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | AUDIO_RECORDING = 3 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | LOCATION = 4 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | BLUETOOTH_INTERACTION = 5 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | MULTI_DEVICE_CONNECTION = 6 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | WIFI_INTERACTION = 7 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | VOIP = 8 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.BackgroundMode | enum | TASK_KEEPING = 9 | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.DelaySuspendInfo | interface | interface DelaySuspendInfo | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.DelaySuspendInfo | field | requestId: number | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.DelaySuspendInfo | field | actualDelayTime: number | This API is deprecated in API version 9 and later versions and is migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | export enum ResourceType | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | CPU = 1 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | COMMON_EVENT = 1 << 1 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | TIMER = 1 << 2 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | WORK_SCHEDULER = 1 << 3 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | BLUETOOTH = 1 << 4 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | GPS = 1 << 5 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | AUDIO = 1 << 6 | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | interface | export interface EfficiencyResourcesRequest | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | reason: string | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isProcess?: bool | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isPersist?: bool | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | timeOut: number | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isApply: bool | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | resourceTypes: number | This API is changed in API version 9 and migrated to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 


**Adaptation Guide**<br>

Import the **backgroundTaskManager** module.
```
import bundle form '@ohos.resourceschedule.backgroundTaskManager'
```
Exception handling also needs to be adapted. For details, see the [backgroundTaskManager API reference](../../../application-dev/reference/apis/js-apis-resourceschedule-backgroundTaskManager.md).

## c2.resourceschedule.usageStatistics
 
Rectified original APIs of **deviceUsageStatistics** of the resource scheduler subsystem. All APIs in API version 8 and earlier versions are deprecated, and original APIs in API version 9 are deleted. New APIs in API version 9 need to be used. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt the modules and APIs in API version 9 and their methods for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enumerations, and constants are changed in API version 9 and later versions. The **@ohos.bundleState.d.ts** file is deprecated, the **@ohos.resourceschedule.usageStatistics.d.ts** file is added, and the class name is changed from **bundleState** to **usageStatistics**.

| Class                                     | API Type | Method/Attribute/Enumeration/Constant                                         | Change Type                                                    |
| ----------------------------------------- | --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| bundleState                               | method    | function isIdleState(bundleName: string, callback: AsyncCallback<boolean>): void; | Deprecated and migrated to **usageStatistics.isIdleState**                     |
| bundleState                               | method    | function isIdleState(bundleName: string): Promise<boolean>;  | Deprecated and migrated to **usageStatistics.isIdleState**                     |
| bundleState                               | method    | function queryAppUsagePriorityGroup(callback: AsyncCallback<number>): void; | Deprecated and changed to **function queryAppGroup(callback: AsyncCallback<number>): void;**|
| bundleState                               | method    | function queryAppUsagePriorityGroup(): Promise<number>;      | Deprecated and changed to **function queryAppGroup(): Promise<number>;**      |
| bundleState                               | method    | function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback<BundleActiveInfoResponse>): void; | Deprecated and changed to **function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback<BundleStatsMap>): void;**|
| bundleState                               | method    | function queryBundleStateInfos(begin: number, end: number): Promise<BundleActiveInfoResponse>; | Deprecated and changed to **function queryBundleStatsInfos(begin: number, end: number): Promise<BundleStatsMap>;**|
| bundleState                               | method    | function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStateInfo>>; | Deprecated and changed to **function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStatsInfo>>;**|
| bundleState                               | method    | function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStateInfo>>): void; | Deprecated and changed to **function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStatsInfo>>): void;**|
| bundleState                               | method    | function queryBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>; | Deprecated and changed to **function queryBundleEvents(begin: number, end: number): Promise<Array<BundleEvents>>;**|
| bundleState                               | method    | function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void; | Deprecated and changed to **function queryBundleEvents(begin: number, end: number, callback: AsyncCallback<Array<BundleEvents>>): void;**|
| bundleState                               | method    | function queryCurrentBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>; | Deprecated and changed to **function queryCurrentBundleEvents(begin: number, end: number): Promise<Array<BundleEvents>>;**|
| bundleState                               | method    | function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void; | Deprecated and changed to **function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback<Array<BundleEvents>>): void;**|
| bundleState                               | method    | function getRecentlyUsedModules(maxNum?: number): Promise<Array<BundleActiveModuleInfo>>; | Deprecated and changed to the following two APIs: **function QueryModuleUsageRecords(maxNum: number): Promise<Array<HapModuleInfo>>;** and **function QueryModuleUsageRecords(): Promise<Array<HapModuleInfo>>;**|
| bundleState                               | method    | function getRecentlyUsedModules(maxNum?: number, callback: AsyncCallback<Array<BundleActiveModuleInfo>>): void; | Deprecated and changed to the following two APIs: **function QueryModuleUsageRecords(maxNum: number, callback: AsyncCallback<Array<HapModuleInfo>>): void;** and **function QueryModuleUsageRecords(callback: AsyncCallback<Array<HapModuleInfo>>): void;**|
| bundleState                               | method    | function queryAppUsagePriorityGroup(bundleName? : string): Promise<number>; | Deprecated and changed to **function queryAppGroup(bundleName: string): Promise<number>;**|
| bundleState                               | method    | function queryAppUsagePriorityGroup(bundleName? : string, callback: AsyncCallback<number>): void; | Deprecated and changed to **function queryAppGroup(bundleName: string, callback: AsyncCallback<number>): void;**|
| bundleState                               | method    | function setBundleGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback<void>): void; | Deprecated and changed to **function setAppGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback<void>): void;**|
| bundleState                               | method    | function setBundleGroup(bundleName: string, newGroup: GroupType): Promise<void>; | Deprecated and changed to **function setAppGroup(bundleName: string, newGroup: GroupType): Promise<void>;**|
| bundleState                               | method    | function registerGroupCallBack(callback: Callback<BundleActiveGroupCallbackInfo>, callback: AsyncCallback<void>): void; | Deprecated and changed to **function registerAppGroupCallBack(callback: Callback<AppGroupCallbackInfo>, callback: AsyncCallback<void>): void;**|
| bundleState                               | method    | function registerGroupCallBack(callback: Callback<BundleActiveGroupCallbackInfo>): Promise<void>; | Deprecated and changed to **function registerAppGroupCallBack(callback: Callback<AppGroupCallbackInfo>): Promise<void>;**|
| bundleState                               | method    | function unRegisterGroupCallBack(callback: AsyncCallback<void>): void; | Deprecated and changed to **function unregisterAppGroupCallBack(): Promise<void>;**|
| bundleState                               | method    | function unRegisterGroupCallBack(): Promise<void>;           | Deprecated and changed to **function unregisterAppGroupCallBack(): Promise<void>;**|
| bundleState                               | method    | function queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveEventState>>): void; | Changed to **function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback<Array<DeviceEventStats>>): void;**|
| bundleState                               | method    | function queryBundleActiveEventStates(begin: number, end: number): Promise<Array<BundleActiveEventState>>; | Changed in API version 9 and later versions to **function queryDeviceEventStats(begin: number, end: number): Promise<Array<DeviceEventStats>>;**|
| bundleState                               | method    | function queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveEventState>>): void; | Changed in API version 9 and later versions to **function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback<Array<NotificationEventStats >>): void;**|
| bundleState                               | method    | function queryAppNotificationNumber(begin: number, end: number): Promise<Array<BundleActiveEventState>>; | Changed in API version 9 and later versions to **function queryNotificationEventStats(begin: number, end: number): Promise<Array<NotificationEventStats >>;**|
| bundleState.BundleActiveGroupCallbackInfo | interface | interface BundleActiveGroupCallbackInfo                      | Changed to **usageStatistics.AppGroupCallbackInfo**            |
| bundleState.BundleActiveGroupCallbackInfo | field     | bundleName: string                                           | Changed and migrated to **usageStatistics.AppGroupCallbackInfo**            |
| bundleState.BundleActiveGroupCallbackInfo | field     | changeReason: number                                         | Changed and migrated to **usageStatistics.AppGroupCallbackInfo**            |
| bundleState.BundleActiveGroupCallbackInfo | field     | userId: number                                               | Changed and migrated to **usageStatistics.AppGroupCallbackInfo**            |
| bundleState.BundleActiveGroupCallbackInfo | field     | appUsageNewGroup: number                                     | Deprecated and changed to **appNewGroup**                                     |
| bundleState.BundleActiveGroupCallbackInfo | field     | appUsageOldGroup: number                                     | Deprecated and changed to **appOldGroup**                                     |
| bundleState.BundleActiveEventState        | interface | interface BundleActiveEventState                             | Deprecated and changed to **usageStatistics.DeviceEventStats**                |
| bundleState.BundleActiveEventState        | field     | count: number                                                | Changed and migrated to **usageStatistics.DeviceEventStats**                |
| bundleState.BundleActiveEventState        | field     | eventId: number                                              | Changed and migrated to **usageStatistics.DeviceEventStats**                |
| bundleState.BundleActiveEventState        | field     | name: string                                                 | Changed and migrated to **usageStatistics.DeviceEventStats**                |
| bundleState.BundleActiveModuleInfo        | interface | interface BundleActiveModuleInfo                             | Changed in API version 9 and later versions to **usageStatistics.HapModuleInfo**         |
| bundleState.BundleActiveModuleInfo        | field     | formRecords: Array<BundleActiveFormInfo>                     | Changed to **formRecords: Array<HapModuleInfo>**               |
| bundleState.BundleActiveModuleInfo        | field     | lastModuleUsedTime: number                                   | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | launchedCount: number                                        | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | abilityIconId?: number                                       | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | abilityDescriptionId?: number                                | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | abilityLableId?: number                                      | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | descriptionId?: number;                                      | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | labelId?: number                                             | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | appLabelId?: number                                          | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | abilityName?: string                                         | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | moduleName: string                                           | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | bundleName: string                                           | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.BundleActiveModuleInfo        | field     | deviceId?: string                                            | Changed and migrated to **usageStatistics.HapModuleInfo**                   |
| bundleState.GroupType                     | enum      | enum GroupType                                               | Changed and migrated to **usageStatistics.GroupType**                       |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_ALIVE                                           | Deprecated and changed to **ALIVE_GROUP**                                     |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_DAILY                                           | Deprecated and changed to **DAILY_GROUP**                                     |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_FIXED                                           | Deprecated and changed to **FIXED_GROUP**                                     |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_RARE                                            | Deprecated and changed to **RARE_GROUP**                                      |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_LIMIT                                           | Deprecated and changed to **LIMITED_GROUP**                                   |
| bundleState.GroupType                     | enum      | ACTIVE_GROUP_NEVER                                           | Deprecated and changed to **NEVER_GROUP**                                     |
| bundleState.IntervalType                  | enum      | enum IntervalType                                            | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.IntervalType                  | enum      | BY_OPTIMIZED                                                 | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.IntervalType                  | enum      | BY_DAILY                                                     | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.IntervalType                  | enum      | BY_WEEKLY                                                    | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.IntervalType                  | enum      | BY_MONTHLY                                                   | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.IntervalType                  | enum      | BY_ANNUALLY                                                  | Deprecated and migrated to **usageStatistics.IntervalType**                    |
| bundleState.BundleActiveInfoResponse      | interface | interface BundleActiveInfoResponse                           | Deprecated and changed to **usageStatistics.BundleStatsMap**                  |
| bundleState.BundleActiveState             | interface | interface BundleActiveState                                  | Deprecated and changed to **usageStatistics.BundleEvents**                    |
| bundleState.BundleActiveState             | field     | stateType?: number                                           | Deprecated and changed to **eventId**                                         |
| bundleState.BundleActiveState             | field     | stateOccurredTime?: number                                   | Deprecated and changed to **eventOccurredTime**                               |
| bundleState.BundleActiveState             | field     | nameOfClass?: string                                         | Deprecated and migrated to **usageStatistics.BundleEvents**                    |
| bundleState.BundleActiveState             | field     | indexOfLink?: string                                         | Deprecated and migrated to **usageStatistics.BundleEvents**                    |
| bundleState.BundleActiveState             | field     | bundleName?: string                                          | Deprecated and migrated to **usageStatistics.BundleEvents**                    |
| bundleState.BundleActiveState             | field     | appUsagePriorityGroup?: number                               | Deprecated and changed to **appGroup**                                        |
| bundleState.BundleStateInfo               | interface | interface BundleStateInfo                                    | Deprecated and changed to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | method    | merge(toMerge: BundleStateInfo): void                        | Deprecated                                                        |
| bundleState.BundleStateInfo               | field     | infosEndTime?: number                                        | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | infosBeginTime?: number                                      | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | fgAbilityPrevAccessTime?: number                             | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | fgAbilityAccessTotalTime?: number                            | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | bundleName?: string                                          | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | abilitySeenTotalTime?: number                                | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | abilityPrevSeenTime?: number                                 | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | abilityPrevAccessTime?: number                               | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | abilityInFgTotalTime?: number                                | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState.BundleStateInfo               | field     | id: number                                                   | Deprecated and migrated to **usageStatistics.BundleStatsInfo**                 |
| bundleState                               | namespace | declare namespace bundleState                                | Deprecated and changed to **usageStatistics**, and migrated to **ohos.resourceschedule.usageStatistics.d.ts**|


**Adaptation Guide**<br>

Import the **usageStatistics** module.
```
import bundle form '@ohos.resourceschedule.usageStatistics'
```
Exception handling also needs to be adapted. For details, see the [usageStatistics API reference](../../../application-dev/reference/apis/js-apis-resourceschedule-deviceUsageStatistics.md).


## c3.resourceschedule.workScheduler
 
Rectified original APIs of **workScheduler** of the resource scheduler subsystem. The original APIs in API version 9 are changed to new APIs in API version 9. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt the modules and APIs in API version 9 and their methods for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enumerations, and constants are changed in API version 9 and later versions. The **@ohos.workScheduler.d.ts** file is deprecated and related APIs are migrated to the newly added **@ohos.resourceschedule.workScheduler.d.ts** file.

| Class| API Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
| workScheduler | namespace | declare namespace workScheduler | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | interface | export interface WorkInfo | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | idleWaitTime?: number | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | isDeepIdle?: boolean | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | repeatCount?: number | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | isRepeat?: boolean | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | repeatCycleTime?: number | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | storageRequest?: StorageRequest | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | batteryStatus?: BatteryStatus | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | batteryLevel?: number | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | chargerType?: ChargingType | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | isCharging?: boolean | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | networkType?: NetworkType | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | isPersisted?: boolean | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | abilityName: string | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | bundleName: string | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.WorkInfo | field | workId: number | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function isLastWorkTimeOut(workId: number): Promise; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function stopAndClearWorks(): boolean; | Changed in API version 8 to **function stopAndClearWorks(): boolean;** and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function obtainAllWorks(): Promise<Array<WorkInfo>>; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function getWorkStatus(workId: number): Promise<WorkInfo>; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void; | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function stopWork(work: WorkInfo, needCancel?: boolean): boolean; | Changed in API version 8 to **function stopWork(work: WorkInfo, needCancel?: boolean): void;** and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function startWork(work: WorkInfo): boolean; | Changed in API version 9 to **function startWork(work: WorkInfo): void;** and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | export enum NetworkType | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ANY = 0 | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_MOBILE | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_BLUETOOTH | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI_P2P | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ETHERNET | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.ChargingType | enum | export enum ChargingType | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_ANY = 0 | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_AC | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_USB | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_WIRELESS | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | export enum BatteryStatus | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW = 0 | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_OKAY | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW_OR_OKAY | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.StorageRequest | enum | export enum StorageRequest | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW = 0 | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_OKAY | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW_OR_OKAY | Changed in API version 9 and migrated to the **ohos.resourceschedule.workScheduler.d.ts** file| 


**Adaptation Guide**<br>

Import the **workScheduler** module.
```
import bundle form '@ohos.resourceschedule.workScheduler'
```
Exception handling also needs to be adapted. For details, see the [workScheduler API reference](../../../application-dev/reference/apis/js-apis-resourceschedule-workScheduler.md).


## c4.resourceschedule.reminderAgent

Rectified original APIs of **reminderAgent** of the resource scheduler subsystem. All APIs in API version 8 and earlier versions are deprecated, and original APIs in API version 9 are deleted. New APIs in API version 9 need to be used. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt the modules and APIs in API version 9 and their methods for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enumerations, and constants are changed in API version 9 and later versions. The **@ohos.reminderAgent.d.ts** file is deprecated, the **@ohos.reminderAgentManager.d.ts** file is added, and the class name is changed from **reminderAgent** to **reminderAgentManager**.

| Class               | API Type       | Method/Attribute/Enumeration/Constant                                         | Change Type                                                    |
| --------------------- | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| reminderAgent | method | publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback<number>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | publishReminder(reminderReq: ReminderRequest): Promise<number>;  | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | cancelReminder(reminderId: number, callback: AsyncCallback<void>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | cancelReminder(reminderId: number): Promise<void>; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | getValidReminders(callback: AsyncCallback<Array<ReminderRequest>>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | getValidReminders(): Promise<Array<ReminderRequest>>; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | cancelAllReminders(callback: AsyncCallback<void>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | cancelAllReminders(): Promise<void>; |  Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback<void>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | addNotificationSlot(slot: NotificationSlot): Promise<void>; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback<void>): void; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent | method | removeNotificationSlot(slotType: notification.SlotType): Promise<void>; | Deprecated and migrated to **reminderAgentManager**|
| reminderAgent.ActionButtonType | enum | ACTION_BUTTON_TYPE_CLOSE | Deprecated and migrated to **reminderAgentManager.ActionButtonType**|
| reminderAgent.ActionButtonType | enum | ACTION_BUTTON_TYPE_SNOOZE |  Deprecated and migrated to **reminderAgentManager.ActionButtonType**|
| reminderAgent.ReminderType | enum | REMINDER_TYPE_TIMER | Deprecated and migrated to **reminderAgentManager.ReminderType**|
| reminderAgent.ReminderType | enum | REMINDER_TYPE_CALENDAR | Deprecated and migrated to **reminderAgentManager.ReminderType**|
| reminderAgent.ReminderType | enum | REMINDER_TYPE_CALENDAR | Deprecated and migrated to **reminderAgentManager.ReminderType**|
| reminderAgent.ActionButton | field | title:string | Deprecated and migrated to **reminderAgentManager.ActionButton**|
| reminderAgent.ActionButton | field | type:ActionButtonType | Deprecated and migrated to **reminderAgentManager.ActionButton**|
| reminderAgent.WantAgent | field | pkgName:string | Deprecated and migrated to **reminderAgentManager.WantAgent**|
| reminderAgent.WantAgent | field | abilityName:string | Deprecated and migrated to **reminderAgentManager.WantAgent**|
| reminderAgent.MaxScreenWantAgent | field | pkgName:string | Deprecated and migrated to **reminderAgentManager.MaxScreenWantAgent**|
| reminderAgent.MaxScreenWantAgent | field | abilityName:string | Deprecated and migrated to **reminderAgentManager.MaxScreenWantAgent**|
| reminderAgent.ReminderRequest | field | reminderType:ReminderType | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | actionButton?:ActionButton | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | wantAgent?:WantAgent | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | maxScreenWantAgent?:MaxScreenWantAgent | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | ringDuration?:number | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | snoozeTimes?:number | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | timeInterval?:number | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | title?:string | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | content?:string | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | expiredContent?:string | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | snoozeContent?:string | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | notificationId?:number | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequest | field | slotType?:	notification.SlotType | Deprecated and migrated to **reminderAgentManager.ReminderRequest**|
| reminderAgent.ReminderRequestCalendar | field | dateTime:LocalDateTime | Deprecated and migrated to **reminderAgentManager.ReminderRequestCalendar**|
| reminderAgent.ReminderRequestCalendar | field | repeatMonths?:Array<number> | Deprecated and migrated to **reminderAgentManager.ReminderRequestCalendar**|
| reminderAgent.ReminderRequestCalendar | field | repeatDays?:Array<number> | Deprecated and migrated to **reminderAgentManager.ReminderRequestCalendar**|
| reminderAgent.ReminderRequestAlarm | field | hour:number | Deprecated and migrated to **reminderAgentManager.ReminderRequestAlarm**|
| reminderAgent.ReminderRequestAlarm | field | minute:number | Deprecated and migrated to **reminderAgentManager.ReminderRequestAlarm**|
| reminderAgent.ReminderRequestAlarm | field | daysOfWeek?:Array<number> | Deprecated and migrated to **reminderAgentManager.ReminderRequestAlarm**|
| reminderAgent.ReminderRequestTimer | field | triggerTimeInSeconds:number | Deprecated and migrated to **reminderAgentManager.ReminderRequestTimer**|
| reminderAgent.LocalDateTime | field | year:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|
| reminderAgent.LocalDateTime | field | month:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|
| reminderAgent.LocalDateTime | field | day:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|
| reminderAgent.LocalDateTime | field | hour:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|
| reminderAgent.LocalDateTime | field | minute:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|
| reminderAgent.LocalDateTime | field | second?:number | Deprecated and migrated to **reminderAgentManager.LocalDateTime**|


**Adaptation Guide**<br>

Import the **reminderAgentManager** module.
```
import bundle form '@ohos.reminderAgentManager'
```
Exception handling also needs to be adapted. For details, see the [reminderAgentManager API reference](../../../application-dev/reference/apis/js-apis-reminderAgentManager.md).
