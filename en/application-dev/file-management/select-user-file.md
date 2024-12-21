# Selecting User Files

You can use [FilePicker](../reference/apis-core-file-kit/js-apis-file-picker.md) to implement the capabilities required for sharing user files and saving images and videos. When Picker is used to access a file, the related application will be started and guide the user to complete related operation on the UI. The caller does not require any permission. The permission on the file URI granted by Picker, however, is temporary. If required, you can persist the permission on the URI. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).

**FilePicker** provides the following types of Pickers by file type:

- [PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpicker): used to select and save images and videos. However, the APIs of this Picker will not be maintained in later versions. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../media/medialibrary/photoAccessHelper-photoviewpicker.md) to select images, and use [security components to create media assets](../media/medialibrary/photoAccessHelper-savebutton.md).

- [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker): used to select and save documents. The **DocumentViewPicker** API triggers the **FilePicker** application. Documents are not distinguished by file name extensions. For example, the images and files downloaded from a browser are documents.

- [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker): used to select and save audio clips. The **AudioViewPicker** API triggers the **FilePicker** application. 

## Selecting Images or Videos

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpicker) will not be maintained in later versions. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../media/medialibrary/photoAccessHelper-photoviewpicker.md) to select images.

## Selecting Documents

1. Import modules.

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a **DocumentSelectOptions** instance.

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions();
   // (Optional) Set the maximum number of documents that can be selected.
   documentSelectOptions.maxSelectNumber = 5;
   // (Optional) Specify the path of the files or folder to select.
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test";
   // (Optional) Set the file name extension types ['File name extension description|File name extension type'] that can be selected. Use a comma to separate multiple file name extensions, which cannot exceed 100. To select all files, use 'All files(*.*)|.*'.
    documentSelectOptions.fileSuffixFilters = ['Image(.png, .jpg)|.png, .jpg', 'Document|.txt', 'Video|.mp4', '.pdf'];
   // Whether to grant the permission for the specified files or folder. The value true means to grant the permission, the value false means the opposite. If this parameter is true, defaultFilePathUri is mandatory and the file management authorization page is displayed. If this parameter is false, a common file management page is displayed. This parameter is optional.
   documentSelectOptions.authMode = true;
   ```

3. Create a [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker) instance, and call [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) to start the FilePicker application page for the user to select documents.
   
   ```ts
   let uris: Array<string> = [];
   let context = getContext (this) as common.Context; // Ensure that getContext (this) returns UIAbilityContext.
   // Create a DocumentViewPicker instance.
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
     // After the user selects documents, a result set containing the document URIs is returned.
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

  > **NOTE**
  >
  > - The permission for the URI returned by [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) of Picker is a temporary read-only permission. The temporary permission will be invalidated once the application exits.
  >
  > - You can persist the temporary permission for a URI. This operation is available only for 2-in-1 devices. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).
  >
  > - Further operations can be performed on the documents based on the file URIs returned in the result set. You are advised to define a global variable to save the URI.
  >
  > - If metadata needs to be obtained, you can use the [@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) and [@ohos.file.fileuri](../reference/apis-core-file-kit/js-apis-file-fileuri.md) APIs to obtain document attribute information, such as the document name, size, access time, modification time, and path, based on the URI.

4. After the application UI is returned from FilePicker, call [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open a document based on the URI. The file descriptor (FD) is obtained.

   ```ts
   let uri: string = '';
   // Note that the mode parameter of fs.openSync() is fs.OpenMode.READ_ONLY.
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Call [fs.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read data from the document based on the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   // Close the FD after the data is read.
   fs.closeSync(file);
   ```

## Selecting Audio Clips

1. Import modules.

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Create an **AudioSelectOptions** instance.

   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker) instance, and call [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-6) to start the FilePicker application page for the user to select audio clips.
   
   ```ts
   let uris: string = '';
   // Ensure that getContext(this) returns UIAbilityContext.
   let context = getContext(this) as common.Context; 
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
     // After the user selects audio clips, a result set containing the URIs of the audio clips selected is returned.
     uris = audioSelectResult[0];
     console.info('audioViewPicker.select to file succeed and uri is:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

  > **NOTE**
  >
  > - The permission for the URI returned by [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) of Picker is a temporary read-only permission. The temporary permission will be invalidated once the application exits.
  >
  > - You can persist the temporary permission for a URI. This operation is available only for 2-in-1 devices. For details, see [Persisting a Temporary Permission Granted by Picker](file-persistPermission.md#persisting-a-temporary-permission-granted-by-picker).
  >
  > - You can read file data based on the URI. You are advised to define a global variable to save the URI. For example, you can use the [@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md) API to obtain the FD of the audio clip based on the URI, and then develop the audio playback application with the media service. For details, see [Audio Playback Development](../media/audio/audio-playback-overview.md).

4. After the application UI is returned from FilePicker, call [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open an audio clip based on the URI. The FD is obtained.

   ```ts
   let uri: string = '';
   // Note that the mode parameter of fs.openSync() is fs.OpenMode.READ_ONLY.
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Call [fs.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read data from the audio clip based on the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   // Close the FD after the data is read.
   fs.closeSync(file);
   ```

<!--RP1--><!--RP1End-->
