# Access Files Across Devices

The distributed file system provides cross-device file access capabilities for applications. For the same application installed on multiple devices that form a Super Device, you can use [ohos.file.fs](app-file-access.md) APIs to implement read and write of the files in the application's distributed directory (**/data/storage/el2/distributedfiles/**). 

For example, device A and device B are installed with the same application. After device A and device B are connected to form a Super Device, the application on device A can access the files in the distributed directory of the same application on Device B.

## How to Develop

1. Connect the devices to form a Super Device.
   
Connect the devices to a LAN, and complete authentication of the devices. The devices must have the same account number.
   
2. Implement cross-device access to the files of the same application.

   Place the files in the **distributedfiles/** directory of the application sandbox to implement access from difference devices.

   For example, create a file in the **distributedfiles/** directory on device A and write data to the file. For details about how to obtain the application context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import fs from '@ohos.file.fs';
   
   let context =...; // Obtain the UIAbilityContext information of device A.
   let pathDir = context.distributedFilesDir;
   // Obtain the file path of the distributed directory.
   let filePath = pathDir + '/test.txt';
   
   try {
     // Create a file in the distributed directory.
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in createing.');
     // Write data to the file.
     fs.writeSync(file.fd, 'content');
     // Close the file.
     fs.closeSync(file.fd);
   } catch (err) {
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```

   Read the file on device B.

   ```ts
   import fs from '@ohos.file.fs';
   
   let context =...; // Obtain the UIAbilityContext information of device B.
   let pathDir = context.distributedFilesDir;
   // Obtain the file path of the distributed directory.
   let filePath = pathDir + '/test.txt';
   
   try {
     // Open the file in the distributed directory.
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
     // Set the buffer for receiving the read data.
     let buffer = new ArrayBuffer(4096);
     // Read the file. The return value is the number of read bytes.
     let num = fs.readSync(file.fd, buffer, {
       offset: 0
     });
     // Print the read data.
     console.info('read result: ' + String.fromCharCode.apply(null, new Uint8Array(buffer.slice(0, num))));
   } catch (err) {
     console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```
