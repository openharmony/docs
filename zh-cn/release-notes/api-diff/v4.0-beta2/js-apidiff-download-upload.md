| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：agent;<br>方法or属性：function create(context: BaseContext, config: Config, callback: AsyncCallback\<Task>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function create(context: BaseContext, config: Config): Promise\<Task>;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function remove(id: string, callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function remove(id: string): Promise\<void>;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function show(id: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function show(id: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function touch(id: string, token: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function touch(id: string, token: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function search(filter: Filter, callback: AsyncCallback\<Array\<string>>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function search(filter: Filter): Promise\<Array\<string>>;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function query(id: string, callback: AsyncCallback\<TaskInfo>): void;|@ohos.request.d.ts|
|新增|NA|类名：agent;<br>方法or属性：function query(id: string): Promise\<TaskInfo>;|@ohos.request.d.ts|
|新增|NA|类名：Action;<br>方法or属性：DOWNLOAD|@ohos.request.d.ts|
|新增|NA|类名：Action;<br>方法or属性：UPLOAD|@ohos.request.d.ts|
|新增|NA|类名：Mode;<br>方法or属性：BACKGROUND|@ohos.request.d.ts|
|新增|NA|类名：Mode;<br>方法or属性：FOREGROUND|@ohos.request.d.ts|
|新增|NA|类名：Network;<br>方法or属性：ANY|@ohos.request.d.ts|
|新增|NA|类名：Network;<br>方法or属性：WIFI|@ohos.request.d.ts|
|新增|NA|类名：Network;<br>方法or属性：CELLULAR|@ohos.request.d.ts|
|新增|NA|类名：FileSpec;<br>方法or属性：path: string;|@ohos.request.d.ts|
|新增|NA|类名：FileSpec;<br>方法or属性：mimeType?: string;|@ohos.request.d.ts|
|新增|NA|类名：FileSpec;<br>方法or属性：filename?: string;|@ohos.request.d.ts|
|新增|NA|类名：FileSpec;<br>方法or属性：extras?: object;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：extras?: object;|@ohos.request.d.ts|
|新增|NA|类名：FormItem;<br>方法or属性：name: string;|@ohos.request.d.ts|
|新增|NA|类名：FormItem;<br>方法or属性：value: string \| FileSpec \| Array\<FileSpec>;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：action: Action;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：url: string;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：title?: string;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：description?: string;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：mode?: Mode;|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：mode?: Mode;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：overwrite?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：method?: string;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：headers?: object;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：data?: string \| Array\<FormItem>;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：saveas?: string;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：network?: Network;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：metered?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：roaming?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：retry?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：redirect?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：index?: number;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：begins?: number;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：ends?: number;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：gauge?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：precise?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：Config;<br>方法or属性：token?: string;|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：INITIALIZED = 0x00|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：WAITING = 0x10|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：RUNNING = 0x20|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：RETRYING = 0x21|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：PAUSED = 0x30|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：STOPPED = 0x31|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：COMPLETED = 0x40|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：FAILED = 0x41|@ohos.request.d.ts|
|新增|NA|类名：State;<br>方法or属性：REMOVED = 0x50|@ohos.request.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：readonly state: State;|@ohos.request.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：readonly index: number;|@ohos.request.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：readonly processed: number;|@ohos.request.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：readonly sizes: Array\<number>;|@ohos.request.d.ts|
|新增|NA|类名：Progress;<br>方法or属性：readonly extras?: object;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly extras?: object;|@ohos.request.d.ts|
|新增|NA|类名：Faults;<br>方法or属性：OTHERS = 0xFF|@ohos.request.d.ts|
|新增|NA|类名：Faults;<br>方法or属性：DISCONNECTED = 0x00|@ohos.request.d.ts|
|新增|NA|类名：Faults;<br>方法or属性：TIMEOUT = 0x10|@ohos.request.d.ts|
|新增|NA|类名：Faults;<br>方法or属性：PROTOCOL = 0x20|@ohos.request.d.ts|
|新增|NA|类名：Faults;<br>方法or属性：FSIO = 0x40|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：bundle?: string;|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：before?: number;|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：after?: number;|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：state?: State;|@ohos.request.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：action?: Action;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly uid?: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly bundle?: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly saveas?: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly url?: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly data?: string \| Array\<FormItem>;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly tid: string;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：readonly tid: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly title: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly description: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly action: Action;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly mode: Mode;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly mimeType: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly progress: Progress;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly gauge: boolean;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly ctime: number;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly mtime: number;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly retry: boolean;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly tries: number;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly faults: Faults;|@ohos.request.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：readonly reason: string;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：config: Config;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：on(event: 'progress', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：on(event: 'completed', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：on(event: 'failed', callback: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：off(event: 'progress', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：off(event: 'completed', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：off(event: 'failed', callback?: (progress: Progress) => void): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：start(): Promise\<void>;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：pause(): Promise\<void>;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：resume(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：resume(): Promise\<void>;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.request.d.ts|
|新增|NA|类名：Task;<br>方法or属性：stop(): Promise\<void>;|@ohos.request.d.ts|
|权限有变化|类名：request;<br>方法or属性：declare request<br>旧版本信息：ohos.permission.INTERNET|类名：request;<br>方法or属性：declare request<br>新版本信息：|@ohos.request.d.ts|
