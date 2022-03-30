# DFX子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，DFX子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.hiTraceMeter | hiTraceMeter | function traceByValue(name: string, count: number): void; | 新增 |
| ohos.hiTraceMeter | hiTraceMeter | function finishTrace(name: string, taskId: number): void; | 新增 |
| ohos.hiTraceMeter | hiTraceMeter | function startTrace(name: string, taskId: number): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function enableFlag(id: HiTraceId, flag: HiTraceFlag): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function isValid(id: HiTraceId): boolean; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function createSpan(): HiTraceId; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function clearId(): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function setId(id: HiTraceId): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function getId(): HiTraceId; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function end(id: HiTraceId): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | function begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId; | 新增 |
| ohos.hiTraceChain | HiTraceId | flags?: number; | 新增 |
| ohos.hiTraceChain | HiTraceId | parentSpanId?: number; | 新增 |
| ohos.hiTraceChain | HiTraceId | spanId?: number; | 新增 |
| ohos.hiTraceChain | HiTraceId | chainId: bigint; | 新增 |
| ohos.hiTraceChain | HiTraceCommunicationMode | DEVICE  = 3 | 新增 |
| ohos.hiTraceChain | HiTraceCommunicationMode | PROCESS = 2 | 新增 |
| ohos.hiTraceChain | HiTraceCommunicationMode | THREAD  = 1 | 新增 |
| ohos.hiTraceChain | HiTraceCommunicationMode | DEFAULT = 0 | 新增 |
| ohos.hiTraceChain | HiTraceTracepointType | GENERAL = 4 | 新增 |
| ohos.hiTraceChain | HiTraceTracepointType | SR = 3 | 新增 |
| ohos.hiTraceChain | HiTraceTracepointType | SS = 2 | 新增 |
| ohos.hiTraceChain | HiTraceTracepointType | CR = 1 | 新增 |
| ohos.hiTraceChain | HiTraceTracepointType | CS = 0 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | D2D_TP_INFO       = 1 << 6 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | FAILURE_TRIGGER   = 1 << 5 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | DISABLE_LOG  = 1 << 4 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | NO_BE_INFO        = 1 << 3 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | TP_INFO           = 1 << 2 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | DONOT_CREATE_SPAN = 1 << 1 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | INCLUDE_ASYNC     = 1 | 新增 |
| ohos.hiTraceChain | HiTraceFlag | DEFAULT           = 0 | 新增 |
| ohos.hilog | LogLevel | FATAL = 7 | 新增 |
| ohos.hilog | LogLevel | ERROR = 6 | 新增 |
| ohos.hilog | LogLevel | WARN = 5 | 新增 |
| ohos.hilog | LogLevel | INFO = 4 | 新增 |
| ohos.hilog | LogLevel | DEBUG = 3 | 新增 |
| ohos.hilog | hilog | function isLoggable(domain: number, tag: string, level: LogLevel) : boolean; | 新增 |
| ohos.hilog | hilog | function fatal(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | function error(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | function warn(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | function info(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | function debug(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hidebug | hidebug | function dumpHeapData(filename : string) : void; | 新增 |
| ohos.hidebug | hidebug | function stopProfiling() : void; | 新增 |
| ohos.hidebug | hidebug | function startProfiling(filename : string) : void; | 新增 |
| ohos.hidebug | hidebug | function getSharedDirty() : bigint; | 新增 |
| ohos.hidebug | hidebug | function getPss() : bigint; | 新增 |
| ohos.hidebug | hidebug | function getNativeHeapFreeSize() : bigint; | 新增 |
| ohos.hidebug | hidebug | function getNativeHeapAllocatedSize() : bigint; | 新增 |
| ohos.hidebug | hidebug | function getNativeHeapSize() : bigint; | 新增 |
| ohos.hichecker | hichecker | function contains(rule: bigint) : boolean; | 新增 |
| ohos.hichecker | hichecker | function getRule() : bigint; | 新增 |
| ohos.hichecker | hichecker | function removeRule(rule: bigint) : void; | 新增 |
| ohos.hichecker | hichecker | function addRule(rule: bigint) : void; | 新增 |
| ohos.hichecker | hichecker | const RULE_CHECK_ABILITY_CONNECTION_LEAK: 8589934592n; | 新增 |
| ohos.hichecker | hichecker | const RULE_THREAD_CHECK_SLOW_PROCESS: 1n; | 新增 |
| ohos.hichecker | hichecker | const RULE_CAUTION_TRIGGER_CRASH: 4611686018427387904n; | 新增 |
| ohos.hichecker | hichecker | const RULE_CAUTION_PRINT_LOG: 9223372036854775808n; | 新增 |
| ohos.faultLogger | FaultLogInfo | fullLog: string; | 新增 |
| ohos.faultLogger | FaultLogInfo | summary: string; | 新增 |
| ohos.faultLogger | FaultLogInfo | module: string; | 新增 |
| ohos.faultLogger | FaultLogInfo | reason: string; | 新增 |
| ohos.faultLogger | FaultLogInfo | timestamp: number; | 新增 |
| ohos.faultLogger | FaultLogInfo | type: FaultType; | 新增 |
| ohos.faultLogger | FaultLogInfo | uid: number; | 新增 |
| ohos.faultLogger | FaultLogInfo | pid: number; | 新增 |
| ohos.faultLogger | FaultLogger | function querySelfFaultLog(faultType: FaultType, callback: AsyncCallback<Array<FaultLogInfo>>) : void;<br>function querySelfFaultLog(faultType: FaultType) : Promise<Array<FaultLogInfo>>; | 新增 |
| ohos.faultLogger | FaultType | APP_FREEZE = 4 | 新增 |
| ohos.faultLogger | FaultType | JS_CRASH = 3 | 新增 |
| ohos.faultLogger | FaultType | CPP_CRASH = 2 | 新增 |
| ohos.faultLogger | FaultType | NO_SPECIFIC = 0 | 新增 |
