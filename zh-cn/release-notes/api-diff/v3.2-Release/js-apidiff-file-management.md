| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.file.environment<br>类名: Environment|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getStorageDataDir(): Promise\<string>;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getStorageDataDir(callback: AsyncCallback\<string>): void;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getUserDataDir(): Promise\<string>;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.environment<br>类名: Environment<br>方法 or 属性: function getUserDataDir(callback: AsyncCallback\<string>): void;|@ohos.file.environment.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function getFileAccessAbilityInfo(callback: AsyncCallback\<Array\<Want>>): void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function getFileAccessAbilityInfo(): Promise\<Array\<Want>>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function createFileAccessHelper(context: Context): FileAccessHelper;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: fileAccess<br>方法 or 属性: function createFileAccessHelper(context: Context, wants: Array\<Want>): FileAccessHelper;|@ohos.file.fileAccess.d.ts|
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
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: openFile(uri: string, flags: OPENFLAGS) : Promise\<number>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback\<number>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: createFile(uri: string, displayName: string) : Promise\<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: createFile(uri: string, displayName: string, callback: AsyncCallback\<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: mkDir(parentUri: string, displayName: string) : Promise\<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: mkDir(parentUri: string, displayName: string, callback: AsyncCallback\<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: delete(uri: string) : Promise\<number>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: delete(uri: string, callback: AsyncCallback\<number>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: move(sourceFile: string, destFile: string) : Promise\<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: move(sourceFile: string, destFile: string, callback: AsyncCallback\<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: rename(uri: string, displayName: string) : Promise\<string>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: rename(uri: string, displayName: string, callback: AsyncCallback\<string>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: access(sourceFileUri: string) : Promise\<boolean>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: access(sourceFileUri: string, callback: AsyncCallback\<boolean>) : void;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: getRoots(): Promise\<RootIterator>;|@ohos.file.fileAccess.d.ts|
|新增|NA|模块名: ohos.file.fileAccess<br>类名: FileAccessHelper<br>方法 or 属性: getRoots(callback:AsyncCallback\<RootIterator>) : void;|@ohos.file.fileAccess.d.ts|
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
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const READ_ONLY = 0o0;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const WRITE_ONLY = 0o1;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const READ_WRITE = 0o2;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const CREATE = 0o100;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const TRUNC = 0o1000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const APPEND = 0o2000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const NONBLOCK = 0o4000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const DIR = 0o200000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const NOFOLLOW = 0o400000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: OpenMode<br>方法 or 属性: const SYNC = 0o4010000;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function access(path: string): Promise\<boolean>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function access(path: string, callback: AsyncCallback\<boolean>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function accessSync(path: string): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function close(file: number \| File): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function close(file: number \| File, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function closeSync(fd: number \| File): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function createStream(path: string, mode: string): Promise\<Stream>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function createStreamSync(path: string, mode: string): Stream;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdatasync(fd: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdatasync(fd: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdatasyncSync(fd: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdopenStream(fd: number, mode: string): Promise\<Stream>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fdopenStreamSync(fd: number, mode: string): Stream;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fsync(fd: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fsync(fd: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function fsyncSync(fd: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): Promise\<string[]>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFile(path: string, options: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}, callback: AsyncCallback\<string[]>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function listFileSync(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): string[];|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function lstat(path: string): Promise\<Stat>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function lstat(path: string, callback: AsyncCallback\<Stat>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function lstatSync(path: string): Stat;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdir(path: string): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdir(path: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdirSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdtemp(prefix: string): Promise\<string>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function mkdtempSync(prefix: string): string;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, mode?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function moveFileSync(src: string, dest: string, mode?: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function open(path: string, mode?: number): Promise\<File>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function open(path: string, callback: AsyncCallback\<File>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function open(path: string, mode: number, callback: AsyncCallback\<File>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function openSync(path: string, mode?: number): File;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function read(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>}): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function read(fd: number, buffer: ArrayBuffer, options: {<br>    offset?: number;<br>    length?: number;<br>}, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function readSync(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>}): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function readText(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<string>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function readText(filePath: string, callback: AsyncCallback\<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function readText(filePath: string, options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<string>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function readTextSync(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function rename(oldPath: string, newPath: string): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function renameSync(oldPath: string, newPath: string): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function rmdir(path: string): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function rmdir(path: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function rmdirSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function stat(file: string \| number): Promise\<Stat>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function stat(file: string \| number, callback: AsyncCallback\<Stat>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function statSync(file: string \| number): Stat;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function symlink(target: string, srcPath: string): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function symlinkSync(target: string, srcPath: string): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function truncate(file: string \| number, len?: number): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function truncate(file: string \| number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function truncate(file: string \| number, len: number, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function truncateSync(file: string \| number, len?: number): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function unlink(path: string): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function unlink(path: string, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function unlinkSync(path: string): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function write(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function write(fd: number, buffer: ArrayBuffer \| string, options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: fileIo<br>方法 or 属性: function writeSync(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: readonly fd: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(exclusive?: boolean): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: lock(exclusive: boolean, callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: tryLock(exclusive?: boolean): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: File<br>方法 or 属性: unlock(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly ino: bigint;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly mode: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly uid: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly gid: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly size: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly atime: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly mtime: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: readonly ctime: number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isBlockDevice(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isCharacterDevice(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isDirectory(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isFIFO(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isFile(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isSocket(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stat<br>方法 or 属性: isSymbolicLink(): boolean;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: close(): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: close(callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: closeSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: flush(): Promise\<void>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: flush(callback: AsyncCallback\<void>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: flushSync(): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: write(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: write(buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: write(buffer: ArrayBuffer \| string, options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: writeSync(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: read(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): Promise\<number>;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: read(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: read(buffer: ArrayBuffer, options: {<br>        offset?: number;<br>        length?: number;<br>    }, callback: AsyncCallback\<number>): void;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.fs<br>类名: Stream<br>方法 or 属性: readSync(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): number;|@ohos.file.fs.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash<br>方法 or 属性: function hash(path: string, algorithm: string): Promise\<string>;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.hash<br>类名: hash<br>方法 or 属性: function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;|@ohos.file.hash.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: picker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: IMAGE_TYPE = "image/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: VIDEO_TYPE = "video/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewMIMETypes<br>方法 or 属性: IMAGE_VIDEO_TYPE = "*/*"|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions<br>方法 or 属性: MIMEType?: PhotoViewMIMETypes;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectOptions<br>方法 or 属性: maxSelectNumber?: number;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult<br>方法 or 属性: photoUris: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSelectResult<br>方法 or 属性: isOriginalPhoto: boolean;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(option?: PhotoSelectOptions) : Promise\<PhotoSelectResult>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(option: PhotoSelectOptions, callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<PhotoSelectResult>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(option?: PhotoSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(option: PhotoSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: PhotoViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(option?: DocumentSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(option: DocumentSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(option?: DocumentSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(option: DocumentSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: DocumentViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSelectOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSaveOptions|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioSaveOptions<br>方法 or 属性: newFileNames?: Array\<string>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(option?: AudioSelectOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(option: AudioSelectOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: select(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(option?: AudioSaveOptions) : Promise\<Array\<string>>;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(option: AudioSaveOptions, callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.picker<br>类名: AudioViewPicker<br>方法 or 属性: save(callback: AsyncCallback\<Array\<string>>) : void;|@ohos.file.picker.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: DataLevel<br>方法 or 属性: type DataLevel = 's0'\|'s1'\|'s2'\|'s3'\|'s4';|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabel(path: string, type: DataLevel): Promise\<void>;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabel(path: string, type: DataLevel, callback: AsyncCallback\<void>): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function setSecurityLabelSync(path: string, type: DataLevel): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabel(path: string): Promise\<string>;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabel(path: string, callback: AsyncCallback\<string>): void;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.securityLabel<br>类名: securityLabel<br>方法 or 属性: function getSecurityLabelSync(path: string): string;|@ohos.file.securityLabel.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性: function getFreeSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性: function getFreeSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性: function getTotalSize(path: string): Promise\<number>;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.statvfs<br>类名: statfs<br>方法 or 属性: function getTotalSize(path: string, callback: AsyncCallback\<number>): void;|@ohos.file.statvfs.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: appSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: cacheSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: BundleStats<br>方法 or 属性: dataSize: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getBundleStats(packageName: string,  callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getBundleStats(packageName: string): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getCurrentBundleStats(): Promise\<BundleStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getSystemSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getSystemSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: total: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: audio: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: video: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: image: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: file: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: StorageStats<br>方法 or 属性: app: number;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(userId: number): Promise\<StorageStats>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getTotalSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSize(callback: AsyncCallback\<number>): void;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.storageStatistics<br>类名: storageStatistics<br>方法 or 属性: function getFreeSize(): Promise\<number>;|@ohos.file.storageStatistics.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: id: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: uuid: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: diskId: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: description: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: removable: boolean;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: state: number;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: Volume<br>方法 or 属性: path: string;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getAllVolumes(): Promise\<Array\<Volume>>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function mount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function mount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function unmount(volumeId: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function unmount(volumeId: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeByUuid(uuid: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function getVolumeById(volumeId: string): Promise\<Volume>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function setVolumeDescription(uuid: string, description: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function format(volumeId: string, fsType: string): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function partition(diskId: string, type: number, callback: AsyncCallback\<void>): void;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.file.volumeManager<br>类名: volumeManager<br>方法 or 属性: function partition(diskId: string, type: number): Promise\<void>;|@ohos.file.volumeManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: userFileManager|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ChangeEvent<br>方法 or 属性: type ChangeEvent = 'deviceChange' \| 'albumChange' \| 'imageChange' \| 'audioChange' \| 'videoChange' \| 'remoteFileChange';|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: userFileManager<br>方法 or 属性: function getUserFileMgr(context: Context): UserFileManager;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileType<br>方法 or 属性: IMAGE = 1|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileType<br>方法 or 属性: VIDEO|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileType<br>方法 or 属性: AUDIO|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: readonly uri: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: readonly fileType: FileType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: displayName: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: get(member: string): MemberType;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: set(member: string, value: string): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: commitModify(callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: commitModify(): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: open(mode: string, callback: AsyncCallback\<number>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: open(mode: string): Promise\<number>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: close(fd: number, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: close(fd: number): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: getThumbnail(size: image.Size, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: getThumbnail(size?: image.Size): Promise\<image.PixelMap>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FileAsset<br>方法 or 属性: favorite(isFavorite: boolean): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: DISPLAY_NAME|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: DATE_ADDED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: DATE_MODIFIED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: TITLE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: ARTIST|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: AUDIOALBUM|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: DURATION|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AudioKey<br>方法 or 属性: FAVORITE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: FILE_TYPE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: DISPLAY_NAME|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: DATE_ADDED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: DATE_MODIFIED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: TITLE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: DURATION|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: WIDTH|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: HEIGHT|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: DATE_TAKEN|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: ORIENTATION|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: ImageVideoKey<br>方法 or 属性: FAVORITE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey<br>方法 or 属性: URI|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey<br>方法 or 属性: FILE_TYPE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey<br>方法 or 属性: ALBUM_NAME|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey<br>方法 or 属性: DATE_ADDED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumKey<br>方法 or 属性: DATE_MODIFIED|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchOptions|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchOptions<br>方法 or 属性: fetchColumns: Array\<string>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchOptions<br>方法 or 属性: predicates: dataSharePredicates.DataSharePredicates;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumFetchOptions|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AlbumFetchOptions<br>方法 or 属性: predicates: dataSharePredicates.DataSharePredicates;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getCount(): number;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: isAfterLast(): boolean;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: close(): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getFirstObject(callback: AsyncCallback\<T>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getFirstObject(): Promise\<T>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getNextObject(callback: AsyncCallback\<T>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getNextObject(): Promise\<T>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getLastObject(callback: AsyncCallback\<T>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getLastObject(): Promise\<T>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getPositionObject(index: number, callback: AsyncCallback\<T>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: FetchResult<br>方法 or 属性: getPositionObject(index: number): Promise\<T>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: albumName: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: readonly albumUri: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: readonly dateModified: number;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: readonly count: number;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: readonly coverUri: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: getPhotoAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: AbsAlbum<br>方法 or 属性: getPhotoAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性: commitModify(callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: Album<br>方法 or 属性: commitModify(): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPhotoAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPhotoAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: createPhotoAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: createPhotoAsset(displayName: string, albumUri?: string): Promise\<FileAsset>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback\<FetchResult\<Album>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPhotoAlbums(options: AlbumFetchOptions): Promise\<FetchResult\<Album>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback\<FetchResult\<PrivateAlbum>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getPrivateAlbum(type: PrivateAlbumType): Promise\<FetchResult\<PrivateAlbum>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getAudioAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getAudioAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: delete(uri: string, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: delete(uri: string): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: on(type: ChangeEvent, callback: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: off(type: ChangeEvent, callback?: Callback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getActivePeers(): Promise\<Array\<PeerInfo>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: getAllPeers(): Promise\<Array\<PeerInfo>>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: release(callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: UserFileManager<br>方法 or 属性: release(): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PeerInfo|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PeerInfo<br>方法 or 属性: readonly deviceName: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PeerInfo<br>方法 or 属性: readonly networkId: string;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PeerInfo<br>方法 or 属性: readonly isOnline: boolean;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbumType|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbumType<br>方法 or 属性: TYPE_FAVORITE|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbumType<br>方法 or 属性: TYPE_TRASH|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbum|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbum<br>方法 or 属性: delete(uri: string, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbum<br>方法 or 属性: delete(uri: string): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbum<br>方法 or 属性: recover(uri: string, callback: AsyncCallback\<void>): void;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.filemanagement.userFileManager<br>类名: PrivateAlbum<br>方法 or 属性: recover(uri: string): Promise\<void>;|@ohos.filemanagement.userFileManager.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare|@ohos.fileshare.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare<br>方法 or 属性: function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback\<void>): void;|@ohos.fileshare.d.ts|
|新增|NA|模块名: ohos.fileshare<br>类名: fileShare<br>方法 or 属性: function grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise\<void>;|@ohos.fileshare.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getStorageDataDir(callback: AsyncCallback\<string>): void;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getStorageDataDir(): Promise\<string>;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getUserDataDir(callback: AsyncCallback\<string>): void;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.environment<br>类名: Environment<br>方法 or 属性：function getUserDataDir(): Promise\<string>;|NA|@ohos.environment.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getTotalSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void;|NA|@ohos.storageStatistics.d.ts|
|删除|模块名: ohos.storageStatistics<br>类名: storageStatistics<br>方法 or 属性：function getFreeSizeOfVolume(volumeUuid: string): Promise\<number>;|NA|@ohos.storageStatistics.d.ts|
|废弃版本有变化|类名：document<br>方法 or 属性：function choose(types?: string[]): Promise\<string>;<br>废弃版本：N/A|类名：document<br>方法 or 属性：function choose(types?: string[]): Promise\<string>;<br>废弃版本：9<br>代替接口：N/A|@ohos.document.d.ts|
|废弃版本有变化|类名：document<br>方法 or 属性：function choose(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：document<br>方法 or 属性：function choose(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.document.d.ts|
|废弃版本有变化|类名：document<br>方法 or 属性：function choose(types: string[], callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：document<br>方法 or 属性：function choose(types: string[], callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.document.d.ts|
|废弃版本有变化|类名：document<br>方法 or 属性：function show(uri: string, type: string): Promise\<void>;<br>废弃版本：N/A|类名：document<br>方法 or 属性：function show(uri: string, type: string): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.document.d.ts|
|废弃版本有变化|类名：document<br>方法 or 属性：function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：document<br>方法 or 属性：function show(uri: string, type: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.document.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, mode?: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, mode?: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.access |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.access |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function access(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.access |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function accessSync(path: string, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function accessSync(path: string, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.accessSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function close(fd: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function close(fd: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.close |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function close(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function close(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.close |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function closeSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function closeSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.closeSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function copyFileSync(src: string \| number, dest: string \| number, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.copyFileSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string): Promise\<Stream>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string): Promise\<Stream>;<br>废弃版本：9<br>代替接口：ohos.file.fs.createStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.createStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function createStreamSync(path: string, mode: string): Stream;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function createStreamSync(path: string, mode: string): Stream;<br>废弃版本：9<br>代替接口：ohos.file.fs.createStreamSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chownSync(path: string, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chownSync(path: string, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmod(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function chmodSync(path: string, mode: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function chmodSync(path: string, mode: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, len?: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, len?: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function ftruncateSync(fd: number, len?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function ftruncateSync(fd: number, len?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncateSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsync(fd: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsync(fd: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fsync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsync(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fsync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fsyncSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fsyncSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fsyncSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fstat(fd: number): Promise\<Stat>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fstat(fd: number): Promise\<Stat>;<br>废弃版本：9<br>代替接口：ohos.file.fs.stat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fstat(fd: number, callback: AsyncCallback\<Stat>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.stat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fstatSync(fd: number): Stat;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fstatSync(fd: number): Stat;<br>废弃版本：9<br>代替接口：ohos.file.fs.statSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdatasync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasync(fd: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdatasync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdatasyncSync(fd: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdatasyncSync(fd: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdatasyncSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchownSync(fd: number, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchownSync(fd: number, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fchmodSync(fd: number, mode: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fchmodSync(fd: number, mode: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string): Promise\<Stream>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string): Promise\<Stream>;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdopenStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdopenStream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function fdopenStreamSync(fd: number, mode: string): Stream;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function fdopenStreamSync(fd: number, mode: string): Stream;<br>废弃版本：9<br>代替接口：ohos.file.fs.fdopenStreamSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string): Promise\<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.file.hash.hash |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.file.hash.hash |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lchownSync(path: string, uid: number, gid: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lchownSync(path: string, uid: number, gid: number): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstat(path: string): Promise\<Stat>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstat(path: string): Promise\<Stat>;<br>废弃版本：9<br>代替接口：ohos.file.fs.lstat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstat(path: string, callback: AsyncCallback\<Stat>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.lstat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function lstatSync(path: string): Stat;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function lstatSync(path: string): Stat;<br>废弃版本：9<br>代替接口：ohos.file.fs.lstatSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode?: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode?: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdirSync(path: string, mode?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdirSync(path: string, mode?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdirSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string): Promise\<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdtemp |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtemp(prefix: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdtemp |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function mkdtempSync(prefix: string): string;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function mkdtempSync(prefix: string): string;<br>废弃版本：9<br>代替接口：ohos.file.fs.mkdtempSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function open(path: string, flags?: number, mode?: number): Promise\<number>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function open(path: string, flags?: number, mode?: number): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.file.fs.open |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function open(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function open(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.open |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.open |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.open |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function openSync(path: string, flags?: number, mode?: number): number;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function openSync(path: string, flags?: number, mode?: number): number;<br>废弃版本：9<br>代替接口：ohos.file.fs.openSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendir(path: string): Promise\<Dir>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendir(path: string): Promise\<Dir>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendir(path: string, callback: AsyncCallback\<Dir>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<string>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.file.fs.readText |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readText(filePath: string, options: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.readText |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readTextSync(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readTextSync(filePath: string, options?: {<br>    position?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;<br>废弃版本：9<br>代替接口：ohos.file.fs.readTextSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}): Promise\<ReadOut><br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}): Promise\<ReadOut><br>废弃版本：9<br>代替接口：ohos.file.fs.read |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.read |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}, callback: AsyncCallback\<ReadOut>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function read(fd: number, buffer: ArrayBuffer, options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}, callback: AsyncCallback\<ReadOut>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.read |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function readSync(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}): number;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function readSync(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>}): number;<br>废弃版本：9<br>代替接口：ohos.file.fs.readSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.rename |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.rename |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function renameSync(oldPath: string, newPath: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function renameSync(oldPath: string, newPath: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.renameSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdir(path: string): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdir(path: string): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.rmdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdir(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.rmdir |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function rmdirSync(path: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function rmdirSync(path: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.rmdirSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function stat(path: string): Promise\<Stat>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function stat(path: string): Promise\<Stat>;<br>废弃版本：9<br>代替接口：ohos.file.fs.stat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function stat(path: string, callback: AsyncCallback\<Stat>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.stat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function statSync(path: string): Stat;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function statSync(path: string): Stat;<br>废弃版本：9<br>代替接口：ohos.file.fs.statSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.symlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.symlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function symlinkSync(target: string, srcPath: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function symlinkSync(target: string, srcPath: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.symlinkSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function truncate(path: string, len?: number): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function truncate(path: string, len?: number): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function truncate(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function truncate(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function truncate(path: string, len: number, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncate |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function truncateSync(path: string, len?: number): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function truncateSync(path: string, len?: number): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.truncateSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlink(path: string): Promise\<void>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlink(path: string): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.unlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlink(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlink(path: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.unlink |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function unlinkSync(path: string): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function unlinkSync(path: string): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.unlinkSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}): Promise\<number>;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.file.fs.write |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.write |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function write(fd: number, buffer: ArrayBuffer \| string, options: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.write |@ohos.fileio.d.ts|
|废弃版本有变化|类名：fileIO<br>方法 or 属性：function writeSync(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}): number;<br>废弃版本：N/A|类名：fileIO<br>方法 or 属性：function writeSync(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    position?: number;<br>    encoding?: string;<br>}): number;<br>废弃版本：9<br>代替接口：ohos.file.fs.writeSync |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：read(): Promise\<Dirent>;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：read(): Promise\<Dirent>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：read(callback: AsyncCallback\<Dirent>): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：read(callback: AsyncCallback\<Dirent>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：readSync(): Dirent;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：readSync(): Dirent;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：close(): Promise\<void>;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：close(): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dir<br>方法 or 属性：closeSync(): void;<br>废弃版本：N/A|类名：Dir<br>方法 or 属性：closeSync(): void;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>废弃版本：N/A|类名：Dirent<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：readonly name: string;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：readonly name: string;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isBlockDevice(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isBlockDevice(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isCharacterDevice(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isCharacterDevice(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isDirectory(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isDirectory(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isFIFO(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isFIFO(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isFile(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isFile(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isSocket(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isSocket(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Dirent<br>方法 or 属性：isSymbolicLink(): boolean;<br>废弃版本：N/A|类名：Dirent<br>方法 or 属性：isSymbolicLink(): boolean;<br>废弃版本：9<br>代替接口：ohos.file.fs.listFile     |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Stat<br>废弃版本：N/A|类名：Stat<br>废弃版本：9<br>代替接口：ohos.file.fs.Stat |@ohos.fileio.d.ts|
|废弃版本有变化|类名：Stream<br>废弃版本：N/A|类名：Stream<br>废弃版本：9<br>代替接口：ohos.file.fs.Stream |@ohos.fileio.d.ts|
|废弃版本有变化|类名：ReadOut<br>废弃版本：N/A|类名：ReadOut<br>废弃版本：9<br>代替接口：N/A|@ohos.fileio.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getFreeSize   |@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string): Promise\<number>;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getFreeBytes(path: string): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getFreeSize   |@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getTotalSize   |@ohos.statfs.d.ts|
|废弃版本有变化|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string): Promise\<number>;<br>废弃版本：N/A|类名：Statfs<br>方法 or 属性：function getTotalBytes(path: string): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.file.statvfs.getTotalSize   |@ohos.statfs.d.ts|
|起始版本有变化|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>起始版本：N/A|类名：fileIO<br>方法 or 属性：function opendirSync(path: string): Dir;<br>起始版本：6|@ohos.fileio.d.ts|
