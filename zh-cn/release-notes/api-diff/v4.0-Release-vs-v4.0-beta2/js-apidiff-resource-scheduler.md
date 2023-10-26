| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
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
|新增|NA|类名：sourcefile;<br>方法or属性：export type WorkSchedulerExtensionContext = _WorkSchedulerExtensionContext;|@ohos.WorkSchedulerExtensionAbility.d.ts|
|废弃版本有变化|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>旧版本信息：|类名：workScheduler;<br>方法or属性：function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>新版本信息：10<br>代替接口：|@ohos.resourceschedule.workScheduler.d.ts|
|废弃版本有变化|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>旧版本信息：|类名：workScheduler;<br>方法or属性：function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>新版本信息：10<br>代替接口：|@ohos.resourceschedule.workScheduler.d.ts|
