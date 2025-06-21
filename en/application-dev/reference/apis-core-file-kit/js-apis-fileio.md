# @ohos.fileio (File Management)

The **FileIO** module provides APIs for file storage and management, including basic file management, directory management, file information statistics, and stream read and write.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [@ohos.file.fs](js-apis-file-fs.md).

## Modules to Import

```ts
import fileio from '@ohos.fileio';
```


## How to Use

Before using the APIs provided by this module to perform operations on a file or directory, obtain the application sandbox path of the file or directory as follows:

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

For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).


## fileio.stat

stat(path: string): Promise&lt;Stat&gt;

Obtains file information. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.stat](js-apis-file-fs.md#stat) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the file information obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "test.txt";
  fileio.stat(filePath).then((stat: fileio.Stat) => {
    console.info("getFileInfo succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.error("getFileInfo failed with error:" + err);
  });
  ```


## fileio.stat

stat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains file information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.stat](js-apis-file-fs.md#fsstat-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                          |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| path     | string                             | Yes  | Application sandbox path of the file.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the file information obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fileio.stat(pathDir, (err: BusinessError, stat: fileio.Stat) => {
    // Example code in Stat
  });
  ```


## fileio.statSync

statSync(path: string): Stat

Obtains file information. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.statSync](js-apis-file-fs.md#fsstatsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|


**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [Stat](#stat) | File information obtained.|

**Example**

  ```ts
  let stat = fileio.statSync(pathDir);
  // Example code in Stat
  ```


## fileio.opendir

opendir(path: string): Promise&lt;Dir&gt;

Opens a directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory to open.|

**Return value**

  | Type                        | Description      |
  | -------------------------- | -------- |
  | Promise&lt;[Dir](#dir)&gt; | Promise used to return the **Dir** object opened.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + "/testDir";
  fileio.opendir(dirPath).then((dir: fileio.Dir) => {
    console.info("opendir succeed");
  }).catch((err: BusinessError) => {
    console.error("opendir failed with error:" + err);
  });
  ```

   
## fileio.opendir

opendir(path: string, callback: AsyncCallback&lt;Dir&gt;): void

Opens a file directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                            | Mandatory| Description                          |
| -------- | -------------------------------- | ---- | ------------------------------ |
| path     | string                           | Yes  | Application sandbox path of the directory to open.|
| callback | AsyncCallback&lt;[Dir](#dir)&gt; | Yes  | Callback invoked when the directory is opened asynchronously.  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fileio.opendir(pathDir, (err: BusinessError, dir: fileio.Dir) => {
    // Example code in Dir struct
    // Use read/readSync/close.
  });
  ```


## fileio.opendirSync

opendirSync(path: string): Dir

Opens a directory. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFileSync](js-apis-file-fs.md#fslistfilesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory to open.|

**Return value**

  | Type         | Description      |
  | ----------- | -------- |
  | [Dir](#dir) | The **Dir** object opened.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  // Example code in Dir struct
  // Use read/readSync/close.
  ```


## fileio.access

access(path: string, mode?: number): Promise&lt;void&gt;

Checks whether this process can access a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.access](js-apis-file-fs.md#fsaccess) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath).then(() => {
    console.info("Access successful");
  }).catch((err: BusinessError) => {
    console.error("access failed with error:" + err);
  });
  ```


## fileio.access

access(path: string, mode?: number, callback: AsyncCallback&lt;void&gt;): void

Checks whether this process can access a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.access](js-apis-file-fs.md#fsaccess-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                                  |
| mode     | number                    | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously checked.                |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.accessSync

accessSync(path: string, mode?: number): void

Checks whether this process can access a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.accessSync](js-apis-file-fs.md#fsaccesssync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  try {
    fileio.accessSync(filePath);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error("accessSync failed with error:" + err);
  }
  ```


## fileio.close<sup>7+</sup>

close(fd: number): Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.close](js-apis-file-fs.md#fsclose) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to close.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd).then(() => {
    console.info("File closed");
  }).catch((err: BusinessError) => {
    console.error("close file failed with error:" + err);
  });
  ```


## fileio.close<sup>7+</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.close](js-apis-file-fs.md#fsclose-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description          |
  | -------- | ------------------------- | ---- | ------------ |
  | fd       | number                    | Yes   | File descriptor of the file to close.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file is closed asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.closeSync

closeSync(fd: number): void

Closes a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.closeSync](js-apis-file-fs.md#fsclosesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to close.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.closeSync(fd);
  ```


## fileio.copyFile

copyFile(src: string|number, dest: string|number, mode?: number): Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.copyFile](js-apis-file-fs.md#fscopyfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string\|number | Yes   | Path or file descriptor of the source file to copy.                     |
  | dest | string\|number | Yes   | Path or file descriptor of the destination file.                         |
  | mode | number                     | No   | Option for overwriting the destination file. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath).then(() => {
    console.info("File copied");
  }).catch((err: BusinessError) => {
    console.error("copyFile failed with error:" + err);
  });
  ```


## fileio.copyFile

copyFile(src: string|number, dest: string|number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.copyFile](js-apis-file-fs.md#fscopyfile-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                        | Mandatory  | Description                                      |
  | -------- | -------------------------- | ---- | ---------------------------------------- |
  | src      | string\|number | Yes   | Path or file descriptor of the source file to copy.                     |
  | dest     | string\|number | Yes   | Path or file descriptor of the destination file.                         |
  | mode     | number                     | No   | Option for overwriting the destination file. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|
  | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked when the file is copied asynchronously.                            |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.copyFileSync

copyFileSync(src: string|number, dest: string|number, mode?: number): void

Copies a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.copyFileSync](js-apis-file-fs.md#fscopyfilesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string\|number | Yes   | Path or file descriptor of the source file to copy.                     |
  | dest | string\|number | Yes   | Path or file descriptor of the destination file.                         |
  | mode | number                     | No   | Option for overwriting the destination file. The default value is **0**, which is the only value supported.<br>**0**: Overwrite the file with the same name completely and truncate the part that is not overwritten.|

**Example**

  ```ts
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFileSync(srcPath, dstPath);
  ```


## fileio.mkdir

mkdir(path: string, mode?: number): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdir](js-apis-file-fs.md#fsmkdir) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| mode   | number | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>- **0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath).then(() => {
    console.info("Directory created");
  }).catch((error: BusinessError) => {
    console.error("mkdir failed with error:" + error);
  });
  ```


## fileio.mkdir

mkdir(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdir](js-apis-file-fs.md#fsmkdir-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| mode     | number                    | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>- **0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the directory is created asynchronously.                            |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath, (err: BusinessError) => {
    console.info("Directory created");
  });
  ```


## fileio.mkdirSync

mkdirSync(path: string, mode?: number): void

Creates a directory. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdirSync](js-apis-file-fs.md#fsmkdirsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| mode   | number | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>- **0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```ts
  let dirPath = pathDir + '/testDir';
  fileio.mkdirSync(dirPath);
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags?: number, mode?: number): Promise&lt;number&gt;

Opens a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.open](js-apis-file-fs.md#fsopen) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Return value**

  | Type                   | Description         |
  | --------------------- | ----------- |
  | Promise&lt;number&gt; | Promise used to return the file descriptor of the file opened.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0o1, 0o0200).then((number: number) => {
    console.info("File opened");
  }).catch((err: BusinessError) => {
    console.error("open file failed with error:" + err);
  });
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags: number, mode: number, callback: AsyncCallback&lt;number&gt;): void

Opens a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.open](js-apis-file-fs.md#fsopen-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path of the file.                                  |
| flags    | number                          | No  | Option for opening the file. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode     | number                          | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked when the file is opened asynchronously.                                    |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0, (err: BusinessError, fd: number) => {
    // Do something.
  });
  ```


## fileio.openSync

openSync(path: string, flags?: number, mode?: number): number

Opens a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.openSync](js-apis-file-fs.md#fsopensync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is opened in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is opened in write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o640**: The owner has the read and write permissions, and the user group has the read permission.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.<br>The file permissions on newly created files are affected by umask, which is set as the process starts. Currently, the modification of umask is not open.|

**Return value**

  | Type    | Description         |
  | ------ | ----------- |
  | number | File descriptor of the file opened.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o640);
  ```
  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o666);
  fileio.writeSync(fd, 'hello world');
  let fd1 = fileio.openSync(filePath, 0o2002);
  fileio.writeSync(fd1, 'hello world');
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
  }
  let option = new Option();
  option.position = 0;
  let buf = new ArrayBuffer(4096)
  let num = fileio.readSync(fd1, buf, option);
  console.info("num == " + num);
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): Promise&lt;ReadOut&gt;

Reads data from a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.read](js-apis-file-fs.md#fsread) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type       | Mandatory| Description                                                        |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | Yes  | File descriptor of the file to read.                                    |
| buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
| options | Object      | No  | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size|

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o640);
  let arrayBuffer = new ArrayBuffer(4096);
  fileio.read(fd, arrayBuffer).then((readResult: fileio.ReadOut) => {
    console.info("Read file data successfully");
    let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);
    console.log(`The content of file: ${buf.toString()}`);
    fileio.closeSync(fd);
  }).catch((err: BusinessError) => {
    console.error("read file data failed with error:" + err);
  });
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options: { offset?: number; length?: number; position?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.read](js-apis-file-fs.md#fsread-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | Yes   | File descriptor of the file to read.                            |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
  | options  | Object                                   | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when the data is read asynchronously.                            |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o640);
  let arrayBuffer = new ArrayBuffer(4096);
  fileio.read(fd, arrayBuffer, (err: BusinessError, readResult: fileio.ReadOut) => {
    if (readResult) {
      console.info("Read file data successfully");
      let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);
      console.info(`The content of file: ${buf.toString()}`);
    }
    fileio.closeSync(fd);
  });
  ```


## fileio.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number

Reads data from a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.readSync](js-apis-file-fs.md#fsreadsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | fd      | number      | Yes   | File descriptor of the file to read.                            |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file data read.                       |
  | options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  let num = fileio.readSync(fd, buf);
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string): Promise&lt;void&gt;

Removes a directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.rmdir](js-apis-file-fs.md#fsrmdir) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath).then(() => {
    console.info("Directory removed");
  }).catch((err: BusinessError) => {
    console.error("rmdir failed with error:" + err);
  });
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Removes a directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.rmdir](js-apis-file-fs.md#fsrmdir-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when a directory is removed asynchronously.  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath, (err: BusinessError) => {
    // Do something.
    console.info("Directory removed");
  });
  ```


## fileio.rmdirSync<sup>7+</sup>

rmdirSync(path: string): void

Removes a directory. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.rmdirSync](js-apis-file-fs.md#fsrmdirsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Example**

  ```ts
  let dirPath = pathDir + '/testDir';
  fileio.rmdirSync(dirPath);
  ```


## fileio.unlink

unlink(path: string): Promise&lt;void&gt;

Removes a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.unlink](js-apis-file-fs.md#fsunlink) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath).then(() => {
    console.info("File removed");
  }).catch((error: BusinessError) => {
    console.error("remove file failed with error:" + error);
  });
  ```


## fileio.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

Removes a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.unlink](js-apis-file-fs.md#fsunlink-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is removed asynchronously.  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath, (err: BusinessError) => {
    console.info("File removed");
  });
  ```


## fileio.unlinkSync

unlinkSync(path: string): void

Removes a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.unlinkSync](js-apis-file-fs.md#fsunlinksync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fileio.unlinkSync(filePath);
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data into a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.write](js-apis-file-fs.md#fswrite) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**

  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world").then((number: number) => {
    console.info("write data to file succeed and size is:" + number);
  }).catch((err: BusinessError) => {
    console.error("write data to file failed with error:" + err);
  });
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer|string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data to a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.write](js-apis-file-fs.md#fswrite-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                             | Mandatory  | Description                                      |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer   | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options  | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
  | callback | AsyncCallback&lt;number&gt;     | Yes   | Callback invoked when the data is written asynchronously.                      |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world", (err: BusinessError, bytesWritten: number) => {
    if (bytesWritten) {
      console.info("write data to file succeed and size is:" + bytesWritten);
    }
  });
  ```


## fileio.writeSync

writeSync(fd: number, buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

Writes data to a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.writeSync](js-apis-file-fs.md#fswritesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  let num = fileio.writeSync(fd, "hello, world");
  ```


## fileio.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

Calculates the hash value of a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [hash.write](js-apis-file-hash.md#hashhash) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| path      | string | Yes  | Application sandbox path of the file.                            |
| algorithm | string | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|

**Return value**

  | Type                   | Description                        |
  | --------------------- | -------------------------- |
  | Promise&lt;string&gt; | Promise used to return the hash value. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256").then((str: string) => {
    console.info("calculate file hash succeed:" + str);
  }).catch((err: BusinessError) => {
    console.error("calculate file hash failed with error:" + err);
  });
  ```


## fileio.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

Calculates the hash value of a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [hash.write](js-apis-file-hash.md#hashhash-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                       | Mandatory| Description                                                        |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | Yes  | Application sandbox path of the file.                            |
| algorithm | string                      | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|
| callback  | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the hash value obtained. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256", (err: BusinessError, hashStr: string) => {
    if (hashStr) {
      console.info("calculate file hash succeed:" + hashStr);
    }
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number): Promise&lt;void&gt;

Changes file permissions. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                              |
| mode   | number | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700).then(() => {
    console.info("File permissions changed");
  }).catch((err: BusinessError) => {
    console.error("chmod failed with error:" + err);
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

Changes file permissions. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                              |
| mode     | number                    | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file permissions are changed asynchronously.                                |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.chmodSync<sup>7+</sup>

chmodSync(path: string, mode: number): void

Changes file permissions. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                              |
| mode   | number | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fileio.chmodSync(filePath, 0o700);
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number): Promise&lt;Stat&gt;

Obtains file status based on the file descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.stat](js-apis-file-fs.md#fsstat) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file whose status is to be obtained.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the detailed file status obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd).then((stat: fileio.Stat) => {
    console.info("fstat succeed, the size of file is " + stat.size);
  }).catch((err: BusinessError) => {
    console.error("fstat failed with error:" + err);
  });
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number, callback: AsyncCallback&lt;Stat&gt;): void

Obtains file status based on the file descriptor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.stat](js-apis-file-fs.md#fsstat-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                | Mandatory  | Description              |
  | -------- | ---------------------------------- | ---- | ---------------- |
  | fd       | number                             | Yes   | File descriptor of the file whose status is to be obtained.    |
  | callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes   | Callback used to return the file status obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.fstatSync<sup>7+</sup>

fstatSync(fd: number): Stat

Obtains file status based on the file descriptor. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.statSync](js-apis-file-fs.md#fsstatsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file whose status is to be obtained.|

**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [Stat](#stat) | Detailed file status obtained.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fstatSync(fd);
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number): Promise&lt;void&gt;

Truncates a file based on the file descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncate](js-apis-file-fs.md#fstruncate) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description              |
  | ---- | ------ | ---- | ---------------- |
  | fd   | number | Yes   | File descriptor of the file to truncate.    |
  | len  | number | No   | File length, in bytes, after truncation.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.ftruncate(fd, 5).then(() => {
    console.info("File truncated");
  }).catch((err: BusinessError) => {
    console.error("truncate file failed with error:" + err);
  });
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file based on the file descriptor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncate](js-apis-file-fs.md#fstruncate-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description              |
  | -------- | ------------------------- | ---- | ---------------- |
  | fd       | number                    | Yes   | File descriptor of the file to truncate.    |
  | len      | number                    | No   | File length, in bytes, after truncation.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncate(fd, 5, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.ftruncateSync<sup>7+</sup>

ftruncateSync(fd: number, len?: number): void

Truncates a file based on the file descriptor. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncateSync](js-apis-file-fs.md#fstruncatesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description              |
  | ---- | ------ | ---- | ---------------- |
  | fd   | number | Yes   | File descriptor of the file to truncate.    |
  | len  | number | No   | File length, in bytes, after truncation.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncateSync(fd, len);
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number): Promise&lt;void&gt;

Truncates a file based on the file path. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncate](js-apis-file-fs.md#fstruncate) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | Yes  | Application sandbox path of the file to truncate.      |
| len    | number | No  | File length, in bytes, after truncation.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len).then(() => {
    console.info("File truncated");
  }).catch((err: BusinessError) => {
    console.error("truncate file failed with error:" + err);
  });
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file based on the file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncate](js-apis-file-fs.md#fstruncate-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file to truncate.      |
| len      | number                    | No  | File length, in bytes, after truncation.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.truncateSync<sup>7+</sup>

truncateSync(path: string, len?: number): void

Truncates a file based on the file path. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.truncateSync](js-apis-file-fs.md#fstruncatesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | Yes  | Application sandbox path of the file to truncate.      |
| len    | number | No  | File length, in bytes, after truncation.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncateSync(filePath, len);
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): Promise&lt;string&gt;

Reads the text content of a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.readText](js-apis-file-fs.md#fsreadtext) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type                   | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the file content read.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.readText(filePath).then((str: string) => {
    console.info("readText succeed:" + str);
  }).catch((err: BusinessError) => {
    console.error("readText failed with error:" + err);
  });
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options: { position?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;string&gt;): void

Reads the text content of a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.readText](js-apis-file-fs.md#fsreadtext-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object                      | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **encoding**: format of the data to be encoded. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the file content read.                        |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  class Option {
    length: number = 4096;
    position: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.position = 1;
  option.encoding = 'utf-8';
  fileio.readText(filePath, option, (err: BusinessError, str: string) => {
    // Do something.
  });
  ```


## fileio.readTextSync<sup>7+</sup>

readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string

Reads the text content of a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.readTextSync](js-apis-file-fs.md#fsreadtextsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **encoding** (string): format of the data to be encoded.<br>It is valid only when the data is of the string type.<br>The default value is **'utf-8'**, which is the only value supported.|

**Return value**

  | Type  | Description                |
  | ------ | -------------------- |
  | string | File content read.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  class Option {
    length: number = 4096;
    position: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.position = 1;
  option.length = 3;
  let str = fileio.readTextSync(filePath, option);
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string): Promise&lt;Stat&gt;

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.lstat](js-apis-file-fs.md#fslstat) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the target file.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the symbolic link information obtained. For details, see **stat**.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath).then((stat: fileio.Stat) => {
    console.info("get link status succeed, the size of file is" + stat.size);
  }).catch((err: BusinessError) => {
    console.error("get link status failed with error:" + err);
  });
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains information about a symbolic link that is used to refer to a file or directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.lstat](js-apis-file-fs.md#fslstat-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                                  |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | Yes  | Application sandbox path of the target file.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the symbolic link information obtained.      |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath, (err: BusinessError, stat: fileio.Stat) => {
    // Do something.
  });
  ```


## fileio.lstatSync<sup>7+</sup>

lstatSync(path: string): Stat

Obtains information about a symbolic link that is used to refer to a file or directory. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.lstatSync](js-apis-file-fs.md#fslstatsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the target file.|

**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [Stat](#stat) | File information obtained.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stat = fileio.lstatSync(filePath);
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.rename](js-apis-file-fs.md#fsrename) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file to rename.|
| newPath | string | Yes  | Application sandbox path of the file renamed.  |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile).then(() => {
    console.info("File renamed");
  }).catch((err: BusinessError) => {
    console.error("rename failed with error:" + err);
  });
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

Renames a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.rename](js-apis-file-fs.md#fsrename-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                        |
| -------- | ------------------------- | ---- | ---------------------------- |
| oldPath  | string                    | Yes  | Application sandbox path of the file to rename.|
| newPath  | string                    | Yes  | Application sandbox path of the file renamed.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously renamed.  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile, (err: BusinessError) => {
  });
  ```

## fileio.renameSync<sup>7+</sup>

renameSync(oldPath: string, newPath: string): void

Renames a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.renameSync](js-apis-file-fs.md#fsrenamesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file to rename.|
| newPath | string | Yes  | Application sandbox path of the file renamed.  |

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.renameSync(srcFile, dstFile);
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number): Promise&lt;void&gt;

Synchronizes a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fsync](js-apis-file-fs.md#fsfsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to synchronize.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd).then(() => {
    console.info("sync data succeed");
  }).catch((err: BusinessError) => {
    console.error("sync data failed with error:" + err);
  });
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fsync](js-apis-file-fs.md#fsfsync-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description             |
  | -------- | ------------------------- | ---- | --------------- |
  | fd       | number                    | Yes   | File descriptor of the file to synchronize.   |
  | Callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file is synchronized in asynchronous mode.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.fsyncSync<sup>7+</sup>

fsyncSync(fd: number): void

Synchronizes a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fsyncSync](js-apis-file-fs.md#fsfsyncsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to synchronize.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsyncSync(fd);
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number): Promise&lt;void&gt;

Synchronizes the data of a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdatasync](js-apis-file-fs.md#fsfdatasync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to synchronize.|

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync(fd).then(() => {
    console.info("sync data succeed");
  }).catch((err: BusinessError) => {
    console.error("sync data failed with error:" + err);
  });
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Synchronizes the data of a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdatasync](js-apis-file-fs.md#fsfdatasync-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                             | Mandatory  | Description               |
  | -------- | ------------------------------- | ---- | ----------------- |
  | fd       | number                          | Yes   | File descriptor of the file to synchronize.     |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file data is synchronized in asynchronous mode.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync (fd, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.fdatasyncSync<sup>7+</sup>

fdatasyncSync(fd: number): void

Synchronizes the data of a file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdatasyncSync](js-apis-file-fs.md#fsfdatasyncsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to synchronize.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fdatasyncSync(fd);
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string): Promise&lt;void&gt;

Creates a symbolic link based on the file path. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.symlink](js-apis-file-fs.md#fssymlink) instead.

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

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile).then(() => {
    console.info("Symbolic link created");
  }).catch((err: BusinessError) => {
    console.error("symlink failed with error:" + err);
  });
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on the file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.symlink](js-apis-file-fs.md#fssymlink-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | Yes  | Application sandbox path of the target file.        |
| srcPath  | string                    | Yes  | Application sandbox path of the symbolic link.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the symbolic link is created asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.symlinkSync<sup>7+</sup>

symlinkSync(target: string, srcPath: string): void

Creates a symbolic link based on the file path. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.symlinkSync](js-apis-file-fs.md#fssymlinksync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link.|

**Example**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlinkSync(srcFile, dstFile);
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file path. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New user ID (UID).       |
| gid    | number | Yes  | New group ID (GID).      |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.chown(filePath, stat.uid, stat.gid).then(() => {
    console.info("File owner changed");
  }).catch((err: BusinessError) => {
    console.error("chown failed with error:" + err);
  });
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner based on the file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                          |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.    |
| uid      | number                    | Yes  | New UID.                     |
| gid      | number                    | Yes  | New GID.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chown(filePath, stat.uid, stat.gid, (err: BusinessError) => {
    // Do something.
  });
  ```

## fileio.chownSync<sup>7+</sup>

chownSync(path: string, uid: number, gid: number): void

Changes the file owner based on its path. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New UID.                 |
| gid    | number | Yes  | New GID.                 |

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chownSync(filePath, stat.uid, stat.gid);
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string): Promise&lt;string&gt;

Creates a temporary directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdtemp](js-apis-file-fs.md#fsmkdtemp) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

  | Type                  | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the directory created.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fileio.mkdtemp(pathDir + "/XXXXXX").then((pathDir: string) => {
    console.info("mkdtemp succeed:" + pathDir);
  }).catch((err: BusinessError) => {
    console.error("mkdtemp failed with error:" + err);
  });
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

Creates a temporary directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdtemp](js-apis-file-fs.md#fsmkdtemp-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                         | Mandatory  | Description                         |
  | -------- | --------------------------- | ---- | --------------------------- |
  | prefix   | string                      | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|
  | callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked when a temporary directory is created asynchronously.             |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  fileio.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {
    // Do something.
  });
  ```


## fileio.mkdtempSync<sup>7+</sup>

mkdtempSync(prefix: string): string

Creates a temporary directory. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.mkdtempSync](js-apis-file-fs.md#fsmkdtempsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | Yes   | String to be replaced with six randomly generated characters to create a unique temporary directory.|

**Return value**

  | Type   | Description        |
  | ------ | ---------- |
  | string | Unique directory generated.|

**Example**

  ```ts
  let res = fileio.mkdtempSync(pathDir + "/XXXXXX");
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number): Promise&lt;void&gt;

Changes file permissions based on the file descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | number | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Return value**

  | Type                | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode: number = 0o700;
  fileio.fchmod(fd, mode).then(() => {
    console.info("File permissions changed");
  }).catch((err: BusinessError) => {
    console.error("chmod failed with error:" + err);
  });
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Changes file permissions based on the file descriptor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                             | Mandatory  | Description                                      |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | Yes   | File descriptor of the target file.                            |
  | mode     | number                          | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file permissions are changed asynchronously.                          |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode: number = 0o700;
  fileio.fchmod(fd, mode, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.fchmodSync<sup>7+</sup>

fchmodSync(fd: number, mode: number): void

Changes the file permissions based on the file descriptor. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | number | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode: number = 0o700;
  fileio.fchmodSync(fd, mode);
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Creates a stream based on the file path. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.createStream](js-apis-file-fs.md#fscreatestream) instead.

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

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+").then((stream: fileio.Stream) => {
    console.info("Stream created");
  }).catch((err: BusinessError) => {
    console.error("createStream failed with error:" + err);
  });
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Creates a stream based on the file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.createStream](js-apis-file-fs.md#fscreatestream-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | Yes  | Application sandbox path of the file.                                  |
| mode     | string                                  | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes  | Callback invoked when the stream is opened asynchronously.                                  |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+", (err: BusinessError, stream: fileio.Stream) => {
    // Do something.
  });
  ```


## fileio.createStreamSync<sup>7+</sup>

createStreamSync(path: string, mode: string): Stream

Creates a stream based on the file path. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.createStreamSync](js-apis-file-fs.md#fscreatestreamsync) instead.

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

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a stream based on the file descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdopenStream](js-apis-file-fs.md#fsfdopenstream) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | string | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

  | Type                              | Description       |
  | --------------------------------- | --------- |
  | Promise&lt;[Stream](#stream)&gt; | Promise used to return the stream opened.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+").then((stream: fileio.Stream) => {
    console.info("Stream opened");
  }).catch((err: BusinessError) => {
    console.error("openStream failed with error:" + err);
  });
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a stream based on the file descriptor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdopenStream](js-apis-file-fs.md#fsfdopenstream-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | Yes   | File descriptor of the target file.                            |
  | mode     | string                                   | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
  | callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes   | Callback invoked when the stream is opened asynchronously.                           |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+", (err: BusinessError, stream: fileio.Stream) => {
    // Do something.
  });
  ```


## fileio.fdopenStreamSync<sup>7+</sup>

fdopenStreamSync(fd: number, mode: string): Stream

Opens a stream based on the file descriptor. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.fdopenStreamSync](js-apis-file-fs.md#fsfdopenstreamsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | string | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

  | Type               | Description       |
  | ------------------ | --------- |
  | [Stream](#stream) | Stream opened.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let ss = fileio.fdopenStreamSync(fd, "r+");
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the target file.|
  | uid  | number | Yes   | New UID.  |
  | gid  | number | Yes   | New GID.  |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid).then(() => {
    console.info("File owner changed");
  }).catch((err: BusinessError) => {
    console.error("chown failed with error:" + err);
  });
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner based on the file descriptor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description             |
  | -------- | ------------------------- | ---- | --------------- |
  | fd       | number                    | Yes   | File descriptor of the target file.   |
  | uid      | number                    | Yes   | New UID.     |
  | gid      | number                    | Yes   | New GID.     |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.fchownSync<sup>7+</sup>

fchownSync(fd: number, uid: number, gid: number): void

Changes the file owner based on the file descriptor. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the target file.|
  | uid  | number | Yes   | New UID.  |
  | gid  | number | Yes   | New GID.  |

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchownSync(fd, stat.uid, stat.gid);
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner (owner of the symbolic link, not the file referred to by the symbolic link) based on the file path. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New UID.                 |
| gid    | number | Yes  | New GID.                 |

**Return value**

  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid).then(() => {
    console.info("File owner changed");
  }).catch((err: BusinessError) => {
    console.error("chown failed with error:" + err);
  });
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner (owner of the symbolic link, not the file referred to by the symbolic link) based on a file path. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                          |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.    |
| uid      | number                    | Yes  | New UID.                     |
| gid      | number                    | Yes  | New GID.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid, (err: BusinessError) => {
    // Do something.
  });
  ```


## fileio.lchownSync<sup>7+</sup>

lchownSync(path: string, uid: number, gid: number): void

Changes the file owner based on a file path and changes the owner of the symbolic link (not the referenced file). This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New UID.                 |
| gid    | number | Yes  | New GID.                 |

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchownSync(filePath, stat.uid, stat.gid);
  ```


## fileio.createWatcher<sup>7+</sup>

createWatcher(filename: string, events: number, callback: AsyncCallback&lt;number&gt;): Watcher

Listens for file or directory changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                            | Yes  | Application sandbox path of the file.                                  |
| events   | number                            | Yes  | - **1**: The file or directory is renamed.<br>- **2**: The file or directory is modified.<br>- **3**: The file or directory is modified and renamed.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Called each time a change is detected.                            |

**Return value**

  | Type                 | Description        |
  | -------------------- | ---------- |
  | [Watcher](#watcher7) | Promise used to return the result.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  fileio.createWatcher(filePath, 1, (err: BusinessError, event: number) => {
    console.info("event: " + event + "errmsg: " + JSON.stringify(err));
  });
  ```


## Readout

Obtains the file read result. This class applies only to the **read()** method.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Read-Only  | Writable  | Description               |
| --------- | ---------- | ---- | ---- | ----------------- |
| bytesRead | number     | Yes   | Yes   | Length of the data read.          |
| offset    | number     | Yes   | Yes   | Position of the buffer to which the data to be read in reference to the start address of the buffer.|
| buffer    | ArrayBuffer | Yes   | Yes   | Buffer for storing the data read.      |


## Stat

Provides detailed file information. Before calling a method of the **Stat** class, use the [stat()](#fileiostat) method synchronously or asynchronously to create a **Stat** instance.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.stat](js-apis-file-fs.md#stat) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name    | Type  | Read-Only  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| dev    | number | Yes   | No   | Major device number.                           |
| ino    | number | Yes   | No   | File identifier, which varies with files on the same device.                |
| mode   | number | Yes   | No   | File type and permissions. The first four bits indicate the file type, and the last 12 bits indicate the permissions. The bit fields are described as follows:<br>- **0o170000**: mask used to obtain the file type.<br>- **0o140000**: The file is a socket.<br>- **0o120000**: The file is a symbolic link.<br>- **0o100000**: The file is a regular file.<br>- **0o060000**: The file is a block device.<br>- **0o040000**: The file is a directory.<br>- **0o020000**: The file is a character device.<br>- **0o010000**: The file is a named pipe (FIFO).<br>- **0o0700**: mask used to obtain the owner permissions.<br>- **0o0400**: The owner has the permission to read a regular file or a directory entry.<br>- **0o0200**: The owner has the permission to write a regular file or create and delete a directory entry.<br>- **0o0100**: The owner has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o0070**: mask used to obtain the user group permissions.<br>- **0o0040**: The user group has the permission to read a regular file or a directory entry.<br>- **0o0020**: The user group has the permission to write a regular file or create and delete a directory entry.<br>- **0o0010**: The user group has the permission to execute a regular file or search for the specified path in a directory.<br>- **0o0007**: mask used to obtain the permissions of other users.<br>- **0o0004**: Other users have the permission to read a regular file or a directory entry.<br>- **0o0002**: Other users have the permission to write a regular file or create and delete a directory entry.<br>- **0o0001**: Other users have the permission to execute a regular file or search for the specified path in a directory.|
| nlink  | number | Yes   | No   | Number of hard links in the file.                                |
| uid    | number | Yes   | No   | ID of the file owner.                               |
| gid    | number | Yes   | No   | ID of the user group of the file.                               |
| rdev   | number | Yes   | No   | Minor device number.                           |
| size   | number | Yes   | No   | File size, in bytes. This parameter is valid only for regular files.                  |
| blocks | number | Yes   | No   | Number of blocks occupied by a file. Each block is 512 bytes.                  |
| atime  | number | Yes   | No   | Time when the file was last accessed. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| mtime  | number | Yes   | No   | Time when the file content was last modified. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| ctime  | number | Yes   | No   | Time of the last status change of the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.      |


### isBlockDevice

isBlockDevice(): boolean

Checks whether this file is a block special file. A block special file supports access by block only, and it is cached when accessed.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isBlockDevice](js-apis-file-fs.md#isblockdevice) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description              |
  | ------- | ---------------- |
  | boolean | Returns **true** if it is a block special file; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fileio.statSync(filePath).isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this file is a character special file. A character special file supports random access, and it is not cached when accessed.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isCharacterDevice](js-apis-file-fs.md#ischaracterdevice) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description               |
  | ------- | ----------------- |
  | boolean | Returns **true** if it is a character special file; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fileio.statSync(filePath).isCharacterDevice();
  ```


### isDirectory

isDirectory(): boolean

Checks whether this file is a directory.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isDirectory](js-apis-file-fs.md#isdirectory) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description           |
  | ------- | ------------- |
  | boolean | Returns **true** if it is a directory; returns **false** otherwise.|

**Example**

  ```ts
  let dirPath = pathDir + "/test";
  let isDirectory = fileio.statSync(dirPath).isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

Checks whether this file is a named pipe (or FIFO). Named pipes are used for inter-process communication.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isFIFO](js-apis-file-fs.md#isfifo) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description                   |
  | ------- | --------------------- |
  | boolean | Returns **true** if it is a named pipe; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFIFO = fileio.statSync(filePath).isFIFO(); 
  ```


### isFile

isFile(): boolean

Checks whether this file is a regular file.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isFile](js-apis-file-fs.md#isfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Returns **true** if it is a regular file; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFile = fileio.statSync(filePath).isFile();
  ```


### isSocket

isSocket(): boolean

Checks whether this file is a socket.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isSocket](js-apis-file-fs.md#issocket) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description            |
  | ------- | -------------- |
  | boolean | Returns **true** if it is a socket; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSocket = fileio.statSync(filePath).isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

Checks whether this file is a symbolic link.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stat.isSymbolicLink](js-apis-file-fs.md#issymboliclink) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Returns **true** if it is a symbolic link; returns **false** otherwise.|

**Example**

  ```ts
  let filePath = pathDir + "/test";
  let isSymbolicLink = fileio.statSync(filePath).isSymbolicLink(); 
  ```


## Watcher<sup>7+</sup>

Listens for file change. You can call the **Watcher.stop()** method synchronously or asynchronously to stop the listening.


### stop<sup>7+</sup>

stop(): Promise&lt;void&gt;

Stops the **watcher** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, (err: BusinessError, event: number) => {
    console.info("event: " + event + "errmsg: " + JSON.stringify(err));
  });
  watcher.stop().then(() => {
    console.info("Watcher stopped");
  });
  ```


### stop<sup>7+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

Stops the **watcher** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description                    |
  | -------- | ------------------------- | ---- | ---------------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when **watcher** is stopped asynchronously.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, (err: BusinessError, event: number) => {
    console.info("event: " + event + "errmsg: " + JSON.stringify(err));
  });
  watcher.stop(() => {
    console.info("Watcher stopped");
  })
  ```


## Stream

Provides a stream for file operations. Before calling any API of the **Stream** class, use **createStream()** to create a **Stream** instance synchronously or asynchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream](js-apis-file-fs.md#stream) instead.

### close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes the file stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.close](js-apis-file-fs.md#close) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.close().then(() => {
    console.info("File stream closed");
  }).catch((err: BusinessError) => {
    console.error("close fileStream  failed with error:" + err);
  });
  ```


### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

Closes the file stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.close](js-apis-file-fs.md#close-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description           |
  | -------- | ------------------------- | ---- | ------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file stream is closed asynchronously.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.close((err: BusinessError) => {
    // Do something.
  });
  ```


### closeSync

closeSync(): void

Closes the file stream. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.closeSync](js-apis-file-fs.md#closesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.closeSync();
  ```


### flush<sup>7+</sup>

flush(): Promise&lt;void&gt;

Flushes the file stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.flush](js-apis-file-fs.md#flush) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.flush().then(() => {
    console.info("Stream flushed");
  }).catch((err: BusinessError) => {
    console.error("flush failed with error:" + err);
  });
  ```


### flush<sup>7+</sup>

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes the file stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.flush](js-apis-file-fs.md#flush-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                       | Mandatory  | Description            |
  | -------- | ------------------------- | ---- | -------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file stream is asynchronously flushed.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.flush((err: BusinessError) => {
    // Do something.
  });
  ```


### flushSync<sup>7+</sup>

flushSync(): void

Flushes the file stream. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.flushSync](js-apis-file-fs.md#flushsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.flushSync();
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data to a stream file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.write](js-apis-file-fs.md#write) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  ss.write("hello, world", option).then((number: number) => {
    console.info("write succeed and size is:" + number);
  }).catch((err: BusinessError) => {
    console.error("write failed with error:" + err);
  });
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer|string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data to a stream file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.write](js-apis-file-fs.md#write-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                           | Mandatory| Description                                                        |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | buffer   | ArrayBuffer\|string | Yes  | Data to write. It can be a string or data from a buffer.                    |
  | options  | Object                          | No  | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
  | callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked when the data is written asynchronously.                              |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  ss.write("hello, world", option, (err: BusinessError, bytesWritten: number) => {
    if (bytesWritten) {
      // Do something.
      console.info("write succeed and size is:" + bytesWritten);
    }
  });
  ```


### writeSync<sup>7+</sup>

writeSync(buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

Writes data to a stream file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.writeSync](js-apis-file-fs.md#writesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to write. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. This parameter is optional. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath,"r+");
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
    encoding: string = 'utf-8';
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  let num = ss.writeSync("hello, world", option);
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): Promise&lt;ReadOut&gt;

Reads data from a stream file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.read](js-apis-file-fs.md#read) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  ss.read(arrayBuffer, option).then((readResult: fileio.ReadOut) => {
    console.info("Read data successfully");
    let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);
    console.info(`The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.error("read data failed with error:" + err);
  });
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from a stream file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.read](js-apis-file-fs.md#read-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
  | options  | Object                                   | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when data is read asynchronously from the stream file.                        |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import buffer from '@ohos.buffer';
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  ss.read(arrayBuffer, option, (err: BusinessError, readResult: fileio.ReadOut) => {
    if (readResult.bytesRead) {
      console.info("Read data successfully");
      let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);
      console.info(`The content of file: ${buf.toString()}`);
    }
  });
  ```


### readSync<sup>7+</sup>

readSync(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): number

Reads data from a stream file. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.Stream.readSync](js-apis-file-fs.md#readsync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. This parameter is optional. The default value is **0**.<br>- **length** (number): length of the data to read. This parameter is optional. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. This parameter is optional. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Example**

  ```ts
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  class Option {
    offset: number = 0;
    length: number = 4096;
    position: number = 0;
  }
  let option = new Option();
  option.offset = 1;
  option.length = 5;
  option.position = 5;
  let buf = new ArrayBuffer(4096)
  let num = ss.readSync(buf, option);
  ```


## Dir

Manages directories. Before calling a method of the **Dir** class, use the **opendir()** method synchronously or asynchronously to create a **Dir** instance.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

### read

read(): Promise&lt;Dirent&gt;

Reads the next directory entry. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type                              | Description           |
  | -------------------------------- | ------------- |
  | Promise&lt;[Dirent](#dirent)&gt; | Promise used to return the result.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  dir.read().then((dirent: fileio.Dirent) => {
    console.log("read succeed, the name of dirent is " + dirent.name);
  }).catch((err: BusinessError) => {
    console.error("read failed with error:" + err);
  });
  ```


### read

read(callback: AsyncCallback&lt;Dirent&gt;): void

Reads the next directory entry. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name     | Type                                    | Mandatory  | Description              |
  | -------- | -------------------------------------- | ---- | ---------------- |
  | callback | AsyncCallback&lt;[Dirent](#dirent)&gt; | Yes   | Callback invoked when the next directory entry is asynchronously read.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  dir.read((err: BusinessError, dirent: fileio.Dirent) => {
    if (dirent) {
      // Do something.
      console.log("read succeed, the name of file is " + dirent.name);
    }
  });
  ```


### readSync

readSync(): Dirent

Reads the next directory entry. This API returns the result synchronously.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFileSync](js-apis-file-fs.md#fslistfilesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type               | Description      |
  | ----------------- | -------- |
  | [Dirent](#dirent) | Directory entry read.|

**Example**

  ```ts
  let dirent = dir.readSync();
  ```


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes a directory. This API uses a promise to return the result. After a directory is closed, the file descriptor in **Dir** will be released and no directory entry can be read from **Dir**.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  dir.close().then(() => {
    console.info("close dir successfully");
  });
  ```


### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

Closes a directory. This API uses an asynchronous callback to return the result. After a directory is closed, the file descriptor in **Dir** will be released and no directory entry can be read from **Dir**.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile-1) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  dir.close((err: BusinessError) => {
    console.info("close dir successfully");
  });
  ```


### closeSync

closeSync(): void

Closes a directory. After a directory is closed, the file descriptor in **Dir** will be released and no directory entry can be read from **Dir**.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFileSync](js-apis-file-fs.md#fslistfilesync) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```ts
  dir.closeSync();
  ```


## Dirent

Provides information about files and directories. Before calling an API of the **Dirent** class, use [dir.read()](#read) synchronously or asynchronously to create a **Dirent** instance.

> **NOTE**
>
> This API is deprecated since API version 9. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Properties

| Name  | Type  | Read-Only  | Writable  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| name | string | Yes   | No   | Directory entry name.|


### isBlockDevice

isBlockDevice(): boolean

Checks whether this directory entry is a block special file. A block special file supports access by block only, and it is cached when accessed.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description              |
  | ------- | ---------------- |
  | boolean | Returns **true** if it is a block special file; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isBLockDevice = dir.readSync().isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this directory entry is a character special file. A character special file supports random access, and it is not cached when accessed.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description               |
  | ------- | ----------------- |
  | boolean | Returns **true** if it is a character special file; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isCharacterDevice = dir.readSync().isCharacterDevice(); 
  ```


### isDirectory

isDirectory(): boolean

Checks whether this directory entry is a directory.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description           |
  | ------- | ------------- |
  | boolean | Returns **true** if it is a directory; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isDirectory = dir.readSync().isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

Checks whether this directory entry is a named pipe (also called FIFO). Named pipes are used for inter-process communication.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Returns **true** if it is a named pipe; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isFIFO = dir.readSync().isFIFO(); 
  ```


### isFile

isFile(): boolean

Checks whether this directory entry is a regular file.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Returns **true** if it is a regular file; returns **false** otherwise.|

**Example**

  <!--code_no_check-->
  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isFile = dir.readSync().isFile(); 
  ```


### isSocket

isSocket(): boolean

Checks whether this directory entry is a socket.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description            |
  | ------- | -------------- |
  | boolean | Returns **true** if it is a socket; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isSocket = dir.readSync().isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

Checks whether this directory entry is a symbolic link.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

  | Type     | Description             |
  | ------- | --------------- |
  | boolean | Returns **true** if it is a symbolic link; returns **false** otherwise.|

**Example**

  ```ts
  let dir = fileio.opendirSync(pathDir);
  let isSymbolicLink = dir.readSync().isSymbolicLink();
  ```
