# Developing a File Manager Application (for System Applications Only)

OpenHarmony is prebuilt with the **FileManager** application. You can also develop your own file manager application as required.

## Available APIs

For details about the APIs used to develop a file manager application, see [User File Access and Management](../reference/apis/js-apis-fileAccess.md).

## How to Develop

1. Apply for permissions required.
   
   Apply for the **ohos.permission.FILE_ACCESS_MANAGER** and **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permissions. For details, see [Applying for Permissions](../security/accesstoken-guidelines.md).

   > **NOTE**
   >
   > - **ohos.permission.FILE_ACCESS_MANAGER** allows your application to use the user file access framework APIs.
   >- **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** allows your application to obtain information about file management server applications supported by the system.

2. Import dependent modules.

   ```ts
   import fileAccess from '@ohos.file.fileAccess';
   import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
   ```

   The **fileAccess** module provides APIs for basic file operations, and the **fileExtensionInfo** module provides key structs for application development.

3. Query device information.

   You can obtain attributes of the devices managed by one or all file management servers in the system. You can also filter devices as required.

   In the user file access framework, **RootInfo** indicates the attribute information of a device. For example, obtain **RootInfo** of all devices.

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   import { Filter } from '@ohos.file.fs';
   
   // Obtain the application context.
   let context = getContext(this) as common.UIAbilityContext;
   
   // Create a helper object for connecting to all file management servers in the system.
   let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
   function createFileAccessHelper(): void {
     try {    // this.context is the context passed from EntryAbility.
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

   In the user file access framework, **FileInfo** indicates basic information about a file (directory). You can use **listfile()** to obtain a **FileIterator** object that traverses all files (directories) of the next level or use **scanfile()** to obtain a **FileIterator** object that meets the specified conditions.

   Currently, **listfile()** and **scanfile()** can be called by the **RootInfo** object to traverse the next-level files or filter the entire directory tree. In addition, **listfile()** and **scanfile()** can be called by the **FileInfo** object to traverse the next-level files or filter the specified directories.

   ```ts
   import { BusinessError } from '@ohos.base';
   import { Filter } from '@ohos.file.fs';
   
   // Start from the root directory.
   let rootInfo: Array<fileAccess.RootInfo> = rootInfos[0];
   let fileInfos: Array<fileAccess.FileInfo> = [];
   let isDone: boolean = false;
   let filter: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // Set the filter.
   try {  
     let fileIterator: string = rootInfo.listFile();          // Traverse the root directory of rootinfos[0] and return a FileIterator object.
     // let fileIterator = rootInfo.scanFile(filter);         // Filter device rootinfos[0] files that meet the specified conditions and return a FileIterator object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone) {
       let result: boolean = fileIterator.next();
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
   let fileInfoDir: Array<fileAccess.FileInfo> = fileInfos[0];  // fileInfoDir indicates the information about a directory.
   let subFileInfos: Array<fileAccess.FileInfo> = [];
   let isDone02: boolean = false;
   let filter02: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // Set the filter.
   try {
     let fileIterator: string = fileInfoDir.listFile();         // Traverse files in the specified directory and return a FileIterator object.
     // let fileIterator = rootInfo.scanFile(filter02);         // Filter the files in the specified directory and return a FileIterator object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone02) {
       let result: boolean = fileIterator.next();
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

   You can integrate APIs of the user file access framework to implement user behaviors, such as deleting, renaming, creating, and moving a file (directory). The following example shows how to create a file. For details about other APIs, see [User File Access and Management](../reference/apis/js-apis-fileAccess.md).

   ```ts
   import { BusinessError } from '@ohos.base';
   
   // The local device is used as an example.
   // Create a file.
   // sourceUri is the URI in fileinfo of the Download directory.
   // You need to use the obtained URI for development.
   async function creatFile(): Promise<void> {
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
