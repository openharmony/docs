# Selecting User Files

You can use [FilePicker](../reference/apis/js-apis-file-picker.md) to implement the capabilities required for sharing and saving user files such as images and videos. The **FilePicker** accesses the file to start the related application, which allows the user to select or save files on the UI. No permission is required for calling **FilePicker** APIs.

The **FilePicker** provides the following interfaces by file type:

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or videos. The **PhotoViewPicker** API triggers the **Gallery** application. The images or videos saved by **save()** are stored in a directory of the **FileManager** application, and cannot be viewed in **Gallery**. To enable the saved media assets to be viewed in **Gallery**, use [a security component to create the media asset](photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

  You are advised to use [PhotoViewPicker of PhotoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md#photoviewpicker) to select images or videos. 

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents. The **DocumentViewPicker** API triggers the **FilePicker** application. Documents are not distinguished by file name extensions. For example, the images and documents downloaded from a browser are documents.

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio clips. The **AudioViewPicker** API triggers the **FilePicker** application. 

## Selecting Images or Videos

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a **PhotoSelectOptions** instance.

   ```ts
   import picker from '@ohos.file.picker';
   
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. Set the type and maximum number of the files to select.
   
   For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).
   
   ```ts
   import picker from '@ohos.file.picker';
      
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```
   
   

4. Create a **PhotoViewPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **Gallery** page for the user to select files. After the files are selected, a [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) object is returned.

   The permission on the URIs returned in the [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) object is read-only. Further file operations can be performed based on the file URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.<br>If metadata needs to be obtained, you can use [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) and [@ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file size, access time, modification time, file name, and file path, based on the URI.

   ```ts
   import picker from '@ohos.file.picker';
   import { BusinessError } from '@ohos.base';
   
   let uris: Array<string> = [];
   const photoViewPicker = new picker.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult: picker.PhotoSelectResult) => {
     uris = photoSelectResult.photoUris;
     console.info('photoViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. After the application UI is returned from **Gallery**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the file descriptor (FD). Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the file is read, use **fs.closeSync** to close the file.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## Selecting Documents

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a **DocumentSelectOptions** instance.

   ```ts
   import picker from '@ohos.file.picker';
   
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   documentSelectOptions.maxSelectNumber = 5; // (Optional) Maximum number of documents to select.
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test"; // (Optional) Path of the document or directory to select.
   documentSelectOptions.fileSuffixFilters = ['.png', '.txt', '.mp4']; // (Optional) Types of the documents to select. Use a comma to separate multiple file name extensions.
   ```

3. Create a **DocumentViewPicker** instance and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** page for the user to select documents. After the documents are selected, a result set containing the URIs of the selected documents is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URI. Note that the URI cannot be directly used in the **picker** callback to open a document. You need to define a global variable to save the URI and use a button to trigger document opening.

   If metadata needs to be obtained, you can use [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) and [@ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md) APIs to obtain document attribute information, such as the document name, size, access time, modification time, and path, based on the URI.

   ```ts
   import picker from '@ohos.file.picker';
   import { BusinessError } from '@ohos.base';
   
   let uris: Array<string> = [];
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the document based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the document based on the FD. After the document is read, use **fs.closeSync** to close the document.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## Selecting Audio Clips

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. Create an **AudioSelectOptions** instance.

   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   import picker from '@ohos.file.picker';
   
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an **audioViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** page for the user to select audio clips. After the audio clips are selected, a result set containing the URIs of the audio clips selected is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the file URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   For example, use the  [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) API to obtain the FD of the audio file based on the URI, and then develop the audio playback function based on the media service. For details, see [Audio Playback Development](../media/audio-playback-overview.md).

   ```ts
   import picker from '@ohos.file.picker';
   
   let uri: string = '';
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.select to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the file is read, use **fs.closeSync** to close the file.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

