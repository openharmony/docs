# @ohos.file.fs (File Management)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->

The **fs** module provides APIs for file operations, including accessing and managing files and directories, obtaining file information statistics, and reading and writing data using a stream.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { fileIo } from '@kit.CoreFileKit';
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

## fileIo.stat

stat(file: string | number): Promise&lt;Stat&gt;

Obtains the detailed attribute information about a file or directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path, URI, or FD of the file or directory.<br>**Note**: URIs can be passed since API version 22.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[Stat](#stat)&gt; | Promise used to return the file or directory information.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.stat(filePath).then((stat: fileIo.Stat) => {
    console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get file info. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.stat

stat(file: string | number, callback: AsyncCallback&lt;Stat&gt;): void

Obtains the detailed attribute information about a file or directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path, URI, or FD of the file or directory.<br>**Note**: URIs can be passed since API version 22.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes| Callback used to return the file or directory information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.stat(pathDir, (err: BusinessError, stat: fileIo.Stat) => {
    if (err) {
      console.error(`Failed to get file info. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
    }
  });
  ```

## fileIo.statSync

statSync(file: string | number): Stat

Obtains detailed attribute information of a file or directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path, URI, or FD of the file or directory.<br>**Note**: URIs can be passed since API version 22.|

**Return value**

| Type| Description|
| ---- | ---- |
| [Stat](#stat) | Detailed information of a file or directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let stat = fileIo.statSync(pathDir);
  console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
  ```

## fileIo.access

access(path: string, mode?: AccessModeType): Promise&lt;boolean&gt;

Checks whether a file or directory exists or has the operation permission. This API uses a promise to return the result.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| mode<sup>12+</sup> | [AccessModeType](#accessmodetype12) | No| Permission on the file or directory to check. If this parameter is left blank, the system checks whether the file exists.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file or directory exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).


**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath).then((res: boolean) => {
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.access<sup>12+</sup>

access(path: string, mode: AccessModeType, flag: AccessFlagType): Promise&lt;boolean&gt;

Checks whether the file or directory is on the local host or verifies the operation permission. This API uses a promise to return the result.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| mode | [AccessModeType](#accessmodetype12) | Yes| Permission on the file or directory to check.|
| flag | [AccessFlagType](#accessflagtype12) | Yes| Position of the file or directory to check.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file or directory is a local one and has the related permission. The value **false** means the file or directory does not exist or is on the cloud or a distributed device.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath, fileIo.AccessModeType.EXIST, fileIo.AccessFlagType.LOCAL).then((res: boolean) => {
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.access

access(path: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a file or directory exists. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means the file exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).


**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath, (err: BusinessError, res: boolean) => {
    if (err) {
      console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (res) {
        console.info(`Succeeded in checking file, file exists.`);
      } else {
        console.info(`Succeeded in checking file, file does not exist.`);
      }
    }
  });
  ```

## fileIo.accessSync

accessSync(path: string, mode?: AccessModeType): boolean

Checks whether a file or directory exists or has the operation permission. This API returns the result synchronously.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| mode<sup>12+</sup> | [AccessModeType](#accessmodetype12) | No| Permission on the file or directory to check. If this parameter is left blank, the system checks whether the file or directory exists.|

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | The value **true** means the file or directory exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  try {
    let res = fileIo.accessSync(filePath);
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to accessSync. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.accessSync<sup>12+</sup>

accessSync(path: string, mode: AccessModeType, flag: AccessFlagType): boolean

Checks whether a file or directory is stored locally or has the operation permission. This API returns the result synchronously.<br>If the read, write, or read and write permission verification fails, the error code 13900012 (Permission denied) will be thrown.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| mode | [AccessModeType](#accessmodetype12) | Yes| Permission on the file or directory to check.|
| flag | [AccessFlagType](#accessflagtype12) | Yes| Position of the file or directory to check.|

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | The value **true** means the file or directory is a local one and has the related permission. The value **false** means the file or directory does not exist or is on the cloud or a distributed device.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  try {
    let res = fileIo.accessSync(filePath, fileIo.AccessModeType.EXIST, fileIo.AccessFlagType.LOCAL);
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to accessSync. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.close

close(file: number | File): Promise&lt;void&gt;

Closes a file or directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | Yes| **File** object or FD of the file to close. After the function is disabled, the **File** object or FD cannot be used for read and write operations. If the file object or file descriptor is still used, an error may occur or the operation may fail.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.close(file).then(() => {
    console.info(`Succeeded in closing file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to close file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.close

close(file: number | File, callback: AsyncCallback&lt;void&gt;): void

Closes a file or directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | Yes| **File** object or FD of the file to close. After the function is disabled, the **File** object or FD cannot be used for read and write operations. If the file object or file descriptor is still used, an error may occur or the operation may fail.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. When the file or directory is successfully closed asynchronously, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.close(file, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to close file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in closing file.`);
    }
  });
  ```

## fileIo.closeSync

closeSync(file: number | File): void

Closes a file or directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | Yes| **File** object or FD of the file to close. After the function is disabled, the **File** object or FD cannot be used for read and write operations. If the file object or file descriptor is still used, an error may occur or the operation may fail.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.closeSync(file);
  ```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options?: CopyOptions): Promise\<void>

Copies a file or directory. This API uses a promise to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| srcUri | string | Yes| URI of the file or directory to copy.|
| destUri | string | Yes| URI of the destination file or directory.|
| options | [CopyOptions](#copyoptions11)| No| Callback invoked to provide the copy progress. If this parameter is not set, the callback will not be invoked.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
};
let copyOption: fileIo.CopyOptions = {
  "progressListener" : progressListener
}
try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, copyOption).then(()=>{
    console.info("Succeeded in copying.");
  }).catch((err: BusinessError)=>{
    console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
  })
} catch (err) {
  console.error(`Failed to copy.Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, callback: AsyncCallback\<void>): void

Copies a file or directory. This API uses an asynchronous callback to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| srcUri | string | Yes| URI of the file or directory to copy.|
| destUri | string | Yes| URI of the destination file or directory.|
| callback | AsyncCallback\<void>| Yes| Callback used to return the result. If the copy is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in copying.");
  })
} catch (err) {
  console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options: CopyOptions, callback: AsyncCallback\<void>): void

Copies a file or directory. This API uses an asynchronous callback to return the result.

File copy across devices is supported. This API forcibly overwrites the file or directory. The input parameter can be the URI of the file or directory.<br>
A maximum of 10 cross-device copy tasks are allowed at the same time, and the number of files to be copied at a time cannot exceed 500.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| srcUri | string | Yes| URI of the file or directory to copy.|
| destUri | string | Yes| URI of the destination file or directory.|
| options | [CopyOptions](#copyoptions11) |Yes| Callback used to return the copy progress.|
| callback | AsyncCallback\<void>| Yes| Callback used to return the result. If the copy is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
    console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyOption: fileIo.CopyOptions = {
    "progressListener" : progressListener
  }
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, copyOption, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in copying.");
  })
} catch (err) {
  console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, mode?: number): Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string \| number | Yes| Path or FD of the file to copy.|
| dest | string \| number | Yes| Destination path of the file or FD of the file created.|
| mode | number | No| Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, 0).then(() => {
    console.info(`Succeeded in copying file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file with the specified mode. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string \| number | Yes| Path or FD of the file to copy.|
| dest | string \| number | Yes| Destination path of the file or FD of the file created.|
| mode | number | Yes| Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is successfully copied, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, 0, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying file.`);
    }
  });
  ```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API overwrites the file with the same name in the destination directory and truncates the part that is not overwritten. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string \| number | Yes| Path or FD of the file to copy.|
| dest | string \| number | Yes| Destination path of the file or FD of the file created.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is successfully copied, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying file.`);
    }
  });
  ```


## fileIo.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

Copies a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string \| number | Yes| Path or FD of the file to copy.|
| dest | string \| number | Yes| Destination path of the file or FD of the file created.|
| mode | number | No| Whether to overwrite the file with the same name in the destination directory. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFileSync(srcPath, dstPath);
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode?: number): Promise\<void>

Copies the source directory to the destination path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | No| Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, 0).then(() => {
    console.info(`Succeeded in copying directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

Copies the source directory to the destination path. You can set the copy mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | Yes| Copy mode.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully copied, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Copy srcPath to destPath.
let srcPath = pathDir + "/srcDir/";
let destPath = pathDir + "/destDir/";
fileIo.copyDir(srcPath, destPath, 0, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in copying directory.`);
  }
});
```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies the source directory to the destination path. You can set the copy mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | Yes| Copy mode.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes| Callback used to return the result. If the directory is successfully copied, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, 0, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to copy directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying directory.`);
    }
  });
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void>): void

Copies the source directory to the destination path. This API uses an asynchronous callback to return the result.

An exception will be thrown if the destination directory contains a directory with the same name as the source directory and there are files with the same name in the conflicting directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully copied, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Copy srcPath to destPath.
let srcPath = pathDir + "/srcDir/";
let destPath = pathDir + "/destDir/";
fileIo.copyDir(srcPath, destPath, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in copying directory.`);
  }
});
```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Copies the source directory to the destination path. This API uses an asynchronous callback to return the result.

An exception will be thrown if the destination directory contains a directory with the same name as the source directory and there are files with the same name in the conflicting directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to copy directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying directory.`);
    }
  });
  ```

## fileIo.copyDirSync<sup>10+</sup>

copyDirSync(src: string, dest: string, mode?: number): void

Copies the source directory to the destination path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | No| Copy mode. The default value is **0**.<br>- **0**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be copied to the destination directory, and the non-conflicting files in the destination directory will be retained. The **data** attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **1**: Forcibly overwrite the files with the same name in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Copy srcPath to destPath.
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  try {
    fileIo.copyDirSync(srcPath, destPath, 0);
    console.info(`Succeeded in copying directory.`);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.dup<sup>10+</sup>

dup(fd: number): File

Duplicates the file descriptor and returns the corresponding **File** object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| File descriptor.|

**Return value**

| Type| Description|
| ---- | ---- |
| [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file1 = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let fd: number = file1.fd;
  let file2 = fileIo.dup(fd);
  console.info(`Succeeded in getting file name of the file2 is ${file2.name}`);
  fileIo.closeSync(file1);
  fileIo.closeSync(file2);
  ```

## fileIo.connectDfs<sup>12+</sup>

connectDfs(networkId: string, listeners: DfsListeners): Promise&lt;void&gt;

Triggers connection. If the peer device is abnormal, [onStatus](#onstatus12) in **DfsListeners** will be called to notify the application. For details, see the [Sharing and Accessing Files Across Devices](../../file-management/file-access-across-devices.md) document.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| networkId | string | Yes| Network ID of the device. The device network ID can be obtained from [DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo) using the related [distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md) API.|
| listeners | [DfsListeners](#dfslisteners12) | Yes| Listeners for distributed file system status.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';

  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Succeeded in getting available device list.`);
    let networkId = deviceInfoList[0].networkId;
    let listeners: fileIo.DfsListeners = {
      onStatus(networkId, status) {
        console.info('onStatus');
      }
    };
    fileIo.connectDfs(networkId, listeners).then(() => {
      console.info("Succeeded in connecting dfs.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to connectDfs. Code: ${err.code}, message: ${err.message}`);
    });
  }
  ```

## fileIo.disconnectDfs<sup>12+</sup>

disconnectDfs(networkId: string): Promise&lt;void&gt;

Triggers disconnection. For details, see the [Sharing and Accessing Files Across Devices](../../file-management/file-access-across-devices.md) document.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| networkId | string | Yes| Network ID of the device. The device network ID can be obtained from [DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo) using the related [distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md) API.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Space Statistics Error Codes](errorcode-filemanagement.md#space-statistics-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';

  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Succeeded in getting available device list.`);
    let networkId = deviceInfoList[0].networkId;
    fileIo.disconnectDfs(networkId).then(() => {
      console.info("Succeeded in disconnecting dfs.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
    })
  }
  ```

## fileIo.setxattr<sup>12+</sup>

setxattr(path: string, key: string, value: string): Promise&lt;void&gt;

Sets an extended attribute of a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| key | string | Yes| Key of the extended attribute to obtain. The value is a string of less than 256 bytes and can contain only the **user.** prefix.|
| value | string | Yes| Value of the extended attribute to set.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  fileIo.setxattr(filePath, attrKey, attrValue).then(() => {
    console.info(`Succeeded in setting extended attribute.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set extended attribute. Code: ${err.code}, message: ${err.message}`);
  });

  ```
## fileIo.setxattrSync<sup>12+</sup>

setxattrSync(path: string, key: string, value: string): void

Sets an extended attribute of a file or directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| key | string | Yes| Key of the extended attribute to obtain. The value is a string of less than 256 bytes and can contain only the **user.** prefix.|
| value | string | Yes| Value of the extended attribute to set.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  try {
    fileIo.setxattrSync(filePath, attrKey, attrValue);
    console.info(`Succeeded in setting extended attribute.`);
  } catch (err) {
    console.error(`Failed to set extended attribute. Code: ${err.code}, message: ${err.message}`);
  }

  ```

## fileIo.getxattr<sup>12+</sup>

getxattr(path: string, key: string): Promise&lt;string&gt;

Obtains an extended attribute of a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| key | string | Yes| Key of the extended attribute to obtain.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string&gt;| Promise used to return the value of the extended attribute obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  fileIo.getxattr(filePath, attrKey).then((attrValue: string) => {
    console.info(`Succeeded in getting extended attribute, the value is: ${attrValue}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get extended attribute. Code: ${err.code}, message: ${err.message}`);
  });

  ```

## fileIo.getxattrSync<sup>12+</sup>

getxattrSync(path: string, key: string): string

Obtains an extended attribute of a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory.|
| key | string | Yes| Key of the extended attribute to obtain.|

**Return value**

| Type| Description|
| ---- | ---- |
| string | Value of the extended attribute obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  try {
    let attrValue = fileIo.getxattrSync(filePath, attrKey);
    console.info(`Succeeded in getting extended attribute, the value is: ${attrValue}`);
  } catch (err) {
    console.error(`Failed to get extended attribute. Code: ${err.code}, message: ${err.message}`);
  }

  ```

## fileIo.mkdir

mkdir(path: string): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.mkdir(dirPath).then(() => {
    console.info(`Succeeded in making directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean): Promise\<void>

Creates a directory. This API uses a promise to return the result. The value **true** means to create a directory recursively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| recursion | boolean | Yes| Whether to create a directory recursively.<br> The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdir(dirPath, true).then(() => {
    console.info(`Succeeded in making directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdir

mkdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully created, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.mkdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making directory.`);
    }
  });
  ```

## fileIo.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. If **recursion** is set to **true**, a directory is created recursively. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| recursion | boolean | Yes| Whether to create a directory recursively.<br> The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully created, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdir(dirPath, true, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making directory.`);
    }
  });
  ```

## fileIo.mkdirSync

mkdirSync(path: string): void

Creates a directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fileIo.mkdirSync(dirPath);
  ```

## fileIo.mkdirSync<sup>11+</sup>

mkdirSync(path: string, recursion: boolean): void

Creates a directory. This API returns the result synchronously. The value **true** means to create a directory recursively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| recursion | boolean | Yes| Whether to create a directory recursively.<br> The value **true** means to create a directory recursively. The value **false** means to create a single-level directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdirSync(dirPath, true);
  ```

## fileIo.open

open(path: string, mode?: number): Promise&lt;File&gt;

Opens a file or directory. This API uses a promise to return the result. This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of the file or directory.|
| mode | number | No| [OpenMode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can add the following function options in bitwise OR mode. By default, no additional option is added.<br>- **OpenMode.CREATE(0o100)**: Create a file if the file does not exist.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.<br>- **OpenMode.UNCACHE(0o10000000000)**: Disable the page cache for reading and writing a file. This option is supported since API version 26.0.0.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[File](#file)&gt; | Promise used to return the **File** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE).then((file: fileIo.File) => {
    console.info(`Succeeded in getting file fd: ${file.fd}`);
    fileIo.closeSync(file);
  }).catch((err: BusinessError) => {
    console.error(`Failed to open file. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.open

open(path: string, mode: number, callback: AsyncCallback&lt;File&gt;): void

Opens a file or directory with the specified mode. This API uses an asynchronous callback to return the result.

This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of a file or directory.|
| mode | number | Yes| [OpenMode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.<br>- **OpenMode.UNCACHE(0o10000000000)**: Disable the page cache for reading and writing a file. This option is supported since API version 26.0.0.|
| callback | AsyncCallback&lt;[File](#file)&gt; | Yes| Callback used to return the **File** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE, (err: BusinessError, file: fileIo.File) => {
    if (err) {
      console.error(`Failed to open. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file fd: ${file.fd}`);
      fileIo.closeSync(file);
    }
  });
  ```

## fileIo.open

open(path: string, callback: AsyncCallback&lt;File&gt;): void

Opens a file or directory. This API supports the use of a URI. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of a file or directory.|
| callback | AsyncCallback&lt;[File](#file)&gt; | Yes| Callback used to return the **File** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, (err: BusinessError, file: fileIo.File) => {
    if (err) {
      console.error(`Failed to open. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file fd: ${file.fd}`);
      fileIo.closeSync(file);
    }
  });
  ```

## fileIo.openSync

openSync(path: string, mode?: number): File

Opens a file or directory. This API returns the result synchronously. This API supports the use of a URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of a file or directory to open.|
| mode | number | No| [OpenMode](#openmode) for opening the file or directory. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **OpenMode.READ_ONLY(0o0)**: Open the file in read-only mode.<br>- **OpenMode.WRITE_ONLY(0o1)**: Open the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Open the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.<br>- **OpenMode.UNCACHE(0o10000000000)**: Disable the page cache for reading and writing a file. This option is supported since API version 26.0.0.|

**Return value**

| Type| Description|
| ---- | ---- |
| [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  console.info(`Succeeded in getting file fd: ${file.fd}`);
  fileIo.closeSync(file);
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

Read file data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fileIo.read(file.fd, arrayBuffer).then((readLen: number) => {
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read file data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fileIo.read(file.fd, arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. Read options can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| options | [ReadOptions](#readoptions11) | Yes| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  fileIo.read(file.fd, arrayBuffer, readOption, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: ReadOptions): number

Reads data from a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let buf = new ArrayBuffer(4096);
  fileIo.readSync(file.fd, buf);
  fileIo.closeSync(file);
  ```

## fileIo.rmdir

rmdir(path: string): Promise&lt;void&gt;

Deletes a directory and all its subdirectories and files. This API uses a promise to return the result.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlink()** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.rmdir(dirPath).then(() => {
    console.info(`Succeeded in removing directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.rmdir

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a directory and all its subdirectories and files. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlink()** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully deleted, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.rmdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to remove directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in removing directory.`);
    }
  });
  ```

## fileIo.rmdirSync

rmdirSync(path: string): void

Removes a directory and all its subdirectories and files synchronously.

> **NOTE**
>
> This API can be used to remove a single file. However, you are advised to use **unlinkSync** instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/testDir";
  fileIo.rmdirSync(dirPath);
  ```

## fileIo.unlink

unlink(path: string): Promise&lt;void&gt;

Deletes a single file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.unlink(filePath).then(() => {
    console.info(`Succeeded in removing file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is deleted successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.unlink(filePath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to remove file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in removing file.`);
    }
  });
  ```

## fileIo.unlinkSync

unlinkSync(path: string): void

Removes a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fileIo.unlinkSync(filePath);
  ```


## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data to a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  fileIo.write(file.fd, str).then((writeLen: number) => {
    console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  fileIo.write(file.fd, str, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. Write options can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | Yes| The options are as follows:<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  let writeOptions: WriteOptions = {
    offset: 1,
    length: 5
  };
  fileIo.write(file.fd, str, writeOptions, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported currently.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  let writeLen = fileIo.writeSync(file.fd, str);
  console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
  fileIo.closeSync(file);
  ```

## fileIo.truncate

truncate(file: string | number, len?: number): Promise&lt;void&gt;

Truncates a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path or FD of the file.|
| len | number | No| File length after truncation, in bytes. The default value is **0**.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncate(filePath, len).then(() => {
    console.info(`Succeeded in truncating file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to truncate file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.truncate

truncate(file: string | number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path or FD of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is truncated successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.truncate(filePath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to truncate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in truncating.`);
    }
  });
  ```

## fileIo.truncate

truncate(file: string | number, len: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file. The file length after truncation can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path or FD of the file.|
| len | number | Yes| File length after truncation, in bytes.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is truncated successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncate(filePath, len, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to truncate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in truncating.`);
    }
  });
  ```

## fileIo.truncateSync

truncateSync(file: string | number, len?: number): void

Truncates the file content. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| number | Yes| Application sandbox path or FD of the file.|
| len | number | No| File length after truncation, in bytes. The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncateSync(filePath, len);
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options): Promise&lt;ReaderIterator&gt;

Reads a file text line by line. Only the files in UTF-8 format are supported. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [Options](#options11) | No| Options for reading the text. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[ReaderIterator](#readeriterator11)&gt; | Promise used to return the **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options).then((readerIterator: fileIo.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info(`Succeeded in reading lines, content: ${it.value}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, callback: AsyncCallback&lt;ReaderIterator&gt;): void

Reads a file text line by line. Only the files in UTF-8 format are supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | Yes| Callback used to return a **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readLines(filePath, (err: BusinessError, readerIterator: fileIo.ReaderIterator) => {
    if (err) {
      console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
    } else {
      for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
        console.info(`Succeeded in reading lines, content: ${it.value}`);
      }
    }
  });
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, options: Options, callback: AsyncCallback&lt;ReaderIterator&gt;): void

Reads a file text line by line. Read options can be configured. Only the files in UTF-8 format are supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [Options](#options11) | Yes| Read options. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | Yes| Callback used to return a **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options, (err: BusinessError, readerIterator: fileIo.ReaderIterator) => {
    if (err) {
      console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
    } else {
      for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
        console.info(`Succeeded in reading lines, content: ${it.value}`);
      }
    }
  });
  ```

## fileIo.readLinesSync<sup>11+</sup>

readLinesSync(filePath: string, options?: Options): ReaderIterator

Reads a file text line by line synchronously. Only the files in UTF-8 format are supported.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [Options](#options11) | No| Options for reading the text. The options are as follows:<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| [ReaderIterator](#readeriterator11) | **ReaderIterator** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  let readerIterator = fileIo.readLinesSync(filePath, options);
  for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
    console.info(`Succeeded in reading lines, content: ${it.value}`);
  }
  ```

## ReaderIterator<sup>11+</sup>

Provides a **ReaderIterator** object. Before calling APIs of **ReaderIterator**, you need to use **readLines()** to create a **ReaderIterator** instance.

### next<sup>11+</sup>

next(): ReaderIteratorResult

Obtains the **ReaderIterator** result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [ReaderIteratorResult](#readeriteratorresult11) | **ReaderIteratorResult** object obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

> **NOTE**
>
> If the line read by **ReaderIterator** is not in UTF-8 format, error code 13900037 will be returned.

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options).then((readerIterator: fileIo.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info(`Succeeded in reading lines, content: ${it.value}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## ReaderIteratorResult<sup>11+</sup>

Represents the information obtained by the **ReaderIterator** object.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| done | boolean | No| No| Whether the iteration is complete. The value **true** means the iteration is complete; the value **false** means the opposite.|
| value | string | No| No| File text content read line by line.|

## fileIo.readText

readText(filePath: string, options?: ReadTextOptions): Promise&lt;string&gt;

Reads the text content of a file synchronously. This API returns the result synchronously. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [ReadTextOptions](#readtextoptions11) | No| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string&gt; | Promise used to return the content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readText(filePath).then((str: string) => {
    console.info(`Succeeded in reading text, text is: ${str}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.readText

readText(filePath: string, callback: AsyncCallback&lt;string&gt;): void

Reads the text of a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readText(filePath, (err: BusinessError, str: string) => {
    if (err) {
      console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in reading text, text is: ${str}`);
    }
  });
  ```

## fileIo.readText

readText(filePath: string, options: ReadTextOptions, callback: AsyncCallback&lt;string&gt;): void

Reads the text of a file. Read options can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [ReadTextOptions](#readtextoptions11) | Yes| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadTextOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stat = fileIo.statSync(filePath);
  let readTextOption: ReadTextOptions = {
      offset: 1,
      length: stat.size,
      encoding: 'utf-8'
  };
  fileIo.readText(filePath, readTextOption, (err: BusinessError, str: string) => {
    if (err) {
      console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in reading text, text is: ${str}`);
    }
  });
  ```

## fileIo.readTextSync

readTextSync(filePath: string, options?: ReadTextOptions): string

Reads the text content of a file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePath | string | Yes| Application sandbox path of the file.|
| options | [ReadTextOptions](#readtextoptions11) | No| The options are as follows:<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the file length.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| string | File content read.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { ReadTextOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let readTextOptions: ReadTextOptions = {
    offset: 1,
    length: 0,
    encoding: 'utf-8'
  };
  let stat = fileIo.statSync(filePath);
  readTextOptions.length = stat.size;
  let str = fileIo.readTextSync(filePath, readTextOptions);
  console.info(`Succeeded in reading text, text is: ${str}`);
  ```

## fileIo.lstat

lstat(path: string): Promise&lt;Stat&gt;

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of the file.<br>**Note**: URIs can be passed since API version 22.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[Stat](#stat)&gt; | Promise used to return the **Stat** object. For details, see **Stat**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/linkToFile";
  fileIo.lstat(filePath).then((stat: fileIo.Stat) => {
    console.info(`Succeeded in getting symbolic link info, the size of file is ${stat.size}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get symbolic link info. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.lstat

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of the file.<br>**Note**: URIs can be passed since API version 22.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes| Callback used to return the **Stat** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/linkToFile";
  fileIo.lstat(filePath, (err: BusinessError, stat: fileIo.Stat) => {
    if (err) {
      console.error(`Failed to get symbolic link info. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting symbolic link info, the size of file is ${stat.size}`);
    }
  });
  ```

## fileIo.lstatSync

lstatSync(path: string): Stat

Obtains information about a symbolic link that is used to refer to a file or directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path or URI of the file.<br>**Note**: URIs can be passed since API version 22.|

**Return value**

| Type| Description|
| ---- | ---- |
| [Stat](#stat) | File information obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/linkToFile";
  let fileStat = fileIo.lstatSync(filePath);
  console.info(`Succeeded in getting symbolic link info, the size of file is ${fileStat.size}`);
  ```

## fileIo.rename

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file or directory. This API uses a promise to return the result.

> **NOTE**
> 
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| oldPath | string | Yes| Application sandbox path of the file or directory to rename.|
| newPath | string | Yes| Application sandbox path of the renamed file or directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.rename(srcFile, dstFile).then(() => {
    console.info(`Succeeded in renaming.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to rename. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.rename

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

Renames a file or directory. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| oldPath | string | Yes| Application sandbox path of the file or directory to rename.|
| newPath | string | Yes| Application sandbox path of the renamed file or directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is renamed successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.rename(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to rename. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in renaming.`);
    }
  });
  ```

## fileIo.renameSync

renameSync(oldPath: string, newPath: string): void

Renames a file or directory. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| oldPath | string | Yes| Application sandbox path of the file or directory to rename.|
| newPath | string | Yes| Application sandbox path of the renamed file or directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.renameSync(srcFile, dstFile);
  ```

## fileIo.fsync

fsync(fd: number): Promise&lt;void&gt;

Synchronizes the cached data of a file to storage. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsync(file.fd).then(() => {
    console.info(`Succeeded in syncing data.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.fsync

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes the cached data of a file to storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the cache data of the file system is successfully written to the disk, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsync(file.fd, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to sync. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in syncing.`);
    }
    fileIo.closeSync(file);
  });
  ```


## fileIo.fsyncSync

fsyncSync(fd: number): void

Synchronizes the cached data of a file to storage. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsyncSync(file.fd);
  fileIo.closeSync(file);
  ```

## fileIo.fdatasync

fdatasync(fd: number): Promise&lt;void&gt;

Synchronizes data in a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasync(file.fd).then(() => {
    console.info(`Succeeded in syncing data.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.fdatasync

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes data in a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file data is successfully synchronized, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasync(file.fd, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in syncing data.`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.fdatasyncSync

fdatasyncSync(fd: number): void

Synchronizes the data of a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasyncSync(file.fd);
  fileIo.closeSync(file);
  ```

## fileIo.symlink

symlink(target: string, srcPath: string): Promise&lt;void&gt;

Creates a symbolic link based on a file path. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 11, this API cannot be used by third-party applications.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| target | string | Yes| Application sandbox path of the target file.|
| srcPath | string | Yes| Application sandbox path of the symbolic link.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlink(srcFile, dstFile).then(() => {
    console.info(`Succeeded in creating symbolic link.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create symbolic link. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.symlink
symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on a file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Since API version 11, this API cannot be used by third-party applications.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| target | string | Yes| Application sandbox path of the target file.|
| srcPath | string | Yes| Application sandbox path of the symbolic link.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the symbolic link is successfully created, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlink(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to create symbolic link. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating symbolic link.`);
    }
  });
  ```

## fileIo.symlinkSync

symlinkSync(target: string, srcPath: string): void

Creates a symbolic link based on the file path. This API returns the result synchronously.

> **NOTE**
>
> Since API version 11, this API cannot be used by third-party applications.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| target | string | Yes| Application sandbox path of the target file.|
| srcPath | string | Yes| Application sandbox path of the symbolic link.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlinkSync(srcFile, dstFile);
  ```

## fileIo.listFile
listFile(path: string, options?: ListFileOptions): Promise<string[]>

Lists the names of all files and directories in the current path. Filtering is supported. This API uses a promise to return the result.

This API supports recursively listing the relative paths of all files by setting **recursion** in **ListFileOptions**. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| options | [ListFileOptions](#listfileoptions11) | No| Options for filtering files. The files are not filtered by default.|


**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string[]&gt; | Promise used to return the file name array, which is encoded in UTF-8 format by default.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Filter, ListFileOptions } from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  }
  fileIo.listFile(pathDir, listFileOption).then((filenames: Array<string>) => {
    console.info(`Succeeded in listing file.`);
    for (let i = 0; i < filenames.length; i++) {
      console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.listFile
listFile(path: string, callback: AsyncCallback<string[]>): void

Lists the names of all files and directories in the current path. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| callback | AsyncCallback&lt;string[]&gt; | Yes| Callback used to return the file name array, which is encoded in UTF-8 format by default.|


**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.listFile(pathDir, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in listing file.`);
      for (let i = 0; i < filenames.length; i++) {
        console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
      }
    }
  });
  ```

## fileIo.listFile
listFile(path: string, options: ListFileOptions, callback: AsyncCallback&lt;string[]&gt;): void

Lists the names of all files and directories in the current path. Filtering is supported. This API uses an asynchronous callback to return the result.

This API supports recursively listing the relative paths of all files by setting **recursion** in **ListFileOptions**. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| options | [ListFileOptions](#listfileoptions11) | Yes| Options for filtering files.|
| callback | AsyncCallback&lt;string[]&gt; | Yes| Callback used to return the file name array, which is encoded in UTF-8 format by default.|


**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Filter, ListFileOptions } from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  fileIo.listFile(pathDir, listFileOption, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in listing file.`);
      for (let i = 0; i < filenames.length; i++) {
        console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
      }
    }
  });
  ```

## fileIo.listFileSync

listFileSync(path: string, options?: ListFileOptions): string[]

Lists the names of all files and directories in the current directory. This API returns the result synchronously. Filtering is supported.

This API supports recursively listing the relative paths of all files by setting **recursion** in **ListFileOptions**. The relative path starts with a slash (/).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| options | [ListFileOptions](#listfileoptions11) | No| Options for filtering files. The files are not filtered by default.|


**Return value**

| Type| Description|
| ---- | ---- |
| string[] | File name array, which is encoded in UTF-8 format by default.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { Filter, ListFileOptions} from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  let filenames = fileIo.listFileSync(pathDir, listFileOption);
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
  ```

## fileIo.listFileExt

listFileExt(path: string, options?: ListFileExtOptions): Promise&lt;string[]&gt;

Lists all files in a directory. This API supports recursive listing of files and file filtering. This API uses a promise to return the result.

You can configure the **recursion** parameter in **options** to recursively list the relative paths of all files. The relative path starts with a slash (/).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| options | [ListFileExtOptions](#listfileextoptions) | No| Options for listing files. The default value is empty, indicating no recursive listing of files or file filtering and no limit on the number of files to be listed.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string[]&gt; | Promise used to return the files names listed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo, ListFileExtOptions, FileFilter } from '@kit.CoreFileKit';

let filter: FileFilter = {
  filter: (name: string): boolean => {
    return name.endsWith('.txt');
  }
};
let options: ListFileExtOptions = {
  recursion: false,
  listNum: 0,
  fileFilter: filter
};
fileIo.listFileExt(pathDir, options).then((filenames: Array<string>) => {
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
}).catch((error: Error) => {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
});
```

## fileIo.listFileExtSync

listFileExtSync(path: string, options?: ListFileExtOptions): string[]

Lists all files in a directory. This API supports recursive listing of files and file filtering and returns the result synchronously.

You can configure the **recursion** parameter in **options** to recursively list the relative paths of all files. The relative path starts with a slash (/).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the directory.|
| options | [ListFileExtOptions](#listfileextoptions) | No| Options for listing files. The default value is empty, indicating no recursive listing of files or file filtering and no limit on the number of files to be listed.|

**Return value**

| Type| Description|
| ---- | ---- |
| string[] | File names listed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo, ListFileExtOptions, FileFilter } from '@kit.CoreFileKit';

let filter: FileFilter = {
  filter: (name: string): boolean => {
    return name.endsWith('.txt');
  }
};
let options: ListFileExtOptions = {
  recursion: false,
  listNum: 0,
  fileFilter: filter
};
try {
  let filenames = fileIo.listFileExtSync(pathDir, options);
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.lseek<sup>11+</sup>

lseek(fd: number, offset: number, whence?: WhenceType): number

Adjusts the position of the file offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| File descriptor.|
| offset | number | Yes| Relative offset, in bytes.|
| whence | [WhenceType](#whencetype11) | No| Where to start the offset. If this parameter is not specified, the file start position is used by default.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Position of the current offset as measured from the beginning of the file, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let offset = fileIo.lseek(file.fd, 5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, the current offset is at ${offset}`);
  fileIo.closeSync(file);
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode?: number): Promise\<void>

Moves the source directory to the destination directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | No| Move mode. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a non-empty directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, 1).then(() => {
    console.info(`Succeeded in moving directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

Moves the source directory to the destination directory. You can set the move mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | Yes| Move mode.<br><br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully moved, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
fileIo.moveDir(srcPath, destPath, 1, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in moving directory.`);
  }
});
```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves the source directory to the destination directory. You can set the move mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | Yes| Move mode.<br><br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes| Callback used to return the result. If the directory is successfully moved, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, 1, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving directory.`);
    }
  });
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void>): void

Moves the source directory to the destination directory. This API uses an asynchronous callback to return the result.

An exception will be thrown if a directory conflict occurs, that is, the destination directory contains a directory with the same name as the source directory.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the directory is successfully moved, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
fileIo.moveDir(srcPath, destPath, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in moving directory.`);
  }
});
```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

Moves the source directory to the destination directory. This API uses an asynchronous callback to return the result.

An exception will be thrown if a directory conflict occurs, that is, the destination directory contains a directory with the same name as the source directory.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | Yes| Callback used to return the result. If the directory is successfully moved, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving directory.`);
    }
  });
  ```

## fileIo.moveDirSync<sup>10+</sup>

moveDirSync(src: string, dest: string, mode?: number): void

Moves the source directory to the destination directory. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the source directory.|
| dest | string | Yes| Application sandbox path of the destination directory.|
| mode | number | No| Move mode. The default value is **0**.<br>- **0**: Throw an exception if a directory conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory.<br>- **1**: Throw an exception if a file conflict occurs.<br> An exception will be thrown if the destination directory contains a directory with the same name as the source directory, and a file with the same name exists in the conflict directory. All the non-conflicting files in the source directory will be moved to the destination directory, and the non-conflicting files in the destination directory will be retained. The data attribute in the error returned provides information about the conflicting files in the Array\<[ConflictFiles](#conflictfiles10)> format.<br>- **2**: Forcibly overwrite the conflicting files in the destination directory.<br> When the destination directory contains a directory with the same name as the source directory, the files with the same names in the destination directory are overwritten forcibly; the files without conflicts in the destination directory are retained.<br>- **3**: Forcibly overwrite the conflicting directory.<br> The source directory is moved to the destination directory, and the content of the moved directory is the same as that of the source directory. If the destination directory contains a directory with the same name as the source directory, all original files in the directory will be deleted.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ConflictFiles } from '@kit.CoreFileKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
try {
  fileIo.moveDirSync(srcPath, destPath, 1);
  console.info(`Succeeded in moving directory.`);
} catch (error) {
  let err: BusinessError<Array<ConflictFiles>> = error as BusinessError<Array<ConflictFiles>>;
  if (err.code == 13900015 && err.data?.length !== undefined) {
    for (let i = 0; i < err.data.length; i++) {
      console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
    }
  } else {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## fileIo.moveFile

moveFile(src: string, dest: string, mode?: number): Promise\<void>

Moves a file This API uses a promise to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the file to move.|
| dest | string | Yes| Application sandbox path of the destination file.|
| mode | number | No| Move mode.<br> The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, 0).then(() => {
    console.info(`Succeeded in moving file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.moveFile

moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

Moves a file with the specified mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the file to move.|
| dest | string | Yes| Application sandbox path of the destination file.|
| mode | number | Yes| Move mode.<br> The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is moved successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, 0, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving file.`);
    }
  });
  ```

## fileIo.moveFile

moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void

Moves a file and forcibly overwrites the file with the same name in the destination directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the file to move.|
| dest | string | Yes| Application sandbox path of the destination file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is moved successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving file.`);
    }
  });
  ```

## fileIo.moveFileSync

moveFileSync(src: string, dest: string, mode?: number): void

Moves a file. This API returns the result synchronously.

> **NOTE**
>
> This API is not supported in a distributed directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| src | string | Yes| Application sandbox path of the file to move.|
| dest | string | Yes| Application sandbox path of the destination file.|
| mode | number | No| Move mode.<br> The value **0** means to overwrite the file with the same name in the destination directory; the value **1** means to throw an exception. The default value is **0**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFileSync(srcPath, destPath, 0);
  console.info(`Succeeded in moving file.`);
  ```

## fileIo.mkdtemp

mkdtemp(prefix: string): Promise&lt;string&gt;

Create a temporary directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| prefix | string | Yes| String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string&gt; | Promise used to return the unique directory generated.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.mkdtemp(pathDir + "/XXXXXX").then((dir: string) => {
    console.info(`Succeeded in making temporary directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make temporary directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdtemp

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

Create a temporary directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| prefix | string | Yes| String to be replaced with six randomly generated characters to create a unique temporary directory.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the temporary directory.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {
    if (err) {
      console.error(`Failed to make temporary directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making temporary directory.`);
    }
  });
  ```

## fileIo.mkdtempSync

mkdtempSync(prefix: string): string

Creates a temporary directory. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| prefix | string | Yes| String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

| Type| Description|
| ---- | ---- |
| string | Unique directory generated.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let res = fileIo.mkdtempSync(pathDir + "/XXXXXX");
  ```

## fileIo.mmap

mmap(file: number | File, mode: MappingMode, offset: number, size: number): Promise&lt;FileMapping&gt;

Creates a file mapping object based on a file descriptor or file object for efficient read and write access to files. This API uses a promise to return the result.

> **NOTE**
>
> 1. Memory mapping can be performed only for regular files. Non-regular files, such as pipeline, socket, and device files, are not supported. You can use [statSync()](#fileiostatsync) to obtain file attributes and then call [Stat.isFile()](#isfile) to check whether the file is a regular file.
> 2. If the mapping range exceeds the raw file size and the write permission is granted for the file, the mapping file size will be automatically expanded.
> 3. For files from external storage or network files, the establishment of mappings and access to the mapped memory are not guaranteed due to differences in the underlying file system. This may cause the application to terminate unexpectedly. You are advised to use other file access APIs such as [read](#fileioread), [write](#fileiowrite), or [Stream](#stream) in this scenario.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | Yes| **File** object or FD of the file to close.|
| mode | [MappingMode](#mappingmode) | Yes| Option to create a file memory-mapped object. You must specify one of the following options:<br>- **MappingMode.READ_ONLY(0)**: read-only mode. The file mapping area is not writable. An exception is thrown when the file mapping area is modified.<br>- **MappingMode.READ_WRITE(1)**: read/write mode. The modification is written to the file mapping area and then synchronized to the file by the operating system (non-real-time).<br>- **MappingMode.PRIVATE(2)**: private mode. It is a copy-on-write mapping mechanism. Modifications to the mapping area are visible only to the current process and do not affect the raw file.|
| offset | number | Yes| Start position of the file mapping area, in bytes.|
| size | number | Yes| Size of the file mapping area, in bytes. The value ranges from 0 to **INT32_MAX**.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[FileMapping](#filemapping)&gt; | Promise used to return the file mapping object. Initial state of the returned object: The value of **position** is **0**, and the values of **limit** and **capacity** are equal to the value of **size**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
fileIo.mmap(file, fileIo.MappingMode.READ_WRITE, 0, 1024).then((mapping: fileIo.FileMapping) => {
  console.info(`Succeeded in mmap`);
  mapping.unmapSync();
}).catch((err: BusinessError) => {
  console.error(`Failed to mmap. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fileIo.closeSync(file);
});
```

## fileIo.mmapSync

mmapSync(file: number | File, mode: MappingMode, offset: number, size: number): FileMapping

Creates a file mapping object synchronously based on a file descriptor or file object for efficient read and write access to files.

> **NOTE**
>
> 1. Memory mapping can be performed only for regular files. Non-regular files, such as pipeline, socket, and device files, are not supported. You can use [statSync()](#fileiostatsync) to obtain file attributes and then call [Stat.isFile()](#isfile) to check whether the file is a regular file.
> 2. If the mapping range exceeds the raw file size and the write permission is granted for the file, the mapping file size will be automatically expanded.
> 3. For files from external storage or network files, the establishment of mappings and access to the mapped memory are not guaranteed due to differences in the underlying file system. This may cause the application to terminate unexpectedly. You are advised to use other file access APIs such as [read](#fileioread), [write](#fileiowrite), or [Stream](#stream) in this scenario.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | Yes| **File** object or FD of the file to close.|
| mode | [MappingMode](#mappingmode) | Yes| Option to create a file memory-mapped object. You must specify one of the following options:<br>- **MappingMode.READ_ONLY(0)**: read-only mode. The file mapping area is not writable. An exception is thrown when the file mapping area is modified.<br>- **MappingMode.READ_WRITE(1)**: read/write mode. The modification is written to the file mapping area and then synchronized to the file by the operating system (non-real-time).<br>- **MappingMode.PRIVATE(2)**: private mode. It is a copy-on-write mapping mechanism. Modifications to the mapping area are visible only to the current process and do not affect the raw file.|
| offset | number | Yes| Start position of the file mapping area, in bytes.|
| size | number | Yes| Size of the file mapping area, in bytes. The value ranges from 0 to **INT32_MAX**.|

**Return value**

| Type| Description|
| ---- | ---- |
| [FileMapping](#filemapping) | File mapping object created. Initial state of the returned object: The value of **position** is **0**, and the values of **limit** and **capacity** are equal to the value of **size**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
console.info("Succeeded in mmapSync.");
mapping.unmapSync();
fileIo.closeSync(file);
```

## fileIo.utimes<sup>11+</sup>

utimes(path: string, mtime: number): void

Last modification time of a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| mtime | number | Yes| New timestamp. The value is the number of milliseconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970). Only the time when the file was last modified can be changed.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.writeSync(file.fd, 'test data');
  fileIo.closeSync(file);
  fileIo.utimes(filePath, new Date().getTime());
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

Creates a **RandomAccessFile** instance in read-only mode based on a file path or file object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | Yes| Application sandbox path of the file or an opened file object.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile10)&gt; | Yes| Callback used to return the **RandomAccessFile** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.createRandomAccessFile(file, (err: BusinessError, randomAccessFile: fileIo.RandomAccessFile) => {
    if (err) {
      console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
      randomAccessFile.close();
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode: number, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

Creates a **RandomAccessFile** instance based on a file path or file object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | Yes| Application sandbox path of the file or an opened file object.|
| mode | number | Yes| [OpenMode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile10)&gt; | Yes| Callback used to return the **RandomAccessFile** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.createRandomAccessFile(file, fileIo.OpenMode.READ_ONLY, (err: BusinessError, randomAccessFile: fileIo.RandomAccessFile) => {
    if (err) {
      console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
      randomAccessFile.close();
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode?: number, options?: RandomAccessFileOptions): Promise&lt;RandomAccessFile&gt;

Creates a **RandomAccessFile** instance based on a file path or file object. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | Yes| Application sandbox path of the file or an opened file object.|
| mode | number | No| [OpenMode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
|options<sup>12+</sup>|[RandomAccessFileOptions](#randomaccessfileoptions12)|No|The options are as follows:<br>- **start** (number): start offset position of the file, in bytes. This parameter is optional. The default value is the current position of the file.<br>- **end** (number): end offset position of the file, in bytes. This parameter is optional. The default value is the end of the file.<br>This parameter takes effect only for file stream objects obtained by [getreadstream](#getreadstream12) and [getwritestream](#getwritestream12).|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[RandomAccessFile](#randomaccessfile10)&gt; | Promise used to return the **RandomAccessFile** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
fileIo.createRandomAccessFile(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE, { start: 10, end: 100 })
  .then((randomAccessFile: fileIo.RandomAccessFile) => {
    console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
    randomAccessFile.close();
  })
  .catch((err: BusinessError) => {
    console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
  });
```


## fileIo.createRandomAccessFileSync<sup>10+</sup>

createRandomAccessFileSync(file: string | File, mode?: number, options?: RandomAccessFileOptions): RandomAccessFile

Creates a **RandomAccessFile** instance based on a file path or file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | Yes| Application sandbox path of the file or an opened file object.|
| mode | number | No| [OpenMode](#openmode) for creating the **RandomAccessFile** instance. This parameter is valid only when the application sandbox path of the file is passed in. One of the following options must be specified:<br>- **OpenMode.READ_ONLY(0o0)**: Create the file in read-only mode. This is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: Create the file in write-only mode.<br>- **OpenMode.READ_WRITE(0o2)**: Create the file in read/write mode.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the **RandomAccessFile** object already exists and is created in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Create the file in append mode. New data will be added to the end of the **RandomAccessFile** object. <br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Create a **RandomAccessFile** instance in synchronous I/O mode.|
|options<sup>12+</sup>|[RandomAccessFileOptions](#randomaccessfileoptions12)|No|The options are as follows:<br>- **start** (number): start offset position of the file, in bytes. This parameter is optional. The default value is the current position of the file.<br>- **end** (number): end offset position of the file, in bytes. This parameter is optional. The default value is the end of the file.<br>This parameter takes effect only for file stream objects obtained by [getreadstream](#getreadstream12) and [getwritestream](#getwritestream12).|

**Return value**

| Type| Description|
| ---- | ---- |
| [RandomAccessFile](#randomaccessfile10) | **RandomAccessFile** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE,
    { start: 10, end: 100 });
  randomAccessFile.close();
  ```

## fileIo.createStream

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Creates a stream based on a file path. This API uses a promise to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the stream result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.createStream(filePath, "a+").then((stream: fileIo.Stream) => {
    stream.closeSync();
    console.info(`Succeeded in creating stream.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create stream. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.createStream

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Creates a stream based on a file path. To close the stream, use **close()** of [Stream](#stream). This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes| Callback used to return the **Stream** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.createStream(filePath, "r+", (err: BusinessError, stream: fileIo.Stream) => {
    if (err) {
      console.error(`Failed to create stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      stream.closeSync();
      console.info(`Succeeded in creating stream.`);
    }
  })
  ```

## fileIo.createStreamSync

createStreamSync(path: string, mode: string): Stream

Creates a stream based on a file path. This API returns the result synchronously. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type| Description|
| ---- | ---- |
| [Stream](#stream) | File stream.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  console.info(`Succeeded in creating stream.`);
  stream.closeSync();
  ```


## fileIo.fdopenStream

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a file stream based on the file descriptor. This API uses a promise to return the result. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the stream result.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdopenStream(file.fd, "r+").then((stream: fileIo.Stream) => {
    console.info(`Succeeded in opening stream.`);
    stream.closeSync();
  }).catch((err: BusinessError) => {
    console.error(`Failed to open stream. Code: ${err.code}, message: ${err.message}`);
    // If the file stream fails to be opened, the FD must be manually closed.
    fileIo.closeSync(file);
  });
  ```

> **NOTE**
>
> When a file stream created with an FD is used, the lifecycle of the FD will be managed by the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fileIo.fdopenStream

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a stream based on the file descriptor. To close the stream, use **close()** of [Stream](#stream). This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes| Callback used to return the **Stream** object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
  fileIo.fdopenStream(file.fd, "r+", (err: BusinessError, stream: fileIo.Stream) => {
    if (err) {
      console.error(`Failed to fdopen stream. Code: ${err.code}, message: ${err.message}`);
      // If the file stream fails to be opened, the FD must be manually closed.
      fileIo.closeSync(file);
    } else {
      console.info(`Succeeded in fdopening stream.`);
      stream.closeSync();
    }
  });
  ```

> **NOTE**
>
> If a file stream is created with an FD, the lifecycle of the FD is also transferred to the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fileIo.fdopenStreamSync

fdopenStreamSync(fd: number, mode: string): Stream

Opens a stream based on an FD. This API returns the result synchronously. To close the stream, use **close()** of [Stream](#stream).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| fd | number | Yes| FD of the file.|
| mode | string | Yes| - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type| Description|
| ---- | ---- |
| [Stream](#stream) | File stream.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
  let stream = fileIo.fdopenStreamSync(file.fd, "r+");
  stream.closeSync();
  ```

> **NOTE**
>
> If a file stream is created with an FD, the lifecycle of the FD is also transferred to the file stream object. When **close()** is called to close the file stream, the FD is also closed.

## fileIo.createReadStream<sup>12+</sup>

createReadStream(path: string, options?: ReadStreamOptions ): ReadStream

Creates a readable stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Path of the file.|
| options | [ReadStreamOptions](#readstreamoptions12) | No| The options are as follows:<br>- **start** (number): start position to read data, in bytes. This parameter is optional. By default, data is read from the current position.<br>- **end** (number): end position to read data, in bytes. This parameter is optional. The default value is the end of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  // Create a readable stream.
  const rs = fileIo.createReadStream(`${pathDir}/read.txt`);
  // Create a writeable stream.
  const ws = fileIo.createWriteStream(`${pathDir}/write.txt`);
  // Copy files in paused mode.
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
  ```

## fileIo.createWriteStream<sup>12+</sup>

createWriteStream(path: string, options?: WriteStreamOptions): WriteStream

Creates a writeable stream. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Path of the file.|
| options | [WriteStreamOptions](#writestreamoptions12) | No| The options are as follows:<br>- **start** (number): start position to write the data, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **mode** (number): [OpenMode](#openmode) for creating the writeable stream. This parameter is optional. The default value is the write-only mode.|

**Return value**

| Type| Description|
| ---- | ---- |
| [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  // Create a readable stream.
  const rs = fileIo.createReadStream(`${pathDir}/read.txt`);
  // Create a writeable stream.
  const ws = fileIo.createWriteStream(`${pathDir}/write.txt`);
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

Creates an **AtomicFile** instance for a file in a specified path.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file.|

### getBaseFile<sup>15+</sup>

getBaseFile(): File

Obtains the file object through the **AtomicFile** object.

The FD needs to be closed by calling **close()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [File](#file) | File object opened.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let atomicFile = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = atomicFile.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    atomicFile.finishWrite();
    let file = atomicFile.getBaseFile();
    console.info(`Succeeded in getting base file. fd: ${file.fd}, path: ${file.path}, name:${file.name}`);
  })
} catch (err) {
  console.error(`Failed to get baseFile. Code: ${err.code}, message: ${err.message}`);
}
```

### openRead<sup>15+</sup>

openRead(): ReadStream

Creates a **ReadStream** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let readStream = file.openRead();
      readStream.on('readable', () => {
        const data = readStream.read();
        if (!data) {
          console.error(`Failed to read atomicfile, data is null.`);
          return;
        }
        console.info(`Succeeded in reading atomicfile, data is: ${data}`);
      });
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### readFully<sup>15+</sup>

readFully(): ArrayBuffer

Reads all content of a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| ArrayBuffer | Full content of a file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { util, buffer } from '@kit.ArkTS';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      console.info(`Succeeded in reading atomicfile fully, str is: ${str}`);
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### startWrite<sup>15+</sup>

startWrite(): WriteStream

Starts to write new file data in the **WriteStream** object returned.

If the file does not exist, create a file.

Call **finishWrite()** if the write operation is successful; call **failWrite()** if the write operation fails.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    console.info(`Succeeded in writing atomicfile finished.`);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### finishWrite<sup>15+</sup>

finishWrite(): void

Finishes writing file data when the write operation is complete.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### failWrite<sup>15+</sup>

failWrite(): void

Rolls back the file after the file fails to be written.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
try {
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    console.info(`Succeeded in writing atomicFile.`);
  })
} catch (err) {
  file.failWrite();
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### delete<sup>15+</sup>

delete(): void

Deletes the **AtomicFile** class, including the original files and temporary files.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { util } from '@kit.ArkTS';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      file.delete();
      console.info(`Succeeded in delete atomicfile.`);
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.createWatcher<sup>10+</sup>

createWatcher(path: string, events: number, listener: WatchEventListener): Watcher

Creates a **Watcher** object to listen for file or directory changes.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Application sandbox path of the file or directory to observe.|
| events | number | Yes| Events to observe. Multiple events can be separated by vertical bars (\|).<br>- **0x1: IN_ACCESS**: A file is accessed.<br>- **0x2: IN_MODIFY**: The file content is modified.<br>- **0x4: IN_ATTRIB**: The file metadata is modified.<br>- **0x8: IN_CLOSE_WRITE**: A file is opened, written with data, and then closed.<br>- **0x10: IN_CLOSE_NOWRITE**: A file or directory is opened and then closed without data written.<br>- **0x20: IN_OPEN**: A file or directory is opened.<br>- **0x40: IN_MOVED_FROM**: A file in the observed directory is moved.<br>- **0x80: IN_MOVED_TO**: A file is moved to the observed directory.<br>- **0x100: IN_CREATE**: A file or directory is created in the observed directory.<br>- **0x200: IN_DELETE**: A file or directory is deleted from the observed directory.<br>- **0x400: IN_DELETE_SELF**: The observed directory is deleted. After the directory is deleted, the listening stops.<br>- **0x800: IN_MOVE_SELF**: The observed file or directory is moved. After the file or directory is moved, the listening continues.<br>- **0xfff: IN_ALL_EVENTS**: All events.|
| listener | [WatchEventListener](#watcheventlistener10) | Yes| Callback invoked when an observed event occurs. The callback will be invoked each time an observed event occurs.|

**Return value**

| Type| Description|
| ---- | ---- |
| [Watcher](#watcher10) | **Watcher** object created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

<!--code_no_check-->
  ```ts
  import { common } from '@kit.AbilityKit';
  import { WatchEvent } from '@kit.CoreFileKit';

  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let pathDir = context.filesDir;
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let watcher = fileIo.createWatcher(filePath, 0x2 | 0x10, (watchEvent: WatchEvent) => {
    if (watchEvent.event == 0x2) {
      console.info(watchEvent.fileName + ' was modified');
    } else if (watchEvent.event == 0x10) {
      console.info(watchEvent.fileName + ' was closed');
    }
  });
  watcher.start();
  fileIo.writeSync(file.fd, 'test');
  fileIo.closeSync(file);
  watcher.stop();
  ```

## WatchEventListener<sup>10+</sup>

(event: WatchEvent): void

Provides APIs for observing events.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| event | [WatchEvent](#watchevent10) | Yes| Event for the callback to invoke.|

## WatchEvent<sup>10+</sup>

Defines the event to observe.

### Properties

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| fileName | string | Yes| No| Sandbox path of the file to observe. The sandbox path contains the file name.|
| event | number | Yes| No| Events to observe. Multiple events can be separated by vertical bars (\|).<br>- **0x1: IN_ACCESS**: A file is accessed.<br>- **0x2: IN_MODIFY**: The file content is modified.<br>- **0x4: IN_ATTRIB**: The file metadata is modified.<br>- **0x8: IN_CLOSE_WRITE**: A file is opened, written with data, and then closed.<br>- **0x10: IN_CLOSE_NOWRITE**: A file or directory is opened and then closed without data written.<br>- **0x20: IN_OPEN**: A file or directory is opened.<br>- **0x40: IN_MOVED_FROM**: A file in the observed directory is moved.<br>- **0x80: IN_MOVED_TO**: A file is moved to the observed directory.<br>- **0x100: IN_CREATE**: A file or directory is created in the observed directory.<br>- **0x200: IN_DELETE**: A file or directory is deleted from the observed directory.<br>- **0x400: IN_DELETE_SELF**: The observed directory is deleted. After the directory is deleted, the listening stops.<br>- **0x800: IN_MOVE_SELF**: The observed file or directory is moved. After the file or directory is moved, the listening continues.<br>- **0xfff: IN_ALL_EVENTS**: All events.|
| cookie | number | Yes| No| Cookie bound with the event.<br> Currently, only the **IN_MOVED_FROM** and **IN_MOVED_TO** events are supported. The **IN_MOVED_FROM** and **IN_MOVED_TO** events of the same file have the same **cookie** value.|

## Progress<sup>11+</sup>

Defines the copy progress information.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| processedSize | number | Yes| No| Size of the copied data, in bytes.|
| totalSize | number | Yes| No| Total size of the data to be copied, in bytes.|

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
import { fileUri } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";
let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);
let copySignal = new fileIo.TaskSignal;
let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  if (progress.processedSize / progress.totalSize > 0.5) {
    copySignal.cancel();
    console.info("copy cancel.");
  }
};
let options: fileIo.CopyOptions = {
  "progressListener" : progressListener,
  "copySignal" : copySignal,
}

try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, options, (err: BusinessError) => {
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

### onCancel<sup>(deprecated)</sup>

onCancel(): Promise&lt;string&gt;

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 24.

Subscribes to the event reported when a copy task is canceled.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;string&gt; | Promise used to return the path of the last file copied.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { TaskSignal } from '@kit.CoreFileKit';

let copySignal: fileIo.TaskSignal = new TaskSignal();
copySignal.onCancel();
```

## CopyOptions<sup>11+</sup>

Defines the callback for listening for the copy progress.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| progressListener | [ProgressListener](#progresslistener11) | No| Yes| Listener used to observe the copy progress.|
| copySignal | [TaskSignal](#tasksignal12) | No| Yes| Signal used to cancel a copy task.|

## ProgressListener<sup>11+</sup>

type ProgressListener = (progress: Progress) => void

Listener used to observe the copy progress.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| progress | [Progress](#progress11) | Yes| Listener used to observe the copy progress.|

**Example**

  ```ts
  import { TaskSignal } from '@kit.CoreFileKit';

  let copySignal: fileIo.TaskSignal = new TaskSignal();
  let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
    console.info(`processedSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyOption: fileIo.CopyOptions = {
    "progressListener" : progressListener,
    "copySignal" : copySignal,
  }
  ```

## Stat

Represents detailed file information. Before calling any API of the **Stat()** class, use [stat()](#fileiostat) to create a **Stat** instance.

### Properties

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| ino | bigint | Yes| No| File ID. Different files on the same device have different **ino**s.|
| mode | number | Yes| No| File permissions. The meaning of each bit is as follows:<br>Note: The following values are in octal format. The return values are in decimal format. You need to convert the values.<br>- **0o400**: The user has the read permission on a regular file or a directory entry.<br>- **0o200**: The user has the permission to write a regular file or create and delete a directory entry.<br>- **0o100**: The user has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o040**: The user group has the read permission on a regular file or a directory entry.<br>- **0o020**: The user group has the permission to write a regular file or create and delete a directory entry.<br>- **0o010**: The user group has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o004**: Other users have the permission to read a regular file or read a directory entry.<br>- **0o002**: Other users have the permission to write a regular file or create and delete a directory entry.<br>- **0o001**: Other users have the permission to execute a regular file or search for the specified path in a directory.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uid | number | Yes| No| ID of the file owner.|
| gid | number | Yes| No| ID of the user group of the file.|
| size | number | Yes| No| File size, in bytes. This parameter is valid only for regular files.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| atime | number | Yes| No| Time when the file was last accessed. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.<br>**Note**: Currently, user data partitions are mounted in **noatime** mode by default, and **atime** update is disabled.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| mtime | number | Yes| No| Time when the file content was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ctime | number | Yes| No| Time when the file metadata was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.|
| atimeNs<sup>15+</sup> | bigint | Yes| Yes| Time of the last access to the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.<br>**Note**: Currently, user data partitions are mounted in **noatime** mode by default, and **atime** update is disabled.|
| mtimeNs<sup>15+</sup> | bigint | Yes| Yes| Time of the last modification to the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.|
| ctimeNs<sup>15+</sup> | bigint | Yes| Yes| Time of the last status change of the file. The value is the number of nanoseconds elapsed since 00:00:00 on January 1, 1970.|
| location<sup>11+</sup> | [LocationType](#locationtype11)| Yes|No| File location, which indicates whether the file is stored in a local device or in the cloud.|

> **NOTE**
>
> Some properties in **Stat** are only supported for common files. You can use the [isFile()](#isfile) API to check whether a file is a common file.

### isBlockDevice

isBlockDevice(): boolean

Checks whether this file is a block special file. A block special file supports access by block only, and it is cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a block special file. The value **true** means the file is a block special file; the value **false** means the file is not a block special file.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fileIo.statSync(filePath).isBlockDevice();
  ```

### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this file is a character special file. A character special device supports random access, and it is not cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a character special device. The value **true** means the file is a character special device; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fileIo.statSync(filePath).isCharacterDevice();
  ```

### isDirectory

isDirectory(): boolean

Checks whether this file is a directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a directory. The value **true** means the file is a directory; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let dirPath = pathDir + "/test";
  let isDirectory = fileIo.statSync(dirPath).isDirectory();
  ```

### isFIFO

isFIFO(): boolean

Checks whether this file is a named pipe (or FIFO). Named pipes are used for inter-process communication.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is an FIFO. The value **true** means the file is an FIFO; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFIFO = fileIo.statSync(filePath).isFIFO();
  ```

### isFile

isFile(): boolean

Checks whether this file is a regular file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a regular file. The value **true** means that the file is a regular file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFile = fileIo.statSync(filePath).isFile();
  ```

### isSocket

isSocket(): boolean

Checks whether this file is a socket.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a socket. The value **true** means that the file is a socket; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSocket = fileIo.statSync(filePath).isSocket();
  ```

### isSymbolicLink

isSymbolicLink(): boolean

Checks whether this file is a symbolic link.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is a symbolic link. The value **true** means that the file is a symbolic link; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSymbolicLink = fileIo.statSync(filePath).isSymbolicLink();
  ```

## Stream

Provides API for stream operations. Before calling any API of **Stream**, you need to create a **Stream** instance by using [fileIo.createStream](#fileiocreatestream) or [fileIo.fdopenStream](#fileiofdopenstream).

### close

close(): Promise&lt;void&gt;

Closes a stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.close().then(() => {
    console.info(`Succeeded in closing file stream.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to close file stream. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### close

close(callback: AsyncCallback&lt;void&gt;): void

Closes the file stream. This API returns the result asynchronously. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file stream is closed successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.close((err: BusinessError) => {
    if (err) {
      console.error(`Failed to close stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in closing stream.`);
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
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.closeSync();
  ```

### flush

flush(): Promise&lt;void&gt;

Flushes all data from this stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flush().then(() => {
    console.info(`Succeeded in flushing.`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to flush. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes the file stream. This API returns the result asynchronously. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file stream is refreshed successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flush((err: BusinessError) => {
    if (err) {
      console.error(`Failed to flush stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in flushing.`);
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
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flushSync();
  stream.close();
  ```

### write

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data to a stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption).then((number: number) => {
    console.info(`Succeeded in writing, size is: ${number}`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### write

write(buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

Writes data to a stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.write("hello, world", (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    stream.close();
  });
  ```

### write

write(buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a stream. Write options can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | Yes| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    stream.close();
  });
  ```

### writeSync

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a stream file. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data in the file, in bytes. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data written in the file, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath,"r+");
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

Reads data from a stream. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption).then((readLen: number) => {
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to read data. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### read

read(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

Reads data from a stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  stream.read(arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
      stream.close();
    }
  });
  ```

### read

read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a stream. Read options can be configured. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | Yes| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
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

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): position of the data to read in the file, in bytes. This parameter is optional. By default, data is read from the current position.<br>|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
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

### Properties

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| fd | number | Yes| No| Indicates the file descriptor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| path<sup>10+</sup> | string | Yes| No| Path of the file.|
| name<sup>10+</sup> | string | Yes| No| Name of the file.|

### getParent<sup>11+</sup>

getParent(): string

Obtains the parent directory of this file object.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| string | Parent directory obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  console.info(`Succeeded in getting parent path, the parent path is: ${file.getParent()}`);
  fileIo.closeSync(file);
  ```

### lock

lock(exclusive?: boolean): Promise\<void>

Applies an exclusive lock or a shared lock on a file in blocking mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| exclusive | boolean | No| Lock to apply.<br> The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock(true).then(() => {
    console.info(`Succeeded in locking file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

### lock

lock(callback: AsyncCallback\<void>): void

Applies a shared lock on a file in blocking mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is locked successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock((err: BusinessError) => {
    if (err) {
      console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in locking file.`);
    }
    fileIo.closeSync(file);
  });
  ```

### lock

lock(exclusive: boolean, callback: AsyncCallback\<void>): void

Applies an exclusive lock or a shared lock on a file in blocking mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| exclusive | boolean | Yes| Whether to apply an exclusive lock. The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the file is locked successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock(true, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in locking file.`);
    }
    fileIo.closeSync(file);
  });
  ```

### tryLock

tryLock(exclusive?: boolean): void

Applies an exclusive lock or a shared lock on this file in non-blocking mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| exclusive | boolean | No| Lock to apply.<br> The value **true** means an exclusive lock, and the value **false** (default) means a shared lock.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.tryLock(true);
  console.info(`Succeeded in locking file.`);
  fileIo.closeSync(file);
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
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.tryLock(true);
  file.unlock();
  console.info(`Succeeded in unlocking file.`);
  fileIo.closeSync(file);
  ```


## FileMapping

Defines a file mapping object. Before calling the **FileMapping** method, construct a **FileMapping** instance using [mmap()](#fileiommap) or [mmapSync()](#fileiommapsync).

**Since**: 26.0.0

### setPosition

setPosition(position: number): void

Sets the current location of the file mapping area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Target position to set, in bytes.<br>The value must be a non-negative number and cannot be greater than the upper bound (**limit**) of the readable and writable area. You can obtain the value of **limit** by calling [getLimit()](#getlimit).|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
mapping.setPosition(100);
console.info("Succeeded in setPosition.");
mapping.unmapSync();
fileIo.closeSync(file);
```

### getPosition

getPosition(): number

Gets the current location of the file mapping area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| number | Current position of the file mapping area, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let pos = mapping.getPosition();
console.info(`Succeeded in getting position, the position is: ${pos}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### capacity

capacity(): number

Obtains the capacity of the file mapping area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| number | Capacity of the file mapping area, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let cap = mapping.capacity();
console.info(`Succeeded in getting capacity, the capacity is: ${cap}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### setLimit

setLimit(limit: number): void

Sets the upper bound of the readable and writable area of the file mapping area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| limit | number | Yes| Upper bound of the readable and writable area to set, in bytes.<br>The value is greater than or equal to 0 and less than or equal to the value of [capacity](#capacity). If the value of **limit** is smaller than that of **position** in the file mapping area, the value of **position** is automatically adjusted to that of **limit**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
mapping.setLimit(512);
console.info("Succeeded in setLimit.");
mapping.unmapSync();
fileIo.closeSync(file);
```

### getLimit

getLimit(): number

Obtains the upper bound of the readable and writable area of the file mapping area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| number | Upper bound of the current readable and writable area, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let lim = mapping.getLimit();
console.info(`Succeeded in getting limit, the limit is: ${lim}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### flip

flip(): void

Flips the file mapping area to switch from the write-ready state to the read-ready state. After this API is called, **limit** is set to the value of **position**, and **position** is reset to **0**.

It is recommended that this API be called to prepare for subsequent [read()](#read-2) operations after the [write()](#write-2) operations are complete.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let writeData = new ArrayBuffer(50);
mapping.write(writeData);
mapping.flip(); // limit=50, position=0
console.info("Succeeded in flip.");

let readBuffer = new ArrayBuffer(50);
mapping.read(readBuffer);

mapping.unmapSync();
fileIo.closeSync(file);
```

### remaining

remaining(): number

Obtains the number of remaining bytes between the current position (**position**) and the upper bound (**limit**) of the readable and writable area.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| number | Number of remaining readable or writable bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

mapping.setPosition(100);
let remaining = mapping.remaining();
console.info(`Succeeded in getting remaining, the remaining is: ${remaining}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### read

read(buffer: ArrayBuffer, length?: number): number

Reads data from the current position and moves the position backward by the number of bytes actually read.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| length | number | No| Length of the data to read, in bytes. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(100);
let bytesRead = mapping.read(buffer);
console.info(`Succeeded in reading data, size is: ${bytesRead}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### read

read(position: number, buffer: ArrayBuffer, length?: number): number

Reads data from the specified position. The current position does not move.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Start position to read the data, in bytes.|
| buffer | ArrayBuffer | Yes| Buffer used to store the file data read.|
| length | number | No| Length of the data to read, in bytes. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(100);
let bytesRead = mapping.read(50, buffer, 50);
console.info(`Succeeded in reading data, size is: ${bytesRead}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### write

write(data: ArrayBuffer, length?: number): number

Writes data from the current position and moves the position backward by the number of bytes actually written.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| data | ArrayBuffer | Yes| Buffer data to be written to the file.|
| length | number | No| Length of the data to write, in bytes. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
let bytesWritten = mapping.write(buffer);
console.info(`Succeeded in writing data to file, size is: ${bytesWritten}`);

mapping.msyncSync();
mapping.unmapSync();
fileIo.closeSync(file);
```

### write

write(position: number, data: ArrayBuffer, length?: number): number

Writes data to the specified position. The current position does not move.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Start position to write, in bytes.|
| data | ArrayBuffer | Yes| Buffer data to be written to the file.|
| length | number | No| Length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
let bytesWritten = mapping.write(50, buffer);
console.info(`Succeeded in writing data to file, size is: ${bytesWritten}`);

mapping.msyncSync();
mapping.unmapSync();
fileIo.closeSync(file);
```

### msync

msync(): Promise&lt;void&gt;

Synchronizes data of the entire file mapping area to the disk file. This API uses a promise to return the result.

> **NOTE**
>
> If the file is not stored on the local device, calling this API does not ensure that all changes are stored persistently.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);

mapping.msync().then(() => {
  console.info("Succeeded in msync.");
}).catch((err: BusinessError) => {
  console.error(`Failed to msync. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  mapping.unmapSync();
  fileIo.closeSync(file);
});
```

### msync

msync(position: number, length: number): Promise&lt;void&gt;

Synchronizes data in the specified range of the file mapping area to the disk file. This API uses a promise to return the result.

> **NOTE**
>
> If the file is not stored on the local device, calling this API does not ensure that all changes are stored persistently.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Start position to synchronize, in bytes.|
| length | number | Yes| Length of the data to synchronize, in bytes.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(50, buffer);

mapping.msync(50, buffer.byteLength).then(() => {
  console.info("Succeeded in msync.");
}).catch((err: BusinessError) => {
  console.error(`Failed to msync. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  mapping.unmapSync();
  fileIo.closeSync(file);
});
```

### msyncSync

msyncSync(): void

Synchronizes data of the entire file mapping area to the disk file synchronously.

> **NOTE**
>
> If the file is not stored on the local device, calling this API does not ensure that all changes are stored persistently.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);

mapping.msyncSync();
console.info("Succeeded in msync.");

mapping.unmapSync();
fileIo.closeSync(file);
```

### msyncSync

msyncSync(position: number, length: number): void

Synchronizes data in the specified range of the file mapping area to the disk file synchronously.

> **NOTE**
>
> If the file is not stored on the local device, calling this API does not ensure that all changes are stored persistently.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Start position to synchronize, in bytes.|
| length | number | Yes| Length of the data to synchronize, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(50, buffer);

mapping.msyncSync(50, buffer.byteLength);
console.info("Succeeded in msync.");

mapping.unmapSync();
fileIo.closeSync(file);
```

### unmap

unmap(): Promise&lt;void&gt;

Releases the file mapping area. This API uses a promise to return the result. After this API is called, **position**, **limit**, and **capacity** are all reset to **0**, and no operation can be performed on the **FileMapping** object.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);
mapping.unmap().then(() => {
  console.info("Succeeded in unmap.");
}).catch((err: BusinessError) => {
  console.error(`Failed to unmap. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fileIo.closeSync(file);
});
```

### unmapSync

unmapSync(): void

Releases the file mapping area synchronously. After this API is called, **position**, **limit**, and **capacity** are all reset to **0**, and no operation can be performed on the **FileMapping** object.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

mapping.unmapSync();
console.info("Succeeded in unmap.");
fileIo.closeSync(file);
```

## DfsListeners<sup>12+</sup>

Provides APIs for observing events. listening for the distributed file system status.

**System capability**: SystemCapability.FileManagement.File.FileIO

### onStatus<sup>12+</sup>

onStatus(networkId: string, status: number): void;

Called to return the specified status. Its parameters are passed in by [connectDfs](#fileioconnectdfs12).

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| networkId | string | Yes| Network ID of the device.|
| status | number | Yes| Status code of the distributed file system. The status code is the error code returned by **onStatus** invoked by **connectDfs**. If the device is abnormal when **connectDfs()** is called, **onStatus** will be called to return the error code:<br>- [13900046](errorcode-filemanagement.md#13900046-connection-interrupted-by-software): The connection is interrupted by software.|

## RandomAccessFile<sup>10+</sup>

Provides APIs for randomly reading and writing a stream. Before invoking any API of **RandomAccessFile**, you need to use **createRandomAccessFile()** to create a **RandomAccessFile** instance synchronously or asynchronously.

### Properties

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| fd | number | Yes| No| FD of the file.|
| filePointer | number | Yes| No| Offset pointer to the **RandomAccessFile** instance, in bytes.|

### setFilePointer<sup>10+</sup>

setFilePointer(filePointer:number): void

Sets the file offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| filePointer | number | Yes| Offset pointer to the **RandomAccessFile** instance, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
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
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  randomAccessFile.close();
  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

Writes data to a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. The default value is the buffer length.<br>- **offset** (number): start position to write the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: 5,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption).then((bytesWritten: number) => {
    console.info(`Succeeded in writing, bytes written: ${bytesWritten}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    randomAccessFile.close();
    fileIo.closeSync(file);
  });

  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
let randomAccessFile = fileIo.createRandomAccessFileSync(file);
let bufferLength: number = 4096;
let arrayBuffer = new ArrayBuffer(bufferLength);
randomAccessFile.write(arrayBuffer, (err: BusinessError, bytesWritten: number) => {
  if (err) {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  } else {
    if (bytesWritten) {
      console.info(`Succeeded in writing, size is: ${bytesWritten}`);
    }
  }
  randomAccessFile.close();
  fileIo.closeSync(file);
});
```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. Write options can be configured. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data written, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: bufferLength,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### writeSync<sup>10+</sup>

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

Writes data to a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | Yes| Data to write. It can be a string or data from a buffer.|
| options | [WriteOptions](#writeoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to write the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is written from the **filePointer**.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data written in the file, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
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

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;number&gt; | Promise used to return the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.read(arrayBuffer, readOption).then((readLength: number) => {
    console.info(`Succeeded in reading, read length: ${readLength}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 20;

  let arrayBuffer = new ArrayBuffer(length);
  randomAccessFile.read(arrayBuffer, (err: BusinessError, readLength: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (readLength) {
        console.info(`Succeeded in reading, size is: ${readLength}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

Reads data from a file. Read options can be configured. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | Yes| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 20;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(length);
  randomAccessFile.read(arrayBuffer, readOption, (err: BusinessError, readLength: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (readLength) {
        console.info(`Succeeded in reading, size is: ${readLength}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### readSync<sup>10+</sup>

readSync(buffer: ArrayBuffer, options?: ReadOptions): number

Reads data from a file. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | Yes| Buffer used to store the file read.|
| options | [ReadOptions](#readoptions11) | No| The options are as follows:<br>- **length** (number): length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.<br>- **offset** (number): start position to read the data, in bytes (it is determined by **filePointer** plus **offset**). This parameter is optional. By default, data is read from the **filePointer**.<br>|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Length of the data read, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 4096;
  let arrayBuffer = new ArrayBuffer(length);
  let readLength = randomAccessFile.readSync(arrayBuffer);
  randomAccessFile.close();
  fileIo.closeSync(file);
  ```

### getReadStream<sup>12+</sup>

getReadStream(): ReadStream

Obtains a **ReadStream** instance of this **RandomAccessFile**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [ReadStream](#readstream12) | **ReadStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const rs = randomAccessFile.getReadStream();
  rs.close();
  randomAccessFile.close();
  ```

### getWriteStream<sup>12+</sup>

getWriteStream(): WriteStream

Obtains a **WriteStream** instance of this **RandomAccessFile**.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type| Description|
| ---- | ---- |
| [WriteStream](#writestream12) | **WriteStream** instance obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
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
  let watcher = fileIo.createWatcher(filePath, 0xfff, () => {});
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
  let watcher = fileIo.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

## OpenMode

Defines the constants of the **mode** parameter used in **open()**. It specifies the mode for opening a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Value| Description|
| ---- | ---- | ---- | ---- |
| READ_ONLY | number | 0o0 | Open the file in read-only mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WRITE_ONLY | number | 0o1 | Open the file in write-only mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| READ_WRITE | number | 0o2 | Open the file in read/write mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CREATE | number | 0o100 | Create a file if the specified file does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| TRUNC | number | 0o1000 | If the file exists and is opened in write-only or read/write mode, truncate the file length to 0.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| APPEND | number | 0o2000 | Open the file in append mode. New data will be written to the end of the file.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| NONBLOCK | number | 0o4000 | If **path** points to a named pipe (FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.|
| DIR | number | 0o200000 | If **path** does not point to a directory, throw an exception.|
| NOFOLLOW | number | 0o400000 | If **path** points to a symbolic link, throw an exception.|
| SYNC | number | 0o4010000 | Open the file in synchronous I/O mode.|
| UNCACHE | number | 0o10000000000 | Disable the page cache for reading and writing a file.<br> **Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## FileFilter

Describes a file name filter, which can be used to customize file name filtering rules.

**Since**: 26.0.0

### filter

filter(name: string): boolean

Filters files of the [listFileExt](#fileiolistfileext) or [listFileExtSync](#fileiolistfileextsync) API and determines whether a specified file name should be included in the returned file list.

> **NOTE**
>
> This function is frequently called. Do not perform time-consuming operations, such as file I/O operations and network requests.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Name or relative path of the file to be filtered. In recursive mode, the value is a relative file path, which starts with a slash (/).|

**Return value**

| Type| Description|
| ---- | ---- |
| boolean | Whether the file is included in the returned file list. The value **true** indicates the file is included, and the value **false** indicates the opposite.|


## MappingMode

Enumerates file memory mapping modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Value| Description|
| ---- | ---- | ---- |
| READ_ONLY | 0 | Read-only mode. The file mapping area is not writable. An exception is thrown when the file mapping area is modified.|
| READ_WRITE | 1 | Read/Write mode. The modification is written to the file mapping area and then synchronized to the file by the operating system (non-real-time).|
| PRIVATE | 2 | Private mode. It is a copy-on-write mapping mechanism. Modifications to the mapping area are visible only to the current process and do not affect the raw file.|

## Filter<sup>10+</sup>

Defines the file filtering configuration used by **listFile()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| suffix | Array&lt;string&gt; | No| Yes| Locate files that fully match the specified file name extensions, which are of the OR relationship.|
| displayName | Array&lt;string&gt; | No| Yes| Locate files that fuzzy match the specified file names, which are of the OR relationship. Currently, only the wildcard * is supported.|
| mimeType | Array&lt;string&gt; | No| Yes| Locate files that fully match the specified MIME types, which are of the OR relationship. This parameter is reserved.|
| fileSizeOver | number | No| Yes| Locate files that are greater than the specified size, in bytes.|
| lastModifiedAfter | number | No| Yes| Locate files whose last modification time is the same or later than the specified time.|
| excludeMedia | boolean | No| Yes| Whether to exclude the files already in **Media**.<br> The value **true** means to exclude the files already in **Media**; the value **false** means not to exclude the files already in **Media**. This parameter is reserved.|

## ConflictFiles<sup>10+</sup>

Defines conflicting file information used in **copyDir()** or **moveDir()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| srcFile | string | No| No| Path of the source file.|
| destFile | string | No| No| Path of the destination file.|

## Options<sup>11+</sup>

Defines the options used in **readLines()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| encoding | string | No| Yes| File encoding format. It is optional.|

## WhenceType<sup>11+</sup>

Enumerates the types of the relative offset position used in **lseek()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Value| Description|
| ---- | ---- | ---- |
| SEEK_SET | 0 | Beginning of the file.|
| SEEK_CUR | 1 | Current offset position.|
| SEEK_END | 2 | End of the file.|

## LocationType<sup>11+</sup>

Enumerates the file locations.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Value| Description|
| ---- | ---- | ---- |
| LOCAL | 1 << 0 | The file is stored in a local device.|
| CLOUD | 1 << 1 | The file is stored in the cloud.|

## AccessModeType<sup>12+</sup>

Enumerates the access modes to verify. If this parameter is left blank, the system checks whether the file exists.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Value| Description|
| ---- | ---- | ---- |
| EXIST | 0 | Whether the file exists.|
| WRITE | 2 | Verify the write permission on the file.|
| READ | 4 | Verify the read permission on the file.|
| READ_WRITE | 6 | Verify the read/write permission on the file.|

## AccessFlagType<sup>12+</sup>

Enumerates the locations of the file to verify.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Value| Description|
| ---- | ---- | ---- |
| LOCAL | 0 | The file is stored locally.|

## ReadOptions<sup>11+</sup>

Defines the options used in **read()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| offset | number | No| Yes| Start position of the file to read, in bytes. This parameter is optional. By default, data is read from the current position.|
| length | number | No| Yes| Length of the data to read, in bytes. This parameter is optional. The default value is the buffer length.|

## ReadTextOptions<sup>11+</sup>

Defines the options used in **readText()**. It inherits from [ReadOptions](#readoptions11).

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| encoding | string | No| Yes| Format of the data to be encoded. This parameter is valid only when the data type is string. The default value is **'utf-8'**, which is the only value supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## WriteOptions<sup>11+</sup>

Defines the options used in **write()**. It inherits from [Options](#options11).

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| offset | number | No| Yes| Start position of the file to write data, in bytes. This parameter is optional. By default, data is written from the current position.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| length | number | No| Yes| Length of the data to write, in bytes. This parameter is optional. The default value is the buffer length.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## ListFileExtOptions

Defines the options used in **listFileExt**.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| recursion | boolean | No| Yes| Whether to list all files in subfolders recursively. The default value is **false**.<br>**false**: The names of files and directories that meet the filtering requirements in the current directory are returned.<br>**true**: Relative paths (starting with /) of all files that meet the filtering requirements in the directory are returned.|
| listNum | number | No| Yes| Number of file names to be listed. The default value is **0**, indicating that all files are listed.|
| fileFilter | [FileFilter](#filefilter) | No| Yes| File name filtering rule. The default value is empty, indicating that no filtering is performed.|

## ListFileOptions<sup>11+</sup>

Defines the options used in **listFile()**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| recursion | boolean | No| Yes| Whether to list all files in the subdirectories recursively. This parameter is optional. The default value is **false**. If **recursion** is **false**, the names of files and directories that meet the filtering requirements in the current directory are returned. If **recursion** is **true**, relative paths (starting with /) of all files that meet the specified conditions in the current directory are returned.|
| listNum | number | No| Yes| Number of file names to list. This parameter is optional. The default value is **0**, which means to list all files.|
| filter | [Filter](#filter10) | No| Yes| File filtering configuration. This parameter is optional. It specifies the file filtering conditions.|

## ReadStream<sup>12+</sup>

Defines a readable stream. You need to use [fileIo.createReadStream](#fileiocreatereadstream12) to create a **ReadStream** instance, which is inherited from [stream.Readable](../apis-arkts/js-apis-stream.md#readable).

The data obtained by **ReadStream** is a decoded string. Currently, only the UTF-8 format is supported.

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| bytesRead | number | Yes| No| Number of bytes read by the readable stream.|
| path | string | Yes| No| Path of the file corresponding to the readable stream.|

### seek<sup>12+</sup>

seek(offset: number, whence?: WhenceType): number


Adjusts the position of the readable stream offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| offset | number | Yes| Relative offset, in bytes.|
| whence | [WhenceType](#whencetype11) | No| Where to start the offset. The default value is **SEEK_SET**, which indicates the beginning of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Position of the current offset pointer (offset relative to the file header, in bytes).|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fileIo.createReadStream(filePath);
  const curOff = rs.seek(5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, current offset is ${curOff}`);
  rs.close();
  ```

### close<sup>12+</sup>

close(): void

Closes this readable stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fileIo.createReadStream(filePath);
  rs.close();
  ```

## WriteStream<sup>12+</sup>

Defines a writeable stream. You need to use [fileIo.createWriteStream](#fileiocreatewritestream12) to create a **WriteStream** instance, which is inherited from [stream.Writable](../apis-arkts/js-apis-stream.md#writable).

### Properties

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| bytesWritten | number | Yes| No| Number of bytes written to the writable stream.|
| path | string | Yes| No| Path of the file corresponding to the writeable stream.|

### seek<sup>12+</sup>

seek(offset: number, whence?: WhenceType): number

Adjusts the position of the writeable stream offset pointer.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| offset | number | Yes| Relative offset, in bytes.|
| whence | [WhenceType](#whencetype11) | No| Where to start the offset. The default value is **SEEK_SET**, which indicates the beginning of the file.|

**Return value**

| Type| Description|
| ---- | ---- |
| number | Position of the current offset pointer (offset relative to the file header, in bytes).|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes) and [Universal Error Codes](../errorcode-universal.md).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fileIo.createWriteStream(filePath);
  const curOff = ws.seek(5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, current offset is ${curOff}`);
  ws.close();
  ```

### close<sup>12+</sup>

close(): void

Closes this writeable stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fileIo.createWriteStream(filePath);
  ws.close();
  ```

## RandomAccessFileOptions<sup>12+</sup>

Defines the options used in **createRandomAccessFile()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| start | number | No| Yes| Start offset position of the file, in bytes. This parameter is optional. By default, data is read from the current position.|
| end | number | No| Yes| End offset position of the file, in bytes. This parameter is optional. The default value is the end of the file.|

## ReadStreamOptions<sup>12+</sup>

Defines the options used in **createReadStream()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| start | number | No| Yes| Start position to read the data, in bytes. This parameter is optional. By default, data is read from the current position.|
| end | number | No| Yes| End position to read the data, in bytes. This parameter is optional. The default value is the end of the file.|

## WriteStreamOptions<sup>12+</sup>

Defines the options used in **createWriteStream()**.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| start | number | No| Yes| Start position to write the data, in bytes. This parameter is optional. By default, data is written from the current position.|
| mode | number | No| Yes| [OpenMode](#openmode) for creating the writeable stream. You must specify one of the following options.<br>- **OpenMode.READ_ONLY(0o0)**: read-only, which is the default value.<br>- **OpenMode.WRITE_ONLY(0o1)**: write-only.<br>- **OpenMode.READ_WRITE(0o2)**: read/write.<br>You can also specify the following options, separated by a bitwise OR operator (&#124;). By default, no additional options are given.<br>- **OpenMode.CREATE(0o100)**: If the file does not exist, create it.<br>- **OpenMode.TRUNC(0o1000)**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **OpenMode.APPEND(0o2000)**: Open the file in append mode. New data will be added to the end of the file.<br>- **OpenMode.NONBLOCK(0o4000)**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the opened file and in subsequent I/Os.<br>- **OpenMode.DIR(0o200000)**: If **path** does not point to a directory, throw an exception. The write permission is not allowed.<br>- **OpenMode.NOFOLLOW(0o400000)**: If **path** points to a symbolic link, throw an exception.<br>- **OpenMode.SYNC(0o4010000)**: Open the file in synchronous I/O mode.|
