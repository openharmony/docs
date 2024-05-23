| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Cross-platform permission changed|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: NA|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: crossplatform|api/@ohos.convertxml.d.ts|
|Cross-platform permission changed|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: NA|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: crossplatform|api/@ohos.util.d.ts|
|Cross-platform permission changed|Class name: WorkerEventTarget;<br>API declaration: addEventListener(type: string, listener: WorkerEventListener): void;<br>Differences: NA|Class name: WorkerEventTarget;<br>API declaration: addEventListener(type: string, listener: WorkerEventListener): void;<br>Differences: crossplatform|api/@ohos.worker.d.ts|
|SysCap changed|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: NA|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: SystemCapability.Utils.Lang|api/@ohos.convertxml.d.ts|
|SysCap changed|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: NA|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: SystemCapability.Utils.Lang|api/@ohos.util.d.ts|
|SysCap changed|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: NA|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|SysCap changed|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|SysCap changed|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: SystemCapability.Utils.Lang|api/@ohos.worker.d.ts|
|Deprecated version changed|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: NA|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: 9|api/@ohos.worker.d.ts|
|Deprecated version changed|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: 9|api/@ohos.worker.d.ts|
|Deprecated version changed|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: 9|api/@ohos.worker.d.ts|
|Error code changed|Class name: Task;<br>API declaration: setTransferList(transfer?: ArrayBuffer[]): void;<br>Differences: 401|Class name: Task;<br>API declaration: setTransferList(transfer?: ArrayBuffer[]): void;<br>Differences: 10200029, 401|api/@ohos.taskpool.d.ts|
|Function changed|Class name: taskpool;<br>API declaration: function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>Differences: Promise\<unknown>|Class name: taskpool;<br>API declaration: function execute(func: Function, ...args: Object[]): Promise\<Object>;<br>Differences: Promise\<Object>|api/@ohos.taskpool.d.ts|
|Function changed|Class name: taskpool;<br>API declaration: function execute(task: Task, priority?: Priority): Promise\<unknown>;<br>Differences: Promise\<unknown>|Class name: taskpool;<br>API declaration: function execute(task: Task, priority?: Priority): Promise\<Object>;<br>Differences: Promise\<Object>|api/@ohos.taskpool.d.ts|
|Function changed|Class name: taskpool;<br>API declaration: function execute(group: TaskGroup, priority?: Priority): Promise\<unknown[]>;<br>Differences: Promise\<unknown[]>|Class name: taskpool;<br>API declaration: function execute(group: TaskGroup, priority?: Priority): Promise\<Object[]>;<br>Differences: Promise\<Object[]>|api/@ohos.taskpool.d.ts|
|Function changed|Class name: TextEncoder;<br>API declaration: encodeIntoUint8Array(input: string, dest: Uint8Array): {<br>            read: number;<br>            written: number;<br>        };<br>Differences: {read:number;written:number;}|Class name: TextEncoder;<br>API declaration: encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo;<br>Differences: EncodeIntoUint8ArrayInfo|api/@ohos.util.d.ts|
|Function changed|Class name: TaskGroup;<br>API declaration: addTask(func: Function, ...args: unknown[]): void;<br>Differences: ...args: unknown[]|Class name: TaskGroup;<br>API declaration: addTask(func: Function, ...args: Object[]): void;<br>Differences: ...args: Object[]|api/@ohos.taskpool.d.ts|
|Function changed|Class name: taskpool;<br>API declaration: function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>Differences: ...args: unknown[]|Class name: taskpool;<br>API declaration: function execute(func: Function, ...args: Object[]): Promise\<Object>;<br>Differences: ...args: Object[]|api/@ohos.taskpool.d.ts|
|Function changed|Class name: TextDecoder;<br>API declaration: static create(encoding?: string, options?: {<br>            fatal?: boolean;<br>            ignoreBOM?: boolean;<br>        }): TextDecoder;<br>Differences: options?: {<br>            fatal?: boolean;<br>            ignoreBOM?: boolean;<br>        }|Class name: TextDecoder;<br>API declaration: static create(encoding?: string, options?: TextDecoderOptions): TextDecoder;<br>Differences: options?: TextDecoderOptions|api/@ohos.util.d.ts|
|Function changed|Class name: TextDecoder;<br>API declaration: decodeWithStream(input: Uint8Array, options?: {<br>            stream?: boolean;<br>        }): string;<br>Differences: options?: {<br>            stream?: boolean;<br>        }|Class name: TextDecoder;<br>API declaration: decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string;<br>Differences: options?: DecodeWithStreamOptions|api/@ohos.util.d.ts|
|Attribute changed|Class name: Task;<br>API declaration: arguments?: unknown[];<br>Differences: unknown[]|Class name: Task;<br>API declaration: arguments?: Object[];<br>Differences: Object[]|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: static sendData(...args: Object[]): void;<br>Differences: static sendData(...args: Object[]): void;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: setCloneList(cloneList: Object[] \| ArrayBuffer[]): void;<br>Differences: setCloneList(cloneList: Object[] \| ArrayBuffer[]): void;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: onReceiveData(callback?: Function): void;<br>Differences: onReceiveData(callback?: Function): void;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: addDependency(...tasks: Task[]): void;<br>Differences: addDependency(...tasks: Task[]): void;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: removeDependency(...tasks: Task[]): void;<br>Differences: removeDependency(...tasks: Task[]): void;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: name: string;<br>Differences: name: string;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: totalDuration: number;<br>Differences: totalDuration: number;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: ioDuration: number;<br>Differences: ioDuration: number;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: Task;<br>API declaration: cpuDuration: number;<br>Differences: cpuDuration: number;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: TaskGroup;<br>API declaration: name: string;<br>Differences: name: string;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: taskpool;<br>API declaration:  class SequenceRunner<br>Differences:  class SequenceRunner|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: SequenceRunner;<br>API declaration: execute(task: Task): Promise\<Object>;<br>Differences: execute(task: Task): Promise\<Object>;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: taskpool;<br>API declaration: function executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<Object>;<br>Differences: function executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<Object>;|api/@ohos.taskpool.d.ts|
|API added|NA|Class name: util;<br>API declaration:  interface TextDecoderOptions<br>Differences:  interface TextDecoderOptions|api/@ohos.util.d.ts|
|API added|NA|Class name: TextDecoderOptions;<br>API declaration: fatal?: boolean;<br>Differences: fatal?: boolean;|api/@ohos.util.d.ts|
|API added|NA|Class name: TextDecoderOptions;<br>API declaration: ignoreBOM?: boolean;<br>Differences: ignoreBOM?: boolean;|api/@ohos.util.d.ts|
|API added|NA|Class name: util;<br>API declaration:  interface DecodeWithStreamOptions<br>Differences:  interface DecodeWithStreamOptions|api/@ohos.util.d.ts|
|API added|NA|Class name: DecodeWithStreamOptions;<br>API declaration: stream?: boolean;<br>Differences: stream?: boolean;|api/@ohos.util.d.ts|
|API added|NA|Class name: util;<br>API declaration:  interface EncodeIntoUint8ArrayInfo<br>Differences:  interface EncodeIntoUint8ArrayInfo|api/@ohos.util.d.ts|
|API added|NA|Class name: EncodeIntoUint8ArrayInfo;<br>API declaration: read: number;<br>Differences: read: number;|api/@ohos.util.d.ts|
|API added|NA|Class name: EncodeIntoUint8ArrayInfo;<br>API declaration: written: number;<br>Differences: written: number;|api/@ohos.util.d.ts|
|API added|NA|Class name: util;<br>API declaration:  class Aspect<br>Differences:  class Aspect|api/@ohos.util.d.ts|
|API added|NA|Class name: Aspect;<br>API declaration: static addBefore(targetClass: Object, methodName: string, isStatic: boolean, before: Function): void;<br>Differences: static addBefore(targetClass: Object, methodName: string, isStatic: boolean, before: Function): void;|api/@ohos.util.d.ts|
|API added|NA|Class name: Aspect;<br>API declaration: static addAfter(targetClass: Object, methodName: string, isStatic: boolean, after: Function): void;<br>Differences: static addAfter(targetClass: Object, methodName: string, isStatic: boolean, after: Function): void;|api/@ohos.util.d.ts|
|API added|NA|Class name: Aspect;<br>API declaration: static replace(targetClass: Object, methodName: string, isStatic: boolean, instead: Function): void;<br>Differences: static replace(targetClass: Object, methodName: string, isStatic: boolean, instead: Function): void;|api/@ohos.util.d.ts|
|API added|NA|Class name: ThreadWorkerGlobalScope;<br>API declaration: callGlobalCallObjectMethod(instanceName: string, methodName: string, timeout: number, ...args: Object[]): Object;<br>Differences: callGlobalCallObjectMethod(instanceName: string, methodName: string, timeout: number, ...args: Object[]): Object;|api/@ohos.worker.d.ts|
|API added|NA|Class name: ThreadWorker;<br>API declaration: registerGlobalCallObject(instanceName: string, globalCallObject: Object): void;<br>Differences: registerGlobalCallObject(instanceName: string, globalCallObject: Object): void;|api/@ohos.worker.d.ts|
|API added|NA|Class name: ThreadWorker;<br>API declaration: unregisterGlobalCallObject(instanceName?: string): void;<br>Differences: unregisterGlobalCallObject(instanceName?: string): void;|api/@ohos.worker.d.ts|
|API added|NA|Class name: worker;<br>API declaration:  class RestrictedWorker<br>Differences:  class RestrictedWorker|api/@ohos.worker.d.ts|
|Initial version changed|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: NA|Class name: xml;<br>API declaration:  interface ConvertOptions<br>Differences: 8|api/@ohos.convertxml.d.ts|
|Initial version changed|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: NA|Class name: util;<br>API declaration:  interface ScopeComparable<br>Differences: 7|api/@ohos.util.d.ts|
|Initial version changed|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: NA|Class name: WorkerGlobalScope;<br>API declaration: readonly self: WorkerGlobalScope & typeof globalThis;<br>Differences: 7|api/@ohos.worker.d.ts|
|Initial version changed|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: DedicatedWorkerGlobalScope;<br>API declaration: postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>Differences: 7|api/@ohos.worker.d.ts|
|Initial version changed|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: NA|Class name: Worker;<br>API declaration: postMessage(message: Object, options?: PostMessageOptions): void;<br>Differences: 7|api/@ohos.worker.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.buffer.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.convertxml.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.process.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.taskpool.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.uri.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.url.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.ArrayList.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.Deque.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.HashMap.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.HashSet.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.LightWeightMap.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.LightWeightSet.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.LinkedList.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.List.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.PlainArray.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.Queue.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.Stack.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.TreeMap.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.TreeSet.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.util.Vector.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.worker.d.ts|
|Kit changed|NA|ArkTS|api/@ohos.xml.d.ts|
