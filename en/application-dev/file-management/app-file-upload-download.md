# Uploading and Downloading an Application File

This topic describes how to enable an application to upload an application file to a network server and download a network resource file from a network server to a local application directory.

## Uploading an Application File

You can use [ohos.request](../reference/apis/js-apis-request.md) **uploadFile()** to upload local files. The system service proxy implements the upload.

> **NOTE**
>
> Currently, only the files in the **cache/** directories (**cacheDir**) can be uploaded.
>
> The **ohos.permission.INTERNET** permission is required for using **ohos.request**. For details about how to apply for a permission, see [Applying for Permissions](../security/accesstoken-guidelines.md).

The following example demonstrates how to upload a file in the **cache** directory of an application to a network server.

```ts
// pages/xxx.ets
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import request from '@ohos.request';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let cacheDir = context.cacheDir;

// Create an application file locally.
let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
fs.writeSync(file.fd, 'upload file test');
fs.closeSync(file);

// Configure the upload task.
let uploadConfig = {
  url: 'https://xxx',
  header: { key1: 'value1', key2: 'value2' },
  method: 'POST',
  files: [
    { filename: 'test.txt', name: 'test', uri: 'internal://cache/test.txt', type: 'txt' }
  ],
  data: [
    { name: 'name', value: 'value' }
  ]
}

// Upload the created application file to the network server.
try {
  request.uploadFile(context, uploadConfig)
    .then((uploadTask) => {
      uploadTask.on('complete', (taskStates) => {
        for (let i = 0; i < taskStates.length; i++) {
          console.info(`upload complete taskState: ${JSON.stringify(taskStates[i])}`);
        }
      });
    })
    .catch((err) => {
      console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (err) {
  console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
}
```

## Downloading a Network Resource File to the Application File Directory

You can use [ohos.request](../reference/apis/js-apis-request.md) **downloadFile()** to download network resource files to a local application directory. You can use the [ohos.file.fs](../reference/apis/js-apis-file-fs.md) APIs to access the downloaded files in the same way as [accessing application files](app-file-access.md). The system service proxy implements the download.

> **NOTE**
>
> Currently, network resource files can be downloaded only to an application file directory.
>
> The **ohos.permission.INTERNET** permission is required for using **ohos.request**. For details about how to apply for a permission, see [Applying for Permissions](../security/accesstoken-guidelines.md).

The following example demonstrates how to download a network resource file to a local application file directory.

```ts
// pages/xxx.ets
// Download the network resource file to the local application file directory, and read data from the file.
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import request from '@ohos.request';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

try {
  request.downloadFile(context, {
    url: 'https://xxxx/xxxx.txt',
    filePath: filesDir + '/xxxx.txt'
  }).then((downloadTask) => {
    downloadTask.on('complete', () => {
      console.info('download complete');
      let file = fs.openSync(filesDir + '/xxxx.txt', fs.OpenMode.READ_WRITE);
      let buf = new ArrayBuffer(1024);
      let readLen = fs.readSync(file.fd, buf);
      console.info(`The content of file: ${String.fromCharCode.apply(null, new Uint8Array(buf.slice(0, readLen)))}`);
      fs.closeSync(file);
    })
  }).catch((err) => {
    console.error(`Invoke downloadTask failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  console.error(`Invoke downloadFile failed, code is ${err.code}, message is ${err.message}`);
}
```
