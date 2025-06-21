# @ohos.file.fs (File Management)

The **fs** module provides APIs for file operations, including accessing and managing files and directories, obtaining file information statistics, and reading and writing data using a stream.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
```

## How to Use

Before using the APIs provided by this module to perform operations on a file or directory, obtain the application sandbox path of the file or directory as follows:

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

For details about how to obtain the sandbox path and how to use the related APIs, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).<br>A uniform resource identifier (URI) is a string pointing to a resource. For APIs that support only the sandbox path as the input parameter, you can construct a **fileUri** object and obtain the sandbox path property to convert the URI to the sandbox path, and then use the APIs. For details about the URI definition and how to convert a URI to a path, see [File URI](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md).

## fs.stat

stat(file: string | number): Promise&lt;Stat&gt;

Obtains detailed attribute information of a file or directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| file   | string \| number | Yes  | Application sandbox path or FD of the file or directory.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the file or directory information.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.stat(filePath).then((stat: fs.Stat) => {
    console.info("get file info succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.error("get file info failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.stat

stat(file: string | number, callback: AsyncCallback&lt;Stat&gt;): void

Obtains detailed attribute information of a file or directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                          |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| file     | string \| number                   | Yes  | Application sandbox path or FD of the file or directory.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the file or directory information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  fs.stat(pathDir, (err: BusinessError, stat: fs.Stat) => {
    if (err) {
      console.error("get file info failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("get file info succeed, the size of file is " + stat.size);
    }
  });
  ```

## fs.statSync

statSync(file: string | number): Stat

Obtains detailed attribute information of a file or directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| file   | string \| number | Yes  | Application sandbox path or FD of the file or directory.|

**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [Stat](#stat) | Detailed information of a file or directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let stat = fs.statSync(pathDir);
  console.info("get file info succeed, the size of file is " + stat.size);
  ```

## fs.access

access(path: string, mode?: AccessModeType): Promise&lt;boolean&gt;

Checks whether the file or directory exists or has the operation permission. This API uses a promise to return the result.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| mode<sup>12+</sup>   | [AccessModeType](#accessmodetype12) | No  | Permission on the file or directory to check. If this parameter is left blank, the system checks whether the file exists.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;boolean&gt; | Promise used to return a Boolean value. The value **true** means the file exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 13900020 | Invalid parameter value.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.access(filePath).then((res: boolean) => {
    if (res) {
      console.info("file exists");
    } else {
      console.info("file not exists");
    }
  }).catch((err: BusinessError) => {
    console.error("access failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.access

access(path: string, mode: AccessModeType, flag: AccessFlagType): Promise&lt;boolean&gt;

Checks whether the file or directory is stored locally or has the operation permission. This API uses a promise to return the result.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| mode<sup>12+</sup>   | [AccessModeType](#accessmodetype12) | Yes  | Permission on the file or directory to check.|
| flag<sup>12+</sup>  | [AccessFlagType](#accessflagtype12) | Yes| Position of the file or directory to check.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;boolean&gt; | Promise used to return a Boolean value. The value **true** means the file or directory is a local one and has the related permission. The value **false** means the file or directory does not exist or is on the cloud or a distributed device.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 13900020 | Invalid parameter value.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.access(filePath, fs.AccessModeType.EXIST, fs.AccessFlagType.LOCAL).then((res: boolean) => {
    if (res) {
      console.info("file exists");
    } else {
      console.info("file not exists");
    }
  }).catch((err: BusinessError) => {
    console.error("access failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.access

access(path: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a file or directory exists. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file or directory.                                  |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the file exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 13900020 | Invalid parameter value.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.access(filePath, (err: BusinessError, res: boolean) => {
    if (err) {
      console.error("access failed with error message: " + err.message + ", error code: " + err.code);
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

accessSync(path: string, mode?: AccessModeType): boolean

Checks whether a file or directory exists or has the operation permission. This API returns the result synchronously.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| mode<sup>12+</sup>   | [AccessModeType](#accessmodetype12) | No  | Permission on the file or directory to check. If this parameter is left blank, the system checks whether the file or directory exists.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | boolean | The value **true** means the file exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 13900020 | Invalid parameter value.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
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
    console.error("accessSync failed with error message: " + err.message + ", error code: " + err.code);
  }
  ```

## fs.accessSync

accessSync(path: string, mode: AccessModeType, flag: AccessFlagType): boolean

Checks whether a file or directory is stored locally or has the operation permission. This API returns the result synchronously.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file to check.                                  |
| mode<sup>12+</sup>   | [AccessModeType](#accessmodetype12) | Yes  | Permission on the file or directory to check.|
| flag<sup>12+</sup>  | [AccessFlagType](#accessflagtype12) | Yes  | Position of the file or directory to check.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | boolean | The value **true** means the file is a local file and has the related permission. The value **false** means the file does not exist or is on the cloud or a distributed device.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 13900020 | Invalid parameter value.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  try {
    let res = fs.accessSync(filePath, fs.AccessModeType.EXIST, fs.AccessFlagType.LOCAL);
    if (res) {
      console.info("file exists");
    } else {
      console.info("file not exists");
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error("accessSync failed with error message: " + err.message + ", error code: " + err.code);
  }
  ```

## fs.close

close(file: number | File): Promise&lt;void&gt;

Closes a file or directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | file   | number \| [File](#file) | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read or write operations.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.close(file).then(() => {
    console.info("File closed");
  }).catch((err: BusinessError) => {
    console.error("close file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.close

close(file: number | File, callback: AsyncCallback&lt;void&gt;): void

Closes a file or directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description          |
  | -------- | ------------------------- | ---- | ------------ |
  | file       | number \| [File](#file)        | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read or write operations.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.close(file, (err: BusinessError) => {
    if (err) {
      console.error("close file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File closed");
    }
  });
  ```

## fs.closeSync

closeSync(file: number | File): void

Closes a file or directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | file   | number \| [File](#file) | Yes   | **File** object or FD of the file to close. Once closed, the **File** object or FD cannot be used for read or write operations.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.closeSync(file);
  ```

## fs.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options?: CopyOptions): Promise\<void>

Copies a file or directory. This API uses a promise to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | srcUri  | string | Yes   | URI of the file or directory to copy.                     |
  | destUri | string | Yes   | URI of the destination file or directory.                         |
  | options | [CopyOptions](#copyoptions11)| No| Callback invoked to provide the copy progress. If this parameter is not set, the callback will not be invoked.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
};
let copyoption: fs.CopyOptions = {
  "progressListener" : progressListener
}
try {
  fs.copy(srcDirUriLocal, dstDirUriLocal, copyoption).then(()=>{
    console.info("Succeeded in copying. ");
  }).catch((err: BusinessError)=>{
    console.error(`Failed to copy: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to copy: ${JSON.stringify(err)}`);
}
```

## fs.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, callback: AsyncCallback\<void>): void

Copies a file or directory. This API uses an asynchronous callback to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type   | Mandatory  | Description         |
  | ---- | ------------------ | ---- | ----------------------------|
  | srcUri  | string | Yes   | URI of the file or directory to copy.                     |
  | destUri | string | Yes   | URI of the destination file or directory.                         |
  | callback | AsyncCallback\<void>| Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  fs.copy(srcDirUriLocal, dstDirUriLocal, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy: ${JSON.stringify(err)}`);
      return;
    }
    console.info("Succeeded in copying. ");
  })
} catch(err) {
  console.error(`Failed to copy: ${JSON.stringify(err)}`);
}
```

## fs.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options: CopyOptions, callback: AsyncCallback\<void>): void

Copies a file or directory. This API uses an asynchronous callback to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | srcUri  | string | Yes   | URI of the file or directory to copy.                     |
  | destUri | string | Yes   | URI of the destination file or directory.                         |
  | options | [CopyOptions](#copyoptions11) |Yes| Callback used to return the copy progress.                         |
  | callback | AsyncCallback\<void>| Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
    console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyoption: fs.CopyOptions = {
    "progressListener" : progressListener
  }
  fs.copy(srcDirUriLocal, dstDirUriLocal, copyoption, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy: ${JSON.stringify(err)}`);
      return;
    }
    console.info("Succeeded in copying. ");
  })
} catch(err) {
  console.error(`Failed to copy: ${JSON.stringify(err)}`);
}
```

## fs.copyFile

copyFile(src: string | number, dest: string | number, mode?: number): Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string \| number | Yes   | Path or FD of the file to copy.                     |
  | dest | string \| number | Yes   | Destination path of the file or FD of the file created.                         |
  | mode | number                     | No   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, 0).then(() => {
    console.info("copy file succeed");
  }).catch((err: BusinessError) => {
    console.error("copy file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file with the specified mode. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                        | Mandatory  | Description                                      |
  | -------- | -------------------------- | ---- | ---------------------------------------- |
  | src      | string \| number | Yes   | Path or FD of the file to copy.                     |
  | dest     | string \| number | Yes   | Destination path of the file or FD of the file created.                         |
  | mode     | number                     | Yes   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|
  | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked immediately after the file is copied.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, 0, (err: BusinessError) => {
    if (err) {
      console.error("copy file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy file succeed");
    }
  });
  ```

## fs.copyFile

copyFile(src: string | number, dest: string | number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API overwrites the file with the same name in the destination directory and truncates the part that is not overwritten. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                        | Mandatory  | Description                                      |
  | -------- | -------------------------- | ---- | ---------------------------------------- |
  | src      | string \| number | Yes   | Path or FD of the file to copy.                     |
  | dest     | string \| number | Yes   | Destination path of the file or FD of the file created.                         |
  | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked immediately after the file is copied.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFile(srcPath, dstPath, (err: BusinessError) => {
    if (err) {
      console.error("copy file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy file succeed");
    }
  });
  ```


## fs.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

Copies a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string \| number | Yes   | Path or FD of the file to copy.                     |
  | dest | string \| number | Yes   | Destination path of the file or FD of the file created.                         |
  | mode | number                     | No   | Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: overwrite the file with the same name and truncate the part that is not overwritten.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fs.copyFileSync(srcPath, dstPath);
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode?: number): Promise\<void>

Copies the source directory to the destination path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | No   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, 0).then(() => {
    console.info("copy directory succeed");
  }).catch((err: BusinessError) => {
    console.error("copy directory failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies the source directory to the destination path. You can set the copy mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | Yes   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|
  | callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ConflictFiles } from '@kit.CoreFileKit';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, 0, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error("copy directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.error("copy directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy directory succeed");
    }
  });
  ```

## fs.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies the source directory to the destination path. This API uses an asynchronous callback to return the result.

An exception will be thrown if the destination directory contains a directory with the same name as the source directory and there are files with the same name in the conflicting directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ConflictFiles } from '@kit.CoreFileKit';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.copyDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error("copy directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.error("copy directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("copy directory succeed");
    }
  });
  ```

## fs.copyDirSync<sup>10+</sup>

copyDirSync(src: string, dest: string, mode?: number): void

Copies the source directory to the destination path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | No   | Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  try {
    fs.copyDirSync(srcPath, destPath, 0);
    console.info("copy directory succeed");
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error("copy directory failed with error message: " + err.message + ", error code: " + err.code);
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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

## fs.connectDfs<sup>12+</sup>

connectDfs(networkId: string, listeners: DfsListeners): Promise&lt;void&gt;

Triggers connection. If the peer device is abnormal, [onStatus](#onstatus12) in **DfsListeners** will be called to notify the application.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | networkId   | string | Yes   | Network ID of the device. The device network ID can be obtained from [deviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo) using the related [distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md) API.                            |
  | listeners | [DfsListeners](#fsdfslisteners12) | Yes   | Listeners for distributed file system status.               |

**Return value**

  | Type    | Description                                      |
  | ------ | ---------------------------------------- |
  | Promise&lt;void&gt;| Promise that returns no value.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs } from '@kit.CoreFileKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Success to get available device list`);
    let networkId = deviceInfoList[0].networkId;
    let listeners: fs.DfsListeners = {
      onStatus(networkId, status) {
        console.info('onStatus');
      }
    };
    fs.connectDfs(networkId, listeners).then(() => {
      console.info("Success to connectDfs");
    }).catch((err: BusinessError) => {
      console.error(`Failed to connectDfs. Code: ${err.code}, message: ${err.message}`);
    });
  }
  ```

## fs.disconnectDfs<sup>12+</sup>

disconnectDfs(networkId: string): Promise&lt;void&gt;

Triggers disconnection.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | networkId   | string | Yes   | Network ID of the device. The device network ID can be obtained from [deviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo) using the related [distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md) API.                           |

**Return value**

  | Type    | Description                                      |
  | ------ | ---------------------------------------- |
  | Promise&lt;void&gt;| Promise that returns no value.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs } from '@kit.CoreFileKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Success to get available device list`);
    let networkId = deviceInfoList[0].networkId;
    fs.disconnectDfs(networkId).then(() => {
      console.info("Success to disconnect dfs");
    }).catch((err: BusinessError) => {
      console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
    })
  }
  ```

## fs.setxattr<sup>12+</sup>

setxattr(path: string, key: string, value: string): Promise&lt;void&gt;

Sets an extended attribute of a file or directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| key   | string | Yes  | Key of the extended attribute to obtain. The value is a string of less than 256 bytes and can contain only the **user.** prefix. |
| value   | string | Yes  | Value of the extended attribute to set.                                  |

**Return value**

  | Type    | Description                                      |
  | ------ | ---------------------------------------- |
  | Promise&lt;void&gt;| Promise that returns no value.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  fs.setxattr(filePath, attrKey, attrValue).then(() => {
    console.info("Set extended attribute successfully.");
  }).catch((err: BusinessError) => {
    console.error("Failed to set extended attribute with error message: " + err.message + ", error code: " + err.code);
  });

  ```
## fs.setxattrSync<sup>12+</sup>

setxattrSync(path: string, key: string, value: string): void

Sets an extended attribute of a file or directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| key   | string | Yes  | Key of the extended attribute to obtain. The value is a string of less than 256 bytes and can contain only the **user.** prefix.  |
| value   | string | Yes  | Value of the extended attribute to set.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  try {
    fs.setxattrSync(filePath, attrKey, attrValue);
    console.info("Set extended attribute successfully.");
  } catch (err) {
    console.error("Failed to set extended attribute with error message: " + err.message + ", error code: " + err.code);
  }

  ```

## fs.getxattr<sup>12+</sup>

getxattr(path: string, key: string): Promise&lt;string&gt;

Obtains an extended attribute of a file or directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| key   | string | Yes  | Key of the extended attribute to obtain.                                  |

**Return value**

  | Type    | Description                                      |
  | ------ | ---------------------------------------- |
  | Promise&lt;string&gt;| Promise used to return the value of the extended attribute obtained.   |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  fs.getxattr(filePath, attrKey).then((attrValue: string) => {
    console.info("Get extended attribute succeed, the value is: " + attrValue);
  }).catch((err: BusinessError) => {
    console.error("Failed to get extended attribute with error message: " + err.message + ", error code: " + err.code);
  });

  ```

## fs.getxattrSync<sup>12+</sup>

getxattrSync(path: string, key: string): string

Obtains an extended attribute of a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file or directory.                                  |
| key   | string | Yes  | Key of the extended attribute to obtain.                                  |

**Return value**

  | Type    | Description                                      |
  | ------ | ---------------------------------------- |
  | key| Value of the extended attribute obtained.     |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  try {
    let attrValue = fs.getxattrSync(filePath, attrKey);
    console.info("Get extended attribute succeed, the value is: " + attrValue);
  } catch (err) {
    console.error("Failed to get extended attribute with error message: " + err.message + ", error code: " + err.code);
    }

  ```

## fs.mkdir

mkdir(path: string): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir";
  fs.mkdir(dirPath).then(() => {
    console.info("Directory created");
  }).catch((err: BusinessError) => {
    console.error("mkdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean): Promise\<void>

Creates a directory. This API uses a promise to return the result. The value **true** means to create a directory recursively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a directory recursively.<br>The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.  |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdir(dirPath, true).then(() => {
    console.info("Directory created");
  }).catch((err: BusinessError) => {
    console.error("mkdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdir

mkdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir";
  fs.mkdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error("mkdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory created");
    }
  });
  ```

## fs.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result. The value **true** means to create a directory recursively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a directory recursively.<br>The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdir(dirPath, true, (err: BusinessError) => {
    if (err) {
      console.error("mkdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory created");
    }
  });
  ```

## fs.mkdirSync

mkdirSync(path: string): void

Creates a directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fs.mkdirSync(dirPath);
  ```

## fs.mkdirSync<sup>11+</sup>

mkdirSync(path: string, recursion: boolean): void

Creates a directory. This API returns the result synchronously. The value **true** means to create a directory recursively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| recursion   | boolean | Yes  | Whether to create a directory recursively.<br>The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fs.mkdirSync(dirPath, true);
  ```

## fs.open

open(path: string, mode?: number): Promise&lt;File&gt;

Opens a file or directory. This API uses a promise to return the result. This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path or URI of the file or directory.                                  |
| mode  | number | No  | [Mode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can add the following function options in bitwise OR mode. By default, no additional option is added.  <br>- **OpenMode.CREATE(0o100)**: Create a file if the file does not exist.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|

**Return value**

  | Type                   | Description         |
  | --------------------- | ----------- |
  | Promise&lt;[File](#file)&gt; | Promise used to return the **File** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE).then((file: fs.File) => {
    console.info("file fd: " + file.fd);
    fs.closeSync(file);
  }).catch((err: BusinessError) => {
    console.error("open file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```


## fs.open

open(path: string, mode: number, callback: AsyncCallback&lt;File&gt;): void

Opens a file or directory with the specified mode. This API uses an asynchronous callback to return the result.

This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path or URI of a file or directory.                                  |
| mode  | number | Yes  | [Mode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|
| callback     | AsyncCallback&lt;void&gt;                          | Yes  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE, (err: BusinessError, file: fs.File) => {
    if (err) {
      console.error("open failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("file fd: " + file.fd);
      fs.closeSync(file);
    }
  });
  ```

## fs.open

open(path: string, callback: AsyncCallback&lt;File&gt;): void

Opens a file or directory. This API uses an asynchronous callback to return the result. This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path or URI of a file or directory.                                  |
| callback     | AsyncCallback&lt;void&gt;                          | Yes  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.open(filePath, (err: BusinessError, file: fs.File) => {
    if (err) {
      console.error("open failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("file fd: " + file.fd);
      fs.closeSync(file);
    }
  });
  ```

## fs.openSync

openSync(path: string, mode?: number): File

Opens a file or directory. This API returns the result synchronously. This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path or URI of a file or directory to open.                                  |
| mode  | number | No  | [Mode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|

**Return value**

  | Type    | Description         |
  | ------ | ----------- |
  | [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  console.info("file fd: " + file.fd);
  fs.closeSync(file);
  ```

## fs.read

read(fd: number, buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

Reads file data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type       | Mandatory| Description                                                        |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | Yes  | FD of the file.                                    |
| buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
| options | [ReadOptions](#readoptions11)      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;number&gt; | Promise used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fs.read(file.fd, arrayBuffer).then((readLen: number) => {
    console.info("Read file data successfully");
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.error("read file data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.read

read(fd: number, buffer: ArrayBuffer, options?: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | Yes   | FD of the file.                            |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
  | options | [ReadOptions](#readoptions11)      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|
  | callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the length of the data read, in bytes.                            |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fs.read(file.fd, arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error("read failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Read file data successfully");
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`The content of file: ${buf.toString()}`);
    }
    fs.closeSync(file);
  });
  ```

## fs.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: ReadOptions): number

Reads data from a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | fd      | number      | Yes   | FD of the file.                            |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file data read.                       |
  | options | [ReadOptions](#readoptions11)      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.|

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

Removes a directory. This API uses a promise to return the result.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlink()** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir";
  fs.rmdir(dirPath).then(() => {
    console.info("Directory removed");
  }).catch((err: BusinessError) => {
    console.error("rmdir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.rmdir

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Removes a directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlink()** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let dirPath = pathDir + "/testDir";
  fs.rmdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error("rmdir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Directory removed");
    }
  });
  ```

## fs.rmdirSync

rmdirSync(path: string): void

Removes a directory. This API returns the result synchronously.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlink()** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fs.rmdirSync(dirPath);
  ```

## fs.unlink

unlink(path: string): Promise&lt;void&gt;

Removes a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.unlink(filePath).then(() => {
    console.info("File removed");
  }).catch((err: BusinessError) => {
    console.error("remove file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

Removes a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked immediately after the file is removed.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.unlink(filePath, (err: BusinessError) => {
    if (err) {
      console.error("remove file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File removed");
    }
  });
  ```

## fs.unlinkSync

unlinkSync(path: string): void

Removes a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fs.unlinkSync(filePath);
  ```


## fs.write

write(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data to a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | FD of the file.                            |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let str: string = "hello, world";
  fs.write(file.fd, str).then((writeLen: number) => {
    console.info("write data to file succeed and size is:" + writeLen);
  }).catch((err: BusinessError) => {
    console.error("write data to file failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.write

write(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                             | Mandatory  | Description                                      |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | Yes   | FD of the file.                            |
  | buffer   | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|
  | callback | AsyncCallback&lt;number&gt;     | Yes   | Callback used to return the result.                      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let str: string = "hello, world";
  fs.write(file.fd, str, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.error("write data to file failed with error message:" + err.message + ", error code: " + err.code);
    } else {
      console.info("write data to file succeed and size is:" + writeLen);
    }
    fs.closeSync(file);
  });
  ```

## fs.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | FD of the file.                            |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| file   | string \| number | Yes  | Application sandbox path or FD of the file.      |
| len    | number | No  | File length, in bytes, after truncation. The default value is **0**.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncate(filePath, len).then(() => {
    console.info("File truncated");
  }).catch((err: BusinessError) => {
    console.error("truncate file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.truncate

truncate(file: string | number, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| file     | string \| number                    | Yes  | Application sandbox path or FD of the file.      |
| len      | number                    | No  | File length, in bytes, after truncation. The default value is **0**.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncate(filePath, len, (err: BusinessError) => {
    if (err) {
      console.error("truncate failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("truncate succeed");
    }
  });
  ```

## fs.truncateSync

truncateSync(file: string | number, len?: number): void

Truncates the file content. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| file   | string \| number | Yes  | Application sandbox path or FD of the file.      |
| len    | number | No  | File length, in bytes, after truncation. The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fs.truncateSync(filePath, len);
  ```

## fs.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options): Promise&lt;ReaderIterator&gt;

Reads the text content of a file line by line. This API uses a promise to return the result. Only the files in UTF-8 format are supported.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options | [Options](#options11) | No  | Options for reading the text. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description        |
  | --------------------- | ---------- |
  | Promise&lt;[ReaderIterator](#readeriterator11)&gt; | Promise used to return a **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, Options } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options).then((readerIterator: fs.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info("content: " + it.value);
    }
  }).catch((err: BusinessError) => {
    console.error("readLines failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options, callback: AsyncCallback&lt;ReaderIterator&gt;): void

Reads a file text line by line. This API uses an asynchronous callback to return the result. Only the files in UTF-8 format are supported.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options | [Options](#options11) | No  | Options for reading the text. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | Yes  | Callback used to return a **ReaderIterator** object.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, Options } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options, (err: BusinessError, readerIterator: fs.ReaderIterator) => {
    if (err) {
      console.error("readLines failed with error message: " + err.message + ", error code: " + err.code);
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
| options | [Options](#options11) | No  | Options for reading the text. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description        |
  | --------------------- | ---------- |
  | [ReaderIterator](#readeriterator11) | **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, Options } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  let readerIterator = fs.readLinesSync(filePath, options);
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
  | [ReaderIteratorResult](#readeriteratorresult) | **ReaderIteratorResult** object obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

> **NOTE**
>
> If the line read by ReaderIterator is not in UTF-8 format, error code 13900037 will be returned.

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, Options } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fs.readLines(filePath, options).then((readerIterator: fs.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info("content: " + it.value);
    }
  }).catch((err: BusinessError) => {
    console.error("readLines failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## ReaderIteratorResult

Represents the information obtained by the **ReaderIterator** object.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Description               |
| ----------- | --------------- | ------------------ |
| done | boolean     |  Whether the iteration is complete. The value **true** means the iteration is complete; the value **false** means the opposite.         |
| value    | string     | File text content read line by line.|

## fs.readText

readText(filePath: string, options?: ReadTextOptions): Promise&lt;string&gt;

Reads the text content of a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options  | [ReadTextOptions](#readtextoptions11) | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the file content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.readText(filePath).then((str: string) => {
    console.info("readText succeed:" + str);
  }).catch((err: BusinessError) => {
    console.error("readText failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.readText

readText(filePath: string, options?: ReadTextOptions, callback: AsyncCallback&lt;string&gt;): void

Reads the text content of a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | Yes  | Application sandbox path of the file.                                  |
| options  | [ReadTextOptions](#readtextoptions11)                      | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the content read.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ReadTextOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let readTextOption: ReadTextOptions = {
      offset: 1,
      length: 0,
      encoding: 'utf-8'
  };
  let stat = fs.statSync(filePath);
  readTextOption.length = stat.size;
  fs.readText(filePath, readTextOption, (err: BusinessError, str: string) => {
    if (err) {
      console.error("readText failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("readText succeed:" + str);
    }
  });
  ```

## fs.readTextSync

readTextSync(filePath: string, options?: ReadTextOptions): string

Reads the text content of a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file.                                  |
| options  | [ReadTextOptions](#readtextoptions11) | No  | The options are as follows:<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type  | Description                |
  | ------ | -------------------- |
  | string | Content of the file read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, ReadTextOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let readTextOptions: ReadTextOptions = {
    offset: 1,
    length: 0,
    encoding: 'utf-8'
  };
  let stat = fs.statSync(filePath);
  readTextOptions.length = stat.size;
  let str = fs.readTextSync(filePath, readTextOptions);
  console.info("readText succeed:" + str);
  ```

## fs.lstat

lstat(path: string): Promise&lt;Stat&gt;

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the symbolic link information obtained. For details, see **Stat**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/linkToFile";
  fs.lstat(filePath).then((stat: fs.Stat) => {
    console.info("lstat succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.error("lstat failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.lstat

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                                  |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the symbolic link information obtained.      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/linkToFile";
  fs.lstat(filePath, (err: BusinessError, stat: fs.Stat) => {
    if (err) {
      console.error("lstat failed with error message: " + err.message + ", error code: " + err.code);
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
| path   | string | Yes  | Application sandbox path of the file.|

**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [Stat](#stat) | File information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/linkToFile";
  let fileStat = fs.lstatSync(filePath);
  console.info("lstat succeed, the size of file is" + fileStat.size);
  ```

## fs.rename

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file or directory. This API uses a promise to return the result.

> **NOTE**
> 
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or directory to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or directory.  |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.rename(srcFile, dstFile).then(() => {
    console.info("File renamed");
  }).catch((err: BusinessError) => {
    console.error("rename failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.rename

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

Renames a file or directory. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                        |
| -------- | ------------------------- | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or directory to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or directory.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.rename(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error("rename failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("File renamed");
    }
  });
  ```

## fs.renameSync

renameSync(oldPath: string, newPath: string): void

Renames a file or directory. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file or directory to rename.|
| newPath | string | Yes  | Application sandbox path of the renamed file or directory.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fs.renameSync(srcFile, dstFile);
  ```

## fs.fsync

fsync(fd: number): Promise&lt;void&gt;

Synchronizes the cached data of a file to storage. This API uses a promise to return the result.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsync(file.fd).then(() => {
    console.info("Data flushed");
  }).catch((err: BusinessError) => {
    console.error("sync data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.fsync

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes the cached data of a file to storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description             |
  | -------- | ------------------------- | ---- | --------------- |
  | fd       | number                    | Yes   | FD of the file.   |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsync(file.fd, (err: BusinessError) => {
    if (err) {
      console.error("fsync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("fsync succeed");
    }
    fs.closeSync(file);
  });
  ```


## fs.fsyncSync

fsyncSync(fd: number): void

Synchronizes the cached data of a file to storage. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fsyncSync(file.fd);
  fs.closeSync(file);
  ```

## fs.fdatasync

fdatasync(fd: number): Promise&lt;void&gt;

Synchronizes the data of a file. This API uses a promise to return the result.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdatasync(file.fd).then(() => {
    console.info("Data flushed");
  }).catch((err: BusinessError) => {
    console.error("sync data failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.fdatasync

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes the data of a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                             | Mandatory  | Description               |
  | -------- | ------------------------------- | ---- | ----------------- |
  | fd       | number                          | Yes   | FD of the file.     |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdatasync (file.fd, (err: BusinessError) => {
    if (err) {
      console.error("fdatasync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("fdatasync succeed");
    }
    fs.closeSync(file);
  });
  ```

## fs.fdatasyncSync

fdatasyncSync(fd: number): void

Synchronizes the data of a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlink(srcFile, dstFile).then(() => {
    console.info("Symbolic link created");
  }).catch((err: BusinessError) => {
    console.error("symlink failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```


## fs.symlink
symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | Yes  | Application sandbox path of the target file.        |
| srcPath  | string                    | Yes  | Application sandbox path of the symbolic link.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlink(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error("symlink failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Symbolic link created");
    }
  });
  ```

## fs.symlinkSync

symlinkSync(target: string, srcPath: string): void

Creates a symbolic link based on the file path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fs.symlinkSync(srcFile, dstFile);
  ```

## fs.listFile
listFile(path: string, options?: ListFileOptions): Promise<string[]>

Lists the names of all files and directories in the current path. Filtering is supported. This API uses a promise to return the result.

You can configure the **recursion** parameter in **options** to recursively list the relative paths of all files. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | path | string | Yes   | Application sandbox path of the directory.|
  | options | [ListFileOptions](#listfileoptions11) | No   | Options for filtering files. The files are not filtered by default.|


**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string[]&gt; | Promise used to return the file names listed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, Filter, ListFileOptions } from '@kit.CoreFileKit';
  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  }
  fs.listFile(pathDir, listFileOption).then((filenames: Array<string>) => {
    console.info("listFile succeed");
    for (let i = 0; i < filenames.length; i++) {
      console.info("fileName: %s", filenames[i]);
    }
  }).catch((err: BusinessError) => {
    console.error("list file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.listFile
listFile(path: string, options?: ListFileOptions, callback: AsyncCallback<string[]>): void

Lists the names of all files and directories in the current path. Filtering is supported. This API uses an asynchronous callback to return the result.

You can configure the **recursion** parameter in **options** to recursively list the relative paths of all files. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | path | string | Yes   | Application sandbox path of the directory.|
  | options | [ListFileOptions](#listfileoptions11) | No   | Options for filtering files. The files are not filtered by default.|
  | callback | AsyncCallback&lt;string[]&gt; | Yes   | Callback used to return the file names listed.             |


**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, Filter, ListFileOptions } from '@kit.CoreFileKit';
  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  fs.listFile(pathDir, listFileOption, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.error("list file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("listFile succeed");
      for (let i = 0; i < filenames.length; i++) {
        console.info("filename: %s", filenames[i]);
      }
    }
  });
  ```

## fs.listFileSync

listFileSync(path: string, options?: ListFileOptions): string[]

Lists the names of all files and directories in the current directory. This API returns the result synchronously. Filtering is supported.

You can configure the **recursion** parameter in **options** to recursively list the relative paths of all files. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | path | string | Yes   | Application sandbox path of the directory.|
  | options | [ListFileOptions](#listfileoptions11) | No   | Options for filtering files. The files are not filtered by default.|


**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | string[] | File names obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, Filter, ListFileOptions} from '@kit.CoreFileKit';
  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  let filenames = fs.listFileSync(pathDir, listFileOption);
  console.info("listFile succeed");
  for (let i = 0; i < filenames.length; i++) {
    console.info("filename: %s", filenames[i]);
  }
  ```

## fs.lseek<sup>11+</sup>

lseek(fd: number, offset: number, whence?: WhenceType): number

Adjusts the position of the file offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | fd | number | Yes   | FD of the file.|
  | offset | number | Yes   | Relative offset, in bytes.|
  | whence | [WhenceType](#whencetype11) | No   | Where to start the offset. If this parameter is not specified, the file start position is used by default.|

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | number | Position of the current offset as measured from the beginning of the file, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  console.info('The current offset is at ' + fs.lseek(file.fd, 5, fs.WhenceType.SEEK_SET));
  fs.closeSync(file);
  ```

## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode?: number): Promise\<void>

Moves the source directory to the destination directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | No   | Move mode. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a non-empty directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, 1).then(() => {
    console.info("move directory succeed");
  }).catch((err: BusinessError) => {
    console.error("move directory failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves the source directory to the destination directory. You can set the move mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | Yes   | Move mode. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|
  | callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ConflictFiles } from '@kit.CoreFileKit';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, 1, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error("move directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.error("move directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move directory succeed");
    }
  });
  ```

  ## fs.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves the source directory to the destination directory. This API uses an asynchronous callback to return the result.

An exception will be thrown if a directory conflict occurs, that is, the destination directory contains a directory with the same name as the source directory.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ConflictFiles } from '@kit.CoreFileKit';
  // move directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fs.moveDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error("move directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
      }
    } else if (err) {
      console.error("move directory failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move directory succeed");
    }
  });
  ```

## fs.moveDirSync<sup>10+</sup>

moveDirSync(src: string, dest: string, mode?: number): void

Moves the source directory to the destination directory. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the source directory.|
  | dest | string | Yes   | Application sandbox path of the destination directory.|
  | mode | number | No   | Move mode. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs, ConflictFiles } from '@kit.CoreFileKit';
// move directory from srcPath to destPath
let srcPath = pathDir + "/srcDir/";
let destPath = pathDir + "/destDir/";
try {
  fs.moveDirSync(srcPath, destPath, 1);
  console.info("move directory succeed");
} catch (error) {
  let err: BusinessError<Array<ConflictFiles>> = error as BusinessError<Array<ConflictFiles>>;
  if (err.code == 13900015 && err.data?.length !== undefined) {
    for (let i = 0; i < err.data.length; i++) {
      console.error("move directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);
    }
  } else {
    console.error("move directory failed with error message: " + err.message + ", error code: " + err.code);
  }
}
  ```

## fs.moveFile

moveFile(src: string, dest: string, mode?: number): Promise\<void>

Moves a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the file to move.|
  | dest | string | Yes   | Application sandbox path of the destination file.|
  | mode | number | No   | Move mode.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, 0).then(() => {
    console.info("move file succeed");
  }).catch((err: BusinessError) => {
    console.error("move file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.moveFile

moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

Moves a file with the specified mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the file to move.|
  | dest | string | Yes   | Application sandbox path of the destination file.|
  | mode | number | Yes   | Move mode.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, 0, (err: BusinessError) => {
    if (err) {
      console.error("move file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move file succeed");
    }
  });
  ```

## fs.moveFile

moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void

Moves a file and forcibly overwrites the file with the same name in the destination directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the file to move.|
  | dest | string | Yes   | Application sandbox path of the destination file.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFile(srcPath, destPath, (err: BusinessError) => {
    if (err) {
      console.error("move file failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("move file succeed");
    }
  });
  ```

## fs.moveFileSync

moveFileSync(src: string, dest: string, mode?: number): void

Moves a file. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | src | string | Yes   | Application sandbox path of the file to move.|
  | dest | string | Yes   | Application sandbox path of the destination file.|
  | mode | number | No   | Move mode.<br>The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fs.moveFileSync(srcPath, destPath, 0);
  console.info("move file succeed");
  ```

## fs.mkdtemp

mkdtemp(prefix: string): Promise&lt;string&gt;

Creates a temporary directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the directory created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  fs.mkdtemp(pathDir + "/XXXXXX").then((dir: string) => {
    console.info("mkdtemp succeed:" + dir);
  }).catch((err: BusinessError) => {
    console.error("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## fs.mkdtemp

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

Creates a temporary directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                         | Mandatory  | Description                         |
  | -------- | --------------------------- | ---- | --------------------------- |
  | prefix   | string                      | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|
  | callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  fs.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {
    if (err) {
      console.error("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("mkdtemp succeed");
    }
  });
  ```

## fs.mkdtempSync

mkdtempSync(prefix: string): string

Creates a temporary directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

  | Type   | Description        |
  | ------ | ---------- |
  | string | Unique directory generated.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

Creates a **RandomAccessFile** instance based on the specified file path or file object. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
|    Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|

**Return value**

  | Type                               | Description       |
  | --------------------------------- | --------- |
  | Promise&lt;[RandomAccessFile](#randomaccessfile)&gt; | Promise used to return the **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file).then((randomAccessFile: fs.RandomAccessFile) => {
    console.info("randomAccessFile fd: " + randomAccessFile.fd);
    randomAccessFile.close();
  }).catch((err: BusinessError) => {
    console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

## fs.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

Creates a **RandomAccessFile** object in read-only mode based on a file path or file object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile)&gt; | Yes  | Callback used to return the **RandomAccessFile** instance created.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file, (err: BusinessError, randomAccessFile: fs.RandomAccessFile) => {
    if (err) {
      console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
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
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | Yes  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile)&gt; | Yes  | Callback used to return the **RandomAccessFile** instance created.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  fs.createRandomAccessFile(file, fs.OpenMode.READ_ONLY, (err: BusinessError, randomAccessFile: fs.RandomAccessFile) => {
    if (err) {
      console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("randomAccessFile fd: " + randomAccessFile.fd);
      randomAccessFile.close();
    }
    fs.closeSync(file);
  });
  ```

## fs.createRandomAccessFile<sup>12+</sup>

createRandomAccessFile(file: string | File, mode?: number, options?: RandomAccessFileOptions): Promise&lt;RandomAccessFile&gt;

Creates a **RandomAccessFile** instance based on the specified file path or file object. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
|options|[RandomAccessFileOptions](#randomaccessfileoptions12)|No|The options are as follows:<br>- **start** (number): start position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **end** (number): end position of the data to read in the file. This parameter is optional. The default value is the end of the file.|

**Return value**

  | Type                               | Description       |
  | --------------------------------- | --------- |
  | Promise&lt;[RandomAccessFile](#randomaccessfile)&gt; | Promise used to return the **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let filePath = pathDir + "/test.txt";
fs.createRandomAccessFile(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE, { start: 10, end: 100 })
  .then((randomAccessFile: fs.RandomAccessFile) => {
    console.info("randomAccessFile fd: " + randomAccessFile.fd);
    randomAccessFile.close();
  })
  .catch((err: BusinessError) => {
    console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  });
```


## fs.createRandomAccessFileSync<sup>10+</sup>

createRandomAccessFileSync(file: string | File, mode?: number): RandomAccessFile

Creates a **RandomAccessFile** instance based on a file path or file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [RandomAccessFile](#randomaccessfile) | **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  randomAccessFile.close();
  ```

## fs.createRandomAccessFileSync<sup>12+</sup>

createRandomAccessFileSync(file: string | File, mode?: number,
  options?: RandomAccessFileOptions): RandomAccessFile

Creates a **RandomAccessFile** instance based on a file path or file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

|  Name   | Type    | Mandatory  | Description                         |
| ------------ | ------ | ------ | ------------------------------------------------------------ |
|     file     | string \| [File](#file) | Yes   | Application sandbox path of the file or an opened file object.|
|     mode     | number | No  | [Mode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the created file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
|options|[RandomAccessFileOptions](#randomaccessfileoptions12)|No|The options are as follows:<br>- **start** (number): start position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **end** (number): end position of the data to read in the file. This parameter is optional. The default value is the end of the file.|

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [RandomAccessFile](#randomaccessfile) | **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE,
    { start: 10, end: 100 });
  randomAccessFile.close();
  ```

## fs.createStream

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Creates a stream based on a file path. This API uses a promise to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.createStream(filePath, "a+").then((stream: fs.Stream) => {
    stream.closeSync();
    console.info("Stream created");
  }).catch((err: BusinessError) => {
    console.error("createStream failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```


## fs.createStream

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Creates a stream based on a file path. This API uses an asynchronous callback to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | Yes  | Application sandbox path of the file.                                  |
| mode     | string                                  | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  fs.createStream(filePath, "r+", (err: BusinessError, stream: fs.Stream) => {
    if (err) {
      console.error("create stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Stream created");
    }
    stream.closeSync();
  })
  ```

## fs.createStreamSync

createStreamSync(path: string, mode: string): Stream

Creates a stream based on a file path. This API returns the result synchronously. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  console.info("Stream created");
  stream.closeSync();
  ```


## fs.fdopenStream

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a stream based on an FD. This API uses a promise to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath);
  fs.fdopenStream(file.fd, "r+").then((stream: fs.Stream) => {
    console.info("Stream opened");
    stream.closeSync();
  }).catch((err: BusinessError) => {
    console.error("openStream failed with error message: " + err.message + ", error code: " + err.code);
    // If the file stream fails to be opened, the FD must be manually closed.
    fs.closeSync(file);
  });
  ```

> **NOTE**
>
> When a file stream created with an FD is used, the lifecycle of the FD will be managed by the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fs.fdopenStream

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a stream based on an FD. This API uses an asynchronous callback to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | Yes   | FD of the file.                            |
  | mode     | string                                   | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
  | callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes   | Callback used to return the result.                           |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.fdopenStream(file.fd, "r+", (err: BusinessError, stream: fs.Stream) => {
    if (err) {
      console.error("fdopen stream failed with error message: " + err.message + ", error code: " + err.code);
      stream.closeSync();
    } else {
      console.info("fdopen stream succeed");
      // If the file stream fails to be opened, the FD must be manually closed.
      fs.closeSync(file);
    }
  });
  ```

> **NOTE**
>
> If a file stream is created with an FD, the lifecycle of the FD is also transferred to the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fs.fdopenStreamSync

fdopenStreamSync(fd: number, mode: string): Stream

Opens a stream based on an FD. This API returns the result synchronously. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY | fs.OpenMode.CREATE);
  let stream = fs.fdopenStreamSync(file.fd, "r+");
  stream.closeSync();
  ```

> **NOTE**
>
> If a file stream is created with an FD, the lifecycle of the FD is also transferred to the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fs.createReadStream<sup>12+</sup>

createReadStream(path: string, options?: ReadStreamOptions ): ReadStream

Creates a readable stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | path   | string | Yes   | Path of the file.                            |
  | options | [ReadStreamOptions](#readstreamoptions12) | No   | The options are as follows:<br>- **start** (number): start position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **end** (number): end position of the data to read in the file. This parameter is optional. The default value is the end of the file.|

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
 // Create a readable stream.
  const rs = fs.createReadStream(`${pathDir}/read.txt`);
  // Create a writeable stream.
  const ws = fs.createWriteStream(`${pathDir}/write.txt`);
  // Copy files in paused mode.
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
  ```

## fs.createWriteStream<sup>12+</sup>

createWriteStream(path: string, options?: WriteStreamOptions): WriteStream

Creates a writeable stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | path   | string | Yes   | Path of the file.                            |
  | options | [WriteStreamOptions](#writestreamoptions12) | No   | The options are as follows:<br>- **start** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **mode** (number): [mode](#openmode) for creating the writeable stream. This parameter is optional. The default value is the write-only mode.|

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
 // Create a readable stream.
  const rs = fs.createReadStream(`${pathDir}/read.txt`);
  // Create a writeable stream.
  const ws = fs.createWriteStream(`${pathDir}/write.txt`);
  // Copy files in paused mode.
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
  ```

## AtomicFile<sup>15+</sup>
AtomicFile is a class used to perform atomic read and write operations on files.

A temporary file is written and renamed to the original file location, which ensures file integrity. If the write operation fails, the temporary file is deleted without modifying the original file content.

You can call **finishWrite()** or **failWrite()** to write or roll back file content.

**System capability**: SystemCapability.FileManagement.File.FileIO

### constructor<sup>15+</sup>

constructor(path: string)

Creates an **AtomicFile** class for a file in a specified path.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                              |
  | ------ | ------ | ---- | -------------------------------------- |
  | path   | string | Yes   | Application sandbox path of the file.                      |

### getBaseFile<sup>15+</sup>

getBaseFile(): File

Obtains the file object through the **AtomicFile** object.

The FD needs to be closed by calling **close()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let atomicFile = new fs.AtomicFile(`${pathDir}/write.txt`);
  let writeSream = atomicFile.startWrite();
  writeSream.write("xxxxx","utf-8",()=> {
    atomicFile.finishWrite();
    let File = atomicFile.getBaseFile();
    hilog.info(0x0000, 'AtomicFile', 'getBaseFile File.fd is:%{public}d, path:%{public}s, name:%{public}s', File.fd, File.path, File.path);
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed! err :%{public}s', err.message);
}
```

### openRead<sup>15+</sup>

openRead(): ReadStream

Creates a **ReadStream** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fs.AtomicFile(`${pathDir}/read.txt`);
  let writeSream = file.startWrite();
  writeSream.write("xxxxxx","utf-8",()=> {
    file.finishWrite();
    setTimeout(()=>{
      let readStream = file.openRead();
      readStream.on('readable', () => {
        const data = readStream.read();
        if (!data) {
          hilog.error(0x0000, 'AtomicFile', 'Read data is null');
          return;
        }
        hilog.info(0x0000, 'AtomicFile', 'Read data is:%{public}s!', data);
      });
    },1000);
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed!, err : %{public}s', err.message);
}
```

### readFully<sup>15+</sup>

readFully(): ArrayBuffer

Reads all content of a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | ArrayBuffer | Full content of a file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { util, buffer } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fs.AtomicFile(`${pathDir}/read.txt`);
  let writeSream = file.startWrite();
  writeSream.write("xxxxxxxxxxx","utf-8",()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      hilog.info(0x0000, 'AtomicFile', 'readFully str is :%{public}s!', str);
    },1000);
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed!, err : %{public}s', err.message);
}
```

### startWrite<sup>15+</sup>

startWrite(): WriteStream

Starts to write new file data in the **WriteStream** object returned.

If the file does not exist, create a file.

Call **finishWrite()** if the write operation is successful; call **failWrite()** if the write operation fails.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fs.AtomicFile(`${pathDir}/write.txt`);
  let writeSream = file.startWrite();
  hilog.info(0x0000, 'AtomicFile', 'startWrite end');
  writeSream.write("xxxxxxxx","utf-8",()=> {
    hilog.info(0x0000, 'AtomicFile', 'write end');
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed! err :%{public}s', err.message);
}
```

### finishWrite<sup>15+</sup>

finishWrite(): void

Finishes writing file data when the write operation is complete.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fs.AtomicFile(`${pathDir}/write.txt`);
  let writeSream = file.startWrite();
  writeSream.write("xxxxxxxxxxx","utf-8",()=> {
    file.finishWrite();
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed!, err : %{public}s', err.message);
}
```

### failWrite<sup>15+</sup>

failWrite(): void

Rolls back the file after the file fails to be written.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { util, buffer } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let file = new fs.AtomicFile(`${pathDir}/write.txt`);
try {
  let writeSream = file.startWrite();
  writeSream.write("xxxxxxxxxxx","utf-8",()=> {
    hilog.info(0x0000, 'AtomicFile', 'write succeed!');
  })
} catch (err) {
  file.failWrite();
  hilog.error(0x0000, 'AtomicFile', 'failed!, err : %{public}s', err.message);
}
```

### delete<sup>15+</sup>

delete(): void

Deletes the **AtomicFile** class, including the original files and temporary files.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md#universal-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { util } from '@kit.ArkTS';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fs.AtomicFile(`${pathDir}/read.txt`);
  let writeSream = file.startWrite();
  writeSream.write("xxxxxxxxxxx","utf-8",()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      hilog.info(0x0000, 'AtomicFile', 'readFully str is :%{public}s!', str);
      file.delete();
    },1000);
  })
} catch (err) {
  hilog.error(0x0000, 'AtomicFile', 'failed!, err : %{public}s', err.message);
}
```

## fs.createWatcher<sup>10+</sup>

createWatcher(path: string, events: number, listener: WatchEventListener): Watcher

Creates a **Watcher** object to listen for file or directory changes.

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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
  ```ts
  import { common } from '@kit.AbilityKit';
  import { fileIo as fs, WatchEvent } from '@kit.CoreFileKit';

  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let pathDir = context.filesDir;
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

Provides APIs for observing events.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | event   | [WatchEvent](#watchevent10) | Yes   | Event for the callback to invoke.                            |

## WatchEvent<sup>10+</sup>

Defines the event to observe.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name  | Type  | Read-Only  | Optional  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| fileName | string | Yes   | No   | Sandbox path of the file to observe. The sandbox path contains the file name.|
| event | number | Yes   | No   | Events to observe. Multiple events can be separated by a bitwise OR operator (\|).<br>- **0x1: IN_ACCESS**: A file is accessed.<br>- **0x2: IN_MODIFY**: The file content is modified.<br>- **0x4: IN_ATTRIB**: The file metadata is modified.<br>- **0x8: IN_CLOSE_WRITE**: A file is opened, written with data, and then closed.<br>- **0x10: IN_CLOSE_NOWRITE**: A file or directory is opened and then closed without data written.<br>- **0x20: IN_OPEN**: A file or directory is opened.<br>- **0x40: IN_MOVED_FROM**: A file in the observed directory is moved.<br>- **0x80: IN_MOVED_TO**: A file is moved to the observed directory.<br>- **0x100: IN_CREATE**: A file or directory is created in the observed directory.<br>- **0x200: IN_DELETE**: A file or directory is deleted from the observed directory.<br>- **0x400: IN_DELETE_SELF**: The observed directory is deleted. After the directory is deleted, the listening stops.<br>- **0x800: IN_MOVE_SELF**: The observed file or directory is moved. After the file or directory is moved, the listening continues.<br>- **0xfff: IN_ALL_EVENTS**: All events.|
| cookie | number | Yes   | No   | Cookie bound with the event.<br>Currently, only the **IN_MOVED_FROM** and **IN_MOVED_TO** events are supported. The **IN_MOVED_FROM** and **IN_MOVED_TO** events of the same file have the same **cookie** value.|

## Progress<sup>11+</sup>

Defines the copy progress information.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name  | Type  | Read-Only  | Optional  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| processedSize | number | Yes   | No   | Size of the copied data.|
| totalSize | number | Yes   | No   | Total size of the data to be copied.|

## TaskSignal<sup>12+</sup>

Provides APIs for interrupting a copy task.

**System capability**: SystemCapability.FileManagement.File.FileIO

### cancel<sup>12+</sup>

cancel(): void

Cancels a copy task.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { fileUri } from '@kit.CoreFileKit';
import common from '@ohos.app.ability.common';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";
let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);
let copySignal = new fs.TaskSignal;
let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  if (progress.processedSize / progress.totalSize > 0.5) {
    copySignal.cancel();
    console.info("copy cancel.");
  }
};
let options: fs.CopyOptions = {
  "progressListener" : progressListener,
  "copySignal" : copySignal,
}

try {
  fs.copy(srcDirUriLocal, dstDirUriLocal, options, (err: BusinessError) => {
    if (err) {
      console.error("copy fail, err: ", err.message);
      return;
    }
    console.info("copy success.");
  })
} catch (err) {
  console.error("copyFileWithCancel failed, err: ", err.message);
}

```

### onCancel<sup>12+</sup>

onCancel(): Promise&lt;string&gt;

Subscribes to the event reported when a copy task is canceled.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the path of the last file copied.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { TaskSignal } from '@ohos.file.fs';
let copySignal: fs.TaskSignal = new TaskSignal();
copySignal.onCancel().then(() => {
    console.info("copyFileWithCancel success.");
});
```

## CopyOptions<sup>11+</sup>

Defines the callback for listening for the copy progress.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name  | Type  | Read-Only  | Optional  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| progressListener | [ProgressListener](#progresslistener11) | No   | Yes   | Listener used to observe the copy progress.|
| copySignal | [TaskSignal](#tasksignal12) | No   | Yes   | Signal used to cancel a copy task.|

## ProgressListener<sup>11+</sup>

Listener used to observe the copy progress.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Type| Description|
| ----| ------|
|(progress: [Progress](#progress11)) => void| Listener used to observe the copy progress.|

**Example**

  ```ts
  import { TaskSignal } from '@kit.CoreFileKit';
  let copySignal: fs.TaskSignal = new TaskSignal();
  let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
    console.info(`processedSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyOption: fs.CopyOptions = {
    "progressListener" : progressListener,
    "copySignal" : copySignal,
  }
  ```

## Stat

Represents detailed file information. Before calling any API of the **Stat()** class, use [stat()](#fsstat) to create a **Stat** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name    | Type  | Read-Only  | Optional  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| ino    | bigint | Yes   | No   | File ID. Different files on the same device have different **ino**s.|                 |
| mode   | number | Yes   | No   | File permissions. The meaning of each bit is as follows:<br>**NOTE**<br>The following values are in octal format. The return values are in decimal format. You need to convert the values.<br>- **0o400**: The user has the read permission on a regular file or a directory entry.<br>- **0o200**: The user has the permission to write a regular file or create and delete a directory entry.<br>- **0o100**: The user has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o040**: The user group has the read permission on a regular file or a directory entry.<br>- **0o020**: The user group has the permission to write a regular file or create and delete a directory entry.<br>- **0o010**: The user group has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o004**: Other users have the permission to read a regular file or read a directory entry.<br>- **0o002**: Other users have the permission to write a regular file or create and delete a directory entry.<br>- **0o001**: Other users have the permission to execute a regular file or search for the specified path in a directory.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uid    | number | Yes   | No   | ID of the file owner.|
| gid    | number | Yes   | No   | ID of the user group of the file.|
| size   | number | Yes   | No   | File size, in bytes. This parameter is valid only for regular files.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| atime  | number | Yes   | No   | Time when the file was last accessed. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.<br>**NOTE**<br>Currently, user data partitions are mounted in **noatime** mode by default, and **atime** update is disabled.<br>**Atomic service API**: This API can be used in atomic services since API version 11.     |
| mtime  | number | Yes   | No   | Time when the file content was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.<br>**Atomic service API**: This API can be used in atomic services since API version 11.     |
| ctime  | number | Yes   | No   | Time when the file metadata was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.     |
| atimeNs<sup>15+</sup>  | bigint | Yes   | Yes   | Time of the last access to the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.<br>**NOTE**<br>Currently, user data partitions are mounted in **noatime** mode by default, and **atime** update is disabled.     |
| mtimeNs<sup>15+</sup>  | bigint | Yes   | Yes   | Time of the last modification to the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.     |
| ctimeNs<sup>15+</sup>  | bigint | Yes   | Yes   | Time of the last status change of the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.     |
| location<sup>11+</sup> | [LocaltionType](#locationtype11)| Yes|No| File location, which indicates whether the file is stored in a local device or in the cloud.

### isBlockDevice

isBlockDevice(): boolean

Checks whether this file is a block special file. A block special file supports access by block only, and it is cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type    | Description              |
  | ------- | ---------------- |
  | boolean | Whether the file is a block special file. The value **true** means the file is a block special file; the value **false** means the file is not a block special file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fs.statSync(filePath).isBlockDevice();
  ```

### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this file is a character special file. A character special device supports random access, and it is not cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description               |
  | ------- | ----------------- |
  | boolean | Whether the file is a character special device. The value **true** means the file is a character special device; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fs.statSync(filePath).isCharacterDevice();
  ```

### isDirectory

isDirectory(): boolean

Checks whether this file is a directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description           |
  | ------- | ------------- |
  | boolean | Whether the file is a directory. The value **true** means the file is a directory; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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
  | boolean | Whether the file is an FIFO. The value **true** means the file is an FIFO; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFIFO = fs.statSync(filePath).isFIFO();
  ```

### isFile

isFile(): boolean

Checks whether this file is a regular file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Whether the file is a regular file. The value **true** means that the file is a regular file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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
  | boolean | Whether the file is a socket. The value **true** means that the file is a socket; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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
  | boolean | Whether the file is a symbolic link. The value **true** means that the file is a symbolic link; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test";
  let isSymbolicLink = fs.statSync(filePath).isSymbolicLink();
  ```

## Stream

Provides API for stream operations. Before calling any API of **Stream**, you need to create a **Stream** instance by using [fs.createStream](#fscreatestream) or [fs.fdopenStream](#fsfdopenstream).

### close

close(): Promise&lt;void&gt;

Closes the file stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.close().then(() => {
    console.info("File stream closed");
  }).catch((err: BusinessError) => {
    console.error("close fileStream  failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### close

close(callback: AsyncCallback&lt;void&gt;): void

Closes the file stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description           |
  | -------- | ------------------------- | ---- | ------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked immediately after the stream is closed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.close((err: BusinessError) => {
    if (err) {
      console.error("close stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("close stream succeed");
    }
  });
  ```

### closeSync

closeSync(): void

Closes the file stream. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.closeSync();
  ```

### flush

flush(): Promise&lt;void&gt;

Flushes the file stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flush().then(() => {
    console.info("Stream flushed");
    stream.close();
  }).catch((err: BusinessError) => {
    console.error("flush failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes the file stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description            |
  | -------- | ------------------------- | ---- | -------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flush((err: BusinessError) => {
    if (err) {
      console.error("flush stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Stream flushed");
      stream.close();
    }
  });
  ```

### flushSync

flushSync(): void

Flushes the file stream. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  stream.flushSync();
  stream.close();
  ```

### write

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data to a stream file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption).then((number: number) => {
    console.info("write succeed and size is:" + number);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error("write failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### write

write(buffer: ArrayBuffer | string, options?: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a stream file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                           | Mandatory| Description                                                        |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | buffer   | ArrayBuffer \| string | Yes  | Data to write. It can be a string or data from a buffer.                    |
  | options  | [WriteOptions](#writeoptions11)                          | No  | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
  | callback | AsyncCallback&lt;number&gt;     | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error("write stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      if (bytesWritten) {
        console.info("write succeed and size is:" + bytesWritten);
        stream.close();
      }
    }
  });
  ```

### writeSync

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a stream file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath,"r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  let num = stream.writeSync("hello, world", writeOption);
  stream.close();
  ```

### read

read(buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

Reads data from a stream file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | [ReadOptions](#readoptions11)      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.|

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;number&gt; | Promise used to return the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption).then((readLen: number) => {
    console.info("Read data successfully");
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.log(`The content of file: ${buf.toString()}`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error("read data failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### read

read(buffer: ArrayBuffer, options?: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a stream file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
  | options  | [ReadOptions](#readoptions11)                                   | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.|
  | callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error("read stream failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("Read data successfully");
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.log(`The content of file: ${buf.toString()}`);
      stream.close();
    }
  });
  ```

### readSync

readSync(buffer: ArrayBuffer, options?: ReadOptions): number

Reads data from a stream file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | [ReadOptions](#readoptions11)      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data. This parameter is optional. By default, data is read from the current position.<br> |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let stream = fs.createStreamSync(filePath, "r+");
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  let buf = new ArrayBuffer(4096);
  let num = stream.readSync(buf, readOption);
  stream.close();
  ```

## File

Represents a **File** object opened by **open()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name  | Type  | Read-Only  | Optional  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| fd | number | Yes   | No   | FD of the file.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
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

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
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
  | exclusive  | boolean | No  | Lock to apply.<br>The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.     |

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.lock(true).then(() => {
    console.log("lock file succeed");
  }).catch((err: BusinessError) => {
    console.error("lock file failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    fs.closeSync(file);
  });
  ```

### lock

lock(exclusive?: boolean, callback: AsyncCallback\<void>): void

Applies an exclusive lock or a shared lock on this file in blocking mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | exclusive  | boolean | No  | Lock to apply.<br>The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.       |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.lock(true, (err: BusinessError) => {
    if (err) {
      console.error("lock file failed with error message: " + err.message + ", error code: " + err.code);
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
  | exclusive  | boolean | No  | Lock to apply.<br>The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.      |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

Unlocks a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  file.tryLock(true);
  file.unlock();
  console.log("unlock file succeed");
  fs.closeSync(file);
  ```

  ## fs.DfsListeners<sup>12+</sup>

interface DfsListeners {
  onStatus(networkId: string, status: number): void
}

Provides APIs for listening for the distributed file system status.

**System capability**: SystemCapability.FileManagement.File.FileIO

### onStatus<sup>12+</sup>

onStatus(networkId: string, status: number): void;

Called to return the specified status. Its parameters are passed in by [connectDfs](#fsconnectdfs12).

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                             |
  | ---- | ------ | ---- | ---------------------------------------- |
  | networkId   | string | Yes   | Network ID of the device.                            |
  | status | number | Yes   | Status code of the distributed file system. The status code is the error code returned by **onStatus** invoked by **connectDfs**. If the device is abnormal when **connectDfs()** is called, **onStatus** will be called to return the error code:<br>- [13900046](errorcode-filemanagement.md#13900046): disconnection caused by software.

## RandomAccessFile

Provides APIs for randomly reading and writing a stream. Before invoking any API of **RandomAccessFile**, you need to use **createRandomAccessFile()** to create a **RandomAccessFile** instance synchronously or asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name        | Type  | Read-Only | Optional | Description             |
| ----------- | ------ | ----  | ----- | ---------------- |
| fd          | number | Yes   | No   | FD of the file.|
| filePointer | number | Yes   | No   | Offset pointer to the **RandomAccessFile** instance.|

### setFilePointer<sup>10+</sup>

setFilePointer(filePointer:number): void

Sets the file offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type     | Mandatory  | Description        |
  | ------- | ----------- | ---- | ----------------------------- |
  | filePointer  | number | Yes  | Offset pointer to the **RandomAccessFile** instance. |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  randomAccessFile.setFilePointer(1);
  randomAccessFile.close();
  ```


### close<sup>10+</sup>

close(): void

Closes the **RandomAccessFile** instance. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  randomAccessFile.close();
  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data into a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: 5,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption).then((bytesWritten: number) => {
    console.info("randomAccessFile bytesWritten: " + bytesWritten);
  }).catch((err: BusinessError) => {
    console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    randomAccessFile.close();
    fs.closeSync(file);
  });

  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                           | Mandatory| Description                                                        |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | buffer   | ArrayBuffer \| string | Yes  | Data to write. It can be a string or data from a buffer.                    |
  | options  | [WriteOptions](#writeoptions11)                          | No  | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
  | callback | AsyncCallback&lt;number&gt;     | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: bufferLength,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error("write failed with error message: " + err.message + ", error code: " + err.code);
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

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer \| string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | [WriteOptions](#writeoptions11)                          | No   | The options are as follows:<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { fileIo as fs, WriteOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  let bytesWritten = randomAccessFile.writeSync("hello, world", writeOption);
  randomAccessFile.close();
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

Reads data from a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | [ReadOptions](#readoptions11)      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;number&gt; | Promise used to return the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.read(arrayBuffer, readOption).then((readLength: number) => {
    console.info("randomAccessFile readLength: " + readLength);
  }).catch((err: BusinessError) => {
    console.error("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);
  }).finally(() => {
    randomAccessFile.close();
    fs.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options?: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
  | options  | [ReadOptions](#readoptions11)                                   | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|
  | callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.                        |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let length: number = 20;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(length);
  randomAccessFile.read(arrayBuffer, readOption, (err: BusinessError, readLength: number) => {
    if (err) {
      console.error("read failed with error message: " + err.message + ", error code: " + err.code);
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

readSync(buffer: ArrayBuffer, options?: ReadOptions): number

Reads data from a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | [ReadOptions](#readoptions11)      | No   | The options are as follows:<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.<br> |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  let randomAccessFile = fs.createRandomAccessFileSync(file);
  let length: number = 4096;
  let arrayBuffer = new ArrayBuffer(length);
  let readLength = randomAccessFile.readSync(arrayBuffer);
  randomAccessFile.close();
  fs.closeSync(file);
  ```

### getReadStream<sup>12+</sup>

getReadStream(): ReadStream

Obtains a **ReadStream** instance of this **RandomAccessFile**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  const rs = randomAccessFile.getReadStream();
  rs.close();
  randomAccessFile.close();
  ```

### getWriteStream<sup>12+</sup>

getWriteStream(): WriteStream

Obtains a **WriteStream** instance of this **RandomAccessFile**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  const ws = randomAccessFile.getWriteStream();
  ws.close();
  randomAccessFile.close();
  ```


## Watcher<sup>10+</sup>

Provides APIs for observing the changes of files or directories. Before using the APIs of **Watcher**, call **createWatcher()** to create a **Watcher** object.

### start<sup>10+</sup>

start(): void

Starts listening.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fs.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

### stop<sup>10+</sup>

stop(): void

Stops listening and removes the **Watcher** object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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
| READ_ONLY | number |  0o0   | Open the file in read-only mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WRITE_ONLY | number | 0o1    | Open the file in write-only mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| READ_WRITE | number | 0o2    | Open the file in read/write mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CREATE | number | 0o100    | Create a file if the specified file does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| TRUNC | number | 0o1000    | If the file exists and is opened in write-only or read/write mode, truncate the file length to 0.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| APPEND | number | 0o2000   | Open the file in append mode. New data will be written to the end of the file.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| NONBLOCK | number | 0o4000    | If **path** points to a named pipe (FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.|
| DIR | number | 0o200000    | If **path** does not point to a directory, throw an exception.|
| NOFOLLOW | number | 0o400000    | If **path** points to a symbolic link, throw an exception.|
| SYNC | number | 0o4010000    | Open the file in synchronous I/O mode.|

## Filter<sup>10+</sup>

Defines the file filtering configuration used by **listFile()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      | Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| suffix | Array&lt;string&gt;     | No| Locate files that fully match the specified file name extensions, which are of the OR relationship.          |
| displayName    | Array&lt;string&gt;     | No| Locate files that fuzzy match the specified file names, which are of the OR relationship. Currently, only the wildcard * is supported.|
| mimeType    | Array&lt;string&gt; | No| Locate files that fully match the specified MIME types, which are of the OR relationship. This parameter is reserved.     |
| fileSizeOver    | number | No| Locate files that are greater than the specified size.      |
| lastModifiedAfter    | number | No| Locate files whose last modification time is the same or later than the specified time.      |
| excludeMedia    | boolean | No| Whether to exclude the files already in **Media**.<br>The value **true** means to exclude the files already in **Media**; the value **false** means not to exclude the files already in **Media**.   |

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

## LocationType<sup>11+</sup>

Enumerates the file locations.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Value      | Description               |
| ----------- | --------------- | ------------------ |
| LOCAl | 1     | The file is stored in a local device.          |
| CLOUD    | 2     | The file is stored in the cloud.|

## AccessModeType<sup>12+</sup>

Enumerates the access modes to verify. If this parameter is left blank, the system checks whether the file exists.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Value      | Description               |
| ----------- | --------------- | ------------------ |
| EXIST | 0     | Whether the file exists.          |
| WRITE    | 2     | Verify the write permission on the file.|
| READ    | 4     | Verify the read permission on the file.|
| READ_WRITE    | 6     | Verify the read/write permission on the file.|

## AccessFlagType<sup>12+</sup>

Enumerates the locations of the file to verify.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Value      | Description               |
| ----------- | --------------- | ------------------ |
| LOCAL | 0     | The file is stored locally.         |

## ReadOptions<sup>11+</sup>

Defines the options used in **read()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      | Description               |
| ----------- | --------------- | ------------------ |------------------ |
| length | number     | No| Length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.          |
|  offset    | number     | No| Start position of the file to read (current **filePointer** plus **offset**), in bytes. This parameter is optional. By default, data is read from the **filePointer**.|

## ReadTextOptions<sup>11+</sup>

Defines the options used in **readText()**. It inherits from [ReadOptions](#readoptions11).

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      | Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| length | number     | No| Length of the data to read, in bytes. This parameter is optional. The default value is the file length.          |
|  offset    | number     | No| Start position of the file to read, in bytes. This parameter is optional. By default, data is read from the current position.|
| encoding    | string | No| Format of the data to be encoded. This parameter is valid only when the data type is string. The default value is **'utf-8'**, which is the only value supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |

## WriteOptions<sup>11+</sup>

Defines the options used in **write()**. It inherits from [Options](#options11).

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      | Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| length | number     | No| Length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>**Atomic service API**: This API can be used in atomic services since API version 11.          |
|  offset    | number     | No| Start position of the file to write (current **filePointer** plus **offset**), in bytes. This parameter is optional. By default, data is written from the **filePointer**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| encoding    | string | No| Format of the data to be encoded. This parameter is valid only when the data type is string. The default value is **'utf-8'**, which is the only value supported.      |

## ListFileOptions<sup>11+</sup>

Defines the options used in **listFile()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      |  Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| recursion | boolean     | No| Whether to list all files in the subdirectories recursively. This parameter is optional. The default value is **false**. If **recursion** is **false**, the names of files and directories that meet the filtering requirements in the current directory are returned. If **recursion** is **true**, relative paths (starting with /) of all files that meet the specified conditions in the current directory are returned.          |
|  listNum    | number     | No| Number of file names to list. This parameter is optional. The default value is **0**, which means to list all files.|
| filter    | [Filter](#filter10) | No| File filtering configuration. This parameter is optional. It specifies the file filtering conditions.|

## ReadStream<sup>12+</sup>

Defines a readable stream. You need to use [fs.createReadStream](#fscreatereadstream12) to create a **ReadStream** instance, which is inherited from the [stream base class](../apis-arkts/js-apis-stream.md#readable).

The data obtained by **ReadStream** is a decoded string. Currently, only the UTF-8 format is supported.

### Properties

| Name    | Type  | Read-Only  | Optional  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| bytesRead    | number | Yes   | No   | Number of bytes read by the readable stream.|
| path    | string | Yes   | No   | Path of the file corresponding to the readable stream.|

### Seek

seek(offset: number, whence?: WhenceType): number


Adjusts the position of the readable stream offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | offset | number | Yes   | Relative offset, in bytes.|
  | whence | [WhenceType](#whencetype11) | No   | Where to start the offset. The default value is **SEEK_SET**, which indicates the beginning of the file.|

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | number | Position of the current offset pointer (offset relative to the file header, in bytes).|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fs.createReadStream(filePath);
  const curOff = rs.seek(5, fs.WhenceType.SEEK_SET);
  console.info(`current offset is ${curOff}`);
  rs.close();
  ```

### close

close(): void

Closes this readable stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fs.createReadStream(filePath);
  rs.close();
  ```

## WriteStream<sup>12+</sup>

Defines a writeable stream. You need to use [fs.createWriteStream](#fscreatewritestream12) to create a **WriteStream** instance, which is inherited from the [stream base class](../apis-arkts/js-apis-stream.md#writable).

### Properties

| Name    | Type  | Read-Only  | Optional  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| bytesWritten    | number | Yes   | No   | Number of bytes written to the writable stream.|
| path    | string | Yes   | No   | Path of the file corresponding to the writeable stream.|

### Seek

seek(offset: number, whence?: WhenceType): number;

Adjusts the position of the writeable stream offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | offset | number | Yes   | Relative offset, in bytes.|
  | whence | [WhenceType](#whencetype11) | No   | Where to start the offset. The default value is **SEEK_SET**, which indicates the beginning of the file.|

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | number | Position of the current offset pointer (offset relative to the file header, in bytes).|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fs.createWriteStream(filePath);
  const curOff = ws.seek(5, fs.WhenceType.SEEK_SET);
  console.info(`current offset is ${curOff}`);
  ws.close();
  ```

### close

close(): void

Closes this writeable stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fs.createWriteStream(filePath);
  ws.close();
  ```

## RandomAccessFileOptions<sup>12+</sup>

Defines the options used in **createRandomAccessFile()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      |  Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| start   | number     | No| Start position to read the data, in bytes. This parameter is optional. By default, data is read from the current position.          |
| end     | number     | No|  End position to read the data, in bytes. This parameter is optional. The default value is the end of the file.|

## ReadStreamOptions<sup>12+</sup>

Defines the options used in **createReadStream()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      |  Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| start   | number     | No| Start position to read the data, in bytes. This parameter is optional. By default, data is read from the current position.          |
| end     | number     | No|  End position to read the data, in bytes. This parameter is optional. The default value is the end of the file.|

## WriteStreamOptions<sup>12+</sup>

Defines the options used in **createWriteStream()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Mandatory      |  Description               |
| ----------- | --------------- | ------------------ | ------------------ |
| start   | number     | No| Start position to write the data, in bytes. This parameter is optional. By default, data is written from the beginning of the file.          |
| mode     | number     | No| [Option](#openmode) for creating the writeable stream. You must specify one of the following options.<br>- **OpenMode.READ_ONLY(0o0)**: read-only, which is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: write-only.<br>- **OpenMode.READ_WRITE(0o2)**: read/write.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|
