# Accessing Application Files (ArkTS)

This topic describes how to enable an application to view, create, read, write, delete, move, or copy an application file and obtain file information.

## Available APIs

You can use [ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to application files. The following table describes the commonly used APIs.

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
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { buffer } from '@kit.ArkTS';

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
  let readOptions: ReadOptions = {
    offset: 0,
    length: arrayBuffer.byteLength
  };
  let readLen = fs.readSync(file.fd, arrayBuffer, readOptions);
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

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function readWriteFile(): void {
  // Open the source and destination files.
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
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

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
  let readOptions: ReadOptions = {
    offset: readSize,
    length: bufSize
  };
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
> - Close the stream once it is not required.
> - Comply with the programming specifications for **Stream** APIs in asynchronous mode and avoid mixed use of the APIs in synchronous mode and asynchronous mode. 
> - The **Stream** APIs do not support concurrent read and write operations.

### Listing Files

The following example demonstrates how to obtain files that meet the specified conditions.

```ts
import { fileIo as fs, Filter, ListFileOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

// List files that meet the specified conditions.
function getListFile(): void {
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

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function copyFileWithReadable(): void {
  // Create a readable stream.
  const rs = fs.createReadStream(`${filesDir}/read.txt`);
  // Create a writable stream.
  const ws = fs.createWriteStream(`${filesDir}/write.txt`);
  // Copy files in paused mode. 
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
}

function copyFileWithData(): void {
  // Create a readable stream.
  const rs = fs.createReadStream(`${filesDir}/read.txt`);
  // Create a writable stream.
  const ws = fs.createWriteStream(`${filesDir}/write.txt`);
  // Copy files in flowing mode.
  rs.on('data', (emitData) => {
    const data = emitData?.data;
    if (!data) {
      return;
    }
    ws.write(data as Uint8Array);
  });
}

```

The following example demonstrates how to use a file hash stream.

```ts
// pages/xxx.ets
import { fileIo as fs } from '@kit.CoreFileKit';
import { hash } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function hashFileWithStream() {
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
