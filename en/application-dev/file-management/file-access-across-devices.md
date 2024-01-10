# Accessing Files Across Devices

The distributed file system provides cross-device file access capabilities for applications. For an application installed on multiple devices that form a Super Device, you can use [ohos.file.fs](app-file-access.md) APIs to read or write files in the application's distributed directory (**/data/storage/el2/distributedfiles/**) across devices. 

For example, an application is installed on both device A and device B. After device A and device B are connected to form a Super Device, the application on device A can access the files in the distributed directory of the same application on device B.

## How to Develop

1. Connect the devices to form a Super Device.
   
   Connect the devices to a LAN, and complete device authentication. The devices must be logged in with the same account number.
   
2. Implement cross-device access to the files of your application.

   Place the files in the **distributedfiles/** directory of the application sandbox directory to implement access from difference devices.

   For example, create a file in the **distributedfiles/** directory on device A and write data to the file. For details about how to obtain the application context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import fs from '@ohos.file.fs';
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   
   let context = getContext(this) as common.UIAbilityContext; // Obtain the UIAbilityContext of device A.
   let pathDir: string = context.distributedFilesDir;
   // Obtain the file path of the distributed directory.
   let filePath: string = pathDir + '/test.txt';
   
   try {
     // Create a file in the distributed directory.
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in createing.');
     // Write data to the file.
     fs.writeSync(file.fd, 'content');
     // Close the file.
     fs.closeSync(file.fd);
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```

   Read the file on device B.

   ```ts
   import fs from '@ohos.file.fs';
   import common from '@ohos.app.ability.common';
   import buffer from '@ohos.buffer';
   import { BusinessError } from '@ohos.base';
   
   let context = getContext(this) as common.UIAbilityContext; // Obtain the UIAbilityContext of device B.
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
     }
     let option = new Option();
     option.length = arrayBuffer.byteLength;
     let num = fs.readSync(file.fd, arrayBuffer, option);
     // Print the read data.
     let buf = buffer.from(arrayBuffer, 0, num);
     console.info('read result: ' + buf.toString());
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```