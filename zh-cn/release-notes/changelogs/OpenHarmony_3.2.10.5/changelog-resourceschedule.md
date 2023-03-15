# 资源调度子系统ChangeLog

## cl.resourceschedule.backgroundTaskManager 
对资源调度子系统backgroundTaskManager仓原有接口进行整改，原有@ohos.backgroundTaskManager.d.ts中的API9接口删除，需要使用@ohos.resourceschedule.backgroundTaskManager.d.ts中的API9新接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.10.5及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更。@ohos.backgroundTaskManager.d.ts文件中的接口移植到@ohos.resourceschedule.backgroundTaskManager.d.ts文件。

| 类名 | 接口类型 | 接口声明 | 说明 | 
|  -- | -- | -- | -- |
| backgroundTaskManager | method | function resetAllEfficiencyResources(): void; | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager | method | function applyEfficiencyResources(request: EfficiencyResourcesRequest): bool; | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts，修改为function applyEfficiencyResources(request: EfficiencyResourcesRequest): void; | 
| backgroundTaskManager.ResourceType | enum | export enum ResourceType | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | CPU = 1 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | COMMON_EVENT = 1 << 1 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | TIMER = 1 << 2 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | WORK_SCHEDULER = 1 << 3 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | BLUETOOTH = 1 << 4 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | GPS = 1 << 5 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.ResourceType | enum | AUDIO = 1 << 6 | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | interface | export interface EfficiencyResourcesRequest | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | reason: string | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isProcess?: bool | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isPersist?: bool | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | timeOut: number | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | isApply: bool | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 
| backgroundTaskManager.EfficiencyResourcesRequest | field | resourceTypes: number | 接口API9删除，移植到ohos.resourceschedule.backgroundTaskManager.d.ts | 


**适配指导**<br>

导入backgroundTaskManager模块。
```
import bundle form '@ohos.resourceschedule.backgroundTaskManager'
```
此外还需要适配异常处理，具体参考[backgroundTaskManager接口文档](../../../application-dev/reference/apis/js-apis-resourceschedule-backgroundTaskManager.md)。

## c2.resourceschedule.workScheduler 
对资源调度子系统workScheduler仓原有接口进行整改，原有@ohos.workScheduler.d.ts中的API9接口删除，需要使用@ohos.resourceschedule.workScheduler.d.ts中的API9新接口。新的API9接口符合错误码规范。

**变更影响**

基于OpenHarmony3.2.10.5及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下方法、属性、枚举和常量均从API9变更。删除@ohos.workScheduler.d.ts文件，相关接口变更至@ohos.resourceschedule.workScheduler.d.ts文件中。

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
| workScheduler | namespace | declare namespace workScheduler | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | interface | export interface WorkInfo | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | idleWaitTime?: number | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isDeepIdle?: boolean | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | repeatCount?: number | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isRepeat?: boolean | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | repeatCycleTime?: number | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | storageRequest?: StorageRequest | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | batteryStatus?: BatteryStatus | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | batteryLevel?: number | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | chargerType?: ChargingType | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isCharging?: boolean | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | networkType?: NetworkType | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | isPersisted?: boolean | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | abilityName: string | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | bundleName: string | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.WorkInfo | field | workId: number | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function isLastWorkTimeOut(workId: number): Promise; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function stopAndClearWorks(): boolean; | 接口API8变更，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function stopAndClearWorks(): boolean; | 
| workScheduler | method | function obtainAllWorks(): Promise<Array<WorkInfo>>; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function getWorkStatus(workId: number): Promise<WorkInfo>; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler | method | function stopWork(work: WorkInfo, needCancel?: boolean): boolean; | 接口API8变更，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function stopWork(work: WorkInfo, needCancel?: boolean): void; | 
| workScheduler | method | function startWork(work: WorkInfo): boolean; | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts，修改为function startWork(work: WorkInfo): void; | 
| workScheduler.NetworkType | enum | export enum NetworkType | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ANY = 0 | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_MOBILE | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_BLUETOOTH | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_WIFI_P2P | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.NetworkType | enum | NETWORK_TYPE_ETHERNET | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | export enum ChargingType | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_ANY = 0 | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_AC | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_USB | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.ChargingType | enum | CHARGING_PLUGGED_WIRELESS | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | export enum BatteryStatus | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW = 0 | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_OKAY | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | BATTERY_STATUS_LOW_OR_OKAY | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.StorageRequest | enum | export enum StorageRequest | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW = 0 | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_OKAY | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 
| workScheduler.BatteryStatus | enum | STORAGE_LEVEL_LOW_OR_OKAY | 接口API9删除，移植到ohos.resourceschedule.workScheduler.d.ts | 


**适配指导**<br>

导入workScheduler模块。
```
import bundle form '@ohos.resourceschedule.workScheduler'
```
此外还需要适配异常处理，具体参考[workScheduler接口文档](../../../application-dev/reference/apis/js-apis-resourceschedule-workScheduler.md)。
