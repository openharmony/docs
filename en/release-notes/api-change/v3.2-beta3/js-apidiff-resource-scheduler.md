# JS API Changes of the Resource Scheduler Subsystem

The table below lists the APIs changes of the resource scheduler subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | reason: string;                                                                  | Added|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | isProcess?: boolean;                                                             | Added|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | isPersist?: boolean;                                                             | Added|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | timeOut: number;                                                                 | Added|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | isApply: boolean;                                                                | Added|
| ohos.backgroundTaskManager | EfficiencyResourcesRequest | resourceTypes: number;                                                           | Added|
| ohos.backgroundTaskManager | ResourceType               | AUDIO = 1 << 6                                                                   | Added|
| ohos.backgroundTaskManager | ResourceType               | GPS = 1 << 5                                                                     | Added|
| ohos.backgroundTaskManager | ResourceType               | BLUETOOTH = 1 << 4                                                               | Added|
| ohos.backgroundTaskManager | ResourceType               | WORK_SCHEDULER = 1 << 3                                                          | Added|
| ohos.backgroundTaskManager | ResourceType               | TIMER = 1 << 2                                                                   | Added|
| ohos.backgroundTaskManager | ResourceType               | COMMON_EVENT = 1 << 1                                                            | Added|
| ohos.backgroundTaskManager | ResourceType               | CPU = 1                                                                          | Added|
| ohos.backgroundTaskManager | backgroundTaskManager      | resetAllEfficiencyResources(): void;                                    | Added|
| ohos.backgroundTaskManager | backgroundTaskManager      | applyEfficiencyResources(request: EfficiencyResourcesRequest): boolean; | Added|
| ohos.workScheduler         | WorkInfo                   | parameters?: {[key: string]: any};                                               | Added|
