# 保存用户文件

在从网络下载文件到本地、或将已有用户文件另存为新的文件路径等场景下，需要使用FilePicker提供的保存用户文件的能力。

对音频、图片、视频、文档类文件的保存操作类似，均通过调用对应picker的save()接口并传入对应的saveOptions来实现。通过Picker访问相关文件，无需申请权限。

当前所有picker的save接口都是用户可感知的，具体行为是拉起FilePicker, 将文件保存在系统文件管理器管理的特定目录，与图库管理的资源隔离，无法在图库中看到。

如需要在图库中看到所保存的图片、视频资源，请使用用户无感的[安全控件创建媒体资源](./photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)。


## 保存图片或视频类文件

本例展示了从图库中选择一张图片，保存到文件管理器的示例代码。

1. 导入[选择器](../reference/apis/js-apis-file-picker.md)、[文件管理](../reference/apis/js-apis-file-fs.md)、[相册管理](../reference/apis/js-apis-photoAccessHelper.md)、[数据共享谓词](../reference/apis/js-apis-data-dataSharePredicates.md)模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

2. 获取设备里第一张图片的缩略图。注意：在执行这一步之前，要先确保设备里至少有一张图片。

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

3. 创建图库选择器实例，调用[save()](../reference/apis/js-apis-file-picker.md#save)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存图片的uri。
   
   save返回的uri权限是读写权限，可以根据结果集里面的uri进行文件读写等操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   ```ts  
   import { BusinessError } from '@ohos.base';

   let uris: Array<string> = [];
   async function photoViewPickerSave(): Promise<void>{
      try {
         const photoSaveOptions = new picker.PhotoSaveOptions(); // 创建文件管理器保存选项实例
         photoSaveOptions.newFileNames = ["PhotoViewPicker01.png"]; // 保存文件名（可选），方括号里的文件名自定义，每次不能重复，设备里已有这个文件的话，名字就需要改个不一样的，不然接口会报错

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

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   然后，通过fd使用[fs.write](../reference/apis/js-apis-file-fs.md#fswrite)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

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

## 保存文档类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建文档保存选项实例。

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions(); // 创建文件管理器选项实例
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"]; // 保存文件名（可选）
   documentSaveOptions.fileSuffixChoices = ['.png', '.txt', '.mp4']; // 保存文件类型（可选）
   ```

3. 创建文档选择器实例。调用[save()](../reference/apis/js-apis-file-picker.md#save-3)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的uri。
   
   </br>save返回的uri权限是读写权限，可以根据结果集中uri进行文件读写等操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   ```ts
   import { BusinessError } from '@ohos.base';

   let uris: Array<string> = [];
   const documentViewPicker = new picker.DocumentViewPicker(); // 创建文件选择器实例
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   ```ts
   import fs from '@ohos.file.fs';
   
   const uri = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](../reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   import fs from '@ohos.file.fs';
   
   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 保存音频类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建音频保存选项实例。

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions(); // 创建文件管理器选项实例
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; // 保存文件名（可选）
   ```

3. 创建音频选择器实例。调用[save()](../reference/apis/js-apis-file-picker.md#save-6)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的uri。
   
   </br>save返回的uri权限是读写权限，可以根据结果集中uri进行文件读写等操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。
   
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

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](../reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
   