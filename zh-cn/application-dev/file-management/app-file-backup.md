# 应用触发数据备份/恢复（仅对系统应用开放）

备份恢复框架是为设备上的应用、服务提供自身数据备份和恢复的解决方案。系统应用开发者可以根据需求，按下述指导开发应用，以触发备份/恢复数据。

- [获取能力文件](#获取能力文件)：获取当前系统用户内所有应用与备份恢复相关基础信息的能力文件。能力文件在应用备份/恢复数据时不可缺少。

- [应用备份数据](#应用备份数据)：根据能力文件提供的应用信息，选择需要备份的应用数据并进行备份。

- [应用恢复数据](#应用恢复数据)：根据能力文件提供的应用信息，选择需要恢复的应用数据并进行恢复。

## 开发说明

备份恢复API的使用指导请参见[API参考](../reference/apis-core-file-kit/js-apis-file-backup-sys.md)。

在使用备份恢复接口之前，需要：

1. [申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)：`ohos.permission.BACKUP`

2. 导入依赖模块：`@ohos.file.backup`

   ```js
   import backup from '@ohos.file.backup';
   ```

## 获取能力文件

获取当前系统用户内所有应用与备份恢复相关基础信息的能力文件。能力文件在应用备份恢复数据时是不可缺少的，开发者可以根据需要获取能力文件。

该文件包含设备类型、设备版本、应用的基础性信息。如应用名称、应用数据大小、应用版本信息、是否支持备份恢复、是否在恢复时安装应用。

调用[backup.getLocalCapabilities()](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#backupgetlocalcapabilities)获取能力文件。

```ts
import backup from '@ohos.file.backup';
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
async function getLocalCapabilities(context: common.UIAbilityContext): Promise<void> {
 try {
   let filesDir = context.filesDir;
   let fileData = await backup.getLocalCapabilities();
   console.info('getLocalCapabilities success');
   let fpath = filesDir + '/localCapabilities.json';
   fs.copyFileSync(fileData.fd, fpath);
   fs.closeSync(fileData.fd);
 } catch (error) {
   let err: BusinessError = error as BusinessError;
   console.error(`getLocalCapabilities failed with err, code is ${err.code}, message is ${err.message}`);
 }
}
```

**返回的能力文件内容示例：**

| 属性名称       | 数据类型 | 必填 | 含义                   |
| -------------- | -------- | ---- | ---------------------- |
| bundleInfos    | 数组     | 是   | 应用信息列表。           |
| allToBackup    | 布尔值   | 是   | 是否允许备份恢复。true表示允许，false表示不允许。       |
| extensionName  | 字符串   | 是   | 应用的扩展名。           |
| name           | 字符串   | 是   | 应用的包名。             |
| spaceOccupied  | 数值     | 是   | 应用数据占用的空间大小（单位为Byte）。 |
| versionCode    | 数值     | 是   | 应用的版本号。           |
| versionName    | 字符串   | 是   | 应用的版本名称。         |
| deviceType     | 字符串   | 是   | 设备类型。               |
| systemFullName | 字符串   | 是   | 设备版本。               |

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

备份过程中，备份恢复服务会将应用的数据打包成文件，打包后的文件会以打开的文件句柄形式，通过创建实例时所注册的回调[onFileReady](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#onfileready)接口返回。

开发者可以根据需要将文件内容保存到本地。

**示例**

  ```ts
  import backup from '@ohos.file.backup';
  import common from '@ohos.app.ability.common';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  appfileDir: string = '';
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  this.appfileDir = context.filesDir;
  // 创建SessionBackup类的实例用于备份数据
  let g_session: backup.SessionBackup;
  function createSessionBackup(fileDir: string): backup.SessionBackup {
    let generalCallbacks: backup.GeneralCallbacks = {
      // onFileReady为服务回调给应用侧数据完成的通知，建议开发者在该接口内不要进行过多的耗时实现，可以通过异步线程实现file.fd数据的处理
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error(`onFileReady err, code is ${err.code}, message is ${err.message}`);
        }
        try {
          let bundlePath = filesDir + '/' + file.bundleName;
          if (!fs.accessSync(bundlePath)) {
            fs.mkdirSync(bundlePath);
          }
          // 此处执行copyFileSync会多一次内存拷贝，开发者可以直接使用onFileReady的file.fd来进行数据出来，处理完成后close即可，这样会减少内存消耗
          fs.copyFileSync(file.fd, bundlePath + `/${file.uri}`);
          fs.closeSync(file.fd);
          console.info('onFileReady success');
        } catch (e) {
          console.error('onFileReady failed with err: ' + e);
        }
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleBegin err, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('onBundleBegin bundleName: ' + bundleName);
        }
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleEnd err, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('onBundleEnd bundleName: ' + bundleName);
        }
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error(`onAllBundlesEnd err, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('onAllBundlesEnd');
        }
      },
      onBackupServiceDied: () => {
        console.info('onBackupServiceDied');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport  bundleName: ' + bundleName);
        console.info('onResultReport  result: ' + result);
      },
      onProcess:(bundleName: string, process: string) => { 
        console.info('onPross bundleName: ' + JSON.stringify(bundleName));
        console.info('onPross result: ' + JSON.stringify(process));
      }
    }
    let sessionBackup = new backup.SessionBackup(generalCallbacks);
    return sessionBackup;
  }

  async function sessionBackup (fileDir: string): Promise<void> {
    g_session = createSessionBackup(fileDir);
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

恢复过程中，备份恢复服务会根据开发者调用[getFileHandle](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#getfilehandle)的请求内容，将应用待恢复数据的文件句柄，通过创建实例时注册的回调[onFileReady](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#onfileready)接口返回。可以根据返回的[uri](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#filemeta)将应用对应的待恢复数据写入到文件句柄中。写入完成后开发者调用[publishFile](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#publishfile)通知服务写入完成。

待应用所有恢复数据准备就绪后，服务开始恢复应用数据。

**示例**

  ```ts
  import backup from '@ohos.file.backup';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  // 创建SessionRestore类的实例用于恢复数据
  let g_session: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 123; // 123: 初始化文件个数
  let testBundleName = 'com.example.myapplication'; // 测试包名
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // 初始化计数
  async function publishFile(file: backup.File): Promise<void> {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: ''
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore(): backup.SessionRestore {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error(`onFileReady err, code is ${err.code}, message is ${err.message}`);
        }
        // 此处开发者请根据实际场景待恢复文件存放位置进行调整 bundlePath
        let bundlePath: string = '';
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // 恢复数据传输完成后，会通知服务端文件准备就绪
        countMap[file.bundleName]++;
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // 每个包的所有文件收到后触发publishFile
          publishFile(file);
        }
        console.info('onFileReady success');
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleBegin failed with err, code is ${err.code}, message is ${err.message}`);
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleEnd failed with err, code is ${err.code}, message is ${err.message}`);
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error(`onAllBundlesEnd failed with err, code is ${err.code}, message is ${err.message}`);
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport  bundleName: ' + bundleName);
        console.info('onResultReport  result: ' + result);
      },
      onProcess:(bundleName: string, process: string) => { 
        console.info('onPross bundleName: ' + JSON.stringify(bundleName));
        console.info('onPross result: ' + JSON.stringify(process));
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
