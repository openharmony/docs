# Triggering Backup and Restore (for System Applications Only)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @chenxi0605-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=23fd3050bf417376fb6020b82cd43307338e4432 translatedAt=2026-08-01T07:23:05.447Z pushedAt=2026-08-01T08:19:58.326Z -->

The backup and restore framework provides a solution for backing up and restoring data of applications and services on a device. You can follow the procedure below to enable an application to trigger data backup or restoration:

- [Obtain capability files](#obtaining-capability-files): Obtain capability files of all applications of the user in the system. The capability files are indispensable for data backup and restoration.

- [Back up application data](#backing-up-application-data): Back up the application data based on the application information in the capability files.

- [Restore application data](#restoring-application-data): Restore the application data based on the application information in the capability files.

## How to Develop

For details about how to use the APIs, see [Backup and Restore](../reference/apis-core-file-kit/js-apis-file-backup-sys.md).

Before using the APIs, you need to:

1. Apply for the `ohos.permission.BACKUP` permission. For details, see [Requesting Permissions for system_basic Applications](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Import `@ohos.file.backup`.

   ```js
   import { backup } from '@kit.CoreFileKit';
   ```

## Obtaining Capability Files

Obtain capability files of all applications of the current user. The capability files are indispensable for application data backup and restoration.

The capability file of an application contains the device type, device version, and basic application information, such as the application name, application size, application version, whether to allow backup and restoration, and whether to install the application during restoration.

Call [backup.getLocalCapabilities()](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#backupgetlocalcapabilities) to obtain the capability file.

<!-- @[get_local_cap_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/AppFileBackup/entry/src/main/ets/backuprestore/BackupRestore.ets) -->

``` TypeScript
import { fileIo } from '@kit.CoreFileKit';
import { backup } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

// This is only an example. The path can be obtained via getHostContext within the component.
let filesDir = '/data/storage/el2/base/haps/entry/files';

// Obtain capability files.
export async function getLocalCapabilities(): Promise<void> {
  try {
    let fileData = await backup.getLocalCapabilities();
    console.info('getLocalCapabilities success');
    let fpath = filesDir + '/localCapabilities.json';
    fileIo.copyFileSync(fileData.fd, fpath);
    // ...
    fileIo.closeSync(fileData.fd);
  } catch (error) {
    console.error(`getLocalCapabilities failed with err, code is ${error.code}, message is ${error.message}`);
  }
}
```

**Capability file example**

| Name      | Type| Mandatory| Description                  |
| -------------- | -------- | ---- | ---------------------- |
| bundleInfos    | Array    | Yes  | Application information.          |
| allToBackup    | Boolean  | Yes  | Whether to allow backup and restoration. The value **true** means that backup and restoration are allowed; the value **false** means the opposite.      |
| extensionName  | String  | Yes  | Extension name of the application.          |
| name           | String  | Yes  | Bundle name of the application.            |
| spaceOccupied  | Number    | Yes  | Space occupied by an application, in bytes.|
| versionCode    | Number    | Yes  | Application version number.          |
| versionName    | String  | Yes  | Application version name.        |
| deviceType     | String  | Yes  | Device type.              |
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

The Backup & Restore service packages the application data to be backed up. The package file handle is returned by the [onFileReady](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#onfileready) callback registered when the **SessionBackup** instance is created.

You can save the file to a local directory as required.

**Example**

  <!-- @[session_backup](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/AppFileBackup/entry/src/main/ets/backuprestore/BackupRestore.ets) -->

  ``` TypeScript
  import { fileIo } from '@kit.CoreFileKit';
  import { backup } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // ...
  
  // This is only an example. The path can be obtained via getHostContext within the component.
  let filesDir = '/data/storage/el2/base/haps/entry/files';
  
  // ...
  
  // Back up application data.
  // Create a SessionBackup instance for data backup.
  let gSession: backup.SessionBackup;
  
  function createSessionBackup(): backup.SessionBackup {
    let generalCallbacks: backup.GeneralCallbacks = {
      // onFileReady is called to return a data complete notification to the application. Avoid time-consuming implementations in onFileReady. You can use asynchronous threads to process data based on the file FD.
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error(`onFileReady err, code is ${err.code}, message is ${err.message}`);
        }
        try {
          let bundlePath = filesDir + '/' + file.bundleName;
          if (!fileIo.accessSync(bundlePath)) {
            fileIo.mkdirSync(bundlePath);
          }
          // Calling copyFileSync causes one more memory copy. To reduce memory consumption, you can use the FD returned by onFileReady for data processing, and close the FD after data is processed.
          fileIo.copyFileSync(file.fd, bundlePath + `/${file.uri}`);
          fileIo.closeSync(file.fd);
          console.info('onFileReady success');
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`onFileReady failed. Code: ${err.code}, message: ${err.message}`);
        }
      },
      onBundleBegin: (err: BusinessError<string | void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleBegin err, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('onBundleBegin bundleName: ' + bundleName);
        }
      },
      onBundleEnd: (err: BusinessError<string | void>, bundleName: string) => {
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
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess bundleName: ' + bundleName);
        console.info('onProcess result: ' + process);
      }
    }
    let sessionBackup = new backup.SessionBackup(generalCallbacks);
    return sessionBackup;
  }
  
  // ...
  export async function sessionBackup(): Promise<void> {
    gSession = createSessionBackup();
    // Select the application to be backed up based on the capability file obtained by backup.getLocalCapabilities().
    // You can also back up data based on the application bundle name.
    const backupApps: string[] = [
      'com.samples.filebackupextension',
    ]
    await gSession.appendBundles(backupApps);
    console.info('appendBundles success');
  }
  ```

## Restoring Application Data

You can select the application data to be restored based on the application information in the capability files.

The Backup and Restore service returns the FD of the application data to be restored in the [onFileReady](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#onfileready) callback registered when the **SessionRestore** instance is created. The file handle is obtained by [getFileHandle](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#getfilehandle). Then, the data to be restored is written to the file handle based on the [uri](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#filemeta) returned. After the data is written, use [publishFile](../reference/apis-core-file-kit/js-apis-file-backup-sys.md#publishfile) to notify the service that the data write is complete.

When all the data of the application is ready, the service starts to restore the application data.

**Example**

  <!-- @[session_restore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/AppFileBackup/entry/src/main/ets/backuprestore/BackupRestore.ets) -->

  ``` TypeScript
  import { fileIo } from '@kit.CoreFileKit';
  import { backup } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // ...
  
  // This is only an example. The path can be obtained via getHostContext within the component.
  let filesDir = '/data/storage/el2/base/haps/entry/files';
  
  // ...
  // Restore the application data.
  // Create a SessionRestore instance for data restoration.
  let gSessionRestore: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 2; // Number of files to back up.
  let testBundleName = 'com.samples.filebackupextension'; // Test bundle name.
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // Count of the files backed up.
  
  async function publishFile(file: backup.File): Promise<void> {
    console.info('start publishFile');
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: ''
    }
    await gSessionRestore.publishFile(fileMeta);
  }
  
  function createSessionRestore(): backup.SessionRestore {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error(`onFileReady err, code is ${err.code}, message is ${err.message}`);
        }
        // Set bundlePath based on the actual situation.
        let bundlePath: string = `${filesDir}/${file.bundleName}/`;
        if (!fileIo.accessSync(bundlePath)) {
          console.error('onFileReady bundlePath err : ' + bundlePath);
        }
        console.info('fd : ' + file.fd);
        let targetPath = `${bundlePath}${file.uri}`;
        fileIo.copyFileSync(targetPath, file.fd);
        fileIo.closeSync(file.fd);
        let currentCount = countMap.get(file.bundleName) || 0; // If no count is found, the default value 0 is returned.
        countMap.set(file.bundleName, ++currentCount);
        // After the data is transferred, notify the server that the files are ready.
        if (countMap.get(file.bundleName) == initMap.get(file.bundleName)) { // Trigger publishFile after all files are received.
          publishFile(file);
        }
        console.info('onFileReady success');
      },
      onBundleBegin: (err: BusinessError<string | void>, bundleName: string) => {
        if (err) {
          console.error(`onBundleBegin failed with err, code is ${err.code}, message is ${err.message}`);
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string | void>, bundleName: string) => {
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
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess bundleName: ' + bundleName);
        console.info('onProcess result: ' + process);
      }
    }
    let sessionRestore = new backup.SessionRestore(generalCallbacks);
    return sessionRestore;
  }
  
  export async function sessionRestore(): Promise<void> {
    gSessionRestore = createSessionRestore();
    const restoreApps: string[] = [
      'com.samples.filebackupextension'
    ];
    // You can obtain the capability file based on actual situation. The following is an example only.
    // You can also construct capability files as required.
    let fileDat = await backup.getLocalCapabilities();
    await gSessionRestore.appendBundles(fileDat.fd, restoreApps);
    console.info('appendBundles success');
    // After the applications to be restored are added, call getFileHandle() to obtain the handles of the application files to be restored based on the application name.
    // The number of application data files to be restored varies depending on the number of backup files. The following is only an example.
    let handle: backup.FileMeta = {
      bundleName: restoreApps[0],
      uri: 'manage.json'
    };
    await gSessionRestore.getFileHandle(handle);
    handle.uri = 'part.0.tar';
    await gSessionRestore.getFileHandle(handle);
    console.info('getFileHandle success');
  }
  ```