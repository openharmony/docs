# Developing a File Manager Application (for System Applications Only)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

OpenHarmony is prebuilt with the **FileManager** application. You can also develop your own file manager application as required.

## How to Develop
For details about the APIs for developing the user file manager, see [User File Access and Management](../reference/apis-core-file-kit/js-apis-fileAccess-sys.md).

1. Request permissions required.
   Request the ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permissions. For details, see [Requesting Permissions for System_basic Applications](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

   > **NOTE**
   >
   > The ohos.permission.FILE_ACCESS_MANAGER permission allows your application to call the user file access framework APIs.
   >
   > The ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission allows your application to obtain information about file management server applications supported by the system.

2. Import dependent modules.

   ```ts
   import { fileAccess } from '@kit.CoreFileKit';
   import { fileExtensionInfo } from '@kit.CoreFileKit';
   ```

   The **fileAccess** module provides APIs for basic file operations, and the **fileExtensionInfo** module provides key structs for application development.

3. Query device information.
   You can obtain attributes of the devices managed by one or all file management servers in the system. You can also filter devices as required.

   In the user file access framework, **RootInfo** indicates the attribute information of a device. For example, obtain **RootInfo** of all devices.

   ```ts
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Filter } from '@kit.CoreFileKit';

   // The context is passed from EntryAbility. Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 

   // Create a helper object for connecting to all file management servers in the system.
   let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
   function createFileAccessHelper(context: common.UIAbilityContext): void {
     try {
       fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);
       if (!fileAccessHelperAllServer) {
         console.error("createFileAccessHelper interface returns an undefined object");
       }
     } catch (err) {
         let error: BusinessError = err as BusinessError;
         console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   let rootInfos: Array<fileAccess.RootInfo> = [];
   async function getRoots(): Promise<void>{
     let rootIterator: fileAccess.RootIterator;
     let isDone: boolean = false;
     try {
       rootIterator = await fileAccessHelperAllServer.getRoots();
       if (!rootIterator) {
         console.error("getRoots interface returns an undefined object");
         return;
       }
       while (!isDone) {
         let result = rootIterator.next();
         console.info("next result = " + JSON.stringify(result));
         isDone = result.done;
         if (!isDone)
           rootInfos.push(result.value);
       }
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   ```

4. View directories.
   In the user file access framework, **FileInfo** indicates basic information about a file or folder. You can use **listfile()** to obtain a **FileIterator** object that traverses all files (folder) of the next level or use **scanfile()** to obtain a **FileIterator** object that meets the specified conditions.

    Currently, **listfile()** and **scanfile()** can be called by the **RootInfo** object to traverse the next-level files or filter the entire directory tree. In addition, **listfile()** and **scanfile()** can be called by the **FileInfo** object to traverse the next-level files or filter the specified directories.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Filter } from '@kit.CoreFileKit';

   // Start from the root directory.
   let rootInfos = [];
   // Obtain rootInfos by using getRoots().
   let rootInfo: fileAccess.RootInfo = rootInfos[0];
   let fileInfos: Array<fileAccess.FileInfo> = [];
   let isDone: boolean = false;
   let filter: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // Set the filter.
   try {  
     let fileIterator = rootInfo.listFile();          // Traverse the root directory of rootinfos[0] and return an iterator object.
     // let fileIterator = rootInfo.scanFile(filter); // Filter device rootinfos[0] files that meet the specified conditions and return a FileIterator object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone) {
       let result = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone = result.done;
       if (!isDone)
         fileInfos.push(result.value);
     }
   } catch (err) {
    let error: BusinessError = err as BusinessError;
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   
   // Start from the specified directory.
   let fileInfoDir: fileAccess.FileInfo = fileInfos[0]; // fileInfoDir indicates the information about a directory.
   let subFileInfos: Array<fileAccess.FileInfo> = [];
   let isDone02: boolean = false;
   let filter02: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // Set the filter.
   try {
     let fileIterator = fileInfoDir.listFile(); // Traverse files in the specified directory and return an iterator object.
     // let fileIterator = rootInfo.scanFile(filter02); // Filter the files in the specified directory and return a FileIterator object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone02) {
       let result = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone02 = result.done;
       if (!isDone02)
         subFileInfos.push(result.value);
     }
   } catch (err) {
    let error: BusinessError = err as BusinessError;
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   ```

5. Perform operations on files or directories.
   You can integrate APIs of the user file access framework to implement user behaviors, such as deleting, renaming, creating, and moving a file or folder. The following example shows how to create a file. For details about other APIs, see [User File Access and Management](../reference/apis-core-file-kit/js-apis-fileAccess-sys.md).

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   // The local device is used as an example.
   // Create a file.
   // sourceUri is the URI in fileinfo of the Download directory.
   // You need to use the obtained URI for development.
   async function createFile(): Promise<void> {
     let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
     let displayName: string = "file1";
     let fileUri: string = '';
     try {
       // Obtain fileAccessHelperAllServer by referring to the sample code of fileAccess.createFileAccessHelper.
       fileUri = await fileAccessHelperAllServer.createFile(sourceUri, displayName);
       if (!fileUri) {
         console.error("createFile return undefined object");
       }
       console.info("createFile sucess, fileUri: " + JSON.stringify(fileUri));
     } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
     };
   }
   ```

## Listening for Device Online/Offline Status

For details about the APIs, see [User File Access and Management](../reference/apis-core-file-kit/js-apis-fileAccess-sys.md).

You can use **notify()** to observe not only the changes of directories, but also the device online/offline status.


1. Request permissions required.

   Request the ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permissions. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

   > **NOTE**
   >
   > The ohos.permission.FILE_ACCESS_MANAGER permission allows your application to call the user file access framework APIs.
   >
   > The ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission allows your application to obtain information about file management server applications supported by the system.

2. Import dependent modules.

   ```ts
   import { fileAccess } from '@kit.CoreFileKit';
   import { fileExtensionInfo } from '@kit.CoreFileKit';
   ```

 The **fileAccess** module provides APIs for basic file operations, and the **fileExtensionInfo** module provides key structs for application development.

3. Define the observer callback.

   ```ts
   const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
     if (NotifyMessageDir != undefined) {
       console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
     } else {
      console.error("NotifyMessageDir is undefined");
     }
   }
   ```

4. Observe devices.

  To listen for the device online/offline status, pass in [DEVICES_URI](../reference/apis-core-file-kit/js-apis-fileAccess-sys.md#constant) to **registerObserver**. To cancel the listening for the device online/offline status, pass in **DEVICES_URI** to **unregisterObserver()**.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';

   // Define the observer callback.
   const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
     if (NotifyMessageDir != undefined) {
       console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
     } else {
      console.error("NotifyMessageDir is undefined");
     }
   }

   // The context is passed from EntryAbility. Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   // Create a helper object for connecting to all file management servers in the system.
   let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
   function createFileAccessHelper(context: common.UIAbilityContext): void {
     try {
       fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);
       if (!fileAccessHelperAllServer) {
         console.error("createFileAccessHelper interface returns an undefined object");
       }
     } catch (err) {
         let error: BusinessError = err as BusinessError;
         console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   // Pass in DEVICES_URI to registerObserver() to listen for the device online/offline status.
   async function RegisterObserver03() {
     try {
       // Subscribe to the device online/offline status.
       fileAccessHelperAllServer.registerObserver(fileAccess.DEVICES_URI, true, callbackDir1);
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   // Pass in DEVICES_URI to unregisterObserver () to cancel the device status listening.
   async function UnregisterObserver04() {
     try {
       // Unsubscribe from the device online/offline status.
       fileAccessHelperAllServer.unregisterObserver(fileAccess.DEVICES_URI, callbackDir1);
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   ```
