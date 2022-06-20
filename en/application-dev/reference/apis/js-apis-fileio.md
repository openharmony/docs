# File Management

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides file storage and management capabilities, including basic file management, file directory management, file information statistics, and stream read and write.

## Modules to Import

```js
import fileio from '@ohos.fileio';
```


## Guidelines

Before using the APIs provided by this module to perform operations on files or directories, obtain the path of the application sandbox as follows:
 ```js
 import featureAbility from '@ohos.ability.featureAbility';
 let context = featureAbility.getContext();
 let path = '';
 context.getFilesDir().then((data) => {
      path = data;
 })
```


## fileio.stat

stat(path: string): Promise&lt;Stat&gt;

Obtains file information. This API uses a promise to return the result asynchronously.

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
  fileio.stat(path).then(function(stat){
      console.info("Got file info successfully:"+ JSON.stringify(stat));
  }).catch(function(err){
      console.info("getFileInfo failed with error:"+ err);
  });
  ```


## fileio.stat

stat(path:string, callback:AsyncCallback&lt;Stat&gt;): void

Obtains file information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                              | Mandatory| Description                          |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| path     | string                             | Yes  | Application sandbox path of the file.    |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback invoked to return the file information obtained.|

**Example**
  ```js
  fileio.stat(path, function (err, stat) {
      // Example code in Stat
  });
  ```


## fileio.statSync

statSync(path:string): Stat

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
  let stat = fileio.statSync(path);
  // Example code in Stat
  ```


## fileio.opendir

opendir(path: string): Promise&lt;Dir&gt;

Opens a file directory. This API uses a promise to return the result asynchronously.

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
  fileio.opendir(path).then(function(dir){
      console.info("Opened directory successfully:"+ JSON.stringify(dir));
  }).catch(function(err){
      console.info("opendir failed with error:"+ err);
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
  fileio.opendir(path, function (err, dir) { 
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
  let dir = fileio.opendirSync(path);
  // Example code in Dir struct
  // Use read/readSync/close.
  ```


## fileio.access

access(path: string, mode?: number): Promise&lt;void&gt;

Checks whether the current process can access a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>-&nbsp;**0**: check whether the file exists.<br>-&nbsp;**1**: check whether the current process has the execute permission on the file.<br>-&nbsp;**2**: check whether the current process has the write permission on the file.<br>-&nbsp;**4**: check whether the current process has the read permission on the file.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.access(path).then(function() {
      console.info("access succeed");
  }).catch(function(err){
      console.info("access failed with error:"+ err);
  });
  ```


## fileio.access

access(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

Checks whether the current process can access a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | Application sandbox path of the file.                                  |
| mode     | number                    | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>-&nbsp;**0**: check whether the file exists.<br>-&nbsp;**1**: check whether the current process has the execute permission on the file.<br>-&nbsp;**2**: check whether the current process has the write permission on the file.<br>-&nbsp;**4**: check whether the current process has the read permission on the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously checked.                |

**Example**
  ```js
  fileio.access(path, function (err) {
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
| mode   | number | No  | Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (&#124;). The default value is **0**.<br>The options are as follows:<br>-&nbsp;**0**: check whether the file exists.<br>-&nbsp;**1**: check whether the current process has the execute permission on the file.<br>-&nbsp;**2**: check whether the current process has the write permission on the file.<br>-&nbsp;**4**: check whether the current process has the read permission on the file.|

**Example**
  ```js
  try {
      fileio.accessSync(path);
  } catch(err) {
      console.info("accessSync failed with error:"+ err);
  }
  ```


## fileio.close<sup>7+</sup>

close(fd: number):Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to close.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  let fd = fileio.openSync(path);
  fileio.close(fd).then(function(){
      console.info("close file succeed");
  }).catch(function(err){
      console.info("close file failed with error:"+ err);
  });
  ```


## fileio.close<sup>7+</sup>

close(fd: number, callback:AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                       | Mandatory  | Description          |
  | -------- | ------------------------- | ---- | ------------ |
  | fd       | number                    | Yes   | File descriptor of the file to close.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the file is closed asynchronously.|

**Example**
  ```js
  let fd = fileio.openSync(path);
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
  fileio.closeSync(fd);
  ```


## fileio.close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes the stream. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.close().then(function(){
      console.info("close file stream succeed");
  }).catch(function(err){
      console.info("close file stream failed with error:"+ err);
  });
  ```


## fileio.close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

Closes the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                       | Mandatory  | Description           |
  | -------- | ------------------------- | ---- | ------------- |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the stream is closed asynchronously.|

**Example**
  ```js
  fileio.close(function(err){
      // Do something.
  });
  ```


## fileio.copyFile

copyFile(src:string | number, dest:string | number, mode?:number):Promise&lt;void&gt;

Copies a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the file to copy.                     |
  | dest | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the new file.                         |
  | mode | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.copyFile(src, dest).then(function(){
      console.info("copyFile succeed");
  }).catch(function(err){
      console.info("copyFile failed with error:"+ err);
  });
  ```


## fileio.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

Copies a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                        | Mandatory  | Description                                      |
  | -------- | -------------------------- | ---- | ---------------------------------------- |
  | src      | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the file to copy.                     |
  | dest     | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the new file.                         |
  | mode     | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|
  | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked when the file is copied asynchronously.                            |

**Example**
  ```js
  fileio.copyFile(src, dest, function (err) {
      // Do something.
  });
  ```


## fileio.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

Synchronously copies a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type                        | Mandatory  | Description                                      |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the file to copy.                     |
  | dest | string&nbsp;\|&nbsp;number | Yes   | Path or file descriptor of the new file.                         |
  | mode | number                     | No   | Option for overwriting the file of the same name in the destination path. The default value is **0**, which is the only value supported.<br>**0**: Completely overwrite the file with the same name and truncate the part that is not overwritten.|

**Example**
  ```js
  fileio.copyFileSync(src, dest);
  ```


## fileio.mkdir

mkdir(path:string, mode?: number): Promise&lt;void&gt;

Creates a directory. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the directory.                                  |
| mode   | number | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>-&nbsp;**0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.mkdir(path).then(function() {
      console.info("mkdir succeed");
  }).catch(function (error){
      console.info("mkdir failed with error:"+ error);
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
| mode     | number                    | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>-&nbsp;**0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the directory is created asynchronously.                            |

**Example**
  ```js
  fileio.mkdir(path, function(err) {
    console.info("mkdir succeed");
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
| mode   | number | No  | Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o775**.<br>-&nbsp;**0o775**: The owner has the read, write, and execute permissions, and other users have the read and execute permissions.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Example**
  ```js
  fileio.mkdirSync(path);
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags?: number, mode?: number): Promise&lt;number&gt;

Opens a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>-&nbsp;**0o0**: Open the file in read-only mode.<br>-&nbsp;**0o1**: Open the file in write-only mode.<br>-&nbsp;**0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>-&nbsp;**0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>-&nbsp;**0o200**: If **0o100** is added and the file already exists, throw an exception.<br>-&nbsp;**0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>-&nbsp;**0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>-&nbsp;**0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>-&nbsp;**0o200000**: If **path** points to a directory, throw an exception.<br><br>-&nbsp;**0o400000**: If **path** points to a symbolic link, throw an exception.<br>-&nbsp;**0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o666**.<br>-&nbsp;**0o666**: The owner, user group, and other users have the read and write permissions on the file.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Return value**
  | Type                   | Description         |
  | --------------------- | ----------- |
  | Promise&lt;number&gt; | Promise used to return the file descriptor of the file opened.|

**Example**
  ```js
  fileio.open(path, 0o1, 0o0200).then(function(number){
      console.info("Opened file successfully");
  }).catch(function(error){
      console.info("open file failed with error:"+ err);
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
| flags    | number                          | Yes  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>-&nbsp;**0o0**: Open the file in read-only mode.<br>-&nbsp;**0o1**: Open the file in write-only mode.<br>-&nbsp;**0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>-&nbsp;**0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>-&nbsp;**0o200**: If **0o100** is added and the file already exists, throw an exception.<br>-&nbsp;**0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>-&nbsp;**0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>-&nbsp;**0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>-&nbsp;**0o200000**: If **path** points to a directory, throw an exception.<br><br>-&nbsp;**0o400000**: If **path** points to a symbolic link, throw an exception.<br>-&nbsp;**0o4010000**: Open the file in synchronous I/O mode.|
| mode     | number                          | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o666**.<br>-&nbsp;**0o666**: The owner, user group, and other users have the read and write permissions on the file.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|
| callback | AsyncCallback&nbsp;&lt;void&gt; | Yes  | Callback invoked when the file is open asynchronously.                                    |

**Example**
  ```js
  fileio.open(path, 0, function(err, fd) {
      // Do something.
  });
  ```


## fileio.openSync

openSync(path:string, flags?:number, mode?:number): number

Synchronously opens a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| flags  | number | No  | Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.<br>-&nbsp;**0o0**: Open the file in read-only mode.<br>-&nbsp;**0o1**: Open the file in write-only mode.<br>-&nbsp;**0o2**: Open the file in read/write mode.<br>In addition, you can specify the following options, separated using a bitwise OR operator (&#124;). By default, no additional option is specified.<br>-&nbsp;**0o100**: If the file does not exist, create it. If you use this option, you must also specify **mode**.<br>-&nbsp;**0o200**: If **0o100** is added and the file already exists, throw an exception.<br>-&nbsp;**0o1000**: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.<br>-&nbsp;**0o2000**: Open the file in append mode. New data will be appended to the file (added to the end of the file).<br>-&nbsp;**0o4000**: If **path** points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.<br>-&nbsp;**0o200000**: If **path** points to a directory, throw an exception.<br><br>-&nbsp;**0o400000**: If **path** points to a symbolic link, throw an exception.<br>-&nbsp;**0o4010000**: Open the file in synchronous I/O mode.|
| mode   | number | No  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;). The default value is **0o666**.<br>-&nbsp;**0o666**: The owner, user group, and other users have the read and write permissions on the file.<br>-&nbsp;**0o640**: The owner has the read and write permissions, and the user group has the read permission.<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.<br>The file permissions on newly created files are affected by umask, which is set as the process starts. Currently, the modification of umask is not open.|

**Return value**
  | Type    | Description         |
  | ------ | ----------- |
  | number | File descriptor of the file opened.|

**Example**
  ```js
  let fd = fileio.openSync(path, 0o102, 0o640);
  ```
  ```js
  let fd = fileio.openSync(path, 0o102, 0o666);
  fileio.writeSync(fd, 'hello world');
  let fd1 = fileio.openSync(path, 0o2002);
  fileio.writeSync(fd1, 'hello world');
  let num = fileio.readSync(fd1, new ArrayBuffer(4096), {position: 0});
  console.info("num == " + num);
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options?: {
    offset?: number;
    length?: number;
    position?: number;
}): Promise&lt;ReadOut&gt;

Reads data from a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name | Type       | Mandatory| Description                                                        |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | Yes  | File descriptor of the file to read.                                    |
| buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
| options | Object      | No  | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size|

**Return value**

  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**
  ```js
  let fd = fileio.openSync(path, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf).then(function(readout){
      console.info("Read file data successfully");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function(error){
      console.info("read file data failed with error:"+ error);
  });
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options: {
    offset?: number;
    length?: number;
    position?: number;
}, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | Yes   | File descriptor of the file to read.                            |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
  | options  | Object                                   | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when the data is read asynchronously.                            |

**Example**
  ```js
  let fd = fileio.openSync(path, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf, function (err, readOut) {
      if (readOut) {
          console.info("Read file data successfully");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


## fileio.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: {
    offset?: number;
    length?: number;
    position?: number;
}): number

Synchronously reads data from a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | fd      | number      | Yes   | File descriptor of the file to read.                            |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file data read.                       |
  | options | Object      | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**
  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Example**
  ```js
  let fd = fileio.openSync(path, 0o2);
  let buf = new ArrayBuffer(4096);
  let num = fileio.readSync(fd, buf);
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string): Promise&lt;void&gt;

Deletes a directory. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory to delete.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.rmdir(path).then(function() {
      console.info("rmdir succeed");
  }).catch(function(err){
      console.info("rmdir failed with error:"+ err);
  });
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string, callback:AsyncCallback&lt;void&gt;): void

Deletes a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the directory to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the directory is deleted asynchronously.  |

**Example**
  ```js
  fileio.rmdir(path, function(err){
      // Do something.
      console.info("rmdir succeed");
  });
  ```


## fileio.rmdirSync<sup>7+</sup>

rmdirSync(path: string): void

Synchronously deletes a directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the directory to delete.|

**Example**
  ```js
  fileio.rmdirSync(path);
  ```


## fileio.unlink

unlink(path:string): Promise&lt;void&gt;

Deletes a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file to delete.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.unlink(path).then(function(){
      console.info("Removed file successfully");
  }).catch(function(error){
      console.info("remove file failed with error:"+ error);
  });
  ```


## fileio.unlink

unlink(path:string, callback:AsyncCallback&lt;void&gt;): void

Deletes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is deleted asynchronously.  |

**Example**
  ```js
  fileio.unlink(path, function(err) {
      console.info("Removed file successfully");
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
  fileio.unlinkSync(path);
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer | string, options?: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}): Promise&lt;number&gt;

Writes data into a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**
  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**
  ```js
  let fd = fileio.openSync(fpath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world").then(function(number){
       console.info("Wrote data to file successfully and size is:"+ number);
  }).catch(function(err){
      console.info("write data to file failed with error:"+ err);
  });
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer | string, options: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}, callback: AsyncCallback&lt;number&gt;): void

Writes data into a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                             | Mandatory  | Description                                      |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer   | ArrayBuffer&nbsp;\|&nbsp;string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options  | Object                          | No   | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
  | callback | AsyncCallback&lt;number&gt;     | Yes   | Callback invoked when the data is written asynchronously.                      |

**Example**
  ```js
  let fd = fileio.openSync(path, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world", function (err, bytesWritten) {
      if (bytesWritten) {
         console.info("Wrote data to file successfully and size is:"+ bytesWritten);
      }
  });
  ```


## fileio.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}): number

Synchronously writes data into a file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | Yes   | File descriptor of the file to write.                            |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|

**Return value**
  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Example**
  ```js
  let fd = fileio.openSync(path, 0o100 | 0o2, 0o666);
  let num = fileio.writeSync(fd, "hello, world");
  ```


## fileio.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

Calculates the hash value of a file. This API uses a promise to return the result asynchronously.

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
  fileio.hash(path, "sha256").then(function(str){
      console.info("Calculated file hash successfully:"+ str);
  }).catch(function(error){
      console.info("calculate file hash failed with error:"+ err);
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
  fileio.hash(fpath, "sha256", function(err, hashStr) {
      if (hashStr) {
          console.info("Calculated file hash successfully:"+ hashStr);
      }
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number):Promise&lt;void&gt;

Changes file permissions. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                              |
| mode   | number | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.chmod(path, mode).then(function() {
      console.info("chmod succeed");
  }).catch(function(err){
      console.info("chmod failed with error:"+ err);
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
| mode     | number                    | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file permissions are changed asynchronously.                                |

**Example**
  ```js
  fileio.chmod(path, mode, function (err) {
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
| mode   | number | Yes  | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Example**
  ```js
  fileio.chmodSync(fpath, mode);
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number): Promise&lt;Stat&gt;

Obtains file information based on the file descriptor. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the target file.|

**Return value**
  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the file information.|

**Example**
  ```js
  fileio.fstat(fd).then(function(stat){
      console.info("fstat succeed:"+ JSON.stringify(stat));
  }).catch(function(err){
      console.info("fstat failed with error:"+ err);
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
  let fd = fileio.openSync(path);
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
  let fd = fileio.openSync(path);
  let stat = fileio.fstatSync(fd);
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number): Promise&lt;void&gt;

Truncates a file based on the file descriptor. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description              |
  | ---- | ------ | ---- | ---------------- |
  | fd   | number | Yes   | File descriptor of the file to truncate.    |
  | len  | number | No   | File length, in bytes, after truncation.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  let fd = fileio.openSync(path);
  fileio.ftruncate(fd, 5).then(function(err) {    
      console.info("truncate file succeed");
  }).catch(function(err){
      console.info("Failed to truncate the file. Error:"+ err);
  });
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len: number, callback:AsyncCallback&lt;void&gt;): void

Truncates a file based on the file descriptor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                       | Mandatory  | Description              |
  | -------- | ------------------------- | ---- | ---------------- |
  | fd       | number                    | Yes   | File descriptor of the file to truncate.    |
  | len      | number                    | Yes   | File length, in bytes, after truncation.|
  | callback | AsyncCallback&lt;void&gt; | Yes   | Callback which returns no value. |

**Example**
  ```js
  fileio.ftruncate(fd, len, function(err){
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
  fileio.ftruncateSync(fd, len);
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number): Promise&lt;void&gt;

Truncates a file based on the file path. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | Yes  | Application sandbox path of the file to truncate.      |
| len    | number | No  | File length, in bytes, after truncation.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.truncate(path, len).then(function(){
      console.info("Truncated file successfully");
  }).catch(function(err){
      console.info("Failed to truncate the file. Error:"+ err);
  });
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len: number, callback:AsyncCallback&lt;void&gt;): void

Truncates a file based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| path     | string                    | Yes  | Application sandbox path of the file to truncate.      |
| len      | number                    | Yes  | File length, in bytes, after truncation.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback which returns no value.  |

**Example**
  ```js
  fileio.truncate(path, len, function(err){
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
  fileio.truncateSync(path, len);
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options?: {
    position?: number;
    length?: number;
    encoding?: string;
}): Promise&lt;string&gt;

Reads the text content of a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object | No  | The options are as follows:<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**encoding** (string): format of the data (string) to be encoded. The default value is **utf-8**, which is the only value supported.|

**Return value**
  | Type                   | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the content read.|

**Example**
  ```js
  fileio.readText(path).then(function(str) {
      console.info("Read text successfully:"+ str);
  }).catch(function(err){
      console.info("readText failed with error:"+ err);
  });
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options: {
    position?: number;
    length?: number;
    encoding?: string;
}, callback: AsyncCallback&lt;string&gt;): void

Reads the text content of a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | Yes  | Application sandbox path of the file to read.                                  |
| options  | Object                      | No  | The options are as follows:<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>- &nbsp;**encoding**: format of the string to be encoded. The default value is &nbsp;**utf-8**, which is the only value supported.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the content read.                        |

**Example**
  ```js
  fileio.readText(path, function(err, str){
      // Do something.
  });
  ```


## fileio.readTextSync<sup>7+</sup>

readTextSync(filePath: string, options?: {
    position?: number;
    length?: number;
    encoding?: string;
}): string

Synchronously reads the text of a file. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | Yes  | Application sandbox path of the file to be read.                                  |
| options  | Object | No  | The options are as follows:<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**encoding** (string): format of the data (string) to be encoded. The default value is **utf-8**, which is the only value supported.|

**Return value**
  | Type  | Description                |
  | ------ | -------------------- |
  | string | Promise used to return the content of the file read.|

**Example**
  ```js
  let str = fileio.readTextSync(path, {position: 1, length: 3});
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string): Promise&lt;Stat&gt;

Obtains link information. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | Yes  | Application sandbox path of the target file, pointing to the link.|

**Return value**
  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise used to return the link information obtained. For details, see [Stat](#stat).|

**Example**
  ```js
  fileio.lstat(path).then(function(stat){
      console.info("Got link info successfully:"+ number);
  }).catch(function(err){
      console.info("Failed to obtain the link status. Error:"+ err);
  });
  ```


## fileio.lstat<sup>7+</sup>

lstat(path:string, callback:AsyncCallback&lt;Stat&gt;): void

Obtains link information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                              | Mandatory| Description                                  |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | Yes  | Application sandbox path of the target file, pointing to the link.|
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | Yes  | Callback used to return the link information obtained.      |

**Example**
  ```js
  fileio.lstat(path, function (err, stat) {
      // Do something.
  });
  ```


## fileio.lstatSync<sup>7+</sup>

lstatSync(path:string): Stat

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
  let stat = fileio.lstatSync(path);
  ```


## fileio.read<sup>7+</sup>

read(buffer: ArrayBuffer, options?: {
    position?: number;
    offset?: number;
    length?: number;
}): Promise&lt;ReadOut&gt;

Reads data from a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type       | Mandatory| Description                                                        |
  | ------- | ----------- | ---- | ------------------------------------------------------------ |
  | buffer  | ArrayBuffer | Yes  | Buffer used to store the file data read.                          |
  | options | Object      | No  | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>Constraints: offset + length <= Buffer size|

**Return value**
  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**
  ```js
  fileio.read(new ArrayBuffer(4096)).then(function(readout){
      console.info("Read file data successfully");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function(err){
      console.info("Failed to read file data. Error:"+ err);
  });
  ```


## fileio.read<sup>7+</sup>

read(buffer: ArrayBuffer, options: {
    position?: number;
    offset?: number;
    length?: number;
}, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file data read.                       |
  | options  | Object                                   | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>Constraints: offset + length <= Buffer size|
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when the data is read asynchronously from the file.                         |

**Example**
  ```js
  let buf = new ArrayBuffer(4096);
  fileio.read(buf, function (err, readOut) {
      if (readOut) {
          console.info("Read file data successfully");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

Renames a file. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | Yes  | Application sandbox path of the file to rename.|
| newPath | String | Yes  | Application sandbox path of the file renamed.  |

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.rename(oldPath, newPath).then(function() {
      console.info("rename succeed");
  }).catch(function(err){
      console.info("rename failed with error:"+ err);
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
| newPath  | String                    | Yes  | Application sandbox path of the file renamed.  |
| Callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the file is asynchronously renamed.  |

**Example**
  ```js
  fileio.rename(oldPath, newPath, function(err){
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
| newPath | String | Yes  | Application sandbox path of the file renamed.  |

**Example**
  ```js
  fileio.renameSync(oldPath, newPath);
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number): Promise&lt;void&gt;

Flushes data of a file to disk. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to flush.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.fsync(fd).then(function(){
      console.info("sync data successfully");
  }).catch(function(err){
      console.info("sync data failed with error:"+ err);
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
  fileio.fsync(fd, function(err){
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
  fileio.fyncsSync(fd);
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number): Promise&lt;void&gt;

Flushes data of a file to disk. This API uses a promise to return the result asynchronously. **fdatasync()** is similar to **fsync()**, but does not flush modified metadata unless that metadata is needed.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description          |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | Yes   | File descriptor of the file to flush.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.fdatasync(fd).then(function(err) {
      console.info("sync data succeed");
  }).catch(function(err){
      console.info("sync data failed with error:"+ err);
  });
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number, callback:AsyncCallback&lt;void&gt;): void

Flushes data of a file to disk. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                             | Mandatory  | Description               |
  | -------- | ------------------------------- | ---- | ----------------- |
  | fd       | number                          | Yes   | File descriptor of the file to synchronize.     |
  | callback | AsyncCallback&nbsp;&lt;void&gt; | Yes   | Callback invoked when the file data is synchronized in asynchronous mode.|

**Example**
  ```js
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
  let stat = fileio.fdatasyncSync(fd);
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string): Promise&lt;void&gt;

Creates a symbolic link based on a path. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | Yes  | Application sandbox path of the target file.    |
| srcPath | string | Yes  | Application sandbox path of the symbolic link file.|

**Return value**
  | Type                 | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.symlink(target, srcPath).then(function() {
      console.info("symlink succeed");
  }).catch(function(err){
      console.info("symlink failed with error:"+ err);
  });
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

Creates a symbolic link based on a path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | Yes  | Application sandbox path of the target file.        |
| srcPath  | string                    | Yes  | Application sandbox path of the symbolic link file.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked when the symbolic link is created asynchronously.|

**Example**
  ```js
  fileio.symlink(target, srcPath, function (err) {
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
  fileio.symlinkSync(target, srcPath);
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file path. This API uses a promise to return the result asynchronously.

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
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  let stat = fileio.statSync(path);
  fileio.chown(path, stat.uid, stat.gid).then(function(){
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
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
  let stat = fileio.statSync(fpath)
  fileio.chown(path, stat.uid, stat.gid, function (err){
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
  let stat = fileio.statSync(fpath)
  fileio.chownSync(path, stat.uid, stat.gid);
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string): Promise&lt;string&gt;

Creates a temporary directory. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name   | Type    | Mandatory  | Description                         |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | Yes   | A randomly generated string used to replace "XXXXXX" in a directory.|

**Return value**
  | Name                  | Description        |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise used to return the directory generated.|

**Example**
  ```js
  fileio.mkdtemp(path + "XXXX").then(function(path){
      console.info("mkdtemp succeed:"+ path);
  }).catch(function(err){
      console.info("mkdtemp failed with error:"+ err);
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
  fileio.mkdtemp(path + "XXXX", function (err, res) {
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
  | Name   | Description        |
  | ------ | ---------- |
  | string | Unique path generated.|

**Example**
  ```js
  let res = fileio.mkdtempSync(path + "XXXX");
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number): Promise&lt;void&gt;

Changes file permissions based on the file descriptor. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | number | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Return value**
  | Name                | Description                          |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  fileio.fchmod(fd, mode).then(function() {
      console.info("chmod succeed");
  }).catch(function(err){
      console.info("chmod failed with error:"+ err);
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
  | mode     | number                          | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|
  | callback | AsyncCallback&nbsp;&lt;void&gt; | Yes   | Callback invoked when the file permissions are changed asynchronously.                          |

**Example**
  ```js
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
  | mode | number | Yes   | Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (&#124;).<br>-&nbsp;**0o700**: The owner has the read, write, and execute permissions.<br>- &nbsp;**0o400**: The owner has the read permission.<br>-&nbsp;**0o200**: The owner has the write permission.<br>-&nbsp;**0o100**: The owner has the execute permission.<br>-&nbsp;**0o070**: The user group has the read, write, and execute permissions.<br>-&nbsp;**0o040**: The user group has the read permission.<br>-&nbsp;**0o020**: The user group has the write permission.<br>-&nbsp;**0o010**: The user group has the execute permission.<br>-&nbsp;**0o007**: Other users have the read, write, and execute permissions.<br>-&nbsp;**0o004**: Other users have the read permission.<br>-&nbsp;**0o002**: Other users have the write permission.<br>-&nbsp;**0o001**: Other users have the execute permission.|

**Example**
  ```js
   fileio.fchmodSync(fd, mode);
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string): Promise&lt;Stream&gt;

Opens a file stream based on the file path. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | Yes  | Application sandbox path of the file.                                  |
| mode   | string | Yes  | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**
  | Type                               | Description       |
  | --------------------------------- | --------- |
  | Promise&lt;[Stream](#stream7)&gt; | Promise used to return the result.|

**Example**
  ```js
  fileio.createStream(path, "r+").then(function(stream){
      console.info("createStream succeed");
  }).catch(function(err){
      console.info("createStream failed with error:"+ err);
  });
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

Opens a stream based on the file path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | Yes  | Application sandbox path of the file.                                  |
| mode     | string                                  | Yes  | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
| callback | AsyncCallback&lt;[Stream](#stream7)&gt; | Yes  | Callback invoked when the stream is open asynchronously.                                  |

**Example**
  ```js
  fileio.createStream(path, mode, function(err, stream){
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
| mode   | string | Yes  | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**
  | Name               | Description       |
  | ------------------ | --------- |
  | [Stream](#stream7) | Stream opened.|

**Example**
  ```js
  let ss = fileio.createStreamSync(path, "r+");
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

Opens a file stream based on the file descriptor. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name | Type    | Mandatory  | Description                                      |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | Yes   | File descriptor of the target file.                            |
  | mode | string | Yes   | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**
  | Name                              | Description       |
  | --------------------------------- | --------- |
  | Promise&lt;[Stream](#stream7)&gt; | Promise used to return the result.|

**Example**
  ```js
  fileio.fdopenStream(fd, mode).then(function(stream){
      console.info("openStream succeed");
  }).catch(function(err){
      console.info("openStream failed with error:"+ err);
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
  | mode     | string                                   | Yes   | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|
  | callback | AsyncCallback&nbsp;&lt;[Stream](#stream7)&gt; | Yes   | Callback invoked when the stream is open asynchronously.                           |

**Example**
  ```js
  fileio.fdopenStream(fd, mode, function (err, stream) {
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
  | mode | string | Yes   | -&nbsp;**r**: Open a file for reading. The file must exist.<br>-&nbsp;**r+**: Open a file for both reading and writing. The file must exist.<br>-&nbsp;**w**: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**w+**: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.<br>-&nbsp;**a**: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).<br>-&nbsp;**a+**: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).|

**Return value**
  | Type               | Description       |
  | ------------------ | --------- |
  | [Stream](#stream7) | Stream opened.|

**Example**
  ```js
  let ss = fileio.fdopenStreamSync(fd, "r+");
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner based on the file descriptor. This API uses a promise to return the result asynchronously.

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
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  let stat = fileio.statSync(path);
  fileio.fchown(fd, stat.uid, stat.gid).then(function() {
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
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
  let stat = fileio.statSync(fpath);
  fileio.fchown(fd, stat.uid, stat.gid, function (err){
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
  let stat = fileio.statSync(fpath);
  fileio.fchownSync(fd, stat.uid, stat.gid);
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number): Promise&lt;void&gt;

Changes the file owner (owner of the symbolic link, not the file referred to by the symbolic link) based on the file path. This API uses a promise to return the result asynchronously.

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
  | Promise&lt;void&gt; | Promise which returns no value.|

**Example**
  ```js
  let stat = fileio.statSync(path);
  fileio.lchown(path, stat.uid, stat.gid).then(function() {
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
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
  let stat = fileio.statSync(path);
  fileio.lchown(path, stat.uid, stat.gid, function (err){
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
  let stat = fileio.statSync(path);
  fileio.lchownSync(path, stat.uid, stat.gid);
  ```


## fileio.createWatcher<sup>7+</sup>

createWatcher(filename: string, events: number, callback: AsyncCallback&lt;number&gt;): Watcher

Listens for file or directory changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| filename | string                            | Yes  | Application sandbox path of the file.                                  |
| events   | Number                            | Yes  | -&nbsp;**1**: The file or directory is renamed.<br>-&nbsp;**2**: The file or directory is modified.<br>-&nbsp;**3**: The file or directory is modified and renamed.|
| callback | AsyncCallback&lt;number&nbsp;&gt; | Yes  | Called each time a change is detected.                            |

**Return value**
  | Name                 | Description        |
  | -------------------- | ---------- |
  | [Watcher](#watcher7) | Promise used to return the **Watcher** instance.|

**Example**
  ```js
  fileio.createWatcher(filename, events, function(watcher){
      // Do something.
  });
  ```


## Readout

Obtains the file read result. This class applies only to the **read()** method.

**System capability**: SystemCapability.FileManagement.File.FileIO

| Name       | Type      | Readable  | Writable  | Description               |
| --------- | ---------- | ---- | ---- | ----------------- |
| bytesRead | number     | Yes   | Yes   | Length of the data read.          |
| offset    | number     | Yes   | Yes   | Position of the buffer to which the data will be read in reference to the start address of the buffer.|
| buffer    | ArrayBufer | Yes   | Yes   | Buffer for storing the data read.      |


## Stat

Provides detailed file information. Before calling a method of the **Stat** class, use the [stat()](#fileiostat) method synchronously or asynchronously to create a **Stat** instance.

**System capability**: SystemCapability.FileManagement.File.FileIO

### Attributes

| Name    | Type  | Readable  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| dev    | number | Yes   | No   | Major device number.                           |
| ino    | number | Yes   | No   | File ID. Different files on the same device have different **ino**s.                |
| mode   | number | Yes   | No   | File type and permissions. The first four bits indicate the file type, and the last 12 bits indicate the permissions. The bit fields are described as follows:<br>-&nbsp;**0o170000**: mask used to obtain the file type.<br>-&nbsp;**0o140000**: The file is a socket.<br>-&nbsp;**0o120000**: The file is a symbolic link.<br>-&nbsp;**0o100000**: The file is a regular file.<br>-&nbsp;**0o060000**: The file is a block device.<br>-&nbsp;**0o040000**: The file is a directory.<br>-&nbsp;**0o020000**: The file is a character device.<br>-&nbsp;**0o010000**: The file is a named pipe (FIFO).<br>-&nbsp;**0o0700**: mask used to obtain the owner permissions.<br>-&nbsp;**0o0400**: The owner has the permission to read a regular file or a directory entry.<br>-&nbsp;**0o0200**: The owner has the permission to write a regular file or create and delete a directory entry.<br>-&nbsp;**0o0100**: The owner has the permission to execute a regular file or search for the specified path in a directory.<br>-&nbsp;**0o0070**: mask used to obtain the user group permissions.<br>-&nbsp;**0o0040**: The user group has the permission to read a regular file or a directory entry.<br>-&nbsp;**0o0020**: The user group has the permission to write a regular file or create and delete a directory entry.<br>-&nbsp;**0o0010**: The user group has the permission to execute a regular file or search for the specified path in a directory.<br>-&nbsp;**0o0007**: mask used to obtain the permissions of other users.<br>-&nbsp;**0o0004**: Other users have the permission to read a regular file or a directory entry.<br>-&nbsp;**0o0002**: Other users have the permission to write a regular file or create and delete a directory entry.<br>-&nbsp;**0o0001**: Other users have the permission to execute a regular file or search for the specified path in a directory.|
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
  let isBLockDevice = fileio.statSync(path).isBlockDevice();
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
  let isCharacterDevice = fileio.statSync(path).isCharacterDevice();
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
  let isDirectory = fileio.statSync(path).isDirectory(); 
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
  let isFIFO = fileio.statSync(path).isFIFO(); 
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
  let isFile = fileio.statSync(fpath).isFile();
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
  let isSocket = fileio.statSync(path).isSocket(); 
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
  let isSymbolicLink = fileio.statSync(path).isSymbolicLink(); 
  ```


## Watcher<sup>7+</sup>

Listens for the changes of a file. You can call the **Watcher.stop()** method synchronously or asynchronously to stop the listening.


### stop<sup>7+</sup>

stop(): Promise&lt;void&gt;

Stops the **watcher** instance. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  fileio.stop();
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
  fileio.stop(function(err){
      // Do something.
  });
  ```



## Stream<sup>7+</sup>

Provides file stream management. Before calling a method of the **Stream** class, use the **createStream()** method synchronously or asynchronously to create a **Stream** instance.


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

Closes the stream. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**
  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise used to return the stream close result.|

**Example**
  ```js
  let ss= fileio.createStreamSync(path);
  ss.close().then(function(){
      console.info("Closed fileStream successfully");
  }).catch(function(err){
      console.info("close fileStream  failed with error:"+ err);
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
  let ss= fileio.createStreamSync(path);
  ss.close(function (err) {
      // Do something
  });
  ```


### closeSync

closeSync(): void

Synchronously closes the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  let ss= fileio.createStreamSync(path);
  ss.closeSync();
  ```


### flush<sup>7+</sup>

flush(): Promise&lt;void&gt;

Flushes the stream. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**
  | Type                 | Description           |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise used to return the stream flushing result.|

**Example**
  ```js
  let ss= fileio.createStreamSync(path);
  ss.flush().then(function (){
      console.info("Flushed stream successfully");
  }).catch(function(err){
      console.info("flush failed with error:"+ err);
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
  let ss= fileio.createStreamSync(path);
  ss.flush(function (err) {
      // Do something
  });
  ```


### flushSync<sup>7+</sup>

flushSync(): void

Synchronously flushes the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  let ss= fileio.createStreamSync(path);
  ss.flushSync();
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer | string, options?: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}): Promise&lt;number&gt;

Writes data into the stream. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**
  | Type                   | Description      |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Example**
  ```js
  let ss= fileio.createStreamSync(fpath, "r+");
  ss.write("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'}).then(function (number){
      console.info("Wrote data successfully and size is:"+ number);
  }).catch(function(err){
      console.info("write failed with error:"+ err);
  });
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer | string, options: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}, callback: AsyncCallback&lt;number&gt;): void

Writes data into the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name  | Type                           | Mandatory| Description                                                        |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | buffer   | ArrayBuffer&nbsp;\|&nbsp;string | Yes  | Data to write. It can be a string or data from a buffer.                    |
  | options  | Object                          | No  | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size|
  | callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked when the data is written asynchronously.                              |

**Example**
  ```js
  let ss= fileio.createStreamSync(fpath, "r+");
  ss.write("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'}, function (err, bytesWritten) {
      if (bytesWritten) {
         // Do something
         console.info("Wrote data successfully and size is:"+ bytesWritten);
      }
  });
  ```


### writeSync<sup>7+</sup>

writeSync(buffer: ArrayBuffer | string, options?: {
    offset?: number;
    length?: number;
    position?: number;
    encoding?: string;
}): number

Synchronously writes data into the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type                             | Mandatory  | Description                                      |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | Yes   | Data to write. It can be a string or data from a buffer.                    |
  | options | Object                          | No   | The options are as follows:<br>-&nbsp;**offset** (number): position of the data to write in reference to the start address of the data. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to write. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): start position to write the data in the file. By default, data is written from the current position.<br>-&nbsp;**encoding** (string): format of the string to be encoded. The default value is **utf-8**, which is the only value supported.<br>Constraints: offset + length <= Buffer size |

**Return value**
  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data written in the file.|

**Example**
  ```js
  let ss= fileio.createStreamSync(fpath,"r+");
  let num = ss.writeSync("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'});
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options?: {
    position?: number;
    offset?: number;
    length?: number;
}): Promise&lt;ReadOut&gt;

Reads data from the stream. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | Object      | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**
  | Type                                | Description    |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise used to return the data read.|

**Example**
  ```js
  let ss = fileio.createStreamSync(fpath, "r+");
  ss.read(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5}).then(function (readout){
      console.info("Read data successfully");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function(err){
      console.info("read data failed with error:"+ err);
  });
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options: {
    position?: number;
    offset?: number;
    length?: number;
}, callback: AsyncCallback&lt;ReadOut&gt;): void

Reads data from the stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**
  | Name     | Type                                      | Mandatory  | Description                                      |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | Yes   | Buffer used to store the file read.                             |
  | options  | Object                                   | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | Yes   | Callback invoked when data is read asynchronously from the stream.                        |

**Example**
  ```js
  let ss = fileio.createStreamSync(fpath, "r+");
  ss.read(new ArrayBuffer(4096),{offset: 1, length: 5, position: 5},function (err, readOut) {
      if (readOut) {
          console.info("Read data successfully");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


### readSync<sup>7+</sup>

readSync(buffer: ArrayBuffer, options?: {
    position?: number;
    offset?: number;
    length?: number;
}): number

Synchronously reads data from the stream.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name    | Type         | Mandatory  | Description                                      |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | Yes   | Buffer used to store the file read.                             |
  | options | Object      | No   | The options are as follows:<br>-&nbsp;**offset** (number): position to store the data read in the buffer in reference to the start address of the buffer. The default value is **0**.<br>-&nbsp;**length** (number): length of the data to read. The default value is the buffer length minus the offset.<br>-&nbsp;**position** (number): position of the data to read in the file. By default, data is read from the current position.<br>Constraints: offset + length <= Buffer size |

**Return value**

  | Type    | Description      |
  | ------ | -------- |
  | number | Length of the data read.|

**Example**
  ```js
  let ss = fileio.createStreamSync(fpath, "r+");
  let num = ss.readSync(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5});
  ```


## Dir

Manages directories. Before calling a method of the **Dir** class, use the [opendir()](#fileioopendir) method synchronously or asynchronously to create a **Dir** instance.


### read

read(): Promise&lt;Dirent&gt;

Reads the next directory entry. This API uses a promise to return the result asynchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Return value**
  | Type                              | Description           |
  | -------------------------------- | ------------- |
  | Promise&lt;[Dirent](#dirent)&gt; | Promise used to return the directory entry read.|

**Example**
  ```js
  let dir = fileio.opendirSync(path);
  dir.read().then(function (dirent){
      console.log("read succeed:"+JSON.stringify(dirent));
  }).catch(function(err){
      console.info("read failed with error:"+ err);
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
  let dir = fileio.opendirSync(path);
  dir.read(function (err, dirent) {
      if (dirent) {
          // Do something
          console.log("read succeed:"+JSON.stringify(dirent));
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
  let dir = fileio.opendirSync(path);
  let dirent = dir.readSync();
  ```


### close

close(): Promise&lt;void&gt;

Closes a directory. This API uses a promise to return the result asynchronously. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  let dir = fileio.opendirSync(path);
  dir.close().then(function(err){
      console.info("close dir successfully");
  });
  ```


  ### close

close(callback: AsyncCallback&lt;void&gt;): void

Closes a directory. This API uses an asynchronous callback to return the result. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  let dir = fileio.opendirSync(path);
  dir.close(function(err){
      console.info("close dir successfully");
  });
  ```


### closeSync

closeSync(): void

Closes a directory. After a directory is closed, the file descriptor in Dir will be released and no directory entry can be read from Dir.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Example**
  ```js
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(path);
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
  let dir = fileio.opendirSync(dpath);
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
  let dir = fileio.opendirSync(path);
  let isSymbolicLink = dir.readSync().isSymbolicLink();
  ```
