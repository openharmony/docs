# 资源调度子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，资源调度子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.bundleState | bundleState | queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveEventState>>): void;<br>queryAppNotificationNumber(begin: number, end: number): Promise\<Array\<BundleActiveEventState>>; | 新增 |
| ohos.bundleState | bundleState | queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveEventState>>): void;<br>queryBundleActiveEventStates(begin: number, end: number): Promise\<Array\<BundleActiveEventState>>; | 新增 |
| ohos.bundleState | bundleState | unRegisterGroupCallBack(callback: AsyncCallback\<void>): void;<br>unRegisterGroupCallBack(): Promise\<void>; | 新增 |
| ohos.bundleState | bundleState | registerGroupCallBack(callback: Callback\<BundleActiveGroupCallbackInfo>, callback: AsyncCallback\<void>): void;<br>registerGroupCallBack(callback: Callback\<BundleActiveGroupCallbackInfo>): Promise\<void>; | 新增 |
| ohos.bundleState | bundleState | setBundleGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback\<void>): void;<br>setBundleGroup(bundleName: string, newGroup: GroupType): Promise\<void>; | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_NEVER = 60 | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_LIMIT = 50 | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_RARE = 40 | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_FIXED = 30 | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_DAILY = 20 | 新增 |
| ohos.bundleState | GroupType | ACTIVE_GROUP_ALIVE = 10 | 新增 |
| ohos.bundleState | BundleActiveGroupCallbackInfo | bundleName: string; | 新增 |
| ohos.bundleState | BundleActiveGroupCallbackInfo | changeReason: number; | 新增 |
| ohos.bundleState | BundleActiveGroupCallbackInfo | userId: number; | 新增 |
| ohos.bundleState | BundleActiveGroupCallbackInfo | appUsageNewGroup: number; | 新增 |
| ohos.bundleState | BundleActiveGroupCallbackInfo | appUsageOldGroup: number; | 新增 |
| ohos.bundleState | BundleActiveEventState | count: number; | 新增 |
| ohos.bundleState | BundleActiveEventState | eventId: number; | 新增 |
| ohos.bundleState | BundleActiveEventState | name: string; | 新增 |


