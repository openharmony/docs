# 选择用户文件

终端用户有时需要分享、保存一些图片、视频等用户文件，开发者需要在应用中支持此类使用场景。此时，开发者可以使用OpenHarmony系统预置的[文件选择器（FilePicker）](../reference/apis/js-apis-file-picker.md)，实现用户文件选择及保存能力。

根据用户文件的常见类型，文件选择器（FilePicker）分别提供以下接口：

- [PhotoViewPicker](../reference/apis/js-apis-file-picker.md#photoviewpicker)：适用于图片或视频类文件的选择与保存。

- [DocumentViewPicker](../reference/apis/js-apis-file-picker.md#documentviewpicker)：适用于文档类文件的选择与保存。

- [AudioViewPicker](../reference/apis/js-apis-file-picker.md#audioviewpicker)：适用于音频类文件的选择与保存。

## 选择图片或视频类文件

1. 导入选择器模块。

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. 创建图库选择选项实例。

   ```ts
   const photoSelectOptions = new picker.PhotoSelectOptions();
   ```

3. 选择媒体文件类型和选择媒体文件的最大数目。
   以下示例以图片选择为例，媒体文件类型请参见[PhotoViewMIMETypes](../reference/apis/js-apis-file-picker.md#photoviewmimetypes)。

   ```ts
   photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE; // 过滤选择媒体文件类型为IMAGE
   photoSelectOptions.maxSelectNumber = 5; // 选择媒体文件的最大数目
   ```

4. 创建图库选择器实例，调用[select()](../reference/apis/js-apis-file-picker.md#select)接口拉起FilePicker界面进行文件选择。

   文件选择成功后，返回[PhotoSelectResult](../reference/apis/js-apis-file-picker.md#photoselectresult)结果集，可以根据结果集中URI进行文件读取等操作。

   ```ts
   let uri;
   const photoPicker = new picker.PhotoViewPicker();
   photoPicker.select(photoSelectOptions).then((photoSelectResult) => {
     uri = photoSelectResult.photoUris[0];
   }).catch((err) => {
     console.error(`Invoke photoPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. 待界面从FilePicker返回后再使用文件管理的接口[fs.openSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#fsopensync)根据目的文件的uri打开这个文件得到fd。

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

6. 通过fd使用[fs.writeSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 选择文档类文件

1. 导入选择器模块。

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. 创建文档选择选项实例。

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions(); 
   ```

3. 创建文档选择器实例。调用[select()](../reference/apis/js-apis-file-picker.md#select-3)接口拉起FilePicker界面进行文件选择。

     文件选择成功后，返回被选中文档的URI结果集。开发者可以根据结果集中URI做进一步的处理。

   例如通过[文件管理接口](../reference/apis/js-apis-file-fs.md)根据URI获取部分文件属性信息，比如文件大小、访问时间、修改时间等。如有获取文件名称需求，请暂时使用[startAbilityForResult](../../application-dev/application-models/uiability-intra-device-interaction.md)获取。

   > **说明：**
   >
   > 目前DocumentSelectOptions不支持参数配置，默认可以选择所有类型的用户文件。

   ```ts
   let uri;
   const documentViewPicker = new picker.DocumentViewPicker(); // 创建文件选择器实例
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
     uri = documentSelectResult[0];
   }).catch((err) => {
     console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **说明：**
   >
   > 目前DocumentSelectOptions功能不完整, 如需获取文件名称，请使用startAbilityForResult接口。

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
       console.error(`DocumentPicker.select failed, code is ${result.resultCode}, message is ${result.want.parameters.message}`);
       return;
     }
     // 获取到文档文件的URI
     let select_item_list = result.want.parameters.select_item_list;
     // 获取到文档文件的文件名称
     let file_name_list = result.want.parameters.file_name_list;
   } catch (err) {
     console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

4. 待界面从FilePicker返回后再使用文件管理的接口[fs.openSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#fsopensync)根据目的文件的uri打开这个文件得到fd。

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```


## 选择音频类文件

1. 导入选择器模块。

   ```ts
   import picker from '@ohos.file.picker';
   ```

2. 创建音频选择选项实例。

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. 创建音频选择器实例。调用[select()](../reference/apis/js-apis-file-picker.md#select-6)接口拉起FilePicker界面进行文件选择。
  
   文件选择成功后，返回被选中音频的URI结果集。开发者可以根据结果集中URI做进一步的处理。

   例如通过[文件管理接口](../reference/apis/js-apis-file-fs.md)根据URI拿到音频资源的文件句柄（FD），再配合媒体服务实现音频播放的开发，具体请参考[音频播放开发指导](../media/audio-playback-overview.md)。

   > **说明：**
   >
   > 目前AudioSelectOptions不支持参数配置，默认可以选择所有类型的用户文件。

   ```ts
   let uri;
   const audioViewPicker = new picker.AudioViewPicker();
   audioViewPicker.select(audioSelectOptions).then(audioSelectResult => {
     uri = audioSelectOptions[0];
   }).catch((err) => {
     console.error(`Invoke audioPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. 待界面从FilePicker返回后再使用文件管理的接口[fs.openSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#fsopensync)根据目的文件的uri打开这个文件得到fd。

   ```ts
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
