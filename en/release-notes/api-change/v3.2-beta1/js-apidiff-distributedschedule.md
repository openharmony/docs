# JS API Changes of the Distributed Scheduler Subsystem

The table below lists the APIs changes of the distributed scheduler subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceConnect", token: number, callback: Callback\<Array\<ContinuationResult>>): void; | Added|
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceConnect", token: number): void; | Added|
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceDisconnect", token: number, callback: Callback\<Array\<string>>): void; | Added|
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceDisconnect", token: number): void; | Added|
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void; | Deprecated|
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceConnect", callback?: Callback\<ContinuationResult>): void; | Deprecated|
| ohos.continuation.continuationManager | continuationManager | on(type: "deviceDisconnect", callback: Callback\<string>): void; | Deprecated|
| ohos.continuation.continuationManager | continuationManager | off(type: "deviceDisconnect", callback?: Callback\<string>): void; | Deprecated|
