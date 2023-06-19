# 应用文件上传下载

应用可以将应用文件上传到网络服务器，也可以从网络服务器下载网络资源文件到本地应用文件目录。

## 上传应用文件

开发者可以使用上传下载模块（[ohos.request](../reference/apis/js-apis-request.md)）的上传接口将本地文件上传。文件上传过程使用系统服务代理完成。

> **说明：**
>
> 当前上传应用文件功能，仅支持上传应用缓存文件路径（cacheDir）下的文件。
>
> 使用上传下载模块，需[申请相关权限](../security/accesstoken-guidelines.md)：ohos.permission.INTERNET。

以下示例代码演示了如何将应用缓存文件路径下的文件上传至网络服务器。

```ts
// pages/xxx.ets
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import request from '@ohos.request';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let cacheDir = context.cacheDir;

// 新建一个本地应用文件
let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
fs.writeSync(file.fd, 'upload file test');
fs.closeSync(file);

// 上传任务配置项
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

// 将本地应用文件上传至网络服务器
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

## 下载网络资源文件至应用文件目录

开发者可以使用上传下载模块（[ohos.request](../reference/apis/js-apis-request.md)）的下载接口将网络资源文件下载到应用文件目录。对已下载的网络资源文件，开发者可以使用基础文件IO接口（[ohos.file.fs](../reference/apis/js-apis-file-fs.md)）对其进行访问，使用方式与[应用文件访问](app-file-access.md)一致。文件下载过程使用系统服务代理完成。

> **说明：**
>
> 当前网络资源文件仅支持下载至应用文件目录。
>
> 使用上传下载模块，需[申请相关权限](../security/accesstoken-guidelines.md)：ohos.permission.INTERNET。

以下示例代码演示了如何将网络资源文件下载到应用文件目录：

```ts
// pages/xxx.ets
// 将网络资源文件下载到应用文件目录并读取一段内容
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import request from '@ohos.request';

// 获取应用文件路径
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
