# JS API Changes of the Resource Scheduler Subsystem

The table below lists the APIs changes of the resource scheduler subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.bundleState | bundleState | queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveEventState>>): void;<br>queryAppNotificationNumber(begin: number, end: number): Promise\<Array\<BundleActiveEventState>>; | Added|
| ohos.bundleState | bundleState | queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveEventState>>): void;<br>queryBundleActiveEventStates(begin: number, end: number): Promise\<Array\<BundleActiveEventState>>; | Added|
| ohos.bundleState | bundleState | unRegisterGroupCallBack(callback: AsyncCallback\<void>): void;<br>unRegisterGroupCallBack(): Promise\<void>; | Added|
| ohos.bundleState | bundleState | registerGroupCallBack(callback: Callback\<BundleActiveGroupCallbackInfo>, callback: AsyncCallback\<void>): void;<br>registerGroupCallBack(callback: Callback\<BundleActiveGroupCallbackInfo>): Promise\<void>; | Added|
| ohos.bundleState | bundleState | setBundleGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback\<void>): void;<br>setBundleGroup(bundleName: string, newGroup: GroupType): Promise\<void>; | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_NEVER = 60 | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_LIMIT = 50 | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_RARE = 40 | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_FIXED = 30 | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_DAILY = 20 | Added|
| ohos.bundleState | GroupType | ACTIVE_GROUP_ALIVE = 10 | Added|
| ohos.bundleState | BundleActiveGroupCallbackInfo | bundleName: string; | Added|
| ohos.bundleState | BundleActiveGroupCallbackInfo | changeReason: number; | Added|
| ohos.bundleState | BundleActiveGroupCallbackInfo | userId: number; | Added|
| ohos.bundleState | BundleActiveGroupCallbackInfo | appUsageNewGroup: number; | Added|
| ohos.bundleState | BundleActiveGroupCallbackInfo | appUsageOldGroup: number; | Added|
| ohos.bundleState | BundleActiveEventState | count: number; | Added|
| ohos.bundleState | BundleActiveEventState | eventId: number; | Added|
| ohos.bundleState | BundleActiveEventState | name: string; | Added|
