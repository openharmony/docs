| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.taskpool<br>类名: taskpool|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Priority|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Priority<br>方法 or 属性: HIGH|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Priority<br>方法 or 属性: MEDIUM|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Priority<br>方法 or 属性: LOW|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Task|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Task<br>方法 or 属性: constructor(func: Function, ...args: unknown[]);|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Task<br>方法 or 属性: function: Function;|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: Task<br>方法 or 属性: arguments?: unknown[];|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: taskpool<br>方法 or 属性: function execute(func: Function, ...args: unknown[]): Promise<unknown>;|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: taskpool<br>方法 or 属性: function execute(task: Task, priority?: Priority): Promise<unknown>;|@ohos.taskpool.d.ts|
|新增|NA|模块名: ohos.taskpool<br>类名: taskpool<br>方法 or 属性: function cancel(task: Task): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：URLParams<br>方法or属性：constructor(init?: string[][] \| Record<string, string> \| string \| URLParams);|@ohos.url.d.ts|
|新增|NA|类名：URL<br>方法or属性：readonly params: URLParams;|@ohos.url.d.ts|
|废弃版本有变化|类名：URL<br>方法 or 属性：readonly searchParams: URLSearchParams;<br>废弃版本：N/A|类名：URL<br>方法 or 属性：readonly searchParams: URLSearchParams;<br>废弃版本：9<br>代替接口：ohos.url.URL.params         |@ohos.url.d.ts|
|废弃版本有变化|类名：worker<br>方法 or 属性：const parentPort: DedicatedWorkerGlobalScope;<br>废弃版本：N/A|类名：worker<br>方法 or 属性：const parentPort: DedicatedWorkerGlobalScope;<br>废弃版本：9<br>代替接口：ohos.worker.workerPort   |@ohos.worker.d.ts|
|起始版本有变化|类名：URL<br>方法 or 属性：static parseURL(url: string, base?: string \| URL): URL;<br>起始版本：N/A|类名：URL<br>方法 or 属性：static parseURL(url: string, base?: string \| URL): URL;<br>起始版本：9|@ohos.url.d.ts|
|起始版本有变化|类名：worker<br>方法 or 属性：const parentPort: DedicatedWorkerGlobalScope;<br>起始版本：N/A|类名：worker<br>方法 or 属性：const parentPort: DedicatedWorkerGlobalScope;<br>起始版本：7|@ohos.worker.d.ts|
|起始版本有变化|类名：worker<br>方法 or 属性：const workerPort: ThreadWorkerGlobalScope;<br>起始版本：N/A|类名：worker<br>方法 or 属性：const workerPort: ThreadWorkerGlobalScope;<br>起始版本：9|@ohos.worker.d.ts|
|函数有变化|类名：DedicatedWorkerGlobalScope<br>方法 or 属性：onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent<T>) => void;<br>|类名：DedicatedWorkerGlobalScope<br>方法 or 属性：onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|函数有变化|类名：DedicatedWorkerGlobalScope<br>方法 or 属性：onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent<T>) => void;<br>|类名：DedicatedWorkerGlobalScope<br>方法 or 属性：onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|函数有变化|类名：Worker<br>方法 or 属性：onmessage?: (event: MessageEvent<T>) => void;<br>|类名：Worker<br>方法 or 属性：onmessage?: (event: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|函数有变化|类名：Worker<br>方法 or 属性：onmessageerror?: (event: MessageEvent<T>) => void;<br>|类名：Worker<br>方法 or 属性：onmessageerror?: (event: MessageEvent) => void;<br>|@ohos.worker.d.ts|
