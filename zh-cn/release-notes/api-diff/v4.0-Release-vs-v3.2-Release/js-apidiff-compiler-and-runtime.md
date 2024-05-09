| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sourcefile;<br>方法or属性：export declare function markModuleCollectable(namespace: Object): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static assert(value?: Object, ...arguments: Object[]): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static count(label?: string): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static countReset(label?: string): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static dir(dir?: Object): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static dirxml(...arguments: Object[]): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static group(...arguments: Object[]): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static groupCollapsed(...arguments: Object[]): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static groupEnd(): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static table(tableData?: Object): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static time(label?: string): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static timeEnd(label?: string): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static timeLog(label?: string, ...arguments: Object[]): void;|global.d.ts|
|新增|NA|类名：console;<br>方法or属性：static trace(...arguments: Object[]): void;|global.d.ts|
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
|错误码有变化|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>旧版本信息：401,10200015,10200016|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;<br>新版本信息：401,10200015|@ohos.taskpool.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：If|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：|@ohos.util.Vector.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>旧版本信息：If|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>新版本信息：|@ohos.util.Vector.d.ts|
|错误码有变化|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>旧版本信息：If|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>新版本信息：|@ohos.util.Vector.d.ts|
|type有变化|类名：Task;<br>方法or属性：arguments?: unknown[];<br>旧版本信息：|类名：Task;<br>方法or属性：arguments?: unknown[];<br>新版本信息：?unknown[]|@ohos.taskpool.d.ts|
|函数有变化|类名：process;<br>方法or属性：function runCmd(command: string,<br><br>        options?: { timeout?: number, killSignal?: number \| string, maxBuffer?: number }): ChildProcess;|类名：process;<br>方法or属性：function runCmd(<br><br>    command: string,<br><br>    options?: ConditionType<br><br>  ): ChildProcess;|@ohos.process.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：HIGH|类名：Priority;<br>方法or属性：HIGH = 0|@ohos.taskpool.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：MEDIUM|类名：Priority;<br>方法or属性：MEDIUM = 1|@ohos.taskpool.d.ts|
|函数有变化|类名：Priority;<br>方法or属性：LOW|类名：Priority;<br>方法or属性：LOW = 2|@ohos.taskpool.d.ts|
|函数有变化|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLSearchParams) => void, thisArg?: Object): void;|@ohos.url.d.ts|
|函数有变化|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void;|@ohos.url.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array): string;|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array, options?: Type): string;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string): Uint8Array;|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string, options?: Type): Uint8Array;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array): Promise\<string>;|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array, options?: Type): Promise\<string>;|@ohos.util.d.ts|
|函数有变化|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string): Promise\<Uint8Array>;|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>;|@ohos.util.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：declare buffer<br>旧版本信息：|类名：buffer;<br>方法or属性：declare buffer<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：type BufferEncoding =<br>    \| 'ascii'<br>    \| 'utf8'<br>    \| 'utf-8'<br>    \| 'utf16le'<br>    \| 'ucs2'<br>    \| 'ucs-2'<br>    \| 'base64'<br>    \| 'base64url'<br>    \| 'latin1'<br>    \| 'binary'<br>    \| 'hex';<br>旧版本信息：|类名：buffer;<br>方法or属性：type BufferEncoding =<br>    \| 'ascii'<br>    \| 'utf8'<br>    \| 'utf-8'<br>    \| 'utf16le'<br>    \| 'ucs2'<br>    \| 'ucs-2'<br>    \| 'base64'<br>    \| 'base64url'<br>    \| 'latin1'<br>    \| 'binary'<br>    \| 'hex';<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function alloc(size: number, fill?: string \| Buffer \| number, encoding?: BufferEncoding): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function alloc(size: number, fill?: string \| Buffer \| number, encoding?: BufferEncoding): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function allocUninitializedFromPool(size: number): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function allocUninitializedFromPool(size: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function allocUninitialized(size: number): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function allocUninitialized(size: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function byteLength(<br>    string: string \| Buffer \| TypedArray \| DataView \| ArrayBuffer \| SharedArrayBuffer,<br>    encoding?: BufferEncoding<br>  ): number;<br>旧版本信息：|类名：buffer;<br>方法or属性：function byteLength(<br>    string: string \| Buffer \| TypedArray \| DataView \| ArrayBuffer \| SharedArrayBuffer,<br>    encoding?: BufferEncoding<br>  ): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function concat(list: Buffer[] \| Uint8Array[], totalLength?: number): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function concat(list: Buffer[] \| Uint8Array[], totalLength?: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function from(array: number[]): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function from(array: number[]): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function from(arrayBuffer: ArrayBuffer \| SharedArrayBuffer, byteOffset?: number, length?: number): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function from(arrayBuffer: ArrayBuffer \| SharedArrayBuffer, byteOffset?: number, length?: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function from(buffer: Buffer \| Uint8Array): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function from(buffer: Buffer \| Uint8Array): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function from(object: Object, offsetOrEncoding: number \| string, length: number): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function from(object: Object, offsetOrEncoding: number \| string, length: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function from(string: String, encoding?: BufferEncoding): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function from(string: String, encoding?: BufferEncoding): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function isBuffer(obj: Object): boolean;<br>旧版本信息：|类名：buffer;<br>方法or属性：function isBuffer(obj: Object): boolean;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function isEncoding(encoding: string): boolean;<br>旧版本信息：|类名：buffer;<br>方法or属性：function isEncoding(encoding: string): boolean;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function compare(buf1: Buffer \| Uint8Array, buf2: Buffer \| Uint8Array): -1 \| 0 \| 1;<br>旧版本信息：|类名：buffer;<br>方法or属性：function compare(buf1: Buffer \| Uint8Array, buf2: Buffer \| Uint8Array): -1 \| 0 \| 1;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：buffer;<br>方法or属性：function transcode(source: Buffer \| Uint8Array, fromEnc: string, toEnc: string): Buffer;<br>旧版本信息：|类名：buffer;<br>方法or属性：function transcode(source: Buffer \| Uint8Array, fromEnc: string, toEnc: string): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：TypedArray;<br>方法or属性：interface TypedArray<br>旧版本信息：|类名：TypedArray;<br>方法or属性：interface TypedArray<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：class Buffer<br>旧版本信息：|类名：Buffer;<br>方法or属性：class Buffer<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：length: number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：buffer: ArrayBuffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：buffer: ArrayBuffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：byteOffset: number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：byteOffset: number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：fill(<br>      value: string \| Buffer \| Uint8Array \| number,<br>      offset?: number,<br>      end?: number,<br>      encoding?: BufferEncoding<br>    ): Buffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：fill(<br>      value: string \| Buffer \| Uint8Array \| number,<br>      offset?: number,<br>      end?: number,<br>      encoding?: BufferEncoding<br>    ): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：compare(<br>      target: Buffer \| Uint8Array,<br>      targetStart?: number,<br>      targetEnd?: number,<br>      sourceStart?: number,<br>      sourceEnd?: number<br>    ): -1 \| 0 \| 1;<br>旧版本信息：|类名：Buffer;<br>方法or属性：compare(<br>      target: Buffer \| Uint8Array,<br>      targetStart?: number,<br>      targetEnd?: number,<br>      sourceStart?: number,<br>      sourceEnd?: number<br>    ): -1 \| 0 \| 1;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：copy(target: Buffer \| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：copy(target: Buffer \| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：equals(otherBuffer: Uint8Array \| Buffer): boolean;<br>旧版本信息：|类名：Buffer;<br>方法or属性：equals(otherBuffer: Uint8Array \| Buffer): boolean;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：includes(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean;<br>旧版本信息：|类名：Buffer;<br>方法or属性：includes(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：indexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：indexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：keys(): IterableIterator\<number>;<br>旧版本信息：|类名：Buffer;<br>方法or属性：keys(): IterableIterator\<number>;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：values(): IterableIterator\<number>;<br>旧版本信息：|类名：Buffer;<br>方法or属性：values(): IterableIterator\<number>;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：entries(): IterableIterator\<[number, number]>;<br>旧版本信息：|类名：Buffer;<br>方法or属性：entries(): IterableIterator\<[number, number]>;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：lastIndexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：lastIndexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readBigInt64BE(offset?: number): bigint;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readBigInt64BE(offset?: number): bigint;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readBigInt64LE(offset?: number): bigint;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readBigInt64LE(offset?: number): bigint;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readBigUInt64BE(offset?: number): bigint;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readBigUInt64BE(offset?: number): bigint;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readBigUInt64LE(offset?: number): bigint;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readBigUInt64LE(offset?: number): bigint;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readDoubleBE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readDoubleBE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readDoubleLE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readDoubleLE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readFloatBE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readFloatBE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readFloatLE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readFloatLE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readInt8(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readInt8(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readInt16BE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readInt16BE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readInt16LE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readInt16LE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readInt32BE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readInt32BE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readInt32LE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readInt32LE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readIntBE(offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readIntBE(offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readIntLE(offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readIntLE(offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUInt8(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUInt8(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUInt16BE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUInt16BE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUInt16LE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUInt16LE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUInt32BE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUInt32BE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUInt32LE(offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUInt32LE(offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUIntBE(offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUIntBE(offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：readUIntLE(offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：readUIntLE(offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：subarray(start?: number, end?: number): Buffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：subarray(start?: number, end?: number): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：swap16(): Buffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：swap16(): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：swap32(): Buffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：swap32(): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：swap64(): Buffer;<br>旧版本信息：|类名：Buffer;<br>方法or属性：swap64(): Buffer;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：toJSON(): Object;<br>旧版本信息：|类名：Buffer;<br>方法or属性：toJSON(): Object;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：toString(encoding?: string, start?: number, end?: number): string;<br>旧版本信息：|类名：Buffer;<br>方法or属性：toString(encoding?: string, start?: number, end?: number): string;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：write(str: string, offset?: number, length?: number, encoding?: string): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：write(str: string, offset?: number, length?: number, encoding?: string): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeBigInt64BE(value: bigint, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeBigInt64BE(value: bigint, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeBigInt64LE(value: bigint, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeBigInt64LE(value: bigint, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeBigUInt64BE(value: bigint, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeBigUInt64BE(value: bigint, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeBigUInt64LE(value: bigint, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeBigUInt64LE(value: bigint, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeDoubleBE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeDoubleBE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeDoubleLE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeDoubleLE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeFloatBE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeFloatBE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeFloatLE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeFloatLE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeInt8(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeInt8(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeInt16BE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeInt16BE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeInt16LE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeInt16LE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeInt32BE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeInt32BE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeInt32LE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeInt32LE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeIntBE(value: number, offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeIntBE(value: number, offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeIntLE(value: number, offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeIntLE(value: number, offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUInt8(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUInt8(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUInt16BE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUInt16BE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUInt16LE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUInt16LE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUInt32BE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUInt32BE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUInt32LE(value: number, offset?: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUInt32LE(value: number, offset?: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUIntBE(value: number, offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUIntBE(value: number, offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Buffer;<br>方法or属性：writeUIntLE(value: number, offset: number, byteLength: number): number;<br>旧版本信息：|类名：Buffer;<br>方法or属性：writeUIntLE(value: number, offset: number, byteLength: number): number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：class Blob<br>旧版本信息：|类名：Blob;<br>方法or属性：class Blob<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：constructor(sources: string[] \| ArrayBuffer[] \| TypedArray[] \| DataView[] \| Blob[], options?: Object);<br>旧版本信息：|类名：Blob;<br>方法or属性：constructor(sources: string[] \| ArrayBuffer[] \| TypedArray[] \| DataView[] \| Blob[], options?: Object);<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：size: number;<br>旧版本信息：|类名：Blob;<br>方法or属性：size: number;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：type: string;<br>旧版本信息：|类名：Blob;<br>方法or属性：type: string;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：arrayBuffer(): Promise\<ArrayBuffer>;<br>旧版本信息：|类名：Blob;<br>方法or属性：arrayBuffer(): Promise\<ArrayBuffer>;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：slice(start?: number, end?: number, type?: string): Blob;<br>旧版本信息：|类名：Blob;<br>方法or属性：slice(start?: number, end?: number, type?: string): Blob;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：Blob;<br>方法or属性：text(): Promise\<string>;<br>旧版本信息：|类名：Blob;<br>方法or属性：text(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.buffer.d.ts|
|跨平台能力有变化|类名：xml;<br>方法or属性：declare xml<br>旧版本信息：|类名：xml;<br>方法or属性：declare xml<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：trim: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：trim: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreDeclaration?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreDeclaration?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreInstruction?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreInstruction?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreAttributes?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreAttributes?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreComment?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreComment?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreCDATA?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreCDATA?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreDoctype?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreDoctype?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：ignoreText?: boolean;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：ignoreText?: boolean;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：declarationKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：declarationKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：instructionKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：instructionKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：attributesKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：attributesKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：textKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：textKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：cdataKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：cdataKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：doctypeKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：doctypeKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：commentKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：commentKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：parentKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：parentKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：typeKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：typeKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：nameKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：nameKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertOptions;<br>方法or属性：elementsKey: string;<br>旧版本信息：|类名：ConvertOptions;<br>方法or属性：elementsKey: string;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertXML;<br>方法or属性：class ConvertXML<br>旧版本信息：|类名：ConvertXML;<br>方法or属性：class ConvertXML<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：ConvertXML;<br>方法or属性：convertToJSObject(xml: string, options?: ConvertOptions): Object;<br>旧版本信息：|类名：ConvertXML;<br>方法or属性：convertToJSObject(xml: string, options?: ConvertOptions): Object;<br>新版本信息：crossplatform|@ohos.convertxml.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：declare process<br>旧版本信息：|类名：process;<br>方法or属性：declare process<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function is64Bit(): boolean;<br>旧版本信息：|类名：process;<br>方法or属性：function is64Bit(): boolean;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function getStartRealtime(): number;<br>旧版本信息：|类名：process;<br>方法or属性：function getStartRealtime(): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function getPastCpuTime(): number;<br>旧版本信息：|类名：process;<br>方法or属性：function getPastCpuTime(): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：type EventListener = (evt: Object) => void;<br>旧版本信息：|类名：process;<br>方法or属性：type EventListener = (evt: Object) => void;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function abort(): void;<br>旧版本信息：|类名：process;<br>方法or属性：function abort(): void;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：process;<br>方法or属性：function uptime(): number;<br>旧版本信息：|类名：process;<br>方法or属性：function uptime(): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：export class ProcessManager<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：export class ProcessManager<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：isAppUid(v: number): boolean;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：isAppUid(v: number): boolean;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：getUidForName(v: string): number;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：getUidForName(v: string): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：getThreadPriority(v: number): number;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：getThreadPriority(v: number): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：getSystemConfig(name: number): number;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：getSystemConfig(name: number): number;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：getEnvironmentVar(name: string): string;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：getEnvironmentVar(name: string): string;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：exit(code: number): void;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：exit(code: number): void;<br>新版本信息：crossplatform|@ohos.process.d.ts|
|跨平台能力有变化|类名：ProcessManager;<br>方法or属性：kill(signal: number, pid: number): boolean;<br>旧版本信息：|类名：ProcessManager;<br>方法or属性：kill(signal: number, pid: number): boolean;<br>新版本信息：crossplatform|@ohos.process.d.ts|
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
|跨平台能力有变化|类名：uri;<br>方法or属性：declare uri<br>旧版本信息：|类名：uri;<br>方法or属性：declare uri<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：class URI<br>旧版本信息：|类名：URI;<br>方法or属性：class URI<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：constructor(uri: string);<br>旧版本信息：|类名：URI;<br>方法or属性：constructor(uri: string);<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：URI;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：equalsTo(other: URI): boolean;<br>旧版本信息：|类名：URI;<br>方法or属性：equalsTo(other: URI): boolean;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：checkIsAbsolute(): boolean;<br>旧版本信息：|类名：URI;<br>方法or属性：checkIsAbsolute(): boolean;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：normalize(): URI;<br>旧版本信息：|类名：URI;<br>方法or属性：normalize(): URI;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：scheme: string;<br>旧版本信息：|类名：URI;<br>方法or属性：scheme: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：userInfo: string;<br>旧版本信息：|类名：URI;<br>方法or属性：userInfo: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：host: string;<br>旧版本信息：|类名：URI;<br>方法or属性：host: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：port: string;<br>旧版本信息：|类名：URI;<br>方法or属性：port: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：path: string;<br>旧版本信息：|类名：URI;<br>方法or属性：path: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：query: string;<br>旧版本信息：|类名：URI;<br>方法or属性：query: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：fragment: string;<br>旧版本信息：|类名：URI;<br>方法or属性：fragment: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：authority: string;<br>旧版本信息：|类名：URI;<br>方法or属性：authority: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：URI;<br>方法or属性：ssp: string;<br>旧版本信息：|类名：URI;<br>方法or属性：ssp: string;<br>新版本信息：crossplatform|@ohos.uri.d.ts|
|跨平台能力有变化|类名：url;<br>方法or属性：declare url<br>旧版本信息：|类名：url;<br>方法or属性：declare url<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：class URLParams<br>旧版本信息：|类名：URLParams;<br>方法or属性：class URLParams<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：constructor(init?: string[][] \| Record\<string, string> \| string \| URLParams);<br>旧版本信息：|类名：URLParams;<br>方法or属性：constructor(init?: string[][] \| Record\<string, string> \| string \| URLParams);<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：append(name: string, value: string): void;<br>旧版本信息：|类名：URLParams;<br>方法or属性：append(name: string, value: string): void;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：delete(name: string): void;<br>旧版本信息：|类名：URLParams;<br>方法or属性：delete(name: string): void;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：getAll(name: string): string[];<br>旧版本信息：|类名：URLParams;<br>方法or属性：getAll(name: string): string[];<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：entries(): IterableIterator\<[string, string]>;<br>旧版本信息：|类名：URLParams;<br>方法or属性：entries(): IterableIterator\<[string, string]>;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void;<br>旧版本信息：|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：get(name: string): string \| null;<br>旧版本信息：|类名：URLParams;<br>方法or属性：get(name: string): string \| null;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：has(name: string): boolean;<br>旧版本信息：|类名：URLParams;<br>方法or属性：has(name: string): boolean;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：set(name: string, value: string): void;<br>旧版本信息：|类名：URLParams;<br>方法or属性：set(name: string, value: string): void;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：sort(): void;<br>旧版本信息：|类名：URLParams;<br>方法or属性：sort(): void;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：keys(): IterableIterator\<string>;<br>旧版本信息：|类名：URLParams;<br>方法or属性：keys(): IterableIterator\<string>;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：values(): IterableIterator\<string>;<br>旧版本信息：|类名：URLParams;<br>方法or属性：values(): IterableIterator\<string>;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[string, string]>;<br>旧版本信息：|类名：URLParams;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[string, string]>;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URLParams;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：URLParams;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：URL;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：class URL<br>旧版本信息：|类名：URL;<br>方法or属性：class URL<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：constructor();<br>旧版本信息：|类名：URL;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：static parseURL(url: string, base?: string \| URL): URL;<br>旧版本信息：|类名：URL;<br>方法or属性：static parseURL(url: string, base?: string \| URL): URL;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：toJSON(): string;<br>旧版本信息：|类名：URL;<br>方法or属性：toJSON(): string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：hash: string;<br>旧版本信息：|类名：URL;<br>方法or属性：hash: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：host: string;<br>旧版本信息：|类名：URL;<br>方法or属性：host: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：hostname: string;<br>旧版本信息：|类名：URL;<br>方法or属性：hostname: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：href: string;<br>旧版本信息：|类名：URL;<br>方法or属性：href: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：readonly origin: string;<br>旧版本信息：|类名：URL;<br>方法or属性：readonly origin: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：password: string;<br>旧版本信息：|类名：URL;<br>方法or属性：password: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：pathname: string;<br>旧版本信息：|类名：URL;<br>方法or属性：pathname: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：port: string;<br>旧版本信息：|类名：URL;<br>方法or属性：port: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：protocol: string;<br>旧版本信息：|类名：URL;<br>方法or属性：protocol: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：search: string;<br>旧版本信息：|类名：URL;<br>方法or属性：search: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：readonly params: URLParams;<br>旧版本信息：|类名：URL;<br>方法or属性：readonly params: URLParams;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：URL;<br>方法or属性：username: string;<br>旧版本信息：|类名：URL;<br>方法or属性：username: string;<br>新版本信息：crossplatform|@ohos.url.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：declare class ArrayList<br>旧版本信息：|类名：ArrayList;<br>方法or属性：declare class ArrayList<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：constructor();<br>旧版本信息：|类名：ArrayList;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：length: number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：add(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：has(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T, thisArg?: Object): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：clone(): ArrayList\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：clone(): ArrayList\<T>;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getCapacity(): number;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：trimToCurrentLength(): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：trimToCurrentLength(): void;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：ArrayList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.ArrayList.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：declare util<br>旧版本信息：|类名：util;<br>方法or属性：declare util<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function format(format: string, ...args: Object[]): string;<br>旧版本信息：|类名：util;<br>方法or属性：function format(format: string, ...args: Object[]): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function errnoToString(errno: number): string;<br>旧版本信息：|类名：util;<br>方法or属性：function errnoToString(errno: number): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function callbackWrapper(original: Function): (err: Object, value: Object) => void;<br>旧版本信息：|类名：util;<br>方法or属性：function callbackWrapper(original: Function): (err: Object, value: Object) => void;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function promisify(original: (err: Object, value: Object) => void): Function;<br>旧版本信息：|类名：util;<br>方法or属性：function promisify(original: (err: Object, value: Object) => void): Function;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function generateRandomUUID(entropyCache?: boolean): string;<br>旧版本信息：|类名：util;<br>方法or属性：function generateRandomUUID(entropyCache?: boolean): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array;<br>旧版本信息：|类名：util;<br>方法or属性：function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：function parseUUID(uuid: string): Uint8Array;<br>旧版本信息：|类名：util;<br>方法or属性：function parseUUID(uuid: string): Uint8Array;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：util;<br>方法or属性：type ScopeType = ScopeComparable \| number;<br>旧版本信息：|类名：util;<br>方法or属性：type ScopeType = ScopeComparable \| number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：class TextDecoder<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：class TextDecoder<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：readonly encoding: string;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：readonly encoding: string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：readonly fatal: boolean;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：readonly fatal: boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：readonly ignoreBOM = false;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：readonly ignoreBOM = false;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：constructor();<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：constructor();<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：constructor();<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：constructor();<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：constructor();<br>旧版本信息：|类名：types;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：static create(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean }): TextDecoder;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：static create(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean }): TextDecoder;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextDecoder;<br>方法or属性：decodeWithStream(input: Uint8Array, options?: { stream?: boolean }): string;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：decodeWithStream(input: Uint8Array, options?: { stream?: boolean }): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：class TextEncoder<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：class TextEncoder<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：readonly encoding = 'utf-8';<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：readonly encoding = 'utf-8';<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：constructor(encoding?: string);<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：constructor(encoding?: string);<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：encodeInto(input?: string): Uint8Array;<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：encodeInto(input?: string): Uint8Array;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：TextEncoder;<br>方法or属性：encodeIntoUint8Array(input: string, dest: Uint8Array): { read: number; written: number };<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：encodeIntoUint8Array(input: string, dest: Uint8Array): { read: number; written: number };<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：class RationalNumber<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：class RationalNumber<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：static parseRationalNumber(numerator: number, denominator: number): RationalNumber;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：static parseRationalNumber(numerator: number, denominator: number): RationalNumber;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：static createRationalFromString(rationalString: string): RationalNumber;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：static createRationalFromString(rationalString: string): RationalNumber;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：compare(another: RationalNumber): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：compare(another: RationalNumber): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：equals(obj: Object): boolean;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：equals(obj: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：valueOf(): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：valueOf(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：static getCommonFactor(number1: number, number2: number): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：static getCommonFactor(number1: number, number2: number): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：getDenominator(): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：getDenominator(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：getNumerator(): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：getNumerator(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：isFinite(): boolean;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：isFinite(): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：isNaN(): boolean;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：isNaN(): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：isZero(): boolean;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：isZero(): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：RationalNumber;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：class LRUCache<br>旧版本信息：|类名：LRUCache;<br>方法or属性：class LRUCache<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：constructor(capacity?: number);<br>旧版本信息：|类名：LRUCache;<br>方法or属性：constructor(capacity?: number);<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：updateCapacity(newCapacity: number): void;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：updateCapacity(newCapacity: number): void;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：length: number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getCapacity(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getCreateCount(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getCreateCount(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getMissCount(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getMissCount(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getRemovalCount(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getRemovalCount(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getMatchCount(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getMatchCount(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：getPutCount(): number;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：getPutCount(): number;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：get(key: K): V \| undefined;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：get(key: K): V \| undefined;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：put(key: K, value: V): V;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：put(key: K, value: V): V;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：values(): V[];<br>旧版本信息：|类名：LRUCache;<br>方法or属性：values(): V[];<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：keys(): K[];<br>旧版本信息：|类名：LRUCache;<br>方法or属性：keys(): K[];<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：remove(key: K): V \| undefined;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：remove(key: K): V \| undefined;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：contains(key: K): boolean;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：contains(key: K): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：createDefault(key: K): V;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：createDefault(key: K): V;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：LRUCache;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LRUCache;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeComparable;<br>方法or属性：compareTo(other: ScopeComparable): boolean;<br>旧版本信息：|类名：ScopeComparable;<br>方法or属性：compareTo(other: ScopeComparable): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：class ScopeHelper<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：class ScopeHelper<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：constructor(lowerObj: ScopeType, upperObj: ScopeType);<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：constructor(lowerObj: ScopeType, upperObj: ScopeType);<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：intersect(range: ScopeHelper): ScopeHelper;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：intersect(range: ScopeHelper): ScopeHelper;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：intersect(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：intersect(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：getUpper(): ScopeType;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：getUpper(): ScopeType;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：getLower(): ScopeType;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：getLower(): ScopeType;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：expand(range: ScopeHelper): ScopeHelper;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：expand(range: ScopeHelper): ScopeHelper;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：expand(value: ScopeType): ScopeHelper;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：expand(value: ScopeType): ScopeHelper;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：contains(value: ScopeType): boolean;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：contains(value: ScopeType): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：contains(range: ScopeHelper): boolean;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：contains(range: ScopeHelper): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：ScopeHelper;<br>方法or属性：clamp(value: ScopeType): ScopeType;<br>旧版本信息：|类名：ScopeHelper;<br>方法or属性：clamp(value: ScopeType): ScopeType;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：class Base64Helper<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：class Base64Helper<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：encodeSync(src: Uint8Array): Uint8Array;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：encodeSync(src: Uint8Array): Uint8Array;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array, options?: Type): string;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array, options?: Type): string;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string, options?: Type): Uint8Array;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string, options?: Type): Uint8Array;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：encode(src: Uint8Array): Promise\<Uint8Array>;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：encode(src: Uint8Array): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array, options?: Type): Promise\<string>;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array, options?: Type): Promise\<string>;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>;<br>旧版本信息：|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：class types<br>旧版本信息：|类名：types;<br>方法or属性：class types<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isAnyArrayBuffer(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isAnyArrayBuffer(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isArrayBufferView(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isArrayBufferView(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isArgumentsObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isArgumentsObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isArrayBuffer(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isArrayBuffer(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isAsyncFunction(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isAsyncFunction(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isBigInt64Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isBigInt64Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isBigUint64Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isBigUint64Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isBooleanObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isBooleanObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isBoxedPrimitive(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isBoxedPrimitive(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isDataView(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isDataView(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isDate(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isDate(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isExternal(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isExternal(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isFloat32Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isFloat32Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isFloat64Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isFloat64Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isGeneratorFunction(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isGeneratorFunction(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isGeneratorObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isGeneratorObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isInt8Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isInt8Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isInt16Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isInt16Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isInt32Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isInt32Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isMap(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isMap(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isMapIterator(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isMapIterator(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isModuleNamespaceObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isModuleNamespaceObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isNativeError(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isNativeError(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isNumberObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isNumberObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isPromise(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isPromise(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isProxy(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isProxy(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isRegExp(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isRegExp(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isSet(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isSet(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isSetIterator(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isSetIterator(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isSharedArrayBuffer(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isSharedArrayBuffer(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isStringObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isStringObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isSymbolObject(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isSymbolObject(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isTypedArray(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isTypedArray(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isUint8Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isUint8Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isUint8ClampedArray(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isUint8ClampedArray(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isUint16Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isUint16Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isUint32Array(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isUint32Array(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isWeakMap(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isWeakMap(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：types;<br>方法or属性：isWeakSet(value: Object): boolean;<br>旧版本信息：|类名：types;<br>方法or属性：isWeakSet(value: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：declare class Deque<br>旧版本信息：|类名：Deque;<br>方法or属性：declare class Deque<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：constructor();<br>旧版本信息：|类名：Deque;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：length: number;<br>旧版本信息：|类名：Deque;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：insertFront(element: T): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：insertFront(element: T): void;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：insertEnd(element: T): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：insertEnd(element: T): void;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：Deque;<br>方法or属性：has(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：Deque;<br>方法or属性：getFirst(): T;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：getLast(): T;<br>旧版本信息：|类名：Deque;<br>方法or属性：getLast(): T;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：popFirst(): T;<br>旧版本信息：|类名：Deque;<br>方法or属性：popFirst(): T;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：popLast(): T;<br>旧版本信息：|类名：Deque;<br>方法or属性：popLast(): T;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：Deque;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Deque;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.Deque.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：declare class HashMap<br>旧版本信息：|类名：HashMap;<br>方法or属性：declare class HashMap<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：constructor();<br>旧版本信息：|类名：HashMap;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：length: number;<br>旧版本信息：|类名：HashMap;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：HashMap;<br>方法or属性：get(key: K): V;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：setAll(map: HashMap\<K, V>): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：setAll(map: HashMap\<K, V>): void;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：HashMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：HashMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.HashMap.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：declare class HashSet<br>旧版本信息：|类名：HashSet;<br>方法or属性：declare class HashSet<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：constructor();<br>旧版本信息：|类名：HashSet;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：length: number;<br>旧版本信息：|类名：HashSet;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：has(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：has(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：add(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：add(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：remove(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：remove(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：HashSet;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：HashSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：HashSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.HashSet.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：declare class LightWeightMap<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：declare class LightWeightMap<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：constructor();<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：length: number;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：hasAll(map: LightWeightMap\<K, V>): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasAll(map: LightWeightMap\<K, V>): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：get(key: K): V;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：getIndexOfKey(key: K): number;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getIndexOfKey(key: K): number;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：getIndexOfValue(value: V): number;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getIndexOfValue(value: V): number;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：getKeyAt(index: number): K;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getKeyAt(index: number): K;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：setAll(map: LightWeightMap\<K, V>): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：setAll(map: LightWeightMap\<K, V>): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：removeAt(index: number): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：removeAt(index: number): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：setValueAt(index: number, newValue: V): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：setValueAt(index: number, newValue: V): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：toString(): String;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：toString(): String;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：getValueAt(index: number): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getValueAt(index: number): V;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：crossplatform|@ohos.util.LightWeightMap.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：declare class LightWeightSet<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：declare class LightWeightSet<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：constructor();<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：length: number;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：add(obj: T): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：add(obj: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：addAll(set: LightWeightSet\<T>): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：addAll(set: LightWeightSet\<T>): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：hasAll(set: LightWeightSet\<T>): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：hasAll(set: LightWeightSet\<T>): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：has(key: T): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：has(key: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：equal(obj: Object): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：equal(obj: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：getIndexOf(key: T): number;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：getIndexOf(key: T): number;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：remove(key: T): T;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：remove(key: T): T;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：removeAt(index: number): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：removeAt(index: number): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：toString(): String;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：toString(): String;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：toArray(): Array\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：toArray(): Array\<T>;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：getValueAt(index: number): T;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：getValueAt(index: number): T;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LightWeightSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.LightWeightSet.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：declare class LinkedList<br>旧版本信息：|类名：LinkedList;<br>方法or属性：declare class LinkedList<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：constructor();<br>旧版本信息：|类名：LinkedList;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：length: number;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：add(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：insert(index: number, element: T): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：insert(index: number, element: T): void;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：get(index: number): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：get(index: number): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：addFirst(element: T): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：addFirst(element: T): void;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：removeFirst(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeFirst(): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：removeLast(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeLast(): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：has(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：removeFirstFound(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeFirstFound(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：removeLastFound(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeLastFound(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getFirst(): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：getLast(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getLast(): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：set(index: number, element: T): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：set(index: number, element: T): T;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：clone(): LinkedList\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：clone(): LinkedList\<T>;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：LinkedList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.LinkedList.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：declare class List<br>旧版本信息：|类名：List;<br>方法or属性：declare class List<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：constructor();<br>旧版本信息：|类名：List;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：length: number;<br>旧版本信息：|类名：List;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：add(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：|类名：List;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：get(index: number): T;<br>旧版本信息：|类名：List;<br>方法or属性：get(index: number): T;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：has(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：List;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：List;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：List;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：List;<br>方法or属性：getFirst(): T;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：getLast(): T;<br>旧版本信息：|类名：List;<br>方法or属性：getLast(): T;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：set(index: number, element: T): T;<br>旧版本信息：|类名：List;<br>方法or属性：set(index: number, element: T): T;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：equal(obj: Object): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：equal(obj: Object): boolean;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, List?: List\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：List;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, List?: List\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：sort(comparator: (firstValue: T, secondValue: T) => number): void;<br>旧版本信息：|类名：List;<br>方法or属性：sort(comparator: (firstValue: T, secondValue: T) => number): void;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：List;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：getSubList(fromIndex: number, toIndex: number): List\<T>;<br>旧版本信息：|类名：List;<br>方法or属性：getSubList(fromIndex: number, toIndex: number): List\<T>;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, list?: List\<T>) => T, thisArg?: Object): void;<br>旧版本信息：|类名：List;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, list?: List\<T>) => T, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：List;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：List;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：List;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.List.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：declare class PlainArray<br>旧版本信息：|类名：PlainArray;<br>方法or属性：declare class PlainArray<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：constructor();<br>旧版本信息：|类名：PlainArray;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：length: number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：add(key: number, value: T): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：add(key: number, value: T): void;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：clone(): PlainArray\<T>;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：clone(): PlainArray\<T>;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：has(key: number): boolean;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：has(key: number): boolean;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：get(key: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：get(key: number): T;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：getIndexOfKey(key: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getIndexOfKey(key: number): number;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：getIndexOfValue(value: T): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getIndexOfValue(value: T): number;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：getKeyAt(index: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getKeyAt(index: number): number;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：remove(key: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：remove(key: number): T;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：removeAt(index: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：removeAt(index: number): T;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：removeRangeFrom(index: number, size: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：removeRangeFrom(index: number, size: number): number;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：setValueAt(index: number, value: T): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：setValueAt(index: number, value: T): void;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：toString(): String;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：toString(): String;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：getValueAt(index: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getValueAt(index: number): T;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：PlainArray;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[number, T]>;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[number, T]>;<br>新版本信息：crossplatform|@ohos.util.PlainArray.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：declare class Queue<br>旧版本信息：|类名：Queue;<br>方法or属性：declare class Queue<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：constructor();<br>旧版本信息：|类名：Queue;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：length: number;<br>旧版本信息：|类名：Queue;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：Queue;<br>方法or属性：add(element: T): boolean;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：Queue;<br>方法or属性：getFirst(): T;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：pop(): T;<br>旧版本信息：|类名：Queue;<br>方法or属性：pop(): T;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：Queue;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Queue;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Queue;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.Queue.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：declare class Stack<br>旧版本信息：|类名：Stack;<br>方法or属性：declare class Stack<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：constructor();<br>旧版本信息：|类名：Stack;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：length: number;<br>旧版本信息：|类名：Stack;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：Stack;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：peek(): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：peek(): T;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：pop(): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：pop(): T;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：push(item: T): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：push(item: T): T;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：locate(element: T): number;<br>旧版本信息：|类名：Stack;<br>方法or属性：locate(element: T): number;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：Stack;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：Stack;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Stack;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.Stack.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：declare class TreeMap<br>旧版本信息：|类名：TreeMap;<br>方法or属性：declare class TreeMap<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：constructor(comparator?: (firstValue: K, secondValue: K) => boolean);<br>旧版本信息：|类名：TreeMap;<br>方法or属性：constructor(comparator?: (firstValue: K, secondValue: K) => boolean);<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：length: number;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：get(key: K): V;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：getFirstKey(): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getFirstKey(): K;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：getLastKey(): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getLastKey(): K;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：setAll(map: TreeMap\<K, V>): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：setAll(map: TreeMap\<K, V>): void;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：getLowerKey(key: K): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getLowerKey(key: K): K;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：getHigherKey(key: K): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getHigherKey(key: K): K;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：crossplatform|@ohos.util.TreeMap.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：declare class TreeSet<br>旧版本信息：|类名：TreeSet;<br>方法or属性：declare class TreeSet<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：constructor(comparator?: (firstValue: T, secondValue: T) => boolean);<br>旧版本信息：|类名：TreeSet;<br>方法or属性：constructor(comparator?: (firstValue: T, secondValue: T) => boolean);<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：length: number;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：length: number;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：has(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：has(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：add(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：add(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：remove(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：remove(value: T): boolean;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：clear(): void;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：getFirstValue(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getFirstValue(): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：getLastValue(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getLastValue(): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：getLowerValue(key: T): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getLowerValue(key: T): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：getHigherValue(key: T): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getHigherValue(key: T): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：popFirst(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：popFirst(): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：popLast(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：popLast(): T;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object): void;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object): void;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：TreeSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：crossplatform|@ohos.util.TreeSet.d.ts|
|跨平台能力有变化|类名：sourcefile;<br>方法or属性：type MessageType = 'message' \| 'messageerror';<br>旧版本信息：|类名：sourcefile;<br>方法or属性：type MessageType = 'message' \| 'messageerror';<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerOptions;<br>方法or属性：export interface WorkerOptions<br>旧版本信息：|类名：WorkerOptions;<br>方法or属性：export interface WorkerOptions<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerOptions;<br>方法or属性：type?: 'classic' \| 'module';<br>旧版本信息：|类名：WorkerOptions;<br>方法or属性：type?: 'classic' \| 'module';<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerOptions;<br>方法or属性：name?: string;<br>旧版本信息：|类名：WorkerOptions;<br>方法or属性：name?: string;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerOptions;<br>方法or属性：shared?: boolean;<br>旧版本信息：|类名：WorkerOptions;<br>方法or属性：shared?: boolean;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：Event;<br>方法or属性：export interface Event<br>旧版本信息：|类名：Event;<br>方法or属性：export interface Event<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：Event;<br>方法or属性：readonly type: string;<br>旧版本信息：|类名：Event;<br>方法or属性：readonly type: string;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：Event;<br>方法or属性：readonly timeStamp: number;<br>旧版本信息：|类名：Event;<br>方法or属性：readonly timeStamp: number;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：export interface ErrorEvent<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：export interface ErrorEvent<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：readonly message: string;<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：readonly message: string;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：readonly filename: string;<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：readonly filename: string;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：readonly lineno: number;<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：readonly lineno: number;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：readonly colno: number;<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：readonly colno: number;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ErrorEvent;<br>方法or属性：readonly error: Object;<br>旧版本信息：|类名：ErrorEvent;<br>方法or属性：readonly error: Object;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：MessageEvent;<br>方法or属性：export interface MessageEvent<br>旧版本信息：|类名：MessageEvent;<br>方法or属性：export interface MessageEvent<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：MessageEvent;<br>方法or属性：readonly data: T;<br>旧版本信息：|类名：MessageEvent;<br>方法or属性：readonly data: T;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：MessageEvents;<br>方法or属性：export interface MessageEvents<br>旧版本信息：|类名：MessageEvents;<br>方法or属性：export interface MessageEvents<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：MessageEvents;<br>方法or属性：readonly data;<br>旧版本信息：|类名：MessageEvents;<br>方法or属性：readonly data;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：PostMessageOptions;<br>方法or属性：export interface PostMessageOptions<br>旧版本信息：|类名：PostMessageOptions;<br>方法or属性：export interface PostMessageOptions<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：PostMessageOptions;<br>方法or属性：transfer?: Object[];<br>旧版本信息：|类名：PostMessageOptions;<br>方法or属性：transfer?: Object[];<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventListener;<br>方法or属性：export interface WorkerEventListener<br>旧版本信息：|类名：WorkerEventListener;<br>方法or属性：export interface WorkerEventListener<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventListener;<br>方法or属性：(event: Event): void \| Promise\<void>;<br>旧版本信息：|类名：WorkerEventListener;<br>方法or属性：(event: Event): void \| Promise\<void>;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventTarget;<br>方法or属性：export interface WorkerEventTarget<br>旧版本信息：|类名：WorkerEventTarget;<br>方法or属性：export interface WorkerEventTarget<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventTarget;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>旧版本信息：|类名：WorkerEventTarget;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventTarget;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;<br>旧版本信息：|类名：WorkerEventTarget;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：WorkerEventTarget;<br>方法or属性：removeAllListener(): void;<br>旧版本信息：|类名：WorkerEventTarget;<br>方法or属性：removeAllListener(): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：removeAllListener(): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：removeAllListener(): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：GlobalScope;<br>方法or属性：declare interface GlobalScope<br>旧版本信息：|类名：GlobalScope;<br>方法or属性：declare interface GlobalScope<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：GlobalScope;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：GlobalScope;<br>方法or属性：readonly name: string;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：GlobalScope;<br>方法or属性：onerror?: (ev: ErrorEvent) => void;<br>旧版本信息：|类名：GlobalScope;<br>方法or属性：onerror?: (ev: ErrorEvent) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：GlobalScope;<br>方法or属性：readonly self: GlobalScope & typeof globalThis;<br>旧版本信息：|类名：GlobalScope;<br>方法or属性：readonly self: GlobalScope & typeof globalThis;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：export interface ThreadWorkerGlobalScope<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：export interface ThreadWorkerGlobalScope<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：close(): void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：close(): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: ArrayBuffer[]): void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: ArrayBuffer[]): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>旧版本信息：|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：worker;<br>方法or属性：declare worker<br>旧版本信息：|类名：worker;<br>方法or属性：declare worker<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：class ThreadWorker<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：class ThreadWorker<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：constructor(scriptURL: string, options?: WorkerOptions);<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：constructor(scriptURL: string, options?: WorkerOptions);<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：onexit?: (code: number) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onexit?: (code: number) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：onmessage?: (event: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onmessage?: (event: MessageEvents) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：onmessageerror?: (event: MessageEvents) => void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：onmessageerror?: (event: MessageEvents) => void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, transfer: ArrayBuffer[]): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, transfer: ArrayBuffer[]): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, options?: PostMessageOptions): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, options?: PostMessageOptions): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：on(type: string, listener: WorkerEventListener): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：on(type: string, listener: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：once(type: string, listener: WorkerEventListener): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：once(type: string, listener: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：off(type: string, listener?: WorkerEventListener): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：off(type: string, listener?: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：terminate(): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：terminate(): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：ThreadWorker;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>旧版本信息：|类名：ThreadWorker;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;<br>新版本信息：crossplatform|@ohos.worker.d.ts|
|跨平台能力有变化|类名：xml;<br>方法or属性：declare xml<br>旧版本信息：|类名：xml;<br>方法or属性：declare xml<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：class XmlSerializer<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：class XmlSerializer<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setAttributes(name: string, value: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setAttributes(name: string, value: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：addEmptyElement(name: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：addEmptyElement(name: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setDeclaration(): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setDeclaration(): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：startElement(name: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：startElement(name: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：endElement(): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：endElement(): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setNamespace(prefix: string, namespace: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setNamespace(prefix: string, namespace: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setComment(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setComment(text: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setCDATA(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setCDATA(text: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setText(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setText(text: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlSerializer;<br>方法or属性：setDocType(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setDocType(text: string): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：enum EventType<br>旧版本信息：|类名：EventType;<br>方法or属性：enum EventType<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：START_DOCUMENT<br>旧版本信息：|类名：EventType;<br>方法or属性：START_DOCUMENT<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：END_DOCUMENT<br>旧版本信息：|类名：EventType;<br>方法or属性：END_DOCUMENT<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：START_TAG<br>旧版本信息：|类名：EventType;<br>方法or属性：START_TAG<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：END_TAG<br>旧版本信息：|类名：EventType;<br>方法or属性：END_TAG<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：TEXT<br>旧版本信息：|类名：EventType;<br>方法or属性：TEXT<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：CDSECT<br>旧版本信息：|类名：EventType;<br>方法or属性：CDSECT<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：COMMENT<br>旧版本信息：|类名：EventType;<br>方法or属性：COMMENT<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：DOCDECL<br>旧版本信息：|类名：EventType;<br>方法or属性：DOCDECL<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：INSTRUCTION<br>旧版本信息：|类名：EventType;<br>方法or属性：INSTRUCTION<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：ENTITY_REFERENCE<br>旧版本信息：|类名：EventType;<br>方法or属性：ENTITY_REFERENCE<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：EventType;<br>方法or属性：WHITESPACE<br>旧版本信息：|类名：EventType;<br>方法or属性：WHITESPACE<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：interface ParseInfo<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：interface ParseInfo<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getColumnNumber(): number;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getColumnNumber(): number;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getDepth(): number;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getDepth(): number;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getLineNumber(): number;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getLineNumber(): number;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getName(): string;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getName(): string;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getNamespace(): string;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getNamespace(): string;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getPrefix(): string;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getPrefix(): string;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getText(): string;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getText(): string;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：isEmptyElementTag(): boolean;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：isEmptyElementTag(): boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：isWhitespace(): boolean;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：isWhitespace(): boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseInfo;<br>方法or属性：getAttributeCount(): number;<br>旧版本信息：|类名：ParseInfo;<br>方法or属性：getAttributeCount(): number;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：interface ParseOptions<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：interface ParseOptions<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：supportDoctype?: boolean;<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：supportDoctype?: boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：ignoreNameSpace?: boolean;<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：ignoreNameSpace?: boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：tagValueCallbackFunction?: (name: string, value: string) => boolean;<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：tagValueCallbackFunction?: (name: string, value: string) => boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：attributeValueCallbackFunction?: (name: string, value: string) => boolean;<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：attributeValueCallbackFunction?: (name: string, value: string) => boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：ParseOptions;<br>方法or属性：tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean;<br>旧版本信息：|类名：ParseOptions;<br>方法or属性：tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlPullParser;<br>方法or属性：class XmlPullParser<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：class XmlPullParser<br>新版本信息：crossplatform|@ohos.xml.d.ts|
|跨平台能力有变化|类名：XmlPullParser;<br>方法or属性：parse(option: ParseOptions): void;<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：parse(option: ParseOptions): void;<br>新版本信息：crossplatform|@ohos.xml.d.ts|
