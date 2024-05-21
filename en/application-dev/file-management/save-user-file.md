# Saving User Files

When a user needs to download a file from the Internet or save a file to another directory, use **FilePicker** to save the file.

The operations for saving images, audio or video clips, and documents are similar. Call **save()** of the corresponding picker instance and pass in **saveOptions**. No permission is required if your application uses **FilePicker** to access files.

Currently, all the **save()** behaviors of **FilePicker** can be perceived by users. Specifically, **FilePicker** is started to save the files to a directory managed by **FileManager**. The files are isolated from the assets managed by **Gallery** and cannot be viewed in **Gallery**.

To enable the saved image or video to be viewed in **Gallery**, [create the media asset using a security component](../media/medialibrary/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).


## Saving Images or Videos

For example, select an image from **Gallery** and save it.

1. Import the [picker](../reference/apis-core-file-kit/js-apis-file-picker.md), [fs](../reference/apis-core-file-kit/js-apis-file-fs.md), and [photoAccessHelper](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md) modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   ```
   
2. Use [select()](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#select) to select an image from the device and use a global variable to hold the returned URI.

   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import { BusinessError } from '@ohos.base';

   let selectUris: Array<string> = [];
       try {
           let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
        	PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
           PhotoSelectOptions.maxSelectNumber = 1;
           let photoPicker = new photoAccessHelper.PhotoViewPicker();
           photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
               selectUris = PhotoSelectResult.photoUris;
               console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
           }).catch((err: BusinessError) => {
               console.error(`PhotoViewPicker.select failed with err: ${err.code}, ${err.message}`);
           });
       } catch (error) {
           let err: BusinessError = error as BusinessError;
           console.error(`PhotoViewPicker failed with err: ${err.code}, ${err.message}`);
       }
   ```
   
3. Use [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save) to start the FilePicker page to save the image. After the user selects the destination folder, the image is saved. A global variable holding the URI of the image is returned.
   
   The permission on the URI returned by **save()** is read/write. Further file operations can be performed based on the URI.

   ```ts  
   import picker from '@ohos.file.picker';
   import { BusinessError } from '@ohos.base';
   
   let saveUris: Array<string> = [];
   try {
       const photoSaveOptions = new picker.PhotoSaveOptions(); // Create a photoSaveOptions instance.
       photoSaveOptions.newFileNames = ["PhotoViewPicker01.png"]; // (Optional) Name of the file to be saved. The file name in the square brackets can be customized and must be unique. If the file name already exists on the device, change the file name. Otherwise, an error will be returned.
       const photoViewPicker = new picker.PhotoViewPicker();
       try {
           let photoSaveResult = await photoViewPicker.save(photoSaveOptions);
           if (photoSaveResult != undefined) {
               saveUris = photoSaveResult;
               console.info('photoViewPicker.save to file succeed and uris are:' + photoSaveResult);
           }
       } catch (error) {
           let err: BusinessError = error as BusinessError;
           console.error(`[picker] Invoke photoViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
       }
   } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.info("[picker] photoViewPickerSave error = " + JSON.stringify(err));
   }
   ```
   
4. Use [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to select the file and save it. The FDs of the file selected and the file saved are returned. Note that the permission is **fs.OpenMode.READ_ONLY** in the select API and **fs.OpenMode.WRITE_ONLY** in the save API. Use [fs.copyFileSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fscopyfilesync) to copy the file. Then, use **close()** to close the file selected and the file saved.

   ```ts
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   
   try {
   	let photoSelect = fs.openSync(selectUris[0], fs.OpenMode.READ_ONLY);
       let photoSave = fs.openSync(saveUris[0], fs.OpenMode.WRITE_ONLY);
       fs.copyFileSync(photoSelect.fd, photoSave.fd);
       fs.close(photoSelect);
       fs.close(photoSave);
   } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.info("[picker] Photo Save error = " + JSON.stringify(err));
   }
   ```

## Saving Documents

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a **documentSaveOptions** instance.

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions(); // Create a documentSaveOptions instance.
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"]; // (Optional) Set the name of the document to save.
   documentSaveOptions.fileSuffixChoices = ['.png', '.txt', '.mp4']; // (Optional) Types of the documents to save.
   ```

3. Create a **documentViewPicker** instance, and use [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-3) to start the FilePicker page to save the document. After the user selects the destination folder, the document is saved and the URI of the document saved is returned.<br>The permission on the URI returned by **save()** is read/write. Further file operations can be performed based on the URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to hold the URI and use a button to open the file.
   
   ```ts
import { BusinessError } from '@ohos.base';
   
   let uris: Array<string> = [];
const documentViewPicker = new picker.DocumentViewPicker(); // Create a documentViewPicker instance.
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
   
4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open a document based on the URI. After the document is opened, the FD is returned. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   import fs from '@ohos.file.fs';
   
   const uri = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync) to modify the document based on the FD, and use **closeSync()** to close the document.

   ```ts
   import fs from '@ohos.file.fs';
   
   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## Saving Audio Clips

1. Import the **picker** and **fs** modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. Create an **audioSaveOptions** instance.

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions(); // Create an audioSaveOptions instance.
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; // (Optional) Set the name of the audio file to save.
   ```

3. Create an **audioViewPicker** instance, and use [save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-6) to start the FilePicker page to save the audio clip. After the user selects the destination folder, the audio clip is saved and the URI of the audio clip saved is returned.<br>The permission on the URI returned by **save()** is read/write. Further file operations can be performed based on the URI. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to hold the URI and use a button to open the audio clip.
   
   ```ts
   let uri: string = '';
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
   
4. After the application UI is returned from **FilePicker**, use a button to trigger the application's API. Use [fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open an audio clip based on the URI. After the audio clip is opened, the FD is returned. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync) to modify the audio clip based on the FD, and use **closeSync()** to close the audio clip.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
   
<!--no_check-->