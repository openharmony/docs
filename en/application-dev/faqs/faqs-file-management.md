# File Management Development

## How do I obtain the path of system screenshots?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

The screenshots are stored in **/storage/media/100/local/files/Pictures/Screenshots/**.

## How do I change the permissions on a directory to read/write on a device?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Symptom**

When the hdc command is used to send a file to a device, "permission denied" is displayed.

**Solution**

Run the **hdc shell mount -o remount,rw /** command to grant the read/write permissions.

## What is the best way to create a file if the file to open does not exist?

Applicable to: OpenHarmony 3.2 (API version 9)

**Solution**

Use **fs.open(path: string, mode?: number)** with **mode** set to **fs.OpenMode.CREATE**. **fs.OpenMode.CREATE** creates a file if it does not exist.

## How do I solve the problem of garbled Chinese characters in a file?

Applicable to: OpenHarmony 3.2 (API version 9)

**Solution**

After the buffer data of the file is read, use **TextDecoder** of @ohos.util to decode the file content.

```
let filePath = getContext(this).filesDir + "/test0.txt";
let stream = fs.createStreamSync(filePath, "r+");
let buffer = new ArrayBuffer(4096)
let readOut = stream.readSync(buffer);
let textDecoder = util.TextDecoder.create('utf-8', { ignoreBOM: true })
let readString = textDecoder.decodeWithStream(new Uint8Array(buffer), { stream: false });
console.log ("File content read: "+ readString);
```

## Why is an error reported when fs.copyFile is used to copy a datashare:// file opened by fs.open()?

Applicable to: OpenHarmony 3.2 (API version 9)

**Solution**

**fs.copyFile** does not support URIs. You can use **fs.open()** to obtain the URI, obtain the file descriptor (FD) based on the URI, and then use **fs.copyFile** to copy the file based on the FD.

```
let file = fs.openSync("datashare://...")
fs.copyFile(file.fd, 'dstPath', 0).then(() => {
  console.info('copyFile success')
}).catch((err) => {
  console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);
})
```

## How do I modify the content of a JSON file in a sandbox directory?

Applicable to: OpenHarmony 3.2 (API version 9)

**Solution**

Perform the following steps:

1. Use **fs.openSyn** to obtain the FD of the JSON file.

```
import fs from '@ohos.file.fs';  
let sanFile = fs.open(basePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
let fd = sanFile.fd;
```

2. Use **fs.readSync** to read the file content.

```
let content = fs.readSync(basePath);
```

3. Modify the file content.

```
obj.name = 'new name';
```

4. Use **fs.writeSync** to write the data to the JSON file.

```
fs.writeSync(file.fd, JSON.stringify(obj));
```

For more information, see [@ohos.file.fs](../reference/apis/js-apis-file-fs.md).

## What is the real path corresponding to the file path obtained through the FileAccess module?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Solution**

The files are stored in the **/storage/media/100/local/files** directory. The specific file path varies with the file type and source. To obtain the file path based on the file name, run the following command in the **/storage/media/100/local/files** directory:<br>-name \[filename\]

For more information, see [Uploading and Downloading an Application File](../file-management/app-file-upload-download.md).

## How do I listen for the changes of a file or folder?

Applicable to: OpenHarmony SDK 4.0 Release API 10

**Solution**

You can use **fs.createWatcher** to listen for the changes of a file or folder with the registered callback.

**References**

[@ohos.file.fs](../reference/apis/js-apis-file-fs.md#fscreatewatcher10)
