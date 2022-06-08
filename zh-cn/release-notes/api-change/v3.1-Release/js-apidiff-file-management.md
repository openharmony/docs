# 文件管理子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，文件管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.statfs | Statfs | getTotalBytes(path: string, callback: AsyncCallback\<number>): void;<br>getTotalBytes(path: string): Promise\<number>; | 新增 |
| ohos.statfs | Statfs | getFreeBytes(path: string, callback: AsyncCallback\<number>): void;<br>getFreeBytes(path: string): Promise\<number>; | 新增 |
| ohos.fileio | Watcher | stop(): Promise\<void>;<br>stop(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | ReadOut | buffer: ArrayBuffer; | 新增 |
| ohos.fileio | ReadOut | offset: number; | 新增 |
| ohos.fileio | ReadOut | bytesRead: number; | 新增 |
| ohos.fileio | Stream | read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): Promise\<ReadOut>;<br>read(buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>read(buffer: ArrayBuffer, options: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback\<ReadOut>): void; | 新增 |
| ohos.fileio | Stream | write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise\<number>;<br>write(buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>write(buffer: ArrayBuffer \| string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.fileio | Stream | flush(): Promise\<void>;<br>flush(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | Stream | close(): Promise\<void>;<br>close(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | Dir | close(): Promise\<void>;<br>close(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | Dir | read(): Promise\<Dirent>;<br>read(callback: AsyncCallback\<Dirent>): void; | 新增 |
| ohos.fileio | fileIO | createWatcher(filename: string, events: number, callback: AsyncCallback\<number>): Watcher; | 新增 |
| ohos.fileio | fileIO | write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise\<number>;<br>write(fd: number, buffer: ArrayBuffer \| string, callback: AsyncCallback\<number>): void;<br>write(fd: number, buffer: ArrayBuffer \| string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.fileio | fileIO | unlink(path: string): Promise\<void>;<br>unlink(path: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | truncate(path: string, len?: number): Promise\<void>;<br>truncate(path: string, callback: AsyncCallback\<void>): void;<br>truncate(path: string, len: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | symlinkSync(target: string, srcPath: string): void; | 新增 |
| ohos.fileio | fileIO | symlink(target: string, srcPath: string): Promise\<void>;<br>symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | stat(path: string): Promise\<Stat>;<br>stat(path: string, callback: AsyncCallback\<Stat>): void; | 新增 |
| ohos.fileio | fileIO | rmdir(path: string): Promise\<void>;<br>rmdir(path: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | rename(oldPath: string, newPath: string): Promise\<void>;<br>rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): Promise\<ReadOut><br>read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void;<br>read(fd: number, buffer: ArrayBuffer, options: { offset?: number; length?: number; position?: number; }, callback: AsyncCallback\<ReadOut>): void; | 新增 |
| ohos.fileio | fileIO | readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string; | 新增 |
| ohos.fileio | fileIO | readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): Promise\<string>;<br>readText(filePath: string, options: { position?: number; length?: number; encoding?: string; }, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.fileio | fileIO | opendir(path: string): Promise\<Dir>;<br>opendir(path: string, callback: AsyncCallback\<Dir>): void; | 新增 |
| ohos.fileio | fileIO | open(path: string, flags?: number, mode?: number): Promise\<number>;<br>open(path: string, callback: AsyncCallback\<number>): void;<br>open(path: string, flags: number, callback: AsyncCallback\<number>): void;<br>open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.fileio | fileIO | mkdtempSync(prefix: string): string; | 新增 |
| ohos.fileio | fileIO | mkdtemp(prefix: string): Promise\<string>;<br>mkdtemp(prefix: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.fileio | fileIO | mkdir(path: string, mode?: number): Promise\<void>;<br>mkdir(path: string, callback: AsyncCallback\<void>): void;<br>mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | lstatSync(path: string): Stat; | 新增 |
| ohos.fileio | fileIO | lstat(path: string): Promise\<Stat>;<br>lstat(path: string, callback: AsyncCallback\<Stat>): void; | 新增 |
| ohos.fileio | fileIO | lchownSync(path: string, uid: number, gid: number): void; | 新增 |
| ohos.fileio | fileIO | lchown(path: string, uid: number, gid: number): Promise\<void>;<br>lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | hash(path: string, algorithm: string): Promise\<string>;<br>hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.fileio | fileIO | fdopenStream(fd: number, mode: string): Promise\<Stream>;<br>fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void; | 新增 |
| ohos.fileio | fileIO | fchmod(fd: number, mode: number): Promise\<void>;<br>fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | fchown(fd: number, uid: number, gid: number): Promise\<void>;<br>fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | fdatasyncSync(fd: number): void; | 新增 |
| ohos.fileio | fileIO | fdatasync(fd: number): Promise\<void>;<br>fdatasync(fd: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | fstat(fd: number): Promise\<Stat>;<br>fstat(fd: number, callback: AsyncCallback\<Stat>): void; | 新增 |
| ohos.fileio | fileIO | fsync(fd: number): Promise\<void>;<br>fsync(fd: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | ftruncate(fd: number, len?: number): Promise\<void>;<br>ftruncate(fd: number, callback: AsyncCallback\<void>): void;<br>ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | chmod(path: string, mode: number): Promise\<void>;<br>chmod(path: string, mode: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | chown(path: string, uid: number, gid: number): Promise\<void>;<br>chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | createStream(path: string, mode: string): Promise\<Stream>;<br>createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void; | 新增 |
| ohos.fileio | fileIO | copyFile(src: string \| number, dest: string \| number, mode?: number): Promise\<void>;<br>copyFile(src: string \| number, dest: string \| number, callback: AsyncCallback\<void>): void;<br>copyFile(src: string \| number, dest: string \| number, mode: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | close(fd: number): Promise\<void>;<br>close(fd: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.fileio | fileIO | access(path: string, mode?: number): Promise\<void>;<br>access(path: string, callback: AsyncCallback\<void>): void;<br>access(path: string, mode: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.document | document | show(uri: string, type: string): Promise\<void>;<br>show(uri: string, type: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.document | document | choose(types?: string[]): Promise\<string>;<br>choose(callback: AsyncCallback\<string>): void;<br>choose(types: string[], callback: AsyncCallback\<string>): void; | 新增 |
