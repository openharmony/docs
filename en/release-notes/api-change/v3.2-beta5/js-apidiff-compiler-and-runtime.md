| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.taskpool<br>Class name: taskpool|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Priority|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Priority<br>Method or attribute name: HIGH|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Priority<br>Method or attribute name: MEDIUM|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Priority<br>Method or attribute name: LOW|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Task|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Task<br>Method or attribute name: constructor(func: Function, ...args: unknown[]);|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Task<br>Method or attribute name: function: Function;|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: Task<br>Method or attribute name: arguments?: unknown[];|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: taskpool<br>Method or attribute name: function execute(func: Function, ...args: unknown[]): Promise<unknown>;|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: taskpool<br>Method or attribute name: function execute(task: Task, priority?: Priority): Promise<unknown>;|@ohos.taskpool.d.ts|
|Added|NA|Module name: ohos.taskpool<br>Class name: taskpool<br>Method or attribute name: function cancel(task: Task): void;|@ohos.taskpool.d.ts|
|Added|NA|Class name: URLParams<br>Method or attribute name: constructor(init?: string[][] \| Record<string, string> \| string \| URLParams);|@ohos.url.d.ts|
|Added|NA|Class name: URL<br>Method or attribute name: readonly params: URLParams;|@ohos.url.d.ts|
|Deprecated version changed|Class name: URL<br>Method or attribute name: readonly searchParams: URLSearchParams;<br>Deprecated version: N/A|Class name: URL<br>Method or attribute name: readonly searchParams: URLSearchParams;<br>Deprecated version: 9<br>Substitute API: ohos.url.URL.params         |@ohos.url.d.ts|
|Deprecated version changed|Class name: worker<br>Method or attribute name: const parentPort: DedicatedWorkerGlobalScope;<br>Deprecated version: N/A|Class name: worker<br>Method or attribute name: const parentPort: DedicatedWorkerGlobalScope;<br>Deprecated version: 9<br>Substitute API: ohos.worker.workerPort   |@ohos.worker.d.ts|
|Initial version changed|Class name: URL<br>Method or attribute name: static parseURL(url: string, base?: string \| URL): URL;<br>Initial version: N/A|Class name: URL<br>Method or attribute name: static parseURL(url: string, base?: string \| URL): URL;<br>Initial version: 9|@ohos.url.d.ts|
|Initial version changed|Class name: worker<br>Method or attribute name: const parentPort: DedicatedWorkerGlobalScope;<br>Initial version: N/A|Class name: worker<br>Method or attribute name: const parentPort: DedicatedWorkerGlobalScope;<br>Initial version: 7|@ohos.worker.d.ts|
|Initial version changed|Class name: worker<br>Method or attribute name: const workerPort: ThreadWorkerGlobalScope;<br>Initial version: N/A|Class name: worker<br>Method or attribute name: const workerPort: ThreadWorkerGlobalScope;<br>Initial version: 9|@ohos.worker.d.ts|
|Function changed|Class name: DedicatedWorkerGlobalScope<br>Method or attribute name: onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent<T>) => void;<br>|Class name: DedicatedWorkerGlobalScope<br>Method or attribute name: onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|Function changed|Class name: DedicatedWorkerGlobalScope<br>Method or attribute name: onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent<T>) => void;<br>|Class name: DedicatedWorkerGlobalScope<br>Method or attribute name: onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|Function changed|Class name: Worker<br>Method or attribute name: onmessage?: (event: MessageEvent<T>) => void;<br>|Class name: Worker<br>Method or attribute name: onmessage?: (event: MessageEvent) => void;<br>|@ohos.worker.d.ts|
|Function changed|Class name: Worker<br>Method or attribute name: onmessageerror?: (event: MessageEvent<T>) => void;<br>|Class name: Worker<br>Method or attribute name: onmessageerror?: (event: MessageEvent) => void;<br>|@ohos.worker.d.ts|
