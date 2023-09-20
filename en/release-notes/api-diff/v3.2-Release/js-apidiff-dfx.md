| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: FaultLogger;<br>Method or attribute name: function query(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;|@ohos.faultLogger.d.ts|
|Added|NA|Class name: FaultLogger;<br>Method or attribute name: function query(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;|@ohos.faultLogger.d.ts|
|Added|NA|Class name: hichecker;<br>Method or attribute name: function addCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hichecker;<br>Method or attribute name: function removeCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hichecker;<br>Method or attribute name: function containsCheckRule(rule: bigint) : boolean;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function getPrivateDirty() : bigint;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function getCpuUsage() : number;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function startJsCpuProfiling(filename : string) : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function stopJsCpuProfiling() : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function dumpJsHeapData(filename : string) : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug;<br>Method or attribute name: function getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hiSysEvent;<br>Method or attribute name: function write(info: SysEventInfo): Promise\<void>;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: hiSysEvent;<br>Method or attribute name: function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: hiSysEvent;<br>Method or attribute name: function addWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: hiSysEvent;<br>Method or attribute name: function removeWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: hiSysEvent;<br>Method or attribute name: function query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: FAULT = 1|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: STATISTIC = 2|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: SECURITY = 3|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: BEHAVIOR = 4|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: SysEventInfo;<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: WatchRule;<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: QueryRule;<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: SysEventInfo;<br>Method or attribute name: name: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: WatchRule;<br>Method or attribute name: name: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: SysEventInfo;<br>Method or attribute name: eventType: EventType;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: SysEventInfo;<br>Method or attribute name: params: object;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: RuleType;<br>Method or attribute name: WHOLE_WORD = 1|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: RuleType;<br>Method or attribute name: PREFIX = 2|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: RuleType;<br>Method or attribute name: REGULAR = 3|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: WatchRule;<br>Method or attribute name: tag: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: WatchRule;<br>Method or attribute name: ruleType: RuleType;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: rules: WatchRule[];|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: onEvent: (info: SysEventInfo) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: onServiceDied: () => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: QueryArg;<br>Method or attribute name: beginTime: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: QueryArg;<br>Method or attribute name: endTime: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: QueryArg;<br>Method or attribute name: maxEvents: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: QueryRule;<br>Method or attribute name: names: string[];|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: Querier;<br>Method or attribute name: onQuery: (infos: SysEventInfo[]) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: Querier;<br>Method or attribute name: onComplete: (reason: number, total: number) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function configure(config: ConfigOption): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function write(info: AppEventInfo): Promise\<void>;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function write(info: AppEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function addWatcher(watcher: Watcher): AppEventPackageHolder;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function removeWatcher(watcher: Watcher): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: hiAppEvent;<br>Method or attribute name: function clearData(): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: FAULT = 1|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: STATISTIC = 2|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: SECURITY = 3|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: EventType;<br>Method or attribute name: BEHAVIOR = 4|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: ConfigOption;<br>Method or attribute name: disable?: boolean;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: ConfigOption;<br>Method or attribute name: maxStorage?: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventInfo;<br>Method or attribute name: domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventFilter;<br>Method or attribute name: domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventInfo;<br>Method or attribute name: name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventInfo;<br>Method or attribute name: eventType: EventType;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventInfo;<br>Method or attribute name: params: object;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackage;<br>Method or attribute name: packageId: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackage;<br>Method or attribute name: row: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackage;<br>Method or attribute name: size: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackage;<br>Method or attribute name: data: string[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackageHolder;<br>Method or attribute name: constructor(watcherName: string);|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackageHolder;<br>Method or attribute name: setSize(size: number): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventPackageHolder;<br>Method or attribute name: takeNext(): AppEventPackage;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: TriggerCondition;<br>Method or attribute name: row?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: TriggerCondition;<br>Method or attribute name: size?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: TriggerCondition;<br>Method or attribute name: timeOut?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: AppEventFilter;<br>Method or attribute name: eventTypes?: EventType[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: triggerCondition?: TriggerCondition;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: appEventFilters?: AppEventFilter[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Class name: Watcher;<br>Method or attribute name: onTrigger?: (curRow: number, curSize: number, holder: AppEventPackageHolder) => void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Deprecated version changed|Class name: bytrace;<br>Method or attribute name: declare bytrace<br>Old version: |Class name: bytrace;<br>Method or attribute name: declare bytrace<br>New version: 8<br>Substitute API: ohos.hiTraceMeter|@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace;<br>Method or attribute name: function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>Old version: |Class name: bytrace;<br>Method or attribute name: function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>New version: 8<br>Substitute API: ohos.hiTraceMeter.startTrace|@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace;<br>Method or attribute name: function finishTrace(name: string, taskId: number): void;<br>Old version: |Class name: bytrace;<br>Method or attribute name: function finishTrace(name: string, taskId: number): void;<br>New version: 8<br>Substitute API: ohos.hiTraceMeter.finishTrace|@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace;<br>Method or attribute name: function traceByValue(name: string, count: number): void;<br>Old version: |Class name: bytrace;<br>Method or attribute name: function traceByValue(name: string, count: number): void;<br>New version: 8<br>Substitute API: ohos.hiTraceMeter.traceByValue|@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: FaultLogger;<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>Old version: |Class name: FaultLogger;<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>New version: 9<br>Substitute API: ohos.faultlogger/FaultLogger#query|@ohos.faultLogger.d.ts|
|Deprecated version changed|Class name: FaultLogger;<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>Old version: |Class name: FaultLogger;<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>New version: 9<br>Substitute API: ohos.faultlogger/FaultLogger#query|@ohos.faultLogger.d.ts|
|Deprecated version changed|Class name: hiAppEvent;<br>Method or attribute name: declare hiAppEvent<br>Old version: |Class name: hiAppEvent;<br>Method or attribute name: declare hiAppEvent<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: hiAppEvent;<br>Method or attribute name: function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>Old version: |Class name: hiAppEvent;<br>Method or attribute name: function write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: hiAppEvent;<br>Method or attribute name: function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: hiAppEvent;<br>Method or attribute name: function write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: hiAppEvent;<br>Method or attribute name: function configure(config: ConfigOption): boolean;<br>Old version: |Class name: hiAppEvent;<br>Method or attribute name: function configure(config: ConfigOption): boolean;<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: EventType;<br>Method or attribute name: enum EventType<br>Old version: |Class name: EventType;<br>Method or attribute name: enum EventType<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: EventType;<br>Method or attribute name: FAULT = 1<br>Old version: |Class name: EventType;<br>Method or attribute name: FAULT = 1<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: EventType;<br>Method or attribute name: STATISTIC = 2<br>Old version: |Class name: EventType;<br>Method or attribute name: STATISTIC = 2<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: EventType;<br>Method or attribute name: SECURITY = 3<br>Old version: |Class name: EventType;<br>Method or attribute name: SECURITY = 3<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: EventType;<br>Method or attribute name: BEHAVIOR = 4<br>Old version: |Class name: EventType;<br>Method or attribute name: BEHAVIOR = 4<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: Event;<br>Method or attribute name: Event<br>Old version: |Class name: Event;<br>Method or attribute name: Event<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: Param;<br>Method or attribute name: Param<br>Old version: |Class name: Param;<br>Method or attribute name: Param<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: ConfigOption;<br>Method or attribute name: interface ConfigOption<br>Old version: |Class name: ConfigOption;<br>Method or attribute name: interface ConfigOption<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: ConfigOption;<br>Method or attribute name: disable?: boolean;<br>Old version: |Class name: ConfigOption;<br>Method or attribute name: disable?: boolean;<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: ConfigOption;<br>Method or attribute name: maxStorage?: string;<br>Old version: |Class name: ConfigOption;<br>Method or attribute name: maxStorage?: string;<br>New version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent|@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: hichecker;<br>Method or attribute name: function addRule(rule: bigint) : void;<br>Old version: |Class name: hichecker;<br>Method or attribute name: function addRule(rule: bigint) : void;<br>New version: 9<br>Substitute API: ohos.hichecker/hichecker#addCheckRule|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hichecker;<br>Method or attribute name: function removeRule(rule: bigint) : void;<br>Old version: |Class name: hichecker;<br>Method or attribute name: function removeRule(rule: bigint) : void;<br>New version: 9<br>Substitute API: ohos.hichecker/hichecker#removeCheckRule|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hichecker;<br>Method or attribute name: function contains(rule: bigint) : boolean;<br>Old version: |Class name: hichecker;<br>Method or attribute name: function contains(rule: bigint) : boolean;<br>New version: 9<br>Substitute API: ohos.hichecker/hichecker#containsCheckRule|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hidebug;<br>Method or attribute name: function startProfiling(filename : string) : void;<br>Old version: |Class name: hidebug;<br>Method or attribute name: function startProfiling(filename : string) : void;<br>New version: 9<br>Substitute API: ohos.hidebug/hidebug.startJsCpuProfiling|@ohos.hidebug.d.ts|
|Deprecated version changed|Class name: hidebug;<br>Method or attribute name: function stopProfiling() : void;<br>Old version: |Class name: hidebug;<br>Method or attribute name: function stopProfiling() : void;<br>New version: 9<br>Substitute API: ohos.hidebug/hidebug.stopJsCpuProfiling|@ohos.hidebug.d.ts|
|Deprecated version changed|Class name: hidebug;<br>Method or attribute name: function dumpHeapData(filename : string) : void;<br>Old version: |Class name: hidebug;<br>Method or attribute name: function dumpHeapData(filename : string) : void;<br>New version: 9<br>Substitute API: ohos.hidebug/hidebug.dumpJsHeapData|@ohos.hidebug.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: pid: number;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: pid: number;<br>New version: number|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: uid: number;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: uid: number;<br>New version: number|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: type: FaultType;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: type: FaultType;<br>New version: FaultType|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: timestamp: number;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: timestamp: number;<br>New version: number|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: reason: string;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: reason: string;<br>New version: string|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: module: string;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: module: string;<br>New version: string|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: summary: string;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: summary: string;<br>New version: string|@ohos.faultLogger.d.ts|
|Type changed|Class name: FaultLogInfo;<br>Method or attribute name: fullLog: string;<br>Old version: |Class name: FaultLogInfo;<br>Method or attribute name: fullLog: string;<br>New version: string|@ohos.faultLogger.d.ts|
|Function changed|Class name: hiTraceChain;<br>Method or attribute name: function begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId;|Class name: hiTraceChain;<br>Method or attribute name: function begin(name: string, flags?: number): HiTraceId;|@ohos.hiTraceChain.d.ts|
