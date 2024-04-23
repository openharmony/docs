| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_TYPE = 'image/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_TYPE = 'image/*'<br>差异内容：SystemCapability.FileManagement.UserFileService|api/@ohos.file.picker.d.ts|
|syscap变更|类名：PhotoViewMIMETypes；<br>API声明：VIDEO_TYPE = 'video/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：VIDEO_TYPE = 'video/*'<br>差异内容：SystemCapability.FileManagement.UserFileService|api/@ohos.file.picker.d.ts|
|syscap变更|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_VIDEO_TYPE = '*/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_VIDEO_TYPE = '*/*'<br>差异内容：SystemCapability.FileManagement.UserFileService|api/@ohos.file.picker.d.ts|
|syscap变更|类名：securityLabel；<br>API声明：type DataLevel = 's0' \| 's1' \| 's2' \| 's3' \| 's4';<br>差异内容：NA|类名：securityLabel；<br>API声明：type DataLevel = 's0' \| 's1' \| 's2' \| 's3' \| 's4';<br>差异内容：SystemCapability.FileManagement.File.FileIO|api/@ohos.file.securityLabel.d.ts|
|API废弃版本变更|类名：PhotoAsset；<br>API声明：getReadOnlyFd(callback: AsyncCallback\<number>): void;<br>差异内容：NA|类名：PhotoAsset；<br>API声明：getReadOnlyFd(callback: AsyncCallback\<number>): void;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：PhotoAsset；<br>API声明：getReadOnlyFd(): Promise\<number>;<br>差异内容：NA|类名：PhotoAsset；<br>API声明：getReadOnlyFd(): Promise\<number>;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：PhotoAsset；<br>API声明：close(fd: number, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：PhotoAsset；<br>API声明：close(fd: number, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：PhotoAsset；<br>API声明：close(fd: number): Promise\<void>;<br>差异内容：NA|类名：PhotoAsset；<br>API声明：close(fd: number): Promise\<void>;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：Album；<br>API声明：addAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：Album；<br>API声明：addAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：Album；<br>API声明：addAssets(assets: Array\<PhotoAsset>): Promise\<void>;<br>差异内容：NA|类名：Album；<br>API声明：addAssets(assets: Array\<PhotoAsset>): Promise\<void>;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：Album；<br>API声明：removeAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：Album；<br>API声明：removeAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：Album；<br>API声明：removeAssets(assets: Array\<PhotoAsset>): Promise\<void>;<br>差异内容：NA|类名：Album；<br>API声明：removeAssets(assets: Array\<PhotoAsset>): Promise\<void>;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：PhotoAccessHelper；<br>API声明：createDeleteRequest(uriList: Array\<string>, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：PhotoAccessHelper；<br>API声明：createDeleteRequest(uriList: Array\<string>, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|API废弃版本变更|类名：PhotoAccessHelper；<br>API声明：createDeleteRequest(uriList: Array\<string>): Promise\<void>;<br>差异内容：NA|类名：PhotoAccessHelper；<br>API声明：createDeleteRequest(uriList: Array\<string>): Promise\<void>;<br>差异内容：11|api/@ohos.file.photoAccessHelper.d.ts|
|函数变更|类名：global；<br>API声明：declare function listFile(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): Promise\<string[]>;<br>差异内容：options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}|类名：global；<br>API声明：declare function listFile(path: string, options?: ListFileOptions): Promise\<string[]>;<br>差异内容：options?: ListFileOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function listFile(path: string, options: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}, callback: AsyncCallback\<string[]>): void;<br>差异内容：options: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}|类名：global；<br>API声明：declare function listFile(path: string, options: ListFileOptions, callback: AsyncCallback\<string[]>): void;<br>差异内容：options: ListFileOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function listFileSync(path: string, options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}): string[];<br>差异内容：options?: {<br>    recursion?: boolean;<br>    listNum?: number;<br>    filter?: Filter;<br>}|类名：global；<br>API声明：declare function listFileSync(path: string, options?: ListFileOptions): string[];<br>差异内容：options?: ListFileOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function read(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>}): Promise\<number>;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>}|类名：global；<br>API声明：declare function read(fd: number, buffer: ArrayBuffer, options?: ReadOptions): Promise\<number>;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function read(fd: number, buffer: ArrayBuffer, options: {<br>    offset?: number;<br>    length?: number;<br>}, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>    offset?: number;<br>    length?: number;<br>}|类名：global；<br>API声明：declare function read(fd: number, buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function readSync(fd: number, buffer: ArrayBuffer, options?: {<br>    offset?: number;<br>    length?: number;<br>}): number;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>}|类名：global；<br>API声明：declare function readSync(fd: number, buffer: ArrayBuffer, options?: ReadOptions): number;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function readText(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<string>;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function readText(filePath: string, options?: ReadTextOptions): Promise\<string>;<br>差异内容：options?: ReadTextOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function readText(filePath: string, options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<string>): void;<br>差异内容：options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function readText(filePath: string, options: ReadTextOptions, callback: AsyncCallback\<string>): void;<br>差异内容：options: ReadTextOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function readTextSync(filePath: string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): string;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function readTextSync(filePath: string, options?: ReadTextOptions): string;<br>差异内容：options?: ReadTextOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function write(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): Promise\<number>;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function write(fd: number, buffer: ArrayBuffer \| string, options?: WriteOptions): Promise\<number>;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function write(fd: number, buffer: ArrayBuffer \| string, options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function write(fd: number, buffer: ArrayBuffer \| string, options: WriteOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：global；<br>API声明：declare function writeSync(fd: number, buffer: ArrayBuffer \| string, options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}): number;<br>差异内容：options?: {<br>    offset?: number;<br>    length?: number;<br>    encoding?: string;<br>}|类名：global；<br>API声明：declare function writeSync(fd: number, buffer: ArrayBuffer \| string, options?: WriteOptions): number;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：write(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): Promise\<number>;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：RandomAccessFile；<br>API声明：write(buffer: ArrayBuffer \| string, options?: WriteOptions): Promise\<number>;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：write(buffer: ArrayBuffer \| string, options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：RandomAccessFile；<br>API声明：write(buffer: ArrayBuffer \| string, options: WriteOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：writeSync(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): number;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：RandomAccessFile；<br>API声明：writeSync(buffer: ArrayBuffer \| string, options?: WriteOptions): number;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：read(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): Promise\<number>;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：RandomAccessFile；<br>API声明：read(buffer: ArrayBuffer, options?: ReadOptions): Promise\<number>;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：read(buffer: ArrayBuffer, options: {<br>        offset?: number;<br>        length?: number;<br>    }, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：RandomAccessFile；<br>API声明：read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：RandomAccessFile；<br>API声明：readSync(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): number;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：RandomAccessFile；<br>API声明：readSync(buffer: ArrayBuffer, options?: ReadOptions): number;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：write(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): Promise\<number>;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：Stream；<br>API声明：write(buffer: ArrayBuffer \| string, options?: WriteOptions): Promise\<number>;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：write(buffer: ArrayBuffer \| string, options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：Stream；<br>API声明：write(buffer: ArrayBuffer \| string, options: WriteOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：writeSync(buffer: ArrayBuffer \| string, options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }): number;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>        encoding?: string;<br>    }|类名：Stream；<br>API声明：writeSync(buffer: ArrayBuffer \| string, options?: WriteOptions): number;<br>差异内容：options?: WriteOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：read(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): Promise\<number>;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：Stream；<br>API声明：read(buffer: ArrayBuffer, options?: ReadOptions): Promise\<number>;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：read(buffer: ArrayBuffer, options: {<br>        offset?: number;<br>        length?: number;<br>    }, callback: AsyncCallback\<number>): void;<br>差异内容：options: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：Stream；<br>API声明：read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback\<number>): void;<br>差异内容：options: ReadOptions|api/@ohos.file.fs.d.ts|
|函数变更|类名：Stream；<br>API声明：readSync(buffer: ArrayBuffer, options?: {<br>        offset?: number;<br>        length?: number;<br>    }): number;<br>差异内容：options?: {<br>        offset?: number;<br>        length?: number;<br>    }|类名：Stream；<br>API声明：readSync(buffer: ArrayBuffer, options?: ReadOptions): number;<br>差异内容：options?: ReadOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function mkdir(path: string, recursion: boolean): Promise\<void>;<br>差异内容：declare function mkdir(path: string, recursion: boolean): Promise\<void>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function mkdir(path: string, recursion: boolean, callback: AsyncCallback\<void>): void;<br>差异内容：declare function mkdir(path: string, recursion: boolean, callback: AsyncCallback\<void>): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function mkdirSync(path: string, recursion: boolean): void;<br>差异内容：declare function mkdirSync(path: string, recursion: boolean): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：BackupExtensionAbility；<br>API声明：context: ExtensionContext;<br>差异内容：context: ExtensionContext;|api/@ohos.application.BackupExtensionAbility.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace cloudSync<br>差异内容： declare namespace cloudSync|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：cloudSync；<br>API声明： enum State<br>差异内容： enum State|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：State；<br>API声明：RUNNING<br>差异内容：RUNNING|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：State；<br>API声明：COMPLETED<br>差异内容：COMPLETED|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：State；<br>API声明：FAILED<br>差异内容：FAILED|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：State；<br>API声明：STOPPED<br>差异内容：STOPPED|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：cloudSync；<br>API声明： enum DownloadErrorType<br>差异内容： enum DownloadErrorType|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：NO_ERROR<br>差异内容：NO_ERROR|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：UNKNOWN_ERROR<br>差异内容：UNKNOWN_ERROR|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：NETWORK_UNAVAILABLE<br>差异内容：NETWORK_UNAVAILABLE|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：LOCAL_STORAGE_FULL<br>差异内容：LOCAL_STORAGE_FULL|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：CONTENT_NOT_FOUND<br>差异内容：CONTENT_NOT_FOUND|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadErrorType；<br>API声明：FREQUENT_USER_REQUESTS<br>差异内容：FREQUENT_USER_REQUESTS|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：cloudSync；<br>API声明： interface DownloadProgress<br>差异内容： interface DownloadProgress|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadProgress；<br>API声明：state: State;<br>差异内容：state: State;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadProgress；<br>API声明：processed: number;<br>差异内容：processed: number;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadProgress；<br>API声明：size: number;<br>差异内容：size: number;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadProgress；<br>API声明：uri: string;<br>差异内容：uri: string;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：DownloadProgress；<br>API声明：error: DownloadErrorType;<br>差异内容：error: DownloadErrorType;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：cloudSync；<br>API声明： class CloudFileCache<br>差异内容： class CloudFileCache|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：on(event: 'progress', callback: Callback\<DownloadProgress>): void;<br>差异内容：on(event: 'progress', callback: Callback\<DownloadProgress>): void;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：off(event: 'progress', callback?: Callback\<DownloadProgress>): void;<br>差异内容：off(event: 'progress', callback?: Callback\<DownloadProgress>): void;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：start(uri: string): Promise\<void>;<br>差异内容：start(uri: string): Promise\<void>;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：start(uri: string, callback: AsyncCallback\<void>): void;<br>差异内容：start(uri: string, callback: AsyncCallback\<void>): void;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：stop(uri: string): Promise\<void>;<br>差异内容：stop(uri: string): Promise\<void>;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：CloudFileCache；<br>API声明：stop(uri: string, callback: AsyncCallback\<void>): void;<br>差异内容：stop(uri: string, callback: AsyncCallback\<void>): void;|api/@ohos.file.cloudSync.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace Environment<br>差异内容： declare namespace Environment|api/@ohos.file.environment.d.ts|
|新增API|NA|类名：Environment；<br>API声明：function getUserDownloadDir(): string;<br>差异内容：function getUserDownloadDir(): string;|api/@ohos.file.environment.d.ts|
|新增API|NA|类名：Environment；<br>API声明：function getUserDesktopDir(): string;<br>差异内容：function getUserDesktopDir(): string;|api/@ohos.file.environment.d.ts|
|新增API|NA|类名：Environment；<br>API声明：function getUserDocumentDir(): string;<br>差异内容：function getUserDocumentDir(): string;|api/@ohos.file.environment.d.ts|
|新增API|NA|类名：FileUri；<br>API声明：getFullDirectoryUri(): string;<br>差异内容：getFullDirectoryUri(): string;|api/@ohos.file.fileuri.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function copy(srcUri: string, destUri: string, options?: CopyOptions): Promise\<void>;<br>差异内容：declare function copy(srcUri: string, destUri: string, options?: CopyOptions): Promise\<void>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function copy(srcUri: string, destUri: string, callback: AsyncCallback\<void>): void;<br>差异内容：declare function copy(srcUri: string, destUri: string, callback: AsyncCallback\<void>): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function copy(srcUri: string, destUri: string, options: CopyOptions, callback: AsyncCallback\<void>): void;<br>差异内容：declare function copy(srcUri: string, destUri: string, options: CopyOptions, callback: AsyncCallback\<void>): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function lseek(fd: number, offset: number, whence?: WhenceType): number;<br>差异内容：declare function lseek(fd: number, offset: number, whence?: WhenceType): number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function readLines(filePath: string, options?: Options): Promise\<ReaderIterator>;<br>差异内容：declare function readLines(filePath: string, options?: Options): Promise\<ReaderIterator>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function readLines(filePath: string, callback: AsyncCallback\<ReaderIterator>): void;<br>差异内容：declare function readLines(filePath: string, callback: AsyncCallback\<ReaderIterator>): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function readLines(filePath: string, options: Options, callback: AsyncCallback\<ReaderIterator>): void;<br>差异内容：declare function readLines(filePath: string, options: Options, callback: AsyncCallback\<ReaderIterator>): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function readLinesSync(filePath: string, options?: Options): ReaderIterator;<br>差异内容：declare function readLinesSync(filePath: string, options?: Options): ReaderIterator;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：declare function utimes(path: string, mtime: number): void;<br>差异内容：declare function utimes(path: string, mtime: number): void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： interface Progress<br>差异内容： interface Progress|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Progress；<br>API声明：readonly processedSize: number;<br>差异内容：readonly processedSize: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Progress；<br>API声明：readonly totalSize: number;<br>差异内容：readonly totalSize: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： interface CopyOptions<br>差异内容： interface CopyOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：CopyOptions；<br>API声明：progressListener?: ProgressListener;<br>差异内容：progressListener?: ProgressListener;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明：type ProgressListener = (progress: Progress) => void;<br>差异内容：type ProgressListener = (progress: Progress) => void;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：File；<br>API声明：getParent(): string;<br>差异内容：getParent(): string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Stat；<br>API声明：readonly location: LocationType;<br>差异内容：readonly location: LocationType;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface ReaderIteratorResult<br>差异内容： export interface ReaderIteratorResult|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReaderIteratorResult；<br>API声明：done: boolean;<br>差异内容：done: boolean;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReaderIteratorResult；<br>API声明：value: string;<br>差异内容：value: string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： declare interface ReaderIterator<br>差异内容： declare interface ReaderIterator|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReaderIterator；<br>API声明：next(): ReaderIteratorResult;<br>差异内容：next(): ReaderIteratorResult;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：suffix?: Array\<string>;<br>差异内容：suffix?: Array\<string>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：displayName?: Array\<string>;<br>差异内容：displayName?: Array\<string>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：mimeType?: Array\<string>;<br>差异内容：mimeType?: Array\<string>;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：fileSizeOver?: number;<br>差异内容：fileSizeOver?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：lastModifiedAfter?: number;<br>差异内容：lastModifiedAfter?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Filter；<br>API声明：excludeMedia?: boolean;<br>差异内容：excludeMedia?: boolean;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ConflictFiles；<br>API声明：srcFile: string;<br>差异内容：srcFile: string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ConflictFiles；<br>API声明：destFile: string;<br>差异内容：destFile: string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface Options<br>差异内容： export interface Options|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：Options；<br>API声明：encoding?: string;<br>差异内容：encoding?: string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface ReadOptions<br>差异内容： export interface ReadOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReadOptions；<br>API声明：offset?: number;<br>差异内容：offset?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReadOptions；<br>API声明：length?: number;<br>差异内容：length?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface ReadTextOptions<br>差异内容： export interface ReadTextOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ReadTextOptions；<br>API声明：encoding?: string;<br>差异内容：encoding?: string;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface WriteOptions<br>差异内容： export interface WriteOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：WriteOptions；<br>API声明：offset?: number;<br>差异内容：offset?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：WriteOptions；<br>API声明：length?: number;<br>差异内容：length?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface ListFileOptions<br>差异内容： export interface ListFileOptions|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ListFileOptions；<br>API声明：recursion?: boolean;<br>差异内容：recursion?: boolean;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ListFileOptions；<br>API声明：listNum?: number;<br>差异内容：listNum?: number;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：ListFileOptions；<br>API声明：filter?: Filter;<br>差异内容：filter?: Filter;|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： declare enum WhenceType<br>差异内容： declare enum WhenceType|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：WhenceType；<br>API声明：SEEK_SET = 0<br>差异内容：SEEK_SET = 0|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：WhenceType；<br>API声明：SEEK_CUR = 1<br>差异内容：SEEK_CUR = 1|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：WhenceType；<br>API声明：SEEK_END = 2<br>差异内容：SEEK_END = 2|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：global；<br>API声明： declare enum LocationType<br>差异内容： declare enum LocationType|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：LocationType；<br>API声明：LOCAL = 1 \<\< 0<br>差异内容：LOCAL = 1 \<\< 0|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：LocationType；<br>API声明：CLOUD = 1 \<\< 1<br>差异内容：CLOUD = 1 \<\< 1|api/@ohos.file.fs.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： enum RecommendationType<br>差异内容： enum RecommendationType|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationType；<br>API声明：QR_OR_BAR_CODE = 1<br>差异内容：QR_OR_BAR_CODE = 1|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationType；<br>API声明：QR_CODE = 2<br>差异内容：QR_CODE = 2|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationType；<br>API声明：BAR_CODE = 3<br>差异内容：BAR_CODE = 3|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationType；<br>API声明：ID_CARD = 4<br>差异内容：ID_CARD = 4|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationType；<br>API声明：PROFILE_PICTURE = 5<br>差异内容：PROFILE_PICTURE = 5|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： enum DeliveryMode<br>差异内容： enum DeliveryMode|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：DeliveryMode；<br>API声明：FAST_MODE = 0<br>差异内容：FAST_MODE = 0|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：DeliveryMode；<br>API声明：HIGH_QUALITY_MODE = 1<br>差异内容：HIGH_QUALITY_MODE = 1|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：DeliveryMode；<br>API声明：BALANCE_MODE = 2<br>差异内容：BALANCE_MODE = 2|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： interface RequestOptions<br>差异内容： interface RequestOptions|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RequestOptions；<br>API声明：deliveryMode: DeliveryMode;<br>差异内容：deliveryMode: DeliveryMode;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： interface MediaAssetDataHandler<br>差异内容： interface MediaAssetDataHandler|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetDataHandler；<br>API声明：onDataPrepared(data: T): void;<br>差异内容：onDataPrepared(data: T): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： class MediaAssetManager<br>差异内容： class MediaAssetManager|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetManager；<br>API声明：static requestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler\<image.ImageSource>): Promise\<string>;<br>差异内容：static requestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler\<image.ImageSource>): Promise\<string>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetManager；<br>API声明：static requestImageData(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler\<ArrayBuffer>): Promise\<string>;<br>差异内容：static requestImageData(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler\<ArrayBuffer>): Promise\<string>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：Album；<br>API声明：readonly imageCount?: number;<br>差异内容：readonly imageCount?: number;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：Album；<br>API声明：readonly videoCount?: number;<br>差异内容：readonly videoCount?: number;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoAccessHelper；<br>API声明：applyChanges(mediaChangeRequest: MediaChangeRequest): Promise\<void>;<br>差异内容：applyChanges(mediaChangeRequest: MediaChangeRequest): Promise\<void>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoSelectOptions；<br>API声明：isSearchSupported?: boolean;<br>差异内容：isSearchSupported?: boolean;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoSelectOptions；<br>API声明：isPhotoTakingSupported?: boolean;<br>差异内容：isPhotoTakingSupported?: boolean;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoSelectOptions；<br>API声明：isEditSupported?: boolean;<br>差异内容：isEditSupported?: boolean;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoSelectOptions；<br>API声明：recommendationOptions?: RecommendationOptions;<br>差异内容：recommendationOptions?: RecommendationOptions;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：PhotoSelectOptions；<br>API声明：preselectedUris?: Array\<string>;<br>差异内容：preselectedUris?: Array\<string>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： class RecommendationOptions<br>差异内容： class RecommendationOptions|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：RecommendationOptions；<br>API声明：recommendationType?: RecommendationType;<br>差异内容：recommendationType?: RecommendationType;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： enum ResourceType<br>差异内容： enum ResourceType|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：ResourceType；<br>API声明：IMAGE_RESOURCE = 1<br>差异内容：IMAGE_RESOURCE = 1|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：ResourceType；<br>API声明：VIDEO_RESOURCE = 2<br>差异内容：VIDEO_RESOURCE = 2|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： interface MediaChangeRequest<br>差异内容： interface MediaChangeRequest|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： class MediaAssetChangeRequest<br>差异内容： class MediaAssetChangeRequest|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：static createImageAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest;<br>差异内容：static createImageAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：static createVideoAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest;<br>差异内容：static createVideoAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：static createAssetRequest(context: Context, photoType: PhotoType, extension: string, options?: CreateOptions): MediaAssetChangeRequest;<br>差异内容：static createAssetRequest(context: Context, photoType: PhotoType, extension: string, options?: CreateOptions): MediaAssetChangeRequest;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：static deleteAssets(context: Context, assets: Array\<PhotoAsset>): Promise\<void>;<br>差异内容：static deleteAssets(context: Context, assets: Array\<PhotoAsset>): Promise\<void>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：static deleteAssets(context: Context, uriList: Array\<string>): Promise\<void>;<br>差异内容：static deleteAssets(context: Context, uriList: Array\<string>): Promise\<void>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：getAsset(): PhotoAsset;<br>差异内容：getAsset(): PhotoAsset;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：setTitle(title: string): void;<br>差异内容：setTitle(title: string): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：getWriteCacheHandler(): Promise\<number>;<br>差异内容：getWriteCacheHandler(): Promise\<number>;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：addResource(type: ResourceType, fileUri: string): void;<br>差异内容：addResource(type: ResourceType, fileUri: string): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAssetChangeRequest；<br>API声明：addResource(type: ResourceType, data: ArrayBuffer): void;<br>差异内容：addResource(type: ResourceType, data: ArrayBuffer): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：photoAccessHelper；<br>API声明： class MediaAlbumChangeRequest<br>差异内容： class MediaAlbumChangeRequest|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAlbumChangeRequest；<br>API声明：getAlbum(): Album;<br>差异内容：getAlbum(): Album;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAlbumChangeRequest；<br>API声明：setAlbumName(name: string): void;<br>差异内容：setAlbumName(name: string): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAlbumChangeRequest；<br>API声明：addAssets(assets: Array\<PhotoAsset>): void;<br>差异内容：addAssets(assets: Array\<PhotoAsset>): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：MediaAlbumChangeRequest；<br>API声明：removeAssets(assets: Array\<PhotoAsset>): void;<br>差异内容：removeAssets(assets: Array\<PhotoAsset>): void;|api/@ohos.file.photoAccessHelper.d.ts|
|新增API|NA|类名：picker；<br>API声明： export enum DocumentSelectMode<br>差异内容： export enum DocumentSelectMode|api/@ohos.file.picker.d.ts|
|新增API|NA|类名：DocumentSelectMode；<br>API声明：FILE = 0<br>差异内容：FILE = 0|api/@ohos.file.picker.d.ts|
|新增API|NA|类名：DocumentSelectMode；<br>API声明：FOLDER = 1<br>差异内容：FOLDER = 1|api/@ohos.file.picker.d.ts|
|新增API|NA|类名：DocumentSelectMode；<br>API声明：MIXED = 2<br>差异内容：MIXED = 2|api/@ohos.file.picker.d.ts|
|新增API|NA|类名：DocumentSelectOptions；<br>API声明：selectMode?: DocumentSelectMode;<br>差异内容：selectMode?: DocumentSelectMode;|api/@ohos.file.picker.d.ts|
|新增API|NA|类名：fileShare；<br>API声明： export enum OperationMode<br>差异内容： export enum OperationMode|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：OperationMode；<br>API声明：READ_MODE = 0b1<br>差异内容：READ_MODE = 0b1|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：OperationMode；<br>API声明：WRITE_MODE = 0b10<br>差异内容：WRITE_MODE = 0b10|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明： export enum PolicyErrorCode<br>差异内容： export enum PolicyErrorCode|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：PolicyErrorCode；<br>API声明：PERSISTENCE_FORBIDDEN = 1<br>差异内容：PERSISTENCE_FORBIDDEN = 1|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：PolicyErrorCode；<br>API声明：INVALID_MODE = 2<br>差异内容：INVALID_MODE = 2|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：PolicyErrorCode；<br>API声明：INVALID_PATH = 3<br>差异内容：INVALID_PATH = 3|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明：export type PolicyErrorResult = {<br>        /**<br>         * Indicates the failed uri of the policy information.<br>         *<br>         * @type { string }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        uri: string;<br>        /**<br>         * Indicates the error code of the failure in the policy information.<br>         *<br>         * @type { PolicyErrorCode }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        code: PolicyErrorCode;<br>        /**<br>         * Indicates the reason of the failure in the policy information.<br>         *<br>         * @type { string }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        message: string;<br>    };<br>差异内容：export type PolicyErrorResult = {<br>        /**<br>         * Indicates the failed uri of the policy information.<br>         *<br>         * @type { string }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        uri: string;<br>        /**<br>         * Indicates the error code of the failure in the policy information.<br>         *<br>         * @type { PolicyErrorCode }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        code: PolicyErrorCode;<br>        /**<br>         * Indicates the reason of the failure in the policy information.<br>         *<br>         * @type { string }<br>         * @syscap SystemCapability.FileManagement.AppFileService.FolderAuthorization<br>         * @since 11<br>         */<br>        message: string;<br>    };|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明： export interface PolicyInfo<br>差异内容： export interface PolicyInfo|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：PolicyInfo；<br>API声明：uri: string;<br>差异内容：uri: string;|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：PolicyInfo；<br>API声明：operationMode: number;<br>差异内容：operationMode: number;|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明：function persistPermission(policies: Array\<PolicyInfo>): Promise\<void>;<br>差异内容：function persistPermission(policies: Array\<PolicyInfo>): Promise\<void>;|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明：function revokePermission(policies: Array\<PolicyInfo>): Promise\<void>;<br>差异内容：function revokePermission(policies: Array\<PolicyInfo>): Promise\<void>;|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明：function activatePermission(policies: Array\<PolicyInfo>): Promise\<void>;<br>差异内容：function activatePermission(policies: Array\<PolicyInfo>): Promise\<void>;|api/@ohos.fileshare.d.ts|
|新增API|NA|类名：fileShare；<br>API声明：function deactivatePermission(policies: Array\<PolicyInfo>): Promise\<void>;<br>差异内容：function deactivatePermission(policies: Array\<PolicyInfo>): Promise\<void>;|api/@ohos.fileshare.d.ts|
|起始版本有变化|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_TYPE = 'image/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_TYPE = 'image/*'<br>差异内容：9|api/@ohos.file.picker.d.ts|
|起始版本有变化|类名：PhotoViewMIMETypes；<br>API声明：VIDEO_TYPE = 'video/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：VIDEO_TYPE = 'video/*'<br>差异内容：9|api/@ohos.file.picker.d.ts|
|起始版本有变化|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_VIDEO_TYPE = '*/*'<br>差异内容：NA|类名：PhotoViewMIMETypes；<br>API声明：IMAGE_VIDEO_TYPE = '*/*'<br>差异内容：9|api/@ohos.file.picker.d.ts|
|起始版本有变化|类名：securityLabel；<br>API声明：type DataLevel = 's0' \| 's1' \| 's2' \| 's3' \| 's4';<br>差异内容：NA|类名：securityLabel；<br>API声明：type DataLevel = 's0' \| 's1' \| 's2' \| 's3' \| 's4';<br>差异内容：9|api/@ohos.file.securityLabel.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.application.BackupExtensionAbility.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.document.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.cloudSyncManager.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.fileAccess.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.fileuri.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.fs.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.hash.d.ts|
|kit变更|NA|MediaLibraryKit|api/@ohos.file.photoAccessHelper.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.picker.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.securityLabel.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.statvfs.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.file.storageStatistics.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.fileio.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.fileshare.d.ts|
|kit变更|NA|CoreFileKit|api/@ohos.statfs.d.ts|
|kit变更|NA|CoreFileKit|api/@system.file.d.ts|
