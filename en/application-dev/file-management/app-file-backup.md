# Backing Up and Restoring Application-triggered Data (for System Applications Only)

The backup and restoration module provides a complete data backup and restoration solution for application data, user data, and system services on devices. You can implement data backup or restoration for applications by performing the following operations:

- [Obtaining the capability file](#obtaining-the-capability-file): Obtain the capability file of all applications of the system user. The capability file is indispensable for data backup and restoration.

- [Backing up application data](#backing-up-application-data): Select the application data to be backed up based on the application information provided by the capability file, and back up the data.

- [Restoring application data](#restoring-application-data): Select the application data to be restored based on the application information provided in the capability file and restore the data.

- [Installing the application during data restoration](#installing-the-application-during-data-restoration): Install the application if the application has not been installed. As an extended function of application data restoration, this function allows the application to be installed on the device before data restoration.

## How to Develop

For details about the APIs to be used, see [Backup and Restoration](../reference/apis/js-apis-file-backup.md).

Before using the APIs, you need to:

1. Apply for the ohos.permission.BACKUP permission. For details, see [Apply for permissions](../security/accesstoken-guidelines.md).

2. Import **@ohos.file.backup**.
   
   ```js
   import backup from '@ohos.file.backup';
   ```

## Obtaining the Capability File

Obtain the application capability file of the current system user. This file is indispensable for application data backup and restoration.

This file contains the device type and version and basic application information, such as the application name, application data size, application version, whether to allow backup and restoration, and whether to install the application during restoration.

Use **backup.getLocalCapabilities()** to obtain the capability file.

 ```js
  import fs from '@ohos.file.fs';
  async function getLocalCapabilities() {
    try {
      let fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let fpath = await globalThis.context.filesDir + '/localCapabilities.json';
      fs.copyFileSync(fileData.fd, fpath);
      fs.closeSync(fileData.fd);
    } catch (err) {
      console.error('getLocalCapabilities failed with err: ' + err);
    }
  }
 ```

 **Capability file example**
 | Name      | Type| Mandatory| Description                  |
 | -------------- | -------- | ---- | ---------------------- |
 | bundleInfos    | Array    | Yes  | Application information.          |
 | allToBackup    | Boolean  | Yes  | Whether to allow backup and restoration.      |
 | extensionName  | String  | Yes  | Extension name of the application.          |
 | name           | String  | Yes  | Bundle name of the application.            |
 | needToInstall  | Boolean  | Yes  | Whether to install the application during data restoration.|
 | spaceOccupied  | Number    | Yes  | Space occupied by the application data.|
 | versionCode    | Number    | Yes  | Application version number.          |
 | versionName    | String  | Yes  | Application version name.        |
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

You need to select the application data to be backed up based on the application information provided by the capability file.

The Backup & Restore service packages the application data into a file. The file handle is returned by the [onFileReady](../reference/apis/js-apis-file-backup.md#onfileready) callback registered when the instance is created.

You can save the file to a local directory as required.

**Example**

 ```ts
  import fs from '@ohos.file.fs';
  // Create a SessionBackup instance for data backup.
  let g_session;
  function createSessionBackup() {
    let sessionBackup = new backup.SessionBackup({
      onFileReady: async (err, file) => {
        if (err) {
          console.info('onFileReady err: ' + err);
        }
        try {
          let bundlePath = await globalThis.context.filesDir + '/' + file.bundleName;
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
      onBundleBegin: (err, bundleName) => {
        if (err) {
          console.info('onBundleBegin err: ' + err);
        } else {
          console.info('onBundleBegin bundleName: ' + bundleName);
        }
      },
      onBundleEnd: (err, bundleName) => {
        if (err) {
          console.info('onBundleEnd err: ' + err);
        } else {
          console.info('onBundleEnd bundleName: ' + bundleName);
        }
      },
      onAllBundlesEnd: (err) => {
        if (err) {
          console.info('onAllBundlesEnd err: ' + err);
        } else {
          console.info('onAllBundlesEnd');
        }
      },
      onBackupServiceDied: () => {
        console.info('onBackupServiceDied');
      },
    });
    return sessionBackup;
  }
  
  async function sessionBackup ()
  {
    g_session = createSessionBackup();
    // Select the application to be backed up based on the capability file obtained by backup.getLocalCapabilities().
    // You can also back up data based on the application bundle name.
    const backupApps = [
      "com.example.hiworld",
    ]
    await g_session.appendBundles(backupApps);
    console.info('appendBundles success');
  }
 ```

## Restoring Application Data

You can select the application data to be restored based on the application information provided by the capability file.

During the restoration, the Backup and Restore service returns the file handle of the application data to be restored in the [onFileReady](../reference/apis/js-apis-file-backup.md#onfileready) callback registered when the instance is created based on the [getFileHandle](../reference/apis/js-apis-file-backup.md#getfilehandle) called. Then, the data to be restored is written to the file handle based on the [uri](../reference/apis/js-apis-file-backup.md#filemeta) returned. After the data is written, use [publishFile()](../reference/apis/js-apis-file-backup.md#publishfile) to notify the service that the data write is complete.

When all the data of the application is ready, the service starts to restore the application data.

**Example**

 ```ts
  import fs from '@ohos.file.fs';
  // Create a SessionRestore instance for data restoration.
  let g_session;
  async function publishFile(file)
  {
    await g_session.publishFile({
      bundleName: file.bundleName,
      uri: file.uri
    });
  }
  function createSessionRestore() {
    let sessionRestore = new backup.SessionRestore({
      onFileReady: (err, file) => {
        if (err) {
          console.info('onFileReady err: ' + err);
        }
        // Set bundlePath based on the actual situation.
        let bundlePath;
        if (!fs.accessSync(bundlePath)) {
          console.info('onFileReady bundlePath err : ' + bundlePath);
        }
        fs.copyFileSync(bundlePath, file.fd);
        fs.closeSync(file.fd);
        // After the data is transferred, notify the server that the file is ready.
        publishFile(file);
        console.info('onFileReady success');
      },
      onBundleBegin: (err, bundleName) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + err);
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err, bundleName) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + err);
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + err);
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      }
    });
    return sessionRestore;
  }
  
  async function restore ()
  {
    g_session = createSessionRestore();
    const backupApps = [
      "com.example.hiworld",
    ]
    // You can obtain the capability file based on actual situation. The following is an example only.
    // You can also construct a capability file as required.
    let fileData = await backup.getLocalCapabilities();
    await g_session.appendBundles(fileData.fd, backupApps);
    console.info('appendBundles success');
    // After the application to be restored is added, call getFileHandle() to obtain the handle of the application file to be restored based on the application name.
    // The number of application data files to be restored varies depending on the number of backup files. The following is only an example.
    await g_session.getFileHandle({
      bundleName: restoreApps[0],
      uri: "manage.json"
    });
    await g_session.getFileHandle({
      bundleName: restoreApps[0],
      uri: "1.tar"
    });
    console.info('getFileHandle success');
  }
 ```

## Installing the Application During Data Restoration

You can enable the application to be installed before application data restoration. To achieve this purpose, the value of **needToInstall** in **bundleInfos** in the [capability file](#obtaining-the-capability-file) must be **true**.

> **NOTE**
> - [Application data backup](#backing-up-application-data) does not support backup of the application installation package. Therefore, you need to obtain the application installation package.
> - To obtain the file handle of the application installation package, call [getFileHandle()](../reference/apis/js-apis-file-backup.md#getfilehandle) with **FileMeta.uri** set to **/data/storage/el2/restore/bundle.hap**. The file handle of the application installation package is returned through the **onFileReady()** callback registered when the instance is created. The returned **File.uri** is **data/storage/el2/restore/bundle.hap**.

**Example**

 ```ts
  import fs from '@ohos.file.fs';
  // Create a SessionRestore instance for data restoration.
  let g_session;
  async function publishFile(file)
  {
    await g_session.publishFile({
      bundleName: file.bundleName,
      uri: file.uri
    });
  }
  function createSessionRestore() {
    let sessionRestore = new backup.SessionRestore({
      onFileReady: (err, file) => {
      if (err) {
        console.info('onFileReady err: ' + err);
      }
        let bundlePath;
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
        // After the data is transferred, notify the server that the file is ready.
        publishFile(file);
        console.info('onFileReady success');
      },
      onBundleBegin: (err, bundleName) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + err);
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err, bundleName) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + err);
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + err);
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      }
    });
    return sessionRestore;
  }
  
  async function restore ()
  {
    g_session = createSessionRestore();
    const backupApps = [
      "com.example.hiworld",
    ]
    let fpath = await globalThis.context.filesDir + '/localCapabilities.json';
    let file = fs.openSync(fpath, fileIO.OpenMode.CREATE | fileIO.OpenMode.READ_WRITE);
    let content = "{\"bundleInfos\" :[{\"allToBackup\" : false,\"extensionName\" : \"\"," +
    "\"name\" : \"cn.openharmony.inputmethodchoosedialog\",\"needToInstall\" : true,\"spaceOccupied\" : 0," +
    "\"versionCode\" : 1000000,\"versionName\" : \"1.0.0\"}],\"deviceType\" : \"default\",\"systemFullName\"   : \"OpenHarmony-4.0.6.2(Canary1)\"}";
    fs.writeSync(file.fd, content);
    fs.fsyncSync(file.fd);
    await g_session.appendBundles(file.fd, backupApps);
    console.info('appendBundles success');
  
    // Obtain the file handle of the application to be installed.
    await g_session.getFileHandle({
      bundleName: restoreApps[0],
      uri: "/data/storage/el2/restore/bundle.hap"
    });
  
    await g_session.getFileHandle({
      bundleName: restoreApps[0],
      uri: "manage.json"
    });
    await g_session.getFileHandle({
      bundleName: restoreApps[0],
      uri: "1.tar"
    });
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
