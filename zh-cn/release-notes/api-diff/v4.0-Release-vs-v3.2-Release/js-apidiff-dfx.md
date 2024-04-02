| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：hiSysEvent;<br>方法or属性：function exportSysEvents(queryArg: QueryArg, rules: QueryRule[]): number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function subscribe(rules: QueryRule[]): number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function unsubscribe(): void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryArg;<br>方法or属性：fromSeq?: number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryArg;<br>方法or属性：toSeq?: number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryRule;<br>方法or属性：condition?: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function list(logType: string): LogEntry[];|@ohos.logLibrary.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function copy(logType: string, logName: string, dest: string): Promise\<void>;|@ohos.logLibrary.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function copy(logType: string, logName: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.logLibrary.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function move(logType: string, logName: string, dest: string): Promise\<void>;|@ohos.logLibrary.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function move(logType: string, logName: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.logLibrary.d.ts|
|新增|NA|类名：logLibrary;<br>方法or属性：function remove(logType: string, logName: string): void;|@ohos.logLibrary.d.ts|
|新增|NA|类名：LogEntry;<br>方法or属性：name: string;|@ohos.logLibrary.d.ts|
|新增|NA|类名：LogEntry;<br>方法or属性：mtime: number;|@ohos.logLibrary.d.ts|
|新增|NA|类名：LogEntry;<br>方法or属性：size: number;|@ohos.logLibrary.d.ts|
|新增(错误码)|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;<br>新版本信息：401,11200001,11200002,11200003,11200004,11200051,11200052,11200053,11200054|@ohos.hiSysEvent.d.ts|
|新增(错误码)|类名：hiAppEvent;<br>方法or属性：function write(info: AppEventInfo, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：hiAppEvent;<br>方法or属性：function write(info: AppEventInfo, callback: AsyncCallback\<void>): void;<br>新版本信息：401,11100001,11101001,11101002,11101003,11101004,11101005,11101006|@ohos.hiviewdfx.hiAppEvent.d.ts|
|错误码有变化|类名：hiSysEvent;<br>方法or属性：function addWatcher(watcher: Watcher): void;<br>旧版本信息：201,401,11200101,11200102|类名：hiSysEvent;<br>方法or属性：function addWatcher(watcher: Watcher): void;<br>新版本信息：201,202,401,11200101,11200102|@ohos.hiSysEvent.d.ts|
|错误码有变化|类名：hiSysEvent;<br>方法or属性：function removeWatcher(watcher: Watcher): void;<br>旧版本信息：201,401,11200201|类名：hiSysEvent;<br>方法or属性：function removeWatcher(watcher: Watcher): void;<br>新版本信息：201,202,401,11200201|@ohos.hiSysEvent.d.ts|
|错误码有变化|类名：hiSysEvent;<br>方法or属性：function query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void;<br>旧版本信息：201,401,11200301,11200302,11200303,11200304|类名：hiSysEvent;<br>方法or属性：function query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void;<br>新版本信息：201,202,401,11200301,11200302,11200303,11200304|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：SysEventInfo;<br>方法or属性：domain: string;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：domain: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：WatchRule;<br>方法or属性：domain: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：domain: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：QueryRule;<br>方法or属性：domain: string;<br>旧版本信息：|类名：QueryRule;<br>方法or属性：domain: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：SysEventInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：WatchRule;<br>方法or属性：name: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：SysEventInfo;<br>方法or属性：eventType: EventType;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：eventType: EventType;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：SysEventInfo;<br>方法or属性：params: object;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：params: object;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：WatchRule;<br>方法or属性：tag: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：tag: string;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：WatchRule;<br>方法or属性：ruleType: RuleType;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：ruleType: RuleType;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：Watcher;<br>方法or属性：rules: WatchRule[];<br>旧版本信息：|类名：Watcher;<br>方法or属性：rules: WatchRule[];<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：QueryArg;<br>方法or属性：beginTime: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：beginTime: number;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：QueryArg;<br>方法or属性：endTime: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：endTime: number;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：QueryArg;<br>方法or属性：maxEvents: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：maxEvents: number;<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|访问级别有变化|类名：QueryRule;<br>方法or属性：names: string[];<br>旧版本信息：|类名：QueryRule;<br>方法or属性：names: string[];<br>新版本信息：systemapi|@ohos.hiSysEvent.d.ts|
|type有变化|类名：SysEventInfo;<br>方法or属性：domain: string;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：domain: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：WatchRule;<br>方法or属性：domain: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：domain: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：QueryRule;<br>方法or属性：domain: string;<br>旧版本信息：|类名：QueryRule;<br>方法or属性：domain: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：SysEventInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：WatchRule;<br>方法or属性：name: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：SysEventInfo;<br>方法or属性：eventType: EventType;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：eventType: EventType;<br>新版本信息：EventType|@ohos.hiSysEvent.d.ts|
|type有变化|类名：SysEventInfo;<br>方法or属性：params: object;<br>旧版本信息：|类名：SysEventInfo;<br>方法or属性：params: object;<br>新版本信息：object|@ohos.hiSysEvent.d.ts|
|type有变化|类名：WatchRule;<br>方法or属性：tag: string;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：tag: string;<br>新版本信息：string|@ohos.hiSysEvent.d.ts|
|type有变化|类名：WatchRule;<br>方法or属性：ruleType: RuleType;<br>旧版本信息：|类名：WatchRule;<br>方法or属性：ruleType: RuleType;<br>新版本信息：RuleType|@ohos.hiSysEvent.d.ts|
|type有变化|类名：QueryArg;<br>方法or属性：beginTime: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：beginTime: number;<br>新版本信息：number|@ohos.hiSysEvent.d.ts|
|type有变化|类名：QueryArg;<br>方法or属性：endTime: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：endTime: number;<br>新版本信息：number|@ohos.hiSysEvent.d.ts|
|type有变化|类名：QueryArg;<br>方法or属性：maxEvents: number;<br>旧版本信息：|类名：QueryArg;<br>方法or属性：maxEvents: number;<br>新版本信息：number|@ohos.hiSysEvent.d.ts|
|type有变化|类名：QueryRule;<br>方法or属性：names: string[];<br>旧版本信息：|类名：QueryRule;<br>方法or属性：names: string[];<br>新版本信息：string[]|@ohos.hiSysEvent.d.ts|
|type有变化|类名：HiTraceId;<br>方法or属性：chainId: bigint;<br>旧版本信息：|类名：HiTraceId;<br>方法or属性：chainId: bigint;<br>新版本信息：bigint|@ohos.hiTraceChain.d.ts|
|type有变化|类名：HiTraceId;<br>方法or属性：spanId?: number;<br>旧版本信息：|类名：HiTraceId;<br>方法or属性：spanId?: number;<br>新版本信息：?number|@ohos.hiTraceChain.d.ts|
|type有变化|类名：HiTraceId;<br>方法or属性：parentSpanId?: number;<br>旧版本信息：|类名：HiTraceId;<br>方法or属性：parentSpanId?: number;<br>新版本信息：?number|@ohos.hiTraceChain.d.ts|
|type有变化|类名：HiTraceId;<br>方法or属性：flags?: number;<br>旧版本信息：|类名：HiTraceId;<br>方法or属性：flags?: number;<br>新版本信息：?number|@ohos.hiTraceChain.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：declare hilog<br>旧版本信息：|类名：hilog;<br>方法or属性：declare hilog<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：function debug(domain: number, tag: string, format: string, ...args: any[]): void;<br>旧版本信息：|类名：hilog;<br>方法or属性：function debug(domain: number, tag: string, format: string, ...args: any[]): void;<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：function info(domain: number, tag: string, format: string, ...args: any[]): void;<br>旧版本信息：|类名：hilog;<br>方法or属性：function info(domain: number, tag: string, format: string, ...args: any[]): void;<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：function warn(domain: number, tag: string, format: string, ...args: any[]): void;<br>旧版本信息：|类名：hilog;<br>方法or属性：function warn(domain: number, tag: string, format: string, ...args: any[]): void;<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：function error(domain: number, tag: string, format: string, ...args: any[]): void;<br>旧版本信息：|类名：hilog;<br>方法or属性：function error(domain: number, tag: string, format: string, ...args: any[]): void;<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：hilog;<br>方法or属性：function fatal(domain: number, tag: string, format: string, ...args: any[]): void;<br>旧版本信息：|类名：hilog;<br>方法or属性：function fatal(domain: number, tag: string, format: string, ...args: any[]): void;<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：enum LogLevel<br>旧版本信息：|类名：LogLevel;<br>方法or属性：enum LogLevel<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：DEBUG = 3<br>旧版本信息：|类名：LogLevel;<br>方法or属性：DEBUG = 3<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：INFO = 4<br>旧版本信息：|类名：LogLevel;<br>方法or属性：INFO = 4<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：WARN = 5<br>旧版本信息：|类名：LogLevel;<br>方法or属性：WARN = 5<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：ERROR = 6<br>旧版本信息：|类名：LogLevel;<br>方法or属性：ERROR = 6<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
|跨平台能力有变化|类名：LogLevel;<br>方法or属性：FATAL = 7<br>旧版本信息：|类名：LogLevel;<br>方法or属性：FATAL = 7<br>新版本信息：crossplatform|@ohos.hilog.d.ts|
