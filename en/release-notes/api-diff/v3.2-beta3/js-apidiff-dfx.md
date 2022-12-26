# JS API Changes of the DFX Subsystem

The table below lists the APIs changes of the DFX subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.hiAppEvent | hiAppEvent            | function clearData(): void;                                                         | Added|
| ohos.hiAppEvent | hiAppEvent            | function removeWatcher(watcher: Watcher): void;                                     | Added|
| ohos.hiAppEvent | hiAppEvent            | function addWatcher(watcher: Watcher): AppEventPackageHolder;                       | Added|
| ohos.hiAppEvent | Watcher               | onTrigger?: (curRow: number, curSize:number, holder:AppEventPackageHolder) => void; | Added|
| ohos.hiAppEvent | Watcher               | appEventFilters?: AppEventFilter[];                                                 | Added|
| ohos.hiAppEvent | Watcher               | triggerCondition?: TriggerCondition;                                                | Added|
| ohos.hiAppEvent | Watcher               | name: string;                                                                       | Added|
| ohos.hiAppEvent | AppEventFilter        | eventTypes?: EventType[];                                                           | Added|
| ohos.hiAppEvent | AppEventFilter        | domain: string;                                                                     | Added|
| ohos.hiAppEvent | TriggerCondition      | timeOut?: number;                                                                   | Added|
| ohos.hiAppEvent | TriggerCondition      | size?: number;                                                                      | Added|
| ohos.hiAppEvent | TriggerCondition      | row?: number;                                                                       | Added|
| ohos.hiAppEvent | AppEventPackageHolder | takeNext(): AppEventPackage;                                                        | Added|
| ohos.hiAppEvent | AppEventPackageHolder | setSize(size: number): void;                                                        | Added|
| ohos.hiAppEvent | AppEventPackageHolder | constructor(watcherName: string);                                                   | Added|
| ohos.hiAppEvent | AppEventPackage       | data: string[];                                                                     | Added|
| ohos.hiAppEvent | AppEventPackage       | size: number;                                                                       | Added|
| ohos.hiAppEvent | AppEventPackage       | row: number;                                                                        | Added|
| ohos.hiAppEvent | AppEventPackage       | packageId: number;                                                                  | Added|
| ohos.hiAppEvent | AppEventInfo          | params: object;                                                                     | Added|
| ohos.hiAppEvent | AppEventInfo          | eventType: EventType;                                                               | Added|
| ohos.hiAppEvent | AppEventInfo          | name: string;                                                                       | Added|
| ohos.hiAppEvent | AppEventInfo          | domain: string;                                                                     | Added|
| ohos.hiAppEvent | hiAppEvent | function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>function write(info: AppEventInfo): Promise\<void>;<br>function write(info: AppEventInfo, callback: AsyncCallback\<void>): void; | Deprecated|
