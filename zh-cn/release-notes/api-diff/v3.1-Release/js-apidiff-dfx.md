# DFX子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，DFX子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.hiTraceMeter | hiTraceMeter | traceByValue(name: string, count: number): void; | 新增 |
| ohos.hiTraceMeter | hiTraceMeter | finishTrace(name: string, taskId: number): void; | 新增 |
| ohos.hiTraceMeter | hiTraceMeter | startTrace(name: string, taskId: number): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | enableFlag(id: HiTraceId, flag: HiTraceFlag): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean; | 新增 |
| ohos.hiTraceChain | hiTraceChain | isValid(id: HiTraceId): boolean; | 新增 |
| ohos.hiTraceChain | hiTraceChain | tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | createSpan(): HiTraceId; | 新增 |
| ohos.hiTraceChain | hiTraceChain | clearId(): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | setId(id: HiTraceId): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | getId(): HiTraceId; | 新增 |
| ohos.hiTraceChain | hiTraceChain | end(id: HiTraceId): void; | 新增 |
| ohos.hiTraceChain | hiTraceChain | begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId; | 新增 |
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
| ohos.hilog | hilog | isLoggable(domain: number, tag: string, level: LogLevel) : boolean; | 新增 |
| ohos.hilog | hilog | fatal(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | error(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | warn(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | info(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hilog | hilog | debug(domain: number, tag: string, format: string, ...args: any[]) : void; | 新增 |
| ohos.hidebug | hidebug | dumpHeapData(filename : string) : void; | 新增 |
| ohos.hidebug | hidebug | stopProfiling() : void; | 新增 |
| ohos.hidebug | hidebug | startProfiling(filename : string) : void; | 新增 |
| ohos.hidebug | hidebug | getSharedDirty() : bigint; | 新增 |
| ohos.hidebug | hidebug | getPss() : bigint; | 新增 |
| ohos.hidebug | hidebug | getNativeHeapFreeSize() : bigint; | 新增 |
| ohos.hidebug | hidebug | getNativeHeapAllocatedSize() : bigint; | 新增 |
| ohos.hidebug | hidebug | getNativeHeapSize() : bigint; | 新增 |
| ohos.hichecker | hichecker | contains(rule: bigint) : boolean; | 新增 |
| ohos.hichecker | hichecker | getRule() : bigint; | 新增 |
| ohos.hichecker | hichecker | removeRule(rule: bigint) : void; | 新增 |
| ohos.hichecker | hichecker | addRule(rule: bigint) : void; | 新增 |
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
| ohos.faultLogger | FaultLogger | querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>) : void;<br>querySelfFaultLog(faultType: FaultType) : Promise\<Array\<FaultLogInfo>>; | 新增 |
| ohos.faultLogger | FaultType | APP_FREEZE = 4 | 新增 |
| ohos.faultLogger | FaultType | JS_CRASH = 3 | 新增 |
| ohos.faultLogger | FaultType | CPP_CRASH = 2 | 新增 |
| ohos.faultLogger | FaultType | NO_SPECIFIC = 0 | 新增 |
