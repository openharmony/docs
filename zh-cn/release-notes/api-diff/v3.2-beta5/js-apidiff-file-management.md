| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.file.environment<br>类名: Environment|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getStorageDataDir(): Promise<string>;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getStorageDataDir(callback: AsyncCallback<string>): void;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getUserDataDir(): Promise<string>;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getUserDataDir(callback: AsyncCallback<string>): void;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function getFileAccessAbilityInfo(callback: AsyncCallback<Array<Want>>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function getFileAccessAbilityInfo(): Promise<Array<Want>>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function createFileAccessHelper(context: Context): FileAccessHelper;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function createFileAccessHelper(context: Context, wants: Array<Want>): FileAccessHelper;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: uri: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: fileName: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: mode: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: size: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: mtime: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: mimeType: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: listFile(filter?: Filter): FileIterator;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileInfo<br>方法 or 属性: scanFile(filter?: Filter): FileIterator;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileIterator|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileIterator<br>方法 or 属性: next(): {value: FileInfo, done: boolean}|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: deviceType: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: uri: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: displayName: string;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: deviceFlags: number;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: listFile(filter?: Filter): FileIterator;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootInfo<br>方法 or 属性: scanFile(filter?: Filter): FileIterator;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootIterator|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: RootIterator<br>方法 or 属性: next(): {value: RootInfo, done: boolean}|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: OPENFLAGS|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性: READ = 0o0|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性: WRITE = 0o1|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性: WRITE_READ = 0o2|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: openFile(uri: string, flags: OPENFLAGS) : Promise<number>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback<number>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: createFile(uri: string, displayName: string) : Promise<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: createFile(uri: string, displayName: string, callback: AsyncCallback<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: mkDir(parentUri: string, displayName: string) : Promise<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: mkDir(parentUri: string, displayName: string, callback: AsyncCallback<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: delete(uri: string) : Promise<number>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: delete(uri: string, callback: AsyncCallback<number>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: move(sourceFile: string, destFile: string) : Promise<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: move(sourceFile: string, destFile: string, callback: AsyncCallback<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: rename(uri: string, displayName: string) : Promise<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: rename(uri: string, displayName: string, callback: AsyncCallback<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: access(sourceFileUri: string) : Promise<boolean>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: access(sourceFileUri: string, callback: AsyncCallback<boolean>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: getRoots(): Promise<RootIterator>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: getRoots(callback:AsyncCallback<RootIterator>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: fileExtensionInfo|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_LOCAL_DISK = 1|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_SHARED_DISK|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_SHARED_TERMINAL|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_NETWORK_NEIGHBORHOODS|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_EXTERNAL_MTP|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_EXTERNAL_USB|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性: DEVICE_EXTERNAL_CLOUD|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceFlag|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceFlag<br>方法 or 属性: const SUPPORTS_READ = 0b1;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DeviceFlag<br>方法 or 属性: const SUPPORTS_WRITE = 0b10;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DocumentFlag|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性: const REPRESENTS_FILE = 0b1;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性: const REPRESENTS_DIR = 0b10;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性: const SUPPORTS_READ = 0b100;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性: const SUPPORTS_WRITE = 0b1000;|@ohos.file.fileExtensionInfo.d.ts|
|新增|NA|模块名: ohos.file.fileuri<br>类名: fileUri|@ohos.file.fileuri.d.ts|
|新增|NA|模块名: ohos.file.fileuri<br>类名: fileUri<br>方法 or 属性: function getUriFromPath(path: string): string;|@ohos.file.fileuri.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function access(path: string): Promise<boolean>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function access(path: string, callback: AsyncCallback<boolean>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function accessSync(path: string): boolean;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function close(file: number \| File): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function close(file: number \| File, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function closeSync(fd: number \| File): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function createStream(path: string, mode: string): Promise<Stream>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function createStream(path: string, mode: string, callback: AsyncCallback<Stream>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function createStreamSync(path: string, mode: string): Stream;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdatasync(fd: number): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdatasync(fd: number, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdatasyncSync(fd: number): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdopenStream(fd: number, mode: string): Promise<Stream>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdopenStream(fd: number, mode: string, callback: AsyncCallback<Stream>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fdopenStreamSync(fd: number, mode: string): Stream;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fsync(fd: number): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fsync(fd: number, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function fsyncSync(fd: number): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function lstat(path: string): Promise<Stat>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function lstat(path: string, callback: AsyncCallback<Stat>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function lstatSync(path: string): Stat;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdir(path: string): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdir(path: string, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdirSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdtemp(prefix: string): Promise<string>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdtemp(prefix: string, callback: AsyncCallback<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function mkdtempSync(prefix: string): string;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function readText(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise<string>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function readText(filePath: string, callback: AsyncCallback<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function readText(filePath: string, options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function readTextSync(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function rename(oldPath: string, newPath: string): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function rename(oldPath: string, newPath: string, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function renameSync(oldPath: string, newPath: string): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function rmdir(path: string): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function rmdir(path: string, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function rmdirSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function symlink(target: string, srcPath: string): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function symlinkSync(target: string, srcPath: string): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function unlink(path: string): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function unlink(path: string, callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：fileIo<br>方法or属性：function unlinkSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stat<br>方法or属性：readonly ino: bigint;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：close(): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：close(): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：close(callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：close(callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：closeSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：closeSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：flush(): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：flush(): Promise<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：flush(callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：flush(callback: AsyncCallback<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：flushSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：flushSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：write(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): Promise<number>;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：write(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): Promise<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：write(buffer: ArrayBuffer \| string, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：write(buffer: ArrayBuffer \| string, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：write(buffer: ArrayBuffer \| string, options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：write(buffer: ArrayBuffer \| string, options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：writeSync(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：writeSync(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：read(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): Promise<number>;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：read(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): Promise<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：read(buffer: ArrayBuffer, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：read(buffer: ArrayBuffer, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：read(buffer: ArrayBuffer, options: {<br>        offset?: number;<br>        length?: number;<br>    }, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：read(buffer: ArrayBuffer, options: {<br>        offset?: number;<br>        length?: number;<br>    }, callback: AsyncCallback<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性：readSync(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|类名：Stream<br>方法or属性：readSync(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: Hash|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: Hash<br>方法 or 属性: function hash(path: string, algorithm: string): Promise<string>;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: Hash<br>方法 or 属性: function hash(path: string, algorithm: string, callback: AsyncCallback<string>): void;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: dataLevel<br>方法 or 属性: type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabel(path: string, type: dataLevel): Promise<void>;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabel(path: string, type: dataLevel, callback: AsyncCallback<void>): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabelSync(path: string, type: dataLevel): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabel(path: string): Promise<string>;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabel(path: string, callback: AsyncCallback<string>): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabelSync(path: string): string;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: Statfs|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性: function getFreeSize(path: string): Promise<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性: function getFreeSize(path: string, callback: AsyncCallback<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性: function getTotalSize(path: string): Promise<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: Statfs<br>方法 or 属性: function getTotalSize(path: string, callback: AsyncCallback<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare|@ohos.fileshare.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare<br>方法 or 属性: function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback<void>): void;|@ohos.fileshare.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare<br>方法 or 属性: function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise<void>;|@ohos.fileshare.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: fileAccess|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: fileAccess<br>方法 or 属性：function getFileAccessAbilityInfo(callback: AsyncCallback<Array<Want>>): void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: fileAccess<br>方法 or 属性：function getFileAccessAbilityInfo(): Promise<Array<Want>>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: fileAccess<br>方法 or 属性：function createFileAccessHelper(context: Context): FileAccessHelper;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: fileAccess<br>方法 or 属性：function createFileAccessHelper(context: Context, wants: Array<Want>): FileAccessHelper;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：uri: string;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：fileName: string;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：mode: number;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：size: number;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：mtime: number;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：mimeType: string;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：listFile(filter?: Filter): FileIterator;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileInfo<br>方法 or 属性：scanFile(filter?: Filter): FileIterator;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileIterator|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileIterator<br>方法 or 属性：next(): {value: FileInfo, done: boolean}|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：deviceType: number;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：uri: string;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：displayName: string;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：deviceFlags: number;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：listFile(filter?: Filter): FileIterator;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootInfo<br>方法 or 属性：scanFile(filter?: Filter): FileIterator;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootIterator|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: RootIterator<br>方法 or 属性：next(): {value: RootInfo, done: boolean}|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: OPENFLAGS|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性：READ = 0o0|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性：WRITE = 0o1|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: OPENFLAGS<br>方法 or 属性：WRITE_READ = 0o2|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：openFile(uri: string, flags: OPENFLAGS) : Promise<number>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback<number>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：createFile(uri: string, displayName: string) : Promise<string>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：createFile(uri: string, displayName: string, callback: AsyncCallback<string>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：mkDir(parentUri: string, displayName: string) : Promise<string>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：mkDir(parentUri: string, displayName: string, callback: AsyncCallback<string>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：delete(uri: string) : Promise<number>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：delete(uri: string, callback: AsyncCallback<number>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：move(sourceFile: string, destFile: string) : Promise<string>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：move(sourceFile: string, destFile: string, callback: AsyncCallback<string>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：rename(uri: string, displayName: string) : Promise<string>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：rename(uri: string, displayName: string, callback: AsyncCallback<string>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：access(sourceFileUri: string) : Promise<boolean>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：access(sourceFileUri: string, callback: AsyncCallback<boolean>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：getRoots(): Promise<RootIterator>;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.data.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性：getRoots(callback:AsyncCallback<RootIterator>) : void;|NA|@ohos.data.fileAccess.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getStorageDataDir(callback: AsyncCallback<string>): void;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getStorageDataDir(): Promise<string>;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getUserDataDir(callback: AsyncCallback<string>): void;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getUserDataDir(): Promise<string>;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: fileExtensionInfo|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_LOCAL_DISK = 1|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_SHARED_DISK|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_SHARED_TERMINAL|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_NETWORK_NEIGHBORHOODS|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_EXTERNAL_MTP|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_EXTERNAL_USB|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceType<br>方法 or 属性：DEVICE_EXTERNAL_CLOUD|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceFlag|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceFlag<br>方法 or 属性：const SUPPORTS_READ = 0b1;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DeviceFlag<br>方法 or 属性：const SUPPORTS_WRITE = 0b10;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DocumentFlag|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性：const REPRESENTS_FILE = 0b1;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性：const REPRESENTS_DIR = 0b10;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性：const SUPPORTS_READ = 0b100;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.fileExtensionInfo<br>类名: DocumentFlag<br>方法 or 属性：const SUPPORTS_WRITE = 0b1000;|NA|@ohos.fileExtensionInfo.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: dataLevel<br>方法 or 属性：type dataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback<void>): void;|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function setSecurityLabel(path:string, type:dataLevel): Promise<void>;|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function setSecurityLabelSync(path:string, type:dataLevel): void;|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function getSecurityLabel(path:string, callback: AsyncCallback<string>): void;|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function getSecurityLabel(path:string): Promise<string>;|NA|@ohos.securityLabel.d.ts|
|删除|模块名: ohos.securityLabel<br>类名: securityLabel<br>方法 or 属性：function getSecurityLabelSync(path:string): string;|NA|@ohos.securityLabel.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, mode?: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, mode?: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.access |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function accessSync(path: string, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function accessSync(path: string, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.accessSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function close(fd: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function close(fd: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.close |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function close(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function close(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function closeSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function closeSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.closeSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFileSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string): Promise<Stream>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string): Promise<Stream>;<br>废弃版本：9<br>代替接口：ohos.file.fs.createStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string, callback: AsyncCallback<Stream>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string, callback: AsyncCallback<Stream>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStreamSync(path: string, mode: string): Stream;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStreamSync(path: string, mode: string): Stream;<br>废弃版本：9<br>代替接口：ohos.file.fs.createStreamSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number): Promise<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chownSync(path: string, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chownSync(path: string, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number): Promise<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmodSync(path: string, mode: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmodSync(path: string, mode: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsync(fd: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsync(fd: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fsync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsync(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsync(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsyncSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsyncSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fsyncSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdatasync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasyncSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasyncSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdatasyncSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number): Promise<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchownSync(fd: number, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchownSync(fd: number, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number): Promise<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmodSync(fd: number, mode: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmodSync(fd: number, mode: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string): Promise<Stream>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string): Promise<Stream>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdopenStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string, callback: AsyncCallback<Stream>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string, callback: AsyncCallback<Stream>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStreamSync(fd: number, mode: string): Stream;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStreamSync(fd: number, mode: string): Stream;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdopenStreamSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string): Promise<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string): Promise<string>;<br>废弃版本：9<br>代替接口：ohos.file.hash.hash |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback<string>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number): Promise<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchownSync(path: string, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchownSync(path: string, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstat(path: string): Promise<Stat>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstat(path: string): Promise<Stat>;<br>废弃版本：9<br>代替接口：ohos.file.fs.lstat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstat(path: string, callback: AsyncCallback<Stat>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstat(path: string, callback: AsyncCallback<Stat>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstatSync(path: string): Stat;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstatSync(path: string): Stat;<br>废弃版本：9<br>代替接口：ohos.file.fs.lstatSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode?: number): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode?: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode: number, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdirSync(path: string, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdirSync(path: string, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdirSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string): Promise<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string): Promise<string>;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdtemp |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string, callback: AsyncCallback<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string, callback: AsyncCallback<string>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtempSync(prefix: string): string;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtempSync(prefix: string): string;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdtempSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise<string>;<br>废弃版本：9<br>代替接口：ohos.file.fs.readText |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback<string>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readTextSync(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readTextSync(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;<br>废弃版本：9<br>代替接口：ohos.file.fs.readTextSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.rename |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function renameSync(oldPath: string, newPath: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function renameSync(oldPath: string, newPath: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.renameSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdir(path: string): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdir(path: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.rmdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdir(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdir(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdirSync(path: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdirSync(path: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.rmdirSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.symlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlinkSync(target: string, srcPath: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlinkSync(target: string, srcPath: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.symlinkSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlink(path: string): Promise<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlink(path: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.unlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlink(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlink(path: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlinkSync(path: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlinkSync(path: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.unlinkSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Stream<br>废弃版本：N/A|类名：Stream<br>废弃版本：9<br>代替接口：ohos.file.fs.Stream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getFreeSize   |@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string): Promise<number>;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string): Promise<number>;<br>废弃版本：9|@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getTotalSize   |@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string): Promise<number>;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string): Promise<number>;<br>废弃版本：9|@ohos.statfs.d.ts|
