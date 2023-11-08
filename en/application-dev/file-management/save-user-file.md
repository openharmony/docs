# Saving User Files

When a user needs to download a file from the network to a local directory or save a user file into another directory, use **FilePicker** to save the file.

The operations for saving images, audio or video clips, and documents are similar. Call **save()** of the corresponding picker instance and pass in **saveOptions**. No permission is required if your application uses **FilePicker** to access files.

Currently, all the **save()** APIs of **FilePicker** can be perceived by users. Specifically, **FilePicker** is started to save the files to a directory managed by **FileManager**. The files are isolated from the assets managed by **Gallery** and cannot be viewed in **Gallery**.

To enable the saved image or video to be viewed in Gallery, [create the media asset using a security component](./photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).


## Saving Images or Video Files

For example, select an image from **Gallery** and save it to the file manager.

1. Import the [picker](../reference/apis/js-apis-file-picker.md), [fs](../reference/apis/js-apis-file-fs.md), [photoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md), and [dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md) modules.

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

2. Obtain the thumbnail of the first image on the device. Before performing this operation, ensure that at least one image exists on the device.

   ```ts
   import common from '@ohos.app.ability.common';
   import image from '@ohos.multimedia.image';
   import { BusinessError } from '@ohos.base';

   let context = getContext(this) as common.UIAbilityContext;
   let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

   let pixelmapArrayBuffer: ArrayBuffer;
   async function getPixelmap(): Promise<void> {
      try {
         let predicates = new dataSharePredicates.DataSharePredicates();
         let fetchOption: photoAccessHelper.FetchOptions = {
            fetchColumns: [],
            predicates: predicates
         };
         let fetchResult = await phAccessHelper.getAssets(fetchOption);
         console.info('[picker] getThumbnail fetchResult: ' + fetchResult);
         const asset = await fetchResult.getFirstObject();
         console.info('[picker] getThumbnail asset displayName = ', asset.displayName);
         asset.getThumbnail().then((pixelMap: image.PixelMap) => {
            let pixelBytesNumber = pixelMap.getPixelBytesNumber();
            const readBuffer = new ArrayBuffer(pixelBytesNumber);
            pixelMap.readPixelsToBuffer(readBuffer).then(() => {
               pixelmapArrayBuffer = readBuffer;
            })
         }).catch((err: BusinessError) => {
            console.error('[picker] getThumbnail failed with error: ' + JSON.stringify(err));
         });
      } catch (error) {
         let err: BusinessError = error as BusinessError;
         console.error('[picker] getThumbnail error = ' + JSON.stringify(err));
      }
   }
   ```

3. Create a **photoViewPicker** instance and call [save()](../reference/apis/js-apis-file-picker.md#save) to open the **FilePicker** page to save the image. After the user selects the destination folder, the image is saved and the URI of the saved image is returned.

   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   ```ts
   import { BusinessError } from '@ohos.base';

   let uris: Array<string> = [];
   async function photoViewPickerSave(): Promise<void>{
      try {
         const photoSaveOptions = new picker.PhotoSaveOptions(); // Create a photoSaveOptions instance.
         photoSaveOptions.newFileNames = ["PhotoViewPicker01.png"]; // (Optional) Name of the file to be saved. The file name in the square brackets can be customized and must be unique. If the file name already exists on the device, change the file name. Otherwise, an error will be returned.

         const photoViewPicker = new picker.PhotoViewPicker();
         try {
            let photoSaveResult = await photoViewPicker.save(photoSaveOptions);
            if (photoSaveResult != undefined) {
               uris = photoSaveResult;
               console.info('photoViewPicker.save to file succeed and uris are:' + uris);
            }
         } catch (error) {
            let err: BusinessError = error as BusinessError;
            console.error(`[picker] Invoke photoViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
         }
      } catch (error) {
         let err: BusinessError = error as BusinessError;
         console.info("[picker] photoViewPickerSave error = " + JSON.stringify(err));
      }
   }
   ```

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   Then, use [fs.write](../reference/apis/js-apis-file-fs.md#fswrite) to modify the file based on the FD, and close the FD after the modification is complete.

   ```ts
   import { BusinessError } from '@ohos.base';

   async function writeOnly(uri: string): Promise<void> {
      try {
         let file = fs.openSync(uri, fs.OpenMode.WRITE_ONLY);
         let writeLen = await fs.write(file.fd, pixelmapArrayBuffer);
         fs.closeSync(file);
         console.info("[picker] writeOnly writeLen = " + writeLen);
      } catch (error) {
         let err: BusinessError = error as BusinessError;
         console.info("[picker] writeOnly error: " + JSON.stringify(err));
      }
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

3. Create a **documentViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-3) to open the **FilePicker** page to save the document. After the user selects the destination folder, the document is saved and the URI of the document saved is returned.

   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

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

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   import fs from '@ohos.file.fs';

   const uri = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync()](../reference/apis/js-apis-file-fs.md#writesync) to edit the document based on the FD, and then close the FD.

   ```ts
   import fs from '@ohos.file.fs';

   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## Saving Audio Files

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

3. Create an **audioViewPicker** instance, and call [save()](../reference/apis/js-apis-file-picker.md#save-6) to open the **FilePicker** page to save the file. After the user selects the destination folder, the audio file is saved and the URI of the document saved is returned.

   The permission on the URI returned by **save()** is read/write. Further operations on the file can be performed based on the URI in the result set. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

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

4. After the UI is returned from the **FilePicker** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_WRITE**.

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. Use [fs.writeSync()](../reference/apis/js-apis-file-fs.md#writesync) to edit the document based on the FD, and then close the FD.

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
