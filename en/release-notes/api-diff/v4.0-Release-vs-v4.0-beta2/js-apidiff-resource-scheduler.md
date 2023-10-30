| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: deviceStandby;<br>Method or attribute name: function getExemptedApps(resourceTypes: number, callback: AsyncCallback\<Array\<ExemptedAppInfo>>): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: deviceStandby;<br>Method or attribute name: function getExemptedApps(resourceTypes: number): Promise\<Array\<ExemptedAppInfo>>;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: deviceStandby;<br>Method or attribute name: function requestExemptionResource(request: ResourceRequest): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: deviceStandby;<br>Method or attribute name: function releaseExemptionResource(request: ResourceRequest): void;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: NETWORK = 1|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: RUNNING_LOCK = 1 \<\< 1|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: TIMER = 1 \<\< 2|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: WORK_SCHEDULER = 1 \<\< 3|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: AUTO_SYNC = 1 \<\< 4|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: PUSH = 1 \<\< 5|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceType;<br>Method or attribute name: FREEZE = 1 \<\< 6|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ExemptedAppInfo;<br>Method or attribute name: resourceTypes: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceRequest;<br>Method or attribute name: resourceTypes: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ExemptedAppInfo;<br>Method or attribute name: name: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceRequest;<br>Method or attribute name: name: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ExemptedAppInfo;<br>Method or attribute name: duration: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceRequest;<br>Method or attribute name: duration: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceRequest;<br>Method or attribute name: uid: number;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: ResourceRequest;<br>Method or attribute name: reason: string;|@ohos.resourceschedule.deviceStandby.d.ts|
|Added|NA|Class name: usageStatistics;<br>Method or attribute name: function isIdleStateSync(bundleName: string): boolean;|@ohos.resourceschedule.usageStatistics.d.ts|
|Added|NA|Class name: usageStatistics;<br>Method or attribute name: function queryAppGroupSync(): number;|@ohos.resourceschedule.usageStatistics.d.ts|
|Added|NA|Class name: usageStatistics;<br>Method or attribute name: function queryAppGroupSync(bundleName: string): number;|@ohos.resourceschedule.usageStatistics.d.ts|
|Added|NA|Class name: workScheduler;<br>Method or attribute name: function obtainAllWorks(callback: AsyncCallback\<Array\<WorkInfo>>): void;|@ohos.resourceschedule.workScheduler.d.ts|
|Added|NA|Class name: workScheduler;<br>Method or attribute name: function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<boolean>): void;|@ohos.resourceschedule.workScheduler.d.ts|
|Added|NA|Class name: sourcefile;<br>Method or attribute name: export type WorkSchedulerExtensionContext = _WorkSchedulerExtensionContext;|@ohos.WorkSchedulerExtensionAbility.d.ts|
|Deprecated version changed|Class name: workScheduler;<br>Method or attribute name: function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>Old version information: |Class name: workScheduler;<br>Method or attribute name: function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;<br>New version information: 10<br>Substitute API: |@ohos.resourceschedule.workScheduler.d.ts|
|Deprecated version changed|Class name: workScheduler;<br>Method or attribute name: function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>Old version information: |Class name: workScheduler;<br>Method or attribute name: function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;<br>New version information: 10<br>Substitute API: |@ohos.resourceschedule.workScheduler.d.ts|
