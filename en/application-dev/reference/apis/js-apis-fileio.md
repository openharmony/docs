# @ohos.fileio (File Management)

The **fileio** module provides APIs for file storage and management, including basic file management, directory management, file information statistics, and stream read and write.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [@ohos.file.fs](js-apis-file-fs.md).

## Modules to Import

```js
import fileio from '@ohos.fileio';
```


## Guidelines

Before using the APIs provided by this module to perform operations on files or directories, obtain the path of the application sandbox as follows:

**Stage Model**

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
 ```

**FA Model**

 ```js
 import featureAbility from '@ohos.ability.featureAbility';
 
 let context = featureAbility.getContext();
 context.getFilesDir().then((data) => {
      let pathDir = data;
 })
 ```

For details about how to obtain the FA model context, see [Contex](js-apis-inner-app-context.md#context).

## fileio.stat

stat(path: string): Promise&lt;Stat&gt;

Obtains file information. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "test.txt";
  fileio.stat(filePath).then(function (stat) {
      console.info("getFileInfo succeed, the size of file is " + stat.size);
  }).catch(function (err) {
      console.info("getFileInfo failed with error:" + err);
  });
  ```


## fileio.stat

stat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains file information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                          |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| path     | string                             | Yes  | Application sandbox path of the file.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback invoked to return the file information obtained.|

**Example**

  ```js
  fileio.stat(pathDir, function (err, stat) {
      // Example code in Stat
  });
  ```


## fileio.statSync

statSync(path: string): Stat

Synchronously obtains file information.

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

  ```js
  let stat = fileio.statSync(pathDir);
  // Example code in Stat
  ```


## fileio.opendir

opendir(path: string): Promise&lt;Dir&gt;

Opens a file directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory to open.|

**Return value**

| Type                        | Description      |
| -------------------------- | -------- |
| Promise&lt;[Dir](#dir)&gt; | Promise used to return the **Dir** object.|

**Example**

  ```js
  let dirPath = pathDir + "/testDir";
  fileio.opendir(dirPath).then(function (dir) {
      console.info("opendir succeed");
  }).catch(function (err) {
      console.info("opendir failed with error:" + err);
  });
  ```


## fileio.opendir

opendir(path: string, callback: AsyncCallback&lt;Dir&gt;): void

Opens a file directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                            | Mandatory| Description                          |
| -------- | -------------------------------- | ---- | ------------------------------ |
| path     | string                           | Yes  | Application sandbox path of the directory to open.|
| callback | AsyncCallback&lt;[Dir](#dir)&gt; | Yes  | Callback invoked when the directory is open asynchronously.  |

**Example**

  ```js
  fileio.opendir(pathDir, function (err, dir) { 
      // Example code in Dir struct
      // Use read/readSync/close.
  });
  ```


## fileio.opendirSync

opendirSync(path: string): Dir

Synchronously opens a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO


**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory to open.|

**Return value**

| Type         | Description      |
| ----------- | -------- |
| [Dir](#dir) | A **Dir** instance corresponding to the directory.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  // Example code in Dir struct
  // Use read/readSync/close.
  ```


## fileio.access

access(path: string, mode?: number): Promise&lt;void&gt;

Checks whether the current process can access a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file. |

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath).then(function () {
      console.info("Access successful");
  }).catch(function (err) {
      console.info("access failed with error:" + err);
  });
  ```


## fileio.access

access(path: string, mode?: number, callback: AsyncCallback&lt;void&gt;): void

Checks whether the current process can access a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                                  |
| mode     | number                    | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously checked.                |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath, function (err) {
      // Do something.
  });
  ```


## fileio.accessSync

accessSync(path: string, mode?: number): void

Synchronously checks whether the current process can access the specified file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>- **0**: Check whether the file exists.<br>- **1**: Check whether the process has the execute permission on the file.<br>- **2**: Check whether the process has the write permission on the file.<br>- **4**: Check whether the process has the read permission on the file. |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  try {
      fileio.accessSync(filePath);
  } catch(err) {
      console.info("accessSync failed with error:" + err);
  }
  ```


## fileio.close<sup>7+</sup>

close(fd: number): Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd).then(function () {
      console.info("File closed");
  }).catch(function (err) {
      console.info("close file failed with error:" + err);
  });
  ```


## fileio.close<sup>7+</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| fd       | number                    | Yes   | File descriptor of the file to close.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file is closed asynchronously.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd, function (err) {
      // Do something.
  });
  ```


## fileio.closeSync

closeSync(fd: number): void

Synchronously closes a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the file to close.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.closeSync(fd);
  ```


## fileio.copyFile

copyFile(src: string|number, dest: string|number, mode?: number): Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type                        | Mandatory  | Description                                      |
| ---- | -------------------------- | ---- | ---------------------------------------- |
| src  | string\|number | Yes   | Path or file descriptor of the file to copy.                     |
| dest | string\|number | Yes   | Path or file descriptor of the new file.                         |
| mode | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath).then(function () {
      console.info("File copied");
  }).catch(function (err) {
      console.info("copyFile failed with error:" + err);
  });
  ```


## fileio.copyFile

copyFile(src: string|number, dest: string|number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                        | Mandatory  | Description                                      |
| -------- | -------------------------- | ---- | ---------------------------------------- |
| src      | string\|number | Yes   | Path or file descriptor of the file to copy.                     |
| dest     | string\|number | Yes   | Path or file descriptor of the new file.                         |
| mode     | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked when the file is copied asynchronously.                            |

**Example**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath, function (err) {
      // Do something.
  });
  ```


## fileio.copyFileSync

copyFileSync(src: string|number, dest: string|number, mode?: number): void

Synchronously copies a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type                        | Mandatory  | Description                                      |
| ---- | -------------------------- | ---- | ---------------------------------------- |
| src  | string\|number | Yes   | Path or file descriptor of the file to copy.                     |
| dest | string\|number | Yes   | Path or file descriptor of the new file.                         |
| mode | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|

**Example**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFileSync(srcPath, dstPath);
  ```


## fileio.mkdir

mkdir(path: string, mode?: number): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result.

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

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath).then(function () {
      console.info("Directory created");
  }).catch(function (error) {
      console.info("mkdir failed with error:" + error);
  });
  ```


## fileio.mkdir

mkdir(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

Creates a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the directory.                                  |
| mode     | number                    | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>- **0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the directory is created asynchronously.                            |

**Example**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath, function (err) {
    console.info("Directory created");
  });
  ```


## fileio.mkdirSync

mkdirSync(path: string, mode?: number): void

Synchronously creates a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| mode   | number | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>- **0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```js
  let dirPath = path + '/testDir';
  fileio.mkdirSync(dirPath);
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags?: number, mode?: number): Promise&lt;number&gt;

Opens a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create a file. The third parameter **mode** must also be specified.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (written to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;number&gt; | Promise used to return the file descriptor of the file opened.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0o1, 0o0200).then(function (number) {
      console.info("File opened");
  }).catch(function (err) {
      console.info("open file failed with error:" + err);
  });
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags: number, mode: number, callback: AsyncCallback&lt;number&gt;): void

Opens a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | Yes  | Application sandbox path of the file.                                  |
| flags    | number                          | No  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create a file. The third parameter **mode** must also be specified.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (written to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode     | number                          | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked when the file is open asynchronously.                                    |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0, function (err, fd) {
      // Do something.
  });
  ```


## fileio.openSync

openSync(path: string, flags?: number, mode?: number): number

Synchronously opens a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>- **0o0**: Open the file in read-only mode.<br>- **0o1**: Open the file in write-only mode.<br>- **0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>- **0o100**: If the file does not exist, create a file. The third parameter **mode** must also be specified.<br>- **0o200**: If **0o100** is added and the file already exists, throw an exception.<br>- **0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>- **0o2000**: Open the file in append mode. New data will be appended to the file (written to the end of the file).<br>- **0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>- **0o200000**: If **path** does not point to a directory, throw an exception.<br>- **0o400000**: If **path** points to a symbolic link, throw an exception.<br>- **0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o660**.<br>- **0o660**: The owner and user group have the read and write permissions.<br>- **0o640**: The owner has the read and write permissions, and the user group has the read permission.<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.<br>The file permissions on newly created files are affected by umask, which is set as the process starts. Currently, the modification of umask is not open.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | File descriptor of the file opened.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o640);
  ```
  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o666);
  fileio.writeSync(fd, 'hello world');
  let fd1 = fileio.openSync(filePath, 0o2002);
  fileio.writeSync(fd1, 'hello world');
  let num = fileio.readSync(fd1, new ArrayBuffer(4096), {position: 0});
  console.info("num == " + num);
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): Promise&lt;ReadOut&gt;

Reads data from a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type       | Mandatory| Description                                                        |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | Yes  | File descriptor of the file to read.                                    |
| buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
| options | Object      | No  | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size|

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf).then(function (readOut) {
      console.info("Read file data successfully");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function (err) {
      console.info("read file data failed with error:" + err);
  });
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options: { offset?: number; length?: number; position?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| fd       | number                                   | Yes   | File descriptor of the file to read.                            |
| buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
| options  | Object                                   | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
| callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when the data is read asynchronously.                            |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf, function (err, readOut) {
      if (readOut) {
          console.info("Read file data successfully");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


## fileio.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number

Synchronously reads data from a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| fd      | number      | Yes   | File descriptor of the file to read.                            |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file data read.                       |
| options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  let num = fileio.readSync(fd, buf);
  ```


## fileio.rmdir<sup>7+</sup>

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

**Example**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath).then(function () {
      console.info("Directory deleted");
  }).catch(function (err) {
      console.info("rmdir failed with error:" + err);
  });
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the directory.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the directory is deleted asynchronously.  |

**Example**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath, function (err) {
      // Do something.
      console.info("Directory deleted");
  });
  ```


## fileio.rmdirSync<sup>7+</sup>

rmdirSync(path: string): void

Synchronously deletes a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory.|

**Example**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdirSync(dirPath);
  ```


## fileio.unlink

unlink(path: string): Promise&lt;void&gt;

Deletes a file. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath).then(function () {
      console.info("File deleted");
  }).catch(function (error) {
      console.info("remove file failed with error:" + error);
  });
  ```


## fileio.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is deleted asynchronously.  |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath, function (err) {
      console.info("File deleted");
  });
  ```


## fileio.unlinkSync

unlinkSync(path: string): void

Synchronously deletes a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlinkSync(filePath);
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data into a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| fd      | number                          | Yes   | File descriptor of the file to write.                            |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**

| Type                   | Description      |
| --------------------- | -------- |
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world").then(function (number) {
       console.info("write data to file succeed and size is:" + number);
  }).catch(function (err) {
      console.info("write data to file failed with error:" + err);
  });
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer|string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data into a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                             | Mandatory  | Description                                      |
| -------- | ------------------------------- | ---- | ---------------------------------------- |
| fd       | number                          | Yes   | File descriptor of the file to write.                            |
| buffer   | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options  | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
| callback | AsyncCallback&lt;number&gt;     | Yes   | Callback invoked when the data is written asynchronously.                      |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world", function (err, bytesWritten) {
      if (bytesWritten) {
         console.info("write data to file succeed and size is:" + bytesWritten);
      }
  });
  ```


## fileio.writeSync

writeSync(fd: number, buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

Synchronously writes data into a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| fd      | number                          | Yes   | File descriptor of the file to write.                            |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data written in the file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  let num = fileio.writeSync(fd, "hello, world");
  ```


## fileio.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

Calculates the hash value of a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| path      | string | Yes  | Application sandbox path of the file.                            |
| algorithm | string | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|

**Return value**

| Type                   | Description                        |
| --------------------- | -------------------------- |
| Promise&lt;string&gt; | Promise used to return the hash value obtained. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256").then(function (str) {
      console.info("calculate file hash succeed:" + str);
  }).catch(function (err) {
      console.info("calculate file hash failed with error:" + err);
  });
  ```


## fileio.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

Calculates the hash value of a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                       | Mandatory| Description                                                        |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | Yes  | Application sandbox path of the file.                            |
| algorithm | string                      | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|
| callback  | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the hash value obtained. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256", function (err, hashStr) {
      if (hashStr) {
          console.info("calculate file hash succeed:" + hashStr);
      }
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number): Promise&lt;void&gt;

Changes file permissions. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700).then(function () {
      console.info("File permissions changed");
  }).catch(function (err) {
      console.info("chmod failed with error:" + err);
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

Changes file permissions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                              |
| mode     | number                    | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file permissions are changed asynchronously.                                |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700, function (err) {
      // Do something.
  });
  ```


## fileio.chmodSync<sup>7+</sup>

chmodSync(path: string, mode: number): void

Synchronously changes file permissions.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                              |
| mode   | number | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmodSync(filePath, 0o700);
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number): Promise&lt;Stat&gt;

Obtains file information based on the file descriptor. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | Descriptor of the target file.|

**Return value**

| Type                          | Description        |
| ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the file information obtained.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd).then(function (stat) {
      console.info("fstat succeed, the size of file is " + stat.size);
  }).catch(function (err) {
      console.info("fstat failed with error:" + err);
  });
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number, callback: AsyncCallback&lt;Stat&gt;): void

Obtains file information based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                | Mandatory  | Description              |
| -------- | ---------------------------------- | ---- | ---------------- |
| fd       | number                             | Yes   | File descriptor of the target file.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes   | Callback invoked to return the file information obtained.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd, function (err) {
      // Do something.
  });
  ```


## fileio.fstatSync<sup>7+</sup>

fstatSync(fd: number): Stat

Synchronously obtains file information based on the file descriptor.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the target file.|

**Return value**

| Type           | Description        |
| ------------- | ---------- |
  | [Stat](#stat) | File information obtained.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fstatSync(fd);
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number): Promise&lt;void&gt;

Truncates a file based on the file descriptor. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.ftruncate(fd, 5).then(function (err) {    
      console.info("File truncated");
  }).catch(function (err) {
      console.info("truncate file failed with error:" + err);
  });
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description              |
| -------- | ------------------------- | ---- | ---------------- |
| fd       | number                    | Yes   | File descriptor of the file to truncate.    |
| len      | number                    | No   | File length, in bytes, after truncation.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value. |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncate(fd, 5, function (err) {
      // Do something.
  });
  ```


## fileio.ftruncateSync<sup>7+</sup>

ftruncateSync(fd: number, len?: number): void

Synchronously truncates a file based on the file descriptor.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description              |
| ---- | ------ | ---- | ---------------- |
| fd   | number | Yes   | File descriptor of the file to truncate.    |
| len  | number | No   | File length, in bytes, after truncation.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncateSync(fd, len);
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number): Promise&lt;void&gt;

Truncates a file based on the file path. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len).then(function () {
      console.info("File truncated");
  }).catch(function (err) {
      console.info("truncate file failed with error:" + err);
  });
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number, callback: AsyncCallback&lt;void&gt;): void

Truncates a file based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file to truncate.      |
| len      | number                    | No  | File length, in bytes, after truncation.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.  |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len, function (err) {
      // Do something.
  });
  ```


## fileio.truncateSync<sup>7+</sup>

truncateSync(path: string, len?: number): void

Synchronously truncates a file based on the file path.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | Yes  | Application sandbox path of the file to truncate.      |
| len    | number | No  | File length, in bytes, after truncation.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncateSync(filePath, len);
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): Promise&lt;string&gt;

Reads the text content of a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **encoding** (string): format of the string to be encoded. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise used to return the content read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.readText(filePath).then(function (str) {
      console.info("readText succeed:" + str);
  }).catch(function (err) {
      console.info("readText failed with error:" + err);
  });
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options: { position?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;string&gt;): void

Reads the text content of a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object                      | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **encoding** (string): format of the string to be encoded. The default value is **'utf-8'**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the content read.                        |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.readText(filePath, { position: 1, encoding: 'UTF-8' }, function (err, str) {
      // Do something.
  });
  ```


## fileio.readTextSync<sup>7+</sup>

readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string

Synchronously reads the text of a file. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object | No  | The options are as follows:<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **encoding** (string): format of the string to be encoded. The default value is **'utf-8'**, which is the only value supported.|

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Promise used to return the content of the file read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let str = fileio.readTextSync(filePath, {position: 1, length: 3});
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string): Promise&lt;Stat&gt;

Obtains link information. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the target file.|

**Return value**

| Type                          | Description        |
| ---------------------------- | ---------- |
| Promise&lt;[Stat](#stat)&gt; | Promise used to return the link information obtained. For details, see [Stat](#stat).|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath).then(function (stat) {
      console.info("get link status succeed, the size of file is" + stat.size);
  }).catch(function (err) {
      console.info("get link status failed with error:" + err);
  });
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

Obtains link information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                              | Mandatory| Description                                  |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | Yes  | Application sandbox path of the target file.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the link information obtained.      |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath, function (err, stat) {
      // Do something.
  });
  ```


## fileio.lstatSync<sup>7+</sup>

lstatSync(path: string): Stat

Synchronously obtains the link information.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the target file.|

**Return value**

| Type           | Description        |
| ------------- | ---------- |
| [Stat](#stat) | Link information obtained.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.lstatSync(filePath);
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file. This API uses a promise to return the result.

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

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile).then(function () {
      console.info("File renamed");
  }).catch(function (err) {
      console.info("rename failed with error:" + err);
  });
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

Renames a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                        |
| -------- | ------------------------- | ---- | ---------------------------- |
| oldPath  | string                    | Yes  | Application sandbox path of the file to rename.|
| newPath  | string                    | Yes  | Application sandbox path of the file renamed.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously renamed.  |

**Example**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile, function (err) {
  });
  ```


## fileio.renameSync<sup>7+</sup>

renameSync(oldPath: string, newPath: string): void

Synchronously renames a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file to rename.|
| newPath | string | Yes  | Application sandbox path of the file renamed.  |

**Example**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.renameSync(srcFile, dstFile);
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number): Promise&lt;void&gt;

Flushes data of a file to disk. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the file to flush.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd).then(function () {
      console.info("Data flushed");
  }).catch(function (err) {
      console.info("sync data failed with error:" + err);
  });
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Flushes data of a file to disk. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description             |
| -------- | ------------------------- | ---- | --------------- |
| fd       | number                    | Yes   | File descriptor of the file to flush.   |
| Callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file is synchronized in asynchronous mode.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd, function (err) {
      // Do something.
  });
  ```


## fileio.fsyncSync<sup>7+</sup>

fsyncSync(fd: number): void

Flushes data of a file to disk in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the file to flush.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsyncSync(fd);
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number): Promise&lt;void&gt;

Flushes data of a file to disk. This API uses a promise to return the result. **fdatasync()** is similar to **fsync()**, but does not flush modified metadata unless that metadata is needed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the file to flush.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync(fd).then(function (err) {
      console.info("Data flushed");
  }).catch(function (err) {
      console.info("sync data failed with error:" + err);
  });
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

Flushes data of a file to disk. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                             | Mandatory  | Description               |
| -------- | ------------------------------- | ---- | ----------------- |
| fd       | number                          | Yes   | File descriptor of the file to synchronize.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file data is synchronized in asynchronous mode.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync (fd, function (err) {
      // Do something.
  });
  ```


## fileio.fdatasyncSync<sup>7+</sup>

fdatasyncSync(fd: number): void

Synchronizes data in a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the file to flush.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fdatasyncSync(fd);
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string): Promise&lt;void&gt;

Creates a symbolic link based on the file path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link file.|

**Return value**

| Type                 | Description                          |
| ------------------- | ---------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile).then(function () {
      console.info("Symbolic link created");
  }).catch(function (err) {
      console.info("symlink failed with error:" + err);
  });
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | Yes  | Application sandbox path of the target file.        |
| srcPath  | string                    | Yes  | Application sandbox path of the symbolic link file.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the symbolic link is created asynchronously.|

**Example**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile, function (err) {
      // Do something.
  });
  ```


## fileio.symlinkSync<sup>7+</sup>

symlinkSync(target: string, srcPath: string): void

Synchronously creates a symbolic link based on a specified path.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link file.|

**Example**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlinkSync(srcFile, dstFile);
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file path. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.chown(filePath, stat.uid, stat.gid).then(function () {
      console.info("File owner changed");
  }).catch(function (err) {
      console.info("chown failed with error:" + err);
  });
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                          |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.    |
| uid      | number                    | Yes  | New UID.                     |
| gid      | number                    | Yes  | New GID.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chown(filePath, stat.uid, stat.gid, function (err) {
      // Do something.
  });
  ```


## fileio.chownSync<sup>7+</sup>

chownSync(path: string, uid: number, gid: number): void

Synchronously changes the file owner based on its path.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New UID.                 |
| gid    | number | Yes  | New GID.                 |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chownSync(filePath, stat.uid, stat.gid);
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string): Promise&lt;string&gt;

Creates a temporary directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| prefix | string | Yes   | A randomly generated string used to replace "XXXXXX" in a directory.|

**Return value**

| Type                  | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise used to return the unique directory generated.|

**Example**

  ```js
  fileio.mkdtemp(pathDir + "/XXXXXX").then(function (pathDir) {
      console.info("mkdtemp succeed:" + pathDir);
  }).catch(function (err) {
      console.info("mkdtemp failed with error:" + err);
  });
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

Creates a temporary directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                         | Mandatory  | Description                         |
| -------- | --------------------------- | ---- | --------------------------- |
| prefix   | string                      | Yes   | A randomly generated string used to replace "XXXXXX" in a directory.|
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked when a temporary directory is created asynchronously.             |

**Example**

  ```js
  fileio.mkdtemp(pathDir + "/XXXXXX", function (err, res) {
      // Do something.
  });
  ```


## fileio.mkdtempSync<sup>7+</sup>

mkdtempSync(prefix: string): string

Synchronously creates a temporary directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type    | Mandatory  | Description                         |
| ------ | ------ | ---- | --------------------------- |
| prefix | string | Yes   | A randomly generated string used to replace "XXXXXX" in a directory.|

**Return value**

| Type   | Description        |
| ------ | ---------- |
| string | Unique path generated.|

**Example**

  ```js
  let res = fileio.mkdtempSync(pathDir + "/XXXXXX");
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number): Promise&lt;void&gt;

Changes file permissions based on the file descriptor. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
  fileio.fchmod(fd, mode).then(function () {
      console.info("File permissions changed");
  }).catch(function (err) {
      console.info("chmod failed with error:" + err);
  });
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Changes file permissions based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                             | Mandatory  | Description                                      |
| -------- | ------------------------------- | ---- | ---------------------------------------- |
| fd       | number                          | Yes   | File descriptor of the target file.                            |
| mode     | number                          | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file permissions are changed asynchronously.                          |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
  fileio.fchmod(fd, mode, function (err) {
      // Do something.
  });
  ```


## fileio.fchmodSync<sup>7+</sup>

fchmodSync(fd: number, mode: number): void

Synchronously changes the file permissions based on the file descriptor.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes   | File descriptor of the target file.                            |
| mode | number | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>- **0o700**: The owner has the read, write, and execute permissions.<br>- **0o400**: The owner has the read permission.<br>- **0o200**: The owner has the write permission.<br>- **0o100**: The owner has the execute permission.<br>- **0o070**: The user group has the read, write, and execute permissions.<br>- **0o040**: The user group has the read permission.<br>- **0o020**: The user group has the write permission.<br>- **0o010**: The user group has the execute permission.<br>- **0o007**: Other users have the read, write, and execute permissions.<br>- **0o004**: Other users have the read permission.<br>- **0o002**: Other users have the write permission.<br>- **0o001**: Other users have the execute permission.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
   fileio.fchmodSync(fd, mode);
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Opens a file stream based on the file path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | string | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type                               | Description       |
| --------------------------------- | --------- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the result.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+").then(function (stream) {
      console.info("Stream created");
  }).catch(function (err) {
      console.info("createStream failed with error:" + err);
  });
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a file stream based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | Yes  | Application sandbox path of the file.                                  |
| mode     | string                                  | Yes  | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes  | Callback invoked when the stream is open asynchronously.                                  |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+", function (err, stream) {
      // Do something.
  });
  ```


## fileio.createStreamSync<sup>7+</sup>

createStreamSync(path: string, mode: string): Stream

Synchronously opens a stream based on the file path.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a file stream based on the file descriptor. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes   | File descriptor of the target file.                            |
| mode | string | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**

| Type                              | Description       |
| --------------------------------- | --------- |
| Promise&lt;[Stream](#stream)&gt; | Promise used to return the result.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+").then(function (stream) {
      console.info("Stream opened");
  }).catch(function (err) {
      console.info("openStream failed with error:" + err);
  });
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a file stream based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| fd       | number                                   | Yes   | File descriptor of the target file.                            |
| mode     | string                                   | Yes   | - **r**: Open a file for reading. The file must exist.<br>- **r+**: Open a file for both reading and writing. The file must exist.<br>- **w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>- **a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>- **a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | Yes   | Callback invoked when the stream is open asynchronously.                           |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+", function (err, stream) {
      // Do something.
  });
  ```


## fileio.fdopenStreamSync<sup>7+</sup>

fdopenStreamSync(fd: number, mode: string): Stream

Synchronously opens a stream based on the file descriptor.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let ss = fileio.fdopenStreamSync(fd, "r+");
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file descriptor. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid).then(function () {
      console.info("File owner changed");
  }).catch(function (err) {
      console.info("chown failed with error:" + err);
  });
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description             |
| -------- | ------------------------- | ---- | --------------- |
| fd       | number                    | Yes   | File descriptor of the target file.   |
| uid      | number                    | Yes   | New UID.     |
| gid      | number                    | Yes   | New GID.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid, function (err) {
      // Do something.
  });
  ```


## fileio.fchownSync<sup>7+</sup>

fchownSync(fd: number, uid: number, gid: number): void

Synchronously changes the file owner based on the file descriptor.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| fd   | number | Yes   | File descriptor of the target file.|
| uid  | number | Yes   | New UID.  |
| gid  | number | Yes   | New GID.  |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchownSync(fd, stat.uid, stat.gid);
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner (owner of the symbolic link, not the file referred to by the symbolic link) based on the file path. This API uses a promise to return the result.

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

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid).then(function () {
      console.info("File owner changed");
  }).catch(function (err) {
      console.info("chown failed with error:" + err);
  });
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

Changes the file owner (owner of the symbolic link, not the file referred to by the symbolic link) based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                     | Mandatory| Description                          |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.    |
| uid      | number                    | Yes  | New UID.                     |
| gid      | number                    | Yes  | New GID.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file owner is changed asynchronously.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid, function (err) {
      // Do something.
  });
  ```


## fileio.lchownSync<sup>7+</sup>

lchownSync(path: string, uid: number, gid: number): void

Synchronously changes the file owner based on the file path and changes the owner of the symbolic link (not the referenced file).

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file.|
| uid    | number | Yes  | New UID.                 |
| gid    | number | Yes  | New GID.                 |

**Example**

  ```js
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
| events   | number                            | Yes  | -**1**: The file or directory is renamed.<br>- **2**: The file or directory is modified.<br>- **3**: The file or directory is modified and renamed.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Called each time a change is detected.                            |

**Return value**

| Type                 | Description        |
| -------------------- | ---------- |
| [Watcher](#watcher7) | Promise used to return the **Watcher** instance.|

**Example**

  ```js
  let filePath = pathDir +"/test.txt";
  fileio.createWatcher(filePath, 1, function (number) {
     console.info("Monitoring times: " +number);
  });
  
  ```


## Readout

Obtains the file read result. This class applies only to the **read()** method.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Readable  | Writable  | Description               |
| --------- | ---------- | ---- | ---- | ----------------- |
| bytesRead | number     | Yes   | Yes   | Length of the data read.          |
| offset    | number     | Yes   | Yes   | Position of the buffer to which the data will be read in reference to the start address of the buffer.|
| buffer    | ArrayBuffer | Yes   | Yes   | Buffer for storing the data read.      |


## Stat

Provides detailed file information. Before calling a method of the **Stat** class, use the [stat()](#fileiostat) method synchronously or asynchronously to create a **Stat** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name    | Type  | Readable  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| dev    | number | Yes   | No   | Major device number.                           |
| ino    | number | Yes   | No   | File ID. Different files on the same device have different **ino**s.                |
| mode   | number | Yes   | No   | File type and permissions. The first four bits indicate the file type, and the last 12 bits indicate the permissions. The bit fields are described as follows:<br>- **0o170000**: mask used to obtain the file type.<br>- **0o140000**: The file is a socket.<br>- **0o120000**: The file is a symbolic link.<br>- **0o100000**: The file is a regular file.<br>- **0o060000**: The file is a block device.<br>- **0o040000**: The file is a directory.<br>- **0o020000**: The file is a character device.<br>- **0o010000**: The file is a named pipe, that is, FIFO.<br>- **0o0700**: mask used to obtain owner permissions.<br>- **0o0400**: The owner has the read permission on a regular file or a directory entry.<br>- **0o0200**: The owner has the permission to write a regular file or create and delete a directory entry.<br>- **0o0100**: The owner has the permission to execute a regular file or has the permission to search for the specified path in a directory.<br>- **0o0070**: mask used to obtain user group permissions.<br>- **0o0040**: The user group has the read permission on a regular file or a directory entry.<br>- **0o0020**: The user group has the permission to write a regular file or has the permission to create and delete a directory entry.<br>- **0o0010**: The user group has the permission to execute a regular file or has the permission to search for the specified path in a directory.<br>- **0o0007**: mask used to obtain permissions of other users.<br>- **0o0004**: Other user groups have the read permission on a regular file or a directory entry.<br>- **0o0002**: Other user groups have the permission to write a regular file or have the permission to create and delete a directory entry.<br>- **0o0001**: Other users have the permission to execute a regular file or search for the specified path in a directory.|
| nlink  | number | Yes   | No   | Number of hard links in the file.                                |
| uid    | number | Yes   | No   | User ID, that is ID of the file owner.                               |
| gid    | number | Yes   | No   | Group ID, that is, ID of the user group of the file.                               |
| rdev   | number | Yes   | No   | Minor device number.                           |
| size   | number | Yes   | No   | File size, in bytes. This parameter is valid only for regular files.                  |
| blocks | number | Yes   | No   | Number of blocks occupied by a file. Each block is 512 bytes.                  |
| atime  | number | Yes   | No   | Time of the last access to the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| mtime  | number | Yes   | No   | Time of the last modification to the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.       |
| ctime  | number | Yes   | No   | Time of the last status change of the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.      |


### isBlockDevice

isBlockDevice(): boolean

Checks whether this file is a block special file. A block special file supports access by block only, and it is cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the file is a block special file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fileio.statSync(filePath).isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

Checks whether this file is a character special file. A character special file supports random access, and it is not cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| boolean | Whether the file is a character special file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fileio.statSync(filePath).isCharacterDevice();
  ```


### isDirectory

isDirectory(): boolean

Checks whether this file is a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Whether the file is a directory.|

**Example**

  ```js
  let dirPath = pathDir + "/test";
  let isDirectory = fileio.statSync(dirPath).isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

Checks whether this file is a named pipe (or FIFO). Named pipes are used for inter-process communication.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Whether the file is an FIFO.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let isFIFO = fileio.statSync(filePath).isFIFO(); 
  ```


### isFile

isFile(): boolean

Checks whether this file is a regular file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the file is a regular file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let isFile = fileio.statSync(filePath).isFile();
  ```


### isSocket

isSocket(): boolean

Checks whether this file is a socket.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description            |
| ------- | -------------- |
| boolean | Whether the file is a socket.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let isSocket = fileio.statSync(filePath).isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

Checks whether this file is a symbolic link.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the file is a symbolic link.|

**Example**

  ```js
  let filePath = pathDir + "/test";
  let isSymbolicLink = fileio.statSync(filePath).isSymbolicLink(); 
  ```


## Watcher<sup>7+</sup>

Listens for the changes of a file. You can call the **Watcher.stop()** method synchronously or asynchronously to stop the listening.


### stop<sup>7+</sup>

stop(): Promise&lt;void&gt;

Stops the **watcher** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  let filePath = path + "/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, function (number) {
      console.info("Monitoring times: " +number);
  });
  watcher.stop().then(function () {
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

  ```js
  let filePath = path +"/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, function (number) {
      console.info("Monitoring times: " +number);
  });
  watcher.stop(function () {
      console.info("Watcher stopped");
  })
  ```


## Stream

Provides file stream management. Before calling a method of the **Stream** class, use the **createStream()** method synchronously or asynchronously to create a **Stream** instance.


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes the stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the stream close result.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.close().then(function () {
      console.info("File stream closed");
  }).catch(function (err) {
      console.info("close fileStream  failed with error:" + err);
  });
  ```


### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

Closes the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description           |
| -------- | ------------------------- | ---- | ------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the stream is closed asynchronously.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.close(function (err) {
      // Do something.
  });
  ```


### closeSync

closeSync(): void

Synchronously closes the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.closeSync();
  ```


### flush<sup>7+</sup>

flush(): Promise&lt;void&gt;

Flushes the stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the stream flushing result.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flush().then(function () {
      console.info("Stream flushed");
  }).catch(function (err) {
      console.info("flush failed with error:" + err);
  });
  ```


### flush<sup>7+</sup>

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                       | Mandatory  | Description            |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the stream is asynchronously flushed.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flush(function (err) {
      // Do something.
  });
  ```


### flushSync<sup>7+</sup>

flushSync(): void

Synchronously flushes the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flushSync();
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

Writes data into the stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**

| Type                   | Description      |
| --------------------- | -------- |
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.write("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'}).then(function (number) {
      console.info("write succeed and size is:" + number);
  }).catch(function (err) {
      console.info("write failed with error:" + err);
  });
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer|string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

Writes data into the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| buffer   | ArrayBuffer\|string | Yes  | Data to write. It can be a string or data from a buffer.                    |
| options  | Object                          | No  | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
| callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked when the data is written asynchronously.                              |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.write("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'}, function (err, bytesWritten) {
      if (bytesWritten) {
         // Do something.
         console.info("write succeed and size is:" + bytesWritten);
      }
  });
  ```


### writeSync<sup>7+</sup>

writeSync(buffer: ArrayBuffer|string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

Synchronously writes data into the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type                             | Mandatory  | Description                                      |
| ------- | ------------------------------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer\|string | Yes   | Data to write. It can be a string or data from a buffer.                    |
| options | Object                          | No   | The options are as follows:<br>- **offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>- **length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>- **position** (number): start position to write the data in the file. By default, data is written from the current position.<br>- **encoding** (string): format of the data to be encoded when the data is a string. The default value is **'utf-8'**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data written in the file.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath,"r+");
  let num = ss.writeSync("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'});
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): Promise&lt;ReadOut&gt;

Reads data from the stream. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.read(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5}).then(function (readOut) {
      console.info("Read data successfully");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function (err) {
      console.info("read data failed with error:" + err);
  });
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
| options  | Object                                   | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
| callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when data is read asynchronously from the stream.                        |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.read(new ArrayBuffer(4096),{offset: 1, length: 5, position: 5},function (err, readOut) {
      if (readOut) {
          console.info("Read data successfully");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


### readSync<sup>7+</sup>

readSync(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): number

Synchronously reads data from the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name    | Type         | Mandatory  | Description                                      |
| ------- | ----------- | ---- | ---------------------------------------- |
| buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
| options | Object      | No   | The options are as follows:<br>- **offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>- **length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- **position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Length of the data read.|

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  let num = ss.readSync(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5});
  ```


## Dir

Manages directories. Before calling a method of the **Dir** class, use the **opendir()** method synchronously or asynchronously to create a **Dir** instance.


### read

read(): Promise&lt;Dirent&gt;

Reads the next directory entry. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type                              | Description           |
| -------------------------------- | ------------- |
| Promise&lt;[Dirent](#dirent)&gt; | Promise used to return the directory entry read.|

**Example**

  ```js
  dir.read().then(function (dirent) {
      console.log("read succeed, the name of dirent is " + dirent.name);
  }).catch(function (err) {
      console.info("read failed with error:" + err);
  });
  ```


### read

read(callback: AsyncCallback&lt;Dirent&gt;): void

Reads the next directory entry. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name     | Type                                    | Mandatory  | Description              |
| -------- | -------------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[Dirent](#dirent)&gt; | Yes   | Callback invoked when the next directory entry is asynchronously read.|

**Example**

  ```js
  dir.read(function (err, dirent) {
      if (dirent) {
          // Do something.
          console.log("read succeed, the name of file is " + dirent.name);
      }
  });
  ```


### readSync

readSync(): Dirent

Synchronously reads the next directory entry.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type               | Description      |
| ----------------- | -------- |
| [Dirent](#dirent) | Directory entry read.|

**Example**

  ```js
  let dirent = dir.readSync();
  ```


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes a directory. This API uses a promise to return the result. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  dir.close().then(function (err) {
      console.info("close dir successfully");
  });
  ```


  ### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

Closes a directory. This API uses an asynchronous callback to return the result. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  dir.close(function (err) {
      console.info("close dir successfully");
  });
  ```


### closeSync

closeSync(): void

Closes a directory. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**

  ```js
  dir.closeSync();
  ```


## Dirent

Provides information about files and directories. Before calling a method of the **Dirent** class, use the [dir.read()](#read) method synchronously or asynchronously to create a **Dirent** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name  | Type  | Readable  | Writable  | Description     |
| ---- | ------ | ---- | ---- | ------- |
| name | string | Yes   | No   | Directory entry name.|


### isBlockDevice

isBlockDevice(): boolean

Checks whether this directory entry is a block special file. A block special file supports access by block only, and it is cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the directory entry is a block special file.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isBLockDevice = dir.readSync().isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

Checks whether a directory entry is a character special file. A character special file supports random access, and it is not cached when accessed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| boolean | Whether the directory entry is a character special file.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isCharacterDevice = dir.readSync().isCharacterDevice(); 
  ```


### isDirectory

isDirectory(): boolean

Checks whether a directory entry is a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Whether the directory entry is a directory.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isDirectory = dir.readSync().isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

Checks whether this directory entry is a named pipe (or FIFO). Named pipes are used for inter-process communication.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the directory entry is a FIFO.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isFIFO = dir.readSync().isFIFO(); 
  ```


### isFile

isFile(): boolean

Checks whether a directory entry is a regular file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the directory entry is a regular file.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isFile = dir.readSync().isFile(); 
  ```


### isSocket

isSocket(): boolean

Checks whether a directory entry is a socket.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description            |
| ------- | -------------- |
| boolean | Whether the directory entry is a socket.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isSocket = dir.readSync().isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

Checks whether a directory entry is a symbolic link.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**

| Type     | Description             |
| ------- | --------------- |
| boolean | Whether the directory entry is a symbolic link.|

**Example**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isSymbolicLink = dir.readSync().isSymbolicLink();
  ```
