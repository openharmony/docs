# Accessing Application Files

This topic describes how to enable an application to view, create, read, write, delete, move, or copy an application and obtain file information.

## Available APIs

You can use [ohos.file.fs](../reference/apis/js-apis-file-fs.md) to implement access to application files. The following table describes the APIs.

**Table 1** APIs for basic application file operations

| API| Description| Type| Synchronous Programming| Asynchronous Programming|
| -------- | -------- | -------- | -------- | -------- |
| access | Checks whether a file exists.| Method| √ | √ |
| close | Closes a file.| Method| √ | √ |
| copyFile | Copies a file.| Method| √ | √ |
| createStream | Creates a stream based on the specified file path.| Method| √ | √ |
| listFile | Lists all files in a directory.| Method| √ | √ |
| mkdir | Creates a directory.| Method| √ | √ |
| moveFile | Moves a file.| Method| √ | √ |
| open | Opens a file.| Method| √ | √ |
| read | Reads data from a file.| Method| √ | √ |
| rename | Renames a file or folder.| Method| √ | √ |
| rmdir | Deletes a directory.| Method| √ | √ |
| stat | Obtains detailed file information.| Method| √ | √ |
| unlink | Deletes a single file.| Method| √ | √ |
| write | Writes data to a file.| Method| √ | √ |
| Stream.close | Closes a stream.| Method| √ | √ |
| Stream.flush | Flushes all data from this stream.| Method| √ | √ |
| Stream.write | Writes data to a stream.| Method| √ | √ |
| Stream.read | Reads data from a stream.| Method| √ | √ |
| File.fd | Defines a file descriptor.| Attribute| √ | × |
| OpenMode | Defines the mode for opening a file.| Attribute| √ | × |
| Filter | Defines the options for setting the file filter.| Type| × | × |

## Development Example

First, obtain the [application file path](../application-models/application-context-stage.md#obtaining-application-file-paths). The following example shows how to obtain a HAP file path using **UIAbilityContext**. For details about how to obtain **UIAbilityContext**, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

Then, perform common file operations.

### Creating, Reading, and Writing a File

The following example demonstrates how to create a file, read data from it, and write data to it.

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

function createFile() {
  // Obtain the application file path.
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;

  // Create a file and open it.
  let file = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Write data to the file.
  let writeLen = fs.writeSync(file.fd, "Try to write str.");
  console.info("The length of str is: " + writeLen);
  // Read data from the file.
  let buf = new ArrayBuffer(1024);
  let readLen = fs.readSync(file.fd, buf, { offset: 0 });
  console.info("the content of file: " + String.fromCharCode.apply(null, new Uint8Array(buf.slice(0, readLen))));
  // Close the file.
  fs.closeSync(file);
}
```

### Copying Data to Another File

  The following example demonstrates how to read data from a file and write it to another file.

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

function readWriteFile() {
  // Obtain the application file path.
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;

  // Open the source and destination files.
  let srcFile = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE);
  let destFile = fs.openSync(filesDir + '/destFile.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // Read data from the source file and copy it to the destination file.
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  let readLen = fs.readSync(srcFile.fd, buf, { offset: readSize });
  while (readLen > 0) {
    readSize += readLen;
    fs.writeSync(destFile.fd, buf);
    readLen = fs.readSync(srcFile.fd, buf, { offset: readSize });
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

async function readWriteFileWithStream() {
  // Obtain the application file path.
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;

  // Open the file streams.
  let inputStream = fs.createStreamSync(filesDir + '/test.txt', 'r+');
  let outputStream = fs.createStreamSync(filesDir + '/destFile.txt', "w+");
  // Read data from the source file and write the data to the destination file using a stream.
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  let readLen = await inputStream.read(buf, { offset: readSize });
  readSize += readLen;
  while (readLen > 0) {
    await outputStream.write(buf);
    readLen = await inputStream.read(buf, { offset: readSize });
    readSize += readLen;
  }
  // Close the streams.
  inputStream.closeSync();
  outputStream.closeSync();
}
```

> **NOTE**
>
> - Close the stream that is no longer used in a timely manner. 
> - Comply with the programming specifications for **Stream** APIs in asynchronous mode and avoid mixed use of the APIs in synchronous mode and asynchronous mode.
> - The **Stream** APIs do not support concurrent read and write operations.

### Listing Files

The following example demonstrates how to list files that meet the specified conditions.

```ts
// List files.
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

// List files that meet the specified conditions.
let options = {
  recursion: false,
  listNum: 0,
  filter: {
    suffix: ['.png', '.jpg', '.txt'],          // The filename extension can be '.png', '.jpg', or '.txt'.
    displayName: ['test%'],                    // The filename starts with 'test'.
    fileSizeOver: 0,                           // The file size is greater than or equal to 0.
    lastModifiedAfter: new Date(0).getTime(),  // The latest modification time of the file is later than January 1, 1970.
  },
}
let files = fs.listFileSync(filesDir, options);
for (let i = 0; i < files.length; i++) {
  console.info(`The name of file: ${files[i]}`);
}
```
