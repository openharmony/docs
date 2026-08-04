# Saving User Files

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=26db867956892783b25f638a74cb23fb0a676944 translatedAt=2026-08-01T07:28:27.106Z pushedAt=2026-08-01T11:09:43.815Z -->

When a user needs to download a file from the Internet or save a file to another directory, use **FilePicker** to save the file. Pay attention to the following key points:

**Permission Description**

- The read and write permissions on the file URI granted by Picker is temporary by default, and will be automatically invalidated once the application exits.

- If the [autoCreateEmptyFile](../reference/apis-core-file-kit/js-apis-file-picker.md#documentsaveoptions) parameter is set to **false**, the obtained URI has **temporary create and delete permissions** in addition to **temporary read and write permissions**.

- You can persist the permissions on the URI. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).

- No permission is required if your application uses Picker to save audio clips, images, videos, and document files.

**Constraints**

When using APIs that require the `SystemCapability.FileManagement.UserFileService.FolderSelection` system capability, you can call [canIUse](../reference/common/js-apis-syscap.md#caniuse) to check whether the device has this system capability:

```ts
if (!canIUse('SystemCapability.FileManagement.UserFileService.FolderSelection')) {
      console.error('This API is not supported on this device');
      return;
}
```

**System Isolation Description**

- The files saved by the Picker are stored in the specified directory. They are isolated from the assets managed by **Gallery** and cannot be viewed in **Gallery**.

- To save images and videos to Gallery, [use the SaveButton](../media/medialibrary/photoAccessHelper-savebutton.md#creating-a-media-asset-using-savebutton).

## Saving Images or Videos

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated) will not be maintained in later versions. You are advised to use [Media Library Kit](../media/medialibrary/photoAccessHelper-savebutton.md) to save media assets.

If the security component cannot be called to save images and videos in your development, use [PhotoAccessHelper.showAssetsCreationDialog](../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#showassetscreationdialog12) to save images and videos.

## Saving Documents

1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Configure the file saving options [DocumentSaveOptions](../reference/apis-core-file-kit/js-apis-file-picker.md#documentsaveoptions) based on your actual service requirements. The following code only lists the configuration reference for each option.

   ```ts
   // Create a documentSaveOptions instance.
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // (Optional) Name of the file to save. The default value is empty.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"];
   // Specify the URI of the file or directory to save (optional).
   documentSaveOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test";
   // File type. The value is in ['Suffix type description|Suffix type'] format. To save all files, use 'All files (*.*)|.*' (optional). If multiple suffixes are selected (a maximum of 100 suffixes can be filtered), the first suffix is selected by default. If this parameter is not transferred, no suffix is filtered by default.
   documentSaveOptions.fileSuffixChoices = ['Document|.txt', '.pdf'];
   // When saving files, the application determines whether to pre-create empty files. The default value is true, where the Picker pre-creates empty files and returns an array of file URIs. When the value is set to false, no empty files are pre-created, and only an array of file URIs is returned.
   documentSaveOptions.autoCreateEmptyFile = false; 
   ```

3. Create a [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker) instance, and call [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save) to open the FilePicker interface for file saving.

   <!--@[save_file_picker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/SavingUserFiles/entry/src/main/ets/pages/Index.ets)-->

   ``` TypeScript
   let uris: string[] = [];
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: string[]) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
     // ···
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

   > **NOTE**
   >
   > - By default, Picker presets an empty file and returns the URI array of the saved file. After obtaining the URI, the app can use the APIs provided by the [file management](../reference/apis-core-file-kit/js-apis-file-fs.md) module to read and write the file.
   > - Avoid directly operating the URI in the Picker callback.
   > - It is recommended that you use a global variable to store the URI for subsequent use.
   > - You can go directly to the download directory through [DOWNLOAD mode](#saving-files-to-the-download-directory).

4. After the UI returns from FilePicker, use [fileIo.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync) to open the file through the URI and obtain the file descriptor (FD).

   ```ts
   if (uris.length > 0) {
      let uri: string = uris[0];
      // Note that the interface permission parameter is fileIo.OpenMode.READ_WRITE.
      let file = fileIo.openSync(uri, fileIo.OpenMode.READ_WRITE);
      console.info('file fd: ' + file.fd);
   }
   ```

5. Use [fileIo.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileiowritesync) to edit and modify the file through the FD, and close the FD after the modification is complete.

   ```ts
   let writeLen: number = fileIo.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fileIo.closeSync(file);
   ```

## Saving Audio Clips

1. Import modules.

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
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

   <!--@[audio_save_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/SavingUserFiles/entry/src/main/ets/pages/Index.ets)-->

   ``` TypeScript
   let uris: string[] = [];
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: string[]) => {
     uris = audioSelectResult;
     console.info('audioViewPicker.save to file succeed and uri is:' + uris);
     // ···
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

   > **NOTE**
   >
   > - By default, Picker presets an empty file and returns the URI array of the saved file. After obtaining the URI, the app can use the APIs provided by the [file management](../reference/apis-core-file-kit/js-apis-file-fs.md) module to read and write the file.
   > - Avoid directly operating the URI in the Picker callback.
   > - It is recommended that you use a global variable to store the URI for subsequent use.
   > - You can go directly to the download directory through [DOWNLOAD mode](#saving-files-to-the-download-directory).

4. After the UI returns from FilePicker, you can use [fileIo.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync) to open the file through the URI and obtain the file descriptor (FD).

   ```ts
   if (uris.length > 0) {
      let uri: string = uris[0];
      // Note that the permission specified by the mode parameter of fs.openSync() is fileIo.OpenMode.READ_WRITE.
      let file = fileIo.openSync(uri, fileIo.OpenMode.READ_WRITE);
      console.info('file fd: ' + file.fd);
   }
   ```

5. Use [fileIo.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileiowritesync) to edit and modify the file through the FD, and close the FD after the modification is complete.

   ```ts
   let writeLen = fileIo.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fileIo.closeSync(file);
 
   ```

## Saving Files to the Download Directory

**Characteristics**

- The directory is automatically created in `Download/bundle name/`.

- Files can be directly saved without file selection.

- You can create files under the returned URI that has persisting permissions.

> **NOTE**
>
> Directories created in DOWNLOAD mode are used only to store files. Directories are not isolated from each other. You are not advised to store sensitive application data.

1. Import modules.

   ```ts
   import { fileUri, picker } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
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
   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   const documentViewPicker = new picker.DocumentViewPicker(context);
   const documentSaveOptions = new picker.DocumentSaveOptions();
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uri = documentSaveResult[0];
     console.info('documentViewPicker.save succeed and uri is:' + uri);
     const testFilePath = new fileUri.FileUri(uri + '/test.txt').path;
     const file = fileIo.openSync(testFilePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
     fileIo.writeSync(file.fd, 'Hello World!');
     fileIo.closeSync(file.fd);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```