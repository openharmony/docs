# Accessing Application Files (ArkTS)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=96b6842378a3034d6245f6b77a19ff25d0ceba9c translatedAt=2026-08-01T07:24:00.361Z pushedAt=2026-08-01T07:40:07.846Z -->

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
| File.fd | Obtains a file descriptor.| Attribute| N/A| N/A|
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
import { fileIo, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { buffer } from '@kit.ArkTS';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

```

<!--@[create_and_read_File](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function createFile(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;
  let file: fileIo.File | null = null;
  try {
    // Create and open the file if it does not exist, and open the file if it exists.
    file = fileIo.openSync(filesDir + '/test.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    // Write a piece of content to the file.
    let writeLen = fileIo.writeSync(file.fd, 'Hello world');
    console.info('The length of str is: ' + writeLen);
    // Create an ArrayBuffer object of 1024 bytes to store data read from the file.
    let arrayBuffer = new ArrayBuffer(1024);
    // Set the read offset and length, in bytes.
    let readOptions: ReadOptions = {
      offset: 0,
      length: arrayBuffer.byteLength
    };
    // Read file content into the ArrayBuffer object and return the number of bytes actually read.
    let readLen = fileIo.readSync(file.fd, arrayBuffer, readOptions);
    // Convert the ArrayBuffer object to a Buffer object, and then convert it to a string for output.
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info('Succeeded in creating file, the content of file: ' + buf.toString());
  } catch (err) {
    console.error(`Failed to create file. Code: ${err.code}, message: ${err.message}`);
  } finally {
    if (file) {
      try {
        fileIo.closeSync(file);
      } catch (err) {
        console.error(`Failed to close file`);
      }
    }
  }
}
```

### Copying Data to Another File

The following example demonstrates how to read data from a file and copy it to another file.

```ts
// pages/xxx.ets
import { fileIo, ReadOptions, WriteOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

```

<!--@[read_write_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function readWriteFile(context: common.UIAbilityContext): void {
  let srcFile: fileIo.File | null = null;
  let destFile: fileIo.File | null = null;
  try {
    let filesDir = context.filesDir;
    // Open the file in read/write mode. If the file does not exist, create it.
    srcFile = fileIo.openSync(filesDir + '/readFile.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    destFile = fileIo.openSync(filesDir + '/writeFile.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    // Create a buffer.
    let bufSize = 4096;
    let buf = new ArrayBuffer(bufSize);
    let readOffset = 0;
    let readLength = 128;
    // Set the read offset and length, in bytes.
    let readOptions: ReadOptions = {
      offset: readOffset,
      length: readLength
    };
    // Read the source file content in chunks and write it to the target file.
    let readLen = fileIo.readSync(srcFile.fd, buf, readOptions);
    while (readLen > 0) {
      readOffset += readLen;
      let writeOptions: WriteOptions = {
        length: readLen
      };
      // Write to the target file.
      fileIo.writeSync(destFile.fd, buf, writeOptions);
      // Update the read position.
      readOptions.offset = readOffset;
      readLen = fileIo.readSync(srcFile.fd, buf, readOptions);
    }
    console.info(`Succeeded in reading and writing file.`);
  } catch (err) {
    console.error(`Failed to read and write File. Code: ${err.code}, message: ${err.message}`);
  } finally {
    try {
      if (srcFile) {
        fileIo.closeSync(srcFile);
      }
      if (destFile) {
        fileIo.closeSync(destFile);
      }
    } catch (closeErr) {
      console.error(`Failed to close file`);
    }
  }
}
```

> **NOTE**
>
> When using **read()** or **write()**, pay attention to the optional parameter **offset**. For a file that has been read or written, **offset** points to the end position of the last read or write operation by default.

### Reading and Writing Files in a Stream

The following sample code shows how to use the **stream()** API to read the **test.txt** file content and write the content to the **destFile.txt** file.

```ts
// pages/xxx.ets
import { fileIo, ReadOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

```

<!--@[read_write_file_with_stream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
async function readWriteFileWithStream(context: common.UIAbilityContext): Promise<void> {
  let filesDir = context.filesDir;
  let inputStream: fileIo.Stream | null = null;
  let outputStream: fileIo.Stream | null = null;
  try {
    // Create and open the input file stream.
    inputStream = fileIo.createStreamSync(filesDir + '/test.txt', 'r+');
    // Create and open the output file stream.
    outputStream = fileIo.createStreamSync(filesDir + '/destFile.txt', 'w+');
    let bufSize = 4096;
    let readSize = 0;
    let buf = new ArrayBuffer(bufSize);
    // Set the read offset and length, in bytes.
    let readOptions: ReadOptions = {
      offset: readSize,
      length: bufSize
    };
    // Read the source file content as a stream and write it to the target file.
    let readLen = await inputStream.read(buf, readOptions);
    readSize += readLen;
    while (readLen > 0) {
      const writeBuf = readLen < bufSize ? buf.slice(0, readLen) : buf;
      await outputStream.write(writeBuf);
      readOptions.offset = readSize;
      readLen = await inputStream.read(buf, readOptions);
      readSize += readLen;
    }
    console.info(`Succeeded in reading and writing file with stream.`);
  } catch (err) {
    console.error(`Failed to read and write file with stream. Code: ${err.code}, message: ${err.message}`);
  } finally {
    try {
      if (inputStream) {
        inputStream.closeSync();
      }
      if (outputStream) {
        outputStream.closeSync();
      }
    } catch (closeErr) {
      console.error(`Failed to close stream`);
    }
  }
}
```

> **NOTE**
>
> Close the stream once it is not required. <br>Comply with the programming specifications for **Stream** APIs in asynchronous mode and avoid mixed use of the APIs in synchronous mode and asynchronous mode. <br>The **Stream** APIs do not support concurrent read and write operations.

### Listing Files

The following example demonstrates how to list files that meet the specified conditions.

```ts
import { fileIo, Filter, ListFileOptions } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

```

<!--@[get_list_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function getListFile(context: common.UIAbilityContext): void {
  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: ['.png', '.jpg', '.txt'],
      displayName: ['test*'],
      fileSizeOver: 0,
      lastModifiedAfter: new Date(0).getTime()
    }
  };
  let filesDir = context.filesDir;
  try {
    let files = fileIo.listFileSync(filesDir, listFileOption);
    for (let i = 0; i < files.length; i++) {
      console.info(`Succeeded in listing file, The name of file: ${files[i]}`);
    }
  } catch (err) {
    console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
  }
}
```

### Using File Streams

The following example demonstrates how to use readable and writable streams.

```ts
// pages/xxx.ets
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

```

<!--@[copy_file_with_readable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function copyFileWithReadable(context: common.UIAbilityContext): void {
  try {
    let filesDir = context.filesDir;
    // Create a readable file stream.
    const rs = fileIo.createReadStream(`${filesDir}/test.txt`);
    // Create a writable file stream.
    const ws = fileIo.createWriteStream(`${filesDir}/destFile.txt`);
    // Copy the file in pause mode. During data copying, the source data is paused and then copied to another location. This mode is suitable for scenarios that require high data integrity and consistency.
    rs.on('readable', () => {
      const data = rs.read();
      if (!data) {
        return;
      }
      ws.write(data);
    });

    rs.on('end', () => {
      ws.end();
      console.info(`Succeeded in copying file with read stream.`);
    });

    // Catch exceptions.
    rs.on('error', () => {
      rs.close();
      ws.close();
    });
  } catch (err) {
    console.error(`Failed to copy file with read stream. Code: ${err.code}, message: ${err.message}`);
  }
}
```

<!--@[copy_file_with_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function copyFileWithData(context: common.UIAbilityContext): void {
  let filesDir = context.filesDir;

  try {
    // Create a readable file stream.
    let rs = fileIo.createReadStream(`${filesDir}/test.txt`);
    // Create a writable file stream.
    let ws = fileIo.createWriteStream(`${filesDir}/destFile.txt`);

    rs.push('Hello world');
    // Copy the file in flowing mode.
    rs.on('data', (emitData) => {
      const data = emitData?.data;
      if (!data) {
        return;
      }
      ws.write(data as Uint8Array);
    });

    rs.on('end', () => {
      ws.end();
      console.info(`Succeeded in copying file with data.`);
    });

    // Catch exceptions.
    rs.on('error', () => {
      rs.close();
      ws.close();
    });
  } catch (err) {
    console.error(`Failed to copy file with data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

### Using File Hash Streams

A hash stream is a data transmission and storage technology that can convert data of any length into a hash value of a fixed length to verify data integrity and consistency. The following code shows how to use the file hash processing API [ohos.file.hash](../reference/apis-core-file-kit/js-apis-file-hash.md) to process file hash streams.

```ts
// pages/xxx.ets
import { fileIo } from '@kit.CoreFileKit';
import { hash } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the application file path. The context should be obtained in the component.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;


```

<!--@[hash_file_with_stream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->

``` TypeScript
function hashFileWithStream(context: common.UIAbilityContext) {
  try {
    let filesDir = context.filesDir;
    const filePath = `${filesDir}/test.txt`;
    // Create a readable file stream.
    const rs = fileIo.createReadStream(filePath);
    // Create a hash stream.
    const hs = hash.createHash('sha256');
    rs.on('data', (emitData) => {
      const data = emitData?.data;
      hs.update(new Uint8Array(data?.split('').map((x: string) => x.charCodeAt(0))).buffer);
    });
    rs.on('end', async () => {
      const hashResult = hs.digest();
      const fileHash = await hash.hash(filePath, 'sha256');
      console.info(`Succeeded in hashing file with stream, hash result: ${hashResult}, file hash: ${fileHash}`);
    });
  } catch (err) {
    console.error(`Failed to hash file with stream. Code: ${err.code}, message: ${err.message}`);
  }
}
```