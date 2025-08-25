# Accessing Files Across Devices
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

The distributed file system provides applications the capability for accessing files across devices. If the same application has been installed on two devices, you can use the [ohos.file.fs APIs](app-file-access.md) to read and write the application files in the [distributed file directory](app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths) (**/data/storage/el2/distributedfiles/**) on the other device. For example, an application is installed on both device A and device B. After device A and device B are connected to form a Super Device, the application on device A can access the files in the distributed directory of the same application on device B.

## How to Develop

1. Connect the devices to form a Super Device.<br>
   Log in to the same account on two devices and ensure that Bluetooth and Wi-Fi are enabled. Bluetooth does not require a physical connection, and Wi-Fi does not need to be connected to the same LAN.

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
       console.info(`request permission result: ${JSON.stringify(result)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Catch err. Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
   }
   ```

3. Implement cross-device access to the files of your application.<br>
   Place the files in the **distributedfiles/** directory of the application sandbox directory to implement access from difference devices.

   For example, create a file in the **distributedfiles/** directory on device A and write data to the file. For details about how to obtain the application context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
 
   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.distributedFilesDir;
   // Obtain the file path of the distributed directory.
   let filePath: string = pathDir + '/test.txt';
   
   try {
     // Create a file in the distributed directory.
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in creating.');
     // Write data to the file.
     fs.writeSync(file.fd, 'content');
     // Close the file.
     fs.closeSync(file.fd);
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   } 
   ```

   Device B initiates a link setup request to device A. After the link is set up, device B can read the test file in the distributed file directory.
   > **NOTE**
   >
   > The network ID (**networkId**) of the device can be obtained by using distributed device management APIs. For details, see [Device Management](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md).

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { buffer } from '@kit.ArkTS';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
 
   // Obtain the network ID of device A by calling distributed device management APIs.
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
     console.info(`Success to get available device list`);
     let networkId = deviceInfoList[0].networkId;
     // Define the callback for accessing the user directory.
     let listeners : fs.DfsListeners = {
       onStatus: (networkId: string, status: number): void => {
         console.info('Failed to access public directory');
       }
     };
     // Start to access files cross devices.
     fs.connectDfs(networkId, listeners).then(() => {
       console.info("Success to connect dfs");
       // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
       let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
       let pathDir: string = context.distributedFilesDir;
       // Obtain the file path of the distributed directory.
       let filePath: string = pathDir + '/test.txt';
       try {
         // Open the file in the distributed directory.
         let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
         // Set the buffer for receiving the read data.
         let arrayBuffer = new ArrayBuffer(4096);
         // Read the file. The return value is the number of read bytes.
         class Option {
             public offset: number = 0;
             public length: number = 0;
         };
         let option = new Option();
         option.length = arrayBuffer.byteLength;
         let num = fs.readSync(file.fd, arrayBuffer, option);
         // Print the read data.
         let buf = buffer.from(arrayBuffer, 0, num);
         console.info('read result: ' + buf.toString());
         fs.closeSync(file);
       } catch (error) {
         let err: BusinessError = error as BusinessError;
         console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
       }
     }).catch((error: BusinessError) => {
       let err: BusinessError = error as BusinessError;
       console.error(`Failed to connect dfs. Code: ${err.code}, message: ${err.message}`);
     });
   }
   ```

3. Disconnect the link for device B.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   // Obtain the network ID of device A.
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
     console.info(`Success to get available device list`);
     let networkId = deviceInfoList[0].networkId;
    // Disable cross-device file access.
     fs.disconnectDfs(networkId).then(() => {
       console.info("Success to disconnect dfs");
     }).catch((err: BusinessError) => {
       console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
     })
   }
   ```
