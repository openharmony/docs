# 保存用户文件

在从网络下载文件到本地、或将已有用户文件另存为新的文件路径等场景下，需要使用FilePicker提供的保存用户文件的能力。

对音频、图片、视频、文档类文件的保存操作类似，均通过调用对应picker的save()接口并传入对应的saveOptions来实现。


## 保存图片或视频类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. 创建图库保存选项实例。

   ```ts
   const photoSaveOptions = new picker.PhotoSaveOptions(); // 创建文件管理器保存选项实例
   photoSaveOptions.newFileNames = ["PhotoViewPicker01.jpg"]; // 保存文件名（可选）
   ```

3. 创建图库选择器实例，调用[save()](../reference/apis/js-apis-file-picker.md#save)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的URI。
   
   </br>save返回的URI权限是读写权限，可以根据结果集中URI进行文件读写等操作。注意不能在picker的回调里直接使用此URI进行打开文件操作，需要定义一个全局变量保存URI，使用类似一个按钮去触发打开文件。

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

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过URI打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](../reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 保存文档类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. 创建文档保存选项实例。

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions(); // 创建文件管理器选项实例
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"]; // 保存文件名（可选）
   ```

3. 创建文档选择器实例。调用[save()](../reference/apis/js-apis-file-picker.md#save-3)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的URI。
   
   </br>save返回的URI权限是读写权限，可以根据结果集中URI进行文件读写等操作。注意不能在picker的回调里直接使用此URI进行打开文件操作，需要定义一个全局变量保存URI，使用类似一个按钮去触发打开文件。

   ```ts
   let URI = null;
   const documentViewPicker = new picker.DocumentViewPicker(); // 创建文件选择器实例
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult) => {
     URI = documentSaveResult[0];
     console.info('documentViewPicker.save to file succeed and URI is:' + URI);
   }).catch((err) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过URI打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](../reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 保存音频类文件

1. 导入选择器模块和文件管理模块。

   ```ts
   import picker from '@ohos.file.picker';
   import fs from '@ohos.file.fs';
   ```

2. 创建音频保存选项实例。

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions(); // 创建文件管理器选项实例
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; // 保存文件名（可选）
   ```

3. 创建音频选择器实例。调用[save()](../reference/apis/js-apis-file-picker.md#save-6)接口拉起FilePicker界面进行文件保存。用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的URI。
   
   </br>save返回的URI权限是读写权限，可以根据结果集中URI进行文件读写等操作。注意不能在picker的回调里直接使用此URI进行打开文件操作，需要定义一个全局变量保存URI，使用类似一个按钮去触发打开文件。
   
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

4. 待界面从FilePicker返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过URI打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。

   ```ts
   let file = fs.openSync(URI, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.writeSync](../reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```
   