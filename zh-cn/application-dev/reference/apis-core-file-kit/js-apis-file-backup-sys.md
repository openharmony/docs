# @ohos.file.backup (备份恢复)(系统接口)

该模块为应用提供备份/恢复数据的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import backup from '@ohos.file.backup';
```

## FileMeta

文件的元数据，包含一个应用名称以及文件uri。FileMeta在执行备份/恢复时是不可缺少的对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称       | 类型   | 必填 | 说明                                                                                                |
| ---------- | ------ | ---- | --------------------------------------------------------------------------------------------------- |
| bundleName | string | 是   | 应用名称，可通过[bundleManager.BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)提供的获取方式获取。 |
| uri        | string | 是   | 应用沙箱内待传输文件的名称，当前uri尚未升级为标准格式，仅接受0-9a-zA-Z下划线(_)点(.)组成的名称      |

## FileData

文件的元数据，包含一个已经打开的文件描述符。FileData在执行备份/恢复时是不可缺少的对象。

> **说明：**
>
> FileData使用完成后必须关闭，如不关闭会出现内存泄露问题。关闭的方法可参考由[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.closeSync](js-apis-file-fs.md#fsclosesync)等相关关闭接口。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型   | 必填 | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | 是   | 已经打开的文件描述符，通过备份服务获取。 |

## FileManifestData<sup>12+</sup>

文件的元数据，包含一个已经打开的文件描述符。FileManifestData所打开的内容是一个清单文件，用于描述应用增量备份/恢复时对应文件的基础信息。FileManifestData在执行增量备份/恢复时是不可缺少的对象。

> **说明：**
>
> 关闭的方法可参考[fs.closeSync](js-apis-file-fs.md#fsclosesync)等关闭接口。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup
| 名称       | 类型   | 必填 | 说明                                     |
| ---------- | ------ | ---- | ---------------------------------------- |
| manifestFd | number | 是   | 已经打开的文件描述符，通过备份服务获取。 |

## IncrementalBackupTime<sup>12+</sup>

用于记录最后一次的增量备份时间，用于描述备份增量的时间点。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称                | 类型   | 必填 | 说明                                                                                                |
| ------------------- | ------ | ---- | --------------------------------------------------------------------------------------------------- |
| bundleName          | string | 是   | 应用名称，可通过[bundleManager.BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)提供的获取方式获取。 |
| lastIncrementalTime | number | 是   | 最后一次的增量备份时间。                                                                           |

## BackupParams<sup>12+</sup>

为备份恢复提供可选配置参数以json格式的字符串形式存在。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称       | 类型   | 必填 | 说明                                               |
| ---------- | ------ | ---- | -------------------------------------------------- |
| parameters | string | 否   | 以json格式为配置项的字符串，为备份恢复提供可选选项。 |

## BackupPriority<sup>12+</sup>

为备份恢复提供优先级配置。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称     | 类型   | 必填 | 说明                                                   |
| -------- | ------ | ---- | ------------------------------------------------------ |
| priority | number | 否   | 数值越大优先级越高；优先级相同的情况下，先调用的先执行。 |

## IncrementalBackupData<sup>12+</sup>

一次增量备份对象。继承[IncrementalBackupTime](#incrementalbackuptime12)，[FileManifestData](#filemanifestdata12)，[BackupParams](#backupparams12)，[BackupPriority](#backuppriority12)。

> **说明：**
>
> 记录应用最后一次的增量时间以及增量备份清单文件的文件描述符，清单文件中记录着增量时间内已备份的文件信息。可选参数包含了备份恢复的可选配置项，优先级配置项。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

## File

一个文件对象。
继承[FileMeta](#filemeta)和[FileData](#filedata)。

> **说明：**
>
> file.backup.File与@ohos.file.fs中的提供的[File](js-apis-file-fs.md#file)是带有不同的涵义，前者是继承[FileMeta](#filemeta)和[FileData](#filedata)的对象而后者只有一个文件描述符的对象。请注意区分，不要混淆。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

## File<sup>12+</sup>

一个文件对象。
继承[FileMeta](#filemeta)和[FileData](#filedata)和[FileManifestData](#filemanifestdata12)。

> **说明：**
>
> file.backup.File与@ohos.file.fs中的提供的[File](js-apis-file-fs.md#file)是带有不同的涵义，前者是继承[FileMeta](#filemeta)和[FileData](#filedata)的对象而后者只有一个文件描述符的对象。请注意区分，不要混淆。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

## GeneralCallbacks

备份/恢复过程中的通用回调，备份服务将通过这些回调通知客户端其应用的备份/恢复阶段。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

### 属性

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| onBackupSizeReport<sup>18+</sup>  | [OnBackupSizeReport](#onbackupsizereport18) | 否 | 是 |  框架获取到的待备份的数据量大小的信息。 |

### onFileReady

onFileReady : AsyncCallback&lt;File&gt;

回调函数。当服务端返向客户端发送文件，如果成功触发回调，返回对应文件的[File](#file)内容；如果触发失败，则返回err错误对象。

> **说明：**
>
> AsyncCallback回调中返回的File所属file.backup.[File](#file)类型。返回的文件归备份服务所有，一旦文件关闭，备份服务将选择合适的时机去清理，但客户端必须关闭文件句柄。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
      return;
    }
    console.info('onFileReady success with file: ' + file.bundleName + ' ' + file.uri);
    fs.closeSync(file.fd);
  }
  ```

### onBundleBegin

onBundleBegin : AsyncCallback&lt;string, void | string&gt;

回调函数。当应用备份/恢复开始时，如果成功触发回调，返回对应的bundleName；如果触发失败，则返回err错误对象。从API version 12开始，返回err的同时，将同时返回第二个string参数bundleName。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 参数名     | 类型          | 必填 | 说明                                                        |
| ---------- | ------------- | ---- | ----------------------------------------------------------- |
| bundleName | string        | 是   | 服务返回的应用名称。                                          |
| err        | BusinessError | 否   | 当发生err时，为错误对象；否则为undefined data为bundle名称。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13500001 | The application is not added to the backup or restore |
| 13500002 | Failed to start application extension Procedure       |
| 13600001 | IPC error                                             |
| 13900005 | I/O error                                             |
| 13900011 | Out of memory                                         |
| 13900020 | Invalid argument                                      |
| 13900025 | No space left on device                               |
| 13900042 | Unknown error                                         |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleBegin: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code));
      return;
    }
    console.info('onBundleBegin success');
  }
  ```

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleBegin: (err: BusinessError<string>, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
      return;
    }
    console.info('onBundleBegin success');
  }
  ```

### onBundleEnd

onBundleEnd : AsyncCallback&lt;string, void | string&gt;

回调函数。当应用备份/恢复结束后，如果成功触发回调，返回对应的bundleName；如果触发失败，则返回err错误对象。从API version 12开始，返回err的同时，将同时返回第二个string参数bundleName。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 参数名     | 类型          | 必填 | 说明                                                        |
| ---------- | ------------- | ---- | ----------------------------------------------------------- |
| bundleName | string        | 是   | 服务返回的应用名称。                                          |
| err        | BusinessError | 否   | 当发生err时，为错误对象，否则为undefined data为bundle名称。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13500003 | Backup or restore timed out     |
| 13500004 | Application extension death     |
| 13600001 | IPC error                       |
| 13900005 | I/O error                       |
| 13900011 | Out of memory                   |
| 13900020 | Invalid argument                |
| 13900025 | No space left on device         |
| 13900042 | Unknown error                   |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleEnd: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
      return;
    }
    console.info('onBundleEnd success with bundleName: ' + bundleName);
  }
  ```

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleEnd: (err: BusinessError<string>, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
      return;
    }
    console.info('onBundleEnd success');
  }
  ```

### onAllBundlesEnd

onAllBundlesEnd : AsyncCallback&lt;undefined&gt;

回调函数。当所有bundle的备份/恢复过程结束成功时触发回调，如果触发失败，则返回err错误对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
      return;
    }
    console.info('onAllBundlesEnd success');
  }
  ```

### onBackupServiceDied

onBackupServiceDied : Callback&lt;undefined&gt;

回调函数。备份服务死亡时触发回调，如果触发失败，则返回err错误对象。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  onBackupServiceDied: () => {
    console.info('onBackupServiceDied success');
  }
  ```

### onResultReport<sup>12+</sup>

onResultReport (bundleName: string, result: string)

回调函数。当应用备份/恢复结束后，如果成功触发回调，返回应用包名及应用备份/恢复信息（备份/恢复数量或异常信息等）。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 参数名     | 类型   | 必填 | 说明                            |
| ---------- | ------ | ---- | ------------------------------- |
| bundleName | string | 是   | 应用包名。                        |
| result     | string | 是   | json格式返回的应用备份/恢复信息。 |

**示例：**

  ```ts
  import backup from '@ohos.file.backup';

  onResultReport: (bundleName: string, result: string) => {
    console.info('onResultReport bundleName : ' + bundleName);
    console.info('onResultReport result : ' + result);
  }
  ```

### onProcess<sup>12+</sup>

onProcess (bundleName: string, process: string)

回调函数。应用备份/恢复过程中进度信息的回调，返回应用执行业务的进度信息和异常信息等。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 参数名     | 类型   | 必填 | 说明                            |
| ---------- | ------ | ---- | ------------------------------- |
| bundleName | string | 是   | 应用包名。                        |
| process     | string | 是   | json格式返回应用备份/恢复的进度信息。 |

**示例：**

  ```ts
  import backup from '@ohos.file.backup';

  onProcess: (bundleName: string, process: string) => {
    console.info('onProcess bundleName : ' + bundleName);
    console.info('onProcess processInfo : ' + process);
  }
  ```

## backup.getBackupVersion<sup>18+</sup>

getBackupVersion(): string;

获取备份恢复版本号信息。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| string | 返回备份恢复版本号信息。<br/>版本号格式为API版本。内部版本，例如API16，则版本号为16.0。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  function getBackupVersion() {
    try {
      let result = backup.getBackupVersion();
      console.info('getBackupVersion success， result: ' + result);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getBackupVersion failed with err: ' + JSON.stringify(err));
    }
  }
  ```

**内容示例：**

  ```json
  { "backupVersion" : "16.0" }
  ```

## backup.getLocalCapabilities

getLocalCapabilities(callback: AsyncCallback&lt;FileData&gt;): void

用于获取一个描述本地能力的Json文件。使用callback异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                               |
| -------- | ------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;[FileData](#filedata)&gt; | 是   | 异步获取本地能力文件之后的回调。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  ```

**能力文件可以通过[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.stat](js-apis-file-fs.md#fsstat-1)等相关接口获取，能力文件内容示例：**

 ```json
 {
  "backupVersion" : "16.0",
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

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

  **能力文件可以通过[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.stat](js-apis-file-fs.md#fsstat)等相关接口获取，能力文件内容示例：**

 ```json
 {
  "backupVersion" : "16.0",
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

## backup.getLocalCapabilities<sup>12+</sup>

getLocalCapabilities(dataList:Array&lt;IncrementalBackupTime&gt;): Promise&lt;FileData&gt;

用于获取一个描述本地能力的Json文件，根据dataList内传递的参数查询对应应用的本地能力数据。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**
| 参数名   | 类型                                                           | 必填 | 说明                                           |
| -------- | -------------------------------------------------------------- | ---- | ---------------------------------------------- |
| dataList | Array&lt;[IncrementalBackupTime](#incrementalbackuptime12)&gt; | 是   | 增量备份数据列表，用于描述增量备份的文件信息。 |

**返回值：**

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900005 | I/O error                                                                                      |
| 13900011 | Out of memory                                                                                  |
| 13900020 | Invalid argument                                                                               |
| 13900025 | No space left on device                                                                        |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  async function getLocalCapabilities() {
    try {
      let backupApps: backup.IncrementalBackupTime[] = [{
        bundleName: "com.example.hiworld",
        lastIncrementalTime: 1700107870 //调用者根据上次记录的增量备份时间
      }];
      let fileData = await backup.getLocalCapabilities(backupApps);
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.getBackupInfo<sup>12+</sup>

getBackupInfo(bundleToBackup: string): string;

获取需要备份的应用信息。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleToBackup | string | 是   | 需要备份的应用名称。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| string | 返回应用上报的信息。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
  import backup from '@ohos.file.backup';

  function getBackupInfo() {
    try {
      let backupApp = "com.example.hiworld";
      let result = backup.getBackupInfo(backupApp);
      console.info('getBackupInfo success， result: ' + result);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getBackupInfo failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.updateTimer<sup>12+</sup>

updateTimer(bundleName: string, timeout: number): void;

调用时机为onBundleBegin之后，onBundleEnd之前。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleName | string | 是   | 需要设置备份或恢复时长的应用名称。 |
| timeout | number | 是   | 备份或恢复的限制时长，入参范围[0,14400000]，单位:ms。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| boolean | 超时时间是否设置成功。true为设置成功；false为设置失败。 |

**错误码：**

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  function updateTimer() {
    try {
      let timeout = 30000;
      let bundleName = "com.example.hiworld";
      let result = backup.updateTimer(bundleName, timeout);
      if (result) {
        console.info('updateTimer success');
      } else {
        console.info('updateTimer fail');
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('updateTimer failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.updateSendRate<sup>12+</sup>

updateSendRate(bundleName: string, sendRate: number): boolean;

调用时机为onBundleBegin之后，onBundleEnd之前。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleName|string | 是   | 需要控制速率对应的应用名称。
| sendRate | number | 是   | 需要应用设置的fd发送速率大小，以秒为单位，范围0~800，默认60/秒。当为0时，表示停止发送，等到设置非0值时激活发送。如果设置值超过最大值800，按照800进行发送。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| boolean | 发送速率是否设置成功。true为设置成功；false为设置失败。 |

**错误码：**

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  function updateSendRate() {
    try {
      let bundleName = "com.example.myApp";
      let sendRate = 300;
      let result = backup.updateSendRate(bundleName, sendRate);
      if (result) {
        console.info('updateSendRate success');
      } else {
        console.info('updateSendRate fail');
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('updateSendRate failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## OnBackupSizeReport<sup>18+</sup>

type OnBackupSizeReport = (reportInfo: string) => void;

框架返回的应用待备份的数据量大小。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 参数名   | 类型                                  | 必填 | 说明                 |
| -------- | ------------------------------------- | ---- | -------------------- |
| reportInfo | string | 是   | 框架获取到的应用待备份数据量大小的信息。 |

**示例：**

  ```ts
  import backup from '@ohos.file.backup';

  onBackupSizeReport: (OnBackupSizeReport) => {
    console.info('dataSizeCallback success');
    console.info('dataSizeCallback report : ' + OnBackupSizeReport);
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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  ```

### getLocalCapabilities<sup>18+</sup>

getLocalCapabilities(): Promise&lt;FileData&gt;

用于在备份业务中获取一个描述本地能力的Json文件。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken |
| 202      | Permission verification failed, application which is not a system application uses system API |
| 13600001 | IPC error                                                    |
| 13900001 | Operation not permitted                                      |
| 13900020 | Invalid argument                                             |
| 13900042 | Internal error                                                |

**示例：**

```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  interface test { // 用于解析能力文件
    bundleInfos: [];
    deviceType: string;
    systemFullName: string;
  }

  interface BundleInfo { // 用于获取单个应用的本地能力信息
    name: string;
    appIndex: number;
    versionCode: number;
    versionName: string;
    spaceOccupied: number;
    allToBackup: boolean;
    increSpaceOccupied?: number;
    fullBackupOnly: boolean;
    extensionName: string;
    restoreDeps: string;
    supportScene: string;
    extraInfo: object;
  }

  let generalCallbacks: backup.GeneralCallbacks = { // 定义备份/恢复过程中的通用回调
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  let basePath = '/data/storage/el2/base/backup'; 
  let path = basePath + '/localCapabilities.json'; // 本地保存能力文件的路径
  try {
    let fileData = await sessionBackup.getLocalCapabilities(); // 获取本地能力文件
    if (fileData) {
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      if (!fs.accessSync(basePath)) {
        fs.mkdirSync(basePath);
        console.info('creat success' + basePath);
      }
      fs.copyFileSync(fileData.fd, path); // 将获取的本地能力文件保存到本地
      fs.closeSync(fileData.fd);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  let data = await fs.readTextSync(path, 'utf8'); // 从本地的能力文件中获取信息
  try {
    const jsonsObj: test | null = JSON.parse(data); // 解析本地的能力文件并打印部分信息
    if (jsonsObj) {
      const infos:BundleInfo [] = jsonsObj.bundleInfos;
      for (let i = 0; i < infos.length; i++) {
        console.info('name: ' + infos[i].name);
        console.info('appIndex: ' + infos[i].appIndex);
        console.info('allToBackup: ' + infos[i].allToBackup);
      }
      const systemFullName: string = jsonsObj.systemFullName;
      console.info('systemFullName: ' + systemFullName);
      const deviceType: string = jsonsObj.deviceType;
      console.info('deviceType: ' + deviceType);
    }
  } catch (error) {
    console.error('parse failed with err: ' + JSON.stringify(error));
  }
```

**能力文件可以通过[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.stat](js-apis-file-fs.md#fsstat-1)等相关接口获取，能力文件内容示例：**

 ```json
 {
  "backupVersion" : "16.0",
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

### getBackupDataSize<sup>18+</sup>

getBackupDataSize(isPreciseScan: boolean, dataList: Array\<IncrementalBackupTime\>): Promise&lt;void&gt;

用于获取应用待备份数据量，在appendBundles之前调用。以异步callback方式（generalCallbacks中的onBackupSizeReport）每隔固定时间（每隔5秒返回一次，如果5秒内获取完则立即返回）返回一次扫描结果，直到datalist中所有的应用数据量全部返回。


**需要权限**：ohos.permission.BACKUP

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                                                     | 必填 | 说明                                                         |
| ------------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isPreciseScan | boolean                                                  | 是   | 是否精确扫描。非精确扫描速度快，为估算数据量；精确扫描速度慢，结果更准确。但由于在实际备份过程中待备份数据可能发生变动，精确扫描结果和实际备份数据量不保证完全匹配。 |
| dataList      | Array<[IncrementalBackupTime](#incrementalbackuptime12)> | 是   | 备份应用列表，用于描述待获取数据量的应用和上一次备份时间（全量备份填0）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken |
| 202      | Permission verification failed, application which is not a system application uses system API |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild |
| 13600001 | IPC error                                                    |
| 13900001 | Operation not permitted                                      |
| 13900020 | Invalid argument                                             |
| 13900042 | Internal error                                                |

**示例：**

```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  interface scanedInfos { //用于解析扫描结果
    scaned: [];
    scanning: string;
  }

  interface ScanedInfo { //用于解析单个应用的扫描结果
    bundleName: string;
    dataSize: number;
    incDataSize: number;
  }

  let generalCallbacks: backup.GeneralCallbacks = { // 定义备份/恢复过程中的通用回调
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    },
    onBackupSizeReport: (OnBackupSizeReport) => { // 回调函数 与getBackupDataSize配套使用，返回已获取到应用的数据量大小和正在获取数据量的应用的包名
      console.info('dataSizeCallback success');
      const jsonObj: scanedInfos | null = JSON.parse(OnBackupSizeReport); // 解析返回的信息并打印
      if (jsonObj) {
        const infos: ScanedInfo [] = jsonObj.scaned;
        for (let i = 0; i < infos.length; i++) {
          console.info('name: ' + infos[i].bundleName);
          console.info('dataSize: ' + infos[i].dataSize);
          console.info('incDataSize: ' + infos[i].incDataSize);
        }
        const scanning: string = jsonObj.scanning;
        console.info('scanning: ' + scanning);
      }
    }
  };

  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  let backupApps: backup.IncrementalBackupTime[] = [{
    bundleName: "com.example.hiworld",
    lastIncrementalTime: 0 // 调用者根据上次记录的增量备份时间，全量时为0
  }];
  try {
    sessionBackup.getBackupDataSize(false, backupApps); // 获取backupApps中指定应用的待备份的数据量大小，false表示使用非精确扫描
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getBackupDataSize failed with err: ' + JSON.stringify(err));
  }
```

**异步返回JSON串示例：**

```json
{
 "scaned" :[ // 本次扫描完成的应用，已返回结果的应用在下一次回调中不会再继续返回
     {
         "name": "com.example.hiworld", // 应用名称
         "dataSize": 1006060, // 数据量大小
         "incDataSize":-1 // 增量数据量大小，全量扫描、非精确扫描时为-1，增量精确扫描时为实际增量数据量大小
     },
     {
         "name": "com.example.myAPP",
         "dataSize": 5000027,
         "incDataSize": -1
     }
 ],
 "scanning" :"com.example.smartAPP" // 正在扫描的应用，在最后一次结果返回时，该字段为空
}
```

### appendBundles

appendBundles(bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

添加需要备份的应用。当前整个流程中，在获取SessionBackup类的实例后只能调用一次。使用callback异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型                      | 必填 | 说明                         |
| --------------- | ------------------------- | ---- | ---------------------------- |
| bundlesToBackup | string[]                  | 是   | 需要备份的应用名称的数组。   |
| callback        | AsyncCallback&lt;void&gt; | 是   | 异步添加备份应用之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  try {
    let backupApps: Array<string> = [
      "com.example.hiworld",
    ];
    sessionBackup.appendBundles(backupApps, (err: BusinessError) => {
      if (err) {
        console.error('appendBundles failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('appendBundles success');
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }
  ```

### appendBundles

appendBundles(bundlesToBackup: string[], infos?: string[]): Promise&lt;void&gt;

添加需要备份的应用。当前整个流程中，在获取SessionBackup类的实例后只能调用一次。使用Promise异步回调。

从API version 12开始, 新增可选参数infos, 可携带备份时各应用所需要的扩展信息, infos和bundlesToBackup根据索引一一对应。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundlesToBackup | string[] | 是   | 需要备份的应用名称的数组。 |
| infos           | string[] | 否   | 备份时各应用所需扩展信息的数组, 与bundlesToBackup根据索引一一对应。从API version 12开始支持。|

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  async function appendBundles() {
    try {
      let backupApps: Array<string> = [
        "com.example.hiworld",
        "com.example.myApp"
      ];
      await sessionBackup.appendBundles(backupApps);
      console.info('appendBundles success');
      // 携带扩展参数, 其中infos,details和外层的type节点为固定节点
      let infos: Array<string> = [
        `
        {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.hiworld"
            }
        ]
    },
    {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.myApp"
            }
        ]
    }
      `
    ]
      await sessionBackup.appendBundles(backupApps, infos);
      console.info('appendBundles success');
    } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### release<sup>12+</sup>

release(): Promise&lt;void&gt;

备份流程结束后，应用与服务断开连接，使备份恢复服务退出。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
  async function release() {
    try {
      await sessionBackup.release();
      console.info('release success');
    } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('release failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### cancel<sup>18+</sup>

cancel(bundleName: string): number;

备份任务过程中，工具应用发现数据异常，需要取消某应用的备份时调用此接口，使此应用的备份任务终止。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleName | string | 是   | 需要取消备份的应用名称。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| number | 返回取消状态。<br/>0：取消任务下发成功；<br/> 13500011：想要取消的任务未开始；<br/> 13500012：想要取消的任务不存在。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  sessionBackup?: backup.SessionBackup;

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        // 文件fd传输失败，调用取消接口，取消此应用的备份任务
        let result = this.sessionBackup.cancel("com.example.myapplication");
        console.info('cancel result:' + result);
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  this.sessionBackup = new backup.SessionBackup(generalCallbacks); // 创建备份流程
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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
  ```

### getLocalCapabilities<sup>18+</sup>

getLocalCapabilities(): Promise&lt;FileData&gt;

用于在恢复业务中获取一个描述本地能力的Json文件。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken |
| 202      | Permission verification failed, application which is not a system application uses system API |
| 13600001 | IPC error                                                    |
| 13900001 | Operation not permitted                                      |
| 13900020 | Invalid argument                                             |
| 13900042 | Internal error                                                |

**示例：**

```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  interface test { // 用于解析能力文件
    bundleInfos: [];
    deviceType: string;
    systemFullName: string;
  }

  interface BundleInfo { // 用于获取单个应用的本地能力信息
    name: string;
    appIndex: number;
    versionCode: number;
    versionName: string;
    spaceOccupied: number;
    allToBackup: boolean;
    increSpaceOccupied?: number;
    fullBackupOnly: boolean;
    extensionName: string;
    restoreDeps: string;
    supportScene: string;
    extraInfo: object;
  }

  let generalCallbacks: backup.GeneralCallbacks = { // 定义备份/恢复过程中的通用回调
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
  let basePath = '/data/storage/el2/base/backup';
  let path = basePath + '/localCapabilities.json'; // 本地保存能力文件的路径
  try {
    let fileData = await sessionRestore.getLocalCapabilities(); // 获取本地能力文件
    if (fileData) {
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      if (!fs.accessSync(basePath)) {
        fs.mkdirSync(basePath);
        console.info('creat success' + basePath);
      }
      fs.copyFileSync(fileData.fd, path); // 将获取的本地能力文件保存到本地
      fs.closeSync(fileData.fd);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  let data = await fs.readTextSync(path, 'utf8'); // 从本地的能力文件中获取信息
  try {
    const jsonsObj: test | null = JSON.parse(data); // 解析本地的能力文件并打印部分信息
    if (jsonsObj) {
      const infos:BundleInfo [] = jsonsObj.bundleInfos;
      for (let i = 0; i < infos.length; i++) {
        console.info('name: ' + infos[i].name);
        console.info('appIndex: ' + infos[i].appIndex);
        console.info('allToBackup: ' + infos[i].allToBackup);
      }
      const systemFullName: string = jsonsObj.systemFullName;
      console.info('systemFullName: ' + systemFullName);
      const deviceType: string = jsonsObj.deviceType;
      console.info('deviceType: ' + deviceType);
    }
  } catch (error) {
    console.error('parse failed with err: ' + JSON.stringify(error));
  }
```

**能力文件可以通过[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.stat](js-apis-file-fs.md#fsstat-1)等相关接口获取，能力文件内容示例：**

 ```json
 {
  "backupVersion" : "16.0",
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

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

添加需要恢复的应用。当前整个流程中，在获取SessionRestore类的实例后只能调用一次，使用callback异步回调。

> **说明：**
>
> - 服务在恢复时需要其能力文件进行相关校验。
> - 因此remoteCapabilitiesFd可通过备份端服务所提供的[getLocalCapabilities](#backupgetlocalcapabilities)接口获取，可对其内容根据恢复应用的实际状况修改参数。也可通过getLocalCapabilities提供的json示例自行生成能力文件。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名               | 类型                      | 必填 | 说明                               |
| -------------------- | ------------------------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number                    | 是   | 用于恢复所需能力文件的文件描述符。 |
| bundlesToBackup      | string[]                  | 是   | 需要恢复的应用名称的数组。         |
| callback             | AsyncCallback&lt;void&gt; | 是   | 异步添加需要恢复的应用之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
  async function appendBundles() {
    let fileData : backup.FileData = {
      fd : -1
    }
    try {
      fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      sessionRestore.appendBundles(fileData.fd, restoreApps, (err: BusinessError) => {
        if (err) {
          console.error('appendBundles failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('appendBundles success');
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    } finally {
      fs.closeSync(fileData.fd);
    }
  }
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], infos?: string[]): Promise&lt;void&gt;

添加需要恢复的应用。从API version 12开始，新增可选参数infos，可携带应用恢复所需信息，infos和bundlesToBackup根据索引一一对应。
当前整个流程中，在获取SessionRestore类的实例后只能调用一次。使用Promise异步回调。

> **说明：**
>
> - 服务在恢复时需要其能力文件进行相关校验。
> - 因此remoteCapabilitiesFd可通过备份端服务所提供的[getLocalCapabilities](#backupgetlocalcapabilities)接口获取，
    可对其内容根据恢复应用的实际状况修改参数。也可通过getLocalCapabilities提供的json示例自行生成能力文件。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名               | 类型     | 必填 | 说明                               |
| -------------------- | -------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number   | 是   | 用于恢复所需能力文件的文件描述符。 |
| bundlesToBackup      | string[] | 是   | 需要恢复的应用包名称的数组。       |
| infos<sup>12+</sup>  | string[] | 否   | 恢复时各应用所需要扩展信息的数组，与bundlesToBackup根据索引一一对应。从API version 12开始支持。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
  async function appendBundles() {
    let fileData : backup.FileData = {
      fd : -1
    }
    try {
      fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      await sessionRestore.appendBundles(fileData.fd, restoreApps);
      console.info('appendBundles success');
      // 携带扩展参数的调用
      let infos: Array<string> = [
        `
         {
          "infos":[
            {
              "details": [
                {
                  "detail": [
                    {
                      "source": "com.example.hiworld", // 应用旧系统包名
                      "target": "com.example.helloworld" // 应用新系统包名
                    }
                  ]，
                  "type": "app_mapping_relation"
                }
              ],
              "type":"broadcast"
            }
          ]
         }
        `
      ]
      await sessionRestore.appendBundles(fileData.fd, restoreApps, infos);
      console.info('appendBundles success');
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    } finally {
      fs.closeSync(fileData.fd);
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
> - 所需恢复的文件，不支持使用相对路径(../)和软链接。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                      | 必填 | 说明                             |
| -------- | ------------------------- | ---- | -------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | 是   | 恢复文件的元数据。               |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步请求文件句柄成功之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
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
> - 所需恢复的文件，不支持使用相对路径(../)和软链接。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| fileMeta | [FileMeta](#filemeta) | 是   | 恢复文件的元数据。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
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
> - 这个接口仅在调用方完成所有待恢复数据的写入操作后才能调用，且调用方需要确保待写入恢复数据的一致性与完整性。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                      | 必填 | 说明                         |
| -------- | ------------------------- | ---- | ---------------------------- |
| fileMeta | [FileMeta](#filemeta)     | 是   | 恢复文件元数据。             |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步发布文件成功之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
  let initMap = new Map<string, number>();
  let testFileNum = 123; // 123: 恢复所需文件个数示例
  let testBundleName = 'com.example.myapplication'; // 测试包名
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // 实际写入文件个数初始化
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // 实际写入文件个数更新
        // 恢复所需文件个数与实际写入文件个数相等时调用，保证数据的一致性和完整性
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // 每个包的所有文件收到后触发publishFile
          let fileMeta: backup.FileMeta = {
            bundleName: file.bundleName,
            uri: ''
          }
          g_session.publishFile(fileMeta, (err: BusinessError) => {
            if (err) {
              console.error('publishFile failed with err: ' + JSON.stringify(err));
              return;
            }
            console.info('publishFile success');
          });
        }
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
       console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
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
> - 这个接口仅在调用方完成所有待恢复数据的写入操作后才能调用，且调用方需要确保待写入恢复数据的一致性与完整性。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                  | 必填 | 说明             |
| -------- | --------------------- | ---- | ---------------- |
| fileMeta | [FileMeta](#filemeta) | 是   | 恢复文件元数据。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

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
  let initMap = new Map<string, number>();
  let testFileNum = 123; // 123: 恢复所需文件个数示例
  let testBundleName = 'com.example.myapplication'; // 测试包名
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // 实际写入文件个数初始化
  async function publishFile(file: backup.FileMeta) {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: ''
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // 实际写入文件个数更新
        // 恢复所需文件个数与实际写入文件个数相等时调用，保证数据的一致性和完整性
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // 每个包的所有文件收到后触发publishFile
          publishFile(file);
        }
        console.info('publishFile success');
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
    return sessionRestore;
  }
  g_session = createSessionRestore();
  ```

### release<sup>12+</sup>

release(): Promise&lt;void&gt;

恢复流程结束后，应用与服务断开连接，使备份恢复服务退出。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let g_session: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 123; // 123: 恢复所需文件个数示例
  let testBundleName = 'com.example.myapplication'; // 测试包名
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // 实际写入文件个数初始化
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // 实际写入文件个数更新
        // 恢复所需文件个数与实际写入文件个数相等时调用，保证数据的一致性和完整性
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // 每个包的所有文件收到后触发publishFile
          let fileMeta: backup.FileMeta = {
            bundleName: file.bundleName,
            uri: ''
          }
          g_session.publishFile(fileMeta, (err: BusinessError) => {
            if (err) {
              console.error('publishFile failed with err: ' + JSON.stringify(err));
              return;
            }
            console.info('publishFile success');
          });
        }
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
    return sessionRestore;
  }
  g_session = createSessionRestore();
  g_session.release();
  console.info('release success');
  ```

### cancel<sup>18+</sup>

cancel(bundleName: string): number;

恢复任务过程中，工具应用发现数据异常，需要取消某应用的恢复时调用此接口，使此应用的恢复任务终止。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleName | string | 是   | 需要取消备份的应用名称。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| number | 返回取消状态。<br/>0：取消任务下发成功；<br/> 13500011：想要取消的任务未开始；<br/> 13500012：想要取消的任务不存在。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  sessionRestore?: backup.SessionRestore;

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        // 文件fd传输失败，调用取消接口，取消此应用的恢复任务
        let result = this.sessionRestore.cancel("com.example.myapplication");
        console.info('cancel result:' + result);
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  this.sessionRestore = new backup.SessionRestore(generalCallbacks); // 创建恢复流程
  ```

## IncrementalBackupSession<sup>12+</sup>

增量备份流程对象，用来支撑应用增量备份的流程。在使用前，需要先创建IncrementalBackupSession实例。

### constructor<sup>12+</sup>

constructor(callbacks: GeneralCallbacks);

增量备份流程的构造函数，用于获取IncrementalBackupSession类的实例。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| callback | [GeneralCallbacks](#generalcallbacks) | 是   | 增量备份流程所需的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  ```

### getLocalCapabilities<sup>18+</sup>

getLocalCapabilities(): Promise&lt;FileData&gt;

用于在增量备份业务中获取一个描述本地能力的Json文件。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise对象。返回FileData对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken |
| 202      | Permission verification failed, application which is not a system application uses system API |
| 13600001 | IPC error                                                    |
| 13900001 | Operation not permitted                                      |
| 13900020 | Invalid argument                                             |
| 13900042 | Internal error                                                |

**示例：**

```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  interface test { // 用于解析能力文件
    bundleInfos: [];
    deviceType: string;
    systemFullName: string;
  }

  interface BundleInfo { // 用于获取单个应用的本地能力信息
    name: string;
    appIndex: number;
    versionCode: number;
    versionName: string;
    spaceOccupied: number;
    allToBackup: boolean;
    increSpaceOccupied?: number;
    fullBackupOnly: boolean;
    extensionName: string;
    restoreDeps: string;
    supportScene: string;
    extraInfo: object;
  }

  let generalCallbacks: backup.GeneralCallbacks = { // 定义备份/恢复过程中的通用回调
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  let basePath = '/data/storage/el2/base/backup';
  let path = basePath + '/localCapabilities.json'; // 本地保存能力文件的路径
  try {
    let fileData = await incrementalBackupSession.getLocalCapabilities(); // 获取本地能力文件
    if (fileData) {
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      if (!fs.accessSync(basePath)) {
        fs.mkdirSync(basePath);
        console.info('creat success' + basePath);
      }
      fs.copyFileSync(fileData.fd, path); // 将获取的本地能力文件保存到本地
      fs.closeSync(fileData.fd);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  let data = await fs.readTextSync(path, 'utf8'); // 从本地的能力文件中获取信息
  try {
    const jsonsObj: test | null = JSON.parse(data); // 解析本地的能力文件并打印部分信息
    if (jsonsObj) {
      const infos:BundleInfo [] = jsonsObj.bundleInfos;
      for (let i = 0; i < infos.length; i++) {
        console.info('name: ' + infos[i].name);
        console.info('appIndex: ' + infos[i].appIndex);
        console.info('allToBackup: ' + infos[i].allToBackup);
      }
      const systemFullName: string = jsonsObj.systemFullName;
      console.info('systemFullName: ' + systemFullName);
      const deviceType: string = jsonsObj.deviceType;
      console.info('deviceType: ' + deviceType);
    }
  } catch (error) {
    console.error('parse failed with err: ' + JSON.stringify(error));
  }
```

**能力文件可以通过[@ohos.file.fs](js-apis-file-fs.md)提供的[fs.stat](js-apis-file-fs.md#fsstat-1)等相关接口获取，能力文件内容示例：**

 ```json
 {
  "backupVersion" : "16.0",
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

### getBackupDataSize<sup>18+</sup>

getBackupDataSize(isPreciseScan: boolean, dataList: Array\<IncrementalBackupTime\>): Promise&lt;void&gt;

用于获取应用待备份数据量，在appendBundles之前调用。以异步callback方式（generalCallbacks中的onBackupSizeReport）每隔固定时间（每隔5秒返回一次，如果5秒内获取完则立即返回）返回一次扫描结果，直到datalist中所有的应用数据量全部返回。

**需要权限**：ohos.permission.BACKUP

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                                                     | 必填 | 说明                                                         |
| ------------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isPreciseScan | boolean                                                  | 是   | 是否精确扫描。非精确扫描速度快，为估算数据量；精确扫描速度慢，结果更准确。但由于在实际备份过程中待备份数据可能发生变动，精确扫描结果和实际备份数据量不保证完全匹配。 |
| dataList      | Array<[IncrementalBackupTime](#incrementalbackuptime12)> | 是   | 备份应用列表，用于描述待获取数据量的应用和上一次备份时间（全量备份填0）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken |
| 202      | Permission verification failed, application which is not a system application uses system API |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild |
| 13600001 | IPC error                                                    |
| 13900001 | Operation not permitted                                      |
| 13900020 | Invalid argument                                             |
| 13900042 | Internal error                                                |

**示例：**

```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  interface scanedInfos { // 用于解析扫描结果
    scaned: [];
    scanning: string;
  }

  interface ScanedInfo { // 用于解析单个应用的扫描结果
    bundleName: string;
    dataSize: number;
    incDataSize: number;
  }

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => { // 定义备份/恢复过程中的通用回调
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    },
    onBackupSizeReport: (OnBackupSizeReport) => { // 回调函数 与getBackupDataSize配套使用，返回已获取到应用的数据量大小和正在获取数据量的应用的包名
      console.info('dataSizeCallback success');
      const jsonObj: scanedInfos | null = JSON.parse(OnBackupSizeReport); // 解析返回的信息并打印
      if (jsonObj) {
        const infos: ScanedInfo [] = jsonObj.scaned;
        for (let i = 0; i < infos.length; i++) {
          console.info('name: ' + infos[i].bundleName);
          console.info('dataSize: ' + infos[i].dataSize);
          console.info('incDataSize: ' + infos[i].incDataSize);
        }
        const scanning: string = jsonObj.scanning;
        console.info('scanning: ' + scanning);
      }
    }
  };

  let incrementalBackupSession = new backup.incrementalBackupSession(generalCallbacks); // 创建增量备份流程

  let backupApps: backup.IncrementalBackupTime[] = [{
    bundleName: "com.example.hiworld",
    lastIncrementalTime: 1700107870 // 调用者根据上次记录的增量备份时间
  }];
  try {
    incrementalBackupSession.getBackupDataSize(true, backupApps); // 获取backupApps中指定应用的待备份的数据量大小，true表示使用精确扫描
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getBackupDataSize failed with err: ' + JSON.stringify(err));
  }
```

**异步返回JSON串示例：**

```json
{
 "scaned" :[ // 本次扫描完成的应用，已返回结果的应用在下一次回调中不会再继续返回
     {
         "name": "com.example.hiworld", // 应用名称
         "dataSize": 1006060, // 数据量大小
         "incDataSize": 50800 // 增量数据量大小
     },
     {
         "name": "com.example.myAPP",
         "dataSize": 5000027,
         "incDataSize": 232344
     }
 ],
 "scanning" :"com.example.smartAPP" // 正在扫描的应用，在最后一次结果返回时，该字段为空
}
```

### appendBundles<sup>12+</sup>

appendBundles(bundlesToBackup: Array&lt;IncrementalBackupData&gt;): Promise&lt;void&gt;

添加需要增量备份的应用。当前整个流程中，触发Release接口之前都可以进行appendBundles的调用。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型                                                           | 必填 | 说明                       |
| --------------- | -------------------------------------------------------------- | ---- | -------------------------- |
| bundlesToBackup | Array&lt;[IncrementalBackupData](#incrementalbackupdata12)&gt; | 是   | 需要增量备份的应用的数组。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900011 | Out of memory                                                                                  |
| 13900020 | Invalid argument                                                                               |
| 13900025 | No space left on device                                                                        |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  let incrementalBackupData: backup.IncrementalBackupData = {
    bundleName: "com.example.hiworld",
    lastIncrementalTime: 1700107870, // 调用者传递上一次备份的时间戳
    manifestFd:1 // 调用者传递上一次备份的manifest文件句柄
  }
  let incrementalBackupDataArray: backup.IncrementalBackupData[] = [incrementalBackupData];
  incrementalBackupSession.appendBundles(incrementalBackupDataArray).then(() => {
    console.info('appendBundles success');
  }).catch((err: BusinessError) => {
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }); // 添加需要增量备份的应用
  ```

### appendBundles<sup>12+</sup>

appendBundles(bundlesToBackup: Array&lt;IncrementalBackupData&gt;, infos: string[]): Promise&lt;void&gt;

添加需要增量备份的应用。当前整个流程中，触发Release接口之前都可以进行appendBundles的调用。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型                                                           | 必填 | 说明                       |
| --------------- | -------------------------------------------------------------- | ---- | -------------------------- |
| bundlesToBackup | Array&lt;[IncrementalBackupData](#incrementalbackupdata12)&gt; | 是   | 需要增量备份的应用的数组。 |
| infos  | string[] | 是   | 备份时各应用所需要扩展信息的数组, 与bundlesToBackup根据索引一一对应。从API version 12开始支持。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900011 | Out of memory                                                                                  |
| 13900020 | Invalid argument                                                                               |
| 13900025 | No space left on device                                                                        |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  let incrementalBackupData: backup.IncrementalBackupData = {
    bundleName: "com.example.hiworld",
    lastIncrementalTime: 1700107870, // 调用者传递上一次备份的时间戳
    manifestFd:1 // 调用者传递上一次备份的manifest文件句柄
  }
      let infos: Array<string> = [
        `
        {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.hiworld"
            }
        ]
    },
    {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.myApp"
            }
        ]
    }
      `
    ]
  let incrementalBackupDataArray: backup.IncrementalBackupData[] = [incrementalBackupData];
  // 添加需要增量备份的应用
  incrementalBackupSession.appendBundles(incrementalBackupDataArray, infos).then(() => {
    console.info('appendBundles success');
  }).catch((err: BusinessError) => {
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }); 
  ```
### release<sup>12+</sup>

release(): Promise&lt;void&gt;

结束增量备份流程。使用Promise异步回调。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900020 | Invalid argument                                                                               |
| 13900042 | Unknown error                                                                                  |

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  incrementalBackupSession.release(); // 结束增量备份流程
  console.info('release success');
  ```

### cancel<sup>18+</sup>

cancel(bundleName: string): number;

增量备份任务过程中，工具应用发现数据异常，需要取消某应用的增量备份时调用此接口，使此应用的增量备份任务终止。

**需要权限**：ohos.permission.BACKUP

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名          | 类型     | 必填 | 说明                       |
| --------------- | -------- | ---- | -------------------------- |
| bundleName | string | 是   | 需要取消备份的应用名称。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| number | 返回取消状态。<br/>0：取消任务下发成功；<br/> 13500011：想要取消的任务未开始；<br/> 13500012：想要取消的任务不存在。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                                                       |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|

**示例：**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  incrementalBackupSession?: backup.IncrementalBackupSession;

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        // 文件fd传输失败，调用取消接口，取消此应用的增量备份任务
        let result = this.incrementalBackupSession.cancel("com.example.myapplication");
        console.info('cancel result:' + result);
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  this.incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // 创建增量备份流程
  ```