# Selecting User Files

You can use [FilePicker](../reference/apis/js-apis-file-picker.md) to implement the capabilities required for sharing and saving user files such as images and videos. The **FilePicker** accesses the file to start the application and guide the user to perform operations on the GUI. The API itself does not need any permission.

The **FilePicker** provides the following interfaces by file type:

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or videos. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md#photoviewpicker) to select files. The **PhotoViewPicker** of **FilePicker** can select only assets in **Gallery**, which is in a directory of the system **FileManager**. Therefore, the images and videos saved using **save()** cannot be viewed in **Gallery**. To enable the saved assets to be viewed in **Gallery**, use [a security component to create the media asset](photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security component).

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents. The documents can be selected by using **FilePicker**. The documents are not distinguished by file name extensions. For example, the images and documents downloaded from a browser are of the document type.

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio files. Currently, the audio files can be selected by using **FilePicker**.

## Selecting Images or Video Files

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

3. Set the file type and the maximum number of media files to select.
   
For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).
   
   ```ts
   import picker from '@ohos.file.picker';
   
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
```
   
4. Create a **photoPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **Gallery** page for the user to select files. After the files are selected, [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the **PhotoSelectResult**. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   If metadata needs to be obtained, you can use [File management](../reference/apis/js-apis-file-fs.md) and [File URI](../reference/apis/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file size, access time, modification time, file name, and file path, based on the URI.

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

5. After the UI is returned from the **Gallery** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the file descriptor (FD). Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

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
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test"; // (Optional) Path of the file or directory to select.
   documentSelectOptions.fileSuffixFilters = ['.png', '.txt', '.mp4']; // (Optional) File name extensions of the documents to select.
   ```

3. Create a **DocumentViewPicker** instance and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** application page for the user to select documents. After the documents are selected, a result set containing the file URIs is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   If metadata needs to be obtained, you can use [File management](../reference/apis/js-apis-file-fs.md) and [File URI](../reference/apis/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file size, access time, modification time, file name, and file path, based on the URI.

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

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## Selecting Audio Files

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

3. Create an **audioViewPicker** instance and call [**select()**](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** application page for the user to select audio files. After the files are selected, a result set containing the URIs of the audio files selected is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   For example, use the [file management interface](../reference/apis/js-apis-file-fs.md) to obtain the file handle (FD) of the audio clip based on the URI, and then develop the audio playback function based on the media service. For details, see [Audio Playback Development](../media/audio-playback-overview.md).

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

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```