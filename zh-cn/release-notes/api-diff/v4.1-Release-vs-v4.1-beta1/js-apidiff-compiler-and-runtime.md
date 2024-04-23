| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API跨平台权限变更|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：NA|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：crossplatform|api/@ohos.convertxml.d.ts|
|API跨平台权限变更|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：NA|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：crossplatform|api/@ohos.util.d.ts|
|syscap变更|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：NA|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：SystemCapability.Utils.Lang|api/@ohos.convertxml.d.ts|
|syscap变更|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：NA|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：SystemCapability.Utils.Lang|api/@ohos.util.d.ts|
|syscap变更|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：NA|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|syscap变更|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|syscap变更|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|API废弃版本变更|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：NA|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：9|api/@ohos.worker.d.ts|
|API废弃版本变更|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：9|api/@ohos.worker.d.ts|
|API废弃版本变更|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：9|api/@ohos.worker.d.ts|
|错误码变更|类名：Task；<br>API声明：setTransferList(transfer?: ArrayBuffer[]): void;<br>差异内容：401|类名：Task；<br>API声明：setTransferList(transfer?: ArrayBuffer[]): void;<br>差异内容：10200029,401|api/@ohos.taskpool.d.ts|
|函数变更|类名：taskpool；<br>API声明：function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>差异内容：Promise\<unknown>|类名：taskpool；<br>API声明：function execute(func: Function, ...args: Object[]): Promise\<Object>;<br>差异内容：Promise\<Object>|api/@ohos.taskpool.d.ts|
|函数变更|类名：taskpool；<br>API声明：function execute(task: Task, priority?: Priority): Promise\<unknown>;<br>差异内容：Promise\<unknown>|类名：taskpool；<br>API声明：function execute(task: Task, priority?: Priority): Promise\<Object>;<br>差异内容：Promise\<Object>|api/@ohos.taskpool.d.ts|
|函数变更|类名：taskpool；<br>API声明：function execute(group: TaskGroup, priority?: Priority): Promise\<unknown[]>;<br>差异内容：Promise\<unknown[]>|类名：taskpool；<br>API声明：function execute(group: TaskGroup, priority?: Priority): Promise\<Object[]>;<br>差异内容：Promise\<Object[]>|api/@ohos.taskpool.d.ts|
|函数变更|类名：TextEncoder；<br>API声明：encodeIntoUint8Array(input: string, dest: Uint8Array): {<br>            read: number;<br>            written: number;<br>        };<br>差异内容：{read:number;written:number;}|类名：TextEncoder；<br>API声明：encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo;<br>差异内容：EncodeIntoUint8ArrayInfo|api/@ohos.util.d.ts|
|函数变更|类名：TaskGroup；<br>API声明：addTask(func: Function, ...args: unknown[]): void;<br>差异内容：...args: unknown[]|类名：TaskGroup；<br>API声明：addTask(func: Function, ...args: Object[]): void;<br>差异内容：...args: Object[]|api/@ohos.taskpool.d.ts|
|函数变更|类名：taskpool；<br>API声明：function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>差异内容：...args: unknown[]|类名：taskpool；<br>API声明：function execute(func: Function, ...args: Object[]): Promise\<Object>;<br>差异内容：...args: Object[]|api/@ohos.taskpool.d.ts|
|函数变更|类名：TextDecoder；<br>API声明：static create(encoding?: string, options?: {<br>            fatal?: boolean;<br>            ignoreBOM?: boolean;<br>        }): TextDecoder;<br>差异内容：options?: {<br>            fatal?: boolean;<br>            ignoreBOM?: boolean;<br>        }|类名：TextDecoder；<br>API声明：static create(encoding?: string, options?: TextDecoderOptions): TextDecoder;<br>差异内容：options?: TextDecoderOptions|api/@ohos.util.d.ts|
|函数变更|类名：TextDecoder；<br>API声明：decodeWithStream(input: Uint8Array, options?: {<br>            stream?: boolean;<br>        }): string;<br>差异内容：options?: {<br>            stream?: boolean;<br>        }|类名：TextDecoder；<br>API声明：decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string;<br>差异内容：options?: DecodeWithStreamOptions|api/@ohos.util.d.ts|
|属性变更|类名：Task；<br>API声明：arguments?: unknown[];<br>差异内容：unknown[]|类名：Task；<br>API声明：arguments?: Object[];<br>差异内容：Object[]|api/@ohos.taskpool.d.ts|
|属性变更|类名：Task；<br>API声明：name: String;<br>差异内容：String|类名：Task；<br>API声明：name: string;<br>差异内容：string|api/@ohos.taskpool.d.ts|
|属性变更|类名：TaskGroup；<br>API声明：name: String;<br>差异内容：String|类名：TaskGroup；<br>API声明：name: string;<br>差异内容：string|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：Task；<br>API声明：setCloneList(cloneList: Object[] \| ArrayBuffer[]): void;<br>差异内容：setCloneList(cloneList: Object[] \| ArrayBuffer[]): void;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：Task；<br>API声明：totalDuration: number;<br>差异内容：totalDuration: number;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：Task；<br>API声明：ioDuration: number;<br>差异内容：ioDuration: number;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：Task；<br>API声明：cpuDuration: number;<br>差异内容：cpuDuration: number;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：taskpool；<br>API声明： class SequenceRunner<br>差异内容： class SequenceRunner|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：SequenceRunner；<br>API声明：execute(task: Task): Promise\<Object>;<br>差异内容：execute(task: Task): Promise\<Object>;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：taskpool；<br>API声明：function executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<Object>;<br>差异内容：function executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<Object>;|api/@ohos.taskpool.d.ts|
|新增API|NA|类名：util；<br>API声明： interface TextDecoderOptions<br>差异内容： interface TextDecoderOptions|api/@ohos.util.d.ts|
|新增API|NA|类名：TextDecoderOptions；<br>API声明：fatal?: boolean;<br>差异内容：fatal?: boolean;|api/@ohos.util.d.ts|
|新增API|NA|类名：TextDecoderOptions；<br>API声明：ignoreBOM?: boolean;<br>差异内容：ignoreBOM?: boolean;|api/@ohos.util.d.ts|
|新增API|NA|类名：util；<br>API声明： interface DecodeWithStreamOptions<br>差异内容： interface DecodeWithStreamOptions|api/@ohos.util.d.ts|
|新增API|NA|类名：DecodeWithStreamOptions；<br>API声明：stream?: boolean;<br>差异内容：stream?: boolean;|api/@ohos.util.d.ts|
|新增API|NA|类名：util；<br>API声明： interface EncodeIntoUint8ArrayInfo<br>差异内容： interface EncodeIntoUint8ArrayInfo|api/@ohos.util.d.ts|
|新增API|NA|类名：EncodeIntoUint8ArrayInfo；<br>API声明：read: number;<br>差异内容：read: number;|api/@ohos.util.d.ts|
|新增API|NA|类名：EncodeIntoUint8ArrayInfo；<br>API声明：written: number;<br>差异内容：written: number;|api/@ohos.util.d.ts|
|新增API|NA|类名：util；<br>API声明： class Aspect<br>差异内容： class Aspect|api/@ohos.util.d.ts|
|新增API|NA|类名：Aspect；<br>API声明：static addBefore(targetClass: Object, methodName: string, isStatic: boolean, before: Function): void;<br>差异内容：static addBefore(targetClass: Object, methodName: string, isStatic: boolean, before: Function): void;|api/@ohos.util.d.ts|
|新增API|NA|类名：Aspect；<br>API声明：static addAfter(targetClass: Object, methodName: string, isStatic: boolean, after: Function): void;<br>差异内容：static addAfter(targetClass: Object, methodName: string, isStatic: boolean, after: Function): void;|api/@ohos.util.d.ts|
|新增API|NA|类名：Aspect；<br>API声明：static replace(targetClass: Object, methodName: string, isStatic: boolean, instead: Function): void;<br>差异内容：static replace(targetClass: Object, methodName: string, isStatic: boolean, instead: Function): void;|api/@ohos.util.d.ts|
|起始版本有变化|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：NA|类名：xml；<br>API声明： interface ConvertOptions<br>差异内容：8|api/@ohos.convertxml.d.ts|
|起始版本有变化|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：NA|类名：util；<br>API声明： interface ScopeComparable<br>差异内容：7|api/@ohos.util.d.ts|
|起始版本有变化|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：NA|类名：WorkerGlobalScope；<br>API声明：readonly self: WorkerGlobalScope & typeof globalThis;<br>差异内容：7|api/@ohos.worker.d.ts|
|起始版本有变化|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：DedicatedWorkerGlobalScope；<br>API声明：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>差异内容：7|api/@ohos.worker.d.ts|
|起始版本有变化|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：NA|类名：Worker；<br>API声明：postMessage(message: Object, options?: PostMessageOptions): void;<br>差异内容：7|api/@ohos.worker.d.ts|
