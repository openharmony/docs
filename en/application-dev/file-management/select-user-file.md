# Selecting User Files

If your application needs to support share and saving of user files (such as images and videos), you can use OpenHarmony [FilePicker](../reference/apis/js-apis-file-picker.md) to implement selection and saving of user files.

The **FilePicker** provides the following interfaces by file type:

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or video files.

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents.

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio files.

## Selecting Images or Video Files

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. Create a **photoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. Set the file type and the maximum number of media files to select.<br>
   For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **FilePicker** page for the user to select files. After the files are selected, [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) is returned.
   
   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the **PhotoSelectResult**. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   ```ts
   let uri = null;
   const photoViewPicker = new picker.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult) => {
     uri = photoSelectResult.photoUris[0];
     console.info('photoViewPicker.select to file succeed and uri is:' + uri);
   }).catch((err) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the file descriptor (FD). Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
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
   ```

2. Create a **documentSelectOptions** instance.

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   ```

3. Create a **documentViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** page for the user to select documents. After the documents are selected, a result set containing the file URIs is returned.
   
   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.
   
   For example, you can use [file management APIs](../reference/apis/js-apis-file-fs.md) to obtain file attributes, such as the file size, access time, and last modification time, based on the URI. If you need to obtain the file name, use [startAbilityForResult](../../application-dev/application-models/uiability-intra-device-interaction.md).

   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   let uri = null;
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
     uri = documentSelectResult[0];
     console.info('documentViewPicker.select to file succeed and uri is:' + uri);
   }).catch((err) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** cannot be used to obtain the file name. To obtain the file name, use **startAbilityForResult()**.

   ```ts
   let config = {
     action: 'ohos.want.action.OPEN_FILE',
     parameters: {
       startMode: 'choose',
     }
   }
   try {
     let result = await context.startAbilityForResult(config, {windowMode: 1});
     if (result.resultCode !== 0) {
       console.error(`documentViewPicker.select failed, code is ${result.resultCode}, message is ${result.want.parameters.message}`);
       return;
     }
     // Obtain the URI of the document.
     let select_item_list = result.want.parameters.select_item_list;
     // Obtain the name of the document.
     let file_name_list = result.want.parameters.file_name_list;
   } catch (err) {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
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
   ```

2. Create an **audioSelectOptions** instance.

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an **audioViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** page for the user to select audio files. After the files are selected, a result set containing the URIs of the audio files selected is returned.
   
   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URIs in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.
   
   For example, use the [file management interface](../reference/apis/js-apis-file-fs.md) to obtain the file handle (FD) of the audio clip based on the URI, and then develop the audio playback function based on the media service. For details, see [Audio Playback Development](../media/audio-playback-overview.md).

   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   let uri = null;
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.select(audioSelectOptions).then(audioSelectResult => {
     uri = audioSelectOptions[0];
     console.info('audioViewPicker.select to file succeed and uri is:' + uri);
   }).catch((err) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```
