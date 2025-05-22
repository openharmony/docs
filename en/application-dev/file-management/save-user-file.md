# Saving User Files

When a user needs to download a file from the Internet or save a file to another directory, use **FilePicker** to save the file. Pay attention to the following key points:

**Permission Description**

- The read and write permissions on the file URI granted by Picker is temporary by default, and will be automatically invalidated once the application exits.
- You can persist the permissions on the URI. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker). (This operation is available only for 2-in-1 devices.)
- No permission is required if your application uses Picker to save audio clips, images, videos, and document files.

**System Isolation Description**

- The files saved by the Picker are stored in the specified directory. They are isolated from the assets managed by **Gallery** and cannot be viewed in **Gallery**.
- To save images and videos to **Gallery**, [use a security component](../media/medialibrary/photoAccessHelper-savebutton.md).

## Saving Images or Videos

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated) will not be maintained in later versions. You are advised to use [Media Library Kit](../media/medialibrary/photoAccessHelper-savebutton.md) to save media assets.

If the security component cannot be called to save images and videos in your development, use [PhotoAccessHelper.showAssetsCreationDialog](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#showassetscreationdialog12) to save images and videos.

## Saving Documents

1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Configure the save options.

   ```ts
   // Create a documentSaveOptions instance.
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // (Optional) Name of the file to save. The default value is empty.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"];
   // (Optional) Type of the document to save. The value is in ['Description|File name extensions'] format. To save all files, use 'All files (*.*)|.*'. If there are multiple file name extensions (a maximum of 100 extensions can be filtered), the first one is used by default. If this parameter is not specified, no extension is filtered by default.
   documentSaveOptions.fileSuffixChoices = ['Document|.txt', '.pdf'];
   ```

3. Create a [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#constructor12) instance, and call [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save) to start the FilePicker page to save the document.

   ```ts
   let uris: Array<string> = [];
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context;
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **NOTE**
   >
   > 1. URI storage:<br>
   > - Avoid directly using a URI in the Picker callback.<br>
   > - Define a global variable to save the URI for future use.<br>
   >
   > 2. Quick saving:<br>
   > - Directly access the download directory in [DOWNLOAD mode](#saving-files-to-the-download-directory).<br>

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

2. Configure the save options.

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions();
   // (Optional) Name of the document to save.
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; 
   ```

3. Create an [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker) instance and call [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-5) to start the FilePicker page to save the audio clip.

   ```ts
   let uri: string = '';
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context; 
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **NOTE**
   >
   > 1. URI storage:<br>
   > - Avoid directly using a URI in the Picker callback.<br>
   > - Define a global variable to save the URI for future use.<br>
   >
   > 2. Quick saving:<br>
   > - Directly access the download directory in [DOWNLOAD mode](#saving-files-to-the-download-directory).<br>

4. After the application UI is returned from FilePicker, call [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open an audio clip based on the URI. The FD is returned after the audio clip is opened.

   ```ts
   // Note that the permission specified by the mode parameter of fs.openSync() is fileIo.OpenMode.READ_WRITE.
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Call [fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync) to modify the document based on the FD, and call **fs.closeSync()** to close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
 
   ```

## Saving Files to the Download Directory

**Characteristics**

- The directory is automatically created in `Download/bundle name/`.
- Files can be directly saved without file selection.
- You can create files under the returned URI that has persistent permissions.

1. Import modules.

   ```ts
   import { fileUri, picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Configure the download mode.

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // Set pickerMode to DOWNLOAD, which takes precedence over the settings in documentSaveOptions.
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD; 
   ```

3. Save the file to the **Download** directory.

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
     const testFilePath = new fileUri.FileUri(uri + '/test.txt').path;
     const file = fs.openSync(testFilePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
     fs.writeSync(file.fd, 'Hello World!');
     fs.closeSync(file.fd);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
