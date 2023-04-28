| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: FaultLogger<br>Method or attribute name: function query(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;|@ohos.faultLogger.d.ts|
|Added|NA|Class name: FaultLogger<br>Method or attribute name: function query(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;|@ohos.faultLogger.d.ts|
|Added|NA|Class name: hichecker<br>Method or attribute name: function addCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hichecker<br>Method or attribute name: function removeCheckRule(rule: bigint) : void;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hichecker<br>Method or attribute name: function containsCheckRule(rule: bigint) : boolean;|@ohos.hichecker.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function getPrivateDirty() : bigint;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function getCpuUsage() : number;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function startJsCpuProfiling(filename : string) : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function stopJsCpuProfiling() : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function dumpJsHeapData(filename : string) : void;|@ohos.hidebug.d.ts|
|Added|NA|Class name: hidebug<br>Method or attribute name: function getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void;|@ohos.hidebug.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: EventType|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: EventType<br>Method or attribute name: FAULT = 1|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: EventType<br>Method or attribute name: STATISTIC = 2|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: EventType<br>Method or attribute name: SECURITY = 3|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: EventType<br>Method or attribute name: BEHAVIOR = 4|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: SysEventInfo|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: SysEventInfo<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: SysEventInfo<br>Method or attribute name: name: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: SysEventInfo<br>Method or attribute name: eventType: EventType;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: SysEventInfo<br>Method or attribute name: params: object;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent<br>Method or attribute name: function write(info: SysEventInfo): Promise\<void>;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent<br>Method or attribute name: function write(info: SysEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: RuleType|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: RuleType<br>Method or attribute name: WHOLE_WORD = 1|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: RuleType<br>Method or attribute name: PREFIX = 2|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: RuleType<br>Method or attribute name: REGULAR = 3|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: WatchRule|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: WatchRule<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: WatchRule<br>Method or attribute name: name: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: WatchRule<br>Method or attribute name: tag: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: WatchRule<br>Method or attribute name: ruleType: RuleType;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Watcher|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Watcher<br>Method or attribute name: rules: WatchRule[];|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Watcher<br>Method or attribute name: onEvent: (info: SysEventInfo) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Watcher<br>Method or attribute name: onServiceDied: () => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryArg|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryArg<br>Method or attribute name: beginTime: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryArg<br>Method or attribute name: endTime: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryArg<br>Method or attribute name: maxEvents: number;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryRule|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryRule<br>Method or attribute name: domain: string;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: QueryRule<br>Method or attribute name: names: string[];|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Querier|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Querier<br>Method or attribute name: onQuery: (infos: SysEventInfo[]) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: Querier<br>Method or attribute name: onComplete: (reason: number, total: number) => void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent<br>Method or attribute name: function addWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent<br>Method or attribute name: function removeWatcher(watcher: Watcher): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiSysEvent<br>Class name: hiSysEvent<br>Method or attribute name: function query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void;|@ohos.hiSysEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: EventType|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: EventType<br>Method or attribute name: FAULT = 1|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: EventType<br>Method or attribute name: STATISTIC = 2|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: EventType<br>Method or attribute name: SECURITY = 3|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: EventType<br>Method or attribute name: BEHAVIOR = 4|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: event|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: event<br>Method or attribute name: const USER_LOGIN: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: event<br>Method or attribute name: const USER_LOGOUT: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: event<br>Method or attribute name: const DISTRIBUTED_SERVICE_START: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: param|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: param<br>Method or attribute name: const USER_ID: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: param<br>Method or attribute name: const DISTRIBUTED_SERVICE_NAME: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: param<br>Method or attribute name: const DISTRIBUTED_SERVICE_INSTANCE_ID: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function configure(config: ConfigOption): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: ConfigOption|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: ConfigOption<br>Method or attribute name: disable?: boolean;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: ConfigOption<br>Method or attribute name: maxStorage?: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventInfo|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventInfo<br>Method or attribute name: domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventInfo<br>Method or attribute name: name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventInfo<br>Method or attribute name: eventType: EventType;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventInfo<br>Method or attribute name: params: object;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function write(info: AppEventInfo): Promise\<void>;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function write(info: AppEventInfo, callback: AsyncCallback\<void>): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackage|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackage<br>Method or attribute name: packageId: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackage<br>Method or attribute name: row: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackage<br>Method or attribute name: size: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackage<br>Method or attribute name: data: string[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackageHolder|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackageHolder<br>Method or attribute name: constructor(watcherName: string);|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackageHolder<br>Method or attribute name: setSize(size: number): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventPackageHolder<br>Method or attribute name: takeNext(): AppEventPackage;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: TriggerCondition|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: TriggerCondition<br>Method or attribute name: row?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: TriggerCondition<br>Method or attribute name: size?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: TriggerCondition<br>Method or attribute name: timeOut?: number;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventFilter|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventFilter<br>Method or attribute name: domain: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: AppEventFilter<br>Method or attribute name: eventTypes?: EventType[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: Watcher|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: Watcher<br>Method or attribute name: name: string;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: Watcher<br>Method or attribute name: triggerCondition?: TriggerCondition;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: Watcher<br>Method or attribute name: appEventFilters?: AppEventFilter[];|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: Watcher<br>Method or attribute name: onTrigger?: (curRow: number, curSize: number, holder: AppEventPackageHolder) => void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function addWatcher(watcher: Watcher): AppEventPackageHolder;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function removeWatcher(watcher: Watcher): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Added|NA|Module name: ohos.hiviewdfx.hiAppEvent<br>Class name: hiAppEvent<br>Method or attribute name: function clearData(): void;|@ohos.hiviewdfx.hiAppEvent.d.ts|
|Deprecated version changed|Class name: bytrace<br>Deprecated version: N/A|Class name: bytrace<br>Deprecated version: 8<br>Substitute API: ohos.hiTraceMeter  |@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace<br>Method or attribute name: function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>Deprecated version: N/A|Class name: bytrace<br>Method or attribute name: function startTrace(name: string, taskId: number, expectedTime?: number): void;<br>Deprecated version: 8<br>Substitute API: ohos.hiTraceMeter.startTrace   |@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace<br>Method or attribute name: function finishTrace(name: string, taskId: number): void;<br>Deprecated version: N/A|Class name: bytrace<br>Method or attribute name: function finishTrace(name: string, taskId: number): void;<br>Deprecated version: 8<br>Substitute API: ohos.hiTraceMeter.finishTrace   |@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: bytrace<br>Method or attribute name: function traceByValue(name: string, count: number): void;<br>Deprecated version: N/A|Class name: bytrace<br>Method or attribute name: function traceByValue(name: string, count: number): void;<br>Deprecated version: 8<br>Substitute API: ohos.hiTraceMeter.traceByValue   |@ohos.bytrace.d.ts|
|Deprecated version changed|Class name: FaultLogger<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>Deprecated version: N/A|Class name: FaultLogger<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>Deprecated version: 9<br>Substitute API: ohos.faultlogger/FaultLogger|@ohos.faultLogger.d.ts|
|Deprecated version changed|Class name: FaultLogger<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>Deprecated version: N/A|Class name: FaultLogger<br>Method or attribute name: function querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>;<br>Deprecated version: 9<br>Substitute API: ohos.faultlogger/FaultLogger|@ohos.faultLogger.d.ts|
|Deprecated version changed|Class name: hiAppEvent<br>Deprecated version: N/A|Class name: hiAppEvent<br>Deprecated version: 9<br>Substitute API: ohos.hiviewdfx.hiAppEvent |@ohos.hiAppEvent.d.ts|
|Deprecated version changed|Class name: hichecker<br>Method or attribute name: function addRule(rule: bigint) : void;<br>Deprecated version: N/A|Class name: hichecker<br>Method or attribute name: function addRule(rule: bigint) : void;<br>Deprecated version: 9<br>Substitute API: ohos.hichecker/hichecker|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hichecker<br>Method or attribute name: function removeRule(rule: bigint) : void;<br>Deprecated version: N/A|Class name: hichecker<br>Method or attribute name: function removeRule(rule: bigint) : void;<br>Deprecated version: 9<br>Substitute API: ohos.hichecker/hichecker|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hichecker<br>Method or attribute name: function contains(rule: bigint) : boolean;<br>Deprecated version: N/A|Class name: hichecker<br>Method or attribute name: function contains(rule: bigint) : boolean;<br>Deprecated version: 9<br>Substitute API: ohos.hichecker/hichecker|@ohos.hichecker.d.ts|
|Deprecated version changed|Class name: hidebug<br>Method or attribute name: function startProfiling(filename : string) : void;<br>Deprecated version: N/A|Class name: hidebug<br>Method or attribute name: function startProfiling(filename : string) : void;<br>Deprecated version: 9<br>Substitute API: ohos.hidebug/hidebug.startJsCpuProfiling     |@ohos.hidebug.d.ts|
|Deprecated version changed|Class name: hidebug<br>Method or attribute name: function stopProfiling() : void;<br>Deprecated version: N/A|Class name: hidebug<br>Method or attribute name: function stopProfiling() : void;<br>Deprecated version: 9<br>Substitute API: ohos.hidebug/hidebug.stopJsCpuProfiling     |@ohos.hidebug.d.ts|
|Deprecated version changed|Class name: hidebug<br>Method or attribute name: function dumpHeapData(filename : string) : void;<br>Deprecated version: N/A|Class name: hidebug<br>Method or attribute name: function dumpHeapData(filename : string) : void;<br>Deprecated version: 9<br>Substitute API: ohos.hidebug/hidebug.dumpJsHeapData     |@ohos.hidebug.d.ts|
|Function changed|Class name: hiTraceChain<br>Method or attribute name: function begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId;<br>|Class name: hiTraceChain<br>Method or attribute name: function begin(name: string, flags?: number): HiTraceId;<br>|@ohos.hiTraceChain.d.ts|
