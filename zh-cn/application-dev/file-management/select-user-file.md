# 选择用户文件

用户有时需要分享或保存图片、视频等用户文件，开发者可以通过系统预置的[文件选择器（FilePicker）](../reference/apis/js-apis-file-picker.md)，实现该能力。通过Picker访问相关文件，将拉起对应的应用，引导用户完成界面操作，接口本身无需申请权限。

根据用户文件的常见类型，选择器（FilePicker）分别提供以下接口：

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker)：适用于图片或视频类型文件的选择与保存。优选使用[PhotoAccessHelper的PhotoViewPicker](../reference/apis/js-apis-photoAccessHelper.md#photoviewpicker)来选择文件。当前PhotoViewPicker对接的选择资源来自于图库，保存位置为系统文件管理器的特定目录，因此使用save接口保存的图片或视频无法在图库中展示。如需在图库中展示，请使用[安全控件创建媒体资源](photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)。

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker)：适用于文件类型文件的选择与保存。DocumentViewPicker对接的选择资源来自于FilePicker, 负责文件类型的资源管理，文件类型不区分后缀，比如浏览器下载的图片、文档等，都属于文件类型。

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker)：适用于音频类型文件的选择与保存。AudioViewPicker目前对接的选择资源来自于FilePicker。

## 选择图片或视频类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建图片-视频类型文件选择选项实例。

   ```ts
   import picker from '@ohos.file.picker';
   
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. 选择媒体文件类型和选择媒体文件的最大数目。
   以下示例以图片选择为例，媒体文件类型请参见[PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes)。

   ```ts
   import picker from '@ohos.file.picker';
   
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // 过滤选择媒体文件类型为IMAGE
   photoSelectOptions.maxSelectNumber = 5; // 选择媒体文件的最大数目
   ```

4. 创建图库选择器实例，调用[select()](../reference/apis/js-apis-file-picker.md#select)接口拉起图库界面进行文件选择。文件选择成功后，返回[PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult)结果集。

   </br>select返回的uri权限是只读权限，可以根据结果集中uri进行读取文件数据操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   </br>如有获取元数据需求，可以通过[文件管理接口](../reference/apis/js-apis-file-fs.md)和[文件URI](../reference/apis/js-apis-file-fileuri.md)根据uri获取部分文件属性信息，比如文件大小、访问时间、修改时间、文件名、文件路径等。

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

5. 待界面从图库返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. 通过fd使用[fs.readSync](../reference/apis/js-apis-file-fs.md#readsync)接口读取这个文件内的数据，读取完成后关闭fd。

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## 选择文档类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建文件类型文件选择选项实例。

   ```ts
   import picker from '@ohos.file.picker';
   
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   documentSelectOptions.maxSelectNumber = 5; // 选择文档的最大数目（可选）
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test"; // 指定选择的文件或者目录路径（可选）
   documentSelectOptions.fileSuffixFilters = ['.png', '.txt', '.mp4']; // 选择文件的后缀类型，若选择项存在多个后缀名，则每一个后缀名之间用英文逗号进行分隔（可选）
   ```

3. 创建文件选择器实例。调用[select()](../reference/apis/js-apis-file-picker.md#select-3)接口拉起FilePicker应用界面进行文件选择。文件选择成功后，返回被选中文档的uri结果集。

   select返回的uri权限是只读权限，开发者可以根据结果集中uri做进一步的处理。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   如有获取元数据需求，可以通过[文件管理接口](../reference/apis/js-apis-file-fs.md)和[文件URI](../reference/apis/js-apis-file-fileuri.md)根据uri获取部分文件属性信息，比如文件大小、访问时间、修改时间、文件名、文件路径等。

   ```ts
   import picker from '@ohos.file.picker';
   import { BusinessError } from '@ohos.base';
   
   let uris: Array<string> = [];
   const documentViewPicker = new picker.DocumentViewPicker(); // 创建文件选择器实例
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.readSync](../reference/apis/js-apis-file-fs.md#readsync)接口读取这个文件内的数据，读取完成后关闭fd。

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## 选择音频类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建音频类型文件选择选项实例。

   > **说明：**
   >
   > 目前AudioSelectOptions不支持参数配置，默认可以选择所有类型的用户文件。

   ```ts
   import picker from '@ohos.file.picker';
   
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. 创建音频选择器实例。调用[select()](../reference/apis/js-apis-file-picker.md#select-6)接口拉起FilePicker应用界面进行文件选择。文件选择成功后，返回被选中音频的uri结果集。

   select返回的uri权限是只读权限，开发者可以根据结果集中uri做读取文件数据操作。注意不能在  picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   例如通过[文件管理接口](../reference/apis/js-apis-file-fs.md)根据uri拿到音频资源的文件句柄（FD），再配合媒体服务实现音频播放的开发，具体请参考[音频播放开发指导](../media/audio-playback-overview.md)。

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

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.readSync](../reference/apis/js-apis-file-fs.md#readsync)接口读取这个文件内的数据，读取完成后关闭fd。

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

## 相关实例

针对用户文件的选择，有以下相关实例可供参考：

- [选择并查看文档与媒体文件（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileShare/Picker)