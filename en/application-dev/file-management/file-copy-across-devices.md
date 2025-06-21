# Copying Files Across Devices

The distributed file system provides the cross-device file copy capability for applications. You can use [@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) to copy files across devices and applications. This topic walks you through the process of copying a file from device A to device B.  

## How to Develop

1. Connect the devices to form a Super Device.<br>
   Log in to the same account on two devices and ensure that Bluetooth and Wi-Fi are enabled. Bluetooth does not need to be connected, and Wi-Fi does not need to be connected to the same LAN.

2. Grant the distributed data synchronization permission.
   Use **requestPermissionsFromUser** to request user authorization for the ohos.permission.DISTRIBUTED_DATASYNC permission in the form of a dialog box. For details about how to obtain the application context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import { common, abilityAccessCtrl } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let atManager = abilityAccessCtrl.createAtManager();
   try {
     // Request the permission from users in the form of a dialog box.
     atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC']).then((result) => {
       console.info(`Request permission result: ${JSON.stringify(result)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Catch err. Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
   }
   ```

3. Copy files across devices.
   Place the files in the **distributedfiles/** directory of the application sandbox directory to implement file copy from difference devices.

   Copy the file of device A from the sandbox directory to the **distributedfiles/** directory of device A.

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // Sandbox directory of the file to copy.
   let filePath: string = pathDir + '/src.txt';
   try {
    // Sandbox file to copy.
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    fs.writeSync(file.fd, 'Create file success');
    fs.closeSync(file);
   } catch (error) {
    console.error(`Failed to createFile. Code: ${error.code}, message: ${error.message}`);
   }

   // Obtain the URI of the file to copy.
   let srcUri = fileUri.getUriFromPath(filePath);
   // Obtain the URI of the destination path (distributed file directory).
   let destUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');
   try {
     // Copy the file from the sandbox directory to the distributed file directory.
     fs.copy(srcUri, destUri).then(()=>{
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
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';

   // The context is passed from EntryAbility. Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // Destination path (sandbox directory) to which the file is to be copied.
   let destPath: string = pathDir + '/dest.txt';
   // Obtain the URI of the destination path.
   let destUri = fileUri.getUriFromPath(destPath);

   // Copy the source file path (distributed file directory).
   let srcPath = distributedPathDir + '/src.txt';
   // Obtain the URI of the source path.
   let srcUri: string = fileUri.getUriFromPath(srcPath);

   // Define a callback for the file copy operation.
   let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
     console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
   };
   let options: fs.CopyOptions = {
     "progressListener" : progressListener
   };
   // Obtain the network ID of device A by calling distributed device management APIs.
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`success to get available device list`);
    let networkId = deviceInfoList[0].networkId; // Only two devices are connected. The first element in the list is the network ID of device A.
    // Define the callback for accessing the distributed file directory.
    let listeners : fs.DfsListeners = {
      onStatus: (networkId: string, status: number): void => {
        console.error(`Failed to access public directory, ${status}`);
      }
    };
    // Start to copy files cross devices.
    fs.connectDfs(networkId, listeners).then(()=>{
      try {
        // Copy the file in the distributed file directory to the destination sandbox directory.
        fs.copy(srcUri, destUri, options).then(()=>{
          console.info(`Succeeded in copying from distribted path`);
          console.info(`src: ${srcUri} dest: ${destUri}`);
          fs.unlinkSync(srcPath); // Remove the temporary file in the distributed file directory after the copy is complete.
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
   ```

4. Disconnect the link for device B.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'
   import { fileIo as fs } from '@kit.CoreFileKit';

   // Obtain the network ID of device A.
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Success to get available device list`);
    let networkId = deviceInfoList[0].networkId; // Only two devices are connected. The first element in the list is the network ID of device A.
    // Disable cross-device file copy.
    fs.disconnectDfs(networkId).then(() => {
      console.info(`Success to disconnect dfs`);
    }).catch((error: BusinessError) => {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
    })
   }
   ```
