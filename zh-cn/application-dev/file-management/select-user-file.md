# 选择用户文件

用户需要分享文件、保存图片、视频等用户文件时，开发者可以通过系统预置的[文件选择器（FilePicker）](../reference/apis-core-file-kit/js-apis-file-picker.md)，实现该能力。通过Picker访问相关文件，将拉起对应的应用，引导用户完成界面操作，接口本身无需申请权限。picker获取的uri只具有临时权限，获取持久化权限需要通过[FilePicker设置永久授权](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)方式获取。

根据用户文件的常见类型，选择器（FilePicker）分别提供以下选项：

- [PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated)：适用于图片或视频类型文件的选择与保存（该接口在后续版本不再演进）。请使用[PhotoAccessHelper的PhotoViewPicker](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker)来选择图片文件。请使用[安全控件保存媒体库资源](../media/medialibrary/photoAccessHelper-savebutton.md)。

- [DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker)：适用于文件类型文件的选择与保存。DocumentViewPicker对接的选择资源来自于FilePicker, 负责文件类型的资源管理，文件类型不区分后缀，比如浏览器下载的图片、文档等，都属于文件类型。

- [AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)：适用于音频类型文件的选择与保存。AudioViewPicker目前对接的选择资源来自于FilePicker。

## 选择图片或视频类文件

[PhotoViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#photoviewpickerdeprecated)在后续版本不再演进，请[PhotoAccessHelper的PhotoViewPicker](../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker)来选择图片文件。

## 选择文档类文件

1. 导入选择器模块和基础文件API模块。

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 创建文件类型、文件选择选项实例。

   ```ts
   const documentSelectOptions = new picker.DocumentSelectOptions();
   // 选择文档的最大数目（可选）。
   documentSelectOptions.maxSelectNumber = 5;
   // 指定选择的文件或者目录路径（可选）。
   documentSelectOptions.defaultFilePathUri = "file://docs/storage/Users/currentUser/test";
   // 选择文件的后缀类型['后缀类型描述|后缀类型']（可选） 若选择项存在多个后缀名，则每一个后缀名之间用英文逗号进行分隔（可选），后缀类型名不能超过100,选择所有文件：'所有文件(*.*)|.*'。
    documentSelectOptions.fileSuffixFilters = ['图片(.png, .jpg)|.png,.jpg', '文档|.txt', '视频|.mp4', '.pdf']; 
   //选择是否对指定文件或目录授权，true为授权，当为true时，defaultFilePathUri为必选参数，拉起文管授权界面；false为非授权(默认为false)，拉起常规文管界面（可选）仅支持2in1设备。
   documentSelectOptions.authMode = false;
   //批量授权模式，默认为false（非批量授权模式）。当multAuthMode为true时为批量授权模式。当multAuthMode为true时，只有multiUriArray参数生效，其他参数不生效。仅支持手机设备。
   documentSelectOptions.multiAuthMode = false;
   //需要传入批量授权的uri数组（仅支持文件，文件夹不生效）。配合multAuthMode使用。当multAuthMode为false时，配置该参数不生效。仅支持手机设备。
   documentSelectOptions.multiAuthMode = ["file://docs/storage/Users/currentUser/test", "file://docs/storage/Users/currentUser/2test"];
   //开启聚合视图模式，支持拉起文件管理应用的聚合视图。默认为DEFAULT，表示该参数不生效，非聚合视图。当该参数置为非DEFAULT时，其他参数不生效。仅支持手机设备。
   documentSelectOptions.mergeMode = picker.MergeTypeMode.DEFAULT;
   ```

3. 创建[文件选择器DocumentViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker)实例。调用[select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3)接口拉起FilePicker应用界面进行文件选择。
   
   ```ts
   let uris: Array<string> = [];
   let context = getContext(this) as common.Context; // 请确保 getContext(this) 返回结果为 UIAbilityContext
   // 创建文件选择器实例
   const documentViewPicker = new picker.DocumentViewPicker(context);
   documentViewPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
     //文件选择成功后，返回被选中文档的uri结果集。
     uris = documentSelectResult;
     console.info('documentViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

  > **注意：**
  >
  > **1**、使用picker获取的[select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3)返回的uri权限是临时只读权限,待退出应用后台后，获取的临时权限就会失效。
  > **2**、如果想要获取持久化权限(仅在2in1设备上生效)，请参考[文件持久化授权访问](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)。
  > **3**、开发者可以根据结果集中uri做进一步的处理。建议定义一个全局变量保存uri。
  > **4**、如有获取元数据需求，可以通过[基础文件API](../reference/apis-core-file-kit/js-apis-file-fs.md)和[文件URI](../reference/apis-core-file-kit/js-apis-file-fileuri.md)根据uri获取部分文件属性信息，比如文件大小、访问时间、修改时间、文件名、文件路径等。

4. 待界面从FilePicker返回后，使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口通过uri打开这个文件得到文件描述符(fd)。

   ```ts
   let uri: string = '';
   //这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd使用[fs.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#readsync)接口读取这个文件内的数据。

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   //读取完成后关闭fd。
   fs.closeSync(file);
   ```

## 选择音频类文件

1. 导入选择器模块和基础文件API模块。

   ```ts
   import  { picker } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 创建音频类型文件选择选项实例。

   > **说明：**
   >
   > 目前AudioSelectOptions不支持参数配置，默认可以选择所有类型的用户文件。

   ```ts
   const audioSelectOptions = new picker.AudioSelectOptions();
   ```

3. 创建[音频选择器AudioViewPicker](../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)实例。调用[select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-5)接口拉起FilePicker应用界面进行文件选择。
   
   ```ts
   let uris: string = '';
   // 请确保 getContext(this) 返回结果为 UIAbilityContext
   let context = getContext(this) as common.Context; 
   const audioViewPicker = new picker.AudioViewPicker(context);
   audioViewPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
     //文件选择成功后，返回被选中音频的uri结果集。
     uris = audioSelectResult[0];
     console.info('audioViewPicker.select to file succeed and uri is:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke audioViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

  > **注意：**
  >
  > **1**、使用picker获取的[select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3)返回的uri权限是临时只读权限,待退出应用后台后，获取的临时权限就会失效。
  > **2**、如果想要获取持久化权限(仅在2in1设备上生效)，请参考[文件持久化授权访问](file-persistPermission.md#通过picker获取临时授权并进行授权持久化)。
  > **3**、开发者可以根据结果集中的uri做读取文件数据操作。建议定义一个全局变量保存uri。例如通过[基础文件API](../reference/apis-core-file-kit/js-apis-file-fs.md)根据uri拿到音频资源的文件描述符(fd)，再配合媒体服务实现音频播放的开发，具体请参考[音频播放开发指导](../media/audio/audio-playback-overview.md)。

4. 待界面从FilePicker返回后，可以使用[基础文件API的fs.openSync](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口通过uri打开这个文件得到文件描述符(fd)。

   ```ts
   let uri: string = '';
   //这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

5. 通过fd可以使用[基础文件API的fs.readSync](../reference/apis-core-file-kit/js-apis-file-fs.md#readsync)接口读取这个文件内的数据。

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   //读取完成后关闭fd。
   fs.closeSync(file);
   ```

## 相关实例

针对用户文件的选择，有以下相关实例可供参考：

- [选择并查看文档与媒体文件（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileShare/Picker) 

<!--RP1--><!--RP1End-->