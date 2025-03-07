# Copying Files Across Devices

The distributed file system provides the cross-device file copy capability for applications. You can use [@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) to copy files across devices and applications. This topic walks you through the process of copying a file from device A to device B.

## How to Develop

1. Connect the devices to form a Super Device.<br>
   Connect the devices to a LAN, and complete device authentication. The devices must be logged in with the same account.

2. Copy a file across devices. To copy a file of the same application across devices, place the file in the **distributedfiles/** directory of the application sandbox directory.

   Copy the file of device A from the sandbox directory to the **distributedfiles/** directory of device A.

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   let context = getContext(this) as common.UIAbilityContext; // Obtain the UIAbilityContext of device A.
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // Sandbox directory of the file to copy
   let filePath: string = pathDir + '/src.txt';
   
   try {
    // If the file does not exist, create a file and write data to the file created.
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    fs.writeSync(file.fd, 'Create file success');
    fs.closeSync(file);
   } catch (error) {
    console.error(`Failed to createFile. Code: ${error.code}, message: ${error.message}`);
   }

   // Obtain the URI of the file to copy.
   let srcUri = fileUri.getUriFromPath(filePath);
   
   // Copy the file from the sandbox directory to the distributed file directory.
   let destUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');

   try {
    // Copy the file from the sandbox directory to the distributed file directory.
    fs.copy(srcUri, destUri).then(()=>{
      console.info("Succeeded in copying---. ");
      console.info("src: " + srcUri + "dest: " + destUri);
    }).catch((error: BusinessError)=>{
      let err: BusinessError = error as BusinessError;
      console.info(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
    })
   } catch (error) {
    console.error(`Failed to getData. Code: ${error.code}, message: ${error.message}`);
   }
   ```

   Device B copies the file from the distributed file directory of device B.

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   let context = getContext(this) as common.UIAbilityContext; // Obtain the UIAbilityContext of device B.
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // Destination sandbox directory to which the file is to be copied.
   let filePath: string = pathDir + '/dest.txt';

   // Obtain the URI of the destination path.
   let destUri = fileUri.getUriFromPath(filePath);

   // Obtain the file in the distributed file directory.
   let srcUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');

   // Define a callback for the file copy operation.
   let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
     console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
   };
   let options: fs.CopyOptions = {
     "progressListener" : progressListener
   }

   try {
    // Copy the file in the distributed file directory to the destination sandbox directory.
    fs.copy(srcUri, destUri, options).then(()=>{
      console.info("Succeeded in copying of paste. ");
      console.info("src: " + srcUri + "dest: " + destUri); // file://com.example.myapplication/data/storage/el2/distributedfiles/src.txt
    }).catch((error: BusinessError)=>{
      let err: BusinessError = error as BusinessError;
      console.info(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
    })
   } catch (error) {
    console.error(`Failed to copy. Code: ${error.code}, message: ${error.message}`);
   }
   ```
