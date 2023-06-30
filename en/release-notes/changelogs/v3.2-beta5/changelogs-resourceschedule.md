# Resource Scheduler Subsystem Changelog

## cl.resourceschedule.backgroundTaskManager 
Rectified the original APIs of **backgroundTaskManager** of the resource scheduler subsystem. All APIs of API version 9 in the **@ohos.backgroundTaskManager.d.ts** file are deleted, and the APIs of API version 9 in the **@ohos.resourceschedule.backgroundTaskManager.d.ts** file are used. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

If your application is developed based on the SDK versions of OpenHarmony 3.2.10.5 and later, adapt to the modules and APIs in API version 9 and the pattern for returning error codes. Otherwise, the service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enums, and constants are changed in API version 9 and later versions. All the APIs in the **@ohos.backgroundTaskManager.d.ts** file are migrated to the **@ohos.resourceschedule.backgroundTaskManager.d.ts** file.

| Class| API Type| Declaration| Description| 
|  -- | -- | -- | -- |
| backgroundTaskManager | method | function resetAllEfficiencyResources(): void; | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager | method | function applyEfficiencyResources(request: EfficiencyResourcesRequest): bool; | Changed in API version 9 to **function applyEfficiencyResources(request: EfficiencyResourcesRequest): void;** and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | export enum ResourceType | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | CPU = 1 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | COMMON_EVENT = 1 << 1 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | TIMER = 1 << 2 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | WORK_SCHEDULER = 1 << 3 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | BLUETOOTH = 1 << 4 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | GPS = 1 << 5 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.ResourceType | enum | AUDIO = 1 << 6 | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | interface | export interface EfficiencyResourcesRequest | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | reason: string | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isProcess?: bool | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isPersist?: bool | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | timeOut: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isApply: bool | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 
| backgroundTaskManager.EfficiencyResourcesRequest | field | resourceTypes: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.backgroundTaskManager.d.ts** file.| 


**Adaptation Guide**

Import the **backgroundTaskManager** module.
```
import bundle form '@ohos.resourceschedule.backgroundTaskManager'
```
Exception handling also needs to be adapted. For details, see the [backgroundTaskManager API reference](../../../application-dev/reference/apis/js-apis-resourceschedule-backgroundTaskManager.md).

## c2.resourceschedule.workScheduler 
Rectified the original APIs of **workScheduler** of the resource scheduler subsystem. All APIs of API version 9 in the **@ohos.workScheduler.d.ts** file are deleted, and the APIs of API version 9 in the **@ohos.resourceschedule.workScheduler.d.ts** file are used. The new APIs in API version 9 comply with the error code specifications.

**Change Impacts**

If your application is developed based on the SDK versions of OpenHarmony 3.2.10.5 and later, adapt to the modules and APIs in API version 9 and the pattern for returning error codes. Otherwise, the service logic will be affected.

**Key API/Component Changes**

The following methods, attributes, enums, and constants are changed in API version 9 and later versions. The **@ohos.workScheduler.d.ts** file is deleted, and all the APIs in it are moved to the **@ohos.resourceschedule.workScheduler.d.ts** file.

| Class| API Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
| workScheduler | namespace | declare namespace workScheduler | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | interface | export interface WorkInfo | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | idleWaitTime?: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | isDeepIdle?: boolean | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | repeatCount?: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | isRepeat?: boolean | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | repeatCycleTime?: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | storageRequest?: StorageRequest | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | batteryStatus?: BatteryStatus | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | batteryLevel?: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | chargerType?: ChargingType | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | isCharging?: boolean | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | networkType?: NetworkType | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | isPersisted?: boolean | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | abilityName: string | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | bundleName: string | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.WorkInfo | field | workId: number | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function isLastWorkTimeOut(workId: number): Promise; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function stopAndClearWorks(): boolean; | Changed in API version 8 to **function stopAndClearWorks(): boolean;** and moved to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler | method | function obtainAllWorks(): Promise<Array<WorkInfo>>; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function getWorkStatus(workId: number): Promise<WorkInfo>; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void; | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function stopWork(work: WorkInfo, needCancel?: boolean): boolean; | Changed in API version 8 to **function stopWork(work: WorkInfo, needCancel?: boolean): void;** and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler | method | function startWork(work: WorkInfo): boolean; | Changed in API version 9 to **function startWork(work: WorkInfo): void;** and moved to the **ohos.resourceschedule.workScheduler.d.ts** file| 
| workScheduler.NetworkType | enum | export enum NetworkType | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ANY = 0 | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_MOBILE | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_BLUETOOTH | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI_P2P | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ETHERNET | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.ChargingType | enum | export enum ChargingType | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_ANY = 0 | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_AC | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_USB | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_WIRELESS | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | export enum BatteryStatus | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW = 0 | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_OKAY | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW_OR_OKAY | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.StorageRequest | enum | export enum StorageRequest | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW = 0 | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_OKAY | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW_OR_OKAY | Deleted in API version 9 and moved to the **ohos.resourceschedule.workScheduler.d.ts** file.| 


**Adaptation Guide**

Import the **workScheduler** module.
```
import bundle form '@ohos.resourceschedule.workScheduler'
```
Exception handling also needs to be adapted. For details, see the [workScheduler API reference](../../../application-dev/reference/apis/js-apis-resourceschedule-workScheduler.md).
