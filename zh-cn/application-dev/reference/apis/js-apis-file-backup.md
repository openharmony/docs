# @ohos.file.backup (备份恢复)

该模块为应用提供备份/恢复数据的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import backup from '@ohos.file.backup';
```

## FileMeta

文件的元数据，包含一个应用名称以及文件uri。FileMeta在执行备份/恢复时是不可缺少的对象

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称       | 类型   | 必填 | 说明                                                                                           |
| ---------- | ------ | ---- | ---------------------------------------------------------------------------------------------- |
| bundleName | string | 是   | 应用名称，可通过[bundle.BundleInfo](js-apis-bundle-BundleInfo.md)提供的获取方式获取。          |
| uri        | string | 是   | 应用沙箱内待传输文件的名称，当前uri尚未升级为标准格式，仅接受0-9a-zA-Z下划线(_)点(.)组成的名称 |

## FileData

文件的元数据，包含一个已经打开的文件描述符。FileData在执行备份/恢复时是不可缺少的对象

> **说明：**
>
> FileData使用完成后必须关闭，如不关闭会出现内存泄露问题。关闭的方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.closeSync](js-apis-file-fs.md#fsclosesync)等相关关闭接口。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型   | 必填 | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | 是   | 已经打开的文件描述符，通过备份服务获取。 |

## File

一个文件对象。
继承[FileMeta](#filemeta)和[FileData](#filedata)

> **说明：**
>
> file.backup.File与@ohos.file.fs中的提供的[File](js-apis-file-fs.md#file)是带有不同的涵义，前者是继承[FileMeta](#filemeta)和[FileData](#filedata)的对象而后者只有一个文件描述符的对象。请注意做区分，不要混淆。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

## GeneralCallbacks

备份/恢复过程中的通用回调，备份服务将通过这些回调通知客户端其应用的备份/恢复阶段。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

### onFileReady

onFileReady : AsyncCallback&lt;File&gt;

回调函数。当服务端返向客户端发送文件成功时触发回调，err为undefined，否则为错误对象。

> **说明：**
>
> AsyncCallback回调中返回的File 所属file.backup.[File](#file)类型，返回的文件归备份服务所有，一旦文件关闭，备份服务将选择合适的时机去清理，但客户端必须关闭文件句柄。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  onFileReady: (err: BusinessError, file: backup.File) => {
    if (err) {
      console.error('onFileReady failed with err: ' + JSON.stringify(err));
    }
    console.info('onFileReady success with file: ' + file.bundleName + ' ' + file.uri);
    fs.closeSync(file.fd);
  }
  ```

### onBundleBegin

onBundleBegin : AsyncCallback&lt;string&gt;

 回调函数。当应用备份/恢复开始时返回bundle名称成功时触发回调，err为undefined，否则为错误对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  onBundleBegin: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
    }
    console.info('onBundleBegin success with bundleName: ' + bundleName);
  }
  ```

### onBundleEnd

onBundleEnd : AsyncCallback&lt;string&gt;

回调函数。当应用备份/恢复结束后返回bundle名称成功时触发回调，err为undefined，否则为错误对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  onBundleEnd: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
    }
    console.info('onBundleEnd success with bundleName: ' + bundleName);
  }
  ```

### onAllBundlesEnd

onAllBundlesEnd : AsyncCallback&lt;undefined&gt;

回调函数。当所有bundle的备份/恢复过程结束成功时触发回调，err为undefined，否则为错误对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  onAllBundlesEnd: (err: BusinessError) => {
    if (err) {
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
    }
    console.info('onAllBundlesEnd success');
  }
  ```

### onBackupServiceDied

onBackupServiceDied : Callback&lt;undefined&gt;

回调函数。备份服务死亡时触发回调。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  onBackupServiceDied: () => {
    console.info('onBackupServiceDied success');
  }
  ```

## backup.getLocalCapabilities

getLocalCapabilities(callback: AsyncCallback&lt;FileData&gt;): void

用于获取一个描述本地能力的Json文件。使用callback异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                   |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;[FileData](#filedata)&gt; | 是   | 回调函数。当获取成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  try {
    backup.getLocalCapabilities((err: BusinessError, fileData: backup.FileData) => {
      if (err) {
        console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
      }
      console.info('getLocalCapabilities success');
      fs.closeSync(fileData.fd);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  ```

**返回的能力文件内容示例：**

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

## backup.getLocalCapabilities

getLocalCapabilities(): Promise&lt;FileData&gt;

用于获取一个描述本地能力的Json文件。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                                 | 说明                                                |
| ------------------------------------ | --------------------------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象，返回描述本地能力的Json文件的FileData。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  async function getLocalCapabilities() {
    try {
      let fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      fs.closeSync(fileData.fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

  **返回的能力文件内容示例：**

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

## SessionBackup

备份流程对象，用来支撑应用备份的流程。在使用前，需要先创建SessionBackup实例。

### constructor

constructor(callbacks: GeneralCallbacks);

备份流程的构造函数，用于获取SessionBackup类的实例。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                 |
| -------- | ------------------------------------- | ---- | -------------------- |
| callback | [GeneralCallbacks](#generalcallbacks) | 是   | 备份流程所需的回调。 |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks);
  ```

### appendBundles

appendBundles(bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

添加需要备份的应用。当前整个流程中，在获取SessionBackup类的实例后只能调用一次。使用callback异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型                      | 必填 | 说明                                                           |
| --------------- | ------------------------- | ---- | -------------------------------------------------------------- |
| bundlesToBackup | string[]                  | 是   | 需要备份的应用名称的数组。                                     |
| callback        | AsyncCallback&lt;void&gt; | 是   | 回调函数。当添加备份应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks);
  try {
    let backupApps: Array<string> = [
      "com.example.hiworld",
    ];
    sessionBackup.appendBundles(backupApps, (err: BusinessError) => {
      if (err) {
        console.error('appendBundles failed with err: ' + JSON.stringify(err));
      }
      console.info('appendBundles success');
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }
  ```

### appendBundles

appendBundles(bundlesToBackup: string[]): Promise&lt;void&gt;

添加需要备份的应用。当前整个流程中，在获取SessionBackup类的实例后只能调用一次。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundlesToBackup | string[] | 是   | 需要备份的应用名称的数组。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks);
  async function appendBundles() {
    try {
      let backupApps: Array<string> = [
        "com.example.hiworld",
      ];
      await sessionBackup.appendBundles(backupApps);
      console.info('appendBundles success');
    } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## SessionRestore

恢复流程对象，用来支撑应用恢复的流程。在使用前，需要先创建SessionRestore实例。

### constructor

constructor(callbacks: GeneralCallbacks);

恢复流程的构造函数，用于获取SessionRestore类的实例。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                 |
| -------- | ------------------------------------- | ---- | -------------------- |
| callback | [GeneralCallbacks](#generalcallbacks) | 是   | 恢复流程所需的回调。 |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks);
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

添加需要恢复的应用。当前整个流程中，在获取SessionRestore类的实例后只能调用一次。使用callback异步回调。

> **说明：**
>
> - 服务在恢复时需要其能力文件进行相关校验。
> - 因此remoteCapabilitiesFd可通过备份端服务所提供的[getLocalCapabilities](#backupgetlocalcapabilities)接口获取，可对其内容根据恢复应用的实际状况修改参数。也可通过getLocalCapabilities提供的json示例自行生成能力文件。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名               | 类型                      | 必填 | 说明                                                           |
| -------------------- | ------------------------- | ---- | -------------------------------------------------------------- |
| remoteCapabilitiesFd | number                    | 是   | 用于恢复所需能力文件的文件描述符。                             |
| bundlesToBackup      | string[]                  | 是   | 需要恢复的应用名称的数组。                                     |
| callback             | AsyncCallback&lt;void&gt; | 是   | 回调函数。当添加恢复应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks);
  async function appendBundles() {
    try {
      let fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      sessionRestore.appendBundles(fileData.fd, restoreApps, (err: BusinessError) => {
        if (err) {
          console.error('appendBundles failed with err: ' + JSON.stringify(err));
        }
        console.info('appendBundles success');
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[]): Promise&lt;void&gt;

添加需要恢复的应用。当前整个流程中，在获取SessionRestore类的实例后只能调用一次。使用Promise异步回调。

> **说明：**
>
> - 服务在恢复时需要其能力文件进行相关校验。
> - 因此remoteCapabilitiesFd可通过备份端服务所提供的[getLocalCapabilities](#backupgetlocalcapabilities)接口获取，可对其内容根据恢复应用的实际状况修改参数。也可通过getLocalCapabilities提供的json示例自行生成能力文件。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名               | 类型     | 必填 | 说明                               |
| -------------------- | -------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number   | 是   | 用于恢复所需能力文件的文件描述符。 |
| bundlesToBackup      | string[] | 是   | 需要恢复的应用包名称的数组。       |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks);
  async function appendBundles() {
    try {
      let fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      await sessionRestore.appendBundles(fileData.fd, restoreApps);
      console.info('appendBundles success');
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### getFileHandle

getFileHandle(fileMeta: FileMeta, callback: AsyncCallback&lt;void&gt;): void

用于请求从服务中获取共享文件。使用callback异步回调。

> **说明：**
>
> - 这个接口是零拷贝特性（减少不必要的内存拷贝，实现了更高效率的传输）的一部分。零拷贝方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.copyFile](js-apis-file-fs.md#fscopyfile)等相关零拷贝接口。
> - 使用getFileHandle前需要获取SessionRestore类的实例，并且成功通过appendBundles添加需要待恢复的应用。
> - 开发者可以通过onFileReady回调来获取文件句柄，当客户端完成文件操作时，需要使用publishFile来进行发布。
> - 根据所需要恢复的文件个数，可以多次调用getFileHandle。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                           |
| -------- | ------------------------- | ---- | -------------------------------------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | 是   | 恢复文件的元数据。                                             |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当请求文件句柄成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks);
  let fileMeta: backup.FileMeta = {
    bundleName: "com.example.hiworld",
    uri: "test.txt"
  }
  sessionRestore.getFileHandle(fileMeta, (err: BusinessError) => {
    if (err) {
      console.error('getFileHandle failed with err: ' + JSON.stringify(err));
    }
    console.info('getFileHandle success');
  });
  ```

### getFileHandle

getFileHandle(fileMeta: FileMeta): Promise&lt;void&gt;

用于请求从服务中获取共享文件。使用Promise异步回调。

> **说明：**
>
> - 这个接口是零拷贝特性（减少不必要的内存拷贝，实现了更高效率的传输）的一部分。零拷贝方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.copyFile](js-apis-file-fs.md#fscopyfile)等相关零拷贝接口。
> - 使用getFileHandle前需要获取SessionRestore类的实例，并且成功通过appendBundles添加需要待恢复的应用。
> - 开发者可以通过onFileReady回调来获取文件句柄，当客户端完成文件操作时，需要使用publishFile来进行发布。
> - 根据所需要恢复的文件个数，可以多次调用getFileHandle。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| fileMeta | [FileMeta](#filemeta) | 是   | 恢复文件的元数据。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
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
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks);
  async function getFileHandle() {
    try {
      let fileMeta: backup.FileMeta = {
        bundleName: "com.example.hiworld",
        uri: "test.txt"
      }
      await sessionRestore.getFileHandle(fileMeta);
      console.info('getFileHandle success');
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getFileHandle failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### publishFile

publishFile(fileMeta: FileMeta, callback: AsyncCallback&lt;void&gt;): void

用于将FileMeta发布到备份服务，使服务知道文件的内容已经准备完成。使用callback异步回调。

> **说明：**
>
> - 这个接口是零拷贝特性（减少不必要的内存拷贝，实现了更高效率的传输）的一部分。零拷贝方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.copyFile](js-apis-file-fs.md#fscopyfile)等相关零拷贝接口。
> - 服务端通过onFileReady返回文件句柄后，客户端可通过零拷贝操作将其对应的文件内容拷贝到服务端提供的文件句柄中。
> - 在完成拷贝操作后可使用publishFile通知备份服务文件已经准备完成。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | 是   | 恢复文件元数据。                                           |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当发布文件成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let g_session: backup.SessionRestore;
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        let fileMeta: backup.FileMeta = {
          bundleName: file.bundleName,
          uri: file.uri
        }
        g_session.publishFile(fileMeta, (err: BusinessError) => {
          if (err) {
            console.error('publishFile failed with err: ' + JSON.stringify(err));
          }
          console.info('publishFile success');
        });
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
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks);
    return sessionRestore;
  }
  g_session = createSessionRestore();
  ```

### publishFile

publishFile(fileMeta: FileMeta): Promise&lt;void&gt;

用于将FileMeta发布到备份服务，使服务知道文件的内容已经准备完成。使用Promise异步回调。

> **说明：**
>
> - 这个接口是零拷贝特性（减少不必要的内存拷贝，实现了更高效率的传输）的一部分。零拷贝方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.copyFile](js-apis-file-fs.md#fscopyfile)等相关零拷贝接口。
> - 服务端通过onFileReady返回文件句柄后，客户端可通过零拷贝操作将其对应的文件内容拷贝到服务端提供的文件句柄中。
> - 在完成拷贝操作后可使用publishFile通知备份服务文件已经准备完成。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                  | 必填 | 说明             |
| -------- | --------------------- | ---- | ---------------- |
| fileMeta | [FileMeta](#filemeta) | 是   | 恢复文件元数据。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  let g_session: backup.SessionRestore;
  async function publishFile(file: backup.FileMeta) {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: file.uri
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        publishFile(file);
        console.info('publishFile success');
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
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks);
    return sessionRestore;
  }
  g_session = createSessionRestore();
  ```
