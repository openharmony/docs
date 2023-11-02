# Selecting User Files

You can use [FilePicker](../reference/apis/js-apis-file-picker.md) to implement the capabilities required for sharing and saving user files such as images and videos.

The **FilePicker** provides the following interfaces by file type:

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or videos.

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents.

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio clips.

## Selecting Images or Videos

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. Create a **photoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. Set the type and maximum number of the files to select.
   For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoViewPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **FilePicker** page for the user to select files. After the files are selected, a [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) object is returned.
   
   The permission on the URIs returned in **PhotoSelectResult** is read-only. Further file operations can be performed based on the file URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

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

5. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the file is read, use **fs.closeSync** to close the file.

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

3. Create a **documentViewPicker** instance and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** page for the user to select documents. After the documents are selected, a result set containing the document URIs is returned.
   
   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the URI. Note that the URI cannot be directly used in the **picker** callback to open a document. You need to define a global variable to save the URI and use a button to trigger document opening.
   
   You can use [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) APIs to obtain document attribute information, such as the file size, access time, and last modification time, based on the URI. If you need to obtain the document name, use [startAbilityForResult](../../application-dev/application-models/uiability-intra-device-interaction.md).

   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   let URI = null;
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
     URI = documentSelectResult[0];
     console.info('documentViewPicker.select to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** cannot be used to obtain the document name. To obtain the document name, use **startAbilityForResult()**.

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

4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the document based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the document based on the FD. After the document is read, use **fs.closeSync** to close the file.

   ```ts
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

3. Create an **audioViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** page for the user to select audio clips. After the audio clips are selected, a result set containing the URIs of the audio clips selected is returned.
   
   The permission on the URIs returned by **select()** is read-only. Further file operations can be performed based on the file URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.
   
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
   
4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the file is read, use **fs.closeSync** to close the file.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```
