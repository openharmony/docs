# Selecting User Files

If your application needs to support share and saving of user files (such as images and videos) by users, you can use the [FilePicker](../reference/apis/js-apis-file-picker.md) prebuilt in OpenHarmony to implement selecting and saving of user files.

The **FilePicker** provides the following interfaces by file type:

- [**PhotoViewPicker**](../reference/apis/js-apis-file-picker.md#photoviewpicker): used to select and save images or video files.

- [**DocumentViewPicker**](../reference/apis/js-apis-file-picker.md#documentviewpicker): used to select and save documents.

- [**AudioViewPicker**](../reference/apis/js-apis-file-picker.md#audioviewpicker): used to select and save audio files.

## Selecting Images or Video Files

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create a **photoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. Set the file type and the maximum number of media files to select.
   For example, select a maximum of five images. For details about the media file type, see [PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoPicker** instance and call [select()](../reference/apis/js-apis-file-picker.md#select) to open the **FilePicker** page for the user to select files.

   Use [PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult) to return a result set. Further operations on the selected files can be performed based on the file URIs in the result set.

   ```ts
   const photoPicker = new picker.PhotoViewPicker();
   photoPicker.select(photoSelectOptions)
     .then(async (photoSelectResult) => {
       let uri = photoSelectResult.photoUris[0];
       // Perform operations on the files based on the file URIs obtained.
     })
     .catch((err) => {
       console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
     })
   ```

## Selecting Documents

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create a **documentSelectOptions** instance.

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   ```

3. Create a **documentViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-3) to open the **FilePicker** page for the user to select documents.
     After the documents are selected successfully, a result set containing the file URIs is returned. Further operations can be performed on the documents based on the file URIs.
   > **NOTE**
   >
   > Currently, **DocumentSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.select(documentSelectOptions)
     .then((documentSelectResult) => {
       let uri = documentSelectResult[0];
       // Perform operations on the documents based on the file URIs.
     })
     .catch((err) => {
       console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
     })
   ```

## Selecting an Audio File

1. Import the **FilePicker** module.

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. Create an **audioSelectOptions** instance.

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. Create an **audioViewPicker** instance, and call [**select()**](../reference/apis/js-apis-file-picker.md#select-6) to open the **FilePicker** page for the user to select audio files.
  
   After the files are selected successfully, a result set containing the URIs of the audio files selected is returned. Further operations can be performed on the documents based on the file URIs.

   For example, use the [file management interface](../reference/apis/js-apis-file-fs.md) to obtain the file handle (FD) of the audio clip based on the URI, and then develop the audio playback function based on the media service. For details, see [Audio Playback Development](../media/audio-playback-overview.md).

   > **NOTE**
   >
   > Currently, **AudioSelectOptions** is not configurable. By default, all types of user files are selected.

   ```ts
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.select(audioSelectOptions)
     .then(audioSelectResult => {
       let uri = audioSelectOptions[0];
       // Perform operations on the audio files based on the file URIs.
     })
     .catch((err) => {
       console.error(`Invoke audioPicker.select failed, code is ${err.code}, message is ${err.message}`);
     })
   ```
