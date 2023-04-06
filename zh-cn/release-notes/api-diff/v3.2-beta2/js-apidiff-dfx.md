# DFX子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，DFX子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.hiSysEvent | hiSysEvent | query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): number; | 新增 |
| ohos.hiSysEvent | hiSysEvent | removeWatcher(wathcer: Watcher): number; | 新增 |
| ohos.hiSysEvent | hiSysEvent | addWatcher(watcher: Watcher): number; | 新增 |
| ohos.hiSysEvent | Querier | onComplete: (reason: number, total: number) => void; | 新增 |
| ohos.hiSysEvent | Querier | onQuery: (infos: SysEventInfo[], seqs: number[]) => void; | 新增 |
| ohos.hiSysEvent | QueryRule | names: string[]; | 新增 |
| ohos.hiSysEvent | QueryRule | domain: string; | 新增 |
| ohos.hiSysEvent | QueryArg | maxEvents: number; | 新增 |
| ohos.hiSysEvent | QueryArg | endTime: number; | 新增 |
| ohos.hiSysEvent | QueryArg | beginTime: number; | 新增 |
| ohos.hiSysEvent | Watcher | onServiceDied: () => void; | 新增 |
| ohos.hiSysEvent | Watcher | onEvent: (info: SysEventInfo) => void; | 新增 |
| ohos.hiSysEvent | Watcher | rules: WatchRule[]; | 新增 |
| ohos.hiSysEvent | WatchRule | ruleType: RuleType; | 新增 |
| ohos.hiSysEvent | WatchRule | tag: string; | 新增 |
| ohos.hiSysEvent | WatchRule | name: string; | 新增 |
| ohos.hiSysEvent | WatchRule | domain: string; | 新增 |
| ohos.hiSysEvent | RuleType | REGULAR = 3 | 新增 |
| ohos.hiSysEvent | RuleType | PREFIX = 2 | 新增 |
| ohos.hiSysEvent | RuleType | WHOLE_WORD = 1 | 新增 |
| ohos.hiSysEvent | hiSysEvent | write(info: SysEventInfo): Promise\<void>;<br>write(info: SysEventInfo, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.hiSysEvent | SysEventInfo | params: object; | 新增 |
| ohos.hiSysEvent | SysEventInfo | eventType: EventType; | 新增 |
| ohos.hiSysEvent | SysEventInfo | name: string; | 新增 |
| ohos.hiSysEvent | SysEventInfo | domain: string; | 新增 |
| ohos.hiSysEvent | EventType | BEHAVIOR = 4 | 新增 |
| ohos.hiSysEvent | EventType | SECURITY = 3 | 新增 |
| ohos.hiSysEvent | EventType | STATISTIC = 2 | 新增 |
| ohos.hiSysEvent | EventType | FAULT = 1 | 新增 |