# Accessing Application Files

This topic describes how to enable an application to view, create, read, write, delete, move, or copy an application file and obtain file information.

## Available APIs

You can use [ohos.file.fs](../reference/apis/js-apis-file-fs.md) to implement access to application files. The following table describes the common APIs.

**Table 1** APIs for basic application file operations

| API| Description| Category| Synchronous Programming| Asynchronous Programming|
| -------- | -------- | -------- | -------- | -------- |
| access | Checks whether a file exists.| Method| Supported| Supported|
| close | Closes a file.| Method| Supported| Supported|
| copyFile | Copies a file.| Method| Supported| Supported|
| createStream | Creates a stream based on a file path.| Method| Supported| Supported|
| listFile | Lists all files in a directory.| Method| Supported| Supported|
| mkdir | Creates a directory.| Method| Supported| Supported|
| moveFile | Moves a file.| Method| Supported| Supported|
| open | Opens a file.| Method| Supported| Supported|
| read | Reads data from a file.| Method| Supported| Supported|
| rename | Renames a file or folder.| Method| Supported| Supported|
| rmdir | Deletes a directory.| Method| Supported| Supported|
| stat | Obtains detailed file information.| Method| Supported| Supported|
| unlink | Deletes a single file.| Method| Supported| Supported|
| write | Writes data to a file.| Method| Supported| Supported|
| Stream.close | Closes a stream.| Method| Supported| Supported|
| Stream.flush | Flushes all data from this stream.| Method| Supported| Supported|
| Stream.write | Writes data to a stream.| Method| Supported| Supported|
| Stream.read | Reads data from a stream.| Method| Supported| Supported|
| File.fd | Defines a file descriptor.| Attribute| N/A| N/A|
| OpenMode | Defines the mode for opening a file.| Attribute| N/A| N/A|
| Filter | Defines the options for filtering files.| Type| N/A| N/A|

## Development Example

Before performing any file operation, obtain the [application file path](../application-models/application-context-stage.md#obtaining-application-file-paths). The following example shows how to obtain a HAP file path using **UIAbilityContext**. For details about how to obtain **UIAbilityContext**, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

The following walks you through on how to perform common file operations.

### Creating, Reading, and Writing a File

The following example demonstrates how to create a file, read data from it, and write data to it.

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';
import buffer from '@ohos.buffer';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function createFile(): void {
    // Create a file and open it.
  let file = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Write data to the file.
  let writeLen = fs.writeSync(file.fd, "Try to write str.");
  console.info("The length of str is: " + writeLen);
  // Read data from the file.
  let arrayBuffer = new ArrayBuffer(1024);
  class Option {
    public offset: number = 0;
    public length: number = 0;
  }
  let option = new Option();
  option.length = arrayBuffer.byteLength;
  let readLen = fs.readSync(file.fd, arrayBuffer, option);
  let buf = buffer.from(arrayBuffer, 0, readLen);
  console.info("the content of file: " + buf.toString());
  // Close the file.
  fs.closeSync(file);
}
```

### Copying Data to Another File

The following example demonstrates how to read data from a file and copy it to another file.

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function readWriteFile(): void {
  // Open the source and destination files.
  let srcFile = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE);
  let destFile = fs.openSync(filesDir + '/destFile.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Read data from the source file and copy it to the destination file.
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  class Option {
    public offset: number = 0;
    public length: number = bufSize;
  }
  let option = new Option();
  option.offset = readSize;
  let readLen = fs.readSync(srcFile.fd, buf, option);
  while (readLen > 0) {
    readSize += readLen;
    fs.writeSync(destFile.fd, buf);
    option.offset = readSize;
    readLen = fs.readSync(srcFile.fd, buf, option);
  }
  // Close the files.
  fs.closeSync(srcFile);
  fs.closeSync(destFile);
}
```

> **NOTE**
>
> When using **read()** or **write()**, pay attention to the optional parameter **offset**. For a file that has been read or written, **offset** points to the end position of the last read or write operation by default.

### Reading and Writing Files in a Stream

The following example demonstrates how to read and write file data using a stream.

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

async function readWriteFileWithStream(): Promise<void> {
  // Open the file streams.
  let inputStream = fs.createStreamSync(filesDir + '/test.txt', 'r+');
  let outputStream = fs.createStreamSync(filesDir + '/destFile.txt', "w+");
  // Read data from the source file and write the data to the destination file using a stream.
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  class Option {
    public offset: number = 0;
    public length: number = bufSize;
  }
  let option = new Option();
  option.offset = readSize;
  let readLen = await inputStream.read(buf, option);
  readSize += readLen;
  while (readLen > 0) {
    await outputStream.write(buf);
    option.offset = readSize;
    readLen = await inputStream.read(buf, option);
    readSize += readLen;
  }
  // Close the streams.
  inputStream.closeSync();
  outputStream.closeSync();
}
```

> **NOTE**
>
> - Close the stream once it is not required.
> - Comply with the programming specifications for **Stream** APIs in asynchronous mode and avoid mixed use of the APIs in synchronous mode and asynchronous mode.
> - The **Stream** APIs do not support concurrent read and write operations.

### Listing Files

The following example demonstrates how to list files that meet the specified conditions.

```ts
import fs, { Filter } from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

// List files that meet the specified conditions.
function getListFile(): void {
  class ListFileOption {
    public recursion: boolean = false;
    public listNum: number = 0;
    public filter: Filter = {};
  }
  let option = new ListFileOption();
  option.filter.suffix = ['.png', '.jpg', '.txt'];          // The file name extension can be '.png', '.jpg', or '.txt'.
  option.filter.displayName = ['test%'];                    // The file name starts with 'test'.
  option.filter.fileSizeOver = 0;                           // The file size is greater than or equal to 0.
  option.filter.lastModifiedAfter = new Date(0).getTime();  // The latest modification time of the file is later than January 1, 1970.
  let files = fs.listFileSync(filesDir, option);
  for (let i = 0; i < files.length; i++) {
    console.info(`The name of file: ${files[i]}`);
  }
}
```
