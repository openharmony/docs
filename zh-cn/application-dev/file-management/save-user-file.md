# 保存用户文件
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

在从网络下载文件到本地或将已有用户文件另存为新的文件路径等场景下，需要使用FilePicker提供的保存用户文件的能力。需关注以下关键点：

**权限说明**

- 通过Picker获取的URI默认只具备**临时读写权限**，临时授权在应用退出后台自动失效。
- 获取持久化权限需要通过[FilePicker设置永久授权](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)方式获取。
- 使用Picker对音频、图片、视频、文档类文件的保存操作**无需申请权限**。

**系统隔离说明**

- 通过Picker保存的文件存储在用户指定的目录。此类文件与图库管理的资源隔离，无法在图库中看到。
- 若开发者需要保存图片、视频资源到图库，可使用用户无感的[安全控件进行保存](../media/medialibrary/photoAccessHelper-savebutton.md#使用安全控件保存媒体库资源)。

## 保存图片或视频类文件

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated)在后续版本不再演进，建议使用[Media Library Kit（媒体文件管理服务）中能力来保存媒体库资源](../media/medialibrary/photoAccessHelper-savebutton.md)。

如果开发场景无法调用安全控件进行图片、视频保存，可使用相册管理模块[PhotoAccessHelper.showAssetsCreationDialog](../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#showassetscreationdialog12)接口进行保存操作。

## 保存文档类文件

1. 模块导入。

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 配置保存选项。

   ```ts
   // 创建文件管理器选项实例。
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // 保存文件名（可选）。 默认为空。
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"];
   //指定保存的文件或者目录的URI（可选）。
   documentSaveOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test";
   // 保存文件类型['后缀类型描述|后缀类型'],选择所有文件：'所有文件(*.*)|.*'（可选） ，如果选择项存在多个后缀（做大限制100个过滤后缀），默认选择第一个。如果不传该参数，默认无过滤后缀。
   documentSaveOptions.fileSuffixChoices = ['文档|.txt', '.pdf']; 
   ```

3. 创建[文件选择器DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#constructor12)实例。调用[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save)接口拉起FilePicker界面进行文件保存。

   ```ts
   let uris: Array<string> = [];
   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **注意**：
   >
   > 1. URI存储建议：
   >	 - 避免在Picker回调中直接操作URI。
   >	 - 建议使用全局变量保存URI以供后续使用。
   >
   > 2. 快捷保存：
   > 	- 可以通过[DOWNLOAD模式](#download模式保存文件)直达下载目录。

4. 待界面从FilePicker返回后，使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口，通过URI打开这个文件得到文件描述符（fd）。

   ```ts
   const uri = '';
   //这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过（fd）使用[基础文件API的fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭（fd）。

   ```ts
   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 保存音频类文件

1. 模块导入。

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 配置保存选项。

   ```ts
   const audioSaveOptions = new picker.AudioSaveOptions();
   // 保存文件名（可选） 
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; 
   ```

3. 创建[音频选择器AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)实例。调用[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-5)接口拉起FilePicker界面进行文件保存。

   ```ts
   let uri: string = '';
   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;  
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

   > **注意**：
   >
   > 1. URI存储建议：
   > 	- 避免在Picker回调中直接操作URI。
   > 	- 建议使用全局变量保存URI以供后续使用。
   >
   > 2. 快捷保存：
   > 	- 可以通过[DOWNLOAD模式](#download模式保存文件)直达下载目录。

4. 待界面从FilePicker返回后，可以使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口，通过URI打开这个文件得到文件描述符（fd）。

   ```ts
   //这里需要注意接口权限参数是fileIo.OpenMode.READ_WRITE。
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过（fd）使用[基础文件API的fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭（fd）。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
 
   ```

## DOWNLOAD模式保存文件

**模式特点**

- 自动创建在`Download/包名/`目录。
- 跳过文件选择界面直接保存。
- 返回的URI已具备持久化权限， 用户可在该URI下创建文件。

> **注意：**
>
> DOWNLOAD模式创建的目录仅用于保存文件，目录之间无访问隔离，不建议保存应用敏感数据。

1. 模块导入。

   ```ts
   import { fileUri, picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 配置下载模式。

   ```ts
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // 配置保存的模式为DOWNLOAD，若配置了DOWNLOAD模式，此时配置的其他documentSaveOptions参数将不会生效。
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD; 
   ```

3. 保存到下载目录。

   ```ts
   let uri: string = '';
   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   const documentViewPicker = new picker.DocumentViewPicker(context);
   const documentSaveOptions = new picker.DocumentSaveOptions();
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uri = documentSaveResult[0];
     console.info('documentViewPicker.save succeed and uri is:' + uri);
     const testFilePath = new fileUri.FileUri(uri + '/test.txt').path;
     const file = fs.openSync(testFilePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
     fs.writeSync(file.fd, 'Hello World!');
     fs.closeSync(file.fd);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
