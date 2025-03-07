# Uploading and Downloading Application Files

This topic describes how to upload an application file to a network server and download a network resource file from a network server to a local application file directory.

## Uploading an Application File

You can use **uploadFile()** in [ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md) to upload local files. The system service agent uploads the files. In API version 12, you can set the address of the agent in **request.agent.create()**.

> **NOTE**
>
> Currently, only the files in the **cache/** directory (specified by **cacheDir**) can be uploaded.
>
> To use **uploadFile()** in **ohos.request**, you need to [declare permissions](../../security/AccessToken/declare-permissions.md): ohos.permission.INTERNET.

The following code demonstrates how to upload files from a cache directory of an application to a network server in two ways:

```ts
// Way 1: Use request.uploadFile.
// pages/xxx.ets
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let cacheDir = context.cacheDir;

// Create an application file locally.
let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
fs.writeSync(file.fd, 'upload file test');
fs.closeSync(file);

// Configure the upload task.
let files: Array<request.File> = [
// "internal://cache" in uri corresponds to the cacheDir directory.
  { filename: 'test.txt', name: 'test', uri: 'internal://cache/test.txt', type: 'txt' }
]
let data: Array<request.RequestData> = [{ name: 'name', value: 'value' }];
let uploadConfig: request.UploadConfig = {
  url: 'https://xxx',
  header: {
    'key1':'value1',
    'key2':'value2'
  },
  method: 'POST',
  files: files,
  data: data
}

// Upload the created application file to the network server.
try {
  request.uploadFile(context, uploadConfig)
    .then((uploadTask: request.UploadTask) => {
      uploadTask.on('complete', (taskStates: Array<request.TaskState>) => {
        for (let i = 0; i < taskStates.length; i++) {
          console.info(`upload complete taskState: ${JSON.stringify(taskStates[i])}`);
        }
      });
    })
    .catch((err: BusinessError) => {
      console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
}
```

```ts
// Way 2: Use request.agent.
// pages/xxx.ets
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';
// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let cacheDir = context.cacheDir;

// Create an application file locally.
let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
fs.writeSync(file.fd, 'upload file test');
fs.closeSync(file);
let attachments: Array<request.agent.FormItem> = [{
  name: "test",
  value: [
    {
      filename: "test.txt",
      path: "./test.txt",
    },
  ]
}];
let config: request.agent.Config = {
  action: request.agent.Action.UPLOAD,
  url: 'http://xxx',
  mode: request.agent.Mode.FOREGROUND,
  overwrite: true,
  method: "POST",
  headers: {
    'key1':'value1',
    'key2':'value2'
  },
  data: attachments,
  saveas: "./"
};
request.agent.create(getContext(), config).then((task: request.agent.Task) => {
  task.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the upload task, Code: ${err.code}  message: ${err.message}`);
      return;
    }
  });
  task.on('progress', async(progress) => {
    console.warn(`/Request upload status ${progress.state}, uploaded ${progress.processed}`);
  })
  task.on('completed', async() => {
    console.warn(`/Request upload completed`);
    // This method requires the user to manage the task lifecycle. After the task is complete, call the remove method to release the task object.
    request.agent.remove(task.tid);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
});
```

## Downloading a Network Resource File to an Application Directory

You can use **downloadFile()** in [ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md) to download network resource files to a local application directory. You can use the [ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md) APIs to access the downloaded files. For details, see [Accessing Application Files](../../file-management/app-file-access.md). The system service agent downloads the files. In API version 12, you can set the address of the agent in **request.agent.create()**.

> **NOTE**
>
> Currently, network resource files can be downloaded only to the application file directory.
>
> To use **uploadFile()** in **ohos.request**, you need to [declare permissions](../../security/AccessToken/declare-permissions.md): ohos.permission.INTERNET.

The following code demonstrates how to download files from a network server to an application directory in two ways:

```ts
// Way 1: Use request.downloadFile.
// pages/xxx.ets
// Download the network resource file to the local application file directory, and read data from the file.
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

// Obtain the application file path.
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

try {
  request.downloadFile(context, {
    url: 'https://xxxx/xxxx.txt',
    filePath: filesDir + '/xxxx.txt'
  }).then((downloadTask: request.DownloadTask) => {
    downloadTask.on('complete', () => {
      console.info('download complete');
      let file = fs.openSync(filesDir + '/xxxx.txt', fs.OpenMode.READ_WRITE);
      let arrayBuffer = new ArrayBuffer(1024);
      let readLen = fs.readSync(file.fd, arrayBuffer);
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`The content of file: ${buf.toString()}`);
      fs.closeSync(file);
    })
  }).catch((err: BusinessError) => {
    console.error(`Invoke downloadTask failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Invoke downloadFile failed, code is ${err.code}, message is ${err.message}`);
}
```
```ts
// Way 2: Use request.agent.
// pages/xxx.ets
// Download the network resource file to the local application file directory, and read data from the file.
import { BusinessError, request } from '@kit.BasicServicesKit';
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

let config: request.agent.Config = {
  action: request.agent.Action.DOWNLOAD,
  url: 'https://xxxx/test.txt',
  saveas: 'xxxx.txt',
  gauge: true,
  overwrite: true,
  network: request.agent.Network.WIFI,
};
request.agent.create(context, config).then((task: request.agent.Task) => {
  task.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
      return;
    }
  });
  task.on('progress', async(progress) => {
    console.warn(`/Request download status ${progress.state}, downloaded ${progress.processed}`);
  })
  task.on('completed', async() => {
    console.warn(`/Request download completed`);
    let file = fs.openSync(filesDir + '/xxxx.txt', fs.OpenMode.READ_WRITE);
    let arrayBuffer = new ArrayBuffer(1024);
    let readLen = fs.readSync(file.fd, arrayBuffer);
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`The content of file: ${buf.toString()}`);
    fs.closeSync(file);
    // This method requires the user to manage the task lifecycle. After the task is complete, call the remove method to release the task object.
    request.agent.remove(task.tid);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
});
```
