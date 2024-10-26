# 保存用户文件

在从网络下载文件到本地、或将已有用户文件另存为新的文件路径等场景下，需要使用FilePicker提供的保存用户文件的能力。picker获取的uri只具有临时权限，获取持久化权限需要通过[FilePicker设置永久授权](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)方式获取。

对音频、图片、视频、文档类文件的保存操作类似，均通过调用对应picker的save()接口并传入对应的saveOptions来实现。通过Picker访问相关文件，无需申请权限。

当前所有picker的save接口都是用户可感知的，具体行为是拉起FilePicker, 将文件保存在系统文件管理器管理的特定目录，与图库管理的资源隔离，无法在图库中看到。

如需要在图库中看到所保存的图片、视频资源，请使用用户无感的[安全控件创建媒体资源](../media/medialibrary/photoAccessHelper-savebutton.md#使用安全控件创建媒体资源)。


## 保存图片或视频类文件

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpicker)在后续版本不再演进，建议使用[安全控件创建媒体资源](../media/medialibrary/photoAccessHelper-savebutton.md#使用安全控件创建媒体资源)。

如果开发场景无法调用安全控件进行图片、视频保存，可使用相册管理模块[PhotoAccessHelper.showAssetsCreationDialog](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#showassetscreationdialog12)接口进行保存操作。

## 保存文档类文件

1. 导入选择器模块和基础文件API模块。

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 创建文档保存选项实例。

   ```ts
   // 创建文件管理器选项实例
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // 保存文件名（可选） 
   documentSaveOptions.newFileNames = ["DocumentViewPicker01.txt"];
   // 保存文件类型['后缀类型描述|后缀类型'],选择所有文件：'所有文件(*.*)|.*'（可选） ，如果选择项存在多个后缀，默认选择第一个。
   documentSaveOptions.fileSuffixChoices = ['文档|.txt', '.pdf']; 
   ```

3. 创建[文件选择器DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#constructor12)实例。调用[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save)接口拉起FilePicker界面进行文件保存。

   ```ts
   let uris: Array<string> = [];
   // 请确保 getContext(this) 返回结果为 UIAbilityContext
   let context = getContext(this) as common.Context;
   // 创建文件选择器实例。
   const documentViewPicker = new picker.DocumentViewPicker(context);
   //用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的uri。
   documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
     uris = documentSaveResult;
     console.info('documentViewPicker.save to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

> **注意**：
> <br>**1**、不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存URI。
> <br>**2**、使用picker的[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save)接口获取到URI的权限是临时读写权限,待退出应用后台后，获取的临时权限就会失效。
> <br>**3**、如果想要获取持久化权限(仅在2in1设备上生效)，请参考[文件持久化授权访问](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)。
> <br>**4**、可以通过便捷方式，直接将文件保存到[Download](#download模式保存文件)目录下。

4. 待界面从FilePicker返回后，使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到文件描述符(fd)。

   ```ts 
   const uri = '';
   //这里需要注意接口权限参数是fs.OpenMode.READ_WRITE。
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[基础文件API的fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen: number = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
   ```

## 保存音频类文件

1. 导入选择器模块和基础文件API模块。

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 创建音频保存选项实例。

   ```ts
   // 创建文件管理器选项实例
   const audioSaveOptions = new picker.AudioSaveOptions();
   // 保存文件名（可选） 
   audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3']; 
   ```

3. 创建[音频选择器AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)实例。调用[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-5)接口拉起FilePicker界面进行文件保存。
   ```ts
   let uri: string = '';
   // 请确保 getContext(this) 返回结果为 UIAbilityContext
   let context = getContext(this) as common.Context; 
   const audioViewPicker = new picker.AudioViewPicker(context);
   //用户选择目标文件夹，用户选择与文件类型相对应的文件夹，即可完成文件保存操作。保存成功后，返回保存文档的uri。
   audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
     uri = audioSelectResult[0];
     console.info('audioViewPicker.save to file succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```
> **注意**：
> <br>**1**、不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri。
> <br>**2**、使用picker获取的[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-3)uri权限是临时读写权限,待退出应用后台后，获取的临时权限就会失效。
> <br>**3**、如果想要获取持久化权限(仅在2in1设备上生效)，请参考[文件持久化授权访问](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)。
> <br>**4**、可以通过便捷方式，直接将文件保存到[Download](#download模式保存文件)目录下。

4. 待界面从FilePicker返回后，可以使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到文件描述符(fd)。

   ```ts
   //这里需要注意接口权限参数是fileIo.OpenMode.READ_WRITE。
   let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[基础文件API的fs.writeSync](../reference/apis-core-file-kit/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改，编辑修改完成后关闭fd。

   ```ts
   let writeLen = fs.writeSync(file.fd, 'hello, world');
   console.info('write data to file succeed and size is:' + writeLen);
   fs.closeSync(file);
 
   ```
## DOWNLOAD模式保存文件

用户在使用save接口时，可以将pickerMode配置为DOWNLOAD模式，该模式下会拉起授权接口，用户确认后会在公共路径download目录下创建用户当前hap包名的文件夹，并通过save接口返回值回传相应的URI，后续用户可以直接将文件保存在该URI下。
1. 导入选择器模块和文件管理模块。

   ```ts
   import { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 创建文件保存选项实例。

   ```ts
   // 创建文件管理器选项实例
   const documentSaveOptions = new picker.DocumentSaveOptions();
   // 配置保存的模式为DOWNLOAD，若配置了DOWNLOAD模式，此时配置的其他documentSaveOptions参数将不会生效。
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD; 
   ```

3. 创建文件选择器实例。调用[save()](../reference/apis-core-file-kit/js-apis-file-picker.md#save-1)接口拉起FilePicker模态窗界面进行文件保存。用户点击同意，即可在download目录下创建对应应用的专属目录，返回该目录的uri。
   
   ```ts
   let uri: string = '';
   // 请确保 getContext(this) 返回结果为 UIAbilityContext
   let context = getContext(this) as common.Context; 
   const documentViewPicker = new picker.DocumentViewPicker(context);
   const documentSaveOptions = new picker.DocumentSaveOptions();
   documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
   documentViewPicker.save(documentSaveOptions ).then((documentSaveResult: Array<string>) => {
     uri = documentSaveResult[0];
     console.info('documentViewPicker.save succeed and uri is:' + uri);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

