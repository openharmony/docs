# Update

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Update module applies to updates throughout the entire system, including built-in resources and preset applications, but not third-party applications.

There are two types of updates: SD card update and over the air (OTA) update.

- The SD card update depends on the update packages and SD cards.
- The OTA update depends on the server deployed by the device manufacturer for managing update packages. The OTA server IP address is passed by the caller. The request interface is fixed and developed by the device manufacturer.

## Modules to Import

```js
import update from '@ohos.update'
```

## Required Permissions

None

## update.getUpdater

getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater

Obtains the **Updater** object for local update.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name        | Type                        | Mandatory | Description  |
| ----------- | --------------------------- | --------- | ------------ |
| upgradeFile | string                      | Yes       | Update file. |
| updateType  | [UpdateTypes](#updatetypes) | Yes       | Update type. |

**Return value**

| Type                | Description         |
| ------------------- | ------------------- |
| [Updater](#updater) | **Updater** object. |

**Example**

```
try {
  let updater = update.getUpdater('/data/updater/updater.zip', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## update.getUpdaterForOther

getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater

Obtains the **Updater** object for the device to be updated.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name        | Type                        | Mandatory | Description           |
| ----------- | --------------------------- | --------- | --------------------- |
| upgradeFile | string                      | Yes       | Update file.          |
| device      | string                      | Yes       | Device to be updated. |
| updateType  | [UpdateTypes](#updatetypes) | Yes       | Update type.          |

**Return value**

| Type                | Description         |
| ------------------- | ------------------- |
| [Updater](#updater) | **Updater** object. |

**Example**

```
try {
  let updater = update.getUpdaterForOther('/data/updater/updater.zip', '1234567890', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## update.getUpdaterFromOther

getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater

Obtains the **Updater** object from another device for the device to be updated.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name        | Type                        | Mandatory | Description           |
| ----------- | --------------------------- | --------- | --------------------- |
| upgradeFile | string                      | Yes       | Update file.          |
| device      | string                      | Yes       | Device to be updated. |
| updateType  | [UpdateTypes](#updatetypes) | Yes       | Update type.          |

**Return value**

| Type                | Description         |
| ------------------- | ------------------- |
| [Updater](#updater) | **Updater** object. |

**Example**

```
try {
  let updater = update.getUpdaterFromOther('/data/updater/updater.zip', '1234567890', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## Updater

###  getNewVersionInfo

getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void

Obtains the new version information. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback<[NewVersionInfo](#newversioninfo)> | No        | Callback used to return the new version information. |

**Example**

```
updater.getNewVersionInfo(info => {
  console.log("getNewVersionInfo success  " + info.status);
  console.log(`info versionName = ` + info.checkResult[0].versionName);
  console.log(`info versionCode = ` + info.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + info.checkResult[0].verifyInfo);
});
```

### getNewVersionInfo

getNewVersionInfo(): Promise\<NewVersionInfo>

Obtains the new version information. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise\<[NewVersionInfo](#newversioninfo)> | Promise used to return the new version information. |

**Example**

```
updater.getNewVersionInfo().then(value => {
  console.log(`info versionName = ` + value.checkResult[0].versionName);
  console.log(`info versionCode = ` + value.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + value.checkResult[0].verifyInfo);
}).catch(err => {
  console.log("getNewVersionInfo promise error: " + err.code);
});
```

### checkNewVersion

checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void

Checks whether the current version is the latest. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback\<[NewVersionInfo](#newversioninfo)> | No        | Callback used to return the new version information. |

**Example**

```
updater.checkNewVersion(info => {
  console.log("checkNewVersion success  " + info.status);
  console.log(`info versionName = ` + info.checkResult[0].versionName);
  console.log(`info versionCode = ` + info.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + info.checkResult[0].verifyInfo);
});
```

### checkNewVersion

checkNewVersion(): Promise\<NewVersionInfo>

Checks whether the current version is the latest. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise\<[NewVersionInfo](#newversioninfo)> | Promise used to return the new version information. |

**Example**

```
updater.checkNewVersion().then(value => {
  console.log(`info versionName = ` + value.checkResult[0].versionName);
  console.log(`info versionCode = ` + value.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + value.checkResult[0].verifyInfo);
}).catch(err => {
  console.log("checkNewVersion promise error: " + err.code);
});
```

### verifyUpdatePackage

verifyUpdatePackage(upgradeFile: string, certsFile: string): void

Verifies whether the update package is valid.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name        | Type   | Mandatory | Description                              |
| ----------- | ------ | --------- | ---------------------------------------- |
| upgradeFile | string | Yes       | Path of the update package to be verified. |
| certsFile   | string | Yes       | Certificate path.                        |

**Example**

```
updater.on("verifyProgress", callback => {
  console.info('on verifyProgress ' + callback.percent);
});
update.verifyUpdatePackage("XXX", "XXX");
```

### rebootAndCleanUserData<sup>8+</sup>

rebootAndCleanUserData(): Promise\<number>

Reboots the device and clears the user partition data. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type             | Description                              |
| ---------------- | ---------------------------------------- |
| Promise\<number> | Promise used to return the execution result. |

**Example**

```
updater.rebootAndCleanUserData().then(result => {
  console.log("rebootAndCleanUserData " + result);
}).catch(err => {
  console.info("rebootAndCleanUserData promise error: " + err.code);
});
```

### rebootAndCleanUserData<sup>8+</sup>

rebootAndCleanUserData(callback: AsyncCallback\<number>): void

Reboots the device and clears the user partition data. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                   | Mandatory | Description                              |
| -------- | ---------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback\<number> | Yes       | Callback used to return the execution result. |

**Example**

```
updater.rebootAndCleanUserData(result => {
  console.log("rebootAndCleanUserData ", result)
});
```

### applyNewVersion

applyNewVersion(): Promise\<number>

Installs the update package. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type             | Description                              |
| ---------------- | ---------------------------------------- |
| Promise\<number> | Promise used to return the execution result. |

**Example**

```
updater.applyNewVersion().then(result => {
    console.log("appVewVersion ", result)
}).catch(err => {
    console.info("applyNewVersion promise error: " + err.code);
});
```

### applyNewVersion

applyNewVersion(callback: AsyncCallback\<number>): void

Installs the update package. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                   | Mandatory | Description                              |
| -------- | ---------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback\<number> | Yes       | Callback used to return the execution result. |

**Example**

```
updater.applyNewVersion(result => {
  console.log("applyNewVersion ", result)
});
```

### download

download(): void

Downloads the new version and displays the download process.

**System capability**: SystemCapability.Update.UpdateService

**Example**

```
updater.on("downloadProgress", progress => {
  console.log("downloadProgress on" + progress);
  console.log(`downloadProgress status: ` + progress.status);
  console.log(`downloadProgress percent: ` + progress.percent);
});
updater.download();
```

### upgrade

upgrade():void

Starts an update.

**System capability**: SystemCapability.Update.UpdateService

**Example**

```
updater.on("upgradeProgress", progress => {
  console.log("upgradeProgress on" + progress);
  console.log(`upgradeProgress status: ` + progress.status);
  console.log(`upgradeProgress percent: ` + progress.percent);
});
updater.upgrade();
```

### setUpdatePolicy

setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void

Sets the update policy. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| policy   | [UpdatePolicy](#updatepolicy)            | Yes       | Update policy to set.                    |
| callback | Callback used to return the execution result. | Yes       | Callback used to return the execution result. |

**Example**

```
// Set the update policy.
let policy = {
  autoDownload: false,
  autoDownloadNet: true,
  mode: 2,
  autoUpgradeInterval: [ 2, 3 ],
  autoUpgradeCondition: 2
}
updater.setUpdatePolicy(policy, result => {
  console.log("setUpdatePolicy ", result)
});
```

### setUpdatePolicy

setUpdatePolicy(policy: UpdatePolicy): Promise\<number>

Sets the update policy. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name   | Type                          | Mandatory | Description           |
| ------ | ----------------------------- | --------- | --------------------- |
| policy | [UpdatePolicy](#updatepolicy) | Yes       | Update policy to set. |

**Return value**

| Type             | Description                              |
| ---------------- | ---------------------------------------- |
| Promise\<number> | Promise used to return the execution result. |

**Example**

```
let policy = {
  autoDownload: false,
  autoDownloadNet: true,
  mode: 2,
  autoUpgradeInterval: [ 2, 3 ],
  autoUpgradeCondition: 2
}
updater.setUpdatePolicy(policy).then(result => 
  console.log("setUpdatePolicy ", result)
).catch(err => {
  console.log("setUpdatePolicy promise error: " + err.code);
});
```

### getUpdatePolicy

getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void

Obtains the update policy. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Parameters**

| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback\<[UpdatePolicy](#updatepolicy)> | No        | Callback used to return the update policy. |

**Example**

```
updater.getUpdatePolicy(policy => {
  console.log("getUpdatePolicy success");
  console.log(`policy autoDownload = ` + policy.autoDownload);
  console.log(`policy autoDownloadNet = ` + policy.autoDownloadNet);
  console.log(`policy mode = ` + policy.mode);
});
```

### getUpdatePolicy

getUpdatePolicy(): Promise\<UpdatePolicy>

Obtains the update policy. This function uses a promise to return the result.

**System capability**: SystemCapability.Update.UpdateService

**Return value**

| Type                                    | Description                              |
| --------------------------------------- | ---------------------------------------- |
| Promise\<[UpdatePolicy](#updatepolicy)> | Promise used to return the update policy. |

**Example**

```
updater.getUpdatePolicy().then(value => {
  console.log(`info autoDownload = ` + value.autoDownload);
  console.log(`info autoDownloadNet = ` + value.autoDownloadNet);
  console.log(`info mode = ` + value.mode);
}).catch(err => {
  console.log("getUpdatePolicy promise error: " + err.code);
});
```

## UpdateTypes

Enumerates update types.

**System capability**: SystemCapability.Update.UpdateService

| Name  | Description   |
| ----- | ------------- |
| OTA   | OTA update.   |
| patch | Patch update. |

## PackageTypes

Enumerates update package types.

**System capability**: SystemCapability.Update.UpdateService

| Name                 | Default Value | Description                             |
| -------------------- | ------------- | --------------------------------------- |
| PACKAGE_TYPE_NORMAL  | 1             | Common update package.                  |
| PACKAGE_TYPE_BASE    | 2             | Basic update package.                   |
| PACKAGE_TYPE_CUST    | 3             | Custom update package.                  |
| PACKAGE_TYPE_PRELOAD | 4             | Preinstalled update package.            |
| PACKAGE_TYPE_COTA    | 5             | Parameter configuration update package. |
| PACKAGE_TYPE_VERSION | 6             | Version update package.                 |
| PACKAGE_TYPE_PATCH   | 7             | Patch package.                          |

## InstallMode

Enumerates update modes.

**System capability**: SystemCapability.Update.UpdateService

| Name                | Default Value | Description       |
| ------------------- | ------------- | ----------------- |
| INSTALL_MODE_NORMAL | 0             | Normal update.    |
| INSTALL_MODE_NIGHT  | 1             | Update at night.  |
| INSTALL_MODE_AUTO   | 2             | Automatic update. |

## NewVersionStatus

Enumerates new version check results.

**System capability**: SystemCapability.Update.UpdateService

| Name                | Default Value | Description                              |
| ------------------- | ------------- | ---------------------------------------- |
| VERSION_STATUS_ERR  | -1            | System error while checking for the new version. |
| VERSION_STATUS_NEW  | 0             | New version detected.                    |
| VERSION_STATUS_NONE | 1             | No new version detected.                 |
| VERSION_STATUS_BUSY | 2             | System busy while checking for the new version. |

## UpdatePolicy

Defines the update policy.

**System capability**: SystemCapability.Update.UpdateService

| Name                | Type                        | Mandatory | Description                          |
| ------------------- | --------------------------- | --------- | ------------------------------------ |
| autoDownload        | bool                        | Yes       | Automatic update switch.             |
| installMode         | [InstallMode](#installmode) | Yes       | Update mode.                         |
| autoUpgradeInterval | Array\<number>              | Yes       | Period of time for automatic update. |

## NewVersionInfo

Defines the new version information.

**System capability**: SystemCapability.Update.UpdateService

| Name            | Type                                     | Mandatory | Description                      |
| --------------- | ---------------------------------------- | --------- | -------------------------------- |
| status          | [NewVersionStatus](#newversionstatus)    | Yes       | Update status.                   |
| errMsg          | string                                   | Yes       | Error message.                   |
| checkResults    | Array<[CheckResult](#checkresult)>       | Yes       | Version check result.            |
| descriptionInfo | Array\<[DescriptionInfo](#descriptioninfo)> | Yes       | Version description information. |

## CheckResult

Defines the version check result.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type                          | Mandatory | Description                       |
| ------------- | ----------------------------- | --------- | --------------------------------- |
| versionName   | string                        | Yes       | Version name.                     |
| versionCode   | number                        | Yes       | Version code.                     |
| size          | number                        | Yes       | Version size.                     |
| verifyInfo    | string                        | Yes       | Version verification information. |
| packageType   | [PackageTypes](#packagetypes) | Yes       | Version type.                     |
| descriptionId | string                        | Yes       | Version description information.  |

## DescriptionInfo

Defines the version description information.

**System capability**: SystemCapability.Update.UpdateService

| Name          | Type   | Mandatory | Description                    |
| ------------- | ------ | --------- | ------------------------------ |
| descriptionId | string | Yes       | Version ID information.        |
| content       | string | Yes       | Version changelog information. |
