# JS API Changes of the DFX Subsystem

The table below lists the APIs changes of the DFX subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.hiTraceMeter | hiTraceMeter | function traceByValue(name: string, count: number): void; | Added|
| ohos.hiTraceMeter | hiTraceMeter | function finishTrace(name: string, taskId: number): void; | Added|
| ohos.hiTraceMeter | hiTraceMeter | function startTrace(name: string, taskId: number): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function enableFlag(id: HiTraceId, flag: HiTraceFlag): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean; | Added|
| ohos.hiTraceChain | hiTraceChain | function isValid(id: HiTraceId): boolean; | Added|
| ohos.hiTraceChain | hiTraceChain | function tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function createSpan(): HiTraceId; | Added|
| ohos.hiTraceChain | hiTraceChain | function clearId(): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function setId(id: HiTraceId): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function getId(): HiTraceId; | Added|
| ohos.hiTraceChain | hiTraceChain | function end(id: HiTraceId): void; | Added|
| ohos.hiTraceChain | hiTraceChain | function begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId; | Added|
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
| ohos.hilog | hilog | function isLoggable(domain: number, tag: string, level: LogLevel) : boolean; | Added|
| ohos.hilog | hilog | function fatal(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | function error(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | function warn(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | function info(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hilog | hilog | function debug(domain: number, tag: string, format: string, ...args: any[]) : void; | Added|
| ohos.hidebug | hidebug | function dumpHeapData(filename : string) : void; | Added|
| ohos.hidebug | hidebug | function stopProfiling() : void; | Added|
| ohos.hidebug | hidebug | function startProfiling(filename : string) : void; | Added|
| ohos.hidebug | hidebug | function getSharedDirty() : bigint; | Added|
| ohos.hidebug | hidebug | function getPss() : bigint; | Added|
| ohos.hidebug | hidebug | function getNativeHeapFreeSize() : bigint; | Added|
| ohos.hidebug | hidebug | function getNativeHeapAllocatedSize() : bigint; | Added|
| ohos.hidebug | hidebug | function getNativeHeapSize() : bigint; | Added|
| ohos.hichecker | hichecker | function contains(rule: bigint) : boolean; | Added|
| ohos.hichecker | hichecker | function getRule() : bigint; | Added|
| ohos.hichecker | hichecker | function removeRule(rule: bigint) : void; | Added|
| ohos.hichecker | hichecker | function addRule(rule: bigint) : void; | Added|
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
| ohos.faultLogger | FaultLogger | function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback<Array<FaultLogInfo>>) : void;<br>function querySelfFaultLog(faultType: FaultType) : Promise<Array<FaultLogInfo>>; | Added|
| ohos.faultLogger | FaultType | APP_FREEZE = 4 | Added|
| ohos.faultLogger | FaultType | JS_CRASH = 3 | Added|
| ohos.faultLogger | FaultType | CPP_CRASH = 2 | Added|
| ohos.faultLogger | FaultType | NO_SPECIFIC = 0 | Added|
