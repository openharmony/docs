# Selecting User Files

You can use [FilePicker](../reference/apis/js-apis-file-picker.md) to implement the capabilities required for sharing and saving user files such as images and videos.

**FilePicker** provides the following interfaces by file type:

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or videos.

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents.

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio clips.

## Selecting Images or Videos

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   ```
   
2. Create a **photoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. Set the type and maximum number of the files to select.<br>
   For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoViewPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **FilePicker** page for the user to select files. After the user selects files, a [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) object is returned.
   
   <br>The permission on the URIs returned in **PhotoSelectResult** is read-only. Further file operations can be performed based on the file URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   ```ts
   let URI = null;
   const photoViewPicker = new picker.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult) => {
     URI = photoSelectResult.photoUris[0];
     console.info('photoViewPicker.select to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. After the application UI is returned from **Gallery**, use a button to trigger the application's API. Use [fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync) to open each file based on the URI and obtain the FD. Use [fs.readSync](../reference/apis/js-apis-file-fs.md#readsync) to read the file, and then close the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```
   
6. Use the [<Image>](../ui/arkts-graphics-display.md) component to display the image based on the URI.

   ```
   ForEach(URI, item => {
       GridItem() {
           Image(item)
               .width(200)
       }
   }, item => JSON.stringify(item))
   ```


## Selecting Documents

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import Want from '@ohos.app.ability.Want';
   ```

2. Create a **DocumentSelectOptions** instance.

   ```ts
   import picker from '@ohos.file.picker';
   
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   documentSelectOptions.maxSelectNumber = 5; // (Optional) Maximum number of documents to select.
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test"; // (Optional) Path of the document or directory to select.
   documentSelectOptions.fileSuffixFilters = ['.png', '.txt', '.mp4']; // (Optional) Types of the documents to select. Use a comma to separate multiple file name extensions.
   ```

3. Create a **DocumentViewPicker** instance and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** page for the user to select documents. After the documents are selected, a result set containing the document URIs is returned.

   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger the operation for opening the file.

   If metadata needs to be obtained, you can use [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) and [@ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md) APIs to obtain document attribute information, such as the document name, size, access time, modification time, and path, based on the URI.

   ```ts
   import picker from '@ohos.file.picker';
   
   let uris: Array<string> = [];
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open each document based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri = uris[0];
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the document based on the FD, and then use **fs.closeSync** to close the FD.

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
   ```

2. Create an **audioSelectOptions** instance.

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an **audioViewPicker** instance, and call [select()](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** page for the user to select audio clips. After the files are selected, a result set containing the URIs of the audio clips selected is returned.<br>The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.
   
   For example, use the [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) API to obtain the FD of the audio clip based on the URI, and then develop the audio playback function based on the media service. For details, see [Audio Playback Development](../media/audio-playback-overview.md).
   
   > **NOTE**
>
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.
   
   ```ts
let URI = null;
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
     URI = audioSelectResult[0];
     console.info('audioViewPicker.select to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
   
4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open each file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD, and then use **fs.closeSync** to close the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```
