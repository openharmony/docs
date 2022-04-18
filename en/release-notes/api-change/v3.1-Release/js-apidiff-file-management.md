# JS API Changes of the File Management Subsystem

The table below lists the APIs changes of the file management subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.statfs | Statfs | function getTotalBytes(path: string, callback: AsyncCallback<number>): void;<br>function getTotalBytes(path: string): Promise<number>; | Added|
| ohos.statfs | Statfs | function getFreeBytes(path: string, callback: AsyncCallback<number>): void;<br>function getFreeBytes(path: string): Promise<number>; | Added|
| ohos.fileio | Watcher | stop(): Promise<void>;<br>stop(callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | ReadOut | buffer: ArrayBuffer; | Added|
| ohos.fileio | ReadOut | offset: number; | Added|
| ohos.fileio | ReadOut | bytesRead: number; | Added|
| ohos.fileio | Stream | read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): Promise<ReadOut>;<br>read(buffer: ArrayBuffer, callback: AsyncCallback<ReadOut>): void;<br>read(buffer: ArrayBuffer, options: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback<ReadOut>): void; | Added|
| ohos.fileio | Stream | write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise<number>;<br>write(buffer: ArrayBuffer \| string, callback: AsyncCallback<number>): void;<br>write(buffer: ArrayBuffer \| string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback<number>): void; | Added|
| ohos.fileio | Stream | flush(): Promise<void>;<br>flush(callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | Stream | close(): Promise<void>;<br>close(callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | Dir | close(): Promise<void>;<br>close(callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | Dir | read(): Promise<Dirent>;<br>read(callback: AsyncCallback<Dirent>): void; | Added|
| ohos.fileio | fileIO | function createWatcher(filename: string, events: number, callback: AsyncCallback<number>): Watcher; | Added|
| ohos.fileio | fileIO | function write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise<number>;<br>function write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback<number>): void;<br>function write(fd: number, buffer: ArrayBuffer \| string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback<number>): void; | Added|
| ohos.fileio | fileIO | function unlink(path: string): Promise<void>;<br>function unlink(path: string, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function truncate(path: string, len?: number): Promise<void>;<br>function truncate(path: string, callback: AsyncCallback<void>): void;<br>function truncate(path: string, len: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function symlinkSync(target: string, srcPath: string): void; | Added|
| ohos.fileio | fileIO | function symlink(target: string, srcPath: string): Promise<void>;<br>function symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function stat(path: string): Promise<Stat>;<br>function stat(path: string, callback: AsyncCallback<Stat>): void; | Added|
| ohos.fileio | fileIO | function rmdir(path: string): Promise<void>;<br>function rmdir(path: string, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function rename(oldPath: string, newPath: string): Promise<void>;<br>function rename(oldPath: string, newPath: string, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): Promise<ReadOut><br>function read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback<ReadOut>): void;<br>function read(fd: number, buffer: ArrayBuffer, options: { offset?: number; length?: number; position?: number; }, callback: AsyncCallback<ReadOut>): void; | Added|
| ohos.fileio | fileIO | function readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string;| Added|
| ohos.fileio | fileIO | function readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): Promise<string>;<br>function readText(filePath: string, options: { position?: number; length?: number; encoding?: string; }, callback: AsyncCallback<string>): void; | Added|
| ohos.fileio | fileIO | function opendir(path: string): Promise<Dir>;<br>function opendir(path: string, callback: AsyncCallback<Dir>): void; | Added|
| ohos.fileio | fileIO | function open(path: string, flags?: number, mode?: number): Promise<number>;<br>function open(path: string, callback: AsyncCallback<number>): void;<br>function open(path: string, flags: number, callback: AsyncCallback<number>): void;<br>function open(path: string, flags: number, mode: number, callback: AsyncCallback<number>): void; | Added|
| ohos.fileio | fileIO | function mkdtempSync(prefix: string): string; | Added|
| ohos.fileio | fileIO | function mkdtemp(prefix: string): Promise<string>;<br>function mkdtemp(prefix: string, callback: AsyncCallback<string>): void; | Added|
| ohos.fileio | fileIO | function mkdir(path: string, mode?: number): Promise<void>;<br>function mkdir(path: string, callback: AsyncCallback<void>): void;<br>function mkdir(path: string, mode: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function lstatSync(path: string): Stat; | Added|
| ohos.fileio | fileIO | function lstat(path: string): Promise<Stat>;<br>function lstat(path: string, callback: AsyncCallback<Stat>): void; | Added|
| ohos.fileio | fileIO | function lchownSync(path: string, uid: number, gid: number): void; | Added|
| ohos.fileio | fileIO | function lchown(path: string, uid: number, gid: number): Promise<void>;<br>function lchown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function hash(path: string, algorithm: string): Promise<string>;<br>function hash(path: string, algorithm: string, callback: AsyncCallback<string>): void; | Added|
| ohos.fileio | fileIO | function fdopenStream(fd: number, mode: string): Promise<Stream>;<br>function fdopenStream(fd: number, mode: string, callback: AsyncCallback<Stream>): void; | Added|
| ohos.fileio | fileIO | function fchmod(fd: number, mode: number): Promise<void>;<br>function fchmod(fd: number, mode: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function fchown(fd: number, uid: number, gid: number): Promise<void>;<br>function fchown(fd: number, uid: number, gid: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function fdatasyncSync(fd: number): void; | Added|
| ohos.fileio | fileIO | function fdatasync(fd: number): Promise<void>;<br>function fdatasync(fd: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function fstat(fd: number): Promise<Stat>;<br>function fstat(fd: number, callback: AsyncCallback<Stat>): void; | Added|
| ohos.fileio | fileIO | function fsync(fd: number): Promise<void>;<br>function fsync(fd: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function ftruncate(fd: number, len?: number): Promise<void>;<br>function ftruncate(fd: number, callback: AsyncCallback<void>): void;<br>function ftruncate(fd: number, len: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function chmod(path: string, mode: number): Promise<void>;<br>function chmod(path: string, mode: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function chown(path: string, uid: number, gid: number): Promise<void>;<br>function chown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function createStream(path: string, mode: string): Promise<Stream>;<br>function createStream(path: string, mode: string, callback: AsyncCallback<Stream>): void; | Added|
| ohos.fileio | fileIO | function copyFile(src: string \| number, dest: string \| number, mode?: number): Promise<void>;<br>function copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback<void>): void;<br>function copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function close(fd: number): Promise<void>;<br>function close(fd: number, callback: AsyncCallback<void>): void; | Added|
| ohos.fileio | fileIO | function access(path: string, mode?: number): Promise<void>;<br>function access(path: string, callback: AsyncCallback<void>): void;<br>function access(path: string, mode: number, callback: AsyncCallback<void>): void; | Added|
| ohos.document | document | function show(uri: string, type: string): Promise<void>;<br>function show(uri: string, type: string, callback: AsyncCallback<void>): void; | Added|
| ohos.document | document | function choose(types?: string[]): Promise<string>;<br>function choose(callback: AsyncCallback<string>): void;<br>function choose(types: string[], callback: AsyncCallback<string>): void; | Added|
