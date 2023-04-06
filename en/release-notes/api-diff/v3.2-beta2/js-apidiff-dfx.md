# JS API Changes of the DFX Subsystem

The table below lists the APIs changes of the DFX subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.hiSysEvent | hiSysEvent | query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): number; | Added|
| ohos.hiSysEvent | hiSysEvent | removeWatcher(wathcer: Watcher): number; | Added|
| ohos.hiSysEvent | hiSysEvent | addWatcher(watcher: Watcher): number; | Added|
| ohos.hiSysEvent | Querier | onComplete: (reason: number, total: number) => void; | Added|
| ohos.hiSysEvent | Querier | onQuery: (infos: SysEventInfo[], seqs: number[]) => void; | Added|
| ohos.hiSysEvent | QueryRule | names: string[]; | Added|
| ohos.hiSysEvent | QueryRule | domain: string; | Added|
| ohos.hiSysEvent | QueryArg | maxEvents: number; | Added|
| ohos.hiSysEvent | QueryArg | endTime: number; | Added|
| ohos.hiSysEvent | QueryArg | beginTime: number; | Added|
| ohos.hiSysEvent | Watcher | onServiceDied: () => void; | Added|
| ohos.hiSysEvent | Watcher | onEvent: (info: SysEventInfo) => void; | Added|
| ohos.hiSysEvent | Watcher | rules: WatchRule[]; | Added|
| ohos.hiSysEvent | WatchRule | ruleType: RuleType; | Added|
| ohos.hiSysEvent | WatchRule | tag: string; | Added|
| ohos.hiSysEvent | WatchRule | name: string; | Added|
| ohos.hiSysEvent | WatchRule | domain: string; | Added|
| ohos.hiSysEvent | RuleType | REGULAR = 3 | Added|
| ohos.hiSysEvent | RuleType | PREFIX = 2 | Added|
| ohos.hiSysEvent | RuleType | WHOLE_WORD = 1 | Added|
| ohos.hiSysEvent | hiSysEvent | write(info: SysEventInfo): Promise\<void>;<br>write(info: SysEventInfo, callback: AsyncCallback\<void>): void; | Added|
| ohos.hiSysEvent | SysEventInfo | params: object; | Added|
| ohos.hiSysEvent | SysEventInfo | eventType: EventType; | Added|
| ohos.hiSysEvent | SysEventInfo | name: string; | Added|
| ohos.hiSysEvent | SysEventInfo | domain: string; | Added|
| ohos.hiSysEvent | EventType | BEHAVIOR = 4 | Added|
| ohos.hiSysEvent | EventType | SECURITY = 3 | Added|
| ohos.hiSysEvent | EventType | STATISTIC = 2 | Added|
| ohos.hiSysEvent | EventType | FAULT = 1 | Added|
