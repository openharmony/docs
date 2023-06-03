# 文件管理子系统ChangeLog

## cl.filemanagement.1 fileio相关接口异常处理方式变更

file_api部件fileio接口返回值不包含错误码error.code，现进行错误码整改，废弃原有相关接口，新增相关接口。

**变更影响**

基于此前版本开发的应用，需注意废弃接口的迭代更新。新接口在接口规格上进行了微调，需注意新接口使用方法。

**关键接口/组件变更**

为适配统一的API异常处理方式，对fileio相关接口进行废弃，并新增对应接口，原接口位于@ohos.fileio，新接口位于@ohos.file.fs。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致，参数上有微调。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** open(path: string, flags?: number, mode?: number, callback?: AsyncCallback<number>): void \| Promise<number>; | 废弃     |
| @ohos.fileio        |  **function** openSync(path: string, flags?: number, mode?: number): number; | 废弃     |
| @ohos.file.fs |  **function**  open(path: string, mode?: number, callback?: AsyncCallback<File>): void \| Promise<File>; | 新增     |
| @ohos.file.fs |  **function** openSync(path: string, mode?: number): File; | 新增     |
| @ohos.fileio        |  **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }, callback?: AsyncCallback<ReadOut>): void \| Promise<ReadOut>; | 废弃     |
| @ohos.fileio        |  **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number; | 废弃     |
| @ohos.file.fs |  **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback?: AsyncCallback<number>): void \| Promise<number>; | 新增     |
| @ohos.file.fs |  **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number; | 新增     |
| @ohos.fileio        |  **function** stat(path: string, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | 废弃     |
| @ohos.fileio        |  **function** statSync(path: string): Stat; | 废弃     |
| @ohos.fileio        |  **function** fstat(fd: number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | 废弃     |
| @ohos.fileio        |  **function** fstatSync(fd: number): Stat; | 废弃     |
| @ohos.file.fs |  **function** stat(file: string \| number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | 新增     |
| @ohos.file.fs |  **function** statSync(file: string \| number): Stat; | 新增     |
| @ohos.fileio        |  **function** truncate(path: string, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | 废弃     |
| @ohos.fileio        |  **function** truncateSync(path: string, len?: number): void; | 废弃     |
| @ohos.fileio        |  **function** ftruncate(fd: number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | 废弃     |
| @ohos.fileio        |  **function** ftruncateSync(fd: number, len?: number): void; | 废弃     |
| @ohos.file.fs |  **function** truncate(file: string \| number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | 新增     |
| @ohos.file.fs |  **function** truncateSync(file: string \| number, len?: number): void; | 新增     |
| @ohos.fileio        |  **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | 废弃     |
| @ohos.fileio        |  **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number; | 废弃     |
| @ohos.file.fs |  **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | 新增     |
| @ohos.file.fs |  **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }): number; | 新增     |

**适配指导**

原接口使用的是@ohos.fileio，以以下方式import:

```js
import fileio from '@ohos.fileio';
```

现新接口使用的是@ohos.file.fs，以以下方式import:

```js
import fs from '@ohos.file.fs';
```

此外还需要适配异常处理，同步接口异常处理示例代码:
```js
import fs from '@ohos.file.fs'

try {
    let file = fs.openSync(path, fs.OpenMode.READ_ONLY);
} catch (err) {
    console.error("openSync errCode:" + err.code + ", errMessage:" + err.message);
}
```
异步接口promise方法异常处理示例代码:
```js
import fs from '@ohos.file.fs'

try {
    let file = await fs.open(path, fs.OpenMode.READ_ONLY);
} catch (err) {
    console.error("open promise errCode:" + err.code + ", errMessage:" + err.message);
}
```

异步接口callback方法异常处理示例代码:
```js
import fs from '@ohos.file.fs'

try {
    fs.open(path, fs.OpenMode.READ_ONLY, function(e, file){ //异步线程的错误（如系统调用等）在回调中获取
        if (e) {
            console.error("open in async errCode:" + e.code + ", errMessage:" + e.message);
        }
    });
} catch (err) { //主线程的错误（如非法参数等）通过try catch获取
    console.error("open callback errCode:" + err.code + ", errMessage:" + err.message);
}
```
