# File Management Subsystem Changelog

## cl.filemanagement.1 environment Module Change 

Moved the file management subsystem **d.ts** file to the **file** directory. The **environment** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **environment** module supports error code processing.

**Key API/Component Changes**

Before the change, **environment** is imported from **@ohos.environment**:

```js
import environment from '@ohos.environment';
```

Now, **environment** is imported from **@ohos.file.environment**:

```js
import environment from '@ohos.file.environment';
```

## cl.filemanagement.2 securityLabel Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **securityLabel** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **securityLabel** module supports error code processing.

**Key API/Component Changes**

Before the change, **securityLabel** is imported from **@ohos.securityLabel**:

```js
import securityLabel from '@ohos.securityLabel';
```

Now, **securityLabel** is imported from **@ohos.file.securityLabel**:

```js
import securityLabel from '@ohos.file.securityLabel';
```

## cl.filemanagement.3 fs Change

Changed the **ino** attribute type of **Stat** under **fs**.

**Change Impact**

The **ino** attribute type is changed from number to BigInt, to adapt to the **inode** range of all types of files in the file system.

**Key API/Component Changes**

The type of the **ino** attribute of **Stat** is changed from number to BigInt.

## cl.filemanagement.4 fileAccess Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileAccess** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **fileAccess** module supports error code processing.

**Key API/Component Changes**

Before the change, **fileAccess** is imported from **@ohos.data.fileAccess**:

```js
import fileAccess from '@ohos.data.fileAccess';
```

Now, **fileAccess** is imported from **@ohos.file.fileAccess**:

```js
import fileAccess from '@ohos.file.fileAccess';
```

## cl.filemanagement.5 fileExtensionInfo Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **fileExtensionInfo** module supports error code processing.

**Key API/Component Changes**

Before the change, **fileExtensionInfo** is imported from **@ohos.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

Now, **fileExtensionInfo** is imported from **@ohos.file.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## cl.filemanagement.6 storageStatistics Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **storageStatistics** module supports error code processing.

**Key API/Component Changes**

Before the change, **storageStatistics** was imported from **@ohos.storageStatistics**:

```js
import storageStatistics from '@ohos.storageStatistics';
```

Now, **storageStatistics** is imported from **@ohos.file.storageStatistics**:

```js
import storageStatistics from '@ohos.file.storageStatistics';
```

## cl.filemanagement.7 volumeManager Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **volumeManager** module supports error code processing.

**Key API/Component Changes**

Before the change, **volumeManager** was imported from **@ohos.volumeManager**:

```js
import volumeManager from '@ohos.volumeManager';
```

Now, **volumeManager** is imported from **@ohos.file.volumeManager**:

```js
import volumeManager from '@ohos.file.volumeManager';
```

## cl.filemanagement.8 fileio API Changes

Deprecated the **fileio** APIs, which do not return error codes, and added APIs that return error codes.

**Change Impact**

For applications developed based on earlier versions, pay attention to the iterative update of deprecated APIs. The specifications of the new APIs are slightly adjusted. Pay attention to the usage of the new APIs.

**Key API/Component Changes**

The APIs of **@ohos.fileio** do not support error code handling and are deprecated. New APIs with minor changes in parameters are added in **@ohos.file.fs** to support unified error code handling specifications. The new APIs function the same as the original APIs. The following table lists the API changes.
The API names remain unchanged.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** access(path: string, mode?: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | Deprecated    |
| @ohos.fileio        |  **function** accessSync(path: string, mode?: number): void | Deprecated    |
| @ohos.file.fs |  **function**  access(path: string, callback?: AsyncCallback\<boolean>): void \| Promise\<boolean> | Added    |
| @ohos.file.fs |  **function** accessSync(path: string): boolean | Added    |
| @ohos.fileio        |  **function** close(fd: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | Deprecated    |
| @ohos.fileio        |  **function** closeSync(fd: number): void | Deprecated    |
| @ohos.file.fs |  **function** close(file: File \| number, callback?: AsyncCallback\<void>): void \| Promise\<void> | Added    |
| @ohos.file.fs |  **function** closeSync(file: File \| number): void | Added    |
| @ohos.fileio        |  **function** mkdir(path: string, mode?: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | Deprecated    |
| @ohos.fileio        |  **function** mkdirSync(path: string, mode?: number): void | Deprecated    |
| @ohos.file.fs |  **function** mkdir(path: string, callback?: AsyncCallback\<void>): void \| Promise\<void> | Added    |
| @ohos.file.fs |  **function** mkdirSync(path: string): void | Added    |
| @ohos.fileio        |  **function** readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<string>): void \| Promise\<string> | Deprecated    |
| @ohos.fileio        |  **function** readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string | Deprecated    |
| @ohos.file.fs |  **function** readText(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<string>): void \| Promise\<string> | Added    |
| @ohos.file.fs |  **function** readTextSync(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }): string | Added    |
| @ohos.fileio        |  **function** Stream.read(buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }, callback?: AsyncCallback\<ReadOut>): void \| Promise\<ReadOut> | Deprecated    |
| @ohos.fileio        |  **function** Stream.readSync(buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number | Deprecated    |
| @ohos.file.fs |  **function** Stream.read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback?: AsyncCallback\<number>): void \| Promise\<number> | Added    |
| @ohos.file.fs |  **function** Stream.readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number | Added    |
| @ohos.fileio        |  **function** Stream.write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }, callback?: AsyncCallback\<number>): void \| Promise\<void> | Deprecated    |
| @ohos.fileio        |  **function** Stream.writeSync(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number | Deprecated    |
| @ohos.file.fs |  **function** Stream.write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<number>): void \| Promise\<void> | Added    |
| @ohos.file.fs |  **function** Stream.writeSync(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }): number | Added    |

**Adaptation Guide**

The APIs of @ohos.file.fs support unified exception handling. For details, see [File Management](../../../application-dev/reference/apis/js-apis-file-fs.md).
