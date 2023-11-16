# Backup and Restoration Triggered by System Applications

The backup and restoration framework provides a complete data backup and restoration solution for application data, user data, and system services on devices. You can follow the procedure below to enable an application to trigger data backup or restoration:

- [Obtain capability files](#obtaining-capability-files): Obtain capability files of all applications of the user in the system. The capability files are indispensable for data backup and restoration.

- [Back up application data](#backing-up-application-data): Back up the application data based on the application information in the capability files.

- [Restore application data](#restoring-application-data): Restore the application data based on the application information in the capability files.

- [Install the application during data restoration](#installing-the-application-during-data-restoration): Install the application if the application with data to be restored has not been installed. As an extended function of application data restoration, this function allows the application to be installed on the device before data restoration.

## How to Develop

For details about the APIs to be used, see [Backup and Restoration](../reference/apis/js-apis-file-backup.md).

Before using the APIs, you need to:

1. Apply for the **ohos.permission.BACKUP** permission. For details, see [Apply for Permissions](../security/accesstoken-guidelines.md).

2. Import **@ohos.file.backup**.

   ```js
   import backup from '@ohos.file.backup';
   ```

## Obtaining Capability Files

Obtain capability files of all applications of the current user. The capability files are indispensable for application data backup and restoration.

The capability file of an application contains the device type, device version, and basic application information, such as the application name, application size, application version, whether to allow backup and restoration, and whether to install the application during restoration.

Use **backup.getLocalCapabilities()** to obtain capability files.

```ts
import backup from '@ohos.file.backup';
import common from '@ohos.app.ability.common';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

// Obtain the application file path.
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

**Capability file example**

| Name      | Type| Mandatory| Description                  |
| -------------- | -------- | ---- | ---------------------- |
| bundleInfos    | Array    | Yes  | Application information.          |
| &nbsp;&nbsp;&nbsp;&nbsp; allToBackup    | Boolean  | Yes  | Whether to allow backup and restoration.      |
| &nbsp;&nbsp;&nbsp;&nbsp; extensionName  | String  | Yes  | Extension name of the application.          |
| &nbsp;&nbsp;&nbsp;&nbsp; name           | String  | Yes  | Bundle name of the application.            |
| &nbsp;&nbsp;&nbsp;&nbsp; needToInstall  | Boolean  | Yes  | Whether to install the application during data restoration.|
| &nbsp;&nbsp;&nbsp;&nbsp; spaceOccupied  | Number    | Yes  | Space occupied by the application data.|
| &nbsp;&nbsp;&nbsp;&nbsp; versionCode    | Number    | Yes  | Application version number.          |
| &nbsp;&nbsp;&nbsp;&nbsp; versionName    | String  | Yes  | Application version name.        |
| deviceType     | String  | Yes  | Type of the device.              |
| systemFullName | String  | Yes  | Device version.              |

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

## Backing Up Application Data

You can select the application data to be backed up based on the application information in the capability files.

The Backup & Restore service packages the application data to be backed up. The package file handle is returned by the [onFileReady](../reference/apis/js-apis-file-backup.md#onfileready) callback registered when the **SessionBackup** instance is created.

You can save the file to a local directory as required.

**Example**

 ```ts
  import backup from '@ohos.file.backup';
  import common from '@ohos.app.ability.common';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  // Obtain the sandbox path.
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;
  // Create a SessionBackup instance for data backup.
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
    // Select the application to be backed up based on the capability file obtained by backup.getLocalCapabilities().
    // You can also back up data based on the application bundle name.
    const backupApps: string[] = [
      "com.example.hiworld",
    ]
    await g_session.appendBundles(backupApps);
    console.info('appendBundles success');
  }
 ```

## Restoring Application Data

You can select the application data to be restored based on the application information in the capability files.

The Backup and Restore service returns the file handle of the application data to be restored in the [onFileReady](../reference/apis/js-apis-file-backup.md#onfileready) callback registered when the **SessionRestore** instance is created. The file handle is obtained by [getFileHandle](../reference/apis/js-apis-file-backup.md#getfilehandle). Then, the data to be restored is written to the file handle based on the [uri](../reference/apis/js-apis-file-backup.md#filemeta) returned. After the data is written, use [publishFile()](../reference/apis/js-apis-file-backup.md#publishfile) to notify the service that the data write is complete.

When all the data of the application is ready, the service starts to restore the application data.

**Example**

 ```ts
  import backup from '@ohos.file.backup';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  // Create a SessionRestore instance for data restoration.
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
        // Set bundlePath based on the actual situation.
        let bundlePath: string = '';
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // After the data is transferred, notify the server that the files are ready.
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
    // You can obtain the capability file based on actual situation. The following is an example only.
    // You can also construct capability files as required.
    let fileData = await backup.getLocalCapabilities();
    await g_session.appendBundles(fileData.fd, restoreApps);
    console.info('appendBundles success');
    // After the applications to be restored are added, call getFileHandle() to obtain the handles of the application files to be restored based on the application name.
    // The number of application data files to be restored varies depending on the number of backup files. The following is only an example.
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

## Installing the Application During Data Restoration

If the application has not been installed, you can install the application and then restore the application data. To achieve this purpose, the value of **needToInstall** in **bundleInfos** in the [capability file](#obtaining-capability-files) must be **true**.

> **NOTE**
>
> - [Application data backup](#backing-up-application-data) does not support backup of the application installation package. Therefore, you need to obtain the application installation package.
> - To obtain the file handle of an application installation package, call [getFileHandle()](../reference/apis/js-apis-file-backup.md#getfilehandle) with **FileMeta.uri** set to **/data/storage/el2/restore/bundle.hap**. The file handle of the application installation package is returned through the **onFileReady()** callback registered when the instance is created. The returned **File.uri** is **data/storage/el2/restore/bundle.hap**.

**Example**

 ```ts
  import backup from '@ohos.file.backup';
  import common from '@ohos.app.ability.common';
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  // Obtain the sandbox path.
  let context = getContext(this) as common.UIAbilityContext;
  let filesDir = context.filesDir;
  // Create a SessionRestore instance for data restoration.
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
          // Set the path of the application installation package based on actual situation.
        } else {
          // Set bundlePath based on the actual situation.
        }
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // After the data is transferred, notify the server that the files are ready.
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

    // Obtain the file handle of the application to be installed.
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

  **Capability file example**
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