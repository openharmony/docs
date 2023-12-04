# @ohos.file.fs (File Management)

The **fs** module provides APIs for file operations, including basic file management, directory management, file information statistics, and data read and write using a stream.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fs from '@ohos.file.fs';
```

## Guidelines

Before using the APIs provided by this module to perform operations on a file or directory, obtain the application sandbox path of the file or directory as follows:

**Stage Model**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

FA Model

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  let context = featureAbility.getContext();
  context.getFilesDir().then((data) => {
    let pathDir = data;
  })
  ```

For details about how to obtain the FA model context, see [Context](js-apis-inner-app-context.md#context).

## fs.stat

stat(file: string | number): Promise&lt;Stat&gt;

Obtains detailed file attribute information. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| file   | string\|number | Yes  | Application sandbox path or file descriptor (FD) of the file.|

**Return value**

| Type                          | Description        |
| ---------------------------- | ---------- |
| Promise&lt;[Stat](#stat)&gt; | Promise used to return detailed file information.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.stat(filePath).then((stat: fs.Stat) => {
    console.info("get file info succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.info("get file info failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.stat

stat(file: string | number, callback: AsyncCallback&lt;Stat&gt;): void

Obtains detailed file information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                          |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| file     | string\|number                            | Yes  | Application sandbox path or FD of the file.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback invoked to return the file information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fs.stat(pathDir, (err: BusinessError, stat: fs.Stat) => {
    if (err) {
      console.info("get file info failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("get file info succeed, the size of file is " + stat.size);
    }
  });
  ```

## fs.statSync

statSync(file: string | number): Stat

Obtains detailed file information. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| file   | string\|number | Yes  | Application sandbox path or FD of the file.|

**Return value**

| Type           | Description        |
| ------------- | ---------- |
| [Stat](#stat) | File information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let stat = fs.statSync(pathDir);
  console.info("get file info succeed, the size of file is " + stat.size);
  ```

## fs.access

access(path: string): Promise&lt;boolean&gt;

Checks whether a file exists. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file to check.                                  |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. A Boolean value is returned, indicating whether the file exists.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.access(filePath).then((res: boolean) => {
    if (res) {
      console.info("file exists");
    } else {
      console.info("file not exists");
    }
  }).catch((err: BusinessError) => {
    console.info("access failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.access

access(path: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a file exists. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                                  |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the file exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.access(filePath, (err: BusinessError, res: boolean) => {
    if (err) {
      console.info("access failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      if (res) {
        console.info("file exists");
      } else {
        console.info("file not exists");
      }
    }
  });
  ```

## fs.accessSync

accessSync(path: string): boolean

Checks whether a file exists. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file to check.                                  |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| boolean | Returns **true** if the file exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  try {
    let res = fs.accessSync(filePath);
    if (res) {
      console.info("file exists");
    } else {
      console.info("file not exists");
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.info("accessSync failed with error message: " + err.message + ", error code: " + err.code);
  }
  ```


## fs.close

close(file: number | File): Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| file   | number\|[File](#file) | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read/write operations.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.close(file).then(() => {
    console.info("File closed");
  }).catch((err: BusinessError) => {
    console.info("close file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.close

close(file: number | File, callback: AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| file       | number\|[File](#file)                  | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read/write operations.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked immediately after the file is closed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.close(file, (err: BusinessError) => {
    if (err) {
      console.info("close file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File closed");
    }
  });
  ```

## fs.closeSync

closeSync(file: number | File): void

Closes a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| file   | number\|[File](#file) | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read/write operations.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.closeSync(file);
  ```

## fs.copyFile

copyFile(src: string | number, dest: string | number, mode?: number): Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type                        | Mandatory  | Description                                      |
| ---- | -------------------------- | ---- | ---------------------------------------- |
| src  | string\|number | Yes   | Path or FD of the file to copy.                     |
| dest | string\|number | Yes   | Destination path of the file or FD of the file created.                         |
| mode | number                     | No   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, 0).then(() => {
    console.info("copy file succeed");
  }).catch((err: BusinessError) => {
    console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file with the specified mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                        | Mandatory  | Description                                      |
| -------- | -------------------------- | ---- | ---------------------------------------- |
| src      | string\|number | Yes   | Path or FD of the file to copy.                     |
| dest     | string\|number | Yes   | Destination path of the file or FD of the file created.                         |
| mode     | number                     | Yes   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked immediately after the file is copied.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, 0, (err: BusinessError) => {
    if (err) {
      console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy file succeed");
    }
  });
  ```

## fs.copyFile

copyFile(src: string | number, dest: string | number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API overwrites the file with the same name in the destination directory and truncates the part that is not overwritten. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                        | Mandatory  | Description                                      |
| -------- | -------------------------- | ---- | ---------------------------------------- |
| src      | string\|number | Yes   | Path or FD of the file to copy.                     |
| dest     | string\|number | Yes   | Destination path of the file or FD of the file created.                         |
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked immediately after the file is copied.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, (err: BusinessError) => {
    if (err) {
      console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy file succeed");
    }
  });
  ```


## fs.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

Copies a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type                        | Mandatory  | Description                                      |
| ---- | -------------------------- | ---- | ---------------------------------------- |
| src  | string\|number | Yes   | Path or FD of the file to copy.                     |
| dest | string\|number | Yes   | Destination path of the file or FD of the file created.                         |
| mode | number                     | No   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFileSync(srcPath, dstPath);
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode?: number): Promise\<void>

Copies a folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to copy.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | No   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination folder. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, 0).then(() => {
    console.info("copy directory succeed");
  }).catch((err: BusinessError) => {
    console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies a folder with the specified mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to copy.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | Yes   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination folder. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { ConflictFiles } from '@ohos.file.fs';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, 0, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015) {
      for (let i = 0; i < err.data.length; i++) {
        console.info("copy directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy directory succeed");
    }  
  });
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies a folder. This API uses an asynchronous callback to return the result.

An exception will be thrown if there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to copy.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { ConflictFiles } from '@ohos.file.fs';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015) {
      for (let i = 0; i < err.data.length; i++) {
        console.info("copy directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy directory succeed");
    }  
  });
  ```

## fs.copyDirSync<sup>10+</sup>

copyDirSync(src: string, dest: string, mode?: number): void

Copies a folder. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to copy.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | No   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination folder. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  try {
    fs.copyDirSync(srcPath, destPath, 0);
    console.info("copy directory succeed");
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);
  }
  ```

## fs.dup<sup>10+</sup>

dup(fd: number): File

Opens a **File** object based on an FD.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| fd | number | Yes   | FD of the file.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file1 = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let fd: number = file1.fd;
  let file2 = fs.dup(fd);
  console.info("The name of the file2 is " + file2.name);
  fs.closeSync(file1);
  fs.closeSync(file2);
  ```


## fs.mkdir

mkdir(path: string): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir";
  fs.mkdir(dirPath).then(() => {
    console.info("Directory created");
  }).catch((err: BusinessError) => {
    console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean): Promise<void>

Creates a directory. This API uses a promise to return the result. If **recursion** is set to **true**, a multi-level directory is created.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a multi-level directory.<br>The value **true** means to create a multi-level directory. The value **false** means to create a single-level directory.  |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdir(dirPath, true).then(() => {
    console.info("Directory created");
  }).catch((err: BusinessError) => {
    console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdir

mkdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir";
  fs.mkdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory created");
    }
  });
  ```

## fs.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result. If **recursion** is set to **true**, a multi-level directory is created.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a multi-level directory.<br>The value **true** means to create a multi-level directory. The value **false** means to create a single-level directory.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdir(dirPath, true, (err: BusinessError) => {
    if (err) {
      console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory created");
    }
  });
  ```

## fs.mkdirSync

mkdirSync(path: string): void

Creates a directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fs.mkdirSync(dirPath);
  ```

## fs.mkdirSync<sup>11+</sup>

mkdirSync(path: string, recursion: boolean): void

Creates a directory. This API returns the result synchronously. If **recursion** is set to **true**, a multi-level directory is created.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a multi-level directory.<br>The value **true** means to create a multi-level directory. The value **false** means to create a single-level directory.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdirSync(dirPath, true);
  ```

## fs.open

open(path: string, mode?: number): Promise&lt;File&gt;

Opens a file. This API uses a promise to return the result. The uniform resource identifier (URI) can be used to open a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path or URI of the file.                                  |
| mode  | number | No  | [Mode](#openmode) for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;[File](#file)&gt; | Promise used to return the **File** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE).then((file: fs.File) => {
    console.info("file fd: " + file.fd);
    fs.closeSync(file);
  }).catch((err: BusinessError) => {
    console.info("open file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```


## fs.open

open(path: string, mode: number, callback: AsyncCallback&lt;File&gt;): void

Opens a file with the specified mode. This API uses an asynchronous callback to return the result.

File URIs are supported. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path or URI of the file.                                  |
| mode  | number | Yes  | [Mode](#openmode) for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE, (err: BusinessError, file: fs.File) => {
    if (err) {
      console.info("open failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("file fd: " + file.fd);
    }
    fs.closeSync(file);
  });
  ```

## fs.open

open(path: string, callback: AsyncCallback&lt;File&gt;): void

Opens a file. This API uses an asynchronous callback to return the result. File URIs are supported. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path or URI of the file.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, (err: BusinessError, file: fs.File) => {
    if (err) {
      console.info("open failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("file fd: " + file.fd);
    }
    fs.closeSync(file);
  });
  ```

## fs.openSync

openSync(path: string, mode?: number): File

Opens a file. This API returns the result synchronously. File URIs are supported. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path or URI of the file.                                  |
| mode  | number | No  | [Mode](#openmode) for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  console.info("file fd: " + file.fd);
  fs.closeSync(file);
  ```

## fs.read

read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): Promise&lt;number&gt;

Reads data from a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type       | Mandatory| Description                                                        |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | Yes  | FD of the file.                                    |
| buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
| options | Object      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;number&gt; | Promise used to return the length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fs.read(file.fd, arrayBuffer).then((readLen: number) => {
    console.info("Read file data successfully");
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.info("read file data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.read

read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| fd       | number                                   | Yes   | FD of the file.                            |
| buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
| options | Object      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the result.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fs.read(file.fd, arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.info("read failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Read file data successfully");
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`The content of file: ${buf.toString()}`);
    }
    fs.closeSync(file);
  });
  ```

## fs.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number

Reads data from a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| fd      | number      | Yes   | FD of the file.                            |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file data read.                       |
| options | Object      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let buf = new ArrayBuffer(4096);
  fs.readSync(file.fd, buf);
  fs.closeSync(file);
  ```

## fs.rmdir

rmdir(path: string): Promise&lt;void&gt;

Deletes a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir";
  fs.rmdir(dirPath).then(() => {
    console.info("Directory deleted");
  }).catch((err: BusinessError) => {
    console.info("rmdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.rmdir

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir";
  fs.rmdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.info("rmdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory deleted");
    }
  });
  ```

## fs.rmdirSync

rmdirSync(path: string): void

Deletes a directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fs.rmdirSync(dirPath);
  ```

## fs.unlink

unlink(path: string): Promise&lt;void&gt;

Deletes a single file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.unlink(filePath).then(() => {
    console.info("File deleted");
  }).catch((err: BusinessError) => {
    console.info("remove file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked immediately after the file is deleted.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.unlink(filePath, (err: BusinessError) => {
    if (err) {
      console.info("remove file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File deleted");
    }
  });
  ```

## fs.unlinkSync

unlinkSync(path: string): void

Deletes a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fs.unlinkSync(filePath);
  ```


## fs.write

write(fd: number, buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data to a file. This API uses a promise to return the data.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| fd      | number                          | Yes   | FD of the file.                            |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

| Type                   | Description      |
| --------------------- | -------- |
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let str: string = "hello, world";
  fs.write(file.fd, str).then((writeLen: number) => {
    console.info("write data to file succeed and size is:" + writeLen);
  }).catch((err: BusinessError) => {
    console.info("write data to file failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.write

write(fd: number, buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                             | Mandatory  | Description                                      |
| -------- | ------------------------------- | ---- | ---------------------------------------- |
| fd       | number                          | Yes   | FD of the file.                            |
| buffer   | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|
| callback | AsyncCallback&lt;number&gt;     | Yes   | Callback invoked to return the result.                      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let str: string = "hello, world";
  fs.write(file.fd, str, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.info("write data to file failed with error message:" + err.message + ", error code: " + err.code);
    } else {
      console.info("write data to file succeed and size is:" + writeLen);
    }
    fs.closeSync(file);
  });
  ```

## fs.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): number

Writes data to a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| fd      | number                          | Yes   | FD of the file.                            |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data written in the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let str: string = "hello, world";
  let writeLen = fs.writeSync(file.fd, str);
  console.info("write data to file succeed and size is:" + writeLen);
  fs.closeSync(file);
  ```

## fs.truncate

truncate(file: string | number, len?: number): Promise&lt;void&gt;

Truncates a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| file   | string\|number | Yes  | Application sandbox path or FD of the file.      |
| len    | number | No  | File length, in bytes, after truncation. The default value is **0**.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncate(filePath, len).then(() => {
    console.info("File truncated");
  }).catch((err: BusinessError) => {
    console.info("truncate file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.truncate

truncate(file: string | number, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| file     | string\|number                    | Yes  | Application sandbox path or FD of the file.      |
| len      | number                    | No  | File length, in bytes, after truncation. The default value is **0**.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncate(filePath, len, (err: BusinessError) => {
    if (err) {
      console.info("truncate failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("truncate succeed");
    }
  });
  ```

## fs.truncateSync

truncateSync(file: string | number, len?: number): void

Truncates a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| file   | string\|number | Yes  | Application sandbox path or FD of the file.      |
| len    | number | No  | File length, in bytes, after truncation. The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncateSync(filePath, len);
  ```

## fs.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options): Promise&lt;ReaderIterator&gt;

Reads the file text line by line. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options | [Options](#options11) | No  | Options for reading the text. The following options are supported:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;[ReaderIterator](#readeriterator11)&gt; | Promise used to return a **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import { Options } from '@ohos.file.fs';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options).then((readerIterator: fs.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info("content: " + it.value);
    }
  }).catch((err: BusinessError) => {
    console.info("readLines failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options, callback: AsyncCallback&lt;ReaderIterator&gt;): void

Reads the text content of a file line by line. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options | [Options](#options11) | No  | Options for reading the text. The following options are supported:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | Yes  | Callback invoked to return a **ReaderIterator** object.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import { Options } from '@ohos.file.fs';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options, (err: BusinessError, readerIterator: fs.ReaderIterator) => {
    if (err) {
      console.info("readLines failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
        console.info("content: " + it.value);
      }
    }
  });
  ```

## fs.readLinesSync<sup>11+</sup>

readLinesSync(filePath: string, options?: Options): ReaderIterator

Reads the text content of a file line by line. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options | [Options](#options11) | No  | Options for reading the text. The following options are supported:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| [ReaderIterator](#readeriterator11) | **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { Options } from '@ohos.file.fs';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  let readerIterator = fs.readLines(filePath, options);
  for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
    console.info("content: " + it.value);
  }
  ```

## ReaderIterator<sup>11+</sup>

Provides a **ReaderIterator** object. Before calling APIs of **ReaderIterator**, you need to use **readLines()** to create a **ReaderIterator** instance.

### next<sup>11+</sup>

next(): ReaderIteratorResult

Obtains the **ReaderIterator** result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| ReaderIteratorResult | **ReaderIteratorResult** object obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import { Options } from '@ohos.file.fs';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options).then((readerIterator: fs.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info("content: " + it.value);
    }
  }).catch((err: BusinessError) => {
    console.info("readLines failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## ReaderIteratorResult

Represents the information obtained by the **ReadIterator** object.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Description               |
| ----------- | --------------- | ------------------ |
| done | boolean     |  Whether the iteration is complete.         |
| value    | string     | File text content read line by line.|

## fs.readText

readText(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }): Promise&lt;string&gt;

Reads the text content of a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options  | Object | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise used to return the file content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.readText(filePath).then((str: string) => {
    console.info("readText succeed:" + str);
  }).catch((err: BusinessError) => {
    console.info("readText failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.readText

readText(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;string&gt;): void

Reads the text content of a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | Yes  | Application sandbox path of the file.                                  |
| options  | Object                      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding**: format of the data to be encoded. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the content read.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let stat = fs.statSync(filePath);
  let option = new Option();
  option.offset = 1;
  option.length = stat.size;
  fs.readText(filePath, option, (err: BusinessError, str: string) => {
    if (err) {
      console.info("readText failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("readText succeed:" + str);
    }
  });
  ```

## fs.readTextSync

readTextSync(filePath: string, options?: { offset?: number; length?: number; encoding?: string; }): string

Reads the text of a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options  | Object | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Content of the file read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let stat = fs.statSync(filePath);
  let option = new Option();
  option.offset = 1;
  option.length = stat.size;
  let str = fs.readTextSync(filePath, option);
  console.info("readText succeed:" + str);
  ```

## fs.lstat

lstat(path: string): Promise&lt;Stat&gt;

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the symbolic link.|

**Return value**

| Type                          | Description        |
| ---------------------------- | ---------- |
| Promise&lt;[Stat](#stat)&gt; | Promise used to return the symbolic link information obtained. For details, see **stat**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/linkToFile";
  fs.lstat(filePath).then((stat: fs.Stat) => {
    console.info("lstat succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.info("lstat failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.lstat

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                                  |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | Yes  | Application sandbox path of the symbolic link.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback invoked to return the symbolic link information obtained.      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/linkToFile";
  fs.lstat(filePath, (err: BusinessError, stat: fs.Stat) => {
    if (err) {
      console.info("lstat failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("lstat succeed, the size of file is" + stat.size);
    }
  });
  ```

## fs.lstatSync

lstatSync(path: string): Stat

Obtains information about a symbolic link that is used to refer to a file or directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the symbolic link.|

**Return value**

| Type           | Description        |
| ------------- | ---------- |
| [Stat](#stat) | File information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/linkToFile";
  let fileStat = fs.lstatSync(filePath);
  console.info("lstat succeed, the size of file is" + fileStat.size);
  ```

## fs.rename

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file or folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or folder to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or folder.  |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.rename(srcFile, dstFile).then(() => {
    console.info("File renamed");
  }).catch((err: BusinessError) => {
    console.info("rename failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.rename

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

Renames a file or folder. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                        |
| -------- | ------------------------- | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or folder to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or folder.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.rename(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.info("rename failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File renamed");
    }
  });
  ```

## fs.renameSync

renameSync(oldPath: string, newPath: string): void

Renames a file or folder. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or folder to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or folder.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.renameSync(srcFile, dstFile);
  ```

## fs.fsync

fsync(fd: number): Promise&lt;void&gt;

Synchronizes a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | FD of the file.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsync(file.fd).then(() => {
    console.info("Data flushed");
  }).catch((err: BusinessError) => {
    console.info("sync data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.fsync

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description             |
| -------- | ------------------------- | ---- | --------------- |
| fd       | number                    | Yes   | FD of the file.   |
| Callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsync(file.fd, (err: BusinessError) => {
    if (err) {
      console.info("fsync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("fsync succeed");
    }
    fs.closeSync(file);
  });
  ```


## fs.fsyncSync

fsyncSync(fd: number): void

Synchronizes a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsyncSync(file.fd);
  fs.closeSync(file);
  ```

## fs.fdatasync

fdatasync(fd: number): Promise&lt;void&gt;

Synchronizes the data of a file. This API uses a promise to return the result. **fdatasync()** is similar to **fsync()**, but does not flush modified metadata unless that metadata is needed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | FD of the file.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdatasync(file.fd).then(() => {
    console.info("Data flushed");
  }).catch((err: BusinessError) => {
    console.info("sync data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.fdatasync

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes the data of a file. This API uses an asynchronous callback to return the result. **fdatasync()** is similar to **fsync()**, but does not flush modified metadata unless that metadata is needed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                             | Mandatory  | Description               |
| -------- | ------------------------------- | ---- | ----------------- |
| fd       | number                          | Yes   | FD of the file.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdatasync (file.fd, (err: BusinessError) => {
    if (err) {
      console.info("fdatasync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("fdatasync succeed");
    }
    fs.closeSync(file);
  });
  ```

## fs.fdatasyncSync

fdatasyncSync(fd: number): void

Synchronizes the data of a file. This API returns the result synchronously. **fdatasync()** is similar to **fsync()**, but does not flush modified metadata unless that metadata is needed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdatasyncSync(file.fd);
  fs.closeSync(file);
  ```

## fs.symlink

symlink(target: string, srcPath: string): Promise&lt;void&gt;

Creates a symbolic link based on a file path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the source file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlink(srcFile, dstFile).then(() => {
    console.info("Symbolic link created");
  }).catch((err: BusinessError) => {
    console.info("symlink failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```


## fs.symlink
symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on a file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | Yes  | Application sandbox path of the source file.        |
| srcPath  | string                    | Yes  | Application sandbox path of the symbolic link.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlink(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.info("symlink failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Symbolic link created");
    }
  });
  ```

## fs.symlinkSync

symlinkSync(target: string, srcPath: string): void

Creates a symbolic link based on a file path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the source file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlinkSync(srcFile, dstFile);
  ```

## fs.listFile
listFile(path: string, options?: {
    recursion?: boolean;
    listNum?: number;
    filter?: Filter;
}): Promise<string[]>

Lists all files, including the files in subfolders, in a directory. This API uses a promise to return the result.<br>You can also set a filter to list the files you want.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| path | string | Yes   | Application sandbox path of the folder.|
| options | Object | No   | Options for filtering files. The files are not filtered by default.|

**options parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| recursion | boolean | No   | Whether to list all files in subfolders recursively. The default value is **false**.<br>If **recursion** is **false**, the names of the files and folders that meet the specified conditions in the current directory are returned. If **recursion** is **true**, relative paths (starting with /) of all files that meet the specified conditions in the current directory are returned.|
| listNum | number | No   | Number of file names to list. The default value is **0**, which means to list all files.|
| filter | [Filter](#filter) | No   | Options for filtering files. Currently, files can be filtered by file name extension, fuzzy file name, file size, and latest modification time only.|

**Return value**

| Type                  | Description        |
| --------------------- | ---------- |
| Promise&lt;string[]&gt; | Promise used to return the file names listed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { Filter } from '@ohos.file.fs';
  class ListFileOption {
    public recursion: boolean = false;
    public listNum: number = 0;
    public filter: Filter = {};
  }
  let option = new ListFileOption();
  option.filter.suffix = [".png", ".jpg", ".jpeg"];
  option.filter.displayName = ["*abc", "efg*"];
  option.filter.fileSizeOver = 1024;
  option.filter.lastModifiedAfter = new Date().getTime();
  fs.listFile(pathDir, option).then((filenames: Array<string>) => {
    console.info("listFile succeed");
    for (let i = 0; i < filenames.length; i++) {
      console.info("fileName: %s", filenames[i]);
    }
  }).catch((err: BusinessError) => {
    console.info("list file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.listFile
listFile(path: string, options?: {
    recursion?: boolean;
    listNum?: number;
    filter?: Filter;
}, callback: AsyncCallback<string[]>): void

Lists all files, including the files in subfolders, in a directory. This API uses an asynchronous callback to return the result.<br>You can also set a filter to list the files you want.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| path | string | Yes   | Application sandbox path of the folder.|
| options | Object | No   | Options for filtering files. The files are not filtered by default.|
| callback | AsyncCallback&lt;string[]&gt; | Yes   | Callback invoked to return the file names listed.             |

**options parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| recursion | boolean | No   | Whether to list all files in subfolders recursively. The default value is **false**.<br>If **recursion** is **false**, the names of the files and folders that meet the specified conditions in the current directory are returned. If **recursion** is **true**, relative paths (starting with /) of all files that meet the specified conditions in the current directory are returned.|
| listNum | number | No   | Number of file names to list. The default value is **0**, which means to list all files.|
| filter | [Filter](#filter) | No   | Options for filtering files. Currently, files can be filtered by file name extension, fuzzy file name, file size, and latest modification time only.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { Filter } from '@ohos.file.fs';
  class ListFileOption {
    public recursion: boolean = false;
    public listNum: number = 0;
    public filter: Filter = {};
  }
  let option = new ListFileOption();
  option.filter.suffix = [".png", ".jpg", ".jpeg"];
  option.filter.displayName = ["*abc", "efg*"];
  option.filter.fileSizeOver = 1024;
  option.filter.lastModifiedAfter = new Date().getTime();
  fs.listFile(pathDir, option, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.info("list file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("listFile succeed");
      for (let i = 0; i < filenames.length; i++) {
        console.info("filename: %s", filenames[i]);
      }
    }
  });
  ```

## fs.listFileSync

listFileSync(path: string, options?: {
    recursion?: boolean;
    listNum?: number;
    filter?: Filter;
}): string[]

Lists all files, including the files in subfolders, in a directory. This API returns the result synchronously.<br>You can also set a filter to list the files you want.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| path | string | Yes   | Application sandbox path of the folder.|
| options | Object | No   | Options for filtering files. The files are not filtered by default.|

**options parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| recursion | boolean | No   | Whether to list all files in subfolders recursively. The default value is **false**.<br>If **recursion** is **false**, the names of the files and folders that meet the specified conditions in the current directory are returned. If **recursion** is **true**, relative paths (starting with /) of all files that meet the specified conditions in the current directory are returned.|
| listNum | number | No   | Number of file names to list. The default value is **0**, which means to list all files.|
| filter | [Filter](#filter) | No   | Options for filtering files. Currently, files can be filtered by file name extension, fuzzy file name, file size, and latest modification time only.|

**Return value**

| Type                  | Description        |
| --------------------- | ---------- |
| string[] | List of the files obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import fs, { Filter } from '@ohos.file.fs';
  class ListFileOption {
    public recursion: boolean = false;
    public listNum: number = 0;
    public filter: Filter = {};
  }
  let option = new ListFileOption();
  option.filter.suffix = [".png", ".jpg", ".jpeg"];
  option.filter.displayName = ["*abc", "efg*"];
  option.filter.fileSizeOver = 1024;
  option.filter.lastModifiedAfter = new Date().getTime();
  let filenames = fs.listFileSync(pathDir, option);
  console.info("listFile succeed");
  for (let i = 0; i < filenames.length; i++) {
    console.info("filename: %s", filenames[i]);
  }
  ```

## fs.lseek<sup>11+</sup>

lseek(fd: number, offset: number, whence?: WhenceType): number

Sets the offset of a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| fd | number | Yes   | FD of the file.|
| offset | number | Yes   | Offset to set.|
| whence | [WhenceType](#whencetype11) | No   | Type of the relative position of the offset.|

**Return value**

| Type                  | Description        |
| --------------------- | ---------- |
| number | Position of the current offset as measured from the beginning of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  console.info('The current offset is at ' + fs.lseek(file.fd, 5, fs.WhenceType.SEEK_SET));
  fs.closeSync(file);
  ```

## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode?: number): Promise\<void>

Moves a folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to move.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | No   | Mode for moving the folder. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br>Throw an exception if there is a non-empty folder with the same name in the destination directory.<br>- **1**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.<br>- **3**: Forcibly overwrite the conflicting folder.<br>Move the source folder to the destination directory and overwrite the conflicting folder completely. That is, if there is a folder with the same name in the destination directory, all the original files in that folder will not be retained.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, 1).then(() => {
    console.info("move directory succeed");
  }).catch((err: BusinessError) => {
    console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves a folder with the specified mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to move.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | Yes   | Mode for moving the folder. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination directory.<br>- **1**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.<br>- **3**: Forcibly overwrite the conflicting folder.<br>Move the source folder to the destination directory and overwrite the conflicting folder completely. That is, if there is a folder with the same name in the destination directory, all the original files in that folder will not be retained.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { ConflictFiles } from '@ohos.file.fs';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, 1, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015) {
      for (let i = 0; i < data.length; i++) {
        console.info("move directory failed with conflicting files: " + data[i].srcFile + " " + data[i].destFile);
      }
    } else if (err) {
      console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move directory succeed");
    }  
  });
  ```

  ## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves a folder. This API uses an asynchronous callback to return the result.

An exception will be thrown if there is a folder with the same name in the destination directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to move.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fs, { ConflictFiles } from '@ohos.file.fs';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015) {
      for (let i = 0; i < data.length; i++) {
        console.info("move directory failed with conflicting files: " + data[i].srcFile + " " + data[i].destFile);
      }
    } else if (err) {
      console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move directory succeed");
    }  
  });
  ```

## fs.moveDirSync<sup>10+</sup>

moveDirSync(src: string, dest: string, mode?: number): void

Moves a folder. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the folder to move.|
| dest | string | Yes   | Application sandbox path of the destination folder.|
| mode | number | No   | Mode for moving the folder. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination directory.<br>- **1**: Throw an exception if a file conflict occurs.<br>Throw an exception if there is a folder with the same name in the destination folder and there are files with the same name in the conflicting folder. All the non-conflicting files in the source folder will be moved to the destination folder, and the non-conflicting files in the destination folder will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory. If there is a folder with the same name in the destination directory and there are files with the same name in the conflicting folder, all the files with the same name in the destination folder will be overwritten and the non-conflicting files will be retained.<br>- **3**: Forcibly overwrite the conflicting folder.<br>Move the source folder to the destination directory and overwrite the conflicting folder completely. That is, if there is a folder with the same name in the destination directory, all the original files in that folder will not be retained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  try {
    fs.moveDirSync(srcPath, destPath, 1);
    console.info("move directory succeed");
  } catch (err) {
    console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);
  }
  ```

## fs.moveFile

moveFile(src: string, dest: string, mode?: number): Promise\<void>

Moves a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the file to move. |
| dest | string | Yes   | Application sandbox path of the destination file.|
| mode | number | No   | Whether to overwrite the file with the same name in the destination directory.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception.<br>The default value is **0**.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, 0).then(() => {
    console.info("move file succeed");
  }).catch((err: BusinessError) => {
    console.info("move file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.moveFile

moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

Moves a file with the specified mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the source file.|
| dest | string | Yes   | Application sandbox path of the destination file.|
| mode | number | Yes   | Whether to overwrite the file with the same name in the destination directory.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception.<br>The default value is **0**.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, 0, (err: BusinessError) => {
    if (err) {
      console.info("move file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move file succeed");
    }  
  });
  ```

## fs.moveFile

moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void

Moves a file and forcibly overwrites the file with the same name in the destination directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the source file.|
| dest | string | Yes   | Application sandbox path of the destination file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, (err: BusinessError) => {
    if (err) {
      console.info("move file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move file succeed");
    }  
  });
  ```

## fs.moveFileSync

moveFileSync(src: string, dest: string, mode?: number): void

Moves a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| src | string | Yes   | Application sandbox path of the source file.|
| dest | string | Yes   | Application sandbox path of the destination file.|
| mode | number | No   | Whether to overwrite the file with the same name in the destination directory.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception.<br>The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFileSync(srcPath, destPath, 0);
  console.info("move file succeed");
  ```

## fs.mkdtemp

mkdtemp(prefix: string): Promise&lt;string&gt;

Creates a temporary directory. The folder name is created by replacing a string (specified by **prefix**) with six randomly generated characters. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory. |

**Return value**

| Type                  | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise used to return the directory created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fs.mkdtemp(pathDir + "/XXXXXX").then((dir: string) => {
    console.info("mkdtemp succeed:" + dir);
  }).catch((err: BusinessError) => {
    console.info("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdtemp

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

Creates a temporary directory. The folder name is created by replacing a string (specified by **prefix**) with six randomly generated characters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                         | Mandatory  | Description                         |
| -------- | --------------------------- | ---- | --------------------------- |
| prefix   | string                      | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory. |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fs.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {
    if (err) {
      console.info("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("mkdtemp succeed");
    }
  });
  ```

## fs.mkdtempSync

mkdtempSync(prefix: string): string

Creates a temporary directory. The folder name is created by replacing a string (specified by **prefix**) with six randomly generated characters. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory. |

**Return value**

| Type   | Description        |
| ------ | ---------- |
| string | Unique path generated.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let res = fs.mkdtempSync(pathDir + "/XXXXXX");
  ```

## fs.utimes<sup>11+</sup>

utimes(path: string, mtime: number): void

Updates the latest access timestamp of a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
|    Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
| path  | string  |  Yes   | Application sandbox path of the file.|
| mtime  | number  |  Yes  | New timestamp. The value is the number of milliseconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970). Only the last access time of a file can be modified.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.writeSync(file.fd, 'test data');
  fs.closeSync(file);
  fs.utimes(filePath, new Date().getTime());
  ```

## fs.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode?: number): Promise&lt;RandomAccessFile&gt;

Creates a **RandomAccessFile** instance based on a file path or file object. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
|    Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string\|[File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|

**Return value**

| Type                               | Description       |
| --------------------------------- | --------- |
| Promise&lt;[RandomAccessFile](#randomaccessfile)&gt; | Promise used to return the **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file).then((randomAccessFile: fs.RandomAccessFile) => {
    console.info("randomAccessFile fd: " + randomAccessFile.fd);
    randomAccessFile.close();
  }).catch((err: BusinessError) => {
    console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode: number, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

Creates a **RandomAccessFile** instance in read-only mode based on a file path or file object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string\|[File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | Yes  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile)&gt; | Yes  | Callback invoked to return the **RandomAccessFile** instance created.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file, fs.OpenMode.READ_ONLY (err: BusinessError, randomAccessFile: fs.RandomAccessFile) => {
    if (err) {
      console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("randomAccessFile fd: " + randomAccessFile.fd);
      randomAccessFile.close();
    }
    fs.closeSync(file);
  });
  ```

  ## fs.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode: number, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

Creates a **RandomAccessFile** instance based on a file path or file object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string\|[File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile)&gt; | Yes  | Callback invoked to return the **RandomAccessFile** instance created.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file, (err: BusinessError, randomAccessFile: fs.RandomAccessFile) => {
    if (err) {
      console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("randomAccessFile fd: " + randomAccessFile.fd);
      randomAccessFile.close();
    }
    fs.closeSync(file);
  });
  ```

## fs.createRandomAccessFileSync<sup>10+</sup>

createRandomAccessFileSync(file: string | File, mode?: number): RandomAccessFile

Creates a **RandomAccessFile** instance based on a file path or file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string\|[File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write-only or read/write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|

**Return value**

| Type               | Description       |
| ------------------ | --------- |
| [RandomAccessFile](#randomaccessfile) | **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  randomAccessFile.close();
  ```

## fs.createStream

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Creates a stream based on a file path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | string | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type                               | Description       |
| --------------------------------- | --------- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the stream opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.createStream(filePath, "r+").then((stream: fs.Stream) => {
    console.info("Stream created");
  }).catch((err: BusinessError) => {
    console.info("createStream failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    stream.closeSync();
  });
  ```


## fs.createStream

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Creates a stream based on a file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | Yes  | Application sandbox path of the file.                                  |
| mode     | string                                  | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes  | Callback invoked to return the result.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fs.createStream(filePath, "r+", (err: BusinessError, stream: fs.Stream) => {
    if (err) {
      console.info("create stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Stream created");
    }
    stream.closeSync();
  })  
  ```

## fs.createStreamSync

createStreamSync(path: string, mode: string): Stream

Creates a stream based on a file path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | string | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type               | Description       |
| ------------------ | --------- |
| [Stream](#stream) | Stream opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  console.info("Stream created");
  stream.closeSync();
  ```


## fs.fdopenStream

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a stream based on an FD. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes   | FD of the file.                            |
| mode | string | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type                              | Description       |
| --------------------------------- | --------- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the stream opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdopenStream(file.fd, "r+").then((stream: fs.Stream) => {
    console.info("Stream opened");
    stream.closeSync();
  }).catch((err: BusinessError) => {
    console.info("openStream failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.fdopenStream

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a stream based on an FD. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| fd       | number                                   | Yes   | FD of the file.                            |
| mode     | string                                   | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes   | Callback invoked to return the result.                           |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.fdopenStream(file.fd, "r+", (err: BusinessError, stream: fs.Stream) => {
    if (err) {
      console.info("fdopen stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("fdopen stream succeed");
      stream.closeSync();
    }
    fs.closeSync(file);
  });
  ```

## fs.fdopenStreamSync

fdopenStreamSync(fd: number, mode: string): Stream

Opens a stream based on an FD. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes   | FD of the file.                            |
| mode | string | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type               | Description       |
| ------------------ | --------- |
| [Stream](#stream) | Stream opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY | fs.OpenMode.CREATE);
  let stream = fs.fdopenStreamSync(file.fd, "r+");
  stream.closeSync();
  fs.closeSync(file);
  ```

## fs.createWatcher<sup>10+</sup>

createWatcher(path: string, events: number, listener: WatchEventListener): Watcher

Creates a **Watcher** object to observe file or directory changes.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| path   | string | Yes   | Application sandbox path of the file or directory to observe.                            |
| events | number | Yes   | Events to observe. Multiple events can be separated by a bitwise OR operator (\|).<br>- **0x1: IN_ACCESS**: A file is accessed.<br>- **0x2: IN_MODIFY**: The file content is modified.<br>- **0x4: IN_ATTRIB**: The file metadata is modified.<br>- **0x8: IN_CLOSE_WRITE**: A file is opened, written with data, and then closed.<br>- **0x10: IN_CLOSE_NOWRITE**: A file or directory is opened and then closed without data written.<br>- **0x20: IN_OPEN**: A file or directory is opened.<br>- **0x40: IN_MOVED_FROM**: A file in the observed directory is moved.<br>- **0x80: IN_MOVED_TO**: A file is moved to the observed directory.<br>- **0x100: IN_CREATE**: A file or directory is created in the observed directory.<br>- **0x200: IN_DELETE**: A file or directory is deleted from the observed directory.<br>- **0x400: IN_DELETE_SELF**: The observed directory is deleted. After the directory is deleted, the listening stops.<br>- **0x800: IN_MOVE_SELF**: The observed file or directory is moved. After the file or directory is moved, the listening continues.<br>- **0xfff: IN_ALL_EVENTS**: All events.|
| listener   | [WatchEventListener](#watcheventlistener10) | Yes   | Callback invoked when an observed event occurs. The callback will be invoked each time an observed event occurs.                            |

**Return value**

| Type               | Description       |
| ------------------ | --------- |
| [Watcher](#watcher10) | **Watcher** object created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import fs, { WatchEvent } from '@ohos.file.fs';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let watcher = fs.createWatcher(filePath, 0x2 | 0x10, (watchEvent: WatchEvent) => {
    if (watchEvent.event == 0x2) {
      console.info(watchEvent.fileName + 'was modified');
    } else if (watchEvent.event == 0x10) {
      console.info(watchEvent.fileName + 'was closed');
    }
  });
  watcher.start();
  fs.writeSync(file.fd, 'test');
  fs.closeSync(file);
  watcher.stop();
  ```

## WatchEventListener<sup>10+</sup>

(event: WatchEvent): void

Called when an observed event occurs.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| event   | WatchEvent | Yes   | Event for the callback to invoke.                            |

## WatchEvent<sup>10+</sup>

Defines the event to observe.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name  | Type  | Readable  | Writable  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| fileName | string | Yes   | No   | Name of the file for which the event occurs.|
| event | number | Yes   | No   | Events to observe. Multiple events can be separated by a bitwise OR operator (\|).<br>- **0x1: IN_ACCESS**: A file is accessed.<br>- **0x2: IN_MODIFY**: The file content is modified.<br>- **0x4: IN_ATTRIB**: The file metadata is modified.<br>- **0x8: IN_CLOSE_WRITE**: A file is opened, written with data, and then closed.<br>- **0x10: IN_CLOSE_NOWRITE**: A file or directory is opened and then closed without data written.<br>- **0x20: IN_OPEN**: A file or directory is opened.<br>- **0x40: IN_MOVED_FROM**: A file in the observed directory is moved.<br>- **0x80: IN_MOVED_TO**: A file is moved to the observed directory.<br>- **0x100: IN_CREATE**: A file or directory is created in the observed directory.<br>- **0x200: IN_DELETE**: A file or directory is deleted from the observed directory.<br>- **0x400: IN_DELETE_SELF**: The observed directory is deleted. After the directory is deleted, the listening stops.<br>- **0x800: IN_MOVE_SELF**: The observed file or directory is moved. After the file or directory is moved, the listening continues.<br>- **0xfff: IN_ALL_EVENTS**: All events.|
| cookie | number | Yes   | No   | Cookie bound with the event. Currently, only the **IN_MOVED_FROM** and **IN_MOVED_TO** events are supported. The **IN_MOVED_FROM** and **IN_MOVED_TO** events of the same file have the same **cookie** value.|

## Stat

Represents detailed file information. Before calling any API of the **Stat()** class, use [stat()](#fsstat) to create a **Stat** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name    | Type  | Readable  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| ino    | bigint | Yes   | No   | File identifier, which varies with files on the same device.|
| mode   | number | Yes   | No   | File permissions. The meaning of each bit is as follows:<br>**NOTE**<br>The following values are in octal format. The return values are in decimal format. You need to convert the values.<br>- **0o400**: The owner has the permission to read a regular file or a directory entry.<br>- **0o200**: The owner has the permission to write a regular file or create and delete a directory entry.<br>- **0o100**: The owner has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o040**: The user group has the permission to read a regular file or a directory entry.<br>- **0o020**: The user group has the permission to write a regular file or create and delete a directory entry.<br>- **0o010**: The user group has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o004**: Other users have the permission to read a regular file, and other user groups have the permission to read a directory entry.<br>- **0o002**: Other users have the permission to write a regular file, and other user groups have the permission to create or delete a directory entry.<br>- **0o001**: Other users have the permission to execute a regular file, and other user groups have the permission to search for the specified path in a directory.|
| uid    | number | Yes   | No   | ID of the file owner.|
| gid    | number | Yes   | No   | ID of the user group of the file.|
| size   | number | Yes   | No   | File size, in bytes. This parameter is valid only for regular files. |
| atime  | number | Yes   | No   | Time when the file was last accessed. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| mtime  | number | Yes   | No   | Time when the file content was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| ctime  | number | Yes   | No   | Time when the file metadata was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.     |

### isBlockDevice

isBlockDevice(): boolean

Checks whether this file is a block special file. A block special file supports access by block only, and it is cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type    | Description              |
| ------- | ---------------- |
| boolean | Whether the file is a block special file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fs.statSync(filePath).isBlockDevice();
  ```

### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this file is a character special file. A character special file supports random access, and it is not cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| boolean | Whether the file is a character special file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fs.statSync(filePath).isCharacterDevice();
  ```

### isDirectory

isDirectory(): boolean

Checks whether this file is a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Whether the file is a directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/test";
  let isDirectory = fs.statSync(dirPath).isDirectory(); 
  ```

### isFIFO

isFIFO(): boolean

Checks whether this file is a named pipe (or FIFO). Named pipes are used for inter-process communication.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Whether the file is an FIFO.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFIFO = fs.statSync(filePath).isFIFO(); 
  ```

### isFile

isFile(): boolean

Checks whether this file is a regular file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the file is a regular file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFile = fs.statSync(filePath).isFile();
  ```

### isSocket

isSocket(): boolean

Checks whether this file is a socket.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description            |
| ------- | -------------- |
| boolean | Whether the file is a socket.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSocket = fs.statSync(filePath).isSocket(); 
  ```

### isSymbolicLink

isSymbolicLink(): boolean

Checks whether this file is a symbolic link.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the file is a symbolic link.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test";
  let isSymbolicLink = fs.statSync(filePath).isSymbolicLink(); 
  ```

## Stream

Provides API for stream operations. Before calling any API of **Stream**, you need to create a **Stream** instance by using [fs.createStream](#fscreatestream) or [fs.fdopenStream](#fsfdopenstream).

### close

close(): Promise&lt;void&gt;

Closes this stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.close().then(() => {
    console.info("File stream closed");
  }).catch((err: BusinessError) => {
    console.info("close fileStream  failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### close

close(callback: AsyncCallback&lt;void&gt;): void

Closes this stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description           |
| -------- | ------------------------- | ---- | ------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked immediately after the stream is closed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.close((err: BusinessError) => {
    if (err) {
      console.info("close stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("close stream succeed");
    }
  });
  ```

### closeSync

closeSync(): void

Closes this stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.closeSync();
  ```

### flush

flush(): Promise&lt;void&gt;

Flushes this stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flush().then(() => {
    console.info("Stream flushed");
  }).catch((err: BusinessError) => {
    console.info("flush failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes this stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description            |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flush((err: BusinessError) => {
    if (err) {
      console.info("flush stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Stream flushed");
    }
  });
  ```

### flushSync

flushSync(): void

Flushes this stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flushSync();
  ```

### write

write(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data to this stream. This API uses a promise to return the data.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description      |
| --------------------- | -------- |
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  stream.write("hello, world", option).then((number: number) => {
    console.info("write succeed and size is:" + number);
  }).catch((err: BusinessError) => {
    console.info("write failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### write

write(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data to this stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| buffer   | ArrayBuffer\|string | Yes  | Data to write. It can be a string or data from a buffer.                    |
| options  | Object                          | No  | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked to return the result.                              |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  stream.write("hello, world", option, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.info("write stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      if (bytesWritten) {
        console.info("write succeed and size is:" + bytesWritten);
      }
    }
  });
  ```

### writeSync

writeSync(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): number

Writes data to this stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data written in the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath,"r+");
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  let num = stream.writeSync("hello, world", option);
  ```

### read

read(buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): Promise&lt;number&gt;

Reads data from this stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.|

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;number&gt; | Promise used to return the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  class Option {
    offset: number = 0;
    length: number = 0;
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  stream.read(arrayBuffer, option).then((readLen: number) => {
    console.info("Read data successfully");
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.log(`The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.info("read data failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### read

read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback&lt;number&gt;): void

Reads data from this stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
| options  | Object                                   | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the result.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  class Option {
    offset: number = 0;
    length: number = 0;
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  stream.read(arrayBuffer, option, (err: BusinessError, readLen: number) => {
    if (err) {
      console.info("read stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Read data successfully");
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.log(`The content of file: ${buf.toString()}`);
    }
  });
  ```

### readSync

readSync(buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number

Reads data from this stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 0;
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  let buf = new ArrayBuffer(4096);
  let num = stream.readSync(buf, option);
  ```

## File

Represents a **File** object opened by **open()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name  | Type  | Readable  | Writable  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| fd | number | Yes   | No   | FD of the file.|
| path<sup>10+</sup> | string | Yes   | No   | Path of the file.|
| name<sup>10+</sup> | string | Yes   | No   | Name of the file.|

### getParent<sup>11+</sup>

getParent(): string

Obtains the parent directory of this file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| string | Parent directory obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  console.info('The parent path is: ' + file.getParent());
  fs.closeSync(file);
  ```

### lock

lock(exclusive?: boolean): Promise\<void>

Applies an exclusive lock or a shared lock on this file in blocking mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| exclusive  | boolean | No  | Lock to apply. The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.      |

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.lock(true).then(() => {
    console.log("lock file succeed");
  }).catch((err: BusinessError) => {
    console.info("lock file failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

### lock

lock(exclusive?: boolean, callback: AsyncCallback\<void>): void

Applies an exclusive lock or a shared lock on this file in blocking mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| exclusive  | boolean | No  | Lock to apply. The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.      |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.lock(true, (err: BusinessError) => {
    if (err) {
      console.info("lock file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.log("lock file succeed");
    }
    fs.closeSync(file);
  });
  ```

### tryLock

tryLock(exclusive?: boolean): void

Applies an exclusive lock or a shared lock on this file in non-blocking mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| exclusive  | boolean | No  | Lock to apply. The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.tryLock(true);
  console.log("lock file succeed");
  fs.closeSync(file);
  ```

### unlock

unlock(): void

Unlocks this file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.tryLock(true);
  file.unlock();
  console.log("unlock file succeed");
  fs.closeSync(file);
  ```


## RandomAccessFile

Provides APIs for randomly reading and writing a stream. Before invoking any API of **RandomAccessFile**, you need to use **createRandomAccess()** to create a **RandomAccessFile** instance synchronously or asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name        | Type  | Readable | Writable | Description             |
| ----------- | ------ | ----  | ----- | ---------------- |
| fd          | number | Yes   | No   | FD of the file.|
| filePointer | number | Yes   | Yes   | Offset pointer to the **RandomAccessFile** instance.|

### setFilePointer<sup>10+</sup>

setFilePointer(): void

Sets the file offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  randomAccessFile.setFilePointer(1);
  randomAccessFile.close();
  ```


### close<sup>10+</sup>

close(): void

Closes this **RandomAccessFile** instance. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  randomAccessFile.close();
  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data to a file. This API uses a promise to return the data.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description      |
| --------------------- | -------- |
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomaccessfile.write(arrayBuffer, option).then((bytesWritten: number) => {
    console.info("randomAccessFile bytesWritten: " + bytesWritten);
  }).catch((err: BusinessError) => {
    console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    randomAccessFile.close();
    fs.closeSync(file);
  });

  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| buffer   | ArrayBuffer\|string | Yes  | Data to write. It can be a string or data from a buffer.                    |
| options  | Object                          | No  | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked to return the result.                              |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  class Option {
    offset: number = 0;
    length: number = bufferLength;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 1;
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, option, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.info("write failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      if (bytesWritten) {
        console.info("write succeed and size is:" + bytesWritten);
      }
    }
    randomAccessFile.close();
    fs.closeSync(file);
  });
  ```

### writeSync<sup>10+</sup>

writeSync(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; encoding?: string; }): number

Writes data to a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data written in the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  class Option {
    offset: number = 0;
    length: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 5;
  option.length = 5;
  let bytesWritten = randomaccessfile.writeSync("hello, world", option);
  randomAccessFile.close();
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): Promise&lt;number&gt;

Reads data from a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;number&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  class Option {
    offset: number = 0;
    length: number = bufferLength;
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomaccessfile.read(arrayBuffer, option).then((readLength: number) => {
    console.info("randomAccessFile readLength: " + readLength);
  }).catch((err: BusinessError) => {
    console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    randomAccessFile.close();
    fs.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
| options  | Object                                   | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the result.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let length: number = 20;
  class Option {
    offset: number = 0;
    length: number = length;
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  let arrayBuffer = new ArrayBuffer(length);
  randomaccessfile.read(arrayBuffer, option, (err: BusinessError, readLength: number) => {
    if (err) {
      console.info("read failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      if (readLength) {
        console.info("read succeed and size is:" + readLength);
      }
    }
    randomAccessFile.close();
    fs.closeSync(file);
  });
  ```

### readSync<sup>10+</sup>

readSync(buffer: ArrayBuffer, options?: { offset?: number; length?: number; }): number

Reads data from a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let length: number = 4096;
  let arrayBuffer = new ArrayBuffer(length);
  let readLength = randomaccessfile.readSync(arrayBuffer);
  randomAccessFile.close();
  fs.closeSync(file);
  ```


## Watcher<sup>10+</sup>

Provides APIs for observing the changes of files or folders. Before using the APIs of **Watcher** , call **createWatcher()** to create a **Watcher** object.

### start<sup>10+</sup>

start(): void

Starts listening.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fs.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

### stop<sup>10+</sup>

stop(): void

Stops listening.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fs.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

## OpenMode

Defines the constants of the **mode** parameter used in **open()**. It specifies the mode for opening a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name  | Type  | Value | Description     |
| ---- | ------ |---- | ------- |
| READ_ONLY | number |  0o0   | Open the file in read-only mode.|
| WRITE_ONLY | number | 0o1    | Open the file in write-only mode.|
| READ_WRITE | number | 0o2    | Open the file in read/write mode.|
| CREATE | number | 0o100    | Create a file if the specified file does not exist.|
| TRUNC | number | 0o1000    | If the file exists and is open in write-only or read/write mode, truncate the file length to 0.|
| APPEND | number | 0o2000   | Open the file in append mode. New data will be written to the end of the file.|
| NONBLOCK | number | 0o4000    | If **path** points to a named pipe (FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.|
| DIR | number | 0o200000    | If **path** does not point to a directory, throw an exception.|
| NOFOLLOW | number | 0o400000    | If **path** points to a symbolic link, throw an exception.|
| SYNC | number | 0o4010000    | Open the file in synchronous I/O mode.|

## Filter<sup>10+</sup>

Defines the file filtering configuration used by **listFile()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Description               |
| ----------- | --------------- | ------------------ |
| suffix | Array&lt;string&gt;     | Locate files that fully match the specified file name extensions, which are of the OR relationship.          |
| displayName    | Array&lt;string&gt;     | Locate files that fuzzy match the specified file names, which are of the OR relationship. Currently, only the wildcard * is supported.|
| mimeType    | Array&lt;string&gt; | Locate files that fully match the specified MIME types, which are of the OR relationship.      |
| fileSizeOver    | number | Locate files that are greater than or equal to the specified size.      |
| lastModifiedAfter    | number | Locate files whose last modification time is the same or later than the specified time.      |
| excludeMedia    | boolean | Whether to exclude the files already in **Media**.      |

## ConflictFiles<sup>10+</sup>

Defines conflicting file information used in **copyDir()** or **moveDir()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Description               |
| ----------- | --------------- | ------------------ |
| srcFile | string     | Path of the source file.          |
| destFile    | string     | Path of the destination file.|

## Options<sup>11+</sup>

Defines the options used in **readLines()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Description               |
| ----------- | --------------- | ------------------ |
| encoding | string     | File encoding format. It is optional.          |

## WhenceType<sup>11+</sup>

Enumerates the types of the relative offset position used in **lseek()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Value      | Description               |
| ----------- | --------------- | ------------------ |
| SEEK_SET | 0     | Beginning of the file.          |
| SEEK_CUR    | 1     | Current offset position.|
| SEEK_END    | 2     | End of the file.|
