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
