# Selecting User Files

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=563f325fc4197af705064cb3a103e60b86e4aa4f translatedAt=2026-08-01T07:29:28.958Z pushedAt=2026-08-01T11:14:03.294Z -->

When users need to share files or save user files such as images and videos, you can use the system's prebuilt [Picker](../reference/apis-core-file-kit/js-apis-file-picker.md) to implement this capability. Accessing files through Picker will launch the corresponding app and guide users through the UI operations. The API itself does not require any permission. The URI obtained by selecting a file or folder through Picker has only **temporary read/write permission**. To obtain persistent permission, use [FilePicker to set permanent authorization](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).

**Constraints**

When using APIs that require the system capability **SystemCapability.FileManagement.UserFileService.FolderSelection**, you can call [canIUse](../reference/common/js-apis-syscap.md#caniuse) to check whether the device has this system capability:

```ts
if (!canIUse('SystemCapability.FileManagement.UserFileService.FolderSelection')) {
      console.error('This API is not supported on this device');
      return;
}
```

**FilePicker** provides the following types of Pickers by file type:

- [PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated): used to select and save images and videos. The APIs of this Picker will not be maintained in later versions. Use [PhotoViewPicker](../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) of PhotoAccessHelper to select image files. Use [a security component to save media library assets](../media/medialibrary/photoAccessHelper-savebutton.md).

- [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker): used to select and save documents. The **DocumentViewPicker** API triggers the **FilePicker** application. Documents are not distinguished by file name extensions. For example, the images and files downloaded from a browser are documents.

- [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker): used to select and save audio clips. The **AudioViewPicker** API triggers the **AudioPicker** application.

## Selecting Images or Videos

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated) will not be maintained in later versions. Use [PhotoViewPicker](../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) of PhotoAccessHelper to select image files.

## Selecting Documents

1. Import the Picker module and the file management module.

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Configure [document selection options](../reference/apis-core-file-kit/js-apis-file-picker.md#documentselectoptions) based on your service requirements. The following code only provides configuration examples for each option.

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions();
   // Optional. Set the maximum number of files. In API version 20 and earlier versions, a maximum of 500 files can be selected at a time, with a default value of 500. The directory selection feature is available only to devices with the system capability, and a maximum of 1 directory can be selected at a time. In API version 21 and later versions, the limit on the number of files that can be selected is canceled. Due to the system capability constraints, selecting an excessively large number of files may result in functional exceptions or poor processing performance. You are advised to select a maximum of 10,000 files at a time. In API version 23 and later versions, the maximum number of directories that can be selected at a time is not limited.
   documentSelectOptions.maxSelectNumber = 5;
   // Optional. Specify the path of the files or folder to select.
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test";
   // Document type to select. The default value is FILE (file type). Starting from API version 26.0.0, when the file type is FOLDER, this parameter is supported on Phone devices; when the file type is MIXED, this parameter works on 2in1 devices and has no effect on other devices.
   documentSelectOptions.selectMode = picker.DocumentSelectMode.FILE;
   // Select the file suffix type ['Suffix type description|Suffix type']. (Optional. If this parameter is not transferred, all files are displayed by default.) Use a comma to separate multiple file suffixes, which cannot exceed 100. The wildcard ['All files (*.*)|.*'] can be used on 2-in-1 devices (and smartphones since API version 17) to display all files.
    documentSelectOptions.fileSuffixFilters = ['Image(.png, .jpg)|.png, .jpg', 'Document|.txt', 'Video|.mp4', '.pdf'];
   // Whether to authorize the specified file or directory. The value true means authorization is enabled. When set to true, defaultFilePathUri is a required parameter and the authorization UI of File Manager is opened. The value false means authorization is disabled (default), and the regular File Manager UI is opened (optional). This parameter works on 2in1 devices and has no effect on other devices.
   documentSelectOptions.authMode = false;
   // Batch authorization mode. The default value is false (non-batch authorization mode). When multiAuthMode is set to true, batch authorization mode is enabled. When multiAuthMode is true, only the multiUriArray parameter takes effect and other parameters do not. This parameter works on Phone devices and has no effect on other devices.
   documentSelectOptions.multiAuthMode = false;
   // URI array for batch authorization (only files are supported; folders do not take effect). Used together with multiAuthMode. When multiAuthMode is false, this parameter does not take effect. This parameter works on Phone devices and has no effect on other devices.
   documentSelectOptions.multiUriArray = ["file://docs/storage/Users/currentUser/test", "file://docs/storage/Users/currentUser/2test"];
   // Enable aggregate view mode, which supports opening the aggregate view of the File Manager app. The default value is DEFAULT, meaning this parameter does not take effect and the view is non-aggregate. When this parameter is set to a non-DEFAULT value, other parameters do not take effect. Starting from API version 26.0.0, when this parameter is set to a non-DEFAULT value, only the fileSuffixFilters parameter takes effect and other parameters do not.
   // This parameter works on Phone devices and has no effect on other devices.
   documentSelectOptions.mergeMode = picker.MergeTypeMode.DEFAULT;
   // Whether encryption is supported (only files are supported; folders do not take effect). The default value is false. When this parameter is set to true, files can be encrypted in the Picker UI. (Note: This parameter is supported from API version 19.)
   documentSelectOptions.isEncryptionSupported = false;
   // Whether multi-select folders is supported. The default value is false, meaning multi-select folders is not supported. This parameter must be used together with the selectMode parameter. (Note: This parameter is supported from API version 26.0.0.)
   documentSelectOptions.allowsMulFolderSelection = false;
   ```

3. Create a [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker) instance. Call [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) to launch the FilePicker app UI for file selection.

   <!--@[picker_select](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/SelectingUserFiles/entry/src/main/ets/pages/Index.ets)-->        

   ``` TypeScript
   let uris: string[] = [];
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: string[]) => {
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

   > **NOTE**
   >
   > 1. The URI permission returned by [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) through Picker is a temporary read/write permission. The temporary permission becomes invalid after the app exits to the background.<br>
   > 2. To obtain persistent permission, see [Persistent Authorization for File Access](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).<br>
   > 3. You can further process the URIs in the result set. It is recommended to define a global variable to store the URI.<br>
   > 4. If you need to obtain metadata, you can use [File Management](../reference/apis-core-file-kit/js-apis-file-fs.md) and [File URI](../reference/apis-core-file-kit/js-apis-file-fileuri.md) to obtain some file attribute information based on the URI, such as file size, access time, modification time, file name, and file path.

4. After the application UI is returned from FilePicker, use [fileIo.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync) to open the file based on the URI and obtain the file descriptor (FD).

   ```ts
   if (uris.length > 0) {
     let uri: string = uris[0];
     // Note that the interface permission parameter is fileIo.OpenMode.READ_ONLY.
     let file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
     console.info('file fd: ' + file.fd);
   }
   ```

5. Use [fileIo.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioreadsync) to read data from the file through the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fileIo.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   // Close the fd after reading.
   fileIo.closeSync(file);
   ```

## Selecting Audio Clips

1. Import the Picker module and the file management module.

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Create an **AudioSelectOptions** instance.

   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files can be selected.

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker) instance. Call [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-5) to launch the AudioPicker app UI for file selection.

   <!--@[audio_select_picker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/SelectingUserFiles/entry/src/main/ets/pages/Index.ets)-->        

   ``` TypeScript
   let uris: string[] = [];
   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
     // Returns the URI result set of the selected audio after the file is selected.
     uris = audioSelectResult;
     console.info('audioViewPicker.select to file succeed and uri is:' + uris);
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **NOTE**
   >
   > 1. The URI permission returned by [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) through Picker is a temporary read-only permission. The temporary permission becomes invalid after the app exits to the background.<br>
   > 2. To obtain persistent permission, see [Persistent Authorization for File Access](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).<br>
   > 3. You can read file data based on the URIs in the result set. It is recommended to define a global variable to store the URI. For example, you can use the APIs of the [File Management](../reference/apis-core-file-kit/js-apis-file-fs.md) module to obtain the file descriptor (FD) of the audio resource based on the URI, and then use the media service to implement audio playback. For details, see [Audio Playback Development](../media/audio/audio-playback-overview.md).

4. After the application UI is returned from AudioPicker, use [fileIo.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync) to open the file based on the URI and obtain the file descriptor (FD).

   ```ts
   if (uris.length > 0) {
      let uri: string = uris[0];
      // Note that the interface permission parameter here is fileIo.OpenMode.READ_ONLY.
      let file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
      console.info('file fd: ' + file.fd);
   }
   ```

5. Use [fileIo.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read data from the file through the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fileIo.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   // Close the fd after reading.
   fileIo.closeSync(file);
   ```

## Samples

The following sample is available:

- [Picker (ArkTS) (API10)](https://gitcode.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileShare/Picker) 

<!--RP1--><!--RP1End-->