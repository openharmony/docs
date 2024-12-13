# Saving User Files

When a user needs to download a file from the Internet or save a file to another directory, use **FilePicker** to save the file. The permission on the file URI granted by Picker, however, is temporary. If required, you can persist the permission on the URI. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).

The operations for saving images, audio or video clips, and documents are similar. Call **save()** of the corresponding Picker instance and pass in **saveOptions**. No permission is required if your application uses **FilePicker** to access files.

Currently, all the **save()** behaviors of **FilePicker** can be perceived by users. Specifically, **FilePicker** is started to save the files to a directory managed by **FileManager**. The files are isolated from the assets managed by **Gallery** and cannot be viewed in **Gallery**.

To enable the saved image or video to be viewed in **Gallery**, [create the media asset using a security component](../media/medialibrary/photoAccessHelper-savebutton.md).


## Saving Images or Videos

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpicker) will not be maintained in later versions. You are advised to [use a security component to create a media asset](../media/medialibrary/photoAccessHelper-savebutton.md).

If the security component cannot be called to save images and videos in your development, use [PhotoAccessHelper.showAssetsCreationDialog](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#showassetscreationdialog12) to save images and videos.

## Saving Documents

1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Create a **documentSaveOptions** instance.

   ```ts
   // Create a documentSaveOptions instance.
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // (Optional) Name of the document to save.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"];
   // (Optional) Type of the document to save. The value is in ['Description|File name extensions'] format. To save all documents, use 'All files (*.*)|.*'. If there are multiple file name extensions, the first one is used by default.
   documentSaveOptions.fileSuffixChoices = ['Document|.txt', '.pdf'];
   ```

3. Create a [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#constructor12) instance, and call [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save) to start the FilePicker page to save the document.

   ```ts
   let uris: Array<string> = [];
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context;
   // Create a DocumentViewPicker instance.
   const documentViewPicker = new picker.DocumentViewPicker(context);
   // After the user selects the target folder and saves the documents, the URIs of the saved documents are returned.
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

> **NOTE**
>
> - Avoid directly using a URI in the Picker callback to open the document. Instead, define a global variable to save the URI.
> - The permission for the URIs returned by [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save) of Picker is a temporary read/write permission. The temporary permission will be invalidated once the application exits.
> - You can persist the temporary permission for a URI, which is available only for 2-in-1 devices. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).
> - You can also directly save the documents to the **Download** folder. For details, see [Saving Files to the Download Directory](#saving-files-to-the-download-directory).

4. After the application UI is returned from FilePicker, call [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open a document based on the URI. The file descriptor (FD) is returned after the document is opened.

   ```ts 
   const uri = '';
   // Note that the permission specified by the mode parameter of fs.openSync() is fs.OpenMode.READ_WRITE.
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Call [fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync) to modify the document based on the FD, and call **fs.closeSync()** to close the FD.

   ```ts
   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## Saving Audio Clips

1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Create an **audioSaveOptions** instance.

   ```ts
   // Create an audioSaveOptions instance.
   const audioSaveOptions = new picker.AudioSaveOptions();
   // Set the name of the audio clip to save. This parameter is optional.
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; 
   ```

3. Create an [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker) instance and use [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-5) to start the FilePicker page to save the audio clip.
   ```ts
   let uri: string = '';
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context; 
   const audioViewPicker = new picker.AudioViewPicker(context);
   // After the user selects the target folder and saves the audio clips, the URIs of the saved audio clips are returned.
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
> **NOTE**
>
> - Avoid directly using a URI in the Picker callback to open the audio clip. Instead, define a global variable to save the URI.
> - The permission for the URIs returned by [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-3) of Picker is a temporary read/write permission. The temporary permission will be invalidated once the application exits.
> - You can persist the temporary permission for a URI, which is available only for 2-in-1 devices. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).
> - You can also directly save audio clips to the **Download** folder. For details, see [Saving Files to the Download Directory](#saving-files-to-the-download-directory).

4. After the application UI is returned from FilePicker, call [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open an audio clip based on the URI. The FD is returned after the audio clip is opened.

   ```ts
   // Note that the permission specified by the mode parameter of fs.openSync() is fileIo.OpenMode.READ_WRITE.
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Call [fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync) to modify the audio clip based on the FD, and use **fs.closeSync()** to close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
 
   ```
## Saving Files to the Download Directory

When using **save()**, you can set **pickerMode** to **DOWNLOAD**, which will trigger user authorization. After the user allows the operation, a folder with the current HAP bundle name will be created in the **Download** directory of the user, and the folder URI will be returned by **save()**. As a result, user files can be directly stored in the folder with this URI.
1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Create a **documentSaveOptions** instance.

   ```ts
   // Create a documentSaveOptions instance.
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // Set pickerMode to DOWNLOAD, which takes precedence over the settings in documentSaveOptions.
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD; 
   ```

3. Create a **DocumentViewPicker** instance, and call [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-1) to start the FilePicker modal page to save the audio clip. After the user allows the operation, a folder of the corresponding application is created in the **Download** directory and the URI of the folder is returned.
   
   ```ts
   let uri: string = '';
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context; 
   const documentViewPicker = new picker.DocumentViewPicker(context);
   const documentSaveOptions = new picker.DocumentSaveOptions();
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
   documentViewPicker.save(documentSaveOptions ).then((documentSaveResult: Array<string>) => {
     uri = documentSaveResult[0];
     console.info('documentViewPicker.save succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
