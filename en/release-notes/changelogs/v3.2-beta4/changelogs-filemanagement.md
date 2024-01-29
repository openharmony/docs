# File Management Subsystem Changelog

## cl.filemanagement.1 fileio API Changes

Deprecated the **fileio** APIs, which do not return error codes; added APIs that return error codes.

**Change Impact**

For applications developed based on earlier versions, pay attention to the iterative update of deprecated APIs. The specifications of the new APIs are slightly adjusted. Pay attention to the usage of the new APIs.

**Key API/Component Changes**

The APIs of **@ohos.fileio** do not support error code handling and are deprecated. New APIs with minor changes in parameters are added in **@ohos.file.fs** to support unified error code handling. The functionalities of the APIs remain unchanged.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** open(path: string, flags?: number, mode?: number, callback?: AsyncCallback<number>): void \| Promise<number>; | Deprecated    |
| @ohos.fileio        |  **function** openSync(path: string, flags?: number, mode?: number): number; | Deprecated    |
| @ohos.file.fs |  **function**  open(path: string, mode?: number, callback?: AsyncCallback<File>): void \| Promise<File>; | Added    |
| @ohos.file.fs |  **function** openSync(path: string, mode?: number): File; | Added    |
| @ohos.fileio        |  **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }, callback?: AsyncCallback<ReadOut>): void \| Promise<ReadOut>; | Deprecated    |
| @ohos.fileio        |  **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number; | Deprecated    |
| @ohos.file.fs |  **function** read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback?: AsyncCallback<number>): void \| Promise<number>; | Added    |
| @ohos.file.fs |  **function** readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number; | Added    |
| @ohos.fileio        |  **function** stat(path: string, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Deprecated    |
| @ohos.fileio        |  **function** statSync(path: string): Stat; | Deprecated    |
| @ohos.fileio        |  **function** fstat(fd: number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Deprecated    |
| @ohos.fileio        |  **function** fstatSync(fd: number): Stat; | Deprecated    |
| @ohos.file.fs |  **function** stat(file: string \| number, callback?: AsyncCallback<Stat>): void \| Promise<Stat>; | Added    |
| @ohos.file.fs |  **function** statSync(file: string \| number): Stat; | Added    |
| @ohos.fileio        |  **function** truncate(path: string, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio        |  **function** truncateSync(path: string, len?: number): void; | Deprecated    |
| @ohos.fileio        |  **function** ftruncate(fd: number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio        |  **function** ftruncateSync(fd: number, len?: number): void; | Deprecated    |
| @ohos.file.fs |  **function** truncate(file: string \| number, len?: number, callback?: AsyncCallback<void>): void \| Promise<void>; | Added    |
| @ohos.file.fs |  **function** truncateSync(file: string \| number, len?: number): void; | Added    |
| @ohos.fileio        |  **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | Deprecated    |
| @ohos.fileio        |  **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number; | Deprecated    |
| @ohos.file.fs |  **function** write(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback<number>): void \| Promise<void>; | Added    |
| @ohos.file.fs |  **function** writeSync(fd: number, buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }): number; | Added    |

**Adaptation Guide**

1. Change the module to import. 

   Change **import fileio from '@ohos.fileio'** to **import fs from '@ohos.file.fs'**.

2. Change the exception handling method. 

   Sample code for exception handling in a synchronous API:

   ```js
   import fs from '@ohos.file.fs'
   
   try {
       let file = fs.openSync(path, fs.OpenMode.READ_ONLY);
   } catch (err) {
       console.error("openSync errCode:" + err.code + ", errMessage:" + err.message);
   }
   ```

   Sample code for exception handling in an asynchronous API (promise):

   ```js
   import fs from '@ohos.file.fs'
   
   try {
       let file = await fs.open(path, fs.OpenMode.READ_ONLY);
   } catch (err) {
       console.error("open promise errCode:" + err.code + ", errMessage:" + err.message);
   }
   
   ```

   Sample code for exception handling in an asynchronous API (callback):

   ```js
   import fs from '@ohos.file.fs'
   
   try {
       fs.open(path, fs.OpenMode.READ_ONLY, function(e, file){ // Asynchronous thread errors (such as a syscall error) are obtained via a callback.
           if (e) {
               console.error("open in async errCode:" + e.code + ", errMessage:" + e.message);
           }
       });
   } catch (err) {// Main thread errors (such as invalid parameters) are obtained by try catch.
       console.error("open callback errCode:" + err.code + ", errMessage:" + err.message);
   }
   ```

   