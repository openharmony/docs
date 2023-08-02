| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：ConditionType;<br>方法or属性：timeout?: number;|@ohos.process.d.ts|
|新增|NA|类名：ConditionType;<br>方法or属性：killSignal?: number \| string;|@ohos.process.d.ts|
|新增|NA|类名：ConditionType;<br>方法or属性：maxBuffer?: number;|@ohos.process.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function execute(group: TaskGroup, priority?: Priority): Promise\<unknown[]>;|@ohos.taskpool.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function cancel(group: TaskGroup): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function getTaskPoolInfo(): TaskPoolInfo;|@ohos.taskpool.d.ts|
|新增|NA|类名：Task;<br>方法or属性：static isCanceled(): boolean;|@ohos.taskpool.d.ts|
|新增|NA|类名：Task;<br>方法or属性：setTransferList(transfer?: ArrayBuffer[]): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskGroup;<br>方法or属性：constructor();|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskGroup;<br>方法or属性：addTask(func: Function, ...args: unknown[]): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskGroup;<br>方法or属性：addTask(task: Task): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：State;<br>方法or属性：WAITING = 1|@ohos.taskpool.d.ts|
|新增|NA|类名：State;<br>方法or属性：RUNNING = 2|@ohos.taskpool.d.ts|
|新增|NA|类名：State;<br>方法or属性：CANCELED = 3|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：taskId: number;|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：state: State;|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：duration?: number;|@ohos.taskpool.d.ts|
|新增|NA|类名：ThreadInfo;<br>方法or属性：tid: number;|@ohos.taskpool.d.ts|
|新增|NA|类名：ThreadInfo;<br>方法or属性：taskIds?: number[];|@ohos.taskpool.d.ts|
|新增|NA|类名：ThreadInfo;<br>方法or属性：priority?: Priority;|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskPoolInfo;<br>方法or属性：threadInfos: ThreadInfo[];|@ohos.taskpool.d.ts|
|新增|NA|类名：TaskPoolInfo;<br>方法or属性：taskInfos: TaskInfo[];|@ohos.taskpool.d.ts|
|新增|NA|类名：Type;<br>方法or属性：BASIC|@ohos.util.d.ts|
|新增|NA|类名：Type;<br>方法or属性：MIME|@ohos.util.d.ts|
|新增(错误码)|类名：WorkerEventListener;<br>方法or属性：(event: Event): void \| Promise\<void>;<br>旧版本信息：|类名：WorkerEventListener;<br>方法or属性：(event: Event): void \| Promise\<void>;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorker;<br>方法or属性：onexit?: (code: number) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onexit?: (code: number) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorker;<br>方法or属性：onmessage?: (event: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onmessage?: (event: MessageEvents) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|新增(错误码)|类名：ThreadWorker;<br>方法or属性：onmessageerror?: (event: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onmessageerror?: (event: MessageEvents) => void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|错误码有变化|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>旧版本信息：401,10200015,10200016|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>新版本信息：401,10200015|@ohos.taskpool.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：If|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：|@ohos.util.Vector.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>旧版本信息：If|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>新版本信息：|@ohos.util.Vector.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>旧版本信息：If|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>新版本信息：|@ohos.util.Vector.d.ts|
|错误码有变化|类名：WorkerEventTarget;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>旧版本信息：401,10200004|类名：WorkerEventTarget;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|错误码有变化|类名：ThreadWorker;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>旧版本信息：401,10200004|类名：ThreadWorker;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|错误码有变化|类名：ThreadWorker;<br>方法or属性：on(type: string, listener: WorkerEventListener): void;<br>旧版本信息：401,10200004|类名：ThreadWorker;<br>方法or属性：on(type: string, listener: WorkerEventListener): void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|错误码有变化|类名：ThreadWorker;<br>方法or属性：once(type: string, listener: WorkerEventListener): void;<br>旧版本信息：401,10200004|类名：ThreadWorker;<br>方法or属性：once(type: string, listener: WorkerEventListener): void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|错误码有变化|类名：ThreadWorker;<br>方法or属性：off(type: string, listener?: WorkerEventListener): void;<br>旧版本信息：401,10200004|类名：ThreadWorker;<br>方法or属性：off(type: string, listener?: WorkerEventListener): void;<br>新版本信息：401,10200004,10200005|@ohos.worker.d.ts|
|type有变化|类名：Task;<br>方法or属性：arguments?: unknown[];<br>旧版本信息：|类名：Task;<br>方法or属性：arguments?: unknown[];<br>新版本信息：?unknown[]|@ohos.taskpool.d.ts|
|函数有变化|类名：process;<br>方法or属性：function runCmd(command: string,<br><br>    options?: { timeout?: number, killSignal?: number \| string, maxBuffer?: number }): ChildProcess;|类名：process;<br>方法or属性：function runCmd(<br><br>    command: string,<br><br>    options?: ConditionType<br><br>  ): ChildProcess;|@ohos.process.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：HIGH|类名：Priority;<br>方法or属性：HIGH = 0|@ohos.taskpool.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：MEDIUM|类名：Priority;<br>方法or属性：MEDIUM = 1|@ohos.taskpool.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：LOW|类名：Priority;<br>方法or属性：LOW = 2|@ohos.taskpool.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array): string;|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array, options?: Type): string;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string): Uint8Array;|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string, options?: Type): Uint8Array;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array): Promise\<string>;|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array, options?: Type): Promise\<string>;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string): Promise\<Uint8Array>;|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>;|@ohos.util.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：type BufferEncoding =<br>    \| 'ascii'<br>    \| 'utf8'<br>    \| 'utf-8'<br>    \| 'utf16le'<br>    \| 'ucs2'<br>    \| 'ucs-2'<br>    \| 'base64'<br>    \| 'base64url'<br>    \| 'latin1'<br>    \| 'binary'<br>    \| 'hex';<br>旧版本信息：|类名：buffer;<br>方法or属性：type BufferEncoding =<br>    \| 'ascii'<br>    \| 'utf8'<br>    \| 'utf-8'<br>    \| 'utf16le'<br>    \| 'ucs2'<br>    \| 'ucs-2'<br>    \| 'base64'<br>    \| 'base64url'<br>    \| 'latin1'<br>    \| 'binary'<br>    \| 'hex';<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：TypedArray;<br>方法or属性：interface TypedArray<br>旧版本信息：|类名：TypedArray;<br>方法or属性：interface TypedArray<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：class Buffer<br>旧版本信息：|类名：Buffer;<br>方法or属性：class Buffer<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：class Blob<br>旧版本信息：|类名：Blob;<br>方法or属性：class Blob<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：type EventListener = (evt: Object) => void;<br>旧版本信息：|类名：process;<br>方法or属性：type EventListener = (evt: Object) => void;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function runCmd(<br><br>    command: string,<br><br>    options?: ConditionType<br><br>  ): ChildProcess;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function runCmd(<br><br>    command: string,<br><br>    options?: ConditionType<br><br>  ): ChildProcess;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function on(type: string, listener: EventListener): void;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function on(type: string, listener: EventListener): void;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function off(type: string): boolean;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function off(type: string): boolean;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function exit(code: number): void;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function exit(code: number): void;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function cwd(): string;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function cwd(): string;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function chdir(dir: string): void;<br>旧版本信息：crossplatform|类名：process;<br>方法or属性：function chdir(dir: string): void;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：export interface ChildProcess<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：export interface ChildProcess<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：readonly pid: number;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：readonly pid: number;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：readonly ppid: number;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：readonly ppid: number;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：readonly exitCode: number;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：readonly exitCode: number;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：readonly killed: boolean;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：readonly killed: boolean;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：wait(): Promise\<number>;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：wait(): Promise\<number>;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：getOutput(): Promise\<Uint8Array>;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：getOutput(): Promise\<Uint8Array>;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：getErrorOutput(): Promise\<Uint8Array>;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：getErrorOutput(): Promise\<Uint8Array>;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：close(): void;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：close(): void;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：ChildProcess;<br>方法or属性：kill(signal: number \| string): void;<br>旧版本信息：crossplatform|类名：ChildProcess;<br>方法or属性：kill(signal: number \| string): void;<br>新版本信息：|@ohos.process.d.ts|
|跨平台能力有变化|类名：taskpool;<br>方法or属性：declare taskpool<br>旧版本信息：|类名：taskpool;<br>方法or属性：declare taskpool<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：taskpool;<br>方法or属性：function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>旧版本信息：|类名：taskpool;<br>方法or属性：function execute(func: Function, ...args: unknown[]): Promise\<unknown>;<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：taskpool;<br>方法or属性：function execute(task: Task, priority?: Priority): Promise\<unknown>;<br>旧版本信息：|类名：taskpool;<br>方法or属性：function execute(task: Task, priority?: Priority): Promise\<unknown>;<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>旧版本信息：|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Priority;<br>方法or属性：enum Priority<br>旧版本信息：|类名：Priority;<br>方法or属性：enum Priority<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Priority;<br>方法or属性：HIGH = 0<br>旧版本信息：|类名：Priority;<br>方法or属性：HIGH = 0<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Priority;<br>方法or属性：MEDIUM = 1<br>旧版本信息：|类名：Priority;<br>方法or属性：MEDIUM = 1<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Priority;<br>方法or属性：LOW = 2<br>旧版本信息：|类名：Priority;<br>方法or属性：LOW = 2<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Task;<br>方法or属性：class Task<br>旧版本信息：|类名：Task;<br>方法or属性：class Task<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Task;<br>方法or属性：constructor(func: Function, ...args: unknown[]);<br>旧版本信息：|类名：Task;<br>方法or属性：constructor(func: Function, ...args: unknown[]);<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Task;<br>方法or属性：function: Function;<br>旧版本信息：|类名：Task;<br>方法or属性：function: Function;<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：Task;<br>方法or属性：arguments?: unknown[];<br>旧版本信息：|类名：Task;<br>方法or属性：arguments?: unknown[];<br>新版本信息：crossplatform|@ohos.taskpool.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：declare class ArrayList<br>旧版本信息：|类名：ArrayList;<br>方法or属性：declare class ArrayList<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：Scope;<br>方法or属性：class Scope<br>旧版本信息：crossplatform|类名：Scope;<br>方法or属性：class Scope<br>新版本信息：|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：getLower(): ScopeType;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：getLower(): ScopeType;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：declare class Deque<br>旧版本信息：|类名：Deque;<br>方法or属性：declare class Deque<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：declare class HashMap<br>旧版本信息：|类名：HashMap;<br>方法or属性：declare class HashMap<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：declare class HashSet<br>旧版本信息：|类名：HashSet;<br>方法or属性：declare class HashSet<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：declare class LightWeightMap<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：declare class LightWeightMap<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：declare class LightWeightSet<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：declare class LightWeightSet<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：declare class LinkedList<br>旧版本信息：|类名：LinkedList;<br>方法or属性：declare class LinkedList<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：declare class List<br>旧版本信息：|类名：List;<br>方法or属性：declare class List<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：declare class PlainArray<br>旧版本信息：|类名：PlainArray;<br>方法or属性：declare class PlainArray<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：declare class Queue<br>旧版本信息：|类名：Queue;<br>方法or属性：declare class Queue<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：declare class Stack<br>旧版本信息：|类名：Stack;<br>方法or属性：declare class Stack<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：declare class TreeMap<br>旧版本信息：|类名：TreeMap;<br>方法or属性：declare class TreeMap<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：declare class TreeSet<br>旧版本信息：|类名：TreeSet;<br>方法or属性：declare class TreeSet<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：WorkerEventTarget;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>旧版本信息：crossplatform|类名：WorkerEventTarget;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>新版本信息：|@ohos.worker.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：enum EventType<br>旧版本信息：|类名：EventType;<br>方法or属性：enum EventType<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：interface ParseInfo<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：interface ParseInfo<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：interface ParseOptions<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：interface ParseOptions<br>新版本信息：crossplatform|@ohos.xml.d.ts|
