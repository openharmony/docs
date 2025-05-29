# @ohos.update (Update)

The **update** module implements update of the entire system, including built-in resources and preset applications, but not third-party applications.

There are two types of updates: SD card update and over the air (OTA) update.

- The SD card update depends on the update packages and SD cards.

- The OTA update depends on the server deployed by the device manufacturer for managing update packages. The OTA server IP address is passed by the caller. The request interface is fixed and developed by the device manufacturer.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { update } from '@kit.BasicServicesKit';
```

## update.getOnlineUpdater

getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater

Obtains an **OnlineUpdater** object.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name        | Type                         | Mandatory  | Description    |
| ----------- | --------------------------- | ---- | ------ |
| upgradeInfo | [UpgradeInfo](#upgradeinfo) | Yes   | **OnlineUpdater** object information.|

**Return value**

| Type                 | Description  |
| ------------------- | ---- |
| [Updater](#updater) | **OnlineUpdater** object.|

**Example**

```ts
try {
      const upgradeInfo: update.UpgradeInfo = {
        upgradeApp: "com.ohos.ota.updateclient",
        businessType: {
          vendor: update.BusinessVendor.PUBLIC,
          subType: update.BusinessSubType.FIRMWARE
        }
      };
      let updater = update.getOnlineUpdater(upgradeInfo);
    } catch(error) {
      console.error(`Fail to get updater error: ${error}`);
    }
```

## update.getRestorer

getRestorer(): Restorer

Obtains a **Restorer** object for restoring factory settings.

**System capability**: SystemCapability.Update.UpdateService


**Return value**

| Type                   | Description    |
| --------------------- | ------ |
| [Restorer](#restorer) | **Restorer** object for restoring factory settings.|


**Example**

```ts
try {
  let restorer = update.getRestorer();
} catch(error) {
  console.error(`Fail to get restorer: ${error}`);
}
```

## update.getLocalUpdater

getLocalUpdater(): LocalUpdater

Obtains a **LocalUpdater** object.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type                           | Description    |
| ----------------------------- | ------ |
| [LocalUpdater](#localupdater) | **LocalUpdater** object.|


**Example**

```ts
try {
  let localUpdater = update.getLocalUpdater();
} catch(error) {
  console.error(`Fail to get localUpdater error: ${error}`);
}
```

## Updater

### checkNewVersion

checkNewVersion(callback: AsyncCallback\<CheckResult>): void

Checks whether a new version is available. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                                      | Mandatory  | Description            |
| -------- | ---------------------------------------- | ---- | -------------- |
| callback | AsyncCallback\<[CheckResult](#checkresult)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.checkNewVersion((err: BusinessError, result: update.CheckResult) => {
      console.log(`checkNewVersion isExistNewVersion  ${result?.isExistNewVersion}`);
    });
```

### checkNewVersion

checkNewVersion(): Promise\<CheckResult>

Checks whether a new version is available. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type                                   | Description                 |
| ------------------------------------- | ------------------- |
| Promise\<[CheckResult](#checkresult)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.checkNewVersion()
      .then((result: update.CheckResult) => {
        console.log(`checkNewVersion isExistNewVersion: ${result.isExistNewVersion}`);
        // Version digest information
        console.log(`checkNewVersion versionDigestInfo: ${result.newVersionInfo.versionDigestInfo.versionDigest}`);
      })
      .catch((err: BusinessError)=>{
        console.log(`checkNewVersion promise error ${JSON.stringify(err)}`);
      });
```

###  getNewVersionInfo

getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void

Obtains information about the new version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                                      | Mandatory  | Description             |
| -------- | ---------------------------------------- | ---- | --------------- |
| callback | AsyncCallback\<[NewVersionInfo](#newversioninfo)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getNewVersionInfo((err: BusinessError, info: update.NewVersionInfo) => {
      console.log(`info displayVersion = ${info?.versionComponents[0].displayVersion}`);
      console.log(`info innerVersion = ${info?.versionComponents[0].innerVersion}`);
});
```

### getNewVersionInfo

getNewVersionInfo(): Promise\<NewVersionInfo>

Obtains information about the new version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| Promise\<[NewVersionInfo](#newversioninfo)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getNewVersionInfo().then((info: update.NewVersionInfo) => {
    console.log(`info displayVersion = ${info.versionComponents[0].displayVersion}`);
    console.log(`info innerVersion = ${info.versionComponents[0].innerVersion}`);
}).catch((err: BusinessError) => {
    console.log(`getNewVersionInfo promise error ${JSON.stringify(err)}`);
});
```

###  getNewVersionDescription

getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void

Obtains the description file of the new version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name               | Type                                      | Mandatory  | Description            |
| ------------------ | ---------------------------------------- | ---- | -------------- |
| versionDigestInfo  | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.        |
| descriptionOptions | [DescriptionOptions](#descriptionoptions) | Yes   | Options of the description file.       |
| callback           | AsyncCallback\<Array\<[ComponentDescription](#componentdescription)>> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options of the description file
const descriptionOptions: update.DescriptionOptions = {
  format: update.DescriptionFormat.STANDARD, // Standard format
  language: "zh-cn" // Chinese
};

updater.getNewVersionDescription(versionDigestInfo, descriptionOptions).then((info: Array<update.ComponentDescription>)=> {
  console.log(`getNewVersionDescription promise info ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.log(`getNewVersionDescription promise error ${JSON.stringify(err)}`);
});
```

### getNewVersionDescription

getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>

Obtains the description file of the new version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name               | Type                                      | Mandatory  | Description    |
| ------------------ | ---------------------------------------- | ---- | ------ |
| versionDigestInfo  | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.|
| descriptionOptions | [DescriptionOptions](#descriptionoptions) | Yes   | Options of the description file.|

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise\<Array\<[ComponentDescription](#componentdescription)>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options of the description file
const descriptionOptions: update.DescriptionOptions = {
  format: update.DescriptionFormat.STANDARD, // Standard format
  language: "zh-cn" // Chinese
};

updater.getNewVersionDescription(versionDigestInfo, descriptionOptions).then((info: Array<update.ComponentDescription>)=> {
  console.log(`getNewVersionDescription promise info ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.log(`getNewVersionDescription promise error ${JSON.stringify(err)}`);
});
```

###  getCurrentVersionInfo

getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void

Obtains information about the current version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                                      | Mandatory  | Description              |
| -------- | ---------------------------------------- | ---- | ---------------- |
| callback | AsyncCallback\<[CurrentVersionInfo](#currentversioninfo)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getCurrentVersionInfo((err: BusinessError, info: update.CurrentVersionInfo) => {
  console.log(`info osVersion = ${info?.osVersion}`);
  console.log(`info deviceName = ${info?.deviceName}`);
  console.log(`info displayVersion = ${info?.versionComponents[0].displayVersion}`);
});
```

### getCurrentVersionInfo

getCurrentVersionInfo(): Promise\<CurrentVersionInfo>

Obtains information about the current version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise\<[CurrentVersionInfo](#currentversioninfo)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getCurrentVersionInfo().then((info: update.CurrentVersionInfo) => {
  console.log(`info osVersion = ${info.osVersion}`);
  console.log(`info deviceName = ${info.deviceName}`);
  console.log(`info displayVersion = ${info.versionComponents[0].displayVersion}`);
}).catch((err: BusinessError) => {
  console.log(`getCurrentVersionInfo promise error ${JSON.stringify(err)}`);
});
```

###  getCurrentVersionDescription

getCurrentVersionDescription(descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void

Obtains the description file of the current version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name               | Type                                      | Mandatory  | Description             |
| ------------------ | ---------------------------------------- | ---- | --------------- |
| descriptionOptions | [DescriptionOptions](#descriptionoptions) | Yes   | Options of the description file.         |
| callback           | AsyncCallback\<Array\<[ComponentDescription](#componentdescription)>> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
// Options of the description file
const descriptionOptions: update.DescriptionOptions = {
  format: update.DescriptionFormat.STANDARD, // Standard format
  language: "zh-cn" // Chinese
};

updater.getCurrentVersionDescription(descriptionOptions, (err, info) => {
  console.log(`getCurrentVersionDescription info ${JSON.stringify(info)}`);
  console.log(`getCurrentVersionDescription err ${JSON.stringify(err)}`);
});
```

### getCurrentVersionDescription

getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>

Obtains the description file of the current version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name               | Type                                      | Mandatory  | Description    |
| ------------------ | ---------------------------------------- | ---- | ------ |
| descriptionOptions | [DescriptionOptions](#descriptionoptions) | Yes   | Options of the description file.|

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| Promise\<Array\<[ComponentDescription](#componentdescription)>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// Options of the description file
const descriptionOptions: update.DescriptionOptions = {
  format: update.DescriptionFormat.STANDARD, // Standard format
  language: "zh-cn" // Chinese
};
updater.getCurrentVersionDescription(descriptionOptions).then((info: Array<update.ComponentDescription>) => {
  console.log(`getCurrentVersionDescription promise info ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.log(`getCurrentVersionDescription promise error ${JSON.stringify(err)}`);
});
```

###  getTaskInfo

getTaskInfo(callback: AsyncCallback\<TaskInfo>): void

Obtains information about the update task. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                                   | Mandatory  | Description              |
| -------- | ------------------------------------- | ---- | ---------------- |
| callback | AsyncCallback\<[TaskInfo](#taskinfo)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getTaskInfo((err: BusinessError, info: update.TaskInfo) => {
  console.log(`getTaskInfo isexistTask= ${info?.existTask}`);
});
```

### getTaskInfo

getTaskInfo(): Promise\<TaskInfo>

Obtains information about the update task. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type                             | Description                 |
| ------------------------------- | ------------------- |
| Promise\<[TaskInfo](#taskinfo)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getTaskInfo().then((info: update.TaskInfo) => {
  console.log(`getTaskInfo isexistTask= ${info.existTask}`);
}).catch((err: BusinessError) => {
  console.log(`getTaskInfo promise error ${JSON.stringify(err)}`);
});
```

###  download

download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void

Downloads the new version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description                                |
| ----------------- | --------------------------------------- | ---- | ---------------------------------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.                            |
| downloadOptions   | [DownloadOptions](#downloadoptions)     | Yes   | Download options.                              |
| callback          | AsyncCallback\<void>                    | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Download options
const downloadOptions: update.DownloadOptions = {
  allowNetwork: update.NetType.CELLULAR, // Whether to allow download over data network
  order: update.Order.DOWNLOAD // Download
};
updater.download(versionDigestInfo, downloadOptions, (err: BusinessError) => {
  console.log(`download error ${JSON.stringify(err)}`);
});
```

### download

download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>

Downloads the new version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description    |
| ----------------- | --------------------------------------- | ---- | ------ |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.|
| downloadOptions   | [DownloadOptions](#downloadoptions)     | Yes   | Download options.  |

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Download options
const downloadOptions: update.DownloadOptions = {
  allowNetwork: update.NetType.CELLULAR, // Whether to allow download over data network
   order: update.Order.DOWNLOAD // Download
};
updater.download(versionDigestInfo, downloadOptions).then(() => {
  console.log(`download start`);
}).catch((err: BusinessError) => {
  console.log(`download error ${JSON.stringify(err)}`);
});
```

###  resumeDownload

resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void

Resumes download of the new version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name                  | Type                                      | Mandatory  | Description                                  |
| --------------------- | ---------------------------------------- | ---- | ------------------------------------ |
| versionDigestInfo     | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.                              |
| resumeDownloadOptions | [ResumeDownloadOptions](#resumedownloadoptions) | Yes   | Options for resuming download.                              |
| callback              | AsyncCallback\<void>                     | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo : update.VersionDigestInfo= {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for resuming download
const resumeDownloadOptions : update.ResumeDownloadOptions= {
  allowNetwork: update.NetType.CELLULAR, // Whether to allow download over data network
};
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions, (err: BusinessError) => {
  console.log(`resumeDownload error ${JSON.stringify(err)}`);
});
```

### resumeDownload

resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>

Resumes download of the new version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name                  | Type                                      | Mandatory  | Description    |
| --------------------- | ---------------------------------------- | ---- | ------ |
| versionDigestInfo     | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.|
| resumeDownloadOptions | [ResumeDownloadOptions](#resumedownloadoptions) | Yes   | Options for resuming download.|

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for resuming download
const resumeDownloadOptions: update.ResumeDownloadOptions = {
  allowNetwork: update.NetType.CELLULAR, // Whether to allow download over data network
};
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions).then(() => {
  console.log(`resumeDownload start`);
}).catch((err: BusinessError) => {
  console.log(`resumeDownload error ${JSON.stringify(err)}`);
});
```

###  pauseDownload

pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void

Pauses download of the new version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                  |
| -------------------- | ---------------------------------------- | ---- | ------------------------------------ |
| versionDigestInfo    | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.                              |
| pauseDownloadOptions | [PauseDownloadOptions](#pausedownloadoptions) | Yes   | Options for pausing download.                              |
| callback             | AsyncCallback\<void>                     | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for pausing download
const pauseDownloadOptions: update.PauseDownloadOptions = {
  isAllowAutoResume: true // Whether to allow automatic resuming of download
};
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions, (err: BusinessError) => {
  console.log(`pauseDownload error ${JSON.stringify(err)}`);
});
```

### pauseDownload

pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>

Resumes download of the new version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name                 | Type                                      | Mandatory  | Description    |
| -------------------- | ---------------------------------------- | ---- | ------ |
| versionDigestInfo    | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.|
| pauseDownloadOptions | [PauseDownloadOptions](#pausedownloadoptions) | Yes   | Options for pausing download.|

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for pausing download
const pauseDownloadOptions: update.PauseDownloadOptions = {
  isAllowAutoResume: true // Whether to allow automatic resuming of download
};
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions).then(() => {
  console.log(`pauseDownload`);
}).catch((err: BusinessError)  => {
  console.log(`pauseDownload error ${JSON.stringify(err)}`);
});
```

###  upgrade

upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void

Updates the version. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description                                  |
| ----------------- | --------------------------------------- | ---- | ------------------------------------ |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.                              |
| upgradeOptions    | [UpgradeOptions](#upgradeoptions)       | Yes   | Update options.                                |
| callback          | AsyncCallback\<void>                    | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Installation options
const upgradeOptions: update.UpgradeOptions = {
  order: update.Order.INSTALL // Installation command
};
updater.upgrade(versionDigestInfo, upgradeOptions, (err: BusinessError) => {
  console.log(`upgrade error ${JSON.stringify(err)}`);
});
```

### upgrade

upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>

Updates the version. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description    |
| ----------------- | --------------------------------------- | ---- | ------ |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.|
| upgradeOptions    | [UpgradeOptions](#upgradeoptions)       | Yes   | Update options.  |

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Installation options
const upgradeOptions: update.UpgradeOptions = {
  order: update.Order.INSTALL // Installation command
};
updater.upgrade(versionDigestInfo, upgradeOptions).then(() => {
  console.log(`upgrade start`);
}).catch((err: BusinessError) => {
  console.log(`upgrade error ${JSON.stringify(err)}`);
});
```

###  clearError

clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void

Clears errors. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description                                  |
| ----------------- | --------------------------------------- | ---- | ------------------------------------ |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.                              |
| clearOptions      | [ClearOptions](#clearoptions)           | Yes   | Clear options.                                |
| callback          | AsyncCallback\<void>                    | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for clearing errors
const clearOptions: update.ClearOptions = {
  status: update.UpgradeStatus.UPGRADE_FAIL,
};
updater.clearError(versionDigestInfo, clearOptions, (err: BusinessError) => {
  console.log(`clearError error ${JSON.stringify(err)}`);
});
```

### clearError

clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>

Clears errors. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name              | Type                                     | Mandatory  | Description    |
| ----------------- | --------------------------------------- | ---- | ------ |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | Yes   | Version digest information.|
| clearOptions      | [ClearOptions](#clearoptions)           | Yes   | Update options.  |

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Version digest information
const versionDigestInfo: update.VersionDigestInfo = {
  versionDigest: "versionDigest" // Version digest information in the check result
};

// Options for clearing errors
const clearOptions: update.ClearOptions = {
  status: update.UpgradeStatus.UPGRADE_FAIL,
};
updater.clearError(versionDigestInfo, clearOptions).then(() => {
  console.log(`clearError success`);
}).catch((err: BusinessError) => {
  console.log(`clearError error ${JSON.stringify(err)}`);
});
```

### getUpgradePolicy

getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void

Obtains the update policy. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                                      | Mandatory  | Description             |
| -------- | ---------------------------------------- | ---- | --------------- |
| callback | AsyncCallback\<[UpgradePolicy](#upgradepolicy)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getUpgradePolicy(err: BusinessError, policy: update.UpgradePolicy) => {
  console.log(`policy downloadStrategy = ${policy?.downloadStrategy}`);
  console.log(`policy autoUpgradeStrategy = ${policy?.autoUpgradeStrategy}`);
});
```

### getUpgradePolicy

getUpgradePolicy(): Promise\<UpgradePolicy>

Obtains the update policy. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise\<[UpgradePolicy](#upgradepolicy)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.getUpgradePolicy().then((policy: update.UpgradePolicy) => {
  console.log(`policy downloadStrategy = ${policy.downloadStrategy}`);
  console.log(`policy autoUpgradeStrategy = ${policy.autoUpgradeStrategy}`);
}).catch((err: BusinessError)  => {
  console.log(`getUpgradePolicy promise error ${JSON.stringify(err)}`);
});
```

### setUpgradePolicy

setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void

Sets the update policy. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                             | Mandatory  | Description           |
| -------- | ------------------------------- | ---- | ------------- |
| policy   | [UpgradePolicy](#upgradepolicy) | Yes   | Update policy.         |
| callback | AsyncCallback\<void>            | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const policy: update.UpgradePolicy = {
  downloadStrategy: false,
  autoUpgradeStrategy: false,
  autoUpgradePeriods: [ { start: 120, end: 240 }] // Automatic update period, in minutes
};
updater.setUpgradePolicy(policy, (err: BusinessError) => {
  console.log(`setUpgradePolicy result: ${err}`);
});
```

### setUpgradePolicy

setUpgradePolicy(policy: UpgradePolicy): Promise\<void>

Sets the update policy. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name   | Type                             | Mandatory  | Description  |
| ------ | ------------------------------- | ---- | ---- |
| policy | [UpgradePolicy](#upgradepolicy) | Yes   | Update policy.|

**Return value**

| Type            | Description                 |
| -------------- | ------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const policy: update.UpgradePolicy = {
  downloadStrategy: false,
  autoUpgradeStrategy: false,
  autoUpgradePeriods: [ { start: 120, end: 240 }] // Automatic update period, in minutes
};
updater.setUpgradePolicy(policy).then(() => {
  console.log(`setUpgradePolicy success`);
}).catch((err: BusinessError) => {
  console.log(`setUpgradePolicy promise error ${JSON.stringify(err)}`);
});
```

###  terminateUpgrade

terminateUpgrade(callback: AsyncCallback\<void>): void

Terminates the update. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name     | Type                  | Mandatory  | Description                                    |
| -------- | -------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.terminateUpgrade((err: BusinessError) => {
  console.log(`terminateUpgrade error ${JSON.stringify(err)}`);
});
```

### terminateUpgrade

terminateUpgrade(): Promise\<void>

Terminates the update. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

updater.terminateUpgrade().then(() => {
  console.log(`terminateUpgrade success`);
}).catch((err: BusinessError) => {
  console.log(`terminateUpgrade error ${JSON.stringify(err)}`);
});
```


### on
on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void

Enables listening for update events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name              | Type                                      | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo)  | Yes   | Event information.|
| taskCallback      | [UpgradeTaskCallback](#upgradetaskcallback) | Yes   | Event callback.|


**Example**

```ts
const eventClassifyInfo: update.EventClassifyInfo = {
  eventClassify: update.EventClassify.TASK, // Listening for update events
  extraInfo: ""
};

updater.on(eventClassifyInfo, (eventInfo: update.EventInfo) => {
  console.log("updater on " + JSON.stringify(eventInfo));
});
```

### off
off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void

Disables listening for update events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name              | Type                                      | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo)  | Yes   | Event information.|
| taskCallback      | [UpgradeTaskCallback](#upgradetaskcallback) | No   | Event callback.|


**Example**

```ts
const eventClassifyInfo: update.EventClassifyInfo = {
  eventClassify: update.EventClassify.TASK, // Listening for update events
  extraInfo: ""
};

updater.off(eventClassifyInfo, (eventInfo: update.EventInfo) => {
  console.log("updater off " + JSON.stringify(eventInfo));
});
```

## Restorer

### factoryReset

factoryReset(callback: AsyncCallback\<void>): void

Restores the scale to its factory settings. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.FACTORY_RESET

**Parameters**

| Name     | Type                  | Mandatory  | Description                                    |
| -------- | -------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation fails, **err** is an error object and a callback is returned. If the operation is successful, **err** is undefined and no callback is returned.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
restorer.factoryReset((err) => {
  console.log(`factoryReset error ${JSON.stringify(err)}`);
});
```

### factoryReset

factoryReset(): Promise\<void>

Restores the scale to its factory settings. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.FACTORY_RESET

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, a callback is returned. If the operation is successful, no callback is returned.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

restorer.factoryReset().then(() => {
  console.log(`factoryReset success`);
}).catch((err: BusinessError) => {
  console.log(`factoryReset error ${JSON.stringify(err)}`);
});
```

## LocalUpdater

### verifyUpgradePackage

verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void

Verifies the update package. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name        | Type                         | Mandatory  | Description              |
| ----------- | --------------------------- | ---- | ---------------- |
| upgradeFile | [UpgradeFile](#upgradefile) | Yes   | Update file.            |
| certsFile   | string                      | Yes   | Path of the certificate file.          |
| callback    | AsyncCallback\<void>        | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
const upgradeFile: update.UpgradeFile = {
  fileType: update.ComponentType.OTA, // OTA package
  filePath: "path" // Path of the local update package
};

localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath", (err) => {
  console.log(`factoryReset error ${JSON.stringify(err)}`);
});
```

### verifyUpgradePackage

verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>

Verifies the update package. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name        | Type                         | Mandatory  | Description    |
| ----------- | --------------------------- | ---- | ------ |
| upgradeFile | [UpgradeFile](#upgradefile) | Yes   | Update file.  |
| certsFile   | string                      | Yes   | Path of the certificate file.|

**Return value**

| Type            | Description                    |
| -------------- | ---------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const upgradeFile: update.UpgradeFile = {
  fileType: update.ComponentType.OTA, // OTA package
  filePath: "path" // Path of the local update package
};
localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath").then(() => {
  console.log(`verifyUpgradePackage success`);
}).catch((err: BusinessError) => {
  console.log(`verifyUpgradePackage error ${JSON.stringify(err)}`);
});
```

### applyNewVersion
applyNewVersion(upgradeFiles: Array<[UpgradeFile](#upgradefile)>, callback: AsyncCallback\<void>): void

Installs the update package. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Parameters**

| Name        | Type                                | Mandatory  | Description                                     |
| ----------- | ---------------------------------- | ---- | --------------------------------------- |
| upgradeFile | Array<[UpgradeFile](#upgradefile)> | Yes   | Update file.                                   |
| callback    | AsyncCallback\<void>               | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an **Error** object.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
const upgradeFiles: Array<update.UpgradeFile> = [{
  fileType: update.ComponentType.OTA, // OTA package
  filePath: "path" // Path of the local update package
}];

localUpdater.applyNewVersion(upgradeFiles, (err) => {
  console.log(`applyNewVersion error ${JSON.stringify(err)}`);
});
```

### applyNewVersion

applyNewVersion(upgradeFiles: Array<[UpgradeFile](#upgradefile)>): Promise\<void>

Installs the update package. This API uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Required permission**: ohos.permission.UPDATE_SYSTEM

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Update Error Codes](errorcode-update.md).

| ID      | Error Message                                                 |
| -------  | ---------------------------------------------------- |
| 201      | Permission denied.       |
| 401      | Parameter verification failed.    |
| 11500104 | IPC error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const upgradeFiles: Array<update.UpgradeFile> = [{
  fileType: update.ComponentType.OTA, // OTA package
  filePath: "path" // Path of the local update package
}];
localUpdater.applyNewVersion(upgradeFiles).then(() => {
  console.log(`applyNewVersion success`);
}).catch((err: BusinessError) => {
  console.log(`applyNewVersion error ${JSON.stringify(err)}`);
});
```

### on
on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void

Enables listening for update events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name              | Type                                      | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo)  | Yes   | Event information.|
| taskCallback      | [UpgradeTaskCallback](#upgradetaskcallback) | Yes   | Event callback.|


**Example**

```ts
const eventClassifyInfo: update.EventClassifyInfo = {
  eventClassify: update.EventClassify.TASK, // Listening for update events
  extraInfo: ""
};

let onTaskUpdate: update.UpgradeTaskCallback = (eventInfo: update.EventInfo) => {
  console.log(`on eventInfo id `, eventInfo.eventId);
};

localUpdater.on(eventClassifyInfo, onTaskUpdate);
```

### off
off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void

Disables listening for update events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name              | Type                                      | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo)  | Yes   | Event information.|
| taskCallback      | [UpgradeTaskCallback](#upgradetaskcallback) | No   | Event callback.|


**Example**

```ts
const eventClassifyInfo: update.EventClassifyInfo = {
  eventClassify: update.EventClassify.TASK, // Listening for update events
  extraInfo: ""
};

let onTaskUpdate: update.UpgradeTaskCallback = (eventInfo: update.EventInfo) => {
  console.log(`on eventInfo id `, eventInfo.eventId);
};

localUpdater.off(eventClassifyInfo, onTaskUpdate);
```

## UpgradeInfo

Represents update information.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type                         | Mandatory  | Description    |
| ------------ | ----------------------------- | ---- | ------ |
| upgradeApp   | string                        | Yes   | Application package name. |
| businessType | [BusinessType](#businesstype) | Yes   | Update service type.|

## BusinessType

Enumerates update service types.

**System capability**: SystemCapability.Update.UpdateService

| Name     | Type                               | Mandatory  | Description  |
| ------- | ----------------------------------- | ---- | ---- |
| vendor  | [BusinessVendor](#businessvendor)   | Yes   | Supplier or vendor. |
| subType | [BusinessSubType](#businesssubtype) | Yes   | Represents an update type. |

## CheckResult

Represents the package check result.

**System capability**: SystemCapability.Update.UpdateService

| Name               | Type                             | Mandatory  | Description    |
| ----------------- | --------------------------------- | ---- | ------ |
| isExistNewVersion | boolean                              | Yes   | Whether a new version is available.<br>The value **true** indicates that a new version is available, and the value **false** indicates the opposite.|
| newVersionInfo    | [NewVersionInfo](#newversioninfo) | No   | Information about the new version. |

## NewVersionInfo

Represents information about the new version.

**System capability**: SystemCapability.Update.UpdateService

| Name               | Type                                    | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.|
| versionComponents | Array\<[VersionComponent](#versioncomponent)> | Yes   | Version components.|

## VersionDigestInfo

Represents version digest information.

**System capability**: SystemCapability.Update.UpdateService

| Name           | Type  | Mandatory  | Description  |
| ------------- | ------ | ---- | ---- |
| versionDigest | string | Yes   | Version digest information.|

## VersionComponent

Represents a version component.

**System capability**: SystemCapability.Update.UpdateService

| Name             | Type                               | Mandatory  | Description      |
| --------------- | ----------------------------------- | ---- | -------- |
| componentId     | string                              | Yes   | Component ID.    |
| componentType   | [ComponentType](#componenttype)     | Yes   | Component type.    |
| upgradeAction   | [UpgradeAction](#upgradeaction)     | Yes   | Update mode.    |
| displayVersion  | string                              | Yes   | Display version number.   |
| innerVersion    | string                              | Yes   | Internal version number.     |
| size            | number                              | Yes   | Size of the update package, in bytes.   |
| effectiveMode   | [EffectiveMode](#effectivemode)     | Yes   | Effective mode.    |
| descriptionInfo | [DescriptionInfo](#descriptioninfo) | Yes   | Information about the version description file.|

## DescriptionOptions

Represents options of the description file.

**System capability**: SystemCapability.Update.UpdateService

| Name      | Type                                   | Mandatory  | Description    |
| -------- | --------------------------------------- | ---- | ------ |
| format   | [DescriptionFormat](#descriptionformat) | Yes   | Format of the description file.|
| language | string                                  | Yes   | Language of the description file.|

## ComponentDescription

Represents a component description file.

**System capability**: SystemCapability.Update.UpdateService

| Name             | Type                               | Mandatory  | Description    |
| --------------- | ----------------------------------- | ---- | ------ |
| componentId     | string                              | Yes   | Component ID.  |
| descriptionInfo | [DescriptionInfo](#descriptioninfo) | Yes   | Information about the description file.|

## DescriptionInfo

Represents information about the version description file.

**System capability**: SystemCapability.Update.UpdateService

| Name             | Type                               | Mandatory  | Description    |
| --------------- | ----------------------------------- | ---- | ------ |
| descriptionType | [DescriptionType](#descriptiontype) | Yes   | Type of the description file.|
| content         | string                              | Yes   | Content of the description file.|

## CurrentVersionInfo

Represents information about the current version.

**System capability**: SystemCapability.Update.UpdateService

| Name               | Type                                    | Mandatory  | Description   |
| ----------------- | ---------------------------------------- | ---- | ----- |
| osVersion         | string                                   | Yes   | System version number.|
| deviceName        | string                                   | Yes   | Device name.  |
| versionComponents | Array\<[VersionComponent](#versioncomponent)> | No   | Version components. |

## DownloadOptions

Represents download options.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type               | Mandatory  | Description  |
| ------------ | ------------------- | ---- | ---- |
| allowNetwork | [NetType](#nettype) | Yes   | Network type.|
| order        | [Order](#order)     | Yes   | Update command.|

## ResumeDownloadOptions

Represents options for resuming download.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type               | Mandatory  | Description  |
| ------------ | ------------------- | ---- | ---- |
| allowNetwork | [NetType](#nettype) | Yes   | Network type.|

## PauseDownloadOptions

Represents options for pausing download.

**System capability**: SystemCapability.Update.UpdateService

| Name               | Type| Mandatory  | Description      |
| ----------------- | ---- | ---- | -------- |
| isAllowAutoResume | boolean | Yes   | Whether to allow automatic resuming of download.<br>The value **true** indicates that automatic resuming is allowed, and the value **false** indicates the opposite.|

## UpgradeOptions

Represents update options.

**System capability**: SystemCapability.Update.UpdateService

| Name   | Type           | Mandatory  | Description  |
| ----- | --------------- | ---- | ---- |
| order | [Order](#order) | Yes   | Update command.|

## ClearOptions

Represents options for clearing errors.

**System capability**: SystemCapability.Update.UpdateService

| Name    | Type                           | Mandatory  | Description  |
| ------ | ------------------------------- | ---- | ---- |
| status | [UpgradeStatus](#upgradestatus) | Yes   | Error status.|

## UpgradePolicy

Represents an update policy.

**System capability**: SystemCapability.Update.UpdateService

| Name                 | Type                                   | Mandatory  | Description     |
| ------------------- | --------------------------------------- | ---- | ------- |
| downloadStrategy    | boolean                        | Yes   | Automatic download policy.<br>The value **true** indicates that automatic download is supported, and the value **false** indicates the opposite.|
| autoUpgradeStrategy | boolean                        | Yes   | Automatic update policy.<br>The value **true** indicates that automatic update is supported, and the value **false** indicates the opposite.|
| autoUpgradePeriods  | Array\<[UpgradePeriod](#upgradeperiod)> | Yes   | Automatic update period.|

## UpgradePeriod

Represents an automatic update period.

**System capability**: SystemCapability.Update.UpdateService

| Name   | Type  | Mandatory  | Description  |
| ----- | ------ | ---- | ---- |
| start | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

## TaskInfo

Task information.

**System capability**: SystemCapability.Update.UpdateService

| Name       | Type                 | Mandatory  | Description    |
| --------- | --------------------- | ---- | ------ |
| existTask |  boolean                  | Yes   | Whether a task exists.<br>The value **true** indicates that the task exists, and the value **false** indicates the opposite.|
| taskBody  | [TaskBody](#taskbody) | Yes   | Task data.  |

## EventInfo

Represents event information.

**System capability**: SystemCapability.Update.UpdateService

| Name      | Type                 | Mandatory  | Description  |
| -------- | --------------------- | ---- | ---- |
| eventId  | [EventId](#eventid)   | Yes   | Event ID.|
| taskBody | [TaskBody](#taskbody) | Yes   | Task data.|

## TaskBody

Represents task data.

**System capability**: SystemCapability.Update.UpdateService

| Name               | Type                                    | Mandatory  | Description  |
| ----------------- | ---------------------------------------- | ---- | ---- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo)  | Yes   | Version digest information.|
| status            | [UpgradeStatus](#upgradestatus)          | Yes   | Update status.|
| subStatus         | number                                   | No   | Sub-status. |
| progress          | number                                   | Yes   | Progress.  |
| installMode       | number                                   | Yes   | Installation mode.|
| errorMessages     | Array\<[ErrorMessage](#errormessage)>    | No   | Error message.|
| versionComponents | Array\<[VersionComponent](#versioncomponent)> | Yes   | Version components.|

## ErrorMessage

Represents an error message.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type  | Mandatory  | Description  |
| ------------ | ------ | ---- | ---- |
| errorCode    | number | Yes   | Error code. |
| errorMessage | string | Yes   | Error message.|

## EventClassifyInfo

Represents event type information.

**System capability**: SystemCapability.Update.UpdateService

| Name           | Type                           | Mandatory  | Description  |
| ------------- | ------------------------------- | ---- | ---- |
| eventClassify | [EventClassify](#eventclassify) | Yes   | Event type.|
| extraInfo     | string                          | Yes   | Additional information.|

## UpgradeFile

Represents an update file.

**System capability**: SystemCapability.Update.UpdateService

| Name      | Type                           | Mandatory  | Description  |
| -------- | ------------------------------- | ---- | ---- |
| fileType | [ComponentType](#componenttype) | Yes   | File type.|
| filePath | string                          | Yes   | File path.|

## UpgradeTaskCallback

(eventInfo: EventInfo): void

Represents an event callback.

**System capability**: SystemCapability.Update.UpdateService

| Name       | Type                   | Mandatory  | Description  |
| --------- | ----------------------- | ---- | ---- |
| eventInfo | [EventInfo](#eventinfo) | Yes   | Event information.|

## BusinessVendor

Represents a device vendor.

**System capability**: SystemCapability.Update.UpdateService

| Name   | Value     | Description  |
| ------ | -------- | ---- |
| PUBLIC | "public" | Open source.  |

## BusinessSubType

Represents an update type.

**System capability**: SystemCapability.Update.UpdateService

| Name     | Value | Description  |
| -------- | ---- | ---- |
| FIRMWARE | 1    | Firmware.  |

## ComponentType

Represents a component type.

**System capability**: SystemCapability.Update.UpdateService

| Name | Value | Description  |
| ---- | ---- | ---- |
| OTA  | 1    | Firmware.  |

## UpgradeAction

Represents an update mode.

**System capability**: SystemCapability.Update.UpdateService

| Name     | Value       | Description  |
| -------- | ---------- | ---- |
| UPGRADE  | "upgrade"  | Differential package. |
| RECOVERY | "recovery" | Recovery package. |

## EffectiveMode

Represents an effective mode.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Value | Description  |
| ------------- | ---- | ---- |
| COLD          | 1    | Cold update. |
| LIVE          | 2    | Live update. |
| LIVE_AND_COLD | 3    | Hybrid live and cold update.|

## DescriptionType

Represents a description file type.

**System capability**: SystemCapability.Update.UpdateService

| Name    | Value | Description  |
| ------- | ---- | ---- |
| CONTENT | 0    | Content.  |
| URI     | 1    | Link.  |

## DescriptionFormat

Represents a description file format.

**System capability**: SystemCapability.Update.UpdateService

| Name       | Value | Description  |
| ---------- | ---- | ---- |
| STANDARD   | 0    | Standard format.|
| SIMPLIFIED | 1    | Simple format.|

## NetType

Represents a network type.

**System capability**: SystemCapability.Update.UpdateService

| Name              | Value | Description       |
| ----------------- | ---- | --------- |
| CELLULAR          | 1    | Data network.     |
| METERED_WIFI      | 2    | Wi-Fi hotspot.   |
| NOT_METERED_WIFI  | 4    | Non Wi-Fi hotspot.  |
| WIFI              | 6    | Wi-Fi.     |
| CELLULAR_AND_WIFI | 7    | Data network and Wi-Fi.|

## Order

Represents an update command.

**System capability**: SystemCapability.Update.UpdateService

| Name                 | Value | Description   |
| -------------------- | ---- | ----- |
| DOWNLOAD             | 1    | Download.   |
| INSTALL              | 2    | Install.   |
| DOWNLOAD_AND_INSTALL | 3    | Download and install.|
| APPLY                | 4    | Apply.   |
| INSTALL_AND_APPLY    | 6    | Install and apply.|

## UpgradeStatus

Enumerates update states.

**System capability**: SystemCapability.Update.UpdateService

| Name             | Value | Description  |
| ---------------- | ---- | ---- |
| WAITING_DOWNLOAD | 20   | Waiting for download. |
| DOWNLOADING      | 21   | Downloading. |
| DOWNLOAD_PAUSED  | 22   | Download paused.|
| DOWNLOAD_FAIL    | 23   | Download failed.|
| WAITING_INSTALL  | 30   | Waiting for installation. |
| UPDATING         | 31   | Updating. |
| WAITING_APPLY    | 40   | Waiting for applying the update. |
| APPLYING         | 41   | Applying the update. |
| UPGRADE_SUCCESS  | 50   | Update succeeded.|
| UPGRADE_FAIL     | 51   | Update failed.|

## EventClassify

Represents an event type.

**System capability**: SystemCapability.Update.UpdateService

| Name  | Value       | Description  |
| ---- | ---------- | ---- |
| TASK | 0x01000000 | Task event.|

## EventId

Enumerates event IDs.

**System capability**: SystemCapability.Update.UpdateService

| Name                    | Value       | Description    |
| ---------------------- | ---------- | ------ |
| EVENT_TASK_BASE        | EventClassify.TASK | Task event.  |
| EVENT_TASK_RECEIVE     | 0x01000001 | Task received.  |
| EVENT_TASK_CANCEL      | 0x01000002 | Task cancelled.  |
| EVENT_DOWNLOAD_WAIT    | 0x01000003 | Waiting for download.   |
| EVENT_DOWNLOAD_START   | 0x01000004 | Download started.  |
| EVENT_DOWNLOAD_UPDATE  | 0x01000005 | Download progress update.|
| EVENT_DOWNLOAD_PAUSE   | 0x01000006 | Download paused.  |
| EVENT_DOWNLOAD_RESUME  | 0x01000007 | Download resumed.  |
| EVENT_DOWNLOAD_SUCCESS | 0x01000008 | Download succeeded.  |
| EVENT_DOWNLOAD_FAIL    | 0x01000009 | Download failed.  |
| EVENT_UPGRADE_WAIT     | 0x0100000A | Waiting for update.   |
| EVENT_UPGRADE_START    | 0x0100000B | Update started.  |
| EVENT_UPGRADE_UPDATE   | 0x0100000C | Update in progress.   |
| EVENT_APPLY_WAIT       | 0x0100000D | Waiting for applying the update.   |
| EVENT_APPLY_START      | 0x0100000E | Applying the update.  |
| EVENT_UPGRADE_SUCCESS  | 0x0100000F | Update succeeded.  |
| EVENT_UPGRADE_FAIL     | 0x01000010 | Update failed.  |
