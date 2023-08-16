# Developing a File Manager Application (for System Applications Only)

OpenHarmony is prebuilt with the **FileManager** application. You can also develop your own file manager application as required.

## Available APIs

For details about the APIs used to develop a file manager application, see [User File Access and Management](../reference/apis/js-apis-fileAccess.md).

## How to Develop

1. Apply for permissions required.<br>
   Apply for the **ohos.permission.FILE_ACCESS_MANAGER** and **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permissions. For details, see [Applying for Permissions](../security/accesstoken-guidelines.md).

   > **NOTE**
   >
   > **ohos.permission.FILE_ACCESS_MANAGER** allows your application to use the user file access framework APIs.
   >
   > **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** allows your application to obtain information about file management server applications supported by the system.

2. Import dependent modules.

   ```ts
   import fileAccess from '@ohos.file.fileAccess';
   import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
   ```

   The **fileAccess** module provides APIs for basic file operations, and the **fileExtensionInfo** module provides key structs for application development.

3. Query device information.<br>
   You can obtain attributes of the devices managed by one or all file management servers in the system. You can also filter devices as required.

   In the user file access framework, **RootInfo** indicates the attribute information of a device. For example, obtain **RootInfo** of all devices.

   ```ts
   // Create a helper object for connecting to all file management servers in the system.
   let fileAccessHelperAllServer = null;
   createFileAccessHelper() {
     try {    // this.context is the context passed from EntryAbility.
       fileAccessHelperAllServer = fileAccess.createFileAccessHelper(this.context);
       if (!fileAccessHelperAllServer) {
         console.error("createFileAccessHelper interface returns an undefined object");
       }
     } catch (error) {    
         console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   async getRoots() {  
     let rootIterator = null;  
     let rootInfos = [];  
     let isDone = false;  
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
           rootinfos.push(result.value);
       }  
     } catch (error) {
       console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   ```

4. View directories.
   In the user file access framework, **FileInfo** indicates basic information about a file (directory). You can use **listfile()** to obtain a **FileIterator** object that traverses all files (directories) of the next level or use **scanfile()** to obtain a **FileIterator** object that meets the specified conditions.

   Currently, **listfile()** and **scanfile()** can be called by the **RootInfo** object to traverse the next-level files or filter the entire directory tree. In addition, **listfile()** and **scanfile()** can be called by the **FileInfo** object to traverse the next-level files or filter the specified directories.

   ```ts
   // Start from the root directory.
   let rootInfo = rootinfos[0];
   let fileInfos = [];
   let isDone = false;
   let filter = {suffix: [".txt", ".jpg", ".xlsx"]};  // Set filter criteria.
   try {  
     let fileIterator = rootInfo.listFile();          // Traverse the root directory of rootinfos[0] and return an iterator object.
     // let fileIterator = rootInfo.scanFile(filter); // Filter device rootinfos[0] files that meet the specified conditions and return an iteration object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
       return;  
     }
     while (!isDone) {
       let result = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone = result.done;
       if (!isDone)
         fileInfos.push(result.value);
     }
   } catch (error) {
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   
   // Start from the specified directory.
   let fileInfoDir = fileInfos[0];                    // fileInfoDir indicates information about a directory.
   let subFileInfos = [];
   let isDone = false;
   let filter = {suffix: [".txt", ".jpg", ".xlsx"]};  // Set filter criteria.
   try {
     let fileIterator = fileInfoDir.listFile();       // Traverse files in the specified directory and return an iterator object.
     // let fileIterator = rootInfo.scanFile(filter); // Filter the files in the specified directory and return an iterator object.
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
       return;
     }
     while (!isDone) {
       let result = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone = result.done;
       if (!isDone)
         subfileInfos.push(result.value);
     }
   } catch (error) {
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   ```

5. Perform operations on files or directories.
   You can integrate APIs of the user file access framework to implement user behaviors, such as deleting, renaming, creating, and moving a file (directory). The following example shows how to create a file. For details about other APIs, see [User File Access and Management](../reference/apis/js-apis-fileAccess.md).

   ```ts
   // The local device is used as an example.
   // Create a file.
   // sourceUri is the URI in fileinfo of the Download directory.
   // You need to use the obtained URI for development.
   let sourceUri = "datashare:///media/file/6";
   let displayName = "file1";
   let fileUri = null;
   try {
     // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
     fileUri = await fileAccessHelper.createFile(sourceUri, displayName);
     if (!fileUri) {
       console.error("createFile return undefined object");
       return;
     }
     console.info("createFile sucess, fileUri: " + JSON.stringify(fileUri));
   } catch (error) {
     console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   };
   ```
