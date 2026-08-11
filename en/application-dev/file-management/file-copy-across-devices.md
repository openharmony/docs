# Copying Files Across Devices

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=78d33fd06d475876659e551e83466b50b3f5df38 translatedAt=2026-08-01T07:26:13.603Z pushedAt=2026-08-01T09:17:26.673Z -->

The distributed file system provides apps with cross-device file copy capabilities. You can use [@ohos.file.fs (File Management)](../reference/apis-core-file-kit/js-apis-file-fs.md) to copy files across devices. For example, in a multi-device data transfer scenario, after devices are networked and interconnected, the app on device A can copy sandbox files to the distributed directory of device A. When pasting on device B, the files are copied from the distributed directory of device B to the corresponding sandbox files.

## How to Develop

1. Connect the devices to form a Super Device.

   Log in to the same account on two devices and ensure that Bluetooth and Wi-Fi are enabled. Bluetooth does not need to be connected, and Wi-Fi does not need to be connected to the same LAN.

2. Grant the distributed data synchronization permission.

   Use **requestPermissionsFromUser** to request user authorization for the ohos.permission.DISTRIBUTED_DATASYNC permission in the form of a dialog box. For details about how to obtain the application context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import { common, abilityAccessCtrl } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

   <!--@[distributed_Data_Permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/DistributedFileSample/entry/src/main/ets/pages/Index.ets)-->      

   ``` TypeScript
   let atManager = abilityAccessCtrl.createAtManager();
   try {
     // Request authorization from the user through a dynamic dialog box.
     atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC']).then((result) => {
       console.info(`request permission result: ${JSON.stringify(result)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Catch err. Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
   }
   ```

3. Copy files across devices.

   Place the files in the **distributedfiles/** directory of the application sandbox directory to implement file copy across difference devices.

   Copy the file of device A from the sandbox directory to the **distributedfiles/** directory of device A.

   ```ts
   import { fileIo } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';
   ```

   <!--@[copy_sand_to_distributed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/DistributedFileSample/entry/src/main/ets/pages/Index.ets)-->     

   ``` TypeScript
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // Sandbox directory of the file to copy.
   let filePath: string = pathDir + '/src.txt';
   try {
     // Sandbox file to copy.
     let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
     fileIo.writeSync(file.fd, 'Create file success');
     fileIo.closeSync(file);
   } catch (error) {
     console.error(`Failed to createFile. Code: ${error.code}, message: ${error.message}`);
   }

   // Obtain the URI of the file to copy.
   let srcUri = fileUri.getUriFromPath(filePath);
   // Obtain the URI of the destination path (distributed file directory).
   let destUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');
   try {
     // Copy the file from the sandbox directory to the distributed file directory.
     fileIo.copy(srcUri, destUri).then(()=>{
       console.info(`Succeeded in copying---. `);
       console.info(`src: ${srcUri} dest: ${destUri}`);
     }).catch((error: BusinessError)=>{
       let err: BusinessError = error as BusinessError;
       console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     console.error(`Catch err. Failed to copy. Code: ${error.code}, message: ${error.message}`);
   }
   ```

   Device B copies the file from the distributed file directory of device B.

   ```ts
   import { fileIo } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   ```

   <!--@[copy_distributed_to_sand](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/DistributedFileSample/entry/src/main/ets/pages/Index.ets)-->        

   ``` TypeScript
   // ...
   try {
     let pathDir: string = context.filesDir;
     let distributedPathDir: string = context.distributedFilesDir;
     // Target path of the file to be copied (sandbox path).
     let destPath: string = pathDir + '/dest.txt';
     // Obtain the target path URI.
     let destUri = fileUri.getUriFromPath(destPath);
 
     // Source file path for copying (distributed directory).
     let srcPath = distributedPathDir + '/src.txt';
     // Obtain the source path URI.
     let srcUri: string = fileUri.getUriFromPath(srcPath);
   
     // Define the copy callback.
     let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
       console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
     };
     let options: fileIo.CopyOptions = {
       'progressListener' : progressListener
     };
     // Obtain the networkId of device A through the distributed device management API.
     let dmInstance = distributedDeviceManager.createDeviceManager('com.example.hap');
     let deviceInfoList: distributedDeviceManager.DeviceBasicInfo[] = dmInstance.getAvailableDeviceListSync();
     if (deviceInfoList && deviceInfoList.length > 0) {
       console.info(`success to get available device list`);
       let networkId = deviceInfoList[0].networkId; // Only two devices are connected here, so the first item in the list is the networkId of device A.
       // Define the callback for accessing the Distributed Directory.
       let listeners : fileIo.DfsListeners = {
         onStatus: (networkId: string, status: number): void => {
           console.error(`Failed to access public directory, ${status}`);
         }
       };
       // Start cross-device file copy.
       fileIo.connectDfs(networkId, listeners).then(()=>{
         try {
           // Copy the file from the Distributed Directory to another sandbox path.
           fileIo.copy(srcUri, destUri, options).then(()=>{
             console.info(`Succeeded in copying from distributed path`);
             console.info(`src: ${srcUri} dest: ${destUri}`);
             fileIo.unlinkSync(srcPath); // Clean up the temporary file in the Distributed Directory after the copy is complete.
           }).catch((error: BusinessError)=>{
             let err: BusinessError = error as BusinessError;
             console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
           })
         } catch (error) {
           console.error(`Catch err. Failed to copy. Code: ${error.code}, message: ${error.message}`);
         }
       }).catch((error: BusinessError) => {
         let err: BusinessError = error as BusinessError;
         console.error(`Failed to connect dfs. Code: ${err.code}, message: ${err.message}`);
       });
     }
   } catch (error) {
     console.error(`Catch err. Code: ${error.code}, message: ${error.message}`);
   }
   ```

4. Disconnect the link for device B.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'
   import { fileIo } from '@kit.CoreFileKit';
   ```

   <!--@[access_DisConnectDfs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/DistributedFileSample/entry/src/main/ets/pages/Index.ets)-->        

   ``` TypeScript
   // Obtain the network ID of device A.
   // ...
   try {
     let dmInstance = distributedDeviceManager.createDeviceManager('com.example.hap');
     let deviceInfoList: distributedDeviceManager.DeviceBasicInfo[] = dmInstance.getAvailableDeviceListSync();
     if (deviceInfoList && deviceInfoList.length > 0) {
       console.info(`Success to get available device list`);
       let networkId = deviceInfoList[0].networkId;
       // Close cross-device file access.
       fileIo.disconnectDfs(networkId).then(() => {
         console.info(`Success to disconnect dfs`);
       }).catch((err: BusinessError) => {
         console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
       })
     }
   } catch (error) {
     console.error(`Catch err. Code: ${error.code}, message: ${error.message}`);
   }
   ```