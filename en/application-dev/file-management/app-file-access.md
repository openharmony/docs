# Accessing Application Files (ArkTS)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

This topic describes how to enable an application to view, create, read, write, delete, move, or copy an application file and obtain file information.

## Available APIs

You can use [ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to application files. The following table describes the commonly used APIs.

Table 1 Functions of ohos.file.fs APIs

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
| rmdir | Removes a directory.| Method| Supported| Supported|
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

> **NOTE**
>
> When using ohos.file.fs APIs, you are advised to use asynchronous APIs for time-consuming operations, such as read and write operations, to prevent application crashes.

## Development Example

Before performing any file operation, obtain the [application file path](../application-models/application-context-stage.md#obtaining-application-file-paths). The following example shows how to obtain a HAP file path using **UIAbilityContext**. For details about how to obtain **UIAbilityContext**, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

The following walks you through on how to perform common file operations.

### Creating, Reading, and Writing a File

The following example demonstrates how to create a file, read data from it, and write data to it.

```ts
// pages/xxx.ets
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { buffer } from '@kit.ArkTS';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

function createFile(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;
  // Create and open a file if the file does not exist. Open it if the file exists.
  let file = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Write data to the file.
  let writeLen = fs.writeSync(file.fd, "Try to write str.");
  console.info("The length of str is: " + writeLen);
  // Create an ArrayBuffer object whose size is 1024 bytes to store the data read from the file.
  let arrayBuffer = new ArrayBuffer(1024);
  // Set the offset and length to be read.
  let readOptions: ReadOptions = {
    offset: 0,
    length: arrayBuffer.byteLength
  };
  // Read the file content to the ArrayBuffer object and return the number of bytes read.
  let readLen = fs.readSync(file.fd, arrayBuffer, readOptions);
  // Convert the ArrayBuffer object into a Buffer object and output it as a string.
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
import { fileIo as fs, ReadOptions, WriteOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

function readWriteFile(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;
  // Open a file.
  let srcFile = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let destFile = fs.openSync(filesDir + '/destFile.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Read data from the source file and copy it to the destination file.
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  let readOptions: ReadOptions = {
    offset: readSize,
    length: bufSize
  };
  let readLen = fs.readSync(srcFile.fd, buf, readOptions);
  while (readLen > 0) {
    readSize += readLen;
    let writeOptions: WriteOptions = {
      length: readLen
    };
    fs.writeSync(destFile.fd, buf, writeOptions);
    readOptions.offset = readSize;
    readLen = fs.readSync(srcFile.fd, buf, readOptions);
  }
  // Close the file.
  fs.closeSync(srcFile);
  fs.closeSync(destFile);
}
```

> **NOTE**
>
> When using **read()** or **write()**, pay attention to the optional parameter **offset**. For a file that has been read or written, **offset** points to the end position of the last read or write operation by default.

### Reading and Writing Files in a Stream

The following sample code shows how to use the **stream()** API to read the **test.txt** file content and write the content to the **destFile.txt** file.

```ts
// pages/xxx.ets
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function readWriteFileWithStream(context: common.UIAbilityContext): Promise<void> {
  let filesDir = context.filesDir;
  // Create and open an input file stream.
  let inputStream = fs.createStreamSync(filesDir + '/test.txt', 'r+');
  // Create and open an output file stream.
  let outputStream = fs.createStreamSync(filesDir + '/destFile.txt', "w+");

  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  let readOptions: ReadOptions = {
    offset: readSize,
    length: bufSize
  };
  // Read data from the source file and write the data to the destination file using a stream.
  let readLen = await inputStream.read(buf, readOptions);
  readSize += readLen;
  while (readLen > 0) {
    const writeBuf = readLen < bufSize ? buf.slice(0, readLen) : buf;
    await outputStream.write(writeBuf);
    readOptions.offset = readSize;
    readLen = await inputStream.read(buf, readOptions);
    readSize += readLen;
  }
  // Close the streams.
  inputStream.closeSync();
  outputStream.closeSync();
}
```

> **NOTE**
>
> Close the stream once it is not required. <br>Comply with the programming specifications for **Stream** APIs in asynchronous mode and avoid mixed use of the APIs in synchronous mode and asynchronous mode. <br>The **Stream** APIs do not support concurrent read and write operations.

### Listing Files

The following example demonstrates how to list files that meet the specified conditions.

```ts
import { fileIo as fs, Filter, ListFileOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

// List files that meet the specified conditions.
function getListFile(context: common.UIAbilityContext): void {
  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".txt"],
      displayName: ["test*"],
      fileSizeOver: 0,
      lastModifiedAfter: new Date(0).getTime()
    }
  };
  let filesDir = context.filesDir;
  let files = fs.listFileSync(filesDir, listFileOption);
  for (let i = 0; i < files.length; i++) {
    console.info(`The name of file: ${files[i]}`);
  }
}
```

### Using File Streams

The following example demonstrates how to use readable and writable streams.

```ts
// pages/xxx.ets
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

function copyFileWithReadable(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;
  // Create a readable stream.
  const rs = fs.createReadStream(`${filesDir}/read.txt`);
  // Create a writable stream.
  const ws = fs.createWriteStream(`${filesDir}/write.txt`);
  // Copy files in paused mode. Pause file operation and copy the original file data to another location, to ensure data integrity and consistency.
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
}

function copyFileWithData(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;
  // Create a readable stream.
  const rs = fs.createReadStream(`${filesDir}/read.txt`);
  // Create a writable stream.
  const ws = fs.createWriteStream(`${filesDir}/write.txt`);
  // Copy files in stream mode. Read and write file data while accessing the original data, to ensure data timeliness.
  rs.on('data', (emitData) => {
    const data = emitData?.data;
    if (!data) {
      return;
    }
    ws.write(data as Uint8Array);
  });
}
```

### Using File Hash Streams

A hash stream is a data transmission and storage technology that can convert data of any length into a hash value of a fixed length to verify data integrity and consistency. The following code shows how to use the file hash processing API [ohos.file.hash](../reference/apis-core-file-kit/js-apis-file-hash.md) to process file hash streams.

```ts
// pages/xxx.ets
import { fileIo as fs } from '@kit.CoreFileKit';
import { hash } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the application file path. The context should be obtained in the component.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

function hashFileWithStream(context: common.UIAbilityContext) {
  let filesDir = context.filesDir;
  const filePath = `${filesDir}/test.txt`;
  // Create a readable stream.
  const rs = fs.createReadStream(filePath);
  // Create a hash stream.
  const hs = hash.createHash('sha256');
  rs.on('data', (emitData) => {
    const data = emitData?.data;
    hs.update(new Uint8Array(data?.split('').map((x: string) => x.charCodeAt(0))).buffer);
  });
  rs.on('close', async () => {
    const hashResult = hs.digest();
    const fileHash = await hash.hash(filePath, 'sha256');
    console.info(`hashResult: ${hashResult}, fileHash: ${fileHash}`);
  });
}

```
