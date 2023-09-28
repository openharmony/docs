| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：FaultLogger;<br>方法or属性：function query(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;|@ohos.faultLogger.d.ts|
|新增|NA|类名：FaultLogger;<br>方法or属性：function query(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;|@ohos.faultLogger.d.ts|
|新增|NA|类名：hichecker;<br>方法or属性：function addCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|新增|NA|类名：hichecker;<br>方法or属性：function removeCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|新增|NA|类名：hichecker;<br>方法or属性：function containsCheckRule(rule: bigint) : boolean;|@ohos.hichecker.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function getPrivateDirty() : bigint;|@ohos.hidebug.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function getCpuUsage() : number;|@ohos.hidebug.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function startJsCpuProfiling(filename : string) : void;|@ohos.hidebug.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function stopJsCpuProfiling() : void;|@ohos.hidebug.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function dumpJsHeapData(filename : string) : void;|@ohos.hidebug.d.ts|
|新增|NA|类名：hidebug;<br>方法or属性：function getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void;|@ohos.hidebug.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo): Promise\<void>;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function addWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function removeWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiSysEvent;<br>方法or属性：function query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：FAULT = 1|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：STATISTIC = 2|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：SECURITY = 3|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：BEHAVIOR = 4|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：SysEventInfo;<br>方法or属性：domain: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：WatchRule;<br>方法or属性：domain: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryRule;<br>方法or属性：domain: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：SysEventInfo;<br>方法or属性：name: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：WatchRule;<br>方法or属性：name: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：SysEventInfo;<br>方法or属性：eventType: EventType;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：SysEventInfo;<br>方法or属性：params: object;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：RuleType;<br>方法or属性：WHOLE_WORD = 1|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：RuleType;<br>方法or属性：PREFIX = 2|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：RuleType;<br>方法or属性：REGULAR = 3|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：WatchRule;<br>方法or属性：tag: string;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：WatchRule;<br>方法or属性：ruleType: RuleType;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：rules: WatchRule[];|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：onEvent: (info: SysEventInfo) => void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：onServiceDied: () => void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryArg;<br>方法or属性：beginTime: number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryArg;<br>方法or属性：endTime: number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryArg;<br>方法or属性：maxEvents: number;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：QueryRule;<br>方法or属性：names: string[];|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：Querier;<br>方法or属性：onQuery: (infos: SysEventInfo[]) => void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：Querier;<br>方法or属性：onComplete: (reason: number, total: number) => void;|@ohos.hiSysEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function configure(config: ConfigOption): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function write(info: AppEventInfo): Promise\<void>;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function write(info: AppEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function addWatcher(watcher: Watcher): AppEventPackageHolder;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function removeWatcher(watcher: Watcher): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：hiAppEvent;<br>方法or属性：function clearData(): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：FAULT = 1|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：STATISTIC = 2|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：SECURITY = 3|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：BEHAVIOR = 4|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：ConfigOption;<br>方法or属性：disable?: boolean;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：ConfigOption;<br>方法or属性：maxStorage?: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventInfo;<br>方法or属性：domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventFilter;<br>方法or属性：domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventInfo;<br>方法or属性：name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventInfo;<br>方法or属性：eventType: EventType;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventInfo;<br>方法or属性：params: object;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackage;<br>方法or属性：packageId: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackage;<br>方法or属性：row: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackage;<br>方法or属性：size: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackage;<br>方法or属性：data: string[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackageHolder;<br>方法or属性：constructor(watcherName: string);|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackageHolder;<br>方法or属性：setSize(size: number): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventPackageHolder;<br>方法or属性：takeNext(): AppEventPackage;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：TriggerCondition;<br>方法or属性：row?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：TriggerCondition;<br>方法or属性：size?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：TriggerCondition;<br>方法or属性：timeOut?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：AppEventFilter;<br>方法or属性：eventTypes?: EventType[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：triggerCondition?: TriggerCondition;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：appEventFilters?: AppEventFilter[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|新增|NA|类名：Watcher;<br>方法or属性：onTrigger?: (curRow: number, curSize: number, holder: AppEventPackageHolder) => void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|废弃版本有变化|类名：bytrace;<br>方法or属性：declare bytrace<br>旧版本信息：|类名：bytrace;<br>方法or属性：declare bytrace<br>新版本信息：8<br>代替接口： ohos.hiTraceMeter|@ohos.bytrace.d.ts|
|废弃版本有变化|类名：bytrace;<br>方法or属性：function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>旧版本信息：|类名：bytrace;<br>方法or属性：function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>新版本信息：8<br>代替接口： ohos.hiTraceMeter.startTrace|@ohos.bytrace.d.ts|
|废弃版本有变化|类名：bytrace;<br>方法or属性：function finishTrace(name: string, taskId: number): void;<br>旧版本信息：|类名：bytrace;<br>方法or属性：function finishTrace(name: string, taskId: number): void;<br>新版本信息：8<br>代替接口： ohos.hiTraceMeter.finishTrace|@ohos.bytrace.d.ts|
|废弃版本有变化|类名：bytrace;<br>方法or属性：function traceByValue(name: string, count: number): void;<br>旧版本信息：|类名：bytrace;<br>方法or属性：function traceByValue(name: string, count: number): void;<br>新版本信息：8<br>代替接口： ohos.hiTraceMeter.traceByValue|@ohos.bytrace.d.ts|
|废弃版本有变化|类名：FaultLogger;<br>方法or属性：function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>旧版本信息：|类名：FaultLogger;<br>方法or属性：function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.faultlogger/FaultLogger#query|@ohos.faultLogger.d.ts|
|废弃版本有变化|类名：FaultLogger;<br>方法or属性：function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>旧版本信息：|类名：FaultLogger;<br>方法or属性：function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>新版本信息：9<br>代替接口： ohos.faultlogger/FaultLogger#query|@ohos.faultLogger.d.ts|
|废弃版本有变化|类名：hiAppEvent;<br>方法or属性：declare hiAppEvent<br>旧版本信息：|类名：hiAppEvent;<br>方法or属性：declare hiAppEvent<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：hiAppEvent;<br>方法or属性：function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>旧版本信息：|类名：hiAppEvent;<br>方法or属性：function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：hiAppEvent;<br>方法or属性：function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：hiAppEvent;<br>方法or属性：function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：hiAppEvent;<br>方法or属性：function configure(config: ConfigOption): boolean;<br>旧版本信息：|类名：hiAppEvent;<br>方法or属性：function configure(config: ConfigOption): boolean;<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：EventType;<br>方法or属性：enum EventType<br>旧版本信息：|类名：EventType;<br>方法or属性：enum EventType<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：EventType;<br>方法or属性：FAULT = 1<br>旧版本信息：|类名：EventType;<br>方法or属性：FAULT = 1<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：EventType;<br>方法or属性：STATISTIC = 2<br>旧版本信息：|类名：EventType;<br>方法or属性：STATISTIC = 2<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：EventType;<br>方法or属性：SECURITY = 3<br>旧版本信息：|类名：EventType;<br>方法or属性：SECURITY = 3<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：EventType;<br>方法or属性：BEHAVIOR = 4<br>旧版本信息：|类名：EventType;<br>方法or属性：BEHAVIOR = 4<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：Event;<br>方法or属性：Event<br>旧版本信息：|类名：Event;<br>方法or属性：Event<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：Param;<br>方法or属性：Param<br>旧版本信息：|类名：Param;<br>方法or属性：Param<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：ConfigOption;<br>方法or属性：interface ConfigOption<br>旧版本信息：|类名：ConfigOption;<br>方法or属性：interface ConfigOption<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：ConfigOption;<br>方法or属性：disable?: boolean;<br>旧版本信息：|类名：ConfigOption;<br>方法or属性：disable?: boolean;<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：ConfigOption;<br>方法or属性：maxStorage?: string;<br>旧版本信息：|类名：ConfigOption;<br>方法or属性：maxStorage?: string;<br>新版本信息：9<br>代替接口： ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|废弃版本有变化|类名：hichecker;<br>方法or属性：function addRule(rule: bigint) : void;<br>旧版本信息：|类名：hichecker;<br>方法or属性：function addRule(rule: bigint) : void;<br>新版本信息：9<br>代替接口： ohos.hichecker/hichecker#addCheckRule|@ohos.hichecker.d.ts|
|废弃版本有变化|类名：hichecker;<br>方法or属性：function removeRule(rule: bigint) : void;<br>旧版本信息：|类名：hichecker;<br>方法or属性：function removeRule(rule: bigint) : void;<br>新版本信息：9<br>代替接口： ohos.hichecker/hichecker#removeCheckRule|@ohos.hichecker.d.ts|
|废弃版本有变化|类名：hichecker;<br>方法or属性：function contains(rule: bigint) : boolean;<br>旧版本信息：|类名：hichecker;<br>方法or属性：function contains(rule: bigint) : boolean;<br>新版本信息：9<br>代替接口： ohos.hichecker/hichecker#containsCheckRule|@ohos.hichecker.d.ts|
|废弃版本有变化|类名：hidebug;<br>方法or属性：function startProfiling(filename : string) : void;<br>旧版本信息：|类名：hidebug;<br>方法or属性：function startProfiling(filename : string) : void;<br>新版本信息：9<br>代替接口： ohos.hidebug/hidebug.startJsCpuProfiling|@ohos.hidebug.d.ts|
|废弃版本有变化|类名：hidebug;<br>方法or属性：function stopProfiling() : void;<br>旧版本信息：|类名：hidebug;<br>方法or属性：function stopProfiling() : void;<br>新版本信息：9<br>代替接口： ohos.hidebug/hidebug.stopJsCpuProfiling|@ohos.hidebug.d.ts|
|废弃版本有变化|类名：hidebug;<br>方法or属性：function dumpHeapData(filename : string) : void;<br>旧版本信息：|类名：hidebug;<br>方法or属性：function dumpHeapData(filename : string) : void;<br>新版本信息：9<br>代替接口： ohos.hidebug/hidebug.dumpJsHeapData|@ohos.hidebug.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：pid: number;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：pid: number;<br>新版本信息：number|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：uid: number;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：uid: number;<br>新版本信息：number|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：type: FaultType;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：type: FaultType;<br>新版本信息：FaultType|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：timestamp: number;<br>新版本信息：number|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：reason: string;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：reason: string;<br>新版本信息：string|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：module: string;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：module: string;<br>新版本信息：string|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：summary: string;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：summary: string;<br>新版本信息：string|@ohos.faultLogger.d.ts|
|type有变化|类名：FaultLogInfo;<br>方法or属性：fullLog: string;<br>旧版本信息：|类名：FaultLogInfo;<br>方法or属性：fullLog: string;<br>新版本信息：string|@ohos.faultLogger.d.ts|
|函数有变化|类名：hiTraceChain;<br>方法or属性：function begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId;|类名：hiTraceChain;<br>方法or属性：function begin(name: string, flags?: number): HiTraceId;|@ohos.hiTraceChain.d.ts|
