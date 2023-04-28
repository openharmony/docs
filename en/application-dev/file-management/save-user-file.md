# Saving User Files

When a user needs to download a file from the network to a local directory or save a user file into another directory, use **FilePicker** to save the file.

The operations for saving images, audio or video clips, and documents are similar. Call **save()** of the corresponding picker instance and pass in **saveOptions**.


## Saving Images or Video Files

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create a **photoSaveOptions** instance.

   ```ts
   const photoSaveOptions = new picker.PhotoSaveOptions(); // Create a photoSaveOptions instance.
   photoSaveOptions.newFileNames = ["PhotoViewPicker01.jpg"]; // (Optional) Set the names of the files to save.
   ```

3. Create a **photoViewPicker** instance and call [save()](../reference/apis/js-apis-file-picker.md#save) to open the **FilePicker** page to save the files.
     After the user selects the target folder, the file saving operation is complete. After the files are saved successfully, the URIs of the files saved are returned.

   ```ts
   const photoViewPicker = new picker.PhotoViewPicker();
   photoViewPicker.save(photoSaveOptions)
     .then(async (photoSaveResult) => {
       let uri = photoSaveResult[0];
       // Perform operations on the files based on the file URIs obtained.
     })
     .catch((err) => {
       console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
     })
   ```

## Saving Documents

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create a **documentSaveOptions** instance.

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions(); // Create a documentSaveOptions instance.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"]; // (Optional) Set the names of the documents to save.
   ```

3. Create a **documentViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-3) to open the **FilePicker** page to save the documents.
   After the user selects the target folder, the file saving operation is complete. After the files are saved successfully, the URIs of the files saved are returned.

   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.save(documentSaveOptions)
     .then(async (documentSaveResult) => {
       let uri = documentSaveResult[0];
       // For example, write data to the documents based on the obtained URIs.
     })
     .catch((err) => {
       console.error(`Invoke documentPicker.save failed, code is ${err.code}, message is ${err.message}`);
     })
   ```

## Saving Audio Files

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create an **audioSaveOptions** instance.

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions(); // Create an audioSaveOptions instance.
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; // (Optional) Set the names of the files to save.
   ```

3. Create an **audioViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-6) to open the **FilePicker** page to save the files.
     After the user selects the target folder, the file saving operation is complete. After the files are saved successfully, the URIs of the files saved are returned.
   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.save(audioSaveOptions)
     .then((audioSelectResult) => {
       let uri = audioSelectResult[0];
       // Perform operations on the audio files based on the file URIs.
     })
     .catch((err) => {
       console.error(`Invoke audioPicker.select failed, code is ${err.code}, message is ${err.message}`);
     })
   ```
