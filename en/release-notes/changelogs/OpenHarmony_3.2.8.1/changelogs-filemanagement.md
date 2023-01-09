# File Management Subsystem ChangeLog

## cl.filemanagement.1 File I/O API Changes

The return value of file I/O APIs of **file_api** does not contain the error code. The original APIs are deprecated, and new APIs are added.

**Change Impacts**

For applications developed based on earlier versions, pay attention to the iterative update of discarded APIs. The specifications of the new APIs are slightly adjusted. Pay attention to the usage of the new APIs.

**Key API/Component Changes**

For the adaptation to the unified API exception handling mode, related file I/O APIs are deprecated, and corresponding new APIs are added. Original APIs are stored in **@ohos.fileio**, and the new ones are stored in **@ohos.file.fs**. The newly added APIs support unified error code handling specifications and function the same as the original APIs. The parameters are slightly adjusted.

| Module       | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio  | **function** open(path: string, flags?: number, mode?: number, callback?: AsyncCallback<number>): void \| Promise<number>; | Deprecated    |
| @ohos.fileio  | **function** openSync(path: string, flags?: number, mode?: number): number; | Deprecated    |
| @ohos.file.fs | **function**  open(path: string, mode?: number, callback?: AsyncCallback<File>): void \| Promise<File>; | Added    |
| @ohos.file.fs | **function** openSync(path: string, mode?: number): File;    | Added    |
| @ohos.fileio  | **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }, callback?: AsyncCallback<ReadOut>): void \| Promise<ReadOut>; | Deprecated    |
| @ohos.fileio  | **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number; | Deprecated    |
| @ohos.file.fs | **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback?: AsyncCallback<number>): void \| Promise<number>; | Added    |
| @ohos.file.fs | **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number; | Added    |
| @ohos.fileio  | **function** stat(path: string, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Deprecated    |
| @ohos.fileio  | **function** statSync(path: string): Stat;                   | Deprecated    |
| @ohos.fileio  | **function** fstat(fd: number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Deprecated    |
| @ohos.fileio  | **function** fstatSync(fd: number): Stat;                    | Deprecated    |
| @ohos.file.fs | **function** stat(file: string \| number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Added    |
| @ohos.file.fs | **function** statSync(file: string \| number): Stat;         | Added    |
| @ohos.fileio  | **function** truncate(path: string, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio  | **function** truncateSync(path: string, len?: number): void; | Deprecated    |
| @ohos.fileio  | **function** ftruncate(fd: number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio  | **function** ftruncateSync(fd: number, len?: number): void;  | Deprecated    |
| @ohos.file.fs | **function** truncate(file: string \| number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Added    |
| @ohos.file.fs | **function** truncateSync(file: string \| number, len?: number): void; | Added    |
| @ohos.fileio  | **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio  | **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number; | Deprecated    |
| @ohos.file.fs | **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | Added    |
| @ohos.file.fs | **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }): number; | Added    |

**Adaptation Guide**

The original APIs use **@ohos.fileio**, which is imported as follows:

```js
import fileio from '@ohos.fileio';
```

The new APIs use **@ohos.file.fs**, which is imported as follows:

```js
import fs from '@ohos.file.fs';
```

In addition, exception handling needs to be adapted. Sample code for synchronous API exception handling is as follows:
```js
import fs from '@ohos.file.fs'

try {
    let file = fs.openSync(path, fs.OpenMode.READ_ONLY);
} catch (err) {
    console.error("openSync errCode:" + err.code + ", errMessage:" + err.message);
}
```
Sample code for handling exceptions of the **promise** method of an asynchronous API:
```js
import fs from '@ohos.file.fs'

try {
    let file = await fs.open(path, fs.OpenMode.READ_ONLY);
} catch (err) {
    console.error("open promise errCode:" + err.code + ", errMessage:" + err.message);
}
```

Sample code for handling exceptions of the **callback** method of an asynchronous API:
```js
import fs from '@ohos.file.fs'

try {
    fs.open(path, fs.OpenMode.READ_ONLY, function(e, file){ // Asynchronous thread (such as system call) errors are obtained from the callback.
        if (e) {
            console.error("open in async errCode:" + e.code + ", errMessage:" + e.message);
        }
    });
} catch (err) {// Errors (such as invalid parameters) of the main thread are obtained through try catch.
    console.error("open callback errCode:" + err.code + ", errMessage:" + err.message);
}
```
