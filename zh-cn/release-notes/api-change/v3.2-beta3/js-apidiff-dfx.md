# DFX子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，DFX子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.hiAppEvent | hiAppEvent            | function clearData(): void;                                                         | 新增 |
| ohos.hiAppEvent | hiAppEvent            | function removeWatcher(watcher: Watcher): void;                                     | 新增 |
| ohos.hiAppEvent | hiAppEvent            | function addWatcher(watcher: Watcher): AppEventPackageHolder;                       | 新增 |
| ohos.hiAppEvent | Watcher               | onTrigger?: (curRow: number, curSize:number, holder:AppEventPackageHolder) => void; | 新增 |
| ohos.hiAppEvent | Watcher               | appEventFilters?: AppEventFilter[];                                                 | 新增 |
| ohos.hiAppEvent | Watcher               | triggerCondition?: TriggerCondition;                                                | 新增 |
| ohos.hiAppEvent | Watcher               | name: string;                                                                       | 新增 |
| ohos.hiAppEvent | AppEventFilter        | eventTypes?: EventType[];                                                           | 新增 |
| ohos.hiAppEvent | AppEventFilter        | domain: string;                                                                     | 新增 |
| ohos.hiAppEvent | TriggerCondition      | timeOut?: number;                                                                   | 新增 |
| ohos.hiAppEvent | TriggerCondition      | size?: number;                                                                      | 新增 |
| ohos.hiAppEvent | TriggerCondition      | row?: number;                                                                       | 新增 |
| ohos.hiAppEvent | AppEventPackageHolder | takeNext(): AppEventPackage;                                                        | 新增 |
| ohos.hiAppEvent | AppEventPackageHolder | setSize(size: number): void;                                                        | 新增 |
| ohos.hiAppEvent | AppEventPackageHolder | constructor(watcherName: string);                                                   | 新增 |
| ohos.hiAppEvent | AppEventPackage       | data: string[];                                                                     | 新增 |
| ohos.hiAppEvent | AppEventPackage       | size: number;                                                                       | 新增 |
| ohos.hiAppEvent | AppEventPackage       | row: number;                                                                        | 新增 |
| ohos.hiAppEvent | AppEventPackage       | packageId: number;                                                                  | 新增 |
| ohos.hiAppEvent | AppEventInfo          | params: object;                                                                     | 新增 |
| ohos.hiAppEvent | AppEventInfo          | eventType: EventType;                                                               | 新增 |
| ohos.hiAppEvent | AppEventInfo          | name: string;                                                                       | 新增 |
| ohos.hiAppEvent | AppEventInfo          | domain: string;                                                                     | 新增 |
| ohos.hiAppEvent | hiAppEvent | function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>function write(info: AppEventInfo): Promise\<void>;<br>function write(info: AppEventInfo, callback: AsyncCallback\<void>): void; | 废弃 |