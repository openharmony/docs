# 文件管理子系统ChangeLog

## cl.filemanagement.1 environment模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。environment模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现environment模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原environment使用的是@ohos.environment，以以下方式import:

```js
import environment from '@ohos.environment';
```

现environment使用的是@ohos.file.environment，以以下方式import:

```js
import environment from '@ohos.file.environment';
```

## cl.filemanagement.2 securityLabel模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。securityLabel模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现securityLabel模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原securityLabel使用的是@ohos.securityLabel，以以下方式import:

```js
import securityLabel from '@ohos.securityLabel';
```

现securityLabel使用的是@ohos.file.securityLabel，以以下方式import:

```js
import securityLabel from '@ohos.file.securityLabel';
```

## cl.filemanagement.3 fs模块变更

fs模块下Stat接口ino属性类型变更。

**变更影响**

fs模块下Stat接口ino属性类型变更，由number变更为bigint，以适配文件系统下所有类型文件的inode范围。

**关键接口/组件变更**

原Stat接口ino属性类型为number，现变更为bigint。

## cl.filemanagement.4 fileAccess模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileAccess模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现fileAccess模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原fileAccess使用的是@ohos.data.fileAccess，以以下方式import:

```js
import fileAccess from '@ohos.data.fileAccess';
```

现fileAccess使用的是@ohos.file.fileAccess，以以下方式import:

```js
import fileAccess from '@ohos.file.fileAccess';
```

## cl.filemanagement.5 fileExtensionInfo模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现fileExtensionInfo模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原fileExtensionInfo使用的是@ohos.fileExtensionInfo，以以下方式import:

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

现fileExtensionInfo使用的是@ohos.file.fileExtensionInfo，以以下方式import:

```js
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## cl.filemanagement.6 storageStatistics模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现storageStatistics模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原storageStatistics使用的是@ohos.storageStatistics，以以下方式import:

```js
import storageStatistics from '@ohos.storageStatistics';
```

现storageStatistics使用的是@ohos.file.storageStatistics，以以下方式import:

```js
import storageStatistics from '@ohos.file.storageStatistics';
```

## cl.filemanagement.7 volumeManager模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现volumeManager模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原volumeManager使用的是@ohos.volumeManager，以以下方式import:

```js
import volumeManager from '@ohos.volumeManager';
```

现volumeManager使用的是@ohos.file.volumeManager，以以下方式import:

```js
import volumeManager from '@ohos.file.volumeManager';
```

## cl.filemanagement.8 fileio相关接口异常处理方式变更

file_api部件fileio接口返回值不包含错误码error.code，现进行错误码整改，废弃原有相关接口，新增相关接口。

**变更影响**

基于此前版本开发的应用，需注意废弃接口的迭代更新。新接口在接口规格上进行了微调，需注意新接口使用方法。

**关键接口/组件变更**

为适配统一的API异常处理方式，对fileio相关接口进行废弃，并新增对应接口，原接口位于@ohos.fileio，新接口位于@ohos.file.fs。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致，参数上有微调，以下为规格调整的接口列表。
废弃与新增方法同名，请在列表中对应查看。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** access(path: string, mode?: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | 废弃     |
| @ohos.fileio        |  **function** accessSync(path: string, mode?: number): void | 废弃     |
| @ohos.file.fs |  **function**  access(path: string, callback?: AsyncCallback\<boolean>): void \| Promise\<boolean> | 新增     |
| @ohos.file.fs |  **function** accessSync(path: string): boolean | 新增     |
| @ohos.fileio        |  **function** close(fd: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | 废弃     |
| @ohos.fileio        |  **function** closeSync(fd: number): void | 废弃     |
| @ohos.file.fs |  **function** close(file: File \| number, callback?: AsyncCallback\<void>): void \| Promise\<void> | 新增     |
| @ohos.file.fs |  **function** closeSync(file: File \| number): void | 新增     |
| @ohos.fileio        |  **function** mkdir(path: string, mode?: number, callback?: AsyncCallback\<void>): void \| Promise\<void> | 废弃     |
| @ohos.fileio        |  **function** mkdirSync(path: string, mode?: number): void | 废弃     |
| @ohos.file.fs |  **function** mkdir(path: string, callback?: AsyncCallback\<void>): void \| Promise\<void> | 新增     |
| @ohos.file.fs |  **function** mkdirSync(path: string): void | 新增     |
| @ohos.fileio        |  **function** readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<string>): void \| Promise\<string> | 废弃     |
| @ohos.fileio        |  **function** readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string | 废弃     |
| @ohos.file.fs |  **function** readText(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<string>): void \| Promise\<string> | 新增     |
| @ohos.file.fs |  **function** readTextSync(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }): string | 新增     |
| @ohos.fileio        |  **function** Stream.read(buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }, callback?: AsyncCallback\<ReadOut>): void \| Promise\<ReadOut> | 废弃     |
| @ohos.fileio        |  **function** Stream.readSync(buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number | 废弃     |
| @ohos.file.fs |  **function** Stream.read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback?: AsyncCallback\<number>): void \| Promise\<number> | 新增     |
| @ohos.file.fs |  **function** Stream.readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number | 新增     |
| @ohos.fileio        |  **function** Stream.write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }, callback?: AsyncCallback\<number>): void \| Promise\<void> | 废弃     |
| @ohos.fileio        |  **function** Stream.writeSync(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number | 废弃     |
| @ohos.file.fs |  **function** Stream.write(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }, callback?: AsyncCallback\<number>): void \| Promise\<void> | 新增     |
| @ohos.file.fs |  **function** Stream.writeSync(buffer: ArrayBuffer \| string, options?: { offset?: number; length?: number; encoding?: string; }): number | 新增     |

**适配指导**

@ohos.file.fs新增统一的API异常处理方式，具体示例代码请参考[接口文档](../../../application-dev/reference/apis/js-apis-file-fs.md)。
