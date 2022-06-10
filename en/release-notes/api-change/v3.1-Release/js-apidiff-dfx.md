# JS API Changes of the DFX Subsystem

The table below lists the APIs changes of the DFX subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.hiTraceMeter | hiTraceMeter | traceByValue(name: string, count: number): void; | Added|
| ohos.hiTraceMeter | hiTraceMeter | finishTrace(name: string, taskId: number): void; | Added|
| ohos.hiTraceMeter | hiTraceMeter | startTrace(name: string, taskId: number): void; | Added|
| ohos.hiTraceChain | hiTraceChain | enableFlag(id: HiTraceId, flag: HiTraceFlag): void; | Added|
| ohos.hiTraceChain | hiTraceChain | isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean; | Added|
| ohos.hiTraceChain | hiTraceChain | isValid(id: HiTraceId): boolean; | Added|
| ohos.hiTraceChain | hiTraceChain | tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void; | Added|
| ohos.hiTraceChain | hiTraceChain | createSpan(): HiTraceId; | Added|
| ohos.hiTraceChain | hiTraceChain | clearId(): void; | Added|
| ohos.hiTraceChain | hiTraceChain | setId(id: HiTraceId): void; | Added|
| ohos.hiTraceChain | hiTraceChain | getId(): HiTraceId; | Added|
| ohos.hiTraceChain | hiTraceChain | end(id: HiTraceId): void; | Added|
| ohos.hiTraceChain | hiTraceChain | begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId; | Added|
| ohos.hiTraceChain | HiTraceId | flags?: number; | Added|
| ohos.hiTraceChain | HiTraceId | parentSpanId?: number; | Added|
| ohos.hiTraceChain | HiTraceId | spanId?: number; | Added|
| ohos.hiTraceChain | HiTraceId | chainId: bigint; | Added|
| ohos.hiTraceChain | HiTraceCommunicationMode | DEVICE  = 3 | Added|
| ohos.hiTraceChain | HiTraceCommunicationMode | PROCESS = 2 | Added|
| ohos.hiTraceChain | HiTraceCommunicationMode | THREAD  = 1 | Added|
| ohos.hiTraceChain | HiTraceCommunicationMode | DEFAULT = 0 | Added|
| ohos.hiTraceChain | HiTraceTracepointType | GENERAL = 4 | Added|
| ohos.hiTraceChain | HiTraceTracepointType | SR = 3 | Added|
| ohos.hiTraceChain | HiTraceTracepointType | SS = 2 | Added|
| ohos.hiTraceChain | HiTraceTracepointType | CR = 1 | Added|
| ohos.hiTraceChain | HiTraceTracepointType | CS = 0 | Added|
| ohos.hiTraceChain | HiTraceFlag | D2D_TP_INFO       = 1 << 6 | Added|
| ohos.hiTraceChain | HiTraceFlag | FAILURE_TRIGGER   = 1 << 5 | Added|
| ohos.hiTraceChain | HiTraceFlag | DISABLE_LOG  = 1 << 4 | Added|
| ohos.hiTraceChain | HiTraceFlag | NO_BE_INFO        = 1 << 3 | Added|
| ohos.hiTraceChain | HiTraceFlag | TP_INFO           = 1 << 2 | Added|
| ohos.hiTraceChain | HiTraceFlag | DONOT_CREATE_SPAN = 1 << 1 | Added|
| ohos.hiTraceChain | HiTraceFlag | INCLUDE_ASYNC     = 1 | Added|
| ohos.hiTraceChain | HiTraceFlag | DEFAULT           = 0 | Added|
| ohos.hilog | LogLevel | FATAL = 7 | Added|
| ohos.hilog | LogLevel | ERROR = 6 | Added|
| ohos.hilog | LogLevel | WARN = 5 | Added|
| ohos.hilog | LogLevel | INFO = 4 | Added|
| ohos.hilog | LogLevel | DEBUG = 3 | Added|
| ohos.hilog | hilog | isLoggable(domain: number, tag: string, level: LogLevel) : boolean; | Added|
| ohos.hilog | hilog | fatal(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | error(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | warn(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | info(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | debug(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hidebug | hidebug | dumpHeapData(filename : string) : void; | Added|
| ohos.hidebug | hidebug | stopProfiling() : void; | Added|
| ohos.hidebug | hidebug | startProfiling(filename : string) : void; | Added|
| ohos.hidebug | hidebug | getSharedDirty() : bigint; | Added|
| ohos.hidebug | hidebug | getPss() : bigint; | Added|
| ohos.hidebug | hidebug | getNativeHeapFreeSize() : bigint; | Added|
| ohos.hidebug | hidebug | getNativeHeapAllocatedSize() : bigint; | Added|
| ohos.hidebug | hidebug | getNativeHeapSize() : bigint; | Added|
| ohos.hichecker | hichecker | contains(rule: bigint) : boolean; | Added|
| ohos.hichecker | hichecker | getRule() : bigint; | Added|
| ohos.hichecker | hichecker | removeRule(rule: bigint) : void; | Added|
| ohos.hichecker | hichecker | addRule(rule: bigint) : void; | Added|
| ohos.hichecker | hichecker | const RULE_CHECK_ABILITY_CONNECTION_LEAK: 8589934592n; | Added|
| ohos.hichecker | hichecker | const RULE_THREAD_CHECK_SLOW_PROCESS: 1n; | Added|
| ohos.hichecker | hichecker | const RULE_CAUTION_TRIGGER_CRASH: 4611686018427387904n; | Added|
| ohos.hichecker | hichecker | const RULE_CAUTION_PRINT_LOG: 9223372036854775808n; | Added|
| ohos.faultLogger | FaultLogInfo | fullLog: string; | Added|
| ohos.faultLogger | FaultLogInfo | summary: string; | Added|
| ohos.faultLogger | FaultLogInfo | module: string; | Added|
| ohos.faultLogger | FaultLogInfo | reason: string; | Added|
| ohos.faultLogger | FaultLogInfo | timestamp: number; | Added|
| ohos.faultLogger | FaultLogInfo | type: FaultType; | Added|
| ohos.faultLogger | FaultLogInfo | uid: number; | Added|
| ohos.faultLogger | FaultLogInfo | pid: number; | Added|
| ohos.faultLogger | FaultLogger | querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>; | Added|
| ohos.faultLogger | FaultType | APP_FREEZE = 4 | Added|
| ohos.faultLogger | FaultType | JS_CRASH = 3 | Added|
| ohos.faultLogger | FaultType | CPP_CRASH = 2 | Added|
| ohos.faultLogger | FaultType | NO_SPECIFIC = 0 | Added|
