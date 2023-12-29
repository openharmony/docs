| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: Config;<br>Method or attribute name: url: string;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: description?: string;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: title?: string;|@ohos.request.d.ts|
|Added|NA|Class name: FormItem;<br>Method or attribute name: name: string;|@ohos.request.d.ts|
|Added|NA|Class name: FileSpec;<br>Method or attribute name: path: string;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function create(context: BaseContext, config: Config, callback: AsyncCallback\<Task>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function create(context: BaseContext, config: Config): Promise\<Task>;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function remove(id: string, callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function remove(id: string): Promise\<void>;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function show(id: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function show(id: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function touch(id: string, token: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function touch(id: string, token: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function search(callback: AsyncCallback\<Array\<string>>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function search(filter: Filter, callback: AsyncCallback\<Array\<string>>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function search(filter?: Filter): Promise\<Array\<string>>;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function query(id: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|Added|NA|Class name: agent;<br>Method or attribute name: function query(id: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: DOWNLOAD|@ohos.request.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: UPLOAD|@ohos.request.d.ts|
|Added|NA|Class name: Mode;<br>Method or attribute name: BACKGROUND|@ohos.request.d.ts|
|Added|NA|Class name: Mode;<br>Method or attribute name: FOREGROUND|@ohos.request.d.ts|
|Added|NA|Class name: Network;<br>Method or attribute name: ANY|@ohos.request.d.ts|
|Added|NA|Class name: Network;<br>Method or attribute name: WIFI|@ohos.request.d.ts|
|Added|NA|Class name: Network;<br>Method or attribute name: CELLULAR|@ohos.request.d.ts|
|Added|NA|Class name: FileSpec;<br>Method or attribute name: mimeType?: string;|@ohos.request.d.ts|
|Added|NA|Class name: FileSpec;<br>Method or attribute name: filename?: string;|@ohos.request.d.ts|
|Added|NA|Class name: FileSpec;<br>Method or attribute name: extras?: object;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: extras?: object;|@ohos.request.d.ts|
|Added|NA|Class name: FormItem;<br>Method or attribute name: value: string \| FileSpec \| Array\<FileSpec>;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: action: Action;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: mode?: Mode;|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: mode?: Mode;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: overwrite?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: method?: string;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: headers?: object;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: data?: string \| Array\<FormItem>;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: saveas?: string;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: network?: Network;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: metered?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: roaming?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: retry?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: redirect?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: index?: number;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: begins?: number;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: ends?: number;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: gauge?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: precise?: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: Config;<br>Method or attribute name: token?: string;|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: INITIALIZED = 0x00|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: WAITING = 0x10|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: RUNNING = 0x20|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: RETRYING = 0x21|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: PAUSED = 0x30|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: STOPPED = 0x31|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: COMPLETED = 0x40|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: FAILED = 0x41|@ohos.request.d.ts|
|Added|NA|Class name: State;<br>Method or attribute name: REMOVED = 0x50|@ohos.request.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: readonly state: State;|@ohos.request.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: readonly index: number;|@ohos.request.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: readonly processed: number;|@ohos.request.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: readonly sizes: Array\<number>;|@ohos.request.d.ts|
|Added|NA|Class name: Progress;<br>Method or attribute name: readonly extras?: object;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly extras?: object;|@ohos.request.d.ts|
|Added|NA|Class name: Faults;<br>Method or attribute name: OTHERS = 0xFF|@ohos.request.d.ts|
|Added|NA|Class name: Faults;<br>Method or attribute name: DISCONNECTED = 0x00|@ohos.request.d.ts|
|Added|NA|Class name: Faults;<br>Method or attribute name: TIMEOUT = 0x10|@ohos.request.d.ts|
|Added|NA|Class name: Faults;<br>Method or attribute name: PROTOCOL = 0x20|@ohos.request.d.ts|
|Added|NA|Class name: Faults;<br>Method or attribute name: FSIO = 0x40|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: bundle?: string;|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: before?: number;|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: after?: number;|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: state?: State;|@ohos.request.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: action?: Action;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly uid?: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly bundle?: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly saveas?: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly url?: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly data?: string \| Array\<FormItem>;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly tid: string;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: readonly tid: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly title: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly description: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly action: Action;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly mode: Mode;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly mimeType: string;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly progress: Progress;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly gauge: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly ctime: number;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly mtime: number;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly retry: boolean;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly tries: number;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly faults: Faults;|@ohos.request.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: readonly reason: string;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: config: Config;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: on(event: 'progress', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: on(event: 'completed', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: on(event: 'failed', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: off(event: 'progress', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: off(event: 'completed', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: off(event: 'failed', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: start(): Promise\<void>;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: pause(): Promise\<void>;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: resume(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: resume(): Promise\<void>;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|Added|NA|Class name: Task;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.request.d.ts|
|Permission changed|Class name: request;<br>Method or attribute name: declare request<br>Old version information: ohos.permission.INTERNET|Class name: request;<br>Method or attribute name: declare request<br>New version information: |@ohos.request.d.ts|
