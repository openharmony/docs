# Saving User Files

When a user needs to download a file from the network to a local directory or save a user file into another directory, use **FilePicker** to save the file.

The operations for saving images, audio or video clips, and documents are similar. Call **save()** of the corresponding picker instance and pass in **saveOptions**.


## Saving Images or Video Files

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. Create a **photoSaveOptions** instance.

   ```ts
   const photoSaveOptions = new picker.PhotoSaveOptions(); // Create a photoSaveOptions instance.
   photoSaveOptions.newFileNames = ["PhotoViewPicker01.jpg"]; // (Optional) Set the names of the files to save.
   ```

3. Create a **photoViewPicker** instance and call [save()](../reference/apis/js-apis-file-picker.md#save) to open the **FilePicker** page to save the image. After the user selects the destination folder, the image is saved and the URI of the saved image is returned.
   
   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   ```ts
   let URI = null;
   const photoViewPicker = new picker.PhotoViewPicker();
   photoViewPicker.save(photoSaveOptions).then((photoSaveResult) => {
     URI = photoSaveResult[0];
     console.info('photoViewPicker.save to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke photoViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync()](../reference/apis/js-apis-file-fs.md#writesync) to edit the file based on the FD, and then close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## Saving Documents

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. Create a **documentSaveOptions** instance.

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions(); // Create a documentSaveOptions instance.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"]; // (Optional) Set the name of the document to save.
   ```

3. Create a **documentViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-3) to open the **FilePicker** page to save the document. After the user selects the destination folder, the document is saved and the URI of the document saved is returned.
   
   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   ```ts
   let URI = null;
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult) => {
     URI = documentSaveResult[0];
     console.info('documentViewPicker.save to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync()](../reference/apis/js-apis-file-fs.md#writesync) to edit the document based on the FD, and then close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## Saving Audio Files

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. Create an **audioSaveOptions** instance.

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions(); // Create an audioSaveOptions instance.
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; // (Optional) Set the name of the audio file to save.
   ```

3. Create an **audioViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-6) to open the **FilePicker** page to save the file. After the user selects the destination folder, the audio file is saved and the URI of the file saved is returned.
   
   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.
   
   ```ts
   let URI = null;
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult) => {
     URI = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync()](../reference/apis/js-apis-file-fs.md#writesync) to edit the file based on the FD, and then close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
   
