| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：URLParams;<br>方法or属性：append(name: string, value: string): void;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：delete(name: string): void;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：getAll(name: string): string[];|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：entries(): IterableIterator\<[string, string]>;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：get(name: string): string \| null;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：has(name: string): boolean;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：set(name: string, value: string): void;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：sort(): void;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：keys(): IterableIterator\<string>;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：values(): IterableIterator\<string>;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[string, string]>;|@ohos.url.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：toString(): string;|@ohos.url.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：constructor(capacity?: number);|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：updateCapacity(newCapacity: number):void|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：toString(): string|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：toString(): string;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：length: number|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getCapacity(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：clear(): void;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getCreateCount(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getMissCount(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getRemovalCount(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getMatchCount(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：getPutCount(): number;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：isEmpty(): boolean;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：get(key: K): V \| undefined;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：put(key: K, value: V): V;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：values(): V[];|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：keys(): K[];|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：remove(key: K): V \| undefined;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：contains(key: K): boolean;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：createDefault(key: K): V;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：entries(): IterableIterator\<[K, V]>;|@ohos.util.d.ts|
|新增|NA|类名：LRUCache;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：constructor(lowerObj: ScopeType, upperObj: ScopeType);|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：getUpper(): ScopeType;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：getLower(): ScopeType;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：contains(value: ScopeType): boolean;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：clamp(value: ScopeType): ScopeType;|@ohos.util.d.ts|
|新增|NA|类名：TextDecoder;<br>方法or属性：constructor();|@ohos.util.d.ts|
|新增|NA|类名：RationalNumber;<br>方法or属性：constructor();|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：constructor();|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：encodeSync(src: Uint8Array): Uint8Array;|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：encodeToStringSync(src: Uint8Array): string;|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：decodeSync(src: Uint8Array \| string): Uint8Array;|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：encode(src: Uint8Array): Promise\<Uint8Array>;|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：encodeToString(src: Uint8Array): Promise\<string>;|@ohos.util.d.ts|
|新增|NA|类名：Base64Helper;<br>方法or属性：decode(src: Uint8Array \| string): Promise\<Uint8Array>;|@ohos.util.d.ts|
|新增|NA|类名：WorkerEventTarget;<br>方法or属性：dispatchEvent(event: Event): boolean;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：dispatchEvent(event: Event): boolean;|@ohos.worker.d.ts|
|新增|NA|类名：WorkerEventTarget;<br>方法or属性：removeAllListener(): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：removeAllListener(): void;|@ohos.worker.d.ts|
|新增|NA|类名：GlobalScope;<br>方法or属性：readonly name: string;|@ohos.worker.d.ts|
|新增|NA|类名：GlobalScope;<br>方法or属性：onerror?: (ev: ErrorEvent) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorkerGlobalScope;<br>方法or属性：close(): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, options?: PostMessageOptions): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：constructor(scriptURL: string, options?: WorkerOptions);|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：onexit?: (code: number) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, transfer: ArrayBuffer[]): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：postMessage(message: Object, options?: PostMessageOptions): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：terminate(): void;|@ohos.worker.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：type BufferEncoding = 'ascii' \| 'utf8' \| 'utf-8' \| 'utf16le' \| 'ucs2' \| 'ucs-2' \| 'base64' \| 'base64url' \| 'latin1' \| 'binary' \| 'hex';|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function alloc(size: number, fill?: string \| Buffer \| number, encoding?: BufferEncoding): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function allocUninitializedFromPool(size: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function allocUninitialized(size: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function byteLength(string: string \| Buffer \| TypedArray \| DataView \| ArrayBuffer \| SharedArrayBuffer, encoding?: BufferEncoding): number;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function concat(list: Buffer[] \| Uint8Array[], totalLength?: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function from(array: number[]): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function from(arrayBuffer: ArrayBuffer \| SharedArrayBuffer, byteOffset?: number, length?: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function from(buffer: Buffer \| Uint8Array): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function from(object: Object, offsetOrEncoding: number \| string, length: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function from(string: String, encoding?: BufferEncoding): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function isBuffer(obj: Object): boolean;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function isEncoding(encoding: string):boolean;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function compare(buf1: Buffer \| Uint8Array, buf2: Buffer \| Uint8Array): -1 \| 0 \| 1;|@ohos.buffer.d.ts|
|新增|NA|类名：buffer;<br>方法or属性：function transcode(source: Buffer \| Uint8Array, fromEnc: string, toEnc: string): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：length: number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：buffer: ArrayBuffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：byteOffset: number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：fill(value: string \| Buffer \| Uint8Array \| number, offset?: number, end?: number, encoding?: BufferEncoding): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：compare(target: Buffer \| Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 \| 0 \| 1;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：copy(target: Buffer \| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：equals(otherBuffer: Uint8Array \| Buffer): boolean;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：includes(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：indexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：keys(): IterableIterator\<number>;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：values(): IterableIterator\<number>;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：entries(): IterableIterator\<[number, number]>;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：lastIndexOf(value: string \| number \| Buffer \| Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readBigInt64BE(offset?: number): bigint;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readBigInt64LE(offset?: number): bigint;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readBigUInt64BE(offset?: number): bigint;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readBigUInt64LE(offset?: number): bigint;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readDoubleBE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readDoubleLE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readFloatBE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readFloatLE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readInt8(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readInt16BE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readInt16LE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readInt32BE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readInt32LE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readIntBE(offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readIntLE(offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUInt8(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUInt16BE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUInt16LE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUInt32BE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUInt32LE(offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUIntBE(offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：readUIntLE(offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：subarray(start?: number, end?: number): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：swap16(): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：swap32(): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：swap64(): Buffer;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：toJSON(): Object;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：toString(encoding?: string, start?: number, end?: number): string;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：write(str: string, offset?: number, length?: number, encoding?: string): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeBigInt64BE(value: bigint, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeBigInt64LE(value: bigint, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeBigUInt64BE(value: bigint, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeBigUInt64LE(value: bigint, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeDoubleBE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeDoubleLE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeFloatBE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeFloatLE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeInt8(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeInt16BE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeInt16LE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeInt32BE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeInt32LE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeIntBE(value: number, offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeIntLE(value : number, offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUInt8(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUInt16BE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUInt16LE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUInt32BE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUInt32LE(value: number, offset?: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUIntBE(value: number, offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Buffer;<br>方法or属性：writeUIntLE(value: number, offset: number, byteLength: number): number;|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：constructor(sources: string[] \| ArrayBuffer[] \| TypedArray[] \| DataView[] \| Blob[] , options?: Object);|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：size: number;|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：type: string;|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：arrayBuffer(): Promise\<ArrayBuffer>;|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：slice(start?: number, end?: number, type?: string): Blob;|@ohos.buffer.d.ts|
|新增|NA|类名：Blob;<br>方法or属性：text(): Promise\<string>;|@ohos.buffer.d.ts|
|新增|NA|类名：ConvertXML;<br>方法or属性：convertToJSObject(xml: string, options?: ConvertOptions) : Object;|@ohos.convertxml.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：isAppUid(v: number): boolean;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：getUidForName(v: string): number;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：getThreadPriority(v: number): number;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：getSystemConfig(name: number): number;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：getEnvironmentVar(name: string): string;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：exit(code: number): void;|@ohos.process.d.ts|
|新增|NA|类名：ProcessManager;<br>方法or属性：kill(signal: number, pid: number): boolean;|@ohos.process.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function execute(func: Function, ...args: unknown[]): Promise\<unknown>;|@ohos.taskpool.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function execute(task: Task, priority?: Priority): Promise\<unknown>;|@ohos.taskpool.d.ts|
|新增|NA|类名：taskpool;<br>方法or属性：function cancel(task: Task): void;|@ohos.taskpool.d.ts|
|新增|NA|类名：Priority;<br>方法or属性：HIGH|@ohos.taskpool.d.ts|
|新增|NA|类名：Priority;<br>方法or属性：MEDIUM|@ohos.taskpool.d.ts|
|新增|NA|类名：Priority;<br>方法or属性：LOW|@ohos.taskpool.d.ts|
|新增|NA|类名：Task;<br>方法or属性：constructor(func: Function, ...args: unknown[]);|@ohos.taskpool.d.ts|
|新增|NA|类名：Task;<br>方法or属性：function: Function;|@ohos.taskpool.d.ts|
|新增|NA|类名：Task;<br>方法or属性：arguments?: unknown[];|@ohos.taskpool.d.ts|
|新增|NA|类名：URI;<br>方法or属性：equalsTo(other: URI): boolean;|@ohos.uri.d.ts|
|新增|NA|类名：URLParams;<br>方法or属性：constructor(init?: string[][] \| Record\<string, string> \| string \| URLParams);|@ohos.url.d.ts|
|新增|NA|类名：URL;<br>方法or属性：constructor();|@ohos.url.d.ts|
|新增|NA|类名：URL;<br>方法or属性：static parseURL(url: string, base?: string \| URL): URL;|@ohos.url.d.ts|
|新增|NA|类名：URL;<br>方法or属性：readonly params: URLParams;|@ohos.url.d.ts|
|新增|NA|类名：util;<br>方法or属性：function format(format: string, ...args: Object[]): string;|@ohos.util.d.ts|
|新增|NA|类名：util;<br>方法or属性：function errnoToString(errno: number): string;|@ohos.util.d.ts|
|新增|NA|类名：util;<br>方法or属性：function promisify(original: (err: Object, value: Object) => void): Function;|@ohos.util.d.ts|
|新增|NA|类名：util;<br>方法or属性：function generateRandomUUID(entropyCache?: boolean): string;|@ohos.util.d.ts|
|新增|NA|类名：util;<br>方法or属性：function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array;|@ohos.util.d.ts|
|新增|NA|类名：util;<br>方法or属性：function parseUUID(uuid: string): Uint8Array;|@ohos.util.d.ts|
|新增|NA|类名：TextDecoder;<br>方法or属性：static create(<br><br>            encoding?: string,<br><br>            options?: { fatal?: boolean; ignoreBOM?: boolean }<br><br>        ): TextDecoder;|@ohos.util.d.ts|
|新增|NA|类名：TextDecoder;<br>方法or属性：decodeWithStream(input: Uint8Array, options?: { stream?: boolean }): string;|@ohos.util.d.ts|
|新增|NA|类名：TextEncoder;<br>方法or属性：constructor(encoding?: string);|@ohos.util.d.ts|
|新增|NA|类名：TextEncoder;<br>方法or属性：encodeInto(input?: string): Uint8Array;|@ohos.util.d.ts|
|新增|NA|类名：TextEncoder;<br>方法or属性：encodeIntoUint8Array(<br><br>            input: string,<br><br>            dest: Uint8Array,<br><br>        ): { read: number; written: number };|@ohos.util.d.ts|
|新增|NA|类名：RationalNumber;<br>方法or属性：static parseRationalNumber(numerator: number, denominator: number): RationalNumber;|@ohos.util.d.ts|
|新增|NA|类名：RationalNumber;<br>方法or属性：compare(another :RationalNumber): number;|@ohos.util.d.ts|
|新增|NA|类名：RationalNumber;<br>方法or属性：static getCommonFactor(number1: number, number2: number): number;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：intersect(range: ScopeHelper): ScopeHelper;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：intersect(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：expand(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：expand(range: ScopeHelper): ScopeHelper;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：expand(value: ScopeType): ScopeHelper;|@ohos.util.d.ts|
|新增|NA|类名：ScopeHelper;<br>方法or属性：contains(range: ScopeHelper): boolean;|@ohos.util.d.ts|
|新增|NA|类名：MessageEvents;<br>方法or属性：readonly data;|@ohos.worker.d.ts|
|新增|NA|类名：WorkerEventListener;<br>方法or属性：(event: Event): void \| Promise\<void>;|@ohos.worker.d.ts|
|新增|NA|类名：WorkerEventTarget;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：addEventListener(type: string, listener: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：WorkerEventTarget;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：removeEventListener(type: string, callback?: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：GlobalScope;<br>方法or属性：readonly self: GlobalScope & typeof globalThis;|@ohos.worker.d.ts|
|新增|NA|类名：DedicatedWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: ArrayBuffer[]): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: ArrayBuffer[]): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：onmessage?: (event: MessageEvents) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：onmessageerror?: (event: MessageEvents) => void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：on(type: string, listener: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：once(type: string, listener: WorkerEventListener): void;|@ohos.worker.d.ts|
|新增|NA|类名：ThreadWorker;<br>方法or属性：off(type: string, listener?: WorkerEventListener): void;|@ohos.worker.d.ts|
|废弃版本有变化|类名：ConvertXML;<br>方法or属性：convert(xml: string, options?: ConvertOptions) : Object;<br>旧版本信息：|类名：ConvertXML;<br>方法or属性：convert(xml: string, options?: ConvertOptions) : Object;<br>新版本信息：9<br>代替接口： ohos.convertxml.ConvertXML.convertToJSObject|@ohos.convertxml.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function isAppUid(v: number): boolean;<br>旧版本信息：|类名：process;<br>方法or属性：function isAppUid(v: number): boolean;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.isAppUid|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function getUidForName(v: string): number;<br>旧版本信息：|类名：process;<br>方法or属性：function getUidForName(v: string): number;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.getUidForName|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function getThreadPriority(v: number): number;<br>旧版本信息：|类名：process;<br>方法or属性：function getThreadPriority(v: number): number;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.getThreadPriority|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function getSystemConfig(name: number): number;<br>旧版本信息：|类名：process;<br>方法or属性：function getSystemConfig(name: number): number;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.getSystemConfig|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function getEnvironmentVar(name: string): string;<br>旧版本信息：|类名：process;<br>方法or属性：function getEnvironmentVar(name: string): string;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.getEnvironmentVar|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function exit(code: number): void;<br>旧版本信息：|类名：process;<br>方法or属性：function exit(code: number): void;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.exit|@ohos.process.d.ts|
|废弃版本有变化|类名：process;<br>方法or属性：function kill(signal: number, pid: number): boolean;<br>旧版本信息：|类名：process;<br>方法or属性：function kill(signal: number, pid: number): boolean;<br>新版本信息：9<br>代替接口： ohos.process.ProcessManager.kill|@ohos.process.d.ts|
|废弃版本有变化|类名：URI;<br>方法or属性：equals(other: URI): boolean;<br>旧版本信息：|类名：URI;<br>方法or属性：equals(other: URI): boolean;<br>新版本信息：9<br>代替接口： ohos.uri.URI.equalsTo|@ohos.uri.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：class URLSearchParams<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：class URLSearchParams<br>新版本信息：9<br>代替接口： ohos.url.URLParams|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：constructor(init?: string[][] \| Record\<string, string> \| string \| URLSearchParams);<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：constructor(init?: string[][] \| Record\<string, string> \| string \| URLSearchParams);<br>新版本信息：9<br>代替接口： ohos.url.URLParams.constructor|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：append(name: string, value: string): void;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：append(name: string, value: string): void;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.append|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：delete(name: string): void;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：delete(name: string): void;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.delete|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：getAll(name: string): string[];<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：getAll(name: string): string[];<br>新版本信息：9<br>代替接口： ohos.url.URLParams.getAll|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：entries(): IterableIterator\<[string, string]>;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：entries(): IterableIterator\<[string, string]>;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.entries|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.forEach|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：get(name: string): string \| null;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：get(name: string): string \| null;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.get|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：has(name: string): boolean;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：has(name: string): boolean;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.has|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：set(name: string, value: string): void;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：set(name: string, value: string): void;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.set|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：sort(): void;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：sort(): void;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.sort|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：keys(): IterableIterator\<string>;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：keys(): IterableIterator\<string>;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.keys|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：values(): IterableIterator\<string>;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：values(): IterableIterator\<string>;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.values|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[string, string]>;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[string, string]>;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.[Symbol.iterator]|@ohos.url.d.ts|
|废弃版本有变化|类名：URLSearchParams;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：URLSearchParams;<br>方法or属性：toString(): string;<br>新版本信息：9<br>代替接口： ohos.url.URLParams.toString|@ohos.url.d.ts|
|废弃版本有变化|类名：URL;<br>方法or属性：constructor(url: string, base?: string \| URL);<br>旧版本信息：|类名：URL;<br>方法or属性：constructor(url: string, base?: string \| URL);<br>新版本信息：9<br>代替接口： ohos.url.URL.parseURL|@ohos.url.d.ts|
|废弃版本有变化|类名：URL;<br>方法or属性：readonly searchParams: URLSearchParams;<br>旧版本信息：|类名：URL;<br>方法or属性：readonly searchParams: URLSearchParams;<br>新版本信息：9<br>代替接口： ohos.url.URL.params|@ohos.url.d.ts|
|废弃版本有变化|类名：util;<br>方法or属性：function printf(format: string, ...args: Object[]): string;<br>旧版本信息：|类名：util;<br>方法or属性：function printf(format: string, ...args: Object[]): string;<br>新版本信息：9<br>代替接口： ohos.util.format|@ohos.util.d.ts|
|废弃版本有变化|类名：util;<br>方法or属性：function getErrorString(errno: number): string;<br>旧版本信息：|类名：util;<br>方法or属性：function getErrorString(errno: number): string;<br>新版本信息：9<br>代替接口： ohos.util.errnoToString|@ohos.util.d.ts|
|废弃版本有变化|类名：util;<br>方法or属性：function promiseWrapper(original: (err: Object, value: Object) => void): Object;<br>旧版本信息：|类名：util;<br>方法or属性：function promiseWrapper(original: (err: Object, value: Object) => void): Object;<br>新版本信息：9<br>代替接口： ohos.util.promisify|@ohos.util.d.ts|
|废弃版本有变化|类名：TextDecoder;<br>方法or属性：constructor(<br><br>            encoding?: string,<br><br>            options?: { fatal?: boolean; ignoreBOM?: boolean },<br><br>        );<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：constructor(<br><br>            encoding?: string,<br><br>            options?: { fatal?: boolean; ignoreBOM?: boolean },<br><br>        );<br>新版本信息：9<br>代替接口： ohos.util.TextDecoder.create|@ohos.util.d.ts|
|废弃版本有变化|类名：TextDecoder;<br>方法or属性：decode(input: Uint8Array, options?: { stream?: false }): string;<br>旧版本信息：|类名：TextDecoder;<br>方法or属性：decode(input: Uint8Array, options?: { stream?: false }): string;<br>新版本信息：9<br>代替接口： ohos.util.decodeWithStream|@ohos.util.d.ts|
|废弃版本有变化|类名：TextEncoder;<br>方法or属性：encode(input?: string): Uint8Array;<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：encode(input?: string): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.util.encodeInto|@ohos.util.d.ts|
|废弃版本有变化|类名：TextEncoder;<br>方法or属性：encodeInto(<br><br>            input: string,<br><br>            dest: Uint8Array,<br><br>        ): { read: number; written: number };<br>旧版本信息：|类名：TextEncoder;<br>方法or属性：encodeInto(<br><br>            input: string,<br><br>            dest: Uint8Array,<br><br>        ): { read: number; written: number };<br>新版本信息：9<br>代替接口： ohos.util.encodeIntoUint8Array|@ohos.util.d.ts|
|废弃版本有变化|类名：RationalNumber;<br>方法or属性：constructor(numerator: number, denominator: number);<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：constructor(numerator: number, denominator: number);<br>新版本信息：9<br>代替接口： ohos.util.RationalNumber.parseRationalNumber|@ohos.util.d.ts|
|废弃版本有变化|类名：RationalNumber;<br>方法or属性：compareTo(another :RationalNumber): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：compareTo(another :RationalNumber): number;<br>新版本信息：9<br>代替接口： ohos.util.compare|@ohos.util.d.ts|
|废弃版本有变化|类名：RationalNumber;<br>方法or属性：static getCommonDivisor(number1: number, number2: number): number;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：static getCommonDivisor(number1: number, number2: number): number;<br>新版本信息：9<br>代替接口： ohos.util.getCommonFactor|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：class LruBuffer<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：class LruBuffer<br>新版本信息：9<br>代替接口： ohos.util.LRUCache|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：constructor(capacity?: number);<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：constructor(capacity?: number);<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.constructor|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：updateCapacity(newCapacity: number):void<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：updateCapacity(newCapacity: number):void<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.updateCapacity|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：toString(): string<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：toString(): string<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.toString|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：Scope;<br>方法or属性：toString(): string;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.toString|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：length: number<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：length: number<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.length|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getCapacity(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getCapacity|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：clear(): void;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.clear|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getCreateCount(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getCreateCount(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getCreateCount|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getMissCount(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getMissCount(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getMissCount|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getRemovalCount(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getRemovalCount(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getRemovalCount|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getMatchCount(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getMatchCount(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getMatchCount|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：getPutCount(): number;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：getPutCount(): number;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.getPutCount|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.isEmpty|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：get(key: K): V \| undefined;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：get(key: K): V \| undefined;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.get|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：put(key: K, value: V): V;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：put(key: K, value: V): V;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.put|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：values(): V[];<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：values(): V[];<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.values|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：keys(): K[];<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：keys(): K[];<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.keys|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：remove(key: K): V \| undefined;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：remove(key: K): V \| undefined;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.remove|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.afterRemoval|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：contains(key: K): boolean;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：contains(key: K): boolean;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.contains|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：createDefault(key: K): V;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：createDefault(key: K): V;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.createDefault|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.entries|@ohos.util.d.ts|
|废弃版本有变化|类名：LruBuffer;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LruBuffer;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：9<br>代替接口： ohos.util.LRUCache.[Symbol.iterator]|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：class Scope<br>旧版本信息：|类名：Scope;<br>方法or属性：class Scope<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：constructor(lowerObj: ScopeType, upperObj: ScopeType);<br>旧版本信息：|类名：Scope;<br>方法or属性：constructor(lowerObj: ScopeType, upperObj: ScopeType);<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.constructor|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：intersect(range: Scope): Scope;<br>旧版本信息：|类名：Scope;<br>方法or属性：intersect(range: Scope): Scope;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.intersect|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：intersect(lowerObj: ScopeType, upperObj: ScopeType): Scope;<br>旧版本信息：|类名：Scope;<br>方法or属性：intersect(lowerObj: ScopeType, upperObj: ScopeType): Scope;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.intersect|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：getUpper(): ScopeType;<br>旧版本信息：|类名：Scope;<br>方法or属性：getUpper(): ScopeType;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.getUpper|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：getLower(): ScopeType;<br>旧版本信息：|类名：Scope;<br>方法or属性：getLower(): ScopeType;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.getLower|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：expand(lowerObj: ScopeType, upperObj: ScopeType): Scope;<br>旧版本信息：|类名：Scope;<br>方法or属性：expand(lowerObj: ScopeType, upperObj: ScopeType): Scope;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.expand|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：expand(range: Scope): Scope;<br>旧版本信息：|类名：Scope;<br>方法or属性：expand(range: Scope): Scope;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.expand|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：expand(value: ScopeType): Scope;<br>旧版本信息：|类名：Scope;<br>方法or属性：expand(value: ScopeType): Scope;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.expand|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：contains(value: ScopeType): boolean;<br>旧版本信息：|类名：Scope;<br>方法or属性：contains(value: ScopeType): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.contains|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：contains(range: Scope): boolean;<br>旧版本信息：|类名：Scope;<br>方法or属性：contains(range: Scope): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.contains|@ohos.util.d.ts|
|废弃版本有变化|类名：Scope;<br>方法or属性：clamp(value: ScopeType): ScopeType;<br>旧版本信息：|类名：Scope;<br>方法or属性：clamp(value: ScopeType): ScopeType;<br>新版本信息：9<br>代替接口： ohos.util.ScopeHelper.clamp|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：class Base64<br>旧版本信息：|类名：Base64;<br>方法or属性：class Base64<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：constructor();<br>旧版本信息：|类名：Base64;<br>方法or属性：constructor();<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.constructor|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：encodeSync(src: Uint8Array): Uint8Array;<br>旧版本信息：|类名：Base64;<br>方法or属性：encodeSync(src: Uint8Array): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.encodeSync|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：encodeToStringSync(src: Uint8Array): string;<br>旧版本信息：|类名：Base64;<br>方法or属性：encodeToStringSync(src: Uint8Array): string;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.encodeToStringSync|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：decodeSync(src: Uint8Array \| string): Uint8Array;<br>旧版本信息：|类名：Base64;<br>方法or属性：decodeSync(src: Uint8Array \| string): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.decodeSync|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：encode(src: Uint8Array): Promise\<Uint8Array>;<br>旧版本信息：|类名：Base64;<br>方法or属性：encode(src: Uint8Array): Promise\<Uint8Array>;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.encode|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：encodeToString(src: Uint8Array): Promise\<string>;<br>旧版本信息：|类名：Base64;<br>方法or属性：encodeToString(src: Uint8Array): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.encodeToString|@ohos.util.d.ts|
|废弃版本有变化|类名：Base64;<br>方法or属性：decode(src: Uint8Array \| string): Promise\<Uint8Array>;<br>旧版本信息：|类名：Base64;<br>方法or属性：decode(src: Uint8Array \| string): Promise\<Uint8Array>;<br>新版本信息：9<br>代替接口： ohos.util.Base64Helper.decode|@ohos.util.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：declare class Vector<br>旧版本信息：|类名：Vector;<br>方法or属性：declare class Vector<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：constructor();<br>旧版本信息：|类名：Vector;<br>方法or属性：constructor();<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：length: number;<br>旧版本信息：|类名：Vector;<br>方法or属性：length: number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：Vector;<br>方法or属性：add(element: T): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：Vector;<br>方法or属性：has(element: T): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：get(index: number): T;<br>旧版本信息：|类名：Vector;<br>方法or属性：get(index: number): T;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：Vector;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getFirstElement(): T;<br>旧版本信息：|类名：Vector;<br>方法or属性：getFirstElement(): T;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getLastElement(): T;<br>旧版本信息：|类名：Vector;<br>方法or属性：getLastElement(): T;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：Vector;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：Vector;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：set(index: number, element: T): T;<br>旧版本信息：|类名：Vector;<br>方法or属性：set(index: number, element: T): T;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：Vector;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getLastIndexFrom(element: T, index: number): number;<br>旧版本信息：|类名：Vector;<br>方法or属性：getLastIndexFrom(element: T, index: number): number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getIndexFrom(element: T, index: number): number;<br>旧版本信息：|类名：Vector;<br>方法or属性：getIndexFrom(element: T, index: number): number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => T,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => T,<br><br>  thisArg?: Object): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>旧版本信息：|类名：Vector;<br>方法or属性：subVector(fromIndex: number, toIndex: number): Vector\<T>;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：clear(): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：clone(): Vector\<T>;<br>旧版本信息：|类名：Vector;<br>方法or属性：clone(): Vector\<T>;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：setLength(newSize: number): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：setLength(newSize: number): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：Vector;<br>方法or属性：getCapacity(): number;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：Vector;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：Vector;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：Vector;<br>方法or属性：toString(): string;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：trimToCurrentLength(): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：trimToCurrentLength(): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：copyToArray(array: Array\<T>): void;<br>旧版本信息：|类名：Vector;<br>方法or属性：copyToArray(array: Array\<T>): void;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：Vector;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Vector;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：9<br>代替接口： ohos.util.ArrayList|@ohos.util.Vector.d.ts|
|废弃版本有变化|类名：EventListener;<br>方法or属性：export interface EventListener<br>旧版本信息：|类名：EventListener;<br>方法or属性：export interface EventListener<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventListener|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventListener;<br>方法or属性：(evt: Event): void \| Promise\<void>;<br>旧版本信息：|类名：EventListener;<br>方法or属性：(evt: Event): void \| Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventListener.(event:|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventTarget;<br>方法or属性：export interface EventTarget<br>旧版本信息：|类名：EventTarget;<br>方法or属性：export interface EventTarget<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventTarget|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventTarget;<br>方法or属性：addEventListener(<br><br>    type: string,<br><br>    listener: EventListener<br><br>  ): void;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：addEventListener(<br><br>    type: string,<br><br>    listener: EventListener<br><br>  ): void;<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventTarget.addEventListener|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventTarget;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：dispatchEvent(event: Event): boolean;<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventTarget.dispatchEvent|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventTarget;<br>方法or属性：removeEventListener(<br><br>    type: string,<br><br>    callback?: EventListener<br><br>  ): void;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：removeEventListener(<br><br>    type: string,<br><br>    callback?: EventListener<br><br>  ): void;<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventTarget.removeEventListener|@ohos.worker.d.ts|
|废弃版本有变化|类名：EventTarget;<br>方法or属性：removeAllListener(): void;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：removeAllListener(): void;<br>新版本信息：9<br>代替接口： ohos.worker.WorkerEventTarget.removeAllListener|@ohos.worker.d.ts|
|废弃版本有变化|类名：WorkerGlobalScope;<br>方法or属性：declare interface WorkerGlobalScope<br>旧版本信息：|类名：WorkerGlobalScope;<br>方法or属性：declare interface WorkerGlobalScope<br>新版本信息：9<br>代替接口： ohos.worker.GlobalScope|@ohos.worker.d.ts|
|废弃版本有变化|类名：WorkerGlobalScope;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：WorkerGlobalScope;<br>方法or属性：readonly name: string;<br>新版本信息：9<br>代替接口： ohos.worker.GlobalScope.name|@ohos.worker.d.ts|
|废弃版本有变化|类名：WorkerGlobalScope;<br>方法or属性：onerror?: (ev: ErrorEvent) => void;<br>旧版本信息：|类名：WorkerGlobalScope;<br>方法or属性：onerror?: (ev: ErrorEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.GlobalScope.onerror|@ohos.worker.d.ts|
|废弃版本有变化|类名：WorkerGlobalScope;<br>方法or属性：readonly self: WorkerGlobalScope & typeof globalThis;<br>旧版本信息：|类名：WorkerGlobalScope;<br>方法or属性：readonly self: WorkerGlobalScope & typeof globalThis;<br>新版本信息：9<br>代替接口： ohos.worker.GlobalScope|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：export interface DedicatedWorkerGlobalScope<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：export interface DedicatedWorkerGlobalScope<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope.onmessage|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope.onmessageerror|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：close(): void;<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：close(): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope.close|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: Transferable[]): void;<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, transfer: Transferable[]): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope.postMessage|@ohos.worker.d.ts|
|废弃版本有变化|类名：DedicatedWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>旧版本信息：|类名：DedicatedWorkerGlobalScope;<br>方法or属性：postMessage(messageObject: Object, options?: PostMessageOptions): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorkerGlobalScope|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：class Worker<br>旧版本信息：|类名：Worker;<br>方法or属性：class Worker<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：constructor(scriptURL: string, options?: WorkerOptions);<br>旧版本信息：|类名：Worker;<br>方法or属性：constructor(scriptURL: string, options?: WorkerOptions);<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.constructor|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：onexit?: (code: number) => void;<br>旧版本信息：|类名：Worker;<br>方法or属性：onexit?: (code: number) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.onexit|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>旧版本信息：|类名：Worker;<br>方法or属性：onerror?: (err: ErrorEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.onerror|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：onmessage?: (event: MessageEvent) => void;<br>旧版本信息：|类名：Worker;<br>方法or属性：onmessage?: (event: MessageEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.onmessage|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：onmessageerror?: (event: MessageEvent) => void;<br>旧版本信息：|类名：Worker;<br>方法or属性：onmessageerror?: (event: MessageEvent) => void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.onmessageerror|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：postMessage(message: Object, transfer: ArrayBuffer[]): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：postMessage(message: Object, transfer: ArrayBuffer[]): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.postMessage|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：postMessage(message: Object, options?: PostMessageOptions): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：postMessage(message: Object, options?: PostMessageOptions): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：on(type: string, listener: EventListener): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：on(type: string, listener: EventListener): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.on|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：once(type: string, listener: EventListener): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：once(type: string, listener: EventListener): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.once|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：off(type: string, listener?: EventListener): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：off(type: string, listener?: EventListener): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.off|@ohos.worker.d.ts|
|废弃版本有变化|类名：Worker;<br>方法or属性：terminate(): void;<br>旧版本信息：|类名：Worker;<br>方法or属性：terminate(): void;<br>新版本信息：9<br>代替接口： ohos.worker.ThreadWorker.terminate|@ohos.worker.d.ts|
|新增(错误码)|类名：URI;<br>方法or属性：constructor(uri: string);<br>旧版本信息：|类名：URI;<br>方法or属性：constructor(uri: string);<br>新版本信息：401,10200002|@ohos.uri.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：constructor();<br>旧版本信息：|类名：ArrayList;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：add(element: T): boolean;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：has(element: T): boolean;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：10200001,10200011,401|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：sort(comparator?: (firstValue: T, secondValue: T) => number): void;<br>新版本信息：10200011,401|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：clone(): ArrayList\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：clone(): ArrayList\<T>;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：getCapacity(): number;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：increaseCapacityTo(newCapacity: number): void;<br>新版本信息：10200011,401|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：trimToCurrentLength(): void;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：trimToCurrentLength(): void;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：ArrayList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：ArrayList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.ArrayList.d.ts|
|新增(错误码)|类名：util;<br>方法or属性：function callbackWrapper(original: Function): (err: Object, value: Object) => void;<br>旧版本信息：|类名：util;<br>方法or属性：function callbackWrapper(original: Function): (err: Object, value: Object) => void;<br>新版本信息：401|@ohos.util.d.ts|
|新增(错误码)|类名：RationalNumber;<br>方法or属性：static createRationalFromString(rationalString: string): RationalNumber​;<br>旧版本信息：|类名：RationalNumber;<br>方法or属性：static createRationalFromString(rationalString: string): RationalNumber​;<br>新版本信息：401|@ohos.util.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：constructor();<br>旧版本信息：|类名：Deque;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：insertFront(element: T): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：insertFront(element: T): void;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：insertEnd(element: T): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：insertEnd(element: T): void;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：Deque;<br>方法or属性：has(element: T): boolean;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：Deque;<br>方法or属性：getFirst(): T;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：Deque;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：401,10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：Deque;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Deque;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：constructor();<br>旧版本信息：|类名：HashMap;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：HashMap;<br>方法or属性：get(key: K): V;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：setAll(map: HashMap\<K, V>): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：setAll(map: HashMap\<K, V>): void;<br>新版本信息：10200011,401|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：HashMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：10200011,401|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：HashMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>旧版本信息：|类名：HashMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：HashMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：HashMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.HashMap.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：constructor();<br>旧版本信息：|类名：HashSet;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：has(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：has(value: T): boolean;<br>新版本信息：10200011,401|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：add(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：add(value: T): boolean;<br>新版本信息：10200011,401|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：remove(value: T): boolean;<br>旧版本信息：|类名：HashSet;<br>方法or属性：remove(value: T): boolean;<br>新版本信息：10200011,401|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：HashSet;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：HashSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：10200011|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：HashSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：HashSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.HashSet.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：constructor();<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：hasAll(map: LightWeightMap\<K, V>): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasAll(map: LightWeightMap\<K, V>): boolean;<br>新版本信息：401,10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>新版本信息：10200011,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：get(key: K): V;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：getIndexOfKey(key: K): number;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getIndexOfKey(key: K): number;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：getIndexOfValue(value: V): number;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getIndexOfValue(value: V): number;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：getKeyAt(index: number): K;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getKeyAt(index: number): K;<br>新版本信息：10200011,10200001,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：setAll(map: LightWeightMap\<K, V>): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：setAll(map: LightWeightMap\<K, V>): void;<br>新版本信息：10200011,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：removeAt(index: number): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：removeAt(index: number): boolean;<br>新版本信息：10200011,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：setValueAt(index: number, newValue: V): boolean;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：setValueAt(index: number, newValue: V): boolean;<br>新版本信息：10200011,10200001,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：toString(): String;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：toString(): String;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：getValueAt(index: number): V;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：getValueAt(index: number): V;<br>新版本信息：10200011,10200001,401|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：LightWeightMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：10200011|@ohos.util.LightWeightMap.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：constructor();<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：add(obj: T): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：add(obj: T): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：addAll(set: LightWeightSet\<T>): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：addAll(set: LightWeightSet\<T>): boolean;<br>新版本信息：10200011,401|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：hasAll(set: LightWeightSet\<T>): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：hasAll(set: LightWeightSet\<T>): boolean;<br>新版本信息：10200011,401|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：has(key: T): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：has(key: T): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：equal(obj: Object): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：equal(obj: Object): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：increaseCapacityTo(minimumCapacity: number): void;<br>新版本信息：10200011,401,10200001|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：getIndexOf(key: T): number;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：getIndexOf(key: T): number;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：remove(key: T): T;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：remove(key: T): T;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：removeAt(index: number): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：removeAt(index: number): boolean;<br>新版本信息：10200011,401|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：toArray(): Array\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：toArray(): Array\<T>;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：getValueAt(index: number): T;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：getValueAt(index: number): T;<br>新版本信息：10200011,401|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LightWeightSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：LightWeightSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.LightWeightSet.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：constructor();<br>旧版本信息：|类名：LinkedList;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：add(element: T): boolean;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：get(index: number): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：get(index: number): T;<br>新版本信息：10200011,401|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：addFirst(element: T): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：addFirst(element: T): void;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：has(element: T): boolean;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：10200011,401,10200001|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：removeFirstFound(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeFirstFound(element: T): boolean;<br>新版本信息：10200011,10200010,10200017|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：removeLastFound(element: T): boolean;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：removeLastFound(element: T): boolean;<br>新版本信息：10200011,10200010,10200017|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getFirst(): T;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：getLast(): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：getLast(): T;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：set(index: number, element: T): T;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：set(index: number, element: T): T;<br>新版本信息：10200011,10200001,401|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：clone(): LinkedList\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：clone(): LinkedList\<T>;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：LinkedList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：LinkedList;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.LinkedList.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：constructor();<br>旧版本信息：|类名：List;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：add(element: T): boolean;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：get(index: number): T;<br>旧版本信息：|类名：List;<br>方法or属性：get(index: number): T;<br>新版本信息：10200011,401|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：has(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：has(element: T): boolean;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：getIndexOf(element: T): number;<br>旧版本信息：|类名：List;<br>方法or属性：getIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：removeByIndex(index: number): T;<br>旧版本信息：|类名：List;<br>方法or属性：removeByIndex(index: number): T;<br>新版本信息：10200011,10200001,401|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：remove(element: T): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：remove(element: T): boolean;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：getLastIndexOf(element: T): number;<br>旧版本信息：|类名：List;<br>方法or属性：getLastIndexOf(element: T): number;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：getFirst(): T;<br>旧版本信息：|类名：List;<br>方法or属性：getFirst(): T;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：getLast(): T;<br>旧版本信息：|类名：List;<br>方法or属性：getLast(): T;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：set(index: number, element: T): T;<br>旧版本信息：|类名：List;<br>方法or属性：set(index: number, element: T): T;<br>新版本信息：10200011,10200001,401|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：equal(obj: Object): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：equal(obj: Object): boolean;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, List?: List\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：List;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, List?: List\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：sort(comparator: (firstValue: T, secondValue: T) => number): void;<br>旧版本信息：|类名：List;<br>方法or属性：sort(comparator: (firstValue: T, secondValue: T) => number): void;<br>新版本信息：401,10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：List;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, list?: List\<T>) => T,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：List;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, list?: List\<T>) => T,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：convertToArray(): Array\<T>;<br>旧版本信息：|类名：List;<br>方法or属性：convertToArray(): Array\<T>;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：List;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：List;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：List;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.List.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：constructor();<br>旧版本信息：|类名：PlainArray;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：clone(): PlainArray\<T>;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：clone(): PlainArray\<T>;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：has(key: number): boolean;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：has(key: number): boolean;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：get(key: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：get(key: number): T;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：getIndexOfKey(key: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getIndexOfKey(key: number): number;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：getIndexOfValue(value: T): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getIndexOfValue(value: T): number;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：getKeyAt(index: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getKeyAt(index: number): number;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：remove(key: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：remove(key: number): T;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：removeAt(index: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：removeAt(index: number): T;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：removeRangeFrom(index: number, size: number): number;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：removeRangeFrom(index: number, size: number): number;<br>新版本信息：10200011,10200001,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：setValueAt(index: number, value: T): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：setValueAt(index: number, value: T): void;<br>新版本信息：10200011,10200001,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：toString(): String;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：toString(): String;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：getValueAt(index: number): T;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：getValueAt(index: number): T;<br>新版本信息：10200011,10200001,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：PlainArray;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[number, T]>;<br>旧版本信息：|类名：PlainArray;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[number, T]>;<br>新版本信息：10200011|@ohos.util.PlainArray.d.ts|
|新增(错误码)|类名：Queue;<br>方法or属性：constructor();<br>旧版本信息：|类名：Queue;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.Queue.d.ts|
|新增(错误码)|类名：Queue;<br>方法or属性：add(element: T): boolean;<br>旧版本信息：|类名：Queue;<br>方法or属性：add(element: T): boolean;<br>新版本信息：10200011|@ohos.util.Queue.d.ts|
|新增(错误码)|类名：Queue;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：Queue;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.Queue.d.ts|
|新增(错误码)|类名：Queue;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Queue;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.Queue.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：constructor();<br>旧版本信息：|类名：Stack;<br>方法or属性：constructor();<br>新版本信息：10200012|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：Stack;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：peek(): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：peek(): T;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：pop(): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：pop(): T;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：push(item: T): T;<br>旧版本信息：|类名：Stack;<br>方法or属性：push(item: T): T;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：locate(element: T): number;<br>旧版本信息：|类名：Stack;<br>方法or属性：locate(element: T): number;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：Stack;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：Stack;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：Stack;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.Stack.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：constructor(comparator?: (firstValue: K, secondValue: K) => boolean);<br>旧版本信息：|类名：TreeMap;<br>方法or属性：constructor(comparator?: (firstValue: K, secondValue: K) => boolean);<br>新版本信息：10200012,401|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：hasKey(key: K): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：hasKey(key: K): boolean;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：hasValue(value: V): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：hasValue(value: V): boolean;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：get(key: K): V;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：get(key: K): V;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：getFirstKey(): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getFirstKey(): K;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：getLastKey(): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getLastKey(): K;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：setAll(map: TreeMap\<K, V>): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：setAll(map: TreeMap\<K, V>): void;<br>新版本信息：10200011,401|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：set(key: K, value: V): Object;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：set(key: K, value: V): Object;<br>新版本信息：10200011,401|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：remove(key: K): V;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：remove(key: K): V;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：getLowerKey(key: K): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getLowerKey(key: K): K;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：getHigherKey(key: K): K;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：getHigherKey(key: K): K;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：keys(): IterableIterator\<K>;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：values(): IterableIterator\<V>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：values(): IterableIterator\<V>;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：replace(key: K, newValue: V): boolean;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：entries(): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>旧版本信息：|类名：TreeMap;<br>方法or属性：[Symbol.iterator](): IterableIterator\<[K, V]>;<br>新版本信息：10200011|@ohos.util.TreeMap.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：constructor(comparator?: (firstValue: T, secondValue: T) => boolean)<br>旧版本信息：|类名：TreeSet;<br>方法or属性：constructor(comparator?: (firstValue: T, secondValue: T) => boolean)<br>新版本信息：10200012,401|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：isEmpty(): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：isEmpty(): boolean;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：has(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：has(value: T): boolean;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：add(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：add(value: T): boolean;<br>新版本信息：401,10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：remove(value: T): boolean;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：remove(value: T): boolean;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：clear(): void;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：clear(): void;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：getFirstValue(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getFirstValue(): T;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：getLastValue(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getLastValue(): T;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：getLowerValue(key: T): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getLowerValue(key: T): T;<br>新版本信息：10200011,401|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：getHigherValue(key: T): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：getHigherValue(key: T): T;<br>新版本信息：10200011,401|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：popFirst(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：popFirst(): T;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：popLast(): T;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：popLast(): T;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void,<br><br>  thisArg?: Object): void;<br>新版本信息：10200011,401|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：values(): IterableIterator\<T>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：values(): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：entries(): IterableIterator\<[T, T]>;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：TreeSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>旧版本信息：|类名：TreeSet;<br>方法or属性：[Symbol.iterator](): IterableIterator\<T>;<br>新版本信息：10200011|@ohos.util.TreeSet.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：constructor(buffer: ArrayBuffer \| DataView, encoding?: string);<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setAttributes(name: string, value: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setAttributes(name: string, value: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：addEmptyElement(name: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：addEmptyElement(name: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：startElement(name: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：startElement(name: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setNamespace(prefix: string, namespace: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setNamespace(prefix: string, namespace: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setComment(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setComment(text: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setCDATA(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setCDATA(text: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setText(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setText(text: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlSerializer;<br>方法or属性：setDocType(text: string): void;<br>旧版本信息：|类名：XmlSerializer;<br>方法or属性：setDocType(text: string): void;<br>新版本信息：401|@ohos.xml.d.ts|
|新增(错误码)|类名：XmlPullParser;<br>方法or属性：parse(option: ParseOptions): void;<br>旧版本信息：|类名：XmlPullParser;<br>方法or属性：parse(option: ParseOptions): void;<br>新版本信息：401|@ohos.xml.d.ts|
|错误码有变化|类名：ArrayList;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：If|类名：ArrayList;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：10200001,10200011,401|@ohos.util.ArrayList.d.ts|
|错误码有变化|类名：ArrayList;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>旧版本信息：If|类名：ArrayList;<br>方法or属性：removeByRange(fromIndex: number, toIndex: number): void;<br>新版本信息：10200001,10200011,401|@ohos.util.ArrayList.d.ts|
|错误码有变化|类名：ArrayList;<br>方法or属性：subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>;<br>旧版本信息：If|类名：ArrayList;<br>方法or属性：subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>;<br>新版本信息：10200001,10200011,401|@ohos.util.ArrayList.d.ts|
|错误码有变化|类名：Deque;<br>方法or属性：getLast(): T;<br>旧版本信息：an|类名：Deque;<br>方法or属性：getLast(): T;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|错误码有变化|类名：Deque;<br>方法or属性：popFirst(): T;<br>旧版本信息：an|类名：Deque;<br>方法or属性：popFirst(): T;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|错误码有变化|类名：Deque;<br>方法or属性：popLast(): T;<br>旧版本信息：an|类名：Deque;<br>方法or属性：popLast(): T;<br>新版本信息：10200011|@ohos.util.Deque.d.ts|
|错误码有变化|类名：LinkedList;<br>方法or属性：insert(index: number, element: T): void;<br>旧版本信息：If|类名：LinkedList;<br>方法or属性：insert(index: number, element: T): void;<br>新版本信息：10200011,401,10200001|@ohos.util.LinkedList.d.ts|
|错误码有变化|类名：LinkedList;<br>方法or属性：removeFirst(): T;<br>旧版本信息：NoSuchElementException|类名：LinkedList;<br>方法or属性：removeFirst(): T;<br>新版本信息：10200011,10200010|@ohos.util.LinkedList.d.ts|
|错误码有变化|类名：LinkedList;<br>方法or属性：removeLast(): T;<br>旧版本信息：NoSuchElementException|类名：LinkedList;<br>方法or属性：removeLast(): T;<br>新版本信息：10200011,10200010|@ohos.util.LinkedList.d.ts|
|错误码有变化|类名：List;<br>方法or属性：insert(element: T, index: number): void;<br>旧版本信息：If|类名：List;<br>方法or属性：insert(element: T, index: number): void;<br>新版本信息：10200011,10200001,401|@ohos.util.List.d.ts|
|错误码有变化|类名：List;<br>方法or属性：getSubList(fromIndex: number, toIndex: number): List\<T>;<br>旧版本信息：If|类名：List;<br>方法or属性：getSubList(fromIndex: number, toIndex: number): List\<T>;<br>新版本信息：10200011,10200001,401|@ohos.util.List.d.ts|
|错误码有变化|类名：PlainArray;<br>方法or属性：add(key: number, value: T): void;<br>旧版本信息：Throws|类名：PlainArray;<br>方法or属性：add(key: number, value: T): void;<br>新版本信息：10200011,401|@ohos.util.PlainArray.d.ts|
|错误码有变化|类名：Queue;<br>方法or属性：getFirst(): T;<br>旧版本信息：an|类名：Queue;<br>方法or属性：getFirst(): T;<br>新版本信息：10200011|@ohos.util.Queue.d.ts|
|错误码有变化|类名：Queue;<br>方法or属性：pop(): T;<br>旧版本信息：an|类名：Queue;<br>方法or属性：pop(): T;<br>新版本信息：10200011|@ohos.util.Queue.d.ts|
|访问级别有变化|类名：ChildProcess;<br>方法or属性：export interface ChildProcess<br>旧版本信息：|类名：ChildProcess;<br>方法or属性：export interface ChildProcess<br>新版本信息：systemapi|@ohos.process.d.ts|
|函数有变化|类名：process;<br>方法or属性：function runCmd(command: string,<br><br>        options?: { timeout : number, killSignal : number \| string, maxBuffer : number }): ChildProcess;|类名：process;<br>方法or属性：function runCmd(command: string,<br><br>        options?: { timeout?: number, killSignal?: number \| string, maxBuffer?: number }): ChildProcess;|@ohos.process.d.ts|
|函数有变化|类名：URLSearchParams;<br>方法or属性：forEach(callbackfn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|@ohos.url.d.ts|
|函数有变化|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T,<br><br>  thisArg?: Object): void;|类名：ArrayList;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T,<br><br>  thisArg?: Object): void;|@ohos.util.ArrayList.d.ts|
|函数有变化|类名：ArrayList;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void,<br><br>  thisArg?: Object): void;|类名：ArrayList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.ArrayList.d.ts|
|函数有变化|类名：Deque;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, deque?: Deque\<T>) => void,<br><br>  thisArg?: Object): void;|类名：Deque;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.Deque.d.ts|
|函数有变化|类名：HashMap;<br>方法or属性：forEach(callbackfn: (value?: V, key?: K, map?: HashMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|类名：HashMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.HashMap.d.ts|
|函数有变化|类名：HashSet;<br>方法or属性：forEach(callbackfn: (value?: T, key?: T, set?: HashSet\<T>) => void,<br><br>  thisArg?: Object): void;|类名：HashSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.HashSet.d.ts|
|函数有变化|类名：LightWeightMap;<br>方法or属性：forEach(callbackfn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|类名：LightWeightMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.LightWeightMap.d.ts|
|函数有变化|类名：LightWeightSet;<br>方法or属性：forEach(callbackfn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void,<br><br>  thisArg?: Object): void;|类名：LightWeightSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.LightWeightSet.d.ts|
|函数有变化|类名：LinkedList;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void,<br><br>  thisArg?: Object): void;|类名：LinkedList;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.LinkedList.d.ts|
|函数有变化|类名：List;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, List?: List\<T>) => void,<br><br>  thisArg?: Object): void;|类名：List;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, List?: List\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.List.d.ts|
|函数有变化|类名：List;<br>方法or属性：replaceAllElements(callbackfn: (value: T, index?: number, list?: List\<T>) => T,<br><br>  thisArg?: Object): void;|类名：List;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, list?: List\<T>) => T,<br><br>  thisArg?: Object): void;|@ohos.util.List.d.ts|
|函数有变化|类名：PlainArray;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,<br><br>  thisArg?: Object): void;|类名：PlainArray;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.PlainArray.d.ts|
|函数有变化|类名：Queue;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, Queue?: Queue\<T>) => void,<br><br>  thisArg?: Object): void;|类名：Queue;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.Queue.d.ts|
|函数有变化|类名：Stack;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, stack?: Stack\<T>) => void,<br><br>  thisArg?: Object): void;|类名：Stack;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.Stack.d.ts|
|函数有变化|类名：TreeMap;<br>方法or属性：forEach(callbackfn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|类名：TreeMap;<br>方法or属性：forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.TreeMap.d.ts|
|函数有变化|类名：TreeSet;<br>方法or属性：forEach(callbackfn: (value?: T, key?: T, set?: TreeSet\<T>) => void,<br><br>  thisArg?: Object): void;|类名：TreeSet;<br>方法or属性：forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.TreeSet.d.ts|
|函数有变化|类名：Vector;<br>方法or属性：replaceAllElements(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => T,<br><br>  thisArg?: Object): void;|类名：Vector;<br>方法or属性：replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => T,<br><br>  thisArg?: Object): void;|@ohos.util.Vector.d.ts|
|函数有变化|类名：Vector;<br>方法or属性：forEach(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => void,<br><br>  thisArg?: Object): void;|类名：Vector;<br>方法or属性：forEach(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => void,<br><br>  thisArg?: Object): void;|@ohos.util.Vector.d.ts|
