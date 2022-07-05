# DistributedSchedule子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，DistributedSchedule子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceConnect", token: number, callback: Callback\<Array\<ContinuationResult>>): void; | 新增 |
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceConnect", token: number): void; | 新增 |
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceDisconnect", token: number, callback: Callback\<Array\<string>>): void; | 新增 |
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceDisconnect", token: number): void; | 新增 |
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void; | 废弃 |
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceConnect", callback?: Callback\<ContinuationResult>): void; | 废弃 |
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceDisconnect", callback: Callback\<string>): void; | 废弃 |
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceDisconnect", callback?: Callback\<string>): void; | 废弃 |