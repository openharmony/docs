# 应用触发数据备份/恢复（仅对系统应用开放）

备份恢复是为设备上应用数据、公共数据和系统服务提供的完整的数据备份和恢复解决方案。系统应用开发者可以根据需求，按下述指导开发应用，以触发备份/恢复数据。

- [获取能力文件](#获取能力文件)：获取当前系统用户内所有应用与备份恢复相关基础信息的能力文件。能力文件在应用备份/恢复数据时不可缺少。

- [应用备份数据](#应用备份数据)：根据能力文件提供的应用信息，选择需要备份的应用数据并进行备份。

- [应用恢复数据](#应用恢复数据)：根据能力文件提供的应用信息，选择需要恢复的应用数据并进行恢复。

- [应用恢复数据时安装应用](#应用恢复数据时安装应用)：应用恢复数据的拓展功能，当用于恢复数据的应用未安装时，建议使用此功能，设备将先安装应用再恢复数据。

## 开发说明

备份恢复API的使用指导请参见[API参考](../reference/apis/js-apis-file-backup.md)。

在使用备份恢复接口之前，需要：

1. [申请相关权限](../security/accesstoken-guidelines.md)：`ohos.permission.BACKUP`

2. 导入依赖模块：`@ohos.file.backup`

   ```js
   import backup from '@ohos.file.backup';
   ```

## 获取能力文件

获取当前系统用户内所有应用与备份恢复相关基础信息的能力文件。能力文件在应用备份恢复数据时是不可缺少的，开发者可以根据需要获取能力文件。

该文件包含设备类型、设备版本、应用的基础性信息，如应用名称、应用数据大小、应用版本信息、是否支持备份恢复、是否在恢复时安装应用。

调用`backup.getLocalCapabilities()`获取能力文件。

```ts
import backup from '@ohos.file.backup';
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

async function getLocalCapabilities(): Promise<void> {
 try {
   let fileData = await backup.getLocalCapabilities();
   console.info('getLocalCapabilities success');
   let fpath = filesDir + '/localCapabilities.json';
   fs.copyFileSync(fileData.fd, fpath);
   fs.closeSync(fileData.fd);
 } catch (error) {
   let err: BusinessError = error as BusinessError;
   console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
 }
}
```

**返回的能力文件内容示例：**

| 属性名称       | 数据类型 | 必填 | 含义                   |
| -------------- | -------- | ---- | ---------------------- |
| bundleInfos    | 数组     | 是   | 应用信息列表           |
| &nbsp;&nbsp;&nbsp;&nbsp; allToBackup    | 布尔值   | 是   | 是否允许备份恢复       |
| &nbsp;&nbsp;&nbsp;&nbsp; extensionName  | 字符串   | 是   | 应用的扩展名           |
| &nbsp;&nbsp;&nbsp;&nbsp; name           | 字符串   | 是   | 应用的包名             |
| &nbsp;&nbsp;&nbsp;&nbsp; needToInstall  | 布尔值   | 是   | 应用恢复时是否需要安装 |
| &nbsp;&nbsp;&nbsp;&nbsp; spaceOccupied  | 数值     | 是   | 应用数据占用的空间大小 |
| &nbsp;&nbsp;&nbsp;&nbsp; versionCode    | 数值     | 是   | 应用的版本号           |
| &nbsp;&nbsp;&nbsp;&nbsp; versionName    | 字符串   | 是   | 应用的版本名称         |
| deviceType     | 字符串   | 是   | 设备类型               |
| systemFullName | 字符串   | 是   | 设备版本               |

```json
{
"bundleInfos" :[{
 "allToBackup" : true,
 "extensionName" : "BackupExtensionAbility",
 "name" : "com.example.hiworld",
 "needToInstall" : false,
 "spaceOccupied" : 0,
 "versionCode" : 1000000,
 "versionName" : "1.0.0"
 }],
"deviceType" : "default",
"systemFullName" : "OpenHarmony-4.0.0.0"
}
```

## 应用备份数据

开发者可以根据能力文件提供的应用信息，选择需要备份的应用数据。

备份过程中，备份恢复服务会将应用的数据打包成文件，打包后的文件会以打开的文件句柄形式，通过创建实例时所注册的回调[onFileReady](../reference/apis/js-apis-file-backup.md#onfileready)接口返回。

开发者可以根据需要将文件内容保存到本地。

**示例**

 ```ts
  import backup from '@ohos.file.backup';
  import common from '@ohos.app.ability.common';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  // 获取沙箱路径
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;
  // 创建SessionBackup类的实例用于备份数据
  let g_session: backup.SessionBackup;
  function createSessionBackup(): backup.SessionBackup {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.info('onFileReady err: ' + JSON.stringify(err));
        }
        try {
          let bundlePath = filesDir + '/' + file.bundleName;
          if (!fs.accessSync(bundlePath)) {
            fs.mkdirSync(bundlePath);
          }
          fs.copyFileSync(file.fd, bundlePath + `/${file.uri}`);
          fs.closeSync(file.fd);
          console.info('onFileReady success');
        } catch (e) {
          console.error('onFileReady failed with err: ' + e);
        }
      },
      onBundleBegin: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.info('onBundleBegin err: ' + JSON.stringify(err));
        } else {
          console.info('onBundleBegin bundleName: ' + bundleName);
        }
      },
      onBundleEnd: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.info('onBundleEnd err: ' + JSON.stringify(err));
        } else {
          console.info('onBundleEnd bundleName: ' + bundleName);
        }
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.info('onAllBundlesEnd err: ' + JSON.stringify(err));
        } else {
          console.info('onAllBundlesEnd');
        }
      },
      onBackupServiceDied: () => {
        console.info('onBackupServiceDied');
      },
    }
    let sessionBackup = new backup.SessionBackup(generalCallbacks);
    return sessionBackup;
  }

  async function sessionBackup (): Promise<void> {
    g_session = createSessionBackup();
    // 此处可根据backup.getLocalCapabilities()提供的能力文件，选择需要备份的应用
    // 也可直接根据应用包名称进行备份
    const backupApps: string[] = [
      "com.example.hiworld",
    ]
    await g_session.appendBundles(backupApps);
    console.info('appendBundles success');
  }
 ```

## 应用恢复数据

开发者可以根据能力文件提供的应用信息，选择需要恢复的应用数据。

恢复过程中，备份恢复服务会根据开发者调用[getFileHandle](../reference/apis/js-apis-file-backup.md#getfilehandle)的请求内容，将应用待恢复数据的文件句柄，通过创建实例时注册的回调[onFileReady](../reference/apis/js-apis-file-backup.md#onfileready)接口返回。可以根据返回的[uri](../reference/apis/js-apis-file-backup.md#filemeta)将应用对应的待恢复数据写入到文件句柄中。写入完成后开发者调用[publishFile](../reference/apis/js-apis-file-backup.md#publishfile)通知服务写入完成。

待应用所有恢复数据准备就绪后，服务开始恢复应用数据。

**示例**

 ```ts
  import backup from '@ohos.file.backup';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  // 创建SessionRestore类的实例用于恢复数据
  let g_session: backup.SessionRestore;
  async function publishFile(file: backup.File): Promise<void> {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: file.uri
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore(): backup.SessionRestore {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.info('onFileReady err: ' + JSON.stringify(err));
        }
        // 此处开发者请根据实际场景待恢复文件存放位置进行调整 bundlePath
        let bundlePath: string = '';
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // 恢复数据传输完成后，会通知服务端文件准备就绪
        publishFile(file);
        console.info('onFileReady success');
      },
      onBundleBegin: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      }
    }
    let sessionRestore = new backup.SessionRestore(generalCallbacks);
    return sessionRestore;
  }

  async function restore01 (): Promise<void> {
    g_session = createSessionRestore();
    const restoreApps: string[] = [
      "com.example.hiworld",
    ]
    // 能力文件的获取方式可以根据开发者实际场景进行调整。此处仅为请求示例
    // 开发者也可以根据能力文件内容的结构示例，自行构造能力文件内容
    let fileData = await backup.getLocalCapabilities();
    await g_session.appendBundles(fileData.fd, restoreApps);
    console.info('appendBundles success');
    // 添加需要恢复的应用成功后，请根据需要恢复的应用名称，调用getFileHandle接口获取待恢复应用数文件的文件句柄
    // 应用待恢复数据文件数请依据实际备份文件个数为准，此处仅为请求示例
    let handle: backup.FileMeta = {
      bundleName: restoreApps[0],
      uri: "manage.json"
    }
    await g_session.getFileHandle(handle);
    handle.uri = "1.tar";
    await g_session.getFileHandle(handle);
    console.info('getFileHandle success');
  }
 ```

## 应用恢复数据时安装应用

开发者在恢复数据时可以选择先安装应用后再进行恢复应用数据。与[应用恢复数据](#应用恢复数据)相比需要修改[能力文件](#获取能力文件)中`bundleInfos`数组内的`needToInstall`字段修改为`true`。

> **说明：**
>
> - [应用备份数据](#应用备份数据)不支持备份应用安装包，因此开发者需要自行准备应用安装包。
> - 开发者在调用[getFileHandle](../reference/apis/js-apis-file-backup.md#getfilehandle)时，传入固定的`FileMeta.uri`=`"/data/storage/el2/restore/bundle.hap"`，用于获取应用安装包的文件句柄。与应用恢复数据时一致，应用安装包的文件句柄，通过创建实例时注册的回调onFileReady接口返回给开发者，返回的`File.uri`=`"/data/storage/el2/restore/bundle.hap"`。

**示例**

 ```ts
  import backup from '@ohos.file.backup';
  import common from '@ohos.app.ability.common';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  // 获取沙箱路径
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;
  // 创建SessionRestore类的实例用于恢复数据
  let g_session: backup.SessionRestore;
  async function publishFile(file: backup.File): Promise<void> {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: file.uri
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore(): backup.SessionRestore {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.info('onFileReady err: ' + JSON.stringify(err));
        }
        let bundlePath: string = '';
        if( file.uri == "/data/storage/el2/restore/bundle.hap" )
        {
          // 此处开发者请根据实际场景安装包的存放位置进行调整
        } else {
          // 此处开发者请根据实际场景待恢复文件存放位置进行调整 bundlePath
        }
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // 恢复数据传输完成后，会通知服务端文件准备就绪
        publishFile(file);
        console.info('onFileReady success');
      },
      onBundleBegin: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      }
    }
    let sessionRestore = new backup.SessionRestore(generalCallbacks);
    return sessionRestore;
  }

  async function restore02 (): Promise<void> {
    g_session = createSessionRestore();
    const restoreApps: string[] = [
      "com.example.hiworld",
    ]
    let fpath = filesDir + '/localCapabilities.json';
    let file = fs.openSync(fpath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    let content = "{\"bundleInfos\" :[{\"allToBackup\" : false,\"extensionName\" : \"\"," +
    "\"name\" : \"cn.openharmony.inputmethodchoosedialog\",\"needToInstall\" : true,\"spaceOccupied\" : 0," +
    "\"versionCode\" : 1000000,\"versionName\" : \"1.0.0\"}],\"deviceType\" : \"default\",\"systemFullName\"   : \"OpenHarmony-4.0.6.2(Canary1)\"}";
    fs.writeSync(file.fd, content);
    fs.fsyncSync(file.fd);
    await g_session.appendBundles(file.fd, restoreApps);
    console.info('appendBundles success');

    // 开发者需要请求安装应用的文件句柄
    let handle: backup.FileMeta = {
      bundleName: restoreApps[0],
      uri: "/data/storage/el2/restore/bundle.hap"
    }
    await g_session.getFileHandle(handle);
    handle.uri = "manage.json";
    await g_session.getFileHandle(handle);
    handle.uri = "1.tar";
    await g_session.getFileHandle(handle);
    console.info('getFileHandle success');
  }
 ```

  **恢复数据时安装应用所需的能力文件内容示例：**
 ```json
 {
  "bundleInfos" :[{
    "allToBackup" : true,
    "extensionName" : "BackupExtensionAbility",
    "name" : "com.example.hiworld",
    "needToInstall" : true,
    "spaceOccupied" : 0,
    "versionCode" : 1000000,
    "versionName" : "1.0.0"
    }],
  "deviceType" : "default",
  "systemFullName" : "OpenHarmony-4.0.0.0"
 }
 ```
